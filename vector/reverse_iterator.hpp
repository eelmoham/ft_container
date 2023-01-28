#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>

template <class Iterator> 
class reverse_iterator
{
    public:
        typedef Iterator iterator_type;
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        reverse_iterator(){this->current = NULL}
        reverse_iterator(Iterator x) : current(x) {}
    private:
        Iterator current;

};


#endif