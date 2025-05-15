#ifndef FA23_CS20A_LlST_H
#define FA23_CS20A_LlST_H

#include<iostream>
#include<assert.h>
#include <codecvt>
// Linked DLList object that maintains both head and tail pointers
// and the count of the list.  Note that you have to keep the head,
// tail and count consistent with the intended state of the DLList 
// otherwise very bad things happen.

template<typename Item>
class DLList {
public:
    DLList();

    DLList(const DLList<Item> &other);

    DLList<Item> &operator=(const DLList<Item> &other);

    ~DLList();

    void print() const;

    bool empty() const;

    void add_front(const Item &itm);

    void add_rear(const Item &itm);

    void add(int idx, const Item &itm);

    // Note that the user must head ensure the list is not empty
    // prior to calling these functions.
    Item front() const;

    Item rear() const;

    Item peek(int idx) const;

    int size() const;

    int items(const Item &itm) const;

    int search(const Item &itm) const;

    bool remove_front();

    bool remove_rear();

    bool remove_index(int idx);

    int remove_item(const Item &itm);


    bool sub_list(const DLList<Item> &sub);

#ifndef MAKE_MEMBERS_PUBLIC

private:
#endif
    // Forward declare the nodes for our DLList.
    // Will be implemented along with list
    // member functions
    class Node;

    // We'll have both head and tail points for
    // Fast insertion/deletion from both ends.
    Node *head;
    Node *tail;

    // Keep track of number of nodes in the list
    int count;
};


/* DLList Implementation
//
//  Since DLList is a template class (which is not an actual
//  class yet, not until we actually instantiate the list)
//  we need to keep the implementation together with
//  the definition.  There are ways to simulate having
//  separate "implementation/definition" with templates,
//  but they aren't necessary and can be confusing.
*/

/* Node definition
//		Already implemented, nothing to do here but to use it.
*/
template<typename Item>
class DLList<Item>::Node {
public:
    Node() : next(nullptr), prev(nullptr) {
    }

    Node(Item i, Node *p, Node *n) : item(i), next(n), prev(p) {
    }

    Node *nxt() const { return next; }
    void nxt(Node *n) { next = n; }

    Node *prv() const { return prev; }
    void prv(Node *p) { prev = p; }

    Item itm() const { return item; }
    void itm(const Item &i) { item = i; }

private:
    Item item;
    Node *next;
    Node *prev;
};


/* DLList default constructor
//		Already implemented, nothing to do.
*/
template<typename Item>
DLList<Item>::DLList() : head(nullptr), tail(nullptr), count(0) {
}


/* Copy constructor
*/
template<typename Item>
DLList<Item>::DLList(const DLList<Item> &other) {
    if (other.empty()) {
        head = nullptr;
        tail = nullptr;
        count = 0;
        return;
    }

    Node* other_current = other.head;
    while (other_current != nullptr) {
        add_rear(other_current->itm());
        other_current =  other_current->nxt();
    }
}

/* Overloaded assignment operator
*/
template<typename Item>
DLList<Item> &DLList<Item>::operator=(const DLList<Item> &other) {
    /*   TODO   */
    return *this;
}


/* DLList destructor
*/
template<typename Item>
DLList<Item>::~DLList() {
    if (!empty()) {
        Node *current = head;
        while (current != nullptr) {
            Node *garbage = current;
            current = current->nxt();
            delete garbage;
        }
        //set to empty state
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
}

/* DLList print
*/

template<typename Item>
void DLList<Item>::print() const {
    Node* current = head;
    while (current !=  nullptr) {
        std::cout << current -> itm();
        if (current != tail)
            std::cout << " ";
        current = current->nxt();
    }
}

/* DLList empty
*/
template<typename Item>
bool DLList<Item>::empty() const {
    return (head == nullptr) && (tail == nullptr) && (count == 0);
}


/* DLList add_front
*/
template<typename Item>
void DLList<Item>::add_front(const Item &itm) {
    Node *newNode = new Node;
    newNode->itm(itm);
    if (empty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->nxt(head);
        head->prv(newNode);
        head = newNode;
    }
    count++;
}

/* DLList add_rear
*/
template<typename Item>
void DLList<Item>::add_rear(const Item &itm) {
    if (empty())
        add_front(itm);
    else {
        Node *newNode = new Node;
        newNode->itm(itm);
        newNode->prv(tail);
        tail->nxt(newNode);
        tail = newNode;
        count++;
    }
}

/* DLList add
*/
template<typename Item>
void DLList<Item>::add(int idx, const Item &itm) {
    if (idx <= 0) {
        add_front(itm);
    } else if (idx >= count) {
        add_rear(itm);
    } else {
        int index = 0;
        Node *current = head;
        while (index < idx) {
            current = current->nxt();
            index++;
        }
        Node *newNode = new Node(itm, current->prv(), current);
        current->prv()->nxt(newNode);
        current->prv(newNode);
        count++;
    }
}

/*  DLList front
*/
template<typename Item>
Item DLList<Item>::front() const {
    // Force check that the head is pointing to a Node
    // Typical solution for deployement code is to throw
    // exceptions, but since we haven't covered that yet
    // we'll make due with assert, which is used for testing
    assert(head != nullptr);

    return head->itm();
}

/* DLList rear
*/
template<typename Item>
Item DLList<Item>::rear() const {
    // Force check that the tail is pointing to a Node
    // Typical solution for deployement code is to throw
    // exceptions, since we haven't covered that yet
    // we'll make due with assert, which is used for testing
    assert(tail != nullptr);

    return tail->itm();
}

/* DLList peek
*/
template<typename Item>
Item DLList<Item>::peek(int idx) const {
    // Force index to be correct before getting the Item
    // Typical solution for deployement code is to throw
    // exceptions, since we haven't covered that yet
    // we'll make due with assert, which is used for testing
    assert(idx >= 0 && idx < count);
    int index = 0;
    Node *current = head;
    while (index != idx) {
        current = current->nxt();
        index++;
    }
    return current->itm();
}

/* DLList size
*/
template<typename Item>
int DLList<Item>::size() const {
    return count;
}

template<typename Item>
int DLList<Item>::items(const Item &itm) const {
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
        if (current->itm() == itm)
            count++;
        current = current->nxt();
    }
    return count;
}

/* DLList search
*/
template<typename Item>
int DLList<Item>::search(const Item &itm) const {
    int index = 0;
    bool found = false;
    Node *current = head;
    while (current != nullptr) {
        if (current->itm() == itm) {
            found = true;
            break;
        }
        current = current->nxt();
        index++;
    }
    if (!found)
        return -42;

    return index;
}

/* DLList remove_front
*/
template<typename Item>
bool DLList<Item>::remove_front() {
    if (empty())
        return false;

    if (size() == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *garbage = head;
        head = head->nxt();
        head->prv(nullptr);
        delete garbage;
    }
    count--;
    return true;
}

/* DLList remove_rear
*/
template<typename Item>
bool DLList<Item>::remove_rear() {
    if (empty())
        return false;
    if (size() == 1) {
        delete tail;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *garbage = tail;
        tail = tail->prv();
        tail->nxt(nullptr);
        delete garbage;
    }
    count--;
    return true;
}

/* DLList remove_index
*/
template<typename Item>
bool DLList<Item>::remove_index(int idx) {
    if (idx < 0 || idx >= size() || empty())
        return false;
    if (idx == 0)
        return remove_front();
    else if (idx == size() - 1)
        return remove_rear();
    else {
        int index = 1;
        Node *current = head->nxt();
        while (index < idx) {
            current = current->nxt();
            index++;
        }
        current->prv()->nxt(current->nxt());
        current->nxt()->prv(current->prv());
        delete current;
    }

    count--;
    return true;
}

/* DLList remove_item
*/
template<typename Item>
int DLList<Item>::remove_item(const Item &itm) {
    if (empty())
        return -1;

    int index = search(itm);
    if (index >= 0)
        remove_index(index);
    return index;
}

/* DLList sub_list
*/
template<typename Item>
bool DLList<Item>::sub_list(const DLList<Item> &sub) {
    //an empty list is a sub list of any list
    if (sub.empty())
        return true;
    if (empty() || sub.size() > size())
        return false;

    Node *current_node = head;
    Node *sub_current = sub.head;
    int count = 0;
    while (current_node != nullptr) {
        if (sub_current->itm() == current_node->itm()) {
            sub_current = sub_current->nxt();
            count++;
            if (count == sub.size())
                return true;
        } else {
            sub_current = sub.head;
            count = 0;
            if (sub_current->itm() == current_node->itm())
                continue;
        }
        current_node = current_node->nxt();
    }
    return false;
}

#endif


// _X_XMMXXI
