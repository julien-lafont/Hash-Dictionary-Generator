/* 
 * Classe :   Log
 * Objectif : Classe de Log
 */

#include <fstream>

#include "Log.h"

// Initialisation membres statiques
Log::Output Log::_output_type = Log::CONSOLE;
ofstream* Log::_output_file = NULL;
pthread_mutex_t Log::_mutex;
Log::Level Log::_niveau_minimum = Log::WARN;

// Debugs depuis Stream
void  Log::trace(const char *format, ...) { 
    if(_niveau_minimum<=TRACE) {
        va_list ap;
        va_start(ap,format);
        char buffer[LOG_BUFFER_SIZE];
        vsprintf(buffer, format, ap);
        log(TRACE, buffer);
    }
}

void  Log::info(const char *format, ...) {
    if(_niveau_minimum<=INFO) {
        va_list ap;
        va_start(ap,format);
        char buffer[LOG_BUFFER_SIZE];
        vsprintf(buffer, format, ap);
        log(INFO, buffer);
    }
}

void  Log::warning(const char *format, ...) {
    if(_niveau_minimum<=WARN) {
        va_list ap;
        va_start(ap,format);
        char buffer[LOG_BUFFER_SIZE];
        vsprintf(buffer, format, ap);
        log(WARN, buffer);
    }
}

void  Log::error(const char *format, ...) {
    if(_niveau_minimum<=ERROR) {
        va_list ap;
        va_start(ap,format);
        char buffer[LOG_BUFFER_SIZE];
        vsprintf(buffer, format, ap);
        log(ERROR, buffer);
    }
}

void  Log::log(Level level, string msg) {

    // Initialisation du mutex au premier appel
    if (&Log::_mutex==NULL) pthread_mutex_init(&Log::_mutex, NULL);

    // L'inscription du log se fait dans une zone Mutex
    pthread_mutex_lock(&Log::_mutex);
    switch(_output_type) {
        
 // Le début console ne peut se faire qu'en mode débug (pas en mode release)
 #ifdef DEBUG
        case CONSOLE:
            DessinerUtil::positionner(2,19);
            DessinerUtil::dessiner_ligne_remplie(COLOR_WHITE, COLOR_HIGH_BLACK, true);
            DessinerUtil::positionner(2,19);
            cout << format(level, msg) << endl;
        break;
#endif
        
        case FICHIER: 
            if (_output_file) *_output_file << format(level, msg) << endl;
        break;
    }
    pthread_mutex_unlock(&Log::_mutex);
    
}

void  Log::activerModeConsole() {
    _output_type = CONSOLE;
}

void  Log::activerModeFichier(string fichier) {
    _output_type = FICHIER;
    if (fichier.empty()) fichier = genererNomFichier();
    _output_file = new ofstream(fichier.c_str(), ios::out|ios::app);
}

void Log::definirNiveauMinimum(Level level) {
    _niveau_minimum = level;
}

void Log::fermerFichier() {
    if (_output_file != NULL) {
        _output_file->close();
        delete _output_file;
    }
}

string  Log::format(Level level, string msg) {
    string s;
    s += "\e[40m";
    s += niveautoString(level);
    s += msg;
    s += " (";
    s += recupTemps();
    s += ")\e[0m";
    return s;
}

string  Log::recupTemps() {
  time_t rawtime;
  struct tm * timeinfo;
  char bufferDate [20];

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  strftime (bufferDate,20,"%X",timeinfo);

  return bufferDate;
}

string  Log::niveautoString(Level level)
{
    switch(level) {
      case TRACE: return "\e[1;37m[Trace]\e[0;37m\e[40m "; break;
      case INFO:  return "\e[1;36m[Info ]\e[0;36m\e[40m "; break;
      case WARN:  return "\e[1;33m[Warn ]\e[0;33m\e[40m "; break;
      case ERROR: return "\e[1;31m[Error]\e[0;31m\e[40m "; break;
  }
}

string Log::genererNomFichier() {
    struct tm Today;
    time_t maintenant;

    time(&maintenant);
    Today = *localtime(&maintenant);

    char nomFichier[20];
    sprintf(nomFichier, "gde%4.4d%2.2d%2.2d.log",Today.tm_year + 1900, Today.tm_mon + 1, Today.tm_mday);

    return string(nomFichier);
}


Log::~Log() {
    fermerFichier();
}




