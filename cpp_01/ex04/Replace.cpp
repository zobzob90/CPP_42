/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:49:27 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/12 16:04:35 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

bool	is_valid(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	inputFile(filename.c_str());
	std::ofstream	outputFile((filename + ".replace").c_str());
	std::string		line;

	if (filename.empty())
	{
		std::cerr << "Error: File empty !" << std::endl;
		return (false);
	}
	if (s1.empty())
	{
		std::cerr << "Error: s1 empty !" << std::endl;
		return (false);
	}
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Cannot opening file !" << std::endl;
		return (false);
	}
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Cannot create file !" << std::endl;
		inputFile.close();
		return (false);
	}
	while (std::getline(inputFile, line))
		outputFile << replace_content(line, s1, s2) << std::endl;
	inputFile.close();
	outputFile.close();
	return (true);
}

std::string replace_content(std::string line, std::string s1, std::string s2)
{
	std::string	result = line;
	size_t		pos = 0;

	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result.erase(pos, s1.length());
		result.insert(pos, s2);
		pos += s2.length();
	} 
	return (result);
}
