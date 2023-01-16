#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T>
class vector
{
    T *data;
    size_t size;
    size_t capacity;

public:
    // Constructors and destructor
    vector();
    vector(size_t n);
    vector(size_t n, const T &val);
    vector(const vector &other);
    ~vector();

    // Element access
    T &operator[](size_t i);
    const T &operator[](size_t i) const;
    T &at(size_t i);
    const T &at(size_t i) const;
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;

    // Iterators
    T *begin();
    const T *begin() const;
    T *end();
    const T *end() const;

    // Capacity
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t n);
    void shrink_to_fit();

    // Modifiers
    void clear();
    void insert(size_t i, const T &val);
    void erase(size_t i);
    void push_back(const T &val);
    void pop_back();
    void resize(size_t n);
    void resize(size_t n, const T &val);
};

#endif