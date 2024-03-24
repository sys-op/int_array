#pragma once
#include <cstddef>

class IntArray {
public:
    IntArray() = default;

    IntArray(const long long &length);
    IntArray(IntArray &array);

    ~IntArray();

    const void copy(IntArray &array);
    const void rearrange(const int &new_length);
    const void resize(const int &new_length);
    const void insert(const int &value, const int &index);
    const void erase(const int &index);
    const void empty();

    const void push_front(const int &value);
    const void push_back(const int &value);
    const int find(const int &value);

    int& operator[](const int &index);
    IntArray &operator=(IntArray &array);

    std::size_t getLength();

private:
    std::size_t _length {0};
    int *_data {nullptr};
};