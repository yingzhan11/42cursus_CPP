/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:00:58 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/20 13:00:59 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACEFILE_HPP
# define REPLACEFILE_HPP

# include <string>
# include <fstream>
# include <iostream>
# include <sstream>

class ReplaceFile
{
	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;
		std::string	_oriContent;

		bool	_readFile(void);
		bool	_writeFile(const std::string& content);

	public:
		ReplaceFile(const std::string& filename, const std::string& s1, const std::string& s2, std::string oriContent);
		
		bool	replace(void);
};

#endif
