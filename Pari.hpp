#include <iostream>
#include <vector>
#include <list>
#include "Evenement.hpp"


enum class Statut{
    G,
    P,
    E,
};


class Pari{
    public:
<<<<<<< HEAD
    Pari(int id, double montant, Statut statut, EvenementSportif& evenement, const std::list<Participant>& participants);
=======
    Pari(int id, double montant, Statut statut, EvenementSportif& evenement, const Participant& participant);
>>>>>>> 2e92182 (m)
    int getId();
    void modifCote();
    void ajouterParticipant(const Participant& participant);
    void supprimerParticipant(const Participant& participant);
    void annulerPari();
<<<<<<< HEAD
    void ResultatPari(const EvenementSportif& evenement);
    void detailPari() const;
=======
    void resultatPari();
    std::string detailPari() const;
>>>>>>> 2e92182 (m)
    std::string getEvenement() const;
    double getCote() const;
    double getMontant() const;
    Statut getStatut() const;
    std::string getChoix() const;
    void mettreMontant(double montant);
    
    
    protected:
    int _id;
    double _montantMise;
    double _cote;
    Statut _statut;
    EvenementSportif&  _evenement;
<<<<<<< HEAD
    std::list<Participant> _participantsChoisis;
=======
    Participant _participantChoisi;
>>>>>>> 2e92182 (m)

};



class Combine : public Pari {
public:
    Combine(const std::list<EvenementSportif*>& evenements);
    Combine(int id, double montant, Statut statut, const std::list<EvenementSportif*>& evenements, const std::list<Participant>& participants);
    ~Combine();
    void ajouterEvenement(EvenementSportif* evenement);
    void retirerEvenement(EvenementSportif* evenement);
    void modifCote();
    void ajouterParticipant(const Participant& participant);
    void supprimerParticipant(const Participant& participant);
    void ResultatPari(const std::list< EvenementSportif*>& listeEvenement);
    void detailPari() const;

private:
    std::list<EvenementSportif*> _listeEvenements;
};
