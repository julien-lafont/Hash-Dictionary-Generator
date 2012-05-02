#ifndef REDIS_H
#define	REDIS_H

#include <string>
#include <sstream>
#include <iostream>
#include <cstring>

#include "hiredis/hiredis.h"
#include "Log.h"

#define REDIS_BUFFER_SIZE 1000
#define REDIS_DEFAULT_PORT 6379

using namespace std;

/**
 * Driver C++ permettant d'accéder à une base de donnée REDIS
 * @param host Hote
 * @param port Port
 * @author Julien Lafont
 */
class Redis {
public:

    /**
     * Initialisation du driver et connexion (port par défaut)
     * @param host Hote de la base de donnée
     */
    Redis(const char* host);

    /**
     * Initialisation du driver et connexion
     * @param host Hote de la base de donnée
     * @param port Port de la base de donnée
     */
    Redis(const char* host, int port);

    /**
     * Initialisation du driver et connexion, en activant ou nom le log des requêtes
     * @param host Hote de la base de donnée
     * @param port Port de la base de donnée
     * @param trace_requete Activer le log des requêtes ?
     */
    Redis(const char* host, int port, bool trace_requete);
    

    //
    // Gestion de la connexion
    //

    /**
     * Connexion à la base de donnée Redis
     * @param host Hote de la base de donnée
     * @param port Port de la base de donnée
     */
    void connexion(const char* host, int port);

    /**
     * Déconnexion de la base de donnée
     */
    void deconnexion();

    /**
     * La connexion est-elle active ?
     * @return Vrai si la connexion est active
     */
    bool estConnecte();

    /**
     * Le serveur répond-t-il aux requêtes ?
     * @return Vrai si la connexion est active et si le serveur répond
     */
    bool ping();



    //
    // Travail sur des clé atomiques
    //

    /**
     * Ajoute une clé/valeur dans la base de donnée
     * @param cle
     * @param valeur
     * @return Résultat de l'opération
     */
    bool add(const char* cle, const char* valeur);

    /**
     * Retourne la valeur liée à une clé dans la BDD
     * @param cle
     * @return valeur de la clé, vide si la clé n'existe pas (déconseillé)
     */
    string get(const char* cle);

    /**
     * Vérifie si une clé est présente dans la base de donnée
     * @param cle
     * @return Vrai si la clé existe
     */
    bool exist(const char* cle);



    //
    // Travail sur des sets
    //

    /**
     * Ajoute une valeur dans un SET de données
     * @param cle
     * @param valeur
     * @return Résultat de l'opération
     */
    bool setAdd(const char* cle, const char* valeur);

    /**
     * Retourne le nombre d'élements présents dans un SET de données
     * @param cle
     * @return  Nombre d'éléments
     */
    int setNb(const char* cle);

    /**
     * Indique si une clé existe en tant que SET de données
     * @param cle
     * @param valeur
     * @return Vrai si le set existe pour la clé donnée
     */
    bool setExist(const char* cle, const char* valeur);

    /**
     * Retourne un des éléments du SET de données
     * @param cle
     * @return un des éléments choisi aléatoirement parmis les valeurs du SET
     */
    string setPop(const char* cle);



    //
    // Travail sur la base de donnée
    //

    /**
     * Force la sauvegarde des données de la BDD
     */
    void forcesave();

    /**
     * Supprime toutes les données de toutes les tables de la BDD
     */
    void flushAll();

    /**
     * Supprime les données d'une table spécifique
     * @param dbId ID de la base à vider
     */
    void flushDb(int dbId);

    /**
     * Choisit une Table dans la Base de donnée
     * @param dbId ID de la base à sélectionner
     */
    void setDb(int dbId);

    virtual ~Redis();

private:

    /**
     * Connexion active
     */
    redisContext *_connexion;
    bool _est_connecte;
    bool _trace_requete;


    //
    // Exécuter des commandes
    //

    /**
     * Execute une requête sur la BDD et retourne l'objet Reply
     * @param str Requête
     * @return objet Reply
     */
    redisReply *executerReply(const char *str);

    /**
     * Execute une requête sur la BDD sans rien retourner
     * @param format Chaine de formatage
     * @param ... Paramètres
     */
    void executer(const char *format, ...);

    /**
     * Exécute une requête sur la BDD et retourne une chaine de caractère
     * @param format Chaine de formatage
     * @param ... Paramètres
     * @return Résultat textuel
     */
    string executerStr(const char *format, ...);

    /**
     * Exécute une requête sur la BDD et retourne un entier
     * @param format Chaine de formatage
     * @param ... Paramètres
     * @return Résultat entier
     */
    int executerInt(const char *format, ...);

    /**
     * Exécute une requête sur la BDD et retourne un booléen
     * @param format Chaine de formatage
     * @param ... Paramètres
     * @return Résultat bool
     */
    bool executerBool(const char *format, ...);

};

#endif	/* REDIS_H */

