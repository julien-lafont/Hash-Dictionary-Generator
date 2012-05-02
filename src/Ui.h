#ifndef UI_H
#define	UI_H

#include <string>
#include <termios.h>
#include <locale>

#include "enums.h"
#include "Moteur.h"
#include "colors.h"
#include "Log.h"
#include "ObserverObservable.h"
#include "DessinerUtil.h"


class Observable;

#define UI_LEGENDE_COL 60
#define UI_LEGENDE_LIG 6
#define UI_PAUSE_COEFF 100000

using namespace std;

class Observable;

/**
 * Interface de commande du logiciel
 */
class Ui : public Observateur {
public:
    Ui();

    /**
     * Initialiser le moteur avec la configuration donnée
     */
    void lancer();

    /**
     * Afficher l'interface
     */
    void afficher();

    /**
     * Réception d'un évènement d'un des éléments observés
     */
    void Update(const Observable* observable, ORDRES ordre, string valeur);

private:

    // Configuration
    DICOS _dico;
    int _nbThreads;
    bool _reinit;
    SORTIES _sortie;

    // Afficher les zones
    void afficher_background();
    void afficher_interface_calculs();

    // Afficher les légendes
    void cacher_legende();
    void afficher_legende_dicos();
    void afficher_legende_sorties();
    void afficher_legende_ouinon();

    // Gestion des erreurs
    void afficher_erreur(string erreur, bool kill);

};

#endif	/* UI_H */

