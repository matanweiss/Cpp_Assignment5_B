#include "Node.hpp"

Node::Node(int data) : data(data), nextPrime(NULL), prevPrime(NULL), isPrime(checkIsPrime()), prev(NULL), next(NULL)
{
}

int Node::getData() { return data; }
bool Node::getIsPrime() { return isPrime; }
void Node::setNextPrime(Node *node)
{
    nextPrime = node;
}
void Node::setPrevPrime(Node *node)
{
    prevPrime = node;
}
Node *Node::getNextPrime()
{
    return nextPrime;
}
Node *Node::getPrevPrime()
{
    return prevPrime;
}
bool Node::operator==(const Node &other) const
{
    return other.data == data;
}

void Node::setNext(Node *node)
{
    next = node;
}
void Node::setPrev(Node *node)
{
    prev = node;
}
Node *Node::getNext()
{
    return next;
}
Node *Node::getPrev()
{
    return prev;
}

bool Node::checkIsPrime()
{
    if (data <= 1)
        return false;
    for (int i = 2; i * i <= data; i++)
        if (data % i == 0)
            return false;
    return true;
}