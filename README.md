# GDE : Générateur de dictionnaires d'empreintes

> Projet C++/linux : Générateur de dictionnaire d'empreintes (md5,sha1,sha2,ck...) en utilisant le principe du calcul réparti (multi-threading) à partir d'un algorithme de brute-force.

Possibilité de lancer le logiciel en mode benchmark, ou de persister les résultats dans un fichier ou dans une base de donnée Nosql Redis (utile pour déchiffrer en masse les empreintes d'une base de donnée)

Télécharger le [rapport complet](http://hash-dictionary-generator.googlecode.com/files/Etude%20projet%20Unix.pdf).

* Guide d'installation
* Guide d'utilisation
* Implémentation technique (C++, multi-thread, IPC)
* Implémentation Redis (Base de données NoSQL)
* Benchmarks

![Calcul](http://up.studio-dev.fr/_/calcul.png)

![Etape 2 : choix du dictionnaire](http://up.studio-dev.fr/_/etape2.png)

![Calcul en cours](http://up.studio-dev.fr/_/etape4init.png)

_Le programme a été développé sur un environnement de type Debian (Ubuntu 10.10)._
_Le programme ainsi que les librairies externes utilisées, n’ont été compilés et testés que sur cet environnement._

Auteurs : Julien Lafont, Christophe N, Alexandre B et Djénéba D (EPSI 2011)
