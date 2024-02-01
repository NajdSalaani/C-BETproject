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

    sf::Text getNom() const{
        return buttonText;
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
     int fenetre = -1;
     int id = 0;
     int compte = 0; //Permet le controle en fonction de l'utilisateur connecté : 0 aucun , 1 Alice , 2 Bob
     
     int idPari = 0;
     Participant choix_participant("", 0.0);


    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "OlympiBet");

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
    Natation natation(2, "100m nage libre", participantsNatation, true);



                
    Pari nouveauPari1(0, 0.0, Statut::E, athletisme, participantsAthletisme[0]);
    Pari nouveauPari2(0, 0.0, Statut::E, athletisme, participantsAthletisme[0]);

    Utilisateur utilisateur1("Alice","1234", nouveauPari1);
    Utilisateur utilisateur2("Bob","2605", nouveauPari2);





    // Création du texte pour afficher les événements
    sf::Font font;
    if (!font.loadFromFile("Poppins-Black.ttf")) {
        std::cerr << "Erreur lors du chargement de la police." << std::endl;
        return 1;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Blue);

    // Construction de la chaîne de caractères contenant les noms des événements
    std::string eventsText = "Evenements du jour :\n";
    std::string choixDuJour = "Choisissez votre vainqueur";
    text.setString(eventsText);

    

    // Création du texte pour afficher les événements
    sf::Text textAthletisme;
    textAthletisme.setFont(font);
    textAthletisme.setCharacterSize(24);
    textAthletisme.setFillColor(sf::Color::Blue);
    textAthletisme.setString(athletisme.getNomEvenement());
    textAthletisme.setPosition(0, 100);

    sf::Text textNatation;
    textNatation.setFont(font);
    textNatation.setCharacterSize(24);
    textNatation.setFillColor(sf::Color::Blue);
    textNatation.setString(natation.getNomEvenement());
    textNatation.setPosition(0, 150);

    sf::Text textActu;
    textActu.setFont(font);
    textActu.setCharacterSize(24);
    textActu.setFillColor(sf::Color::Blue);
    textActu.setPosition(200, 300);

    sf::Text textchoix;
    textchoix.setFont(font);
    textchoix.setCharacterSize(24);
    textchoix.setFillColor(sf::Color::Blue);
    textchoix.setPosition(200, 300);
    textchoix.setString(choixDuJour);

    sf::Text textResultatsParis;
    textResultatsParis.setFont(font);
    textResultatsParis.setCharacterSize(24);
    textResultatsParis.setFillColor(sf::Color::Blue);
    textResultatsParis.setPosition(200, 100);

   
    

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
    inputBox.setFillColor(sf::Color::Blue);
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
    
    // Déclaration d'une liste de boutons pour les participants

    
    
    //Pour la page de connexion
    // Création du texte pour la page de connexion

    sf::Text textConnexionAccueil;
    textConnexionAccueil.setFont(font);
    textConnexionAccueil.setCharacterSize(24);
    textConnexionAccueil.setFillColor(sf::Color::Blue);
    textConnexionAccueil.setString(
    "Bienvenue sur OlympiBet !!! \n   Choisissez votre compte :"
    );
    textConnexionAccueil.setPosition(200, 100);

    sf::Text textConnexionMDP;
    textConnexionMDP.setFont(font);
    textConnexionMDP.setCharacterSize(24);
    textConnexionMDP.setFillColor(sf::Color::Blue);
    textConnexionMDP.setString(
    ""
    );
    textConnexionMDP.setPosition(175, 100);

    //Boutons utilisateurs connus
    Button buttonAlice(sf::Vector2f(550, 200), "Alice");
    Button buttonBob(sf::Vector2f(150, 200), "Bob");
    //Boutons de contrôles
    Button buttonQuit(sf::Vector2f(700, 0), "Quitter");
    Button buttonDeco(sf::Vector2f(700, 40), "LogOut");
    //Rectangle pour saisie du mot de passe 
    // Déclaration de la zone de saisie du mot de passe
    sf::Text mdpText;
    mdpText.setFont(font);
    mdpText.setCharacterSize(20);
    mdpText.setFillColor(sf::Color::Black);
    mdpText.setPosition(305, 255); 

    sf::Text erreurText;
    erreurText.setFont(font);
    erreurText.setCharacterSize(20);
    erreurText.setFillColor(sf::Color::Red);
    erreurText.setPosition(150, 300); 
    erreurText.setString("");


    sf::RectangleShape mdpBox(sf::Vector2f(200, 30));
    mdpBox.setFillColor(sf::Color::Blue);
    mdpBox.setOutlineColor(sf::Color::Black);
    mdpBox.setOutlineThickness(2);
    mdpBox.setPosition(300, 250);

    //Variables pour la saisie et la comparaison des mots de passe 
    bool mdpInputFinished = false; //etat de la saisie , true si finie
    std::ostringstream mdpInputString; //utile pour afficher ce que l'utilisateur saisie
    std::string mdp; //Pour comparer avec le mot passe du compte

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

    Button ButtonMonPari(sf::Vector2f(100, 200), "Mon Pari");

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
                    detailsText.setString(athletisme.getDetails());
                    textActu.setString(athletisme.majResultats());
                    fenetre = 1;
                    id = 1;
                }

                if (buttonNatation.isClicked(mousePos)) {
                    std::cout << "Bouton Natation cliqué !" << std::endl;
                    detailsText.setString(natation.getDetails());
                    textActu.setString(natation.majResultats());
                    fenetre = 1;
                    id = 2;
                }

                if (buttonAlice.isClicked(mousePos)) {
                    compte = 2;
                    //Pour ne pas prendre en compte d'ancienne saisies
                    mdpInputFinished = false;
                    mdpInputString.str("");
                    mdp.clear();
                    erreurText.setString("");                   
                }

                if (buttonBob.isClicked(mousePos)) {
                    compte = 1;
                    //Pour ne pas prendre en compte d'ancienne saisies
                    mdpInputFinished = false;
                    mdpInputString.str("");
                    mdp.clear();
                    erreurText.setString("");
                    
                }

                if (buttonDeco.isClicked(mousePos)) {
                    fenetre = -1;
                    compte = 0;
                    //Pour ne pas prendre en compte d'ancienne saisies
                    mdpInputFinished = false;
                    mdpInputString.str("");
                    mdp.clear();
                    erreurText.setString("");
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
                        if(compte == 1){
                            nouveauPari1.resultatPari();
                            textResultatsParis.setString(nouveauPari1.detailPari());
                        }
                        else{
                            nouveauPari2.resultatPari();
                            textResultatsParis.setString(nouveauPari2.detailPari());
                        }

                    }
                    else{
                        if(compte == 1){
                            nouveauPari1.resultatPari();
                            textResultatsParis.setString(nouveauPari1.detailPari());
                        }
                        else{
                            nouveauPari2.resultatPari();
                            textResultatsParis.setString(nouveauPari2.detailPari());
                        }
                    }

                }

                if(id == 1){
                    if (buttonBolt.isClicked(mousePos)) {
                        choix_participant = participantsAthletisme[0];
                        fenetre = 4;
                    } 
                    else if (buttonLewis.isClicked(mousePos)) {
                        choix_participant = participantsAthletisme[1];
                        fenetre = 4;
                    } 
                    else if (buttonOwens.isClicked(mousePos)) {
                        choix_participant = participantsAthletisme[2];
                        fenetre = 4;
                    } 
                }
                else{
                    if (buttonPhelps.isClicked(mousePos)) {
                        choix_participant = participantsNatation[0];
                        fenetre = 4;
                    } 
                    else if (buttonThorpe.isClicked(mousePos)) {
                        choix_participant = participantsNatation[1];
                        fenetre = 4;
                    } 
                    else if (buttonLedecky.isClicked(mousePos)) {
                        choix_participant = participantsNatation[2];
                        fenetre = 4;
                    }
                }

                if(ButtonMonPari.isClicked(mousePos)){
                    std::cout << "Bouton MonPari clique!" << std::endl;
                    if(compte == 1){
                        textResultatsParis.setString(nouveauPari1.detailPari());
                    }
                    else{
                        textResultatsParis.setString(nouveauPari2.detailPari());
                    }
                    fenetre = 5;
                }



                

            }


            if (fenetre == -1) {  //Page de connexion
            if (!mdpInputFinished && event.type == sf::Event::TextEntered) {
                if (isValidInput(event.text.unicode)) {
                    if (event.text.unicode == '\b' && !mdpInputString.str().empty()) {
                        std::string str = mdpInputString.str();
                        str.erase(str.size() - 1, 1);
                        mdpInputString.str("");
                        mdpInputString << str;
                    } else if (event.text.unicode < 128) {
                        mdpInputString << static_cast<char>(event.text.unicode);
                    }
                }

                if (event.text.unicode == '\r') {  // Touche "Enter" pour terminer la saisie
                    if (!mdpInputString.str().empty()) {
                        mdp = mdpInputString.str();
                        mdpInputFinished = true;
                        }
                    }
                }   
            }

           

            if(fenetre == 4){
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
            if( compte != 0){
             window.draw(mdpBox);
             window.draw(mdpText);
             window.draw(erreurText);
             
             if(compte == 1){
                textConnexionMDP.setString("Tapez le mot de passe du compte de Bob");
                
             } else {
                textConnexionMDP.setString("Tapez le mot de passe du compte d'Alice");
                
             }
             window.draw(textConnexionMDP);
             //On met en place maintenant la saisie du mot de passe :
             
             if (!mdpInputFinished) {
                mdpText.setString(mdpInputString.str());
             }
             if (mdpInputFinished) {
                
                // On vérifie la conformité du mot de passe
                if( compte == 1 && mdp == utilisateur1.getMotDePasse()){
                    fenetre = 0;
                }
                else if( compte == 2 && mdp == utilisateur2.getMotDePasse()){
                    fenetre = 0;
                }
                else{
                    erreurText.setString( "Erreur de mot de passe" );
                }
                // Réinitialisez les variables pour la prochaine saisie , ici car sinon si pas dans ce if cela bloque la saisie en effaçant constamment
                // On le fait aussi en code de déconnexion par bouton
                mdpInputFinished = false;
                mdpInputString.str("");
                mdp.clear();
                
             }
            }
            else {
                window.draw(textConnexionAccueil);
            }

            

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


            //Répétition Nécessaire ? ex deco ou quit 
            buttonAthletisme.draw(window);
            buttonNatation.draw(window);
            ButtonMonPari.draw(window);
            buttonDeco.draw(window);
            buttonQuit.draw(window);
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
            detailsText.setFillColor(sf::Color::Blue);
            if (id == 1){
                if(compte == 1){
                detailsText.setString(athletisme.getDetails());
                nouveauPari1.setEvenement(athletisme);
                }
                else{
                   detailsText.setString(athletisme.getDetails());
                   nouveauPari2.setEvenement(athletisme); 
                }
            }
            else{
                if(compte == 1){
                detailsText.setString(natation.getDetails());
                nouveauPari1.setEvenement(natation);
                }
                else{
                   detailsText.setString(natation.getDetails());
                   nouveauPari2.setEvenement(natation); 
                }
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
                inputFinished = false;
                break; // Sortir de la boucle de rendu
            }

            buttonDeco.draw(window);
            buttonQuit.draw(window);

        
            // Afficher les modifications
            //ICI pas compris pourquoi tu break avant , ptet que c'est puisque c'est pas encore au point après cette ligne 
            window.draw(textchoix);
            buttonDeco.draw(window);
            buttonQuit.draw(window); 
            window.display();
            break;
            //


        case 3:
            window.clear();
            window.draw(sprite);

             // Effacer la fenêtre
            detailsText.setFont(font);
            detailsText.setCharacterSize(16);
            detailsText.setFillColor(sf::Color::Blue);
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
        case 4:
           // Effacer la fenêtre
            window.clear();
            window.draw(sprite);

             buttonRetour.draw(window);

            inputText.setString(inputString.str()); // Mettre à jour le texte affiché
            window.draw(inputBox);
            window.draw(inputText);
            buttonDeco.draw(window);
            buttonQuit.draw(window); 

            if (!inputFinished) {
                inputText.setString(inputString.str()); // Mettre à jour le texte affiché
            }
            if (inputFinished) {
                std::cout << "Mise enregistrée : " << mise << std::endl;

                Statut statutInitial = Statut::E; // Assumant que le statut initial est en cours


                if(compte == 1){
                    nouveauPari1.modifPari(idPari, mise, statutInitial, choix_participant);
                }
                else{
                    nouveauPari2.modifPari(idPari, mise, statutInitial, choix_participant);
                }
                // Créez une instance de Pari avec les informations obtenues
                

                // Manipulez l'instance de Pari selon vos besoins
              

                mise = 0.0;
                idPari ++;


                fenetre = 0;
                break; 
            }
            

            window.display();
            break;

        case 5:
            window.clear();
            window.draw(sprite);
            window.draw(textResultatsParis);
            buttonRetour.draw(window);
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
