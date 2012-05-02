/* 
 * Classe :   Ui
 * Objectif :
 */

#include "Ui.h"


Ui::Ui() {
    
}

void Ui::afficher() {

    afficher_background();

    DessinerUtil::positionner(3,6);
    cout << COLOR_GRAS_WHITE << BG_BLACK << "ʘ Configuration du générateur " ;

    // Configurer le nombre de threads
    cacher_legende();
    DessinerUtil::positionner(6,8);
    cout << COLOR_WHITE << BG_BLACK << "Nombre de threads ? ........................ "<< COLOR_YELLOW << BG_BLACK;
    cin >> _nbThreads;
    if (_nbThreads<1 || _nbThreads>16) afficher_erreur("Vous ne pouvez lancer qu'entre 1 et 16 threads !", true);

    // Configurer le dictionnaire
    afficher_legende_dicos();
    DessinerUtil::positionner(6,9);
    cout << COLOR_WHITE << BG_BLACK << "Dictionnaire ? ............................. " << COLOR_YELLOW << BG_BLACK;
    int dico; cin >> dico;
    if (dico<0 || dico>9) afficher_erreur("Le dictionnaire que vous avez choisi n'existe pas !", true);
    _dico = (DICOS)dico;

    // Configurer l'enregistrement
    cacher_legende();
    afficher_legende_sorties();
    DessinerUtil::positionner(6,10);
    cout << COLOR_WHITE << BG_BLACK << "Enregistrer les résultats ? ................ " << COLOR_YELLOW << BG_BLACK;
    int sortie; cin >> sortie;
    if (sortie<0 || sortie>2) afficher_erreur("La sortie que vous avez sélectionné est invalide !", true);
    _sortie = (SORTIES)sortie;

    // Configurer la reprise de la génération
    cacher_legende();
    afficher_legende_ouinon();
    DessinerUtil::positionner(6,11);
    cout << COLOR_WHITE << BG_BLACK << "Reprendre la génération ? .................. " << COLOR_YELLOW << BG_BLACK;
    int reprendre; cin >> reprendre; _reinit = (reprendre==0);

    cacher_legende();
    DessinerUtil::positionner(3, 14);
    cout << COLOR_GRAS_WHITE << BG_BLACK << "ʘ Initialisation du générateur " << flush; ;
    DessinerUtil::positionner(6, 16);
    cout << COLOR_WHITE <<  BG_BLACK << "Initialisation de la sortie ................ " << flush ;

}

void Ui::lancer() {
    Moteur* m = Moteur::Get();
    m->init(_dico, _nbThreads, _sortie, _reinit);
    m->lancerCalculateur();

    // Fin du programmes : dernières instructions
    DessinerUtil::raz_couleur();
    for (int i=0; i<25; i++) cout << endl << endl; // Clear la console
}



void Ui::Update(const Observable* source, ORDRES ordre, string value) {
    switch(ordre) {
        case ORDRE_SORTIE_OK:
            usleep(1*UI_PAUSE_COEFF); cout << COLOR_HIGH_GREEN << BG_BLACK << "OK"<< flush ;
            DessinerUtil::positionner(6, 17);
            cout << COLOR_WHITE <<  BG_BLACK << "Récupérer chaine à calculer ................ " << flush ;
        break;
        case ORDRE_SORTIE_ERREUR:
            DessinerUtil::positionner(51, 16);
            cout << COLOR_HIGH_RED << BG_BLACK << "Erreur !"<< flush ;
            sleep(1); afficher_erreur("Initialisation de la sortie impossible", true);
            exit(EXIT_FAILURE);
        break;
        case ORDRE_PREMIERE_CHAINE:
            usleep(8*UI_PAUSE_COEFF); cout << COLOR_HIGH_GREEN << BG_BLACK << "OK ("<<value<<")"<< flush ;
            DessinerUtil::positionner(6, 18);
            cout << COLOR_WHITE <<  BG_BLACK << "Lancement du moteur ........................ " << flush ;
        break;
        case ORDRE_MOTEUR_PRET:
            usleep(8*UI_PAUSE_COEFF); cout << COLOR_HIGH_GREEN << BG_BLACK << "OK"<< flush ;
            DessinerUtil::positionner(6, 19);
            cout << COLOR_WHITE <<  BG_BLACK << "Lancement des calculateurs ................. " << flush ;
        break;
        case ORDRE_CALCULATEUR_PRET:

            // Passer en mode : Calcul en cours
            afficher_background();
            afficher_interface_calculs();
        break;

    }
}



/*
 * Affichage des légendes
 */

void Ui::afficher_legende_dicos() {
    int ligne = UI_LEGENDE_LIG;
    cout <<  BG_WHITE << COLOR_GRAS_BLUE;
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "               ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "    Légende    ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "               ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  0: SUM       ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  1: CK        ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  2: MD5       ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  3: SHA1      ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  4: SHA224    ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  5: SHA256    ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  6: SHA384    ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  7: SHA512    ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  8: MD5Natif  ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "               ";
}

void Ui::afficher_legende_sorties() {
    int ligne = UI_LEGENDE_LIG;
    cout <<  BG_WHITE << COLOR_GRAS_BLUE;
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "               ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "    Légende    ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "               ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  0: AUCUN     ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  1: FICHIER   ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  2: NOSQL     ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "               ";
}

void Ui::afficher_legende_ouinon() {
    int ligne = UI_LEGENDE_LIG;
    cout <<  BG_WHITE << COLOR_GRAS_BLUE;
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "               ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "    Légende    ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "               ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  0: Non       ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "  1: Oui       ";
    DessinerUtil::positionner(UI_LEGENDE_COL, ligne++);  cout << "               ";
}

void Ui::cacher_legende() {
    int ligne=6;
    cout << BG_BLACK;
    for(int i=ligne; i<20; i++) {
        DessinerUtil::positionner(UI_LEGENDE_COL, i);  cout << "               ";
    }
}


/*
 * Afficher Erreur
 */
void Ui::afficher_erreur(string erreur, bool kill) {
    DessinerUtil::positionner(1,10);
    DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_HIGH_RED, true);
    DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_RED, true);
    DessinerUtil::dessiner_ligne_texte_centrer(COLOR_GRAS_WHITE, BG_RED, erreur);
    DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_RED, true);
    DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_HIGH_RED, true);
    if (kill) {
        DessinerUtil::raz_couleur(); DessinerUtil::positionner(80,25);
        exit(EXIT_FAILURE);
    }
}


/*
 * Background
 */

void Ui::afficher_background() {
    cout << endl<< COLOR_OFF;

    // Background
    DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_HIGH_BLACK, true);
    DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_HIGH_BLACK, true);
    DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_HIGH_BLACK, true);
    for (int i=0; i<18; i++) DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_BLACK, true);
    DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_HIGH_BLACK, true);
    DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_HIGH_BLACK, true);
    DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, BG_HIGH_BLACK, false);
    DessinerUtil::enregistrerPosition();

    // Entete
    DessinerUtil::positionner(1,2);
    DessinerUtil::dessiner_ligne_texte_centrer(COLOR_BLACK, BG_WHITE, "GDE : Generateur Dictionnaires d'Empreintes" );

    // Pied de page
    DessinerUtil::positionner(2,23);
    DessinerUtil::dessiner_ligne_texte_centrer(COLOR_BLACK, BG_WHITE, "Réalisé par Djeneba, Julien, Alexandre et Christophe" );
}


/* Séparateur de nombres */
template<typename CharT>
struct Sep : public std::numpunct<CharT>
{
    virtual std::string do_grouping()   const { return "\003"; }
    virtual CharT do_thousands_sep()    const { return ' '; }
};


void Ui::afficher_interface_calculs() {

    // Définition du format pour ajouter un ' ' entre les groupes de chiffres
    std::cout.imbue(std::locale(std::cout.getloc(), new Sep <char>()));

    // Fond
    for (int l=6; l<13; l++) {
        DessinerUtil::positionner(0,l);
        DessinerUtil::dessiner_ligne_partielle(COLOR_WHITE, BG_CYAN, BG_BLACK, 10);
    }

    // Textes
    DessinerUtil::positionner(25,7);  cout << COLOR_GRAS_WHITE << BG_CYAN << "DICTIONNAIRE EN COURS DE GENERATION" << flush;
    DessinerUtil::positionner(13,9);  cout << COLOR_WHITE << BG_CYAN << "Cycle : " << flush;
    DessinerUtil::positionner(13,10); cout << COLOR_WHITE << BG_CYAN << "Vitesse : " << flush;
    DessinerUtil::positionner(13,11); cout << COLOR_WHITE << BG_CYAN << "Clés calculées : " << flush;

    // Quitter
    for (int l=16; l<19; l++) {
        DessinerUtil::positionner(0,l);
        DessinerUtil::dessiner_ligne_partielle(COLOR_WHITE, BG_HIGH_BLUE, BG_BLACK, 15);
    }
    DessinerUtil::positionner(24,17);  cout << COLOR_WHITE << BG_HIGH_BLUE << "Appuyez sur <CTRL+C> pour terminer." << flush;


    // Toutes les secondes, on va récupérer les bencharmks établies par le moteur
    // et mettre à jour l'interface
    // On boucle tant que les calculateurs sont actifs
    structBenchRes res; res.ordre_fin = false;
    while(!res.ordre_fin) {

        sleep(1);
        Moteur::Get()->getBench(&res);

        DessinerUtil::positionner(40,9);
        cout << COLOR_GRAS_WHITE << BG_CYAN << res.chaine << flush;

        DessinerUtil::positionner(40,10);
        cout << COLOR_GRAS_WHITE << BG_CYAN << res.nb << " /s    " << flush;

        DessinerUtil::positionner(40,11);
        cout << COLOR_GRAS_WHITE << BG_CYAN << res.total << " clés  " << flush;

    }

    afficher_erreur("Attente fermeture des calculateurs", false);
    sleep(2); // Pour lire le message

}