//compilation : g++ -c main.cpp
//Liaison avec la librairie SFML pour obtenir l' exécutable:g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
//Pour exécuter le programme : ./sfml-app 


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <ctime>



#include "Utilisateur.hpp"


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

