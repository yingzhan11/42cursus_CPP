#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename Func>
void    iter(T* array, size_t length, Func function) {
    if (!array)
    {
        std::cout << "Error: Empty array" << std::endl;
        return ;
    }
    for (size_t i = 0; i < length; i++)
    {
        function(array[i]);
    }
}

#endif
