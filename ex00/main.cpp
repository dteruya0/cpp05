/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:33:27 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/28 14:15:19 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "===== Test 1: valid creation =====" << std::endl;
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Test 2: grade too high =====" << std::endl;
	try
	{
		Bureaucrat b("Bob", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Test 3: grade too low =====" << std::endl;
	try
	{
		Bureaucrat c("Charlie", 151);
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Test 4: increment / decrement =====" << std::endl;
	try
	{
		Bureaucrat d("Diego", 2);
		std::cout << d << std::endl;

		d.incrementGrade();
		std::cout << "After increment: " << d << std::endl;

		d.decrementGrade();
		std::cout << "After decrement: " << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Test 5: assignment operator =====" << std::endl;
	try
	{
		Bureaucrat e("Eva", 10);
		Bureaucrat f("Frank", 100);

		std::cout << "Before:" << std::endl;
		std::cout << e << std::endl;
		std::cout << f << std::endl;

		f = e;

		std::cout << "After:" << std::endl;
		std::cout << e << std::endl;
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

