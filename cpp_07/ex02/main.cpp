/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:57:51 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/19 20:55:16 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    std::cout << "=== Testing Array Template ===" << std::endl;
    
    // Test constructeur par défaut
    std::cout << "1. Testing default constructor..." << std::endl;
    Array<int> empty;
    std::cout << "   Empty array size: " << empty.size() << std::endl;
    
    // Test constructeur avec paramètre
    std::cout << "2. Testing parametric constructor..." << std::endl;
    Array<int> numbers(MAX_VAL);
    std::cout << "   Array size: " << numbers.size() << std::endl;
    
    int* mirror = new int[MAX_VAL];
    std::cout << "3. Filling array with random values..." << std::endl;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "   First few values: " << numbers[0] << ", " << numbers[1] << ", " << numbers[2] << std::endl;
    
    //SCOPE
    std::cout << "4. Testing copy constructor and assignment..." << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "   Copy successful, sizes: tmp=" << tmp.size() << ", test=" << test.size() << std::endl;
    }

    std::cout << "5. Verifying deep copy integrity..." << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "   ✓ Deep copy integrity verified!" << std::endl;
    
    std::cout << "6. Testing bounds checking..." << std::endl;
    try
    {
        std::cout << "   Testing negative index [-2]..." << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "   ✓ Exception caught for negative index: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "   Testing out of bounds index [" << MAX_VAL << "]..." << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "   ✓ Exception caught for out of bounds: " << e.what() << std::endl;
    }

    std::cout << "7. Testing different types..." << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "!";
    std::cout << "   String array: " << strings[0] << " " << strings[1] << " " << strings[2] << std::endl;

    std::cout << "8. Final modifications..." << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "   ✓ Array successfully modified with new values" << std::endl;
    
    std::cout << "\n=== All tests completed successfully! ===" << std::endl;
    delete [] mirror;
    return 0;
}
