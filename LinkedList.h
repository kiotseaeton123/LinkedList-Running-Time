// linkedList header file
struct Node
{
public:
    int key;
    Node *next;
    Node * prev;

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
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }
    void _insertSorted(int _key);
    void _delete(int _index);
    void _print();
};

void ::LinkedList::_insertSorted(int _key)
{
    Node *temp = new Node(_key);

    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        // insert new node at beginning if _key is smaller than head->key
        if (_key < head->key)
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        Node *_tempHead = head; //temp variable to traverse linkedList

        // traverse linkedlist until the new node can be inserted into sorted position
        while (_tempHead->next != nullptr && _key < _tempHead->next->key)
        {
            _tempHead = _tempHead->next;
        }
        
        //insert new node into linkedList: link temp with previous node
        Node *_tempPrev = _tempHead->prev;
        _tempPrev->next = temp;
        temp->prev = _tempPrev;
        //insert new node into linkedList: link temp with next node
        temp->next = _tempHead;
        _tempHead->prev = temp;
    }
}

void::LinkedList::_delete(int _index){
    
}