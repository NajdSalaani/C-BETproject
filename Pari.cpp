#include <iostream>
#include <string>
<<<<<<< HEAD
=======
#include <sstream>
>>>>>>> 2e92182 (m)
#include "Pari.hpp"




using namespace std;



<<<<<<< HEAD
Pari::Pari(int id, double montant, Statut statut, EvenementSportif& evenement, const std::list<Participant>& participants)
    : _id(id), _montantMise(montant), _statut(statut), _evenement(evenement), _participantsChoisis(participants) {
    // Calcul de la cote moyenne parmi les participants
    double maxCote = 0.0;
=======
Pari::Pari(int id, double montant, Statut statut, EvenementSportif& evenement, const Participant& participant)
    : _id(id), _montantMise(montant), _statut(statut), _evenement(evenement), _participantChoisi(participant) {
    // Calcul de la cote moyenne parmi les participants
    /*double maxCote = 0.0;
>>>>>>> 2e92182 (m)
    for (const auto& participant : participants) {
        if (participant.getCote() > maxCote) {
            maxCote = participant.getCote();
        }
    }
<<<<<<< HEAD
    _cote = maxCote / participants.size();
=======
    _cote = maxCote / participants.size();*/
    _cote = participant.getCote();
>>>>>>> 2e92182 (m)
}


int Pari:: getId(){
    return _id;
}

<<<<<<< HEAD

=======
/*
>>>>>>> 2e92182 (m)
void Pari:: modifCote() {
        // Calcul de la cote moyenne parmi les participants
        double maxCote = 0.0;
        for (const auto& participant : _participantsChoisis) {
            if (participant.getCote() > maxCote) {
                maxCote = participant.getCote();
            }
        }
        _cote = maxCote / _participantsChoisis.size();
<<<<<<< HEAD
    }


=======
    }*/

/*
>>>>>>> 2e92182 (m)
void Pari:: ajouterParticipant(const Participant& participant) {
    _participantsChoisis.push_back(participant);
    modifCote();
}


void Pari:: supprimerParticipant(const Participant& participant) {
    _participantsChoisis.remove(participant);
    modifCote();
<<<<<<< HEAD
}
=======
}*/
>>>>>>> 2e92182 (m)

void Pari::annulerPari() {
    // Réinitialiser les données du pari
    _id = 0;
    _montantMise = 0.0;
    _cote = 0.0;
    _statut = Statut::E;
<<<<<<< HEAD
    _participantsChoisis.clear(); // Effacer la liste des participants
=======
    //_participantsChoisis.clear(); // Effacer la liste des participants
>>>>>>> 2e92182 (m)

    // Libérer la mémoire de l'instance de l'objet pari
    delete this;
}




<<<<<<< HEAD
void Pari:: ResultatPari(const EvenementSportif& evenement){
   // Vérifier si l'un des participants choisis remporte l'événement
    bool participantGagnant = false;
    for (const auto& participant : _participantsChoisis) {
=======
void Pari:: resultatPari(){
   // Vérifier si l'un des participants choisis remporte l'événement
    bool participantGagnant = false;
    /*for (const auto& participant : _participantsChoisis) {
>>>>>>> 2e92182 (m)
        if (evenement.getGagnant() == participant.getNom()) {
            participantGagnant = true;
            break;
        }
<<<<<<< HEAD
=======
    }*/
    if (_evenement.getGagnant() == _participantChoisi.getNom()){
        participantGagnant = true;
>>>>>>> 2e92182 (m)
    }

    // Mettre à jour le statut du pari en conséquence
    if (participantGagnant) {
        _statut = Statut::G; // Gagné si l'un des participants choisis remporte l'événement
<<<<<<< HEAD
    } else if (evenement.getGagnant() == "--") {
        _statut = Statut::E; // Événement en cours
    } else {
=======
    } 
    else if (_evenement.getGagnant() == "--") {
        _statut = Statut::E; // Événement en cours
    } 
    else {
>>>>>>> 2e92182 (m)
        _statut = Statut::P; // Perdu si aucun des participants choisis ne remporte l'événement
    }
}


<<<<<<< HEAD
void Pari:: detailPari() const {
   std::cout << "Détails du Pari :\n";
    std::cout << "ID du Pari : " << _id << "\n";
    std::cout << "Montant misé : " << _montantMise << "\n";
    std::cout << "Cote : " << _cote << "\n";
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

    std::cout << "\nParticipants sur lesquels vous avez misé :\n";
    for (const auto& participant : _participantsChoisis) {
        std::cout << " - " << participant.getNom() << "\n";
    }

    std::cout << "Événement associé :\n";
    std::cout << " - " << _evenement.getNomEvenement() << "\n";

    std::cout << "-------------------------\n";
    std::cout << std::endl << std::endl;
=======
std::string Pari:: detailPari() const {
    std::ostringstream detailsStream;
    detailsStream << "Détails du Pari :\n";
    detailsStream << "ID du Pari : " << _id << "\n";
    detailsStream << "Montant misé : " << _montantMise << "\n";
    detailsStream << "Cote : " << _cote << "\n";
    detailsStream << "Statut : ";

    switch (_statut) {
        case Statut::E:
            detailsStream << "En cours";
            break;
        case Statut::G:
            detailsStream << "Gagné";
            break;
        case Statut::P:
            detailsStream << "Perdu";
            break;
    }

    detailsStream << "\nParticipant sur lequel vous avez misé :\n";
    //for (const auto& participant : _participantsChoisis) {
        detailsStream << " - " << _participantChoisi.getNom() << "\n";
    //}

    detailsStream << "Événement associé :\n";
    detailsStream << " - " << _evenement.getNomEvenement() << "\n";

    detailsStream << "-------------------------\n";
    detailsStream << std::endl << std::endl;
    return detailsStream.str();
>>>>>>> 2e92182 (m)
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

    // Parcourir la liste des participants choisis et concaténer leur nom dans la chaîne de caractères
<<<<<<< HEAD
    for (const auto& participant : _participantsChoisis) {
=======
    /*for (const auto& participant : _participantsChoisis) {
>>>>>>> 2e92182 (m)
        choix += participant.getNom() + ", ";
    }

    // Supprimer la virgule et l'espace en trop à la fin de la chaîne
    if (!choix.empty()) {
        choix.erase(choix.size() - 2); // Supprimer les deux derniers caractères
<<<<<<< HEAD
    }

    return choix;
=======
    }*/

    return _participantChoisi.getNom();
>>>>>>> 2e92182 (m)
}


void Pari::mettreMontant(double montant){
    _montantMise = montant;
}










<<<<<<< HEAD

=======
/*
>>>>>>> 2e92182 (m)

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


        // Vérifier si au moins un participant choisi est gagnant
        for (const auto& participant : _participantsChoisis) {
            if (evenement->getGagnant() == participant.getNom()) {
                auMoinsUnParticipantGagnant = true;
                break;
            }
            auMoinsUnParticipantGagnant = false;
            tousEvenementsGagnants = false;
        }
    }

    // Mettre à jour le statut du pari en conséquence
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
<<<<<<< HEAD
}
=======
}*/
>>>>>>> 2e92182 (m)
