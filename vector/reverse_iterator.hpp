#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"
#include "iterator.hpp"
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
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : current(rev_it.base()) {}
        iterator_type base() const { return this->current; }
        reference operator*() const
        {
            Iterator tmp = current;
            return *(tmp - 1);
        }
        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator(current - n);
        }
        reverse_iterator operator-(difference_type n) const
        {
            return reverse_iterator(current + n);
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator temp(*this);
            this->current -= 1;
            return temp;
        }

        reverse_iterator operator++()
        {
            current -= 1;
            return *this;
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator temp(*this);
            this->current += 1;
            return temp;
        }

        reverse_iterator operator--()
        {
            current += 1;
            return *this;
        }

        reverse_iterator& operator+= (difference_type n)
        {
            this->current -= n;
            return (*this);
        }

        reverse_iterator& operator-= (difference_type n)
        {
            this->current += n;
            return (*this);
        }

        pointer operator->() const
        {
            return &*current;
        }

        reference operator[](difference_type n)) const
        {
            return
        }
    private:
        Iterator current;
    };
    
    //this claas implemented basic this standard lirary by ligacy version  (c++98)
}
#endif