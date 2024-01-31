//compilation : g++ -c main.cpp
//Liaison avec la librairie SFML pour obtenir l' exécutable:g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
//Pour exécuter le programme : ./sfml-app 


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <ctime>
#include <sstream>
#include <stdlib.h>

#include "Utilisateur.hpp"


class Button {
public:
    Button(const sf::Vector2f& position, const std::string& text) {
        font.loadFromFile("Poppins-Black.ttf");
        buttonShape.setSize(sf::Vector2f(100, 30));
        buttonShape.setPosition(position);
        buttonShape.setFillColor(sf::Color::Blue);

        buttonText.setFont(font);
        buttonText.setString(text);
        buttonText.setCharacterSize(16);
        buttonText.setPosition(position.x + 10, position.y + 5);
    }

    bool isClicked(const sf::Vector2f& mousePos) const {
        return buttonShape.getGlobalBounds().contains(mousePos);
    }

    void draw(sf::RenderWindow& window) const{
        window.draw(buttonShape);
        window.draw(buttonText);
    }

    float getY() const {
        return buttonShape.getSize().y;
    }


private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font; // Déclaration du membre font
};




bool isValidInput(char input) {
    // Accepter les chiffres, le signe moins, le point et le backspace
    return (input >= '0' && input <= '9') || input == '.' || input == '-' || input == '\b';
}





int main() {
     srand(time(NULL)); // Initialisation du générateur de nombres aléatoires
     int fenetre = 0;
     int id = 0;

    Utilisateur utilisateur1("Alice");
    Utilisateur utilisateur2("Bob");

    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bienvenu sur OlympiBet");

    sf::Texture texture;
    if (!texture.loadFromFile("a.jpg")) {
        // Gestion de l'erreur si le chargement de l'image échoue
        return 1;
    }
    sf::Sprite sprite(texture);


    // Création des événements avec leurs participants
    std::vector<Participant> participantsAthletisme = {
        Participant("Usain Bolt", 2.0),
        Participant("Carl Lewis", 1.8),
        Participant("Jesse Owens", 1.5)
    };
    Athletisme athletisme(1, "100m hommes", participantsAthletisme);

    std::vector<Participant> participantsNatation = {
        Participant("Michael Phelps", 1.7),
        Participant("Ian Thorpe", 1.9),
        Participant("Katie Ledecky", 2.2)
    };
    Natation natation(2, "Relais 4x100m nage libre", participantsNatation, true);





    // Création du texte pour afficher les événements
    sf::Font font;
    if (!font.loadFromFile("Poppins-Black.ttf")) {
        std::cerr << "Erreur lors du chargement de la police." << std::endl;
        return 1;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    // Construction de la chaîne de caractères contenant les noms des événements
    std::string eventsText = "Evenements du jour :\n";
    text.setString(eventsText);

    // Création du texte pour afficher les événements
    sf::Text textAthletisme;
    textAthletisme.setFont(font);
    textAthletisme.setCharacterSize(24);
    textAthletisme.setFillColor(sf::Color::White);
    textAthletisme.setString(athletisme.getNomEvenement());
    textAthletisme.setPosition(0, 100);

    sf::Text textNatation;
    textNatation.setFont(font);
    textNatation.setCharacterSize(24);
    textNatation.setFillColor(sf::Color::White);
    textNatation.setString(natation.getNomEvenement());
    textNatation.setPosition(0, 150);

    sf::Text textActu;
    textActu.setFont(font);
    textActu.setCharacterSize(24);
    textActu.setFillColor(sf::Color::White);
    textActu.setPosition(200, 300);


    

    sf::Text detailsText;

    //Cadre ou rentrer du texte
    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(20);
    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition(305, 205);

    std::ostringstream inputString; // Chaîne de caractères pour stocker la saisie
    bool inputFinished = false;
    double mise = 0.0;



    // Déclaration du rectangle de saisie de texte
    sf::RectangleShape inputBox(sf::Vector2f(200, 30));
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);
    inputBox.setPosition(300, 200); //mieux que 300/500 pour la superposition entre la case et le texte




    // Boutons "Voir" pour chaque événement
    Button buttonAthletisme(sf::Vector2f(textAthletisme.getPosition().x + textAthletisme.getGlobalBounds().width + 10, textAthletisme.getPosition().y), "Voir");
    Button buttonNatation(sf::Vector2f(textNatation.getPosition().x + textNatation.getGlobalBounds().width + 10, textNatation.getPosition().y), "Voir");
    Button buttonRetour(sf::Vector2f(700, 500), "Retour");

    // Création des boutons "Parier" et "Actualiser"
    Button buttonParier(sf::Vector2f(50, 300), "Parier");
    Button buttonActualiser(sf::Vector2f(50, 400), "Actualiser");

    // Création bouton participants 
    //athlétisme
    Button buttonBolt(sf::Vector2f(20, 10), "U.Bolt");
    Button buttonLewis(sf::Vector2f(20, 50), "C.Lewis");
    Button buttonOwens(sf::Vector2f(20, 90), "J.Owens");
    //natation
    Button buttonPhelps(sf::Vector2f(20, 10), "M.Phelps");
    Button buttonThorpe(sf::Vector2f(20, 50), "I.Thorpe");
    Button buttonLedecky(sf::Vector2f(20, 90), "K.Ledecky");
    
    //Pour la page de connexion
    //Boutons utilisateurs connus
    Button buttonAlice(sf::Vector2f(550, 200), "Alice");
    Button buttonBob(sf::Vector2f(150, 200), "Bob");
    //Boutons de contrôles
    Button buttonQuit(sf::Vector2f(700, 0), "Quitter");
    Button buttonDeco(sf::Vector2f(700, 40), "LogOut");
    /*// Déclaration d'une liste de boutons pour les participants
    std::vector<Button> participantButtons;
    int positionParticipantY = 10;
    for (const auto& participant : participantsAthletisme) {
        // Création du bouton avec le nom du participant
        Button participantButton(sf::Vector2f(20, positionParticipantY), participant.getNom());
        printf(" Test : %s \n",participant.getNom());
        //Ajout du bouton à la liste
        participantButtons.push_back(participantButton);

        // Mis à jour de la position verticale
        positionParticipantY += participantButton.getY() + 10;
    }*/


    // Boucle principale de rendu
    while (window.isOpen()) {
        sf::Event event;

        //Lorsqu' un evenement est declenche
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }


            // Vérification du clic sur les boutons
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                if (buttonAthletisme.isClicked(mousePos)) {
                    std::cout << "Bouton Athlétisme cliqué !" << std::endl;
                    fenetre = 1;
                    id = 1;
                }

                if (buttonNatation.isClicked(mousePos)) {
                    std::cout << "Bouton Natation cliqué !" << std::endl;
                    fenetre = 1;
                    id = 2;
                }

                if (buttonDeco.isClicked(mousePos)) {
                    fenetre = -1;
                }

                if (buttonQuit.isClicked(mousePos)) {
                    window.close();
                }

                if (buttonRetour.isClicked(mousePos)) {
                    std::cout << "Bouton Retour cliqué !" << std::endl;
                    fenetre = 0;
                }

                 if (buttonParier.isClicked(mousePos)) {
                    std::cout << "Bouton Parier cliqué !" << std::endl;
                    fenetre = 2;
                }

                if (buttonActualiser.isClicked(mousePos)){
                    std::cout << "Bouton Actualise cliqué !" << std::endl;
                    fenetre = 3;
                    if (id == 1){
                        detailsText.setString(athletisme.getDetails());
                        textActu.setString(athletisme.majResultats());
                    }
                    else{
                        detailsText.setString(natation.getDetails());
                        textActu.setString(natation.majResultats());
                    }
                }

            }


            if(fenetre == 2){
                if (!inputFinished && event.type == sf::Event::TextEntered) {
                    if (isValidInput(event.text.unicode)) {
                        if (event.text.unicode == '\b' && !inputString.str().empty()) { // Gestion de la touche Backspace
                            std::string str = inputString.str();
                            str.erase(str.size() - 1, 1);
                            inputString.str("");
                            inputString << str;
                        } 
                        else if (event.text.unicode < 128) {
                            inputString << static_cast<char>(event.text.unicode);
                        }
                    }

                    if (event.text.unicode == '\r') { // Touche "Enter" pour terminer la saisie
                        if (!inputString.str().empty()) {
                            mise = std::stod(inputString.str());
                            inputFinished = true;
                        }
                    }
                }
            }
        }





        //Etats de la fenetre
        switch (fenetre){
        case -1 : // Fenêtre de connexion
            window.clear();
            window.draw(sprite);
            buttonAlice.draw(window);
            buttonBob.draw(window);
            buttonDeco.draw(window);
            buttonQuit.draw(window);
            
            window.display();
            
            
            break;
        case 0:
             window.clear();
            // Affichage du texte des événements
            window.draw(sprite);
            window.draw(text);
            window.draw(textAthletisme);
            window.draw(textNatation);

            // Affichage des boutons
            buttonDeco.draw(window);
            buttonQuit.draw(window);
            buttonAthletisme.draw(window);
            buttonNatation.draw(window);

            // Affichage des autres éléments de la fenêtre ici, si nécessaire

            // Affichage des modifications
            window.display();
            break;

        case 1:
            // Effacer la fenêtre
            window.clear();
            window.draw(sprite);
            detailsText.setFont(font);
            detailsText.setCharacterSize(16);
            detailsText.setFillColor(sf::Color::White);
            if (id == 1){
                detailsText.setString(athletisme.getDetails());
            }
            else{
                detailsText.setString(natation.getDetails());
            }
            detailsText.setPosition(50, 100); // Ajustez la position selon vos besoins
            window.draw(detailsText);
            buttonRetour.draw(window);
            buttonActualiser.draw(window);
            buttonParier.draw(window);
            buttonDeco.draw(window);
            buttonQuit.draw(window);
            window.display();      
            // Afficher les modifications
            break;

        case 2: 
            // Effacer la fenêtre
            window.clear();
            window.draw(sprite);

            // Affichage des boutons des participants
            /*for (const auto& button : participantButtons) {
                button.draw(window);
            }*/
            if(id == 1){
                buttonBolt.draw(window);
                buttonLewis.draw(window);
                buttonOwens.draw(window);
            } else {
                buttonPhelps.draw(window);
                buttonThorpe.draw(window);
                buttonLedecky.draw(window);
            }
             
             buttonRetour.draw(window);

            inputText.setString(inputString.str()); // Mettre à jour le texte affiché
            window.draw(inputBox);
            window.draw(inputText);

            if (!inputFinished) {
                inputText.setString(inputString.str()); // Mettre à jour le texte affiché
            }
            if (inputFinished) {
                // L'utilisateur a terminé la saisie, nous pouvons utiliser "mise" comme valeur de la mise
                std::cout << "Mise enregistrée : " << mise << std::endl;
                // Vous pouvez ajouter ici le code pour traiter la mise enregistrée
                fenetre = 0;
                //input finished = false;
                break; // Sortir de la boucle de rendu
            }

            buttonDeco.draw(window);
            buttonQuit.draw(window);

            window.display();
            // Afficher les modifications
            break;


        case 3:
            window.clear();
            window.draw(sprite);

             // Effacer la fenêtre
            detailsText.setFont(font);
            detailsText.setCharacterSize(16);
            detailsText.setFillColor(sf::Color::White);
            detailsText.setPosition(50, 100); // Ajustez la position selon vos besoins
            window.draw(textActu);
            window.draw(detailsText);
            buttonRetour.draw(window);
            buttonActualiser.draw(window);
            buttonParier.draw(window);
            buttonDeco.draw(window);
            buttonQuit.draw(window);
            window.display();      
            // Afficher les modifications
            break;

        }
        // Effacement de la fenêtre
       
    }

    return 0;
}
