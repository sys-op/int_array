#include "IntArray_exception.h"
#include <iostream>

bad_range::bad_range(const int &range) : _error_range {range} {
    std::cout << "Некорректное значение индекса: " << range << "\n";
}


bad_length::bad_length(const int &length) : _error_length {length} {
    std::cout << "Некорректное значение длины массива: " << length << "\n";
}
