#pragma once

#include <algorithm>
#include <stdexcept>
#include <type_traits>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    static_assert(
        std::is_same<typename T::value_type, int>::value,
        "Container must hold interger"
    );

    auto it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Element not found");
    }
    return it;
}
