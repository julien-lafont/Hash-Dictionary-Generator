/* 
 * Classe :   SortieFichier
 * Objectif :
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "SortieFichier.h"
#include "Log.h"

SortieFichier::SortieFichier()
{
    
}

SortieFichier::~SortieFichier() {
    fermer();
}

void SortieFichier::ecrire(string cle, string valeur)
{
    
    if(_fichier != NULL)
    {
        *_fichier << cle << "\t" << valeur << endl;
    } 
    else
    {
        Log::warning("Impossible d'écrire dans le fichier");
    }
}

void SortieFichier::definirDico(DICOS dico)
{
    ouvrirfichier(dico);
    _dico_ouvert = dico;
}

void SortieFichier::viderDico(DICOS dico) {
    fermer();
    remove(getNomFichier(dico).c_str());
    ouvrirfichier(dico);
}

string SortieFichier::recupererDerniereCle() {

    // Si le fichier n'existe pas, on retourne directement 'a'
    if (!existe(getNomFichier(_dico_ouvert))) return "";

    // Commande permettant de retourner la dernière clé enregistrée
    char* format = "tail %s -n 1 | tr \"\\t\" \"|\" | cut -d \"|\" -f1";

    // Si le fichier existe, on lit la dernière ligne
    char commande[strlen(format)+10];
    sprintf(commande, format, getNomFichier(_dico_ouvert).c_str());

    // Exécution de la commande par le shell et lecture du résultat
    FILE *pp;
    char res[50] ="";
    if ((pp = popen(commande, "r")) == NULL)
    {
        Log::error("Erreur d'exécution de la commande : %s", commande);
        exit(EXIT_FAILURE);
    }

    // Lit la réponse
    fgets(res, 50, pp);

    // Si le résultat est vide
    if (res[0]=='\000') return "";

    // Transforme en string et supprime le retour à la ligne final
    string str(res);
    if (str.find_first_of('\n')!=-1) { Log::error("correction"); str = str.substr(0, str.length()-1); }

    // Fermeture des flux et libération de la mémoire
    pclose(pp); pp = NULL;

    return str;
}

void SortieFichier::ouvrirfichier(DICOS dico) {

    _fichier = new ofstream();
    _fichier->open(getNomFichier(dico).c_str(), ios::out | ios::app);

    if(_fichier == NULL || !_fichier->is_open())
    {
        Log::error("Impossible d'ouvrir le fichier 0.txt en écriture");
        exit(EXIT_FAILURE);
    }
}

void SortieFichier::fermer() {
     if (_fichier != NULL) {
         _fichier->close();
         delete _fichier;
     }
}

string SortieFichier::getNomFichier(DICOS dico) {
    stringstream ss;
    ss << DOSSIER_SORTIE;
    ss << dico;
    ss << ".";
    ss << EXTENSION_SORTIE;
    return ss.str();
}

bool SortieFichier::existe(const string f) {
    ifstream fichier(f.c_str());
    return !fichier.fail();
}
bool SortieFichier::estValide() {
    definirDico(DICO_MD5);
    return !_fichier->fail();
}