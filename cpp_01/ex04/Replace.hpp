/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:49:37 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/12 15:27:38 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

bool		is_valid(std::string filename, std::string s1, std::string s2);
std::string replace_content(std::string line, std::string s1, std::string s2);

#endif