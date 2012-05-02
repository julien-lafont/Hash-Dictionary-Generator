/* 
 * Classe :   ObserverObservable
 * Objectif :
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


#include "ObserverObservable.h"
#include "Log.h"

using namespace std;


/*
void Observateur::AddObs( Observable* obs)
{
    m_list.push_back(obs);
}

void Observateur::DelObs(Observable* obs)
{
   iterator it= std::find(m_list.begin(),m_list.end(),obs);
    if(it != m_list.end())
       m_list.erase(it);
}*/

void Observable::AddObs( Observateur* obs)
{
    m_list.push_back(obs);
    //obs->AddObs(this);
}

void Observable::DelObs(Observateur* obs)
{
   iterator it= find(m_list.begin(),m_list.end(),obs);
    if(it != m_list.end())
       m_list.erase(it);
}


Observable::~Observable()
{
    
}

void Observable::Notify(ORDRES ordre, string valeur)
{
    iterator itb=m_list.begin();
    const_iterator ite=m_list.end();

    for(;itb!=ite;++itb)
    {
        (*itb)->Update(this, ordre, valeur);
    }
}
