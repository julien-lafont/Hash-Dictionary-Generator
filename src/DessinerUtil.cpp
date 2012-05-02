#include "DessinerUtil.h"

void DessinerUtil::dessiner_ligne_remplie(char* foreground, char* background, bool retourLigne) {
    cout  << foreground << background;
    for (int i=0; i<80; i++) cout << " ";
    cout << COLOR_OFF << flush;
    if (retourLigne) cout << endl;
}

void DessinerUtil::dessiner_ligne_partielle(char* foreground, char* background, char* oldBg, int marge) {

    cout  << oldBg;
    for (int i=0; i<marge; i++) cout << " ";

    cout  << foreground << background;
    for (int i=marge; i<80-(marge); i++) cout << " ";
    cout << COLOR_OFF << flush;
}

void DessinerUtil::dessiner_ligne_texte_centrer(char* foreground, char* background, string texte) {
    cout << foreground << background;

    int taille = texte.size();
    int espace = (80-taille)/2;

    for (int i=0; i<=espace; i++) cout << " ";
    cout << texte;
    if (taille + espace*2 == 80) espace--;
    for (int i=0; i<espace; i++) cout << " ";

    cout << COLOR_OFF << flush;
}

void DessinerUtil::positionner(int x, int y) {
    cout << "\033[" << y << ";" << x << "f";
}

void DessinerUtil::enregistrerPosition() {
    cout << "\033[s";
}

void DessinerUtil::restaurerPosition() {
    cout << "\033[u";
}

void DessinerUtil::raz_couleur() {
    cout << COLOR_OFF;
}
