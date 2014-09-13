#include "Slist.h"

#ifdef USE_EXPORT_KEYWORD
export
#endif

using namespace std;

template <class T>
inline Node<T>::Node(T _data = 0) :
        data(_data), next(NULL)
{
}

template <class T>
inline SList<T>::SList() :
        head(NULL)
{
}

/* push_front */
template <class T>
inline void SList<T>::insert(T data)
{
        Node<T> *node = new Node<T>(data);
        node->next = head;
        head = node;
}

template <class T>
inline Node<T>* SList<T>::search(T data)
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
inline bool SList<T>::isPresent(T data)
{
        return ((search(data)) ? true : false);
}

/* Removes just the first occurence of data */
template <class T>
inline void SList<T>::remove(T data)
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
inline void SList<T>::print()
{
        Node<T> *node = head;
        while (node) {
                cout << node->data << " -> ";
                node = node->next;
        }
        cout << "NULL" << endl;
}
