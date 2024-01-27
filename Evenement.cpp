#include <iostream>
#include <vector>
#include "Evenement.hpp"
#include <sstream>

using namespace std;


EvenementSportif::EvenementSportif() {}


EvenementSportif::EvenementSportif(const std::string& nom, const std::vector<Participant>& participants)
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


void EvenementSportif::majResultats(){
    std::cout << "Résultats de l'événement " << _nomEvenement << std::endl;
    if (_participants.empty()) {
        std::cout << "Aucun participant dans l'événement." << std::endl;
    } 
    else {
        // Utilisation de rand() pour générer un indice aléatoire
        int indiceGagnant = rand() % _participants.size();

        std::cout << "Le gagnant est : " << _participants[indiceGagnant].getNom() << std::endl << std::endl;
        _gagnant = _participants[indiceGagnant].getNom();
    }
}

string EvenementSportif:: getGagnant() const{
    return _gagnant;
}

string EvenementSportif:: getNomEvenement() const{
    return _nomEvenement;
}

std::string EvenementSportif::getDetails() const {
    std::ostringstream detailsStream;
    detailsStream << "Nom de l'événement : " << _nomEvenement << "\n";
    detailsStream << "Participants :\n";
    for (const Participant& participant : _participants) {
        detailsStream << "- Nom : " << participant.getNom() << ", Cote : " << participant.getCote() << "\n";
    }
    return detailsStream.str();
}






Athletisme::Athletisme(const std::string& nom, const std::vector<Participant>& participants)
    : EvenementSportif(nom, participants) {}

void Athletisme::afficherDetails() const {
    std::cout << "Événement d'athlétisme : " << getNomEvenement() << std::endl;
    std::cout << "Participants : ";
    for (const auto& participant : getParticipants()) {
        std::cout << participant << " ";
    }
    std::cout << std::endl;
}



Natation::Natation(const std::string& nom, const std::vector<Participant>& participants, bool estRelais)
    : EvenementSportif(nom, participants), estRelais(estRelais) {
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