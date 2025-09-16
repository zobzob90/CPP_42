/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:55:51 by eric              #+#    #+#             */
/*   Updated: 2025/09/15 11:06:48 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <cmath>
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

		static bool convertChar(const std::string& input);
		static bool convertInt(const std::string& input);
		static bool convertFloat(const std::string& input);
		static bool convertDouble(const std::string& input);
	public:
		static bool convert(const std::string& input);
}

#endif