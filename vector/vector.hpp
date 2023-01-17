#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class vector
{
    private:
        T *data;
        size_t size;
        size_t capacity;

    public:
        vector():size(0), capacity(0){}
        vector(size_t n):size(n), capacity(0)
        {
            this->data = new(std::nothrow) data[n];
            if (!this->data)
                throw badAlloc();
        }
        vector(size_t n, const T &val):size(n), capacity(n)
        {
            this->data = new(std::nothrow) data[n];
            if (!this->data)
                throw badAlloc();
            for (size_t i = 0; i < n: i++)
                this->data[i] = val;
        }
        vector(const vector &cpy)
        {
            this->size = cpy.size();
            this->capacity = cpy.capacity();
            for(size_t i = 0; i < this->size(); i++)
                this->data[i] = cpy[i];
        }
        ~vector()
        {
            if (this->data != nullptr)
                delete[] this->data
        }
        
        T &operator=(const vector &rhs)
        {
            this->size = rhs.size();
            this->capacity = rhs.capacity();
            for(size_t i = 0; i < this->size(); i++)
                this->data[i] = rhs[i];
            return (*this);
        }

        T &operator[](size_t index)
        {
            if (index < 0 || index > this->size)
                throw out_of_range();
            else
                return this->data[index];
        }
        
        const T &operator[](size_t i) const
        {
            if (index < 0 || index > this->size)
                throw out_of_range();
            else
                return this->data[index];
        }
        
        T &at(size_t index)
        {
            if (index < 0 || index > this->size)
                throw out_of_range();
            else
                return this->data[i];
        }

        const T &at(size_t i) const
        {
            if (index < 0 || index > this->size)
                throw out_of_range();
            else
                return this->data[i];
        }

        T &front()
        {
            if (this->size() < 1)
                throw out_of_range();
            return this->data[0];
        }

        const T &front() const
        {
            if (this->size() < 1)
                throw out_of_range();
            return this->data[0];
        }
        T &back()
        {
            if (this->data[this->size - 1])
                return this->data[this->size - 1]
            else
                throw out_of_range();
        }
        const T &back() const
        {
            if (this->data[this->size - 1])
                return this->data[this->size - 1]
            else
                throw out_of_range();
        }

        // // Iterators
        T *begin()
        {
            if (this->size())
            {
                std::iterator<std::random_access_iterator_tag, T> *it;
                it = this->data;
                return it;
            }
            else
                throw empty_vector();
        }
        const T *begin() const
        {
            if (this->size())
            {
                std::iterator<std::random_access_iterator_tag, T> *it;
                it = this->data;
                return it;
            }
            else
                throw empty_vector();
        }
        
        T *end()
        {
            if (this->size())
            {
                std::iterator<std::random_access_iterator_tag, T> *it;
                it = this->data;
                it+=this->size();
                return it;
            }
            else
                throw empty_vector();
        }
        const T *cend() const
        {
            if (this->size())
            {
                std::iterator<std::random_access_iterator_tag, T> *it;
                it = this->data;
                it+=this->size();
                return it;
                return it;
            }
            else
                throw empty_vector();
        }

        // // Capacity
        bool empty() const
        {
            if(this->size())
                return false;
            else
                true;
        }
        size_t size() const{
            return this->size;
        }
        size_t capacity() const{
            return this->capacity;
        }
        void reserve(size_t n);
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


        class badAlloc() : public std::exception
        {
            public:
    		    virtual const char* what() const throw()
                {
                    std::cout << "bad allocation" << std::endl;
                }
        }

        class out_of_range() : public std::exception
        {
            public:
    		    virtual const char* what() const throw()
                {
                    std::cout << "out of range" << std::endl;
                }
        }

        class empty_vector() : public std::exception
        {
            public:
    		    virtual const char* what() const throw()
                {
                    std::cout << "vector is empty" << std::endl;
                }
        }
};

#endif