#pragma once

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

class Span {
    private:
        unsigned int _size;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int nbr);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned int shortestSpan();
        unsigned int longestSpan();

};