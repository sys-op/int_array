#include <iostream>
#include "IntArray.h"

void print_array(IntArray &array) {
    for (std::size_t i = 0; i < array.getLength(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Домашнее задание модуля 7 Skillfactory курс Разработчик C++\n";
    
    IntArray a1(10);

    for (int i = 0; i < 10; ++i) {
        a1[i] = i + 1;
    }

    std::cout << "Массив a1: ";
    print_array(a1);

    int find_value = 9;
    int find_index = a1.find(find_value);
    if (find_index >=0 ) {
        std::cout << "Найден " << find_value << ", индекс в массиве: " << find_index << "\n";
    }
    find_value = 999;
    find_index = a1.find(find_value);
    if (find_index >=0 ) {
        std::cout << "Найден " << find_value << ", индекс в массиве: " << find_index << "\n";
    }
    else {
        std::cout << find_value << " не найден.\n";
    }

    a1.resize(8);
    a1.push_front(100);
    a1.push_back(200);

    a1.erase(4);

    IntArray a2(a1);
    IntArray a3 = a1;

    std::cout << "Массив a1: ";
    print_array(a1);


    std::cout << "Массив a2: ";
    print_array(a2);

    std::cout << "Массив a3: ";
    print_array(a2);

    try
    {
        std::cout << a1[-1];
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    
    try
    {
        a2.insert(0, 100);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    try
    {
        a3.erase(-1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    try
    {
        IntArray a4(-1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    return 0;
}