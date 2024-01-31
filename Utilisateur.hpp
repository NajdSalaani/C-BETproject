#include <iostream>
#include <vector>
#include <string>
#include "Pari.hpp"

class Utilisateur{
    public:
    Utilisateur();
    Utilisateur(const std::string &nom,const std::string& motDePasse);
    std::string getNom() const;
    std::string getMotDePasse() const;
    void ajoutPari(const Pari& nouveauPari);
    void supprimerPari(const Pari& pariASupp);
    void getMesParis() const;


    private:
    std::string _nom;
    std::string _motDePasse;
    std::vector<Pari> _mesParis;

};