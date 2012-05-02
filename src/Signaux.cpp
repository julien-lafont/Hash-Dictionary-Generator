 #include "Signaux.h"


/**
 * Gestionnaire d'évènement des signaux
 * @param signum
 */
static void handler(int signum) {
    Moteur::Get()->terminerCalculateurs();
}

void Signaux::init() {

    // Interception du signal "CTRL+C"
    if (signal(SIGINT, handler)==SIG_ERR) {
        Log::error("Impossible d'intercepter le signal SIGINT");
    }
}

