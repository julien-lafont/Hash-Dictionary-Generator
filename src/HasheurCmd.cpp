/* 
 * Classe :   HasheurCmd
 * Objectif :
 */

#include <stdlib.h>

#include "HasheurCmd.h"
#include "Log.h"

// Initialisation variables statiques
char* HasheurCmd::_format = "echo %s | %s  | cut -d ' ' -f1 ";

void HasheurCmd::initialiser(DICOS type) {
    chargerAlgorithme(type);
}

HasheurCmd::~HasheurCmd() {
    fermer();
}

void HasheurCmd::chargerAlgorithme(DICOS type) {
     _commande = typeToCommande(type);
    _taille_buffer = TAILLES_ALGOS[type];
}

void HasheurCmd::fermer() {

}


string HasheurCmd::hasher(const char* cle) {

    if (_format == NULL || _commande == NULL) {
        Log::error("Hasheur non initialise");
        exit(EXIT_FAILURE);
    }

    // On prépare la commande à exécuter
    char commande[strlen(_format)+strlen(cle)+strlen(_commande)-4];
    sprintf(commande, _format, cle, _commande );

    string str; bool incorrect;
    do {
        incorrect = false;

        // Exécution de la commande par le shell et lecture du résultat
        FILE *pp;
        char empreinte[300];
        if ((pp = popen(commande, "r")) == NULL)
        {
            Log::error("Erreur d'exécution de la commande : %s", commande);
            exit(EXIT_FAILURE);
        }

        // Lit la réponse
        fgets(empreinte, 300, pp);

        // Transforme en string et supprime le retour à la ligne final
        str = empreinte;
        str = str.substr(0, str.length()-1);

        // Tests pour certifier la cohérence de la bdd
        // (Un bug peut subvenir lorsqu'un signal est reçu en même temps qu'une
        //  commande est envoyée au shell. Le la chaine retournée est invalide,
        //  on relance l'opération )
        if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyz0123456789")!=-1) {
            Log::error("HahsheurCmd::Chaine détectée comme invalide (%s)", cle);
            incorrect = true;
        }

        // Fermeture des flux et libération de la mémoire
        pclose(pp); pp = NULL;
        
    } while (incorrect==true);

    return str;

}

char* HasheurCmd::typeToCommande(DICOS _type) {
    switch(_type) {
        case DICO_SUM:       return "sum";       break;
        case DICO_CK:        return "cksum";     break;
        case DICO_MD5:       return "md5sum";    break;
        case DICO_SHA1:      return "sha1sum";   break;
        case DICO_SHA224:    return "sha224sum"; break;
        case DICO_SHA256:    return "sha256sum"; break;
        case DICO_SHA384:    return "sha384sum"; break;
        case DICO_SHA512:    return "sha512sum"; break;
        case DICO_MD5MAISON: return "md5maison"; break;
        default:             return "md5sum";    break;
    }
}
