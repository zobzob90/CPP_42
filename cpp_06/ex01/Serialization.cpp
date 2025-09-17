/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:55:00 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/17 14:54:07 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

// Constructeur privé (ne sera jamais appelé)
Serializer::Serializer() {}

// Constructeur de copie privé (ne sera jamais appelé)
Serializer::Serializer(const Serializer& src) {
    (void)src;
}

// Opérateur d'assignation privé (ne sera jamais appelé)
Serializer& Serializer::operator=(const Serializer& src) {
    (void)src;
    return *this;
}

// Destructeur privé (ne sera jamais appelé)
Serializer::~Serializer() {}

// Convertit un pointeur Data* en uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// Convertit un uintptr_t en pointeur Data*
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
