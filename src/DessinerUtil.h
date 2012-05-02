#ifndef DESSINERUTIL_H
#define	DESSINERUTIL_H

#include <string>
#include <iostream>

#include "colors.h"

using namespace std;

/**
 * Classe utilitaire permettant de faciliter l'écriture de texte et de fonds
 * sur une console.
 */
class DessinerUtil {
public:

    // --- Dessin ---

    /**
     * Dessiner une ligne colorée avec une marge sur les côtés
     * @param foreground Couleur du texte
     * @param background Background du bloc
     * @param oldbg Background extérieur
     * @param marge Largeur de la marge
     */
    static void dessiner_ligne_partielle(char* foreground, char* background, char* oldbg, int marge);

    /**
     * Dessine une ligne colorée qui prend toute la largeur
     * @param foreground Couleur du texte
     * @param background Couleur du fond
     * @param retour_ligne Effectuer un retour à la ligne ?
     */
    static void dessiner_ligne_remplie(char* foreground, char* background, bool retour_ligne);

    /**
     * Dessiner une ligne de colorée avec un texte centré dans celle-ci
     * @param foreground Couleur du texte
     * @param background Couleur du fond
     * @param str Texte à écrire
     */
    static void dessiner_ligne_texte_centrer(char* foreground, char* background, string str);

    /**
     * Remet à zéro les couleurs
     */
    static void raz_couleur();


    // --- Positionnement ---

    /**
     * Positionne le curseur
     * @param x Colonne
     * @param y Ligne
     */
    static void positionner(int x, int y);

    /**
     * Enregistre la position actuelle du curseur
     */
    static void enregistrerPosition();

    /**
     * Restaure la position du curseur préalablement enregistré
     */
    static void restaurerPosition();

};

#endif	/* DESSINERUTIL_H */

