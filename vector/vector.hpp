#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "iterator.hpp"

namespace ft
{
    template <class T>
    class vector
    {
    public:
        typedef ft::iterator<T> iterator;
        typedef T value_type;
        typedef size_t size_type;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef T &reference;
        typedef const T &const_reference;

        vector() : _size(0), _capacity(0)
        {
            // this->data = NULL;
        }

        vector(size_type n) : _size(n), _capacity(n)
        {
            this->data = alloc.allocate(n); // throw exception
            for (size_type i = 0; i < this->_size; i++)
                this->alloc.construct(this->data + i, T());
        }

        vector(size_type n, const T &val) : _size(n), _capacity(n)
        {
            this->data = alloc.allocate(n); // throw exception
            for (size_type i = 0; i < this->_size; i++)
                this->alloc.construct(this->data + i, val);
        }

        vector(const vector &cpy)
        {
            this->_size = cpy.size();
            this->_capacity = cpy.capacity();
            this->data = alloc.allocate(cpy.size()); // throw exception
            for (size_type i = 0; i < this->_size; i++)
                this->alloc.construct(this->data + i, this->end());
            for (size_type i = 0; i < this->_size; i++)
                this->alloc.construct(this->data + i, cpy[i]);
        }

        ~vector()
        {
            // std::cout << "done" << std::endl;
            if (this->data != nullptr)
                this->alloc.deallocate(this->data, this->size());
        }

        vector &operator=(const vector &rhs)
        {
            this->_size = rhs.size();
            this->_capacity = rhs.capacity();
            if (this->data)
                this->alloc.deallocate(this->data, this->size());
            this->data = alloc.allocate(rhs.size()); // throw exception
            for (size_type i = 0; i < this->_size; i++)
                this->alloc.construct(this->data + i, rhs[i]);
            return (*this);
        }

        reference operator[](size_type index)
        {
            if (index < 0 || index > this->_size)
                throw std::exception();
            else
                return this->data[index];
        }

        const_reference operator[](size_type index) const
        {
            if (index < 0 || index > this->_size)
                throw std::exception();
            else
                return this->data[index];
        }

        reference at(size_type index)
        {
            if (index < 0 || index > this->_size)
                throw std::exception();
            else
                return this->data[index];
        }

        const_reference at(size_t index) const
        {
            if (index < 0 || index > this->_size)
                throw std::exception();
            else
                return this->data[index];
        }

        const_reference front()
        {
            if (this->size() < 1)
                throw std::exception();
            return this->data[0];
        }

        const_reference front() const
        {
            if (this->size() < 1)
                throw std::exception();
            return this->data[0];
        }

        reference back()
        {
            if (this->data[this->_size - 1])
                return this->data[this->_size - 1];
            else
                throw std::exception();
        }

        const_reference back() const
        {
            if (this->data[this->_size - 1])
                return this->data[this->_size - 1];
            else
                throw std::exception();
        }

        iterator begin()
        {
            if (this->_size)
                return iterator(this->data, 0);
            else
                throw std::exception();
        }
        const iterator begin() const
        {
            if (this->_size)
                return iterator(this->data, 0);
            else
                throw std::exception();
        }

        iterator end()
        {
            if (this->_size)
                return iterator(this->data, this->_size);
            else
                throw std::exception();
        }

        const iterator end() const
        {
            if (this->_size)
                return iterator(this->data, this->_size);
            else
                throw std::exception();
        }

        // // Capacity
        bool empty() const
        {
            if (this->_size)
                return false;
            else
                return true;
        }

        size_type size() const
        {
            return this->_size;
        }

        size_type capacity() const
        {
            return this->_capacity;
        }

        void reserve(size_type n)
        {
            if (this->_size == 0 && this->_capacity == 0)
            {
                this->data = alloc.allocate(n);
                this->_capacity = n;
            }
            else if (n < this->_size)
            {
                for (size_type i = n; i < this->_capacity; i++)
                    this->alloc.destroy(this->data + i);
            }
            else
            {
                pointer tmp = this->alloc.allocate(n);
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->alloc.construct(tmp + i, this->data[i]);
                    this->alloc.destroy(this->data + i);
                }
                this->alloc.deallocate(this->data, this->size());
                this->data = this->alloc.allocate(n);
                for (size_type i = 0; i < n; i++)
                {
                    this->alloc.construct(this->data + i, tmp[i]);
                    this->alloc.destroy(tmp + i);
                }
                this->alloc.deallocate(tmp, n);
            }
        }

        void shrink_to_fit()
        {
            if (this->_capacity > this->_size)
            {
                for (size_type i = this->_size; i < this->_capacity; i++)
                    this->alloc.destroy(this->data + i);
            }
            this->_capacity = this->_size;
        }

        // // Modifiers
        void clear()
        {
            for (size_type i = 0; i < this->_size; i++)
                this->alloc.destroy(this->data + i);
            this->_size = 0;
        }

        iterator insert(iterator position, const value_type &val)
        {
            pointer tmp = this->alloc.allocate(_size);
            for (size_t i = 0; i < this->_size; i++)
            {
                this->alloc.construct(tmp + i, this->data[i]);
                this->alloc.destroy(this->data + i);
            }
            this->alloc.deallocate(this->data, _size);
            this->_size += 1;
            if (this->_size > this->_capacity)
                this->_capacity *= 2;
            this->data = this->alloc.allocate(_size);
            int index = 0;
            for (iterator i = this->begin(); i != this->end(); ++i)
            {
                if (position == i)
                    *i = val;
                else
                {
                    *i = tmp[index];
                    index++;
                    this->alloc.destroy(tmp + index);
                }
            }
            this->alloc.deallocate(tmp, _size - 1);
            return position;
        }

        void insert(iterator position, size_type n, const value_type &val)
        {
            pointer tmp = this->alloc.allocate(_size);
            for (size_t i = 0; i < this->_size; i++)
            {
                this->alloc.construct(tmp + i, this->data[i]);
                this->alloc.destroy(this->data + i);
            }
            this->alloc.deallocate(this->data, _size);
            this->_size += n;
            if (this->_size > this->_capacity)
                this->_capacity *= 2;
            this->data = this->alloc.allocate(_size);
            int index = 0;
            for (iterator i = this->begin(); i != this->end(); ++i)
            {
                if (position == i)
                {
                    for (size_t j = 0; j < n; j++)
                    {
                        *i = val;
                        if (j < n - 1)
                            ++i;
                    }
                    continue;
                }
                else
                {
                    *i = tmp[index];
                    index++;
                    this->alloc.destroy(tmp + index);
                }
            }
            this->alloc.deallocate(tmp, _size - n);
        }

        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last)
        {
            InputIterator c = first;
            size_type counter = 0;
            while (c++ != last)
                counter++;
            pointer tmp = alloc.allocate(this->_size + counter);
            int index = 0;
            for (iterator it = this->begin(); it != position; ++it)
            {
                this->alloc.construct(tmp + index, *it);
                index++;
            }
            for (InputIterator it = first; it != last; ++it)
            {
                this->alloc.construct(tmp + index, *it);
                index++;
            }
            for (iterator it = position; it != this->end(); ++it)
            {
                this->alloc.construct(tmp + index, *it);
                index++;
            }
            this->alloc.deallocate(this->data, this->_size);
            this->_size += counter;
            this->data = this->alloc.allocate(_size);
            if (this->_size > this->_capacity)
                this->_capacity *= 2;
            for (size_type i = 0; i < this->_size; i++)
                this->alloc.construct(this->data + i, tmp[i]);
            this->alloc.deallocate(tmp, _size);
        }

        void push_back(const value_type &val)
        {
            this->reserve(this->_size + 1);
            this->alloc.construct(this->data + this->_size, val);
            this->_size++;
            if (this->_size > this->_capacity)
                this->_capacity *= 2;
        }
        void pop_back()
        {
            pointer tmp = this->alloc.allocate(_size);
            for (size_type i = 0; i < this->_size; i++)
            {
                this->alloc.construct(tmp + i, this->data[i]);
                this->alloc.destroy(this->data + i);
            }
            this->alloc.deallocate(this->data, this->_size);
            _size--;
            this->data = this->alloc.allocate(this->_size);
            for (size_type i = 0; i < this->_size; i++)
            {
                this->alloc.construct(this->data + i, tmp[i]);
                this->alloc.destroy(tmp + i);
            }
            this->alloc.deallocate(tmp, _size + 1);
        }

        void resize(size_type n, value_type val = value_type())
        {
            if (n < this->_size)
            {
                reserve(n);
                this->_size = n;
            }
            else if (n == this->_size)
                return;
            else
            {
                size_type sz = this->_size;
                reserve(n);
                this->_size = n;
                for (size_type i = sz; i < this->_size; i++)
                {
                    this->alloc.destroy(data + i);
                    this->alloc.construct(data + i, val);
                }
            }
        }
        iterator erase(iterator pos)
        {
            for (iterator i = this->begin(); i != this->end(); ++i)
            {
                if (i == pos)
                {
                    while (i != this->end())
                        i = ++i;
                    this->pop_back();
                    break;
                }
            }
            return pos;
        }
        iterator erase(iterator first, iterator last)
        {
            iterator it = first;
            size_type count = 0;
            while (++it)
                count++;
            pointer tmp = this->alloc.allocate(this->_size - count);
            size_type index = 0;
            iterator it;
            for (it = this->begin(); it != first; ++it)
            {
                this->alloc.construct(tmp + index, *it);
                index++;
            }
            while (++it != last);
            for (it != end(); ++it)
            {
                this->alloc.construct(tmp + index, *it);
                index++;
            }
        }

    private:
        value_type *data;
        size_type _size;
        size_type _capacity;
        std::allocator<T> alloc;
    };
};

#endif

/*
vector( size_type count, const T& value, const Allocator& alloc = Allocator());

template< class InputIt >
vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );

vector( const vector& other, const Allocator& alloc );

vector( vector&& other );

vector( vector&& other, const Allocator& alloc );

vector( std::initializer_list<T> init, const Allocator& alloc = Allocator() );
*/

/*

Here is a list of some of the member functions that are typically declared in the C++ STL vector class:

vector() : constructor, creates an empty vector
vector(size_type n) : constructor, creates a vector with n elements
vector(size_type n, const value_type& val) : constructor, creates a vector with n elements, all elements are initialized with val
vector(InputIterator first, InputIterator last) : constructor, creates a vector with the elements in the range [first, last)
~vector() : destructor, frees the memory used by the vector
iterator begin() : returns an iterator pointing to the first element of the vector
iterator end() : returns an iterator pointing to the one past the last element of the vector
size_type size() : returns the number of elements in the vector
size_type max_size() : returns the maximum number of elements that the vector can hold
void resize(size_type n) : resizes the vector to have n elements
void resize(size_type n, const value_type& val) : resizes the vector to have n elements, new elements are initialized with val
void reserve(size_type n) : reserves space for n elements, but does not change the size of the vector
void push_back(const value_type& val) : adds a new element to the end of the vector
void pop_back() : removes the last element from the vector
reference operator[](size_type i) : returns a reference to the i-th element of the vector
reference at(size_type i) : returns a reference to the i-th element of the vector, throws an exception if i is out of range
void clear() : removes all elements from the vector
bool empty() : returns true if the vector is empty, false otherwise
void swap(vector<value_type>& v) : swaps the contents of the vector with the contents of v
Note that this is not an exhaustive list of all functions that may be declared in a vector class, as some implementations may have more or less functions. Additionally, the function signature may change based on the specific implementation of vector.

*/