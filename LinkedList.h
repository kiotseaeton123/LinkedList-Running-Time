// linkedList header file
#include <iostream>

struct Node
{
public:
    int key;
    Node *next;
    Node *prev;

    Node()
    { // default constructor
        key = 0;
        next = prev = nullptr;
    }

    Node(int _key)
    { // constructor with parameter
        key = _key;
        next = prev = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = tail = nullptr;
    }
    void _insertSorted(int _key);
    void _delete(int _key);
    void _print();
};

void LinkedList::_insertSorted(int _key)
{
    Node *tempNew = new Node(_key);

    if (head == nullptr)
    {
        head = tail = tempNew;
    }
    else
    {
        // insert new node at beginning if _key is smaller than head->key
        if (_key < head->key)
        {
            tempNew->next = head;
            head->prev = tempNew;
            tail = head;
            head = tempNew;
            return;
        }
        // insert new node at end of linkedList
        if (_key > tail->key)
        {
            tail->next = tempNew;
            tempNew->prev = tail;
            tail = tempNew;
            return;
        }

        Node *_tempHead = head; // temp variable to traverse linkedList

        // traverse linkedlist until the new node can be inserted into sorted position
        while (_tempHead->next != nullptr)
        {
            _tempHead = _tempHead->next;
            
            if (_tempHead->key > _key)
            {
                
                break;
            }
        }

        // insert new node into linkedList: link temp with previous node
        Node *_tempPrev = _tempHead->prev;
        _tempPrev->next = tempNew;
        tempNew->prev = _tempPrev;
        // insert new node into linkedList: link temp with next node
        tempNew->next = _tempHead;
        _tempHead->prev = tempNew;
    }
}

void LinkedList::_delete(int _key)
{
    Node *_temp = head;

    while (_temp->next != nullptr)
    {
        // if key is found, delete node and break out of loop
        if (_temp->key == _key)
        {
            Node *_tempPrev = _temp->prev;
            Node *_tempNext = _temp->next;
            _tempPrev->next = _tempNext;
            _tempNext->prev = _tempPrev;
            break;
        }
        // key is not found, continue iterating thru linkedList
        _temp = _temp->next;
    }
}

void LinkedList::_print()
{ // print check
    Node *_temp = head;

    while (_temp->next != nullptr)
    {
        std::cout << _temp->key << " ";
        _temp = _temp->next;
    }
    std::cout << _temp->key << std::endl; // end string buffer
}
