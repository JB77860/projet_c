#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    typedef struct 
    {
        int bois;
        int gold;
        int matiereNoire;

    } Ressource;


    typedef struct {
        int niveau;
        int population;
        Ressource ressources;
    } HotelDeVille;


    typedef struct {
        int quantite;
    } Villageois;


    typedef struct 
    {
        int villageois;

    } Batiment;
    

    typedef struct 
    {
        Batiment scierie;
        int bois;

    } Scierie;


    typedef struct 
    {
        Batiment mine;
        int gold;

    } Mine;


     typedef struct 
    {
        Batiment raffinerie;
        int matiereNoire;

    } Raffinerie;



HotelDeVille *creerBatiment(int niveau, int population, int bois, int gold, int matiereNoire) {
    HotelDeVille *hotelDeVille = malloc(sizeof(HotelDeVille));
    hotelDeVille->niveau = niveau;
    hotelDeVille->population = population;
    hotelDeVille->ressources.bois = bois;
    hotelDeVille->ressources.gold = gold;
    hotelDeVille->ressources.matiereNoire = matiereNoire;

    return hotelDeVille;
}

Villageois *creerVillageois(int quantite) {
    Villageois *villageois = malloc(sizeof(Villageois));
    villageois->quantite = quantite;

    return villageois;
}


void detruireBatiment(HotelDeVille *hotelDeVille) {
    free(hotelDeVille);
}

void detruireVillageois(Villageois *villageois) {
    free(villageois);
}


void collecteRessource(HotelDeVille *hotelDeVille, Scierie scierie, Mine mine, Raffinerie raffinerie)
{
    hotelDeVille->ressources.bois += scierie.bois;
    hotelDeVille->ressources.gold += mine.gold;
    hotelDeVille->ressources.matiereNoire += raffinerie.matiereNoire;
}


// void affecterRessources(HotelDeVille *hotelDeVille, Villageois *villageois) {
//     if (villageois->quantite >= hotelDeVille->population) {
//         int ressourcesProduites = hotelDeVille->population * hotelDeVille->niveau;
//         hotelDeVille->ressources += ressourcesProduites;
//         villageois->quantite -= hotelDeVille->population;

//         printf("Ressources ajoutées au bâtiment : %d\n", ressourcesProduites);
//     } else {
//         printf("Pas assez de villageois pour affecter aux ressources.\n");
//     }
// }
// batiment

#endif