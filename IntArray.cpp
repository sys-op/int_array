#include "IntArray.h"
#include "IntArray_exception.h"
#include <iostream>
#include <algorithm>

IntArray::IntArray(const long long &length) {
    if (length < 0) {
        throw bad_length(length);
    }
    if (length > 0) {
        _data = new int[length];
        _length = length;
    }
}

IntArray::IntArray(IntArray &array) {
    this->rearrange(array.getLength());
    std::copy_n(array._data, _length, _data);
}

IntArray::~IntArray() {
    delete[] _data;
}

const void IntArray::copy(IntArray &array)
{
    this->rearrange(array.getLength());
    std::copy_n(array._data, this->_length, this->_data);
}

int &IntArray::operator[](const int &index)
{
    if (index >= 0 && index < this->_length) {
        return this->_data[index];
    }
    else {
        throw bad_range(index);
    }
}

IntArray &IntArray::operator=(IntArray &array)
{
    if (&array == this) {
        return *this;
    }

    this->rearrange(array.getLength());
    std::copy_n(array._data, this->_length, this->_data);

    return *this;
}

std::size_t IntArray::getLength()
{
    return this->_length;
}

const void IntArray::rearrange(const int &new_length)
{
    empty();

    if (new_length <= 0) {
        return;
    }

    this->_data = new int[new_length];
    this->_length = new_length;
}

const void IntArray::resize(const int &new_length)
{
    if (new_length == this->_length) {
        return;
    }

    if (new_length <= 0) {
        empty();
        return;
    }

    int *data = new int[new_length];
    if (this->_length > 0) {
        int elementsToCopy = (new_length > this->_length) ? this->_length : new_length;
        std::copy_n(this->_data, elementsToCopy, data);
    }

    delete[] this->_data;

    this->_data = data;
    this->_length = new_length;
}

const void IntArray::insert(const int &value, const int &index)
{
    if (index < 0 || index > this->_length) {
        throw bad_range(index);
    }

    int *data = new int[this->_length + 1];
    std::copy_n(this->_data, index, data);
    data[index] = value;
    std::copy_n(this->_data + index, this->_length - index, data + index + 1);

    delete[] this->_data;
    this->_data = data;
    ++_length;
}

const void IntArray::erase(const int &index)
{
    if (index < 0 || index > this->_length) {
        throw bad_range(index);
    }

    if (this->_length == 1) {
        empty();
        return;
    }

    int *data = new int[this->_length - 1];
    std::copy_n(this->_data, index, data);
    std::copy_n(this->_data + index + 1, this->_length - index - 1, data + index);

    delete[] this->_data;
    this->_data = data;
    --_length;
}

const void IntArray::empty()
{
    delete[] this->_data;
    this->_data = nullptr;
    this->_length = 0;
}

const void IntArray::push_front(const int &value)
{
    insert(value, 0);
}

const void IntArray::push_back(const int &value)
{
    insert(value, this->_length);
}

const int IntArray::find(const int &value)
{
    for(std::size_t i = 0; i < this->_length; ++i) {
        if (this->_data[i] == value) {
            return i;
        }
    }

    return -1;
}
