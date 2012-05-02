#ifndef OBSERVEROBSERVABLE_H
#define	OBSERVEROBSERVABLE_H

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>

#include "enums.h"

using namespace std;

class Observable;

/**
 * Design pattern Observer-Observable
 */
class Observateur
{
public:

    /**
     * Classe appelée lorsqu'un ordre est notifié par la classe observée
     * @param observable    Source
     * @param ordre         Identification de l'ordre
     * @param valeur        Texte libre
     */
    virtual void Update(const Observable* observable, ORDRES ordre, string valeur)=0;
};

/**
 * Design pattern Observer-Observable
 */

class Observable
{
public:

    /**
     * Ajouter un observateur
     * @param obs
     */
    void AddObs(Observateur* obs);

    /**
     * Retirer un observateur
     * @param obs
     */
    void DelObs(Observateur* obs);
    virtual ~Observable();
    
protected:

    /**
     * Notifier les observateurs d'un évènement
     * @param ordre
     * @param valeur
     */
    void Notify(ORDRES ordre, string valeur);

private:
    std::list<Observateur*> m_list;
    typedef std::list<Observateur*>::iterator iterator;
    typedef std::list<Observateur*>::const_iterator const_iterator;
};


#endif	/* OBSERVEROBSERVABLE_H */

