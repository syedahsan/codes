#ifndef _AUTO_PTR_H_
#define _AUTO_PTR_H_

#include <iostream>

template <class T>
class auto_ptr
{
        private:
                T *ptr_;

        public:
                explicit auto_ptr(T *ptr);
                ~auto_ptr();
                T& operator*();
                T* operator->();
                auto_ptr<T>& operator=(auto_ptr<T>& rhs);
};

#endif /* _AUTO_PTR_H_ */
