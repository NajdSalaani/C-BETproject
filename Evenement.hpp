#include <iostream>
#include <vector>
#include "Participant.hpp"

class EvenementSportif {
public:
    EvenementSportif();
    EvenementSportif(const std::string& nom, const std::vector<Participant>& participants);
    virtual ~EvenementSportif();

    std::vector<std::string> getParticipants() const;
    std::vector<double> getParticipantCote() const;
    void ajoutEvenement();
    void majResultats();
    std::string getGagnant() const;
    std:: string getNomEvenement() const;
    std::string getDetails() const;

    virtual void afficherDetails() const = 0;


protected:
    std::string _nomEvenement;
    std::vector<Participant> _participants;
    std::string _gagnant;
};



class Athletisme : public EvenementSportif {
public:
    Athletisme(const std::string& nom, const std::vector<Participant>& participants);

    void afficherDetails() const override;

private:
};


class Natation : public EvenementSportif {
public:
    Natation(const std::string& nom, const std::vector<Participant>& participants, bool estRelais);
    void afficherDetails() const override;

private:
    bool estRelais;
};