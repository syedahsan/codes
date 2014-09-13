#include "AutoPointer.h"

template <class T>
auto_ptr<T>::auto_ptr(T *ptr = NULL) :
        ptr_(ptr)
{
}

template <class T>
auto_ptr<T>::~auto_ptr()
{
        delete ptr_;
}

template <class T>
T& auto_ptr<T>::operator*()
{
        return *ptr_;
}

template <class T>
T* auto_ptr<T>::operator->()
{
        return ptr_;
}

/* Ownership Transfer Copying */
template <class T>
auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr<T>& rhs)
{
        if (this != rhs) {
                delete ptr_;
                ptr_ = rhs.ptr_;
                rhs.ptr_ = NULL;
        }
        return *this;
}
