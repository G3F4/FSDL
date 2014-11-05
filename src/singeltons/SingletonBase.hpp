#ifndef __SINGLETON_HPP_
#define __SINGLETON_HPP_
#include <stddef.h>  // defines NULL
#include <memory>
#include <mutex>


template <class T>
class Singleton
{
public:
    static T& Instance() {
        std::call_once(m_once_flag, [] {
            m_instance.reset(new T);
        });
        return *m_instance.get();
    }
//    static T* Instance() {
//        if(!m_pInstance) m_pInstance = new T;
//        assert(m_pInstance != NULL);
//        return m_pInstance;
//    }
protected:
    Singleton();
    ~Singleton();
private:
    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);
    static T* m_pInstance;
    static std::unique_ptr<T> m_instance;
    static std::once_flag m_once_flag;
};

template <class T> T* Singleton<T>::m_pInstance=NULL;

#endif