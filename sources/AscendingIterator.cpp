#include "MagicalContainer.hpp"

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container) : Iterator(container, container.getHead(), ASCENDING)
{
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : Iterator(other.getContainer(), other.getCurr(), other.getType())
{
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this != &other)
        throw runtime_error("cannot assign from an iterator a different container");
    setCurr(other.getCurr());
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (!getCurr())
        throw runtime_error("Iterator has aleady ended");

    setCurr(getCurr()->getNext());
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
{
    return AscendingIterator(getContainer());
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
{
    AscendingIterator iter(getContainer());
    iter.setCurr(NULL);
    return iter;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept
{
    if (this == &other)
        return *this;
    if (&getContainer() == &other.getContainer())
        setCurr(other.getCurr());
    return *this;
}
