#include <iostream>
#include <vector>
#include <string>
<<<<<<< HEAD
=======
#include <list>
>>>>>>> 2e92182 (m)
#include "Pari.hpp"

class Utilisateur{
    public:
    Utilisateur();
    Utilisateur(const std::string &nom);
    std::string getNom() const;
    void ajoutPari(const Pari& nouveauPari);
    void supprimerPari(const Pari& pariASupp);
<<<<<<< HEAD
    void getMesParis() const;
=======
    std::string getMesParis() const;
    std::list<Pari> getListParis() const;
>>>>>>> 2e92182 (m)


    private:
    std::string _nom;
<<<<<<< HEAD
    std::vector<Pari> _mesParis;
=======
    std::list<Pari> _mesParis;
>>>>>>> 2e92182 (m)
};