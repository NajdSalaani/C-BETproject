#include <iostream>
#include <vector>
#include "Utilisateur.hpp"



using namespace std;

Utilisateur::Utilisateur(){
}

/*Utilisateur::Utilisateur(const std::string& nom) : _nom(nom) {
}*/

Utilisateur::Utilisateur(const std::string& nom, const std::string &motDePasse) : _nom(nom), _motDePasse(motDePasse) {}

std::string Utilisateur::getNom() const {
    return _nom;
}

std::string Utilisateur::getMotDePasse() const {
    return _motDePasse;  //Pas opti niveau sécurité
}

void Utilisateur:: ajoutPari(const Pari& nouveauPari){
    _mesParis.push_back(nouveauPari);
}



void Utilisateur:: getMesParis() const{
    std::cout << "Liste de mes paris :\n";
    for (const Pari& pari : _mesParis) {
        std::cout << "Événement : " << pari.getEvenement() << "\n";
        std::cout << "Cote : " << pari.getCote() << "\n";
        std::cout << "Montant misé : " << pari.getMontant() << "\n";
        std::cout << "Statut : " << (pari.getStatut() == Statut::E ? "En cours" : (pari.getStatut() == Statut::G ? "Gagné" : "Perdu")) << "\n";
        std::cout << "Choix : " << pari.getChoix() << "\n";
        std::cout << "-------------------------\n";
        std::cout << endl;
    }
    std::cout << endl;


}