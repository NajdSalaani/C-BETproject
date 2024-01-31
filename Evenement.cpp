#include <iostream>
#include <vector>
#include "Evenement.hpp"
#include <sstream>
//test
using namespace std;


EvenementSportif::EvenementSportif() {}


EvenementSportif::EvenementSportif(int id, const std::string& nom, const std::vector<Participant>& participants)
    : _nomEvenement(nom), _participants(participants), _gagnant("--") {}


EvenementSportif::~EvenementSportif() {}


std::vector<std::string> EvenementSportif::getParticipants() const {
    std::vector<std::string> noms;
    for (const auto& participant : _participants) {
        noms.push_back(participant.getNom());
    }
    return noms;
}


std::vector<double> EvenementSportif::getParticipantCote() const {
    std::vector<double> cotes;
    for (const auto& participant : _participants) {
        cotes.push_back(participant.getCote());
    }
    return cotes;
}

void EvenementSportif:: ajoutEvenement(){
    std::cout << "Nouvel événement ajouté : " << _nomEvenement << std::endl;
}


std::string EvenementSportif::majResultats(){
    std::ostringstream detailStream;
    detailStream << "Resultats de l'evenement " << _nomEvenement << "\n";
    if (_participants.empty()) {
        detailStream << "Aucun participant dans l'evenement." << "\n";
    } 
    else {
        // Utilisation de rand() pour générer un indice aléatoire
        int indiceGagnant = rand() % _participants.size();

        detailStream << "Le gagnant est : " << _participants[indiceGagnant].getNom() << "\n" << "\n";
        _gagnant = _participants[indiceGagnant].getNom();
    }
    return detailStream.str();
}

string EvenementSportif:: getGagnant() const{
    return _gagnant;
}

string EvenementSportif:: getNomEvenement() const{
    return _nomEvenement;
}

std::string EvenementSportif::getDetails() const {
    std::ostringstream detailsStream;
    detailsStream << "Nom de l'evenement : " << _nomEvenement << "\n";
    detailsStream << "Participants :\n";
    for (const Participant& participant : _participants) {
        detailsStream << "- Nom : " << participant.getNom() << ", Cote : " << participant.getCote() << "\n";
    }
    return detailsStream.str();
}






Athletisme::Athletisme(int id, const std::string& nom, const std::vector<Participant>& participants)
    : EvenementSportif(id, nom, participants) {}

void Athletisme::afficherDetails() const {
    std::cout << "Événement d'athlétisme : " << getNomEvenement() << std::endl;
    std::cout << "Participants : ";
    for (const auto& participant : getParticipants()) {
        std::cout << participant << " ";
    }
    std::cout << std::endl;
}



Natation::Natation(int id, const std::string& nom, const std::vector<Participant>& participants, bool estRelais)
    : EvenementSportif(id, nom, participants), estRelais(estRelais) {
}

void Natation::afficherDetails() const {
    std::cout << "Événement de natation : " << getNomEvenement() << std::endl;
    std::cout << "Relais : " << (estRelais ? "Oui" : "Non") << std::endl;
    std::cout << "Participants : ";
    for (const auto& participant : getParticipants()) {
        std::cout << participant << " ";
    }
    std::cout << std::endl << std::endl;

}
