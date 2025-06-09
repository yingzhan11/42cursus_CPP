/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:03:17 by yzhan             #+#    #+#             */
/*   Updated: 2025/06/05 14:03:18 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include <iostream>
#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
