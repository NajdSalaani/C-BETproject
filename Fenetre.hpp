#include <iostream>
#include <SFML/Graphics.hpp>

class FenetrePari {

    public:
    FenetrePari(sf::RenderWindow& mainWindow);
    void afficher();


    private:
    sf::RenderWindow& mainWindow; // Référence vers la fenêtre principale
    sf::RenderWindow fenetrePari; // Fenêtre de pari
};