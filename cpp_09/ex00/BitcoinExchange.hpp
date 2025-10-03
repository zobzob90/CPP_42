/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:42:37 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/03 17:47:38 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Btc
{
	private :
		std::map<std::string, double> _ctnrRates; // container pour stocker data.csv(Date -> taux)

	public :
		// constructeur / destructeur / operateur part
		Btc() {}
		Btc(const Btc& src) : _ctnrRates(src._ctnrRates) {}
		Btc& operator=(const Btc& src)
		{
			if (this != &src)
				_ctnrRates = src._ctnrRates;
			return (*this);
		}
		~Btc() {};
	
		void	loadDatabase(const std::string& filename);	// charger data.csv pour remplir _ctnrRates
		void	processInput(const std::string& filename);	// traiter input.txt
	
	private :
		// fonction annexe de parsing de la date et des valeur passe en argument
		bool isValidValue(double value) const;
		bool isValidDate(const std::string& date) const;
		bool isValidExtent(const std::string& extention) const;
		double getRateForDate(const std::string& date) const; // double pour affiner le calcul en 64 bits pas en 16 comme float
		std::string trim(const std::string& str) const; // helper function to remove whitespace
} ;

#endif