#include "MagicalContainer.hpp"

MagicalContainer::MagicalContainer() : firstPrime(NULL), head(NULL), tail(NULL), listSize(0)
{
}
void MagicalContainer::addElement(int data)
{
    Node *newNode = new Node(data);
    newNode->getIsPrime() ? addPrimeElement(newNode) : addNonPrimeElement(newNode);
}

void MagicalContainer::addPrimeElement(Node *newNode)
{
    Node *lastNode = NULL;
    Node *lastPrime = NULL;
    Node *curr = head;
    while (curr)
    {
        if (newNode->getData() < curr->getData())
        {
            addToPrimesList(newNode, lastPrime);
            addToList(newNode, lastNode);
            return;
        }
        if (curr->getIsPrime())
            lastPrime = curr;
        lastNode = curr;
        curr = curr->getNext();
    }
    if (!firstPrime)
        firstPrime = newNode;
    else
        addToPrimesList(newNode, lastPrime);
    addToList(newNode, lastNode);
}

void MagicalContainer::addNonPrimeElement(Node *newNode)
{
    Node *lastNode = NULL;
    Node *curr = head;
    while (curr)
    {
        if (newNode->getData() < curr->getData())
        {
            addToList(newNode, lastNode);
            return;
        }
        lastNode = curr;
        curr = curr->getNext();
    }
    addToList(newNode, lastNode);
}

void MagicalContainer::removeElement(int data)
{
    Node *curr = head;
    while (curr)
    {
        if (data == curr->getData())
        {
            if (curr->getIsPrime())
                removeFromPrimesList(curr);
            removeFromList(curr);
            delete curr;
            listSize--;
            return;
        }
        curr = curr->getNext();
    }
    throw runtime_error("Element is not in the container");
}

void MagicalContainer::removeFromPrimesList(Node *curr)
{
    Node *prev = curr->getPrevPrime();
    Node *next = curr->getNextPrime();
    if (prev)
        prev->setNextPrime(next);
    if (next)
        next->setPrevPrime(prev);
    if (firstPrime == curr)
        firstPrime = next;
}
void MagicalContainer::removeFromList(Node *curr)
{
    Node *prev = curr->getPrev();
    Node *next = curr->getNext();
    if (prev)
        prev->setNext(next);
    if (next)
        next->setPrev(prev);
    if (head == curr)
        head = next;
    if (tail == curr)
        tail = prev;
}

void MagicalContainer::printList()
{
    Node *curr = head;
    cout << "HEAD";
    while (curr)
    {
        cout << " -> " << curr->getData();
        curr = curr->getNext();
    }
    cout << endl;
}

void MagicalContainer::printListAddresses()
{
    Node *curr = head;
    cout << "HEAD";
    while (curr)
    {
        cout << " -> " << curr;
        curr = curr->getNext();
    }
    cout << endl;
}

void MagicalContainer::printPrimes()
{
    Node *curr = firstPrime;
    cout << "PRIMES";
    while (curr)
    {
        cout << " -> " << curr->getData();
        curr = curr->getNextPrime();
    }
    cout << endl;
}

Node *MagicalContainer::getFirstPrime() const
{
    return firstPrime;
}

MagicalContainer::~MagicalContainer()
{
    Node *curr = head;
    while (curr)
    {
        Node *temp = curr;
        curr = curr->getNext();
        delete temp;
    }
}

size_t MagicalContainer::size() const
{
    return listSize;
}

void MagicalContainer::addToPrimesList(Node *newNode, Node *lastPrime)
{
    // there is a previous prime
    if (lastPrime)
    {
        Node *temp = lastPrime->getNextPrime();
        lastPrime->setNextPrime(newNode);
        newNode->setPrevPrime(lastPrime);
        newNode->setNextPrime(temp);
        if (temp)
            temp->setPrevPrime(newNode);
    }

    // newNode is the first prime
    else
    {
        if (firstPrime)
            firstPrime->setPrevPrime(newNode);
        newNode->setNextPrime(firstPrime);
        firstPrime = newNode;
    }
}

void MagicalContainer::addToList(Node *newNode, Node *lastNode)
{
    // there is a previous node
    if (lastNode)
    {
        Node *temp = lastNode->getNext();
        lastNode->setNext(newNode);
        newNode->setPrev(lastNode);
        newNode->setNext(temp);
        if (temp)
            temp->setPrev(newNode);
    }

    // newNode is the first node
    else
    {
        if (head)
            head->setPrev(newNode);
        newNode->setNext(head);
        head = newNode;
    }

    if (!newNode->getNext())
        tail = newNode;

    listSize++;
}

Node *MagicalContainer::getHead() const
{
    return head;
}

Node *MagicalContainer::getTail() const
{
    return tail;
}

MagicalContainer::MagicalContainer(const MagicalContainer &other) : firstPrime(NULL), head(NULL), tail(NULL), listSize(0)
{
    Node *otherCurr = other.getHead();
    while (otherCurr)
    {
        addElement(otherCurr->getData());
        otherCurr = otherCurr->getNext();
    }
}
MagicalContainer::MagicalContainer(MagicalContainer &&other) noexcept : firstPrime(other.getFirstPrime()), head(other.getHead()), tail(other.getTail()), listSize(other.size())
{
}

MagicalContainer &MagicalContainer::operator=(MagicalContainer &&other) noexcept
{
    if (this == &other)
        return *this;
    firstPrime = other.getFirstPrime();
    head = other.getHead();
    tail = other.getTail();
    listSize = other.size();
    return *this;
}

MagicalContainer &MagicalContainer::operator=(const MagicalContainer &other) 
{
    firstPrime = NULL;
    head = NULL;
    tail = NULL;
    listSize = 0;
    Node *otherCurr = other.getHead();
    while (otherCurr)
    {
        addElement(otherCurr->getData());
        otherCurr = otherCurr->getNext();
    }
    return *this;
}