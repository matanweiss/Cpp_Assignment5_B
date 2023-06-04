#pragma once
#include "Node.hpp"

constexpr int ASCENDING = 1;
constexpr int CROSS = 2;
constexpr int PRIME = 3;

namespace ariel
{
};

class MagicalContainer
{
    size_t listSize;
    Node *head;
    Node *tail;
    Node *firstPrime;
    void addToPrimesList(Node *newNode, Node *lastPrime);
    void addToList(Node *newNode, Node *lastNode);
    void removeFromPrimesList(Node *curr);
    void removeFromList(Node *curr);

public:
    class Iterator;
    class AscendingIterator;
    class PrimeIterator;
    class SideCrossIterator;
    MagicalContainer();
    void addElement(int data);
    void addPrimeElement(Node *newNode);
    void addNonPrimeElement(Node *newNode);
    void removeElement(int data);
    void printList();
    void printListAddresses();
    void printPrimes();
    size_t size() const;
    Node *getFirstPrime() const;
    Node *getHead() const;
    Node *getTail() const;
    ~MagicalContainer();
    MagicalContainer(const MagicalContainer &other);
    MagicalContainer(MagicalContainer &&other) noexcept;
    MagicalContainer &operator=(MagicalContainer &&other) noexcept;
    MagicalContainer &operator=(const  MagicalContainer& other) ;
};

class MagicalContainer::Iterator
{
    Node *curr;
    const MagicalContainer &container;
    int type;

public:
    Iterator(const MagicalContainer &container, Node *curr, int type);
    virtual int operator*();
    Node *getCurr() const;
    const MagicalContainer &getContainer() const;
    void setCurr(Node *curr);
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
    virtual bool operator<(const Iterator &other) const;
    virtual bool operator>(const Iterator &other) const;
    int getType() const;
    virtual Iterator &operator++() = 0;
    virtual ~Iterator() = default;
    Iterator(const Iterator& other);
    Iterator& operator=(const Iterator& other);

    Iterator(Iterator&& other) noexcept;
    Iterator& operator=(Iterator&& other) noexcept;
};

class MagicalContainer::AscendingIterator : public MagicalContainer::Iterator
{
public:
    AscendingIterator(const MagicalContainer &container);
    AscendingIterator(const AscendingIterator &other);
    AscendingIterator &operator=(const AscendingIterator &other);
    AscendingIterator &operator++() override;
    AscendingIterator begin() const;
    AscendingIterator end() const;
    ~AscendingIterator() override = default;
    AscendingIterator(AscendingIterator &&other) noexcept = default;
    AscendingIterator &operator=(AscendingIterator &&other) noexcept;
};

class MagicalContainer::PrimeIterator : public MagicalContainer::Iterator
{
public:
    PrimeIterator(const MagicalContainer &container);
    PrimeIterator(const PrimeIterator &other);
    PrimeIterator &operator++() override;
    PrimeIterator begin() const;
    PrimeIterator end() const;
    PrimeIterator &operator=(const PrimeIterator &other);
    ~PrimeIterator() override = default;
    PrimeIterator(PrimeIterator &&other) noexcept = default;
    PrimeIterator &operator=(PrimeIterator &&other) noexcept;
};

class MagicalContainer::SideCrossIterator : public MagicalContainer::Iterator
{
    Node *last;
    int count;

public:
    SideCrossIterator(const MagicalContainer &container);
    SideCrossIterator(const SideCrossIterator &other);
    SideCrossIterator &operator++() override;
    SideCrossIterator begin() const;
    SideCrossIterator end() const;
    SideCrossIterator &operator=(const SideCrossIterator &other);
    ~SideCrossIterator() override = default;
    SideCrossIterator(SideCrossIterator &&other) noexcept = default;  // Move constructor
    SideCrossIterator &operator=(SideCrossIterator &&other) noexcept; // Move assignment operator
    int operator*() override;
    virtual bool operator<(const SideCrossIterator &other) const;
};
