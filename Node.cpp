#include "Node.h"
#include <iostream> //for nullptr to be recognized

template <typename T> 
Node<T>::Node() {
    datum = 0;
    next = nullptr;
}


template <typename T>
Node<T>::~Node() {

}