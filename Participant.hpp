#include <iostream>
#include <string>

class Participant {
public:
Participant();
    Participant(const std::string& nom, double cote);

    std::string getNom() const;
    double getCote() const;
    Participant& operator=(const Participant& autre);
    bool operator==(const Participant& autre) const;


private:
    std::string _nom;
    double _cote;
};