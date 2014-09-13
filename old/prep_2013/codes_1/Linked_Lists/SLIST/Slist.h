#ifndef __SLIST_H__
#define __SLIST_H__

#include <iostream>

#ifdef USE_EXPORT_KEYWORD
export
#endif

template <class T>
class SList;

template <class T>
class Node
{
        private:
                T data;
                Node<T> *next;
                Node(T _data);

        public:
                friend class SList<T>;
};

template <class T>
class SList
{
        private:
                Node<T> *head;
                Node<T>* search(T data);

        public:
                SList();
                void insert(T data);
                void remove(T data);
                bool isPresent(T data);
                void print();
};

#ifndef USE_EXPORT_KEYWORD
        #include "Slist.cpp"
#endif

#endif /* __SLIST_H__ */
