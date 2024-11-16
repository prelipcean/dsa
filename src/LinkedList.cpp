#include <iostream>
#include "LinkedList.hpp"

LinkedList::LinkedList(int value)
{
    Node* newNode = new Node(value);

    // Constructor already creates a node with the given value
    head_ = newNode;
    tail_ = newNode;
    
    // Set length to 1 because we added only a node with the constructor
    length_ = 1;
}

LinkedList::~LinkedList()
{
    Node* temp = head_;
    uint8 l_numNodes_u8 = 0u;

    while (head_)
    {
        head_ = head_->getNext();
        delete temp;
        temp = head_;
        l_numNodes_u8++;
    }

    std::cout << "LL deleted " << (int)l_numNodes_u8 << std::endl;
}

void LinkedList::printLL(void)
{
    Node* temp = head_;

    while (temp != nullptr)
    {
        std::cout << temp->getValue() << std::endl;
        temp = temp->getNext();
    }
}

void LinkedList::getHeadLL(void)
{
    if (nullptr == head_)
    {
        std::cout << "Head: nullptr" << std::endl;
    }
    else
    {
        std::cout << "Head: " << head_->getValue() << std::endl;
    }
}

void LinkedList::getTailLL(void)
{
    if (nullptr == tail_)
    {
        std::cout << "Tail: nullptr" << std::endl;
    }
    else
    { 
        std::cout << "Tail: " << tail_->getValue() << std::endl;
    }  
}

// Getter for length of the list
void LinkedList::getLengthLL(void)
{
    std::cout << "Length: " << length_ << std::endl;
}

void LinkedList::appendLL(int value)
{
    // Create a new node
    Node* newNode = new Node(value);

    // Check if LL is empty
    if((0 == length_) || (nullptr == head_))
    {
        // LL was empty, appended node is the only node in LL and we set head and tail
        head_ = newNode;
        tail_ = newNode;
    }
    else
    {
        // Set tail->next of last node equal to new node
        // and tail = new node because new node is the last one in the list now
        tail_->setNext(newNode);
        tail_ = newNode;
    }
    
    // Increment size of the LL
    length_++;
}

void LinkedList::deleteLastLL(void)
{
    Node* temp = nullptr;
    Node* pre = nullptr;

    if((0 == length_) || (nullptr == head_))
    {
        std::cout << "List is empty!\n"<< std::endl;
    }
    else
    {
        temp = head_;
        pre = head_;

        // Start iterating until nullptr is next node
        while(temp->getNext() != nullptr)
        {
            pre = temp; // set previous node to temporary node
            temp = temp->getNext(); // change temporary node to next node which is not nullptr
        } // We break out of while loop when temp->next == nullptr

        // Move tail one node back
        tail_ = pre;
        tail_->setNext(nullptr);

        if(length_ > 1)
        {
            length_--; // decrement length

            std::cout << "\nLast node was deleted!\n"<< std::endl;
        }
        else
        {
            // This is the only node
            head_ = nullptr;
            tail_ = nullptr;
            length_ = 0;

            std::cout << "\nThis was the only node in the list and it was deleted now\n"<< std::endl;
        }

        delete temp; // Delete last node
    }
}

void LinkedList::prependLL(int value)
{
    // Create a new node
    Node* newNode = new Node(value);

    if((0 == length_) || (nullptr == head_))
    {
        head_ = newNode;
        tail_ = newNode;
    }
    else
    {
        newNode->setNext(head_);
        head_ = newNode;
    }

    length_++;
}

void LinkedList::deleteFirstLL(void)
{
    Node* temp = nullptr;

    if((0 == length_) || (nullptr == head_))
    {
        std::cout << "List is empty!\n"<< std::endl;
    }
    else
    {
        temp = head_;

        if(length_ > 1)
        {
            head_ = head_->getNext();
            length_--; // decrement size of list
        }
        else
        {
            // Only one element/node in the linked list
            head_ = nullptr;
            tail_ = nullptr;
        }

        delete temp; // Delete node
    }
}

Node* LinkedList::getNodeLL(int index)
{
    Node* temp = nullptr;

    if((index >= 0) && (index < length_))
    {
        temp = head_;

        for(int i = 0; i < index; i++)
        {
            temp = temp->getNext();
        }
    }
    else
    {
        temp = nullptr;
    }

    return temp;
}

bool LinkedList::setValueLL(int index, int value)
{
    bool l_return_b = false;
    Node* temp = nullptr;

    temp = getNodeLL(index);
    if(temp != nullptr)
    {
        temp->setValue(value);
        l_return_b = true;
    }
    else
    {
        l_return_b = false;
    }

    return l_return_b;
}

bool LinkedList::insertLL(int index, int value)
{
    bool l_return_b = false;

    if((index < 0) || (index > length_))
    {
        l_return_b = false;
    }
    else if(0 == index)
    {
        prependLL(value);
        length_++;
        l_return_b = true;
    }
    else if(length_ == index)
    {
        appendLL(value);
        length_++;
        l_return_b = true;
    }
    else
    {
        Node* newNode = new Node(value); // New node to be inserted
        Node* temp = getNodeLL(index - 1); // Get pointer of previous node
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
        length_++;
        l_return_b = true;
    }

    return l_return_b;
}

void LinkedList::deleteNodeLL(int index)
{
    if((index < 0) || (index >= length_))
        return;

    if(0 == index)
    {
        deleteFirstLL();
    }
    else if((length_ - 1) == index)
    {
        deleteLastLL();
    }
    else
    {
        Node* prev = getNodeLL((index - 1));
        Node* temp = prev->getNext();
        prev->setNext(temp->getNext());
        delete temp;
        length_--;
    }
}

void LinkedList::reverseLL(void)
{
    Node* temp = nullptr;
    Node* after = nullptr;
    Node* before = nullptr;
    
    // Step 1 reverse head and tail
    temp = head_;
    head_ = tail_;
    tail_ = temp;

    // Step 2 create moving window that switches pointer direction
    // temp Node already holds old head_ pointer
    after = temp->getNext();
    // before Node already holds null pointer

    // Iterate over remaining nodes
    for(int i = 0; i < length_; i++)
    {
        after = temp->getNext();
        temp->setNext(before);
        before = temp;
        temp = after;
    }
}

Node* LinkedList::findMiddleNode(void)
{
    #if 0 // Disable this variant
    Node* returnNode = nullptr;

    switch (length_)
    {
        case 0:
            returnNode = nullptr;
            break;
        case 1:
            returnNode = getNodeLL(1);
            break;
        case 2:
            returnNode = getNodeLL(2);
            break;
        default:
            /* If the list has an even number of nodes, 
                return the second middle node (the one closer to the end).
            */
            returnNode = getNodeLL((int)(length_ / 2));
            // if(0 == (length_ % 2))
            break;
    }

    return returnNode;
    #endif

    // Initialize slow and fast pointers to head
    Node* slow = head_;
    Node* fast = head_;

    // Traverse the list until fast reaches the end
    while (fast != nullptr && fast->getNext() != nullptr)
    {
        // Move slow pointer one step forward
        slow = slow->getNext();
        
        // Move fast pointer two steps forward
        fast = fast->getNext()->getNext();
    }
    
    // When the loop ends, slow points to the middle
    return slow;
}
