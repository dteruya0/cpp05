/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:33:27 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/26 15:50:01 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "===== Teste 1: criação válida =====" << std::endl;
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Teste 2: grade muito alta =====" << std::endl;
	try
	{
		Bureaucrat b("Bob", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Teste 3: grade muito baixa =====" << std::endl;
	try
	{
		Bureaucrat c("Charlie", 151);
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Teste 4: increment / decrement =====" << std::endl;
	try
	{
		Bureaucrat d("Diego", 2);
		std::cout << d << std::endl;

		d.incrementGrade();
		std::cout << "Após increment: " << d << std::endl;

		d.incrementGrade(); // deve lançar exceção
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Teste 5: operador de atribuição =====" << std::endl;
	try
	{
		Bureaucrat e("Eva", 10);
		Bureaucrat f("Frank", 100);

		std::cout << "Antes:" << std::endl;
		std::cout << e << std::endl;
		std::cout << f << std::endl;

		f = e;

		std::cout << "Depois:" << std::endl;
		std::cout << e << std::endl;
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
