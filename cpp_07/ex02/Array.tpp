/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:57:54 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/08 13:43:38 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& src) : _elements(NULL), _size(src._size)
{
	if (_size > 0)
	{
		_elements = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = src._elements[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& src)
{
	if (this != &src)
	{
		delete[] _elements;
		_size = src._size;
		if (_size > 0)
		{
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_elements[i] = src._elements[i];
		}
		else
			_elements = NULL;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

template <typename T> // version pour objet non-constant 
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (_elements[index]); // PEUT modifier l'element
}

template <typename T> // version pour objet const
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception(); // evite le segfault
	return (_elements[index]); // Lecture seuleument
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
