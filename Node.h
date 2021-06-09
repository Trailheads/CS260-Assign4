#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
    public:
        Node();
        ~Node();

        T datum;
        Node * next;
};

#endif