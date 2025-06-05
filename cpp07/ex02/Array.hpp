/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:04:35 by yzhan             #+#    #+#             */
/*   Updated: 2025/06/05 14:04:36 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);

        Array(const Array& other);
        Array& operator=(const Array& other);

        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        
        unsigned int size() const;
};

#include "Array.tpp"
