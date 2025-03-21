/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:01:06 by yzhan             #+#    #+#             */
/*   Updated: 2025/03/20 13:01:08 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceFile.hpp"

ReplaceFile::ReplaceFile(const std::string& filename, const std::string& s1, const std::string& s2, std::string oriContent)
	: _filename(filename), _s1(s1), _s2(s2), _oriContent(oriContent){}

/**
 * Public function
 */
bool	ReplaceFile::replace()
{
	std::string	newContent;
	size_t		i = 0;

	if (_s1 == "")
	{
		std::cout << "The s1 cannot be empty." << std::endl;
		return false;
	}
	if (_readFile() == false)
		return false;
	if (this->_oriContent == "")
	{
		std::cout << "The infile is empty." << std::endl;
		return false;
	}
	while (1)
	{
		// Find s1 in oriContent
		size_t isFind = _oriContent.find(_s1, i);
		if (isFind == std::string::npos)
			break ;
		// Copy content before s1 and append s2 after it
		try
		{
			newContent.append(_oriContent, i, isFind - i);
		}
		catch(const std::exception& e)
		{
			std::cerr << "String length error: " << e.what() << std::endl;
			return false;
		}
		newContent += _s2;
		i = isFind + _s1.length();
	}
	// Append the rest part
	try
	{
		newContent.append(_oriContent, i, std::string::npos);
	}
	catch(const std::exception& e)
	{
		std::cerr << "String length error: " << e.what() << std::endl;
		return false;
	}
	// Write the copy&replaced content into outFile
	if (_writeFile(newContent) == false)
		return false;
	return true;
	
}

/**
 * Private function
 */
bool ReplaceFile::_readFile()
{
	// Open file, if cannot open, return false
	std::ifstream	inFile(this->_filename);
	if (!inFile)
	{
		std::cout << "Cannot open the infile" << std::endl;
		return false;
	}
	// get content from file to a stringstream
	std::stringstream	content;
	content << inFile.rdbuf();
	this->_oriContent = content.str();
	return true;
}

bool ReplaceFile::_writeFile(const std::string& content)
{
	std::ofstream	outFile(this->_filename + ".replace");
	if (!outFile)
	{
		std::cout << "Cannot create the outfile" << std::endl;
		return false;
	}
	outFile << content;
	return true;
}