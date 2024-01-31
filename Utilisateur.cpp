#include <iostream>
#include <vector>
<<<<<<< HEAD
=======
#include<sstream>
>>>>>>> 2e92182 (m)
#include "Utilisateur.hpp"



using namespace std;

Utilisateur::Utilisateur(){
}

Utilisateur::Utilisateur(const std::string& nom) : _nom(nom) {
}

std::string Utilisateur::getNom() const {
    return _nom;
}


void Utilisateur:: ajoutPari(const Pari& nouveauPari){
    _mesParis.push_back(nouveauPari);
}



<<<<<<< HEAD
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
=======
std::string Utilisateur:: getMesParis() const{
    std::ostringstream detailsStream;
    detailsStream << "Liste de mes paris :\n";
    for (const Pari& pari : _mesParis) {
        if (pari.getStatut() == Statut::E){printf("bnojour");}
        detailsStream << "Evenement : " << pari.getEvenement() << "\n";
        detailsStream << "Cote : " << pari.getCote() << "\n";
        detailsStream << "Montant mise : " << pari.getMontant() << "\n";
        detailsStream << "Statut : " << (pari.getStatut() == Statut::E ? "En cours" : (pari.getStatut() == Statut::G ? "Gagne" : "Perdu")) << "\n";
        detailsStream << "Choix : " << pari.getChoix() << "\n";
        detailsStream << "-------------------------\n";
        detailsStream << endl;
    }
    std::cout << endl;
    return detailsStream.str();
}


std::list<Pari> Utilisateur:: getListParis() const{
    std::list<Pari> listeParis;
        for (const auto& paris : _mesParis) {
            listeParis.push_back(paris);
        }
        return listeParis;
    }
>>>>>>> 2e92182 (m)
