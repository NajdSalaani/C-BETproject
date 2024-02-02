#include <iostream>
#include <vector>
#include <sstream>
#include "Utilisateur.hpp"



using namespace std;


Utilisateur::Utilisateur(const std::string& nom, const std::string &motDePasse, const Pari &pari) : _nom(nom), _motDePasse(motDePasse), _pari(pari) {}

std::string Utilisateur::getNom() const {
    return _nom;
}

std::string Utilisateur::getMotDePasse() const {
    return _motDePasse;  //Renvoi le mot de passe
}



void Utilisateur:: ajoutPari(const Pari& nouveauPari){
    _pari = nouveauPari;
}

//Affiche les details du pari de l' utilisateur
std::string Utilisateur:: getMonPari() const{
    std::ostringstream detailsStream;
    detailsStream << "Mon pari :\n";
    if (_pari.getStatut() == Statut::E)
    detailsStream << "Evenement : " << _pari.getEvenement() << "\n";
    detailsStream << "Cote : " << _pari.getCote() << "\n";
    detailsStream << "Montant mise : " << _pari.getMontant() << "\n";
    detailsStream << "Statut : " << (_pari.getStatut() == Statut::E ? "En cours" : (_pari.getStatut() == Statut::G ? "Gagne" : "Perdu")) << "\n";
    detailsStream << "Choix : " << _pari.getChoix() << "\n";
    detailsStream << "-------------------------\n";
    detailsStream << endl;
    std::cout << endl;
    return detailsStream.str();
}


Pari Utilisateur:: monPari() const{
    return _pari;
}