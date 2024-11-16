#ifndef _NODE_H_
#define _NODE_H_

#include "types.h"

class Node {
    public:
        Node(int value);
        // Setters
        void setValue(int value) { value_ = value; }
        void setNext(Node* next) { next_ = next; }
        // Getters
        int getValue(void) { return value_; }
        Node* getNext(void) { return next_; }

    private:
        int value_;
        Node* next_;
};

#endif // _NODE_H_
