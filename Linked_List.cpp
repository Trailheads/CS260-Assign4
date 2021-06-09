#include "Linked_List.h"
#include <stdexcept>

template <typename T>
Linked_List<T>::Linked_List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}


template <typename T>
Linked_List<T>::~Linked_List() {
    Node<T> * current = head;

    while(current->next != nullptr) {
        head = current->next;
        delete current;
        current = head;
    }

    delete current;
}


template <typename T>
Linked_List<T>::Linked_List(const Linked_List &LL) {
    Node<T> * current = this->head;
    int counter = 0;
    
    while(current != nullptr) {
        this->add(current->value, counter);
        current = current->next;
        ++counter;
    }
}


template <typename T>
void Linked_List<T>::add(const T value, const int position) {
    if(position < 0 || position > size) {
        throw std::out_of_range("Position can't be less than 0 or greater than the current list size: ");
    }

    Node<T> * new_node = new Node<T>;
    new_node->datum = value;

    if(head == nullptr) {
        head = new_node;
    }
    else if(tail == nullptr) {
        tail = new_node;
        head->next = tail;
    }
    else if(position == 0) {
        new_node->next = head->next;
        head = new_node;
    }
    else if(position == size) {
        Node<T> * current = head;

        for(int i = 0; i < (size - 1); i++) {
            current = current->next;
        }

        current->next = new_node;
        tail = new_node;
    }
    else {
        new_node = head;
        Node<T> * previous;
        int counter = 0;

        while(counter < position) {
            previous = new_node;
            new_node = new_node->next;
            ++counter;
        }

        new_node->datum = value;
        Node<T> * save_node;
        save_node = previous;

        previous->next = new_node;
        new_node->next = save_node;
    }

    size++;
}


template <typename T>
T Linked_List<T>::remove(const int position) {
    if(position < 0 || position > size) {
        throw std::out_of_range("Position can't be less than 0 or greater than the current list size.");
        return -1;
    }

    Node<T> * current = head;
    Node<T> * previous;
    int counter = 0;

    while(counter < position) {
        previous = current;
        current = current->next;
        counter++;
    }

    previous->next = current->next;
    T save_datum = current->datum;
    delete current;
    --size;

    return save_datum;
}


template <typename T>
T Linked_List<T>::get(const int position) {
    if(position < 0 || position > size) {
        throw std::out_of_range("Position can't be less than 0 or greater than the current list size");
        return -1;
    }

    Node<T> * current = head;
    int counter = 0;

    while(counter < position) {
        current = current->next;
        ++counter;
    }

    return current->datum;
}

template <typename T>
int Linked_List<T>::get_size() const{
    return size;
}