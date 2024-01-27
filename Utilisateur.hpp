#include <iostream>
#include <vector>
#include <string>
#include "Pari.hpp"

class Utilisateur{
    public:
    Utilisateur();
    Utilisateur(const std::string &nom);
    std::string getNom() const;
    void ajoutPari(const Pari& nouveauPari);
    void supprimerPari(const Pari& pariASupp);
    void getMesParis() const;


    private:
    std::string _nom;
    std::vector<Pari> _mesParis;
};