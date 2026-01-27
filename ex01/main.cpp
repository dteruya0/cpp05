/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:33:27 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/26 20:24:38 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		std::cout << "=== Creating Bureaucrats ===" << std::endl;
		Bureaucrat a("Raze", 40);
		Bureaucrat b("Kayo", 120);
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << "\n=== Creating Form ===" << std::endl;
		Form f("TaxForm", 50, 30);
		std::cout << f << std::endl;

		std::cout << "\n=== Signing form with sufficient grade ===" << std::endl;
		a.signForm(f);
		std::cout << f << std::endl;

		std::cout << "\n=== Signing form with low grade ===" << std::endl;
		Form secret("SecretForm", 10, 5);
		b.signForm(secret);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Creating invalid form ===" << std::endl;
	try
	{
		Form bad("BadForm", 0, 200);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}


