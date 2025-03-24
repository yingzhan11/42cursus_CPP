/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:01:06 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/24 10:01:07 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		// Constructor
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& copy);
		~Fixed();
		
		// Operators
		Fixed&	operator=(const Fixed& copy);
		bool	operator>(const Fixed& number) const;
		bool	operator>=(const Fixed& number) const;
		bool	operator<(const Fixed& number) const;
		bool	operator<=(const Fixed& number) const;
		bool	operator==(const Fixed& number) const;
		bool	operator!=(const Fixed& number) const;

		Fixed	operator+(const Fixed& number) const;
		Fixed	operator-(const Fixed& number) const;
		Fixed	operator*(const Fixed& number) const;
		Fixed	operator/(const Fixed& number) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		// Functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		// Overloaded functions
		static Fixed& 		min(Fixed& a, Fixed& b);
		const static Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed& 		max(Fixed& a, Fixed& b);
		const static Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator << (std::ostream& os, const Fixed& number);


#endif
