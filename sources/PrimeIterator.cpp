#include "MagicalContainer.hpp"

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : Iterator(other.getContainer(), other.getCurr(), other.getType())
{
}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container) : Iterator(container, container.getFirstPrime(), PRIME)
{
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator ::operator++()
{
    if (!getCurr())
        throw runtime_error("Iterator has aleady ended");

    setCurr(getCurr()->getNextPrime());
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
{
    return PrimeIterator(getContainer());
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
{
    PrimeIterator iter(getContainer());
    iter.setCurr(NULL);
    return iter;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this != &other)
        throw runtime_error("cannot assign from an iterator a different container");
    if (getType() != other.getType())
        throw runtime_error("cannot assign from a different iterator type");
    setCurr(other.getCurr());
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept
{
    if (this == &other)
        return *this;
    if (&getContainer() == &other.getContainer())
        setCurr(other.getCurr());
    return *this;
}
