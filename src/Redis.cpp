#include "Redis.h"


Redis::Redis(const char* host, int port, bool trace_requete) {
    connexion(host, port);
    _trace_requete = trace_requete;
}

Redis::Redis(const char* host, int port) {
    connexion(host, port);
    _trace_requete = false;
}
Redis::Redis(const char* host) {
    connexion(host, REDIS_DEFAULT_PORT);
    _trace_requete = false;
}

Redis::~Redis() {
    if (estConnecte()) {
        deconnexion();
    }
    
}

//
// Gestion de la connexion
//

void Redis::connexion(const char* host, int port) {
    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    _connexion = redisConnectWithTimeout(host, port, timeout);
    
    if (_connexion->err) {
        Log::error("Impossible de se connecter à la base redis distance");
        Log::error(_connexion->errstr);
        _est_connecte = false;
    }
    else {
        _est_connecte = true;
    }
}

bool Redis::ping() {
    if (!estConnecte()) return false;

    timeval start;
    gettimeofday(&start, 0);

    bool res = false;
    string rep = executerStr("PING");
    if (rep.compare("PONG")==0) {
        
        if (_trace_requete) {
            timeval end;
            gettimeofday(&end, 0);

            Log::trace("Ping reussi en %d ms", ( end.tv_usec - start.tv_usec)/1000);
        }
        
        res = true;
        
    } else {
        Log::error("Ping impossible sur le serveur");
    }

    return res;
}

bool Redis::estConnecte() {
    return _est_connecte && _connexion!=NULL;
}

void Redis::deconnexion() {
    executer("QUIT");
    _est_connecte = false;

    // Libération mémoire
    redisFree(_connexion); _connexion = NULL;
    
}


//
// Commandes sur la base de donnée
//

void Redis::forcesave() {
    executer("SAVE");
}
void Redis::flushAll(){
    executer("FLUSHALL");
}
void Redis::flushDb(int dbId){
    setDb(dbId);
    executer("FLUSHDB", dbId);
}
void Redis::setDb(int dbId){
    executer("SELECT %d", dbId);
}


//
// Travail sur des clé atomiques
//
bool Redis::add(const char* cle, const char* valeur) {
    return executerBool("SET %s %s", cle, valeur);
}
string Redis::get(const char* cle) {
    return executerStr("GET %s", cle);
}
bool Redis::exist(const char* cle) {
    return executerBool("EXISTS %s", cle);
}


//
// Travail sur des sets
//
bool Redis::setAdd(const char* cle, const char* valeur) {
    return executerBool("SADD %s %s", cle, valeur);
}
int Redis::setNb(const char* cle) {
    return executerInt("SCARD %s", cle);
}
bool Redis::setExist(const char* cle, const char* valeur) {
    return executerBool("SISMEMBER %s %s", cle, valeur);
}
string Redis::setPop(const char* cle) {
    return executerStr("SPOP %s", cle);
}


// --------------- Exécution des commandes ----------------------------- //

string Redis::executerStr(const char *format, ...) {
    va_list ap;
    va_start(ap,format);
    char buffer[REDIS_BUFFER_SIZE];
    vsprintf(buffer, format, ap);

    redisReply *reply = executerReply(buffer);
    string r = "";

    if (reply == NULL || reply->type == REDIS_REPLY_ERROR) {
        Log::error("Echec commande REDIS : %s", reply->str);
    } else if (reply->type == REDIS_REPLY_STRING || reply->type == REDIS_REPLY_STATUS ) {
        r = reply->str;
    } 

    if (reply != NULL) freeReplyObject(reply);
    return r;

}

int Redis::executerInt(const char *format, ...) {
    va_list ap;
    va_start(ap,format);
    char buffer[REDIS_BUFFER_SIZE];
    vsprintf(buffer, format, ap);

    redisReply *reply = executerReply(buffer);

    int r = -1;
    if (reply == NULL || reply->type == REDIS_REPLY_ERROR) {
        Log::error("Echec commande REDIS : %s", reply->str);
    } else if (reply->type == REDIS_REPLY_INTEGER) {
        r = reply->integer;
    } else if (reply->type == REDIS_REPLY_NIL) {
        r = 0;
    }

    if (reply != NULL) freeReplyObject(reply);
    return r;
}

bool Redis::executerBool(const char *format, ...) {
    va_list ap;
    va_start(ap,format);
    char buffer[REDIS_BUFFER_SIZE];
    vsprintf(buffer, format, ap);

    redisReply *reply = executerReply(buffer);

    bool r = false;
    if (reply == NULL || reply->type == REDIS_REPLY_ERROR) {
        Log::error("Echec commande REDIS : %s", reply->str);
    } else if (reply->type == REDIS_REPLY_INTEGER) {
        r = reply->integer>0;
    } else if (reply->type == REDIS_REPLY_STRING || reply->type == REDIS_REPLY_STATUS ) {
        r = strcmp(reply->str, "OK")==0;
    }

    if (reply != NULL) freeReplyObject(reply);
    return r;
}

void Redis::executer(const char *format, ...) {
    if (estConnecte()) {
        va_list ap;
        va_start(ap,format);
        char buffer[REDIS_BUFFER_SIZE];
        vsprintf(buffer, format, ap);

        if (_trace_requete) Log::trace(buffer);
        redisCommand(_connexion, buffer);
    }
}

redisReply *Redis::executerReply(const char *str) {
    if (estConnecte()) {
        if (_trace_requete) Log::trace(str);
        return (redisReply *)redisCommand(_connexion, str);
    }
    return NULL;
}

