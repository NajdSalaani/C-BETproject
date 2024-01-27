#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fenetre.hpp"


    FenetrePari::FenetrePari(sf::RenderWindow& mainWindow) : mainWindow(mainWindow) {
        // Initialisation de la fenêtre de pari
        fenetrePari.create(sf::VideoMode(400, 300), "Fenêtre de pari", sf::Style::Default);
    }

    void FenetrePari:: afficher() {
        while (fenetrePari.isOpen()) {
            sf::Event event;
            while (fenetrePari.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    fenetrePari.close();
                }
            }

            fenetrePari.clear();
            // Dessinez le contenu de la fenêtre de pari ici
            fenetrePari.display();
        }
    }


