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
                DLL_Node<T> *next;
                DLL_Node<T> *prev;
                DLL_Node(T _data);

        public:
                friend class Hashed_DLL<T>;
};

template <class T>
DLL_Node<T>::DLL_Node(T _data = 0) :
        data(_data), next(NULL), prev(NULL)
{
}

typedef enum{
        PRINT_HASH,
        PRINT_DLL
} print_type;

/* 
 * Although map/multimap in C++ are implemented as
 * balanced trees and the time complexity is O(log N)
 * for most of the operations. We are going to assume
 * that we are using perfect hashing and the time
 * complexities for our operations is O(1)
 */
template <class T>
class Hashed_DLL
{
        private:
                multimap < T, DLL_Node<T>* > hash;
                DLL_Node<T> *head;
                DLL_Node<T> *tail;
                void print_hash();
                void print_dll();

        public:
                Hashed_DLL();
                void print(print_type type);

                /* O(1) methods */
                void push_back(T data);
                void push_front(T data);
                bool delete_one(T data);
                bool delete_all(T data);

};

template <class T>
Hashed_DLL<T>::Hashed_DLL() :
        head(NULL), tail(NULL)
{
}

template <class T>
void Hashed_DLL<T>::push_back(T data)
{
        DLL_Node<T> *node = new DLL_Node<T>(data);
        hash.insert(pair<T, DLL_Node<T>*>(data, node));

        if (head == NULL && tail == NULL) { /* they should be NULL at the same time */
                head = tail = node;
                return;
        }

        tail->next = node;
        node->prev = tail;
        tail = node;
}

template <class T>
void Hashed_DLL<T>::push_front(T data)
{
        DLL_Node<T> *node = new DLL_Node<T>(data);
        hash.insert(pair<T, DLL_Node<T>*>(data, node));

        if (head == NULL && tail == NULL) { /* they should be NULL at the same time */
                head = tail = node;
                return;
        }

        head->prev = node;
        node->next = head;
        head = node;
}

template <class T>
bool Hashed_DLL<T>::delete_one(T data)
{
        typename multimap<T, DLL_Node<T>*>::iterator it;
        
        it = hash.find(data);
        if (it != hash.end()) { /* data found */
                /* delete from DLL */
                if (it->second == NULL) {
                        /* this shouldn't have happened */
                } else if (it->second == head && head == tail) { /* the only node */
                        head = tail = NULL;
                        delete it->second;
                } else if (it->second == head) { /* head node */
                        head = head->next;
                        head->prev = NULL;
                        delete it->second;
                } else if (it->second == tail) { /* tail node */
                        tail = tail->prev;
                        tail->next = NULL;
                        delete it->second;
                } else { /* generic case */
                        DLL_Node<T> *temp = it->second;
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        delete temp;
                }

                /* remove from hashmap */
                hash.erase(it);

                return (true);
        }

        return (false);
}

template <class T>
bool Hashed_DLL<T>::delete_all(T data)
{
        bool ret = false;
        typename multimap<T, DLL_Node<T>*>::iterator it;
        
        it = hash.find(data);
        while (it != hash.end()) {
                ret = true;

                /* delete from DLL */
                if (it->second == NULL) {
                        /* this shouldn't have happened */
                } else if (it->second == head && head == tail) { /* the only node */
                        head = tail = NULL;
                        delete it->second;
                } else if (it->second == head) { /* head node */
                        head = head->next;
                        head->prev = NULL;
                        delete it->second;
                } else if (it->second == tail) { /* tail node */
                        tail = tail->prev;
                        tail->next = NULL;
                        delete it->second;
                } else { /* generic case */
                        DLL_Node<T> *temp = it->second;
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        delete temp;
                }

                /* remove from hashmap */
                hash.erase(it);

                it = hash.find(data);
        }

        return (ret);
}

template <class T>
void Hashed_DLL<T>::print_dll()
{
        DLL_Node<T> *it = head;
        while (it) {
                cout << it->data << " <=> ";
                it = it->next;
        }
        cout << "(Null)" << endl;
}

template <class T>
void Hashed_DLL<T>::print_hash()
{
        typename multimap<T, DLL_Node<T>*>::iterator it;

        cout << "[ ";
        for (it = hash.begin(); it != hash.end(); ++it) {
                cout << it->second->data << " ";
        }
        cout << "]" << endl;
}

template <class T>
void Hashed_DLL<T>::print(print_type type = PRINT_DLL)
{
        switch (type) {
        case PRINT_DLL:
                print_dll();
                break;
        case PRINT_HASH:
                print_hash();
                break;
        default:
                cout << "Unknown type" << endl;
                print_dll();
        }
}

#endif /* __HASHED_DLL__ */
