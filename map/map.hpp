#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>

namespace ft
{
    template <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key, T>>>
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const Key, T> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;

    private:
        struct Node
        {
            value_type value;
            Node *left, *right;
            Node(const value_type &v) : value(v), left(nullptr), right(nullptr) {}
        };

        Node *root;
        allocator_type alloc;
        key_compare cmp;
        size_t size 
    public:
        
    }
}

#endif