/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:45 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/17 14:54:06 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>
#include <string>
#include <fstream>

// Structure Data pour les tests
struct Data {
    int     ValueOfInt;
    char    ValueOfChar;
    double  ValueOfDouble;
    
    Data(int i, char c, double d) : ValueOfInt(i), ValueOfChar(c), ValueOfDouble(d) {}
};

// Classe Serializer avec méthodes statiques
class Serializer {
private:
    // Constructeur privé pour empêcher l'instanciation
    Serializer();
    Serializer(const Serializer& src);
    Serializer& operator=(const Serializer& src);
    ~Serializer();

public:
    // Méthodes statiques pour sérialisation/désérialisation
    static uintptr_t    serialize(Data* ptr);
    static Data*        deserialize(uintptr_t raw);
};

#endif