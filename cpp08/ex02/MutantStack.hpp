/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:06:12 by yzhan             #+#    #+#             */
/*   Updated: 2025/06/05 14:06:13 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <iterator>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
	public:
		
		//template constructors
		MutantStack() {}
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
		~MutantStack(void) {}
		MutantStack &operator=(const MutantStack &other) {
			if (this != &other) {
				std::stack<T, Container>::operator=(other);
			}
			return (*this);
		}
		
		using std::stack<T, Container>::stack;

		//iterators
		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;
		using reverse_iterator = typename Container::reverse_iterator;
		using const_reverse_iterator = typename Container::const_reverse_iterator;

		//iterator functions
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

		const_iterator begin() const { return (this->c.begin()); }
		const_iterator end() const { return (this->c.end()); }

		reverse_iterator rbegin() { return (this->c.rbegin()); }
		reverse_iterator rend() { return (this->c.rend()); }

		const_reverse_iterator rbegin() const { return (this->c.rbegin()); }
		const_reverse_iterator rend() const { return (this->c.rend()); }
};
