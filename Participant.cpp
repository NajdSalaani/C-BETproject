#include <iostream>
#include "Participant.hpp"
using namespace std;


Participant::Participant(const std::string& nom, double cote)
    : _nom(nom), _cote(cote) {}

std::string Participant::getNom() const {
    return _nom;
}

double Participant::getCote() const {
    return _cote;
}

 Participant& Participant::operator=(const Participant& autre) {
        // Vérifier l'auto-attribution
        if (this != &autre) {
            // Copier les attributs de l'autre participant dans le participant actuel
            this->_nom = autre._nom;
            this->_cote = autre._cote;
            // Copiez d'autres attributs si nécessaire
        }
        return *this;
    }


 bool Participant::operator==(const Participant& autre) const {
        // Comparer les attributs pertinents pour déterminer l'égalité
        return (this->_nom == autre._nom && this->_cote == autre._cote);
    }