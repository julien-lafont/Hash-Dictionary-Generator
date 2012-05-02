#ifndef SINGLETONTPL_H
#define SINGLETONTPL_H

/**
 * Singleton double-check
 * @see http://come-david.developpez.com/tutoriels/dps/?page=Singleton
 * @return
 */
template <class T> class Singleton
{
    public:

        static T* Get();
        static void Kill();

    protected:
        static T* m_i;
        private:
        T& operator= (const T&){}
};

template <class T> T* Singleton<T>::m_i=0;

template <class T>  T* Singleton<T>::Get()
{
        if(m_i==0)
        {
            m_i=new T();
        }
        return m_i;
}

template <class T> void Singleton<T>::Kill()
{
        delete m_i;
        m_i=0;
}

#endif




