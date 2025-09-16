/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:55:51 by eric              #+#    #+#             */
/*   Updated: 2025/09/16 15:34:28 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <limits>

class Scalar
{
	private:
		Scalar();
		Scalar(const Scalar& src);
		Scalar& operator=(const Scalar& src);
		~Scalar();

		static bool isChar(const std::string& input);
		static bool isInt(const std::string& input);
		static bool isFloat(const std::string& input);
		static bool isDouble(const std::string& input);

		static void convertChar(const std::string& input);
		static void convertInt(const std::string& input);
		static void convertFloat(const std::string& input);
		static void convertDouble(const std::string& input);
	public:
		static void convert(const std::string& input);
} ;

#endif