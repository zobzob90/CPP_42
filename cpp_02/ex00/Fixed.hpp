/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:49:43 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/13 14:34:42 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int					stock_num;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &value);
		~Fixed();
		Fixed &operator=(const Fixed &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);	
} ;

#endif