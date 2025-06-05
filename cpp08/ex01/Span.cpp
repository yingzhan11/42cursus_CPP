/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:05:47 by yzhan             #+#    #+#             */
/*   Updated: 2025/06/05 14:05:49 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int N) : _size(N) {}

Span::Span(const Span &other) : _size(other._size), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _size = other._size;
        _numbers = other._numbers;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_numbers.size() >= _size)
        throw std::overflow_error("Error: span is full");
    _numbers.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if ((_numbers.size() + std::distance(begin, end)) > _size)
        throw std::overflow_error("Error: Too many numbers than the size of span");
    _numbers.insert(_numbers.end(), begin, end);
}

unsigned int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("No enought numbers to find a span");
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    unsigned int shortestSpan = std::numeric_limits<unsigned int >::max();
    for (size_t i = 1; i < sortedNumbers.size(); i++)
    {
        unsigned int tempSpan = static_cast<unsigned int>(sortedNumbers[i] - sortedNumbers[i - 1]);
        if (tempSpan < shortestSpan)
            shortestSpan = tempSpan;
    }
    return shortestSpan;
}

unsigned int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("No enought numbers to find a span");
    auto [min, max] = std::minmax_element(_numbers.begin(), _numbers.end());
    return (static_cast<unsigned int>(*max - *min));
}
