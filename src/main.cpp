#include <iostream>
#include "types.h"
#include "LinkedList.hpp"

int main(int argc, char *argv[])
{     
    bool test = false;

    std::cout << "\nTest Linked List:\n";

    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->appendLL(2);

    std::cout << myLinkedList->getNodeLL(1) << std::endl;
    std::cout << myLinkedList->getNodeLL(1)->getValue() << std::endl;

    test = myLinkedList->setValueLL(10, 5);
    if(test)
        std::cout << myLinkedList->getNodeLL(1)->getValue() << std::endl;
    else
        std::cout << "Can't write value at given index" << std::endl;
    
    test = myLinkedList->insertLL(1,8);
    if(test)
        std::cout << myLinkedList->getNodeLL(1)->getValue() << std::endl;
    else
        std::cout << "Can't insert node at given index" << std::endl;

    myLinkedList->getHeadLL();
    myLinkedList->getTailLL();
    myLinkedList->getLengthLL();

    std::cout << "\nLinked List values:\n";
    myLinkedList->printLL();
    std::cout << std::endl;

    myLinkedList->prependLL(10);
    myLinkedList->prependLL(11);
    myLinkedList->prependLL(12);
    myLinkedList->prependLL(13);
    myLinkedList->prependLL(14);
    myLinkedList->prependLL(15);
    std::cout << "\nLinked List values:\n";
    myLinkedList->printLL();
    std::cout << std::endl;

    std::cout << "\nMiddle Linked List:\n";
    std::cout << myLinkedList->findMiddleNode() << std::endl;
    std::cout << myLinkedList->findMiddleNode()->getValue() << std::endl;

    myLinkedList->reverseLL();
    std::cout << "\nLinked List values:\n";
    myLinkedList->printLL();
    std::cout << std::endl;

    myLinkedList->deleteNodeLL(1);
    std::cout << "\nLinked List values:\n";
    myLinkedList->printLL();
    std::cout << std::endl;

    std::cout << "Call delete"<< std::endl;
    // myLinkedList->deleteLastLL();
    myLinkedList->deleteFirstLL();
    myLinkedList->printLL();

    std::cout << "Call delete"<< std::endl;
    // myLinkedList->deleteLastLL();
    myLinkedList->deleteFirstLL();
    myLinkedList->printLL();

    std::cout << "Call delete"<< std::endl;
    // myLinkedList->deleteLastLL();
    myLinkedList->deleteFirstLL();
    myLinkedList->printLL();

    std::cout << "Call delete"<< std::endl;
    // myLinkedList->deleteLastLL();
    myLinkedList->deleteFirstLL();
    myLinkedList->printLL();

    std::cout << "Call delete"<< std::endl;
    // myLinkedList->deleteLastLL();
    myLinkedList->deleteFirstLL();
    myLinkedList->printLL();

    std::cout << "Call prepend: "<< std::endl;
    myLinkedList->prependLL(1);
    myLinkedList->printLL();

    std::cout << "Delete LL:"<< std::endl;
    delete myLinkedList;

    return 0;
}
