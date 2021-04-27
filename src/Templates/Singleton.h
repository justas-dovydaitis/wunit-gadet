#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <FreeRTOS.h>

template <typename T>
class Singleton
{
private:
    Singleton(Singleton const &){};
    Singleton &operator=(Singleton const &){};

protected:
    static T *_pInstance;

    Singleton() { _pInstance = static_cast<T *>(this); };
    ~Singleton(){};

public:
    static T *getInstance();
};

template <typename T>
T *Singleton<T>::_pInstance = nullptr;

template <typename T>
T *Singleton<T>::getInstance()
{
    if (!_pInstance)
    {
        Singleton<T>::_pInstance = new T();
    }
    return _pInstance;
}

#endif