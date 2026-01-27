/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:04:09 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/27 17:40:38 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << "\n=== Intern tries to sign ===\n";
		intern.signForm(shrub);

		std::cout << "\n=== Boss signs all ===\n";
		boss.signForm(shrub);
		boss.signForm(robo);
		boss.signForm(pardon);

		std::cout << "\n=== Boss executes all ===\n";
		boss.executeForm(shrub);
		boss.executeForm(robo);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
