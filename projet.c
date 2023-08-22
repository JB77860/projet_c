#include "struct.h"

int main() {
    HotelDeVille *hotelDeVille = creerBatiment(1, 20, 20, 20, 0);
    Villageois *villageois = creerVillageois(20);  // Départ avec 20 villageois

    Scierie scierie;
    scierie.scierie.villageois = 2;
    scierie.bois = 10;

    Mine mine;
    mine.mine.villageois = 3;
    mine.gold = 20;

    Raffinerie raffinerie;
    raffinerie.raffinerie.villageois = 5;
    raffinerie.matiereNoire = 10;

    Batiment caserne;
    caserne.villageois = 4;

    int choix;
    do {
        printf("1. Afficher les informations de l'hotel de ville et des villageois\n");
        printf("2. Modifier le nombre de personnes dans l'hotel de ville\n");
        printf("3. Modifier le nombre de ressources dans l'hotel de ville\n");
        printf("4. Modifier le nombre de villageois disponibles\n");
        printf("5. Afficher les informations des bâtiments\n");
        printf("6. Modifier les ressources d'un bâtiment\n");
        printf("7. Collecter les ressources des bâtiments\n");
        printf("8. Créer un bâtiment\n");
        printf("0. Quitter\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Niveau de l'hotel de ville : %d\n", hotelDeVille->niveau);
                printf("Population de l'hotel de ville : %d\n", hotelDeVille->population);
                printf("Nombre de villageois disponibles : %d\n", villageois->quantite);
                printf("Bois disponible: %d\n", hotelDeVille->ressources.bois);
                printf("Or disponible : %d\n", hotelDeVille->ressources.gold);
                printf("Matière noire disponible : %d\n", hotelDeVille->ressources.matiereNoire);
    
                break;
            case 2:
                printf("Entrez le nouveau nombre de personnes dans l'hotel de ville : ");
                scanf("%d", &hotelDeVille->population);
                break;
            case 3:
                printf("Entrez le nouveau nombre de ressources dans l'hotel de ville : ");
                scanf("%d", &hotelDeVille->ressources);
                break;
            case 4:
                printf("Entrez le nouveau nombre de villageois disponibles : ");
                scanf("%d", &villageois->quantite);
                break;
            case 5:
                printf("Choisissez un bâtiment :\n");
                printf("1. Scierie\n");
                printf("2. Mine\n");
                printf("3. Raffinerie\n");
                int choixBatiment;
                scanf("%d", &choixBatiment);


                switch (choixBatiment) {
                    case 1:
                            printf("Bois collecté : %d\nVillageois dans la scierie : %d\n", scierie.bois, scierie.scierie.villageois);
                        
                        break;
                    case 2:
                            printf("Or collecté : %d\nVillageois dans la mine : %d\n", mine.gold, mine.mine.villageois);                        
                        break;
                    case 3:
                            printf("Matière noire collectée : %d\nVillageois dans la raffinerie : %d\n", raffinerie.matiereNoire, raffinerie.raffinerie.villageois);                        
                        break;
                    default:
                        printf("Choix de bâtiment invalide\n");
                }

            case 6:
                // Modifier les ressources d'un bâtiment
                int choixBatimentRessources;
                printf("Choisissez un bâtiment pour modifier les ressources :\n");
                printf("1. Scierie\n");
                printf("2. Mine\n");
                printf("3. Raffinerie\n");
                scanf("%d", &choixBatimentRessources);

                int quantiteRessources;
                printf("Entrez la quantité de ressources à ajouter : ");
                scanf("%d", &quantiteRessources);

                switch (choixBatimentRessources) {
                    case 1:
                        scierie.bois += quantiteRessources; // Ajouter la quantité de bois à la scierie
                        break;

                    case 2:
                        mine.gold += quantiteRessources; // Ajouter la quantité d'or à la mine
                        break;

                    case 3:
                        raffinerie.matiereNoire += quantiteRessources; // Ajouter la quantité de matière noire à la raffinerie
                        break;

                    default:
                        printf("Choix de bâtiment invalide\n");
                }
                break;

                
            case 7:
                collecteRessource(hotelDeVille, scierie, mine, raffinerie);
                break;

            case 8:
                printf("Choisissez un bâtiment à construire :\n");
                printf("1. Scierie\n");
                printf("2. Mine\n");
                printf("3. Raffinerie\n");
                
                break;
            default:

                printf("Choix invalide\n");
        }


    } while (choix != 0);

    detruireBatiment(hotelDeVille);
    detruireVillageois(villageois);

    return 0;
}
