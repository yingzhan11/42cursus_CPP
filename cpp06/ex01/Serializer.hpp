/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:02:13 by yzhan             #+#    #+#             */
/*   Updated: 2025/06/05 14:02:15 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint> //uintptr_t
#include "Data.hpp"

class Serializer {
	private:
		Serializer(void) = delete;
		Serializer(const Serializer &other) = delete;
		~Serializer(void) = delete;
		Serializer &operator=(const Serializer &other) = delete;

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
