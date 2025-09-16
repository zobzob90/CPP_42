/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:27:51 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/16 15:34:33 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Usage : " << av[0] << " <value>" << std::endl;
		return (1);
	}
	Scalar::convert(av[1]);
	return (0);
}
