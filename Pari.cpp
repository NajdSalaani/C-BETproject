#include <iostream>
#include <string>
#include <sstream>
#include "Pari.hpp"




using namespace std;


Pari::Pari(int id, double montant, Statut statut, EvenementSportif& evenement, const Participant& participant)
    : _id(id), _montantMise(montant), _statut(statut), _evenement(evenement), _participantChoisi(participant) {
    // Calcul de la cote moyenne parmi les participants
    /*double maxCote = 0.0;
    for (const auto& participant : participants) {
        if (participant.getCote() > maxCote) {
            maxCote = participant.getCote();
        }
    }
    _cote = maxCote / participants.size();*/
    _cote = participant.getCote();
}


int Pari:: getId(){
    return _id;
}



void Pari::annulerPari() {
    // Réinitialiser les données du pari
    _id = 0;
    _montantMise = 0.0;
    _cote = 0.0;
    _statut = Statut::E;
    //_participantsChoisis.clear(); // Effacer la liste des participants

    // Libérer la mémoire de l'instance de l'objet pari
    delete this;
}




void Pari:: resultatPari(){
   // Vérifie si le participant choisi remporte l'événement
    bool participantGagnant = false;
   
    if (_evenement.getGagnant() == _participantChoisi.getNom()){
        participantGagnant = true;
    }

    // Mis à jour du statut du pari en conséquence
    if (participantGagnant) {
        _statut = Statut::G; // Gagné si le participant choisi remporte l'événement
    } 
    else if (_evenement.getGagnant() == "--") {
        _statut = Statut::E; // Événement en cours
    } 
    else {
        _statut = Statut::P; // Perdu si le participant choisi ne remporte pas l' evenement l'événement
    }
}


std::string Pari:: detailPari() const {
    std::ostringstream detailsStream;
    detailsStream << "Details du Pari :\n";
    detailsStream << "ID du Pari : " << _id << "\n";
    detailsStream << "Montant mise : " << _montantMise << "\n";
    detailsStream << "Cote : " << _cote << "\n";
    detailsStream << "Statut : ";

    switch (_statut) {
        case Statut::E:
            detailsStream << "En cours";
            break;
        case Statut::G:
            detailsStream << "Gagne";
            break;
        case Statut::P:
            detailsStream << "Perdu";
            break;
    }

    detailsStream << "\nParticipant sur lequel vous avez mise :\n";
    detailsStream << " - " << _participantChoisi.getNom() << "\n";

    detailsStream << "Evenement associe :\n";
    detailsStream << " - " << _evenement.getNomEvenement() << "\n";

    detailsStream << "-------------------------\n";
    detailsStream << std::endl << std::endl;
    return detailsStream.str();
}


std::string Pari:: getEvenement() const{
    return _evenement.getNomEvenement();
}

double Pari:: getCote() const{
    return _cote;
}

double Pari:: getMontant() const{
    return _montantMise;

}
Statut Pari:: getStatut() const{
    return _statut;
}

string Pari:: getChoix() const{
    std::string choix;

    return _participantChoisi.getNom();
}


void Pari::mettreMontant(double montant){
    _montantMise = montant;
}


Pari& Pari::operator=(const Pari& autre) {
    if (this != &autre) {
        _id = autre._id;
        _montantMise = autre._montantMise;
        _cote = autre._cote;
        _statut = autre._statut;
        _evenement = autre._evenement;
        _participantChoisi = autre._participantChoisi;
    }
    return *this;
}

void Pari::modifPari(int id, double montantMise, Statut statut, Participant participantChoisi){
    _id = id;
    _montantMise = montantMise;
    _statut = statut;
    _participantChoisi = participantChoisi;
}

void Pari::setEvenement(const EvenementSportif &evenement){
    _evenement = evenement;
}








/*

Combine::Combine(int id, double montant,  Statut statut, const std::list<EvenementSportif*>& evenements, const std::list<Participant>& participants)
    : Pari(id, montant, statut, *evenements.front(), participants), _listeEvenements(evenements) {}


Combine::~Combine() {
    // Libérer la mémoire de chaque événement
    for (auto evenement : _listeEvenements) {
        delete evenement;
    }
}


void Combine::ajouterEvenement(EvenementSportif* evenement) {
    _listeEvenements.push_back(evenement);
    modifCote();
}

void Combine::retirerEvenement(EvenementSportif* evenement) {
    _listeEvenements.remove(evenement);
    modifCote();
}


void Combine::ajouterParticipant(const Participant& participant){
    _participantsChoisis.push_back(participant);
    modifCote();

}
void Combine::supprimerParticipant(const Participant& participant){
    _participantsChoisis.remove(participant);
    modifCote();

}

void Combine::modifCote(){
    double l= 0.0;
    double maxCote = 0.0;
    for(size_t i = 0; i < _listeEvenements.size(); i ++){
    //for (const auto& evenement : _listeEvenements) {
        for (const auto& participant : _participantsChoisis) {
            if (participant.getCote() > maxCote) {
                maxCote = participant.getCote();
            }
        }
        l = maxCote / _participantsChoisis.size();
        _cote *= l;
    }

}

void Combine:: ResultatPari(const std::list< EvenementSportif*>& listeEvenements){
// Vérifier si tous les événements sont gagnants
    bool tousEvenementsGagnants = true;
    bool auMoinsUnParticipantGagnant = false;

    for (const auto& evenement : listeEvenements) {
        // Vérifier si l'événement est en cours
        if (evenement->getGagnant() == "--") {
            auMoinsUnParticipantGagnant = false;
            _statut = Statut::E; // Événement en cours
            return;
        }


        // Vérification si au moins un participant choisi est gagnant
        for (const auto& participant : _participantsChoisis) {
            if (evenement->getGagnant() == participant.getNom()) {
                auMoinsUnParticipantGagnant = true;
                break;
            }
            auMoinsUnParticipantGagnant = false;
            tousEvenementsGagnants = false;
        }
    }

    // Mis à jour le statut du pari en conséquence
    if (tousEvenementsGagnants) {
        _statut = Statut::G; // Pari gagné si tous les événements sont gagnants et qu'au moins un participant choisi est gagnant
    } 
     else {
        _statut = Statut::P; // Pari perdu si au moins un événement est perdant
    }
}


void Combine::detailPari() const {
    std::cout << "Détails du Pari Combine :\n";
    std::cout << "ID du Pari : " << _id << "\n";
    std::cout << "Montant misé : " << _montantMise << "\n";
    std::cout << "Cote totale : " << getCote() << "\n";
    std::cout << "Statut : ";

    switch (_statut) {
        case Statut::E:
            std::cout << "En cours";
            break;
        case Statut::G:
            std::cout << "Gagné";
            break;
        case Statut::P:
            std::cout << "Perdu";
            break;
    }

    std::cout << "\nÉvénements associés :\n";
    for (const auto& evenement : _listeEvenements) {
        std::cout << " - " << evenement->getNomEvenement() << "\n";
        std::cout << "Participants sur lesquels vous avez misé :\n";
        for (const auto& participant : _participantsChoisis) {
            std::cout << "   - " << participant.getNom() << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "-------------------------\n";
    std::cout << std::endl << std::endl;
}*/