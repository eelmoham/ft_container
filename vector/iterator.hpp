#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
    template <typename T>
    class iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    public:
        typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;

        iterator()
        {
            this->vec_ = NULL;
            this->index_ = 0;
        }
        iterator(value_type *vec, int index) : vec_(vec), index_(index) {}

        iterator &operator++()
        {
            ++index_;
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp(*this);
            ++*this;
            return tmp;
        }

        iterator &operator--()
        {
            --index_;
            return *this;
        }

        iterator operator--(int)
        {
            iterator tmp(*this);
            --*this;
            return tmp;
        }

        iterator operator+(difference_type n)
        {
            iterator tmp(*this);
            tmp.index_ += n;
            return tmp;
        }

        iterator operator-(difference_type n)
        {
            iterator tmp(*this);
            tmp.index_ -= n;
            return tmp;
        }

        iterator &operator+=(difference_type n)
        {
            index_ += n;
            return *this;
        }

        iterator &operator-=(difference_type n)
        {
            index_ -= n;
            return *this;
        }

        reference operator*()
        {
            return vec_[index_];
        }

        pointer operator->()
        {
            return &vec_[index_];
        }

        bool operator==(const iterator &other) const
        {
            return index_ == other.index_;
        }

        bool operator!=(const iterator &other) const
        {
            return index_ != other.index_;
        }

        bool operator<(const iterator &other) const
        {
            return index_ < other.index_;
        }

        bool operator>(const iterator &other) const
        {
            return index_ > other.index_;
        }

        bool operator<=(const iterator &other) const
        {
            return index_ <= other.index_;
        }

        bool operator>=(const iterator &other) const
        {
            return index_ >= other.index_;
        }

    private:
        value_type *vec_;
        int index_;
    };
}

#endif
