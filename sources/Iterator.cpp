#include "MagicalContainer.hpp"

MagicalContainer::Iterator::Iterator(const MagicalContainer &container, Node *curr, int type) : container(container), curr(curr), type(type)
{
}

int MagicalContainer::Iterator::operator*()
{
    if (!curr)
        throw runtime_error("Element is NULL");
    return curr->getData();
}

bool MagicalContainer::Iterator::operator==(const Iterator &other) const
{
    if (&container != &other.container)
        throw runtime_error("cannot compare Iterators with different containers");
    if (type != other.type)
        throw runtime_error("cannot compare Iterators with different type");
    int thisValue = 0;
    int otherValue = 0;
    if (curr)
        thisValue = curr->getData();
    if (other.curr)
        otherValue = other.curr->getData();
    return thisValue == otherValue;
}

bool MagicalContainer::Iterator::operator!=(const Iterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::Iterator::operator<(const Iterator &other) const
{
    if (curr == NULL && other.curr == NULL)
        return false;
    
    if (curr == NULL)
        return false;

    if (other.curr == NULL)
        return true;
    return curr->getData() < other.curr->getData();
}

bool MagicalContainer::Iterator::operator>(const Iterator &other) const
{
    return !(*this < other || *this == other);
}

Node *MagicalContainer::Iterator::getCurr() const
{
    return curr;
}

void MagicalContainer::Iterator::setCurr(Node *curr)
{
    this->curr = curr;
}

const MagicalContainer &MagicalContainer::Iterator::getContainer() const
{
    return container;
}

int MagicalContainer::Iterator::getType() const
{
    return type;
}

MagicalContainer::Iterator::Iterator(const Iterator &other) : container(other.container), type(other.type), curr(other.curr)
{
}

MagicalContainer::Iterator &MagicalContainer::Iterator::operator=(const Iterator &other)
{
    if (&container != &other.container)
        throw runtime_error("cannot assign from an Iterator of a different container");
    curr = other.curr;
    type = other.type;
    return *this;
}

MagicalContainer::Iterator::Iterator(Iterator &&other) noexcept : container(other.container), curr(other.curr), type(other.type)
{
}
MagicalContainer::Iterator &MagicalContainer::Iterator::operator=(Iterator &&other) noexcept
{
    if (&container != &other.container)
        return *this;
    curr = other.curr;
    type = other.type;
    return *this;
}
