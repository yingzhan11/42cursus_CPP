#pragma once

#include <iostream>

template <typename T>
void	swap(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T&	min(const T& a, const T& b){
    static_assert(
        std::is_convertible<decltype(std::declval<T>() < std::declval<T>()), bool>::value,
        "Type T must support operator<"
    );
	return (a < b ? a : b);
}

template <typename T>
const T&	max(const T& a, const T& b){
    static_assert(
        std::is_convertible<decltype(std::declval<T>() > std::declval<T>()), bool>::value,
        "Type T must support operator>"
    );
	return (a > b ? a : b);
}
