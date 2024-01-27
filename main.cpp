//compilation : g++ -c main.cpp
//Liaison avec la librairie SFML pour obtenir l' exécutable:g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
//Pour exécuter le programme : ./sfml-app 


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <ctime>
#include <sstream>



#include "Utilisateur.hpp"
#include "Fenetre.hpp"

/*
//Test sans interface graphique
int main(){
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires

    Utilisateur utilisateur1("Alice");
    Utilisateur utilisateur2("Bob");

    // Création d'événements d'athlétisme et de natation avec leurs participants
    std::vector<Participant> participantsAthletisme = {
        Participant("Usain Bolt", 2.0),
        Participant("Carl Lewis", 1.8),
        Participant("Jesse Owens", 1.5)
    };
    Athletisme athletisme("100m hommes", participantsAthletisme);

    std::vector<Participant> participantsNatation = {
        Participant("Michael Phelps", 1.7),
        Participant("Ian Thorpe", 1.9),
        Participant("Katie Ledecky", 2.2)
    };
    Natation natation("Relais 4x100m nage libre", participantsNatation, true);

    // Affichage des détails des événements
    athletisme.afficherDetails();
    natation.afficherDetails();

    // Interaction avec l'utilisateur pour choisir s'il souhaite faire un pari combiné ou non
    std::string choixCombine;
    std::cout << "Voulez-vous faire un pari combiné ? (oui/non) : ";
    std::cin >> choixCombine;

    if (choixCombine == "oui") {
        // Création d'un pari combiné
        Combine* nouveauPariCombine = nullptr;

        // Interaction avec l'utilisateur pour choisir la discipline pour le pari combiné
        std::string discipline;
        std::cout << "Choisissez la discipline pour le pari combiné (athletisme/natation) : ";
        std::cin >> discipline;

        std::cin.ignore(); // Pour consommer le caractère '\n' restant dans le flux d'entrée

        // Définition des événements choisis en fonction de la discipline
        std::list<EvenementSportif*> evenementsChoisis;
        if (discipline == "athletisme") {
            evenementsChoisis.push_back(&athletisme);
        } else if (discipline == "natation") {
            evenementsChoisis.push_back(&natation);
        } else {
            std::cout << "Discipline non reconnue." << std::endl;
            return 1;
        }

        // Demander à l'utilisateur le montant du pari combiné
        double montantCombine;
        std::cout << "Entrez le montant que vous souhaitez miser pour le pari combiné : ";
        std::cin >> montantCombine;

        // Création du pari combiné
        nouveauPariCombine = new Combine(1, montantCombine, Statut::E, evenementsChoisis, {});

        // Demander à l'utilisateur s'il souhaite ajouter des participants à son pari combiné
        std::string choixAjoutParticipants;
        std::cout << "Voulez-vous ajouter des participants à votre pari combiné ? (oui/non) : ";
        std::cin >> choixAjoutParticipants;

        if (choixAjoutParticipants == "oui") {
            // Demander à l'utilisateur le nombre de participants à ajouter
            int nbParticipants;
            std::cout << "Combien de participants voulez-vous ajouter à votre pari combiné ? : ";
            std::cin >> nbParticipants;

            // Affichage des participants avec leur numéro
            std::cout << "Liste des participants disponibles :\n";
            const std::vector<std::string>& participants = evenementsChoisis.front()->getParticipants();
            for (size_t i = 0; i < participants.size(); ++i) {
                std::cout << i + 1 << ". " << participants[i] << std::endl;
            }

            // Sélection des participants à ajouter
            for (int i = 0; i < nbParticipants; ++i) {
                int choixParticipant;
                std::cout << "Sur quel participant voulez-vous miser (entrez le numéro) : ";
                std::cin >> choixParticipant;

                // Vérifier si l'allocation de mémoire a réussi
                Participant* nouveauParticipant = new (std::nothrow) Participant(participants[choixParticipant - 1], evenementsChoisis.front()->getParticipantCote()[choixParticipant - 1]);
                if (nouveauParticipant) {
                    // Ajouter le participant choisi à la liste des participants pour le pari
                    nouveauPariCombine->ajouterParticipant(*nouveauParticipant);
                } else {
                    std::cout << "Erreur : Échec de l'allocation de mémoire pour le participant." << std::endl;
                    // Gérer l'erreur d'allocation de mémoire ici
                }
            }
        }

        // Ajout du pari combiné à l'utilisateur
        utilisateur1.ajoutPari(*nouveauPariCombine);

        // Affichage des paris de l'utilisateur
        utilisateur1.getMesParis();

        // Mise à jour des résultats des paris avec les résultats aléatoires des événements
        for (auto evenement : evenementsChoisis) {
            evenement->majResultats();
        }

        // Affichage des détails mis à jour des paris
        nouveauPariCombine->ResultatPari(evenementsChoisis);
        nouveauPariCombine->detailPari();

        // Affichage du gain en cas de victoire
        if (nouveauPariCombine->getStatut() == Statut::G) {
            double gain = montantCombine * nouveauPariCombine->getCote();
            std::cout << "Vous avez gagné " << gain << " euros !" << std::endl;
        }

        // Libération de la mémoire du pari combiné
        delete nouveauPariCombine;
    } else {
        // Interaction avec l'utilisateur pour placer un pari simple
        // Le code pour le pari simple reste à ajouter ici...
    }

    return 0;
}
*/


//Test avec interface graphqque
int main() {
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires

    Utilisateur utilisateur1("Alice");
    Utilisateur utilisateur2("Bob");

    // Création d'événements d'athlétisme et de natation avec leurs participants
    std::vector<Participant> participantsAthletisme = {
        Participant("Usain Bolt", 2.0),
        Participant("Carl Lewis", 1.8),
        Participant("Jesse Owens", 1.5)
    };
    Athletisme athletisme("100m hommes", participantsAthletisme);

    std::vector<Participant> participantsNatation = {
        Participant("Michael Phelps", 1.7),
        Participant("Ian Thorpe", 1.9),
        Participant("Katie Ledecky", 2.2)
    };
    Natation natation("Relais 4x100m nage libre", participantsNatation, true);

    // Affichage des détails des événements
    std::string detailsAthletisme = athletisme.getDetails();
    std::string detailsNatation = natation.getDetails();

    // Création de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "BETS");

    // Création des polices et des textes pour afficher les détails des événements
    sf::Font font;
    if (!font.loadFromFile("Poppins-Black.ttf")) {
        std::cerr << "Impossible de charger la police Arial" << std::endl;
        return 1;
    }

    sf::Text textAthletisme(detailsAthletisme, font, 20);
    textAthletisme.setPosition(50.f, 50.f);

    sf::Text textNatation(detailsNatation, font, 20);
    textNatation.setPosition(50.f, 200.f);

   // Création du bouton pour parier
sf::RectangleShape bouton(sf::Vector2f(200.f, 50.f)); // Définissez la taille du bouton
bouton.setFillColor(sf::Color::Green); // Couleur du bouton
bouton.setPosition(50.f, 500.f); // Position du bouton

// Création du texte pour le bouton
sf::Text textBouton("Parier", font, 20);
textBouton.setPosition(75.f, 510.f); // Position du texte à l'intérieur du bouton

// Création du texte pour afficher l'événement
sf::Text textEvenement("Détails de l'événement", font, 24);
textEvenement.setPosition(50.f, 350.f); // Position du texte pour l'événement


// Boucle principale de rendu
while (window.isOpen()) {
    // Gestion des événements
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        // Gestion du clic de souris pour le bouton
        // Gestion du clic de souris pour le bouton
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mousePositionF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
                if (bouton.getGlobalBounds().contains(mousePositionF)) {
                    // Action à effectuer lors du clic sur le bouton (par exemple, ouvrir la fenêtre de pari)
                    FenetrePari fenetrePari(window);
                    fenetrePari.afficher();
                }
            }
        }
    }

    // Effacement de la fenêtre
    window.clear();

    // Dessin des éléments
    window.draw(textAthletisme);
    window.draw(textNatation);
    window.draw(textEvenement);
    window.draw(bouton);
    window.draw(textBouton);

    // Affichage de la fenêtre
    window.display();
}

    return 0;
}
