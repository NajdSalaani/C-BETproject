#include <iostream>
#include <vector>
#include <string>
#include "Pari.hpp"

//Classe qui definit l' utilisateur qui va faire un pari
class Utilisateur{
    public:
    Utilisateur(const std::string& nom, const std::string& motDePasse);
    Utilisateur(const std::string &nom,const std::string& motDePasse, const Pari& pari);
    std::string getNom() const;
    std::string getMotDePasse() const;
    void ajoutPari(const Pari& nouveauPari);
    void supprimerPari(const Pari& pariASupp);
     std::string getMonPari() const;
    Pari monPari() const;


    private:
    std::string _nom;
    std::string _motDePasse;
    Pari _pari;

};