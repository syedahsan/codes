#ifndef __SLIST_H__
#define __SLIST_H__

#include <iostream>

using namespace std;

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
Node<T>::Node(T _data = 0) :
        data(_data), next(NULL)
{
}

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

template <class T>
SList<T>::SList() :
        head(NULL)
{
}

/* push_front */
template <class T>
void SList<T>::insert(T data)
{
        Node<T> *node = new Node<T>(data);
        node->next = head;
        head = node;
}

template <class T>
Node<T>* SList<T>::search(T data)
{
        Node<T> *node = head;
        while(node) {
                if (node->data == data)
                        break;
                node = node->next;
        }
        return node;
}

template <class T>
bool SList<T>::isPresent(T data)
{
        return ((search(data)) ? true : false);
}

/* Removes just the first occurence of data */
template <class T>
void SList<T>::remove(T data)
{
        Node<T> *node = search(data);
        if (!node) {
                return; /* Not found */
        } else if (head == node) {
                head = head->next;
                delete node;
        } else {
                Node<T> *temp = head;
                while (temp && temp->next) {
                        if (temp->next == node)
                                break;
                        temp = temp->next;
                }
                temp->next = node->next;
                delete node;
        }
}

template <class T>
void SList<T>::print()
{
        Node<T> *node = head;
        while (node) {
                cout << node->data << " -> ";
                node = node->next;
        }
        cout << "NULL" << endl;
}

#endif /* __SLIST_H__ */
