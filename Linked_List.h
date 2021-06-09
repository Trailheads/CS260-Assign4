#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

template <class T>
class Linked_List {
    public:
        Linked_List();
        ~Linked_List();
        Linked_List(const Linked_List &LL);
        int get_size() const;

        void add(const T value, const int position);
        T remove(const int position);
        T get(const int position);

    private:
        Node<T> * head;
        Node<T> * tail;
        int size;
};

#endif