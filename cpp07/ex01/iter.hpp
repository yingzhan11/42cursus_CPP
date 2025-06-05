/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:04:14 by yzhan             #+#    #+#             */
/*   Updated: 2025/06/05 14:04:15 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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
