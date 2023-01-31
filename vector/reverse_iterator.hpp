#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"
namespace ft
{

    template <class Iterator>
    class reverse_iterator
    {
    public:
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename ft::iterator_traits<Iterator>::reference reference;

        reverse_iterator() : current() {}
        explicit reverse_iterator(iterator_type it) : current(it) {}
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter>& rev_it) : current(rev_it.base()) {}
        iterator_type base() const { return this->current; }
        typename std::iterator_traits<Iterator>::value_type operator*() const
        {
            Iterator tmp = current;
            return *--tmp;
        }
        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator(current - n);
        }
    private:
        Iterator current;
    };
}
#endif