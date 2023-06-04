#pragma once
#include <iostream>

using namespace std;

class Node
{
    int data;
    bool isPrime;
    Node* next;
    Node* prev;
    Node* nextPrime;
    Node* prevPrime;
    bool checkIsPrime();
public:
    Node(int data);
    int getData();
    bool getIsPrime();
    void setNext(Node* node);
    void setPrev(Node* node);
    Node* getNext();
    Node* getPrev();
    void setNextPrime(Node* node);
    void setPrevPrime(Node* node);
    Node* getNextPrime();
    Node* getPrevPrime();
    bool operator==(const Node& other) const;
};