/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:15:12 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/12 17:04:34 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char *av[])
{
	Harl	harl;
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <log_level>" << std::endl;
        std::cerr << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }
    harl.complain(av[1]);
    return 0;
}
