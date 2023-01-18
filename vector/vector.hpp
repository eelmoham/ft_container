#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector
{
    private:
        T *data;
        size_t _size;
        size_t _capacity;
        std::allocator<T> alloc;
    public:
        Vector():_size(0), _capacity(0){std::cout<< "Vector" << std::endl;}

        Vector(size_t n):_size(n), _capacity(0)
        {
            this->data = alloc.allocate(n);//throw exception
            for (size_t i = 0; i < this->size; i++)
                this->alloc.construct(this->data + i, )
            
        }

        Vector(size_t n, const T &val):_size(n), _capacity(n)
        {
            this->data = new(std::nothrow) T[n];
            for(size_t i = 0; i < n; i++)
                this->data[i] = val;
        }

        Vector(const Vector &cpy)
        {
            this->_size = cpy.size();
            this->_capacity = cpy.capacity();
            this->data = alloc.allocate(cpy.size());//throw exception
            for(size_t i = 0; i < this->_size; i++)
                this->data[i] = cpy[i];
        }
        
        ~Vector()
        {
            // std::cout << "done" << std::endl;
            if (this->data != nullptr)
                this->alloc.deallocate(this->data, this->size());
        }
        
        Vector &operator=(const Vector &rhs)
        {
            this->_size = rhs.size();
            this->_capacity = rhs.capacity();
            if (this->data)
                this->alloc.deallocate(this->data, this->size());
            this->data = alloc.allocate(rhs.size());//throw exception
            for(size_t i = 0; i < this->_size; i++)
                this->data[i] = rhs[i];
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
        T *begin()
        {
            if (this->_size)
            {
                std::iterator<std::random_access_iterator_tag, T> *it;
                it = this->data;
                return it;
            }
            else
                throw std::exception();
        }
        const T *begin() const
        {
            if (this->_size)
            {
                std::iterator<std::random_access_iterator_tag, T> *it;
                it = this->data;
                return it;
            }
            else
                throw std::exception();
        }
        
        T *end()
        {
            if (this->_size)
            {
                std::iterator<std::random_access_iterator_tag, T> *it;
                it = this->data;
                it+=this->_size;
                return it;
            }
            else
                throw std::exception();
        }
        const T *cend() const
        {
            if (this->_size)
            {
                std::iterator<std::random_access_iterator_tag, T> *it;
                it = this->data;
                it+=this->_size;
                return it;
                return it;
            }
            else
                throw std::exception();
        }

        // // Capacity
        bool empty() const
        {
            if(this->_size)
                return false;
            else
                return true;
        }

        size_t size() const{
            return this->_size;
        }

        size_t capacity() const{
            return this->_capacity;
        }

        void reserve(size_t n)
        {
            
        }

        // void shrink_to_fit();

        // // Modifiers
        // void clear();
        // void insert(size_t i, const T &val);
        // void erase(size_t i);
        // void push_back(const T &val);
        // void pop_back();
        // void resize(size_t n);
        // void resize(size_t n, const T &val);


        // class badAlloc() : public std::exception
        // {
        //     public:
    	// 	    virtual const char* what() const throw()
        //         {
        //             std::cout << "bad allocation" << std::endl;
        //         }
        // }

        // class out_of_range : public std::exception
        // {
        //     public:
    	// 	    virtual const char* what() const throw()
        //         {
        //             std::cout << "out of range" << std::endl;
        //         }
        // }

        // class empty_Vector() : public std::exception
        // {
        //     public:
    	// 	    virtual const char* what() const throw()
        //         {
        //             std::cout << "Vector is empty" << std::endl;
        //         }
        // }
};

#endif
