#ifndef __HASHED_DLL__
#define __HASHED_DLL__

#include <iostream>
#include <map>

using namespace std;

template <class T>
class Hashed_DLL;

template <class T>
class DLL_Node
{
        private:
                T data;
                int frequency;
                DLL_Node<T> *next;
                DLL_Node<T> *prev;
                DLL_Node(T _data);

        public:
                friend class Hashed_DLL<T>;
};

template <class T>
DLL_Node<T>::DLL_Node(T _data = 0) :
        data(_data), frequency(1), next(NULL), prev(NULL)
{
}

template <class T>
class Hashed_DLL
{
        private:
                map < T, DLL_Node<T>* > hash;
                DLL_Node<T> *head;
                DLL_Node<T> *tail;

        public:
                Hashed_DLL();
                void print();
                void push(T data);

};

template <class T>
Hashed_DLL<T>::Hashed_DLL() :
        head(NULL), tail(NULL)
{
}

template <class T>
void Hashed_DLL<T>::push(T data)
{
        typename map<T, DLL_Node<T>* >::iterator it;

        it = hash.find(data);

        if (it == hash.end()) {
                DLL_Node<T> *node = new DLL_Node<T>(data);
                hash.insert(pair<T, DLL_Node<T>*>(data, node));
                
                if (head == NULL && tail == NULL) { /* empty linked list */
                        head = tail = node;
                        return;
                }
                
                tail->next = node;
                node->prev = tail;
                tail = node;
        } else {
                it->second->frequency += 1;
        }
}

template <class T>
void Hashed_DLL<T>::print()
{
        DLL_Node<T> *it = head;
        while (it) {
                cout << "(" << it->data << ", " << it->frequency << ") <=> ";
                it = it->next;
        }
        cout << "(Null)" << endl;
}

#endif /* __HASHED_DLL__ */
