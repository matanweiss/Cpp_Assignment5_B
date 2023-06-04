#include "MagicalContainer.hpp"

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : Iterator(other.getContainer(), other.getCurr(), other.getType())
{
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container) : Iterator(container, container.getHead(), CROSS), last(container.getTail()), count(0)
{
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator ::operator++()
{
    if (!getCurr())
        throw runtime_error("Iterator has aleady ended");
    if (count == getContainer().size() - 1)
    {
        last = NULL;
        setCurr(NULL);
        return *this;
    }
    if (count % 2 == 0)
        setCurr(getCurr()->getNext());
    else
        last = last->getPrev();
    count++;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
{
    return SideCrossIterator(getContainer());
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
{
    SideCrossIterator iter(getContainer());
    iter.setCurr(NULL);
    return iter;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this != &other)
        throw runtime_error("cannot assign from an iterator a different container");
    if (getType() != other.getType())
        throw runtime_error("cannot assign from a different iterator type");
    setCurr(other.getCurr());
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*()
{
    if (count % 2 == 0)
    {
        if (!getCurr())
            throw runtime_error("Element is NULL");
        return getCurr()->getData();
    }
    else
    {
        if (!last)
            throw runtime_error("Element is NULL");
        return last->getData();
    }
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    if (other.getType() != CROSS)
        throw runtime_error("cannot compare iterator from a different type");
    return count < other.count;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator ::operator=(SideCrossIterator &&other) noexcept
{
    if (this == &other)
        return *this;
    if (&getContainer() == &other.getContainer())
        setCurr(other.getCurr());
    return *this;
}
