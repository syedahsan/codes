#ifndef __SLL_H__
#define __SLL_H__

#include <iostream>
#include <map>

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
                Node<T>* search(T data) const;
                void delete_node(Node<T> *del, Node<T> *prev);
                void delete_node_pseudo(Node<T> *del);
                void free_and_nullify();
                void iterative_reverse();
                void recursive_reverse();
                Node<T>* _recursive_reverse(Node<T> *ptr);

        public:
                /* constructors & destructors */
                SList();
                SList(const SList<T> &other);
                SList<T>& operator=(const SList<T> &rhs);
                ~SList();

                /* basic operations */
                void push_back(T data);
                void push_front(T data);
                void delete_first(T data);
                void delete_all(T data);
                bool is_present(T data) const;
                void print() const;
                size_t size() const;
                void reverse();

                /* special operations */
                bool tryGet_kth_end(int k, T *ret) const;
                void remove_duplicates_n2();
                void remove_duplicates_hash();
                void partition_around_x(T x);
                bool is_palindrome();
};

template <class T>
SList<T>::SList() :
        head(NULL)
{
}

template <class T>
SList<T>::SList(const SList<T> &other)
{
        Node<T> *temp = other.head;
        while (temp) {
                push_back(temp->data);
                temp = temp->next;
        }
}

template <class T>
SList<T>& SList<T>::operator=(const SList<T> &rhs)
{
        if (this != &rhs) {
                free_and_nullify();
                Node<T> *temp = rhs.head;
                while (temp) {
                        push_back(temp->data);
                        temp = temp->next;
                }
        }

        return (*this);
}

template <class T>
void SList<T>::free_and_nullify()
{
        Node<T> *temp = NULL;
        while (head) {
                temp = head;
                head = head->next;
                delete temp;
        }
        head = NULL;
}

template <class T>
SList<T>::~SList()
{
        free_and_nullify();
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
Node<T>* SList<T>::search(T data) const
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
bool SList<T>::is_present(T data) const
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
void SList<T>::print() const
{
        Node<T> *node = head;
        while (node) {
                cout << node->data << " -> ";
                node = node->next;
        }
        cout << "(Null)" << endl;
}

template <class T>
size_t SList<T>::size() const
{
        size_t size = 0;
        Node<T> *temp = head;

        while (temp) {
                temp = temp->next;
                ++size;
        }

        return (size);
}

template <class T>
void SList<T>::iterative_reverse()
{
        if (head == NULL || head->next == NULL)
                return;

        Node<T> *prev = head;
        Node<T> *it = head->next;

        while (it) {
                Node<T> *temp = it;
                it = it->next;
                temp->next = prev;
                if (prev == head)
                        prev->next = NULL;
                prev = temp;
        }
        head = prev;
}

template <class T>
Node<T>* SList<T>::_recursive_reverse(Node<T> *start)
{
        if (start == NULL || start->next == NULL)
                return (start);

        Node<T> *rest = _recursive_reverse(start->next);
        start->next->next = start;
        start->next = NULL;

        return (rest);
}

template <class T>
void SList<T>::recursive_reverse()
{
        head = _recursive_reverse(head);
}

template <class T>
void SList<T>::reverse()
{
        iterative_reverse();
        // recursive_reverse();
}        

template <class T>
bool SList<T>::tryGet_kth_end(int k, T *ret) const
{
        if ((k >= (int)size()) || (k < 0))
                return (false);

        Node<T> *start = head;
        Node<T> *end = head;
        
        for (int i = 0; i < k; i++)
                end = end->next;
        while (end) {
                end = end->next;
                if (end)
                        start = start->next;
        }
        *ret = start->data;
        return (true);
}

template <class T>
void SList<T>::remove_duplicates_n2()
{
        Node<T> *one = head;
        Node<T> *prev = NULL;
        Node<T> *del = NULL;
        while (one) {
                Node<T> *two = one->next;
                prev = one;
                while (two) {
                        if (one->data == two->data) {
                                del = two;
                                two = two->next;
                                delete_node(del, prev);
                        } else {
                                prev = two;
                                two = two->next;
                        }
                }
                one = one->next;
        }
}

template <class T>
void SList<T>::remove_duplicates_hash()
{
        map<T, int> hash;
        typename std::map<T, int>::iterator it;
        Node<T> *temp = head;
        Node<T> *prev = temp;

        hash.clear();
        while (temp) {
                if (hash.find(temp->data) != hash.end()) {
                        Node<T> *del = temp;
                        hash[del->data] += 1;
                        temp = temp->next;
                        delete_node(del, prev);
                } else {
                        prev = temp;
                        hash[temp->data] = 1;
                        temp = temp->next;
                }
        }
}

template <class T>
void SList<T>::partition_around_x(T x)
{
        Node<T> *s_head, *g_head, *s_it, *g_it;
        s_head = g_head = s_it = g_it = NULL;

        Node<T> *it = NULL;
        while (head) {
                it = head;
                head = head->next;
                if (it->data < x) { /* small pointer */
                        if (s_head == NULL) {
                                s_head = it;
                        } else {
                                s_it->next = it;
                        }
                        s_it = it;
                        s_it->next = NULL;
                } else { /* greater pointer */
                        if (g_head == NULL) {
                                g_head = it;
                        } else {
                                g_it->next = it;
                        }
                        g_it = it;
                        g_it->next = NULL;
                }
        }

       if (s_head == NULL) {
               head = g_head;
               return;
       } else {
               head = s_head;
               s_it->next = g_head;
               return;
       }
}

template <class T>
bool SList<T>::is_palindrome()
{
        SList<T> temp = *this;
        temp.reverse();

        Node<T> *it = head;
        Node<T> *rev_it = temp.head;
        while (it && rev_it) {
                if (it->data != rev_it->data)
                        return (false);
                it = it->next;
                rev_it = rev_it->next;
        }

        return (true);
}

#endif /* __SLL_H__ */
