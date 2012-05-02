#ifndef SORTIEFICHIER_H
#define	SORTIEFICHIER_H

#include <string>
#include <cstring>
#include <fstream>
#include <sysexits.h>

#include "Sortie.h"

#define DOSSIER_SORTIE ""
#define EXTENSION_SORTIE "hash"

using namespace std;

/**
 * Enregistrement des empreintes générées dans un fichier
 * 
 */
class SortieFichier : public Sortie  {
public:
    SortieFichier();
    virtual ~SortieFichier();

    /**
     * Ecriture de la clé et de l'empreinte dans un fichier texte
     * @param cle
     * @param valeur
     */
    void ecrire(string cle, string valeur);

    /**
     * Choix du dictionnaire etn fonction de son ID
     * @param dico
     */
    void definirDico(DICOS dico);
    
    /**
     * Vider un fichier
     * @param dico
     */
    void viderDico(DICOS dico);

    /**
     * Récupère la dernière clé enregistrée dans la sortie
     */
    string recupererDerniereCle();
    
    /**
     * La sortie est-elle valide ?
     */
    bool estValide();

private:

    /**
     * Flux du fichier ouvert
     */
    ofstream* _fichier;

    /*
     * Dictionnaire persistant actuellement chargé
     */
    DICOS _dico_ouvert;

    /**
     * Ouvrir un fichier
     * @param dico ID du dictionnaire
     */
    void ouvrirfichier(DICOS dico);

    /**
     * Fermer un fichier
     */
    void fermer();

    /**
     * Générer le nom du fichier dans lequel seront enregistrés les
     * empreintes en fonction de l'ID du dictionnaire
     * @param dico
     * @return
     */
    string getNomFichier(DICOS dico);

    /**
     * Vérifie si un fichier existe
     * @param fichier
     * @return VRAI si le fichier existe et est lisible
     */
    bool existe(const string fichier);

 

};

#endif	/* SORTIEFICHIER_H */

