#ifndef LOG_H
#define	LOG_H

#include <string>
#include <ctime>
#include <iostream>
#include <cstdarg>
#include <cstdio>
#include <fstream>
#include "DessinerUtil.h"


#define LOG_BUFFER_SIZE 1000

#define LOG_LEVEL_TRACE 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_WARN 3
#define LOG_LEVEL_ERROR 4


using namespace std;

/**
 * Classe utilitaire permettant de gérer les informations de Log
 * Les logs sont activés par défaut en compilation "Debug", et complètement
 * désactivés en compilation "Release"
 *
 * Plusieurs sorties sont disponibles : Console ou Fichier
 */
class Log {
public:

    /**
     * Sorties possible du loggueur
     */
    enum Output {
        CONSOLE,
        FICHIER
    };

    /**
     * Niveaux de log
     */
    enum Level {
        TRACE,
        INFO,
        WARN,
        ERROR
    };


    //
    // Loggueurs de différent niveaux
    //

    /**
     * Logguer une information de type TRACE
     * @param format : Chaine de formatage
     * @param ... : Paramètres
     */
    void static trace(const char *format, ...);

    /**
     * Logguer une information de type INFO
     * @param format : Chaine de formatage
     * @param ... : Paramètres
     */
    void static info(const char *format, ...);

    /**
     * Logguer une information de type WARNING
     * @param format : Chaine de formatage
     * @param ... : Paramètres
     */
    void static warning(const char *format, ...);

    /**
     * Logguer une information de type ERROR
     * @param format : Chaine de formatage
     * @param ... : Paramètres
     */
    void static error(const char *format, ...);



    //
    // Configuration du logger
    //

    /**
     * Activer la sortie "Console" du loggueur
     */
    void static activerModeConsole();

    /**
     * Activer la sortie "Fichier" du loggueur
     * @param fichier Fichier de sortie. Si vide, un nom par défaut sera généré (YYYYMMDD.log)
     */
    void static activerModeFichier(string fichier);

    /**
     * Définir le niveau minimum des messages à logguer
     * @param level
     */
    void static definirNiveauMinimum(Level level);

    /**
     * Fermer le fichier si le loggueur Fichier est utilisé
     */
    void static fermerFichier();

    
    virtual ~Log();
    
private:

    /**
     * Type de loggueur utilisé
     */
    static Output _output_type;

    /**
     * Si loggueur de type fichier, enregistre le type
     */
    static ofstream* _output_file;

    /**
     * Mutex permettant de créer une zone exlusive pour l'écriture
     */
    static pthread_mutex_t _mutex;

    /**
     * Niveau minimum du message à logguer
     */
    static Level _niveau_minimum;

    /**
     * Loggueur générique
     * @param level Niveau du message
     * @param msg Message brute
     */
    void static inline log(Level level, string msg);

    //
    // Fonctions de mise en forme
    //

    /**
     * Formatte un message en rajoutant des infos auxiliaires
     * (heure, niveau de l'erreur)
     * @param level Niveau de l'erreur
     * @param msg Message
     * @return message formatté
     */
    string static inline format(Level level, string msg);

    /**
     * Récupère l'heure courante
     * @return heure courante
     */
    string static inline recupTemps();

    /**
     * Retourne le niveau d'une erreur au format String à partir de l'Enum
     * @param level
     * @return niveau de l'erreur textuel
     */
    string static inline niveautoString(Level level);

    /**
     * Génère un nom de fichier de log
     * @return nom du fichier
     */
    string static genererNomFichier();

};

#endif	/* LOG_H */

