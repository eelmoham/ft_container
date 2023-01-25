#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "iterator.hpp"

namespace ft
{
    template <class T>
    class vector
    {
    private:
        T *data;
        size_t _size;
        size_t _capacity;
        std::allocator<T> alloc;

    public:
        typedef ft::iterator<T> VectorIterator;
        vector() : _size(0), _capacity(0)
        {
            // this->data = NULL;
        }

        vector(size_t n) : _size(n), _capacity(n)
        {
            this->data = alloc.allocate(n); // throw exception
            for (size_t i = 0; i < this->_size; i++)
                this->alloc.construct(this->data + i, T());
        }

        vector(size_t n, const T &val) : _size(n), _capacity(n)
        {
            this->data = alloc.allocate(n); // throw exception
            for (size_t i = 0; i < this->_size; i++)
                this->alloc.construct(this->data + i, val);
        }

        vector(const vector &cpy)
        {
            this->_size = cpy.size();
            this->_capacity = cpy.capacity();
            this->data = alloc.allocate(cpy.size()); // throw exception
            for (size_t i = 0; i < this->_size; i++)
                this->alloc.construct(this->data + i, this->end());
            for (size_t i = 0; i < this->_size; i++)
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
            for (size_t i = 0; i < this->_size; i++)
                this->alloc.construct(this->data + i, rhs[i]);
            return (*this);
        }

        T &operator[](size_t index)
        {
            if (index < 0 || index > this->_size)
                throw std::exception();
            else
                return this->data[index];
        }

        const T &operator[](size_t index) const
        {
            if (index < 0 || index > this->_size)
                throw std::exception();
            else
                return this->data[index];
        }

        T &at(size_t index)
        {
            if (index < 0 || index > this->_size)
                throw std::exception();
            else
                return this->data[index];
        }

        const T &at(size_t index) const
        {
            if (index < 0 || index > this->_size)
                throw std::exception();
            else
                return this->data[index];
        }

        T &front()
        {
            if (this->size() < 1)
                throw std::exception();
            return this->data[0];
        }

        const T &front() const
        {
            if (this->size() < 1)
                throw std::exception();
            return this->data[0];
        }
        T &back()
        {
            if (this->data[this->_size - 1])
                return this->data[this->_size - 1];
            else
                throw std::exception();
        }
        const T &back() const
        {
            if (this->data[this->_size - 1])
                return this->data[this->_size - 1];
            else
                throw std::exception();
        }

        // // Iterators
        VectorIterator begin()
        {
            if (this->_size)
                return VectorIterator(this->data, 0);
            else
                throw std::exception();
        }
        const VectorIterator cbegin()
        {
            if (this->_size)
                return VectorIterator(this->data, 0);
            else
                throw std::exception();
        }

        VectorIterator end()
        {
            if (this->_size)
                return VectorIterator(this->data, this->_size);
            else
                throw std::exception();
        }

        const VectorIterator cend()
        {
            if (this->_size)
                return VectorIterator(this->data, this->_size);
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

        size_t size() const
        {
            return this->_size;
        }

        size_t capacity() const
        {
            return this->_capacity;
        }

        void reserve(size_t n)
        {
            if (this->_size == 0 && this->_capacity == 0)
            {
                this->data = alloc.allocate(n);
                this->_capacity = n;
            }
            else if (n < this->_size)
            {
                for (size_t i = n; i < this->_capacity; i++)
                    this->alloc.destroy(this->data + i);
            }
            else
            {
                T *tmp = this->alloc.allocate(n);
                for (size_t i = 0; i < this->_size; i++)
                {
                    this->alloc.construct(tmp + i, this->data[i]);
                    this->alloc.destroy(this->data + i);
                }
                this->alloc.deallocate(this->data, this->size());
                this->data = this->alloc.allocate(n);
                for (size_t i = 0; i < n; i++)
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
                for (size_t i = this->_size; i < this->_capacity; i++)
                    this->alloc.destroy(this->data + i);
            }
            this->_capacity = this->_size;
        }

        // // Modifiers
        void clear()
        {
            for (size_t i = 0; i < this->_size; i++)
                this->alloc.destroy(this->data + i);
            this->_size = 0;
        }

        void insert(VectorIterator it, const T &val)
        {
            std::cout << this->_size << " * " << this->_capacity << std::endl;
            T *tmp = this->alloc.allocate(_size);
            for (size_t i = 0; i < this->_size; i++)
            {
                this->alloc.construct(tmp + i, this->data[i]);
                this->alloc.destroy(this->data + i);
            }
            int index = 0;
            for (VectorIterator i = this->begin();i != this->end() ;++i)
            {
                if (it == i)
                {
                    this->push_back(tmp[index]);
                    ++it;
                    it = val;
                }
                else
                {
                    this->push_back(tmp[index]);
                    index++;
                }
            }
        }
        // void erase(size_t i);
        void push_back(const T &val)
        {
            this->reserve(this->_size + 1);
            this->alloc.construct(this->data + this->_size, val);
            this->_size++;
            if (this->_size > this->_capacity)
                this->_capacity *= 2;
        }
        // void pop_back();
        // void resize(size_t n);
        // void resize(size_t n, const T &val);
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
