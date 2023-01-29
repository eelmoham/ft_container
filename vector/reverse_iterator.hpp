#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"
template <class Iterator>
class reverse_iterator
{
public:
    typedef Iterator iterator_type;
    typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
    typedef typename iterator_traits<Iterator>::value_type value_type;
    typedef typename iterator_traits<Iterator>::difference_type difference_type;
    typedef typename iterator_traits<Iterator>::pointer pointer;
    typedef typename iterator_traits<Iterator>::reference reference;

    reverse_iterator() : current() {}
    reverse_iterator(Iterator x) : current(x) {}
    explicit reverse_iterator(iterator_type it) : current(it) {}
    template <class Iter>
    reverse_iterator(const reverse_iterator<Iter> &rev_it) : current(rev_it.base()) {}
    iterator_type base() const { return current; }
    reference operator*() const
    {
        Iterator tmp = current;
        return *--tmp;
    }

private:
    Iterator current;
};

#endif