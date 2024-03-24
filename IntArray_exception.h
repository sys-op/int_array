#pragma once
#include <exception>

class bad_range : public std::exception {
public:
    bad_range(const int &range);
    virtual const char* what() const noexcept override {
        return "ОШИБКА! Некорректный индекс. Значение индекса лежит за пределами допустимого диапазона.";
    }
private:
    int _error_range {0};
};

class bad_length : public std::exception {
public:
    bad_length(const int &length);
    virtual const char* what() const noexcept override {
        return "ОШИБКА! Некорректная длина массива. Значение длины массива лежит за пределами допустимого диапазона.";
    }
private:
    int _error_length {0};
};