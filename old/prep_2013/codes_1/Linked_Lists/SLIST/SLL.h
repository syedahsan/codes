#ifndef __SLL_H__
#define __SLL_H__

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
                void delete_node(Node<T> *del, Node<T> *prev);
                void delete_node_pseudo(Node<T> *del);

        public:
                /* constructors & destructors */
                SList();
                /* NOT IMPLEMENTED
                SList(const SList<T> &other);
                SList<T>& operator=(const SList<T> &rhs);
                */
                ~SList();

                /* basic operations */
                void push_back(T data);
                void push_front(T data);
                void delete_first(T data);
                void delete_all(T data);
                bool is_present(T data);
                void print();
};

template <class T>
SList<T>::SList() :
        head(NULL)
{
}

template <class T>
SList<T>::~SList()
{
        Node<T> *temp = NULL;
        while(head) {
                temp = head;
                head = head->next;
                delete temp;
        }

        head = NULL;
}


/* push_back */
template <class T>
void SList<T>::push_back(T data)
{
        Node<T> *node = new Node<T>(data);
        
        /* first element */
        if (!head) {
                head = node;
                return;
        }

        Node<T> *temp = head;
        while(temp && temp->next)
                temp = temp->next;
        temp->next = node;

        return;
}

/* push_front */
template <class T>
void SList<T>::push_front(T data)
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
bool SList<T>::is_present(T data)
{
        return ((search(data)) ? true : false);
}

/* delete just the first occurence of data */
template <class T>
void SList<T>::delete_first(T data)
{
        Node<T> *del = search(data);
        delete_node(del);
}

/* deletes all the occurence of data */
template <class T>
void SList<T>::delete_all(T data)
{
        Node<T> *iter = head;
        Node<T> *prev = iter;
        while(iter) {
                if (iter->data == data) {
                        delete_node(iter, prev);
                } else {
                        prev = iter;
                }
                iter = iter->next;
        }
}

/* delete a node; prev can be some node 
 * previous to the delete pointer
 * if nothing is provided; head will be taken
 * as previous pointer
 */
template <class T>
void SList<T>::delete_node(Node<T> *del, Node<T> *prev = NULL)
{
        if (!del) { /* NULL pointer provided/data not present */
                return;
        } else if (del == head) { /* data is at the head pointer */
                head = head->next;
                delete del;
        } else {
                if (!prev || prev == del)
                        prev = head;
                while (prev && prev->next) {
                        if (prev->next == del)
                                break;
                        prev = prev->next;
                }
                if (prev->next == del) {
                        prev->next = del->next;
                        delete del;
                } else {
                        /* not a valid prev pointer/data not found */
                }
        }
}

/* THIS IS ACTUALLY FOR CIRCULAR LINKED LISTS; so don't use in SLL
 * pseudo delete a node;
 * using data copy and deleting the false node
 * NOTE: Don't use if the address of nodes are of importance
 */
template <class T>
void SList<T>::delete_node_pseudo(Node<T> *del)
{
        if (!del)
                return; /* invalid pointer */

        Node<T> *temp = NULL;

        if (del->next == NULL) { /* del is the last pointer */
                /* we'll need head pointer only for this case */
                temp = head;
                while(temp) {
                        if (temp->next == del)
                                break;
                        temp = temp->next;
                }
                if (temp->next == del) {
                        temp->next = NULL;
                        delete del;
                } else; /* something is wrong */
                return;
        }

        if (del == head) { /* del is the head pointer */
                head = head->next;
                delete del;
                return;
        }

        {
                temp = del->next;
                del->next = temp->next;
                del->data = temp->data;
                delete temp;
                return;
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
        cout << "(Null)" << endl;
}

#endif /* __SLL_H__ */
