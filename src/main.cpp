#include "Ui.h"
#include "Signaux.h"
#include "ObserverObservable.h"

#include "TestBruteForce.h"
#include "TestHasheurMd5.h"
#include "TestHasheurCmd.h"
#include "TestDriverRedis.h"

using namespace std;


/**
 * Lancer le programme principal
 */
int mainProgramme() {

    /* Lancer le gestionnaire de signaux */
    Signaux::init();
    
    /* Choix du mode de LOG */
    Log::definirNiveauMinimum(Log::WARN);   // Niveau minimum des erreurs enregistrées
    Log::activerModeFichier("");            // Sortie du log (fichier ou console)

    /* Création d'une UI qui observera un moteur */
    Ui ui; Moteur::Get()->AddObs(&ui);

    /* Lancement du programme */
    ui.afficher();
    ui.lancer();

    // Exemples de logs
    Log::trace("Log niveau 1 : trace");
    Log::info("Log de niveau 2 : info");
    Log::warning("Log de niveau 3 : warning");
    Log::error("Log de niveau 4 : error");

    return EXIT_SUCCESS;
}

/**
 * Lancer les tests
 */
int mainTest(){

    Log::definirNiveauMinimum(Log::TRACE);   // Niveau minimum des erreurs enregistrées
    Log::activerModeFichier("");            // Sortie du log (fichier ou console)

    Test::Suite ts;

    // Configuration des tests
    ts.add(auto_ptr<Test::Suite>(new TestBruteForce));
    ts.add(auto_ptr<Test::Suite>(new TestHasheurMd5));
    ts.add(auto_ptr<Test::Suite>(new TestHasheurCmd));
    ts.add(auto_ptr<Test::Suite>(new TestDriverRedis));

    Test::TextOutput output(Test::TextOutput::Verbose);
    return ts.run(output, false);

}



/**
 * Dispatcher entre programme principal et tests
 */
int main(int argc, char** argv){
    if (argc>1 && argv!=NULL && argv[1]!=NULL && strncmp(argv[1], "test", 4)==0) {
        return mainTest();
    } else {
        return mainProgramme();
    }
}