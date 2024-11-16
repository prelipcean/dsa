#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "Node.hpp"
#include "types.h"

class LinkedList {
    public:
        LinkedList(int value);
        ~LinkedList();

        void printLL(void);
        void getHeadLL(void);
        void getTailLL(void);
        void getLengthLL(void);
        void appendLL(int value);
        void deleteLastLL(void);
        void prependLL(int value);
        void deleteFirstLL(void);
        Node* getNodeLL(int index);
        bool setValueLL(int index, int value);
        bool insertLL(int index, int value);
        void deleteNodeLL(int index);
        void reverseLL(void);
        Node* findMiddleNode(void);

    private:
        Node* head_;
        Node* tail_;
        int length_;
};

#endif // _LINKEDLIST_H_
