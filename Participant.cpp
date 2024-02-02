#include <iostream>
#include "Participant.hpp"
using namespace std;

Participant::Participant() : _nom(""), _cote(0.0) {}

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
            this->_nom = autre._nom;
            this->_cote = autre._cote;
        }
        return *this;
    }

//Test d' egalite entre les attributs de 2 instances Participant
 bool Participant::operator==(const Participant& autre) const {
        return (this->_nom == autre._nom && this->_cote == autre._cote);
    }