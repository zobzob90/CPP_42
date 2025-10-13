/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:46:10 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/13 14:09:39 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	printElement(T const & x)
{
	std::cout << x;
}

template<typename T>
void	isEvenOrOdd(T& x)
{
	if (x % 2 == 0)
		std::cout << x << " is even" << std::endl;
	else if (x % 3 == 0)
		 std::cout << x << " is odd" << std::endl;
}

template<typename T>
T	capsLock(T& x)
{
	if (std::isalpha(x))
		x = std::toupper(x);
	std::cout << x;
	return (x);
}

int main(void)
{
	int		intArr[4] = {1, 2 ,3 ,4};
	char	charArray[6] = "Hello";
	double	doubleArr[10] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};
	int		evenArr[1] = {4};
	int		oddArr[1] = {3};
	
	std::cout << "=== Testing with int array ===" << std::endl;
	iter(intArr, 4, printElement<int>);
	std::cout << "\n=== Testing with char array ===" << std::endl;
	iter(charArray, 6, printElement<char>);
	std::cout << "\n=== Testing with double array ===" << std::endl;
	iter(doubleArr, 10, printElement<double>);
	std::cout << std::endl;

	std::cout << "=== TESTING ODD OR EVEN ===" << std::endl;
	iter(evenArr, 1, isEvenOrOdd<int>);
	iter(oddArr, 1, isEvenOrOdd<int>);
	iter(charArray, 6, isEvenOrOdd<char>);

	std::cout << "TESTING WITH A RETURN TYPE : ";
	iter(charArray, 6, capsLock<char>);
	std::cout << std::endl;
	
	return (0);
}

// class Awesome
// {
// 	public:
// 		Awesome( void ) : _n(42) { return ; }
// 		int get (void) const {return this->_n;}
// 	private:
// 		int _n;
// } ;

// std::ostream& operator<<(std::ostream& o, Awesome const &rhs)
// {
// 	o << rhs.get();
// 	return o;
// }

// template<typename T>
// void	printElement(const T& x)
// {
// 	std::cout << x << std::endl;
// 	return ;
// }

// int main()
// {
// 	int tab[] = { 0, 1, 2, 3, 4};
// 	Awesome tab2[5];

// 	iter(tab, 5, printElement<int>);
// 	iter(tab2, 5, printElement<Awesome>);

// 	return (0);
// }