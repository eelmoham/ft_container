#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include "iterator.hpp"

namespace ft {
    template <class Iterator>
class iterator_traits
{
public:
    typedef typename ft::iterator<Iterator>::value_type value_type;
    typedef typename ft::iterator<Iterator>::difference_type difference_type;
    typedef typename ft::iterator<Iterator>::pointer pointer;
    typedef typename ft::iterator<Iterator>::reference reference;
    typedef typename ft::iterator<Iterator>::iterator_category iterator_category;
};

template <class T>
class iterator_traits<T *>
{
public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &reference;
    // typedef random_access_iterator_tag iterator_category;
};

template <class T>
class iterator_traits<const T *>
{
public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T *pointer;
    typedef const T &reference;
    // typedef random_access_iterator_tag iterator_category;
};
};

#endif