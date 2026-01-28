/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:04:09 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/28 14:12:32 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "============================================" << std::endl;
	std::cout << "        INTERN FORM CREATION TEST            " << std::endl;
	std::cout << "============================================" << std::endl;

	Intern someRandomIntern;

	std::cout << "\n[STEP 1] Intern tries to create valid forms\n" << std::endl;

	AForm *shrubbery = NULL;
	AForm *robotomy = NULL;
	AForm *pardon = NULL;
	AForm *invalid = NULL;

	shrubbery = someRandomIntern.makeForm("shrubbery creation", "Home");
	robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	pardon = someRandomIntern.makeForm("presidential pardon", "Alice");

	std::cout << "\n[STEP 2] Intern tries to create an INVALID form\n" << std::endl;
	invalid = someRandomIntern.makeForm("unknown form", "Nobody");

	std::cout << "\n============================================" << std::endl;
	std::cout << "              RESULTS                        " << std::endl;
	std::cout << "============================================\n" << std::endl;

	if (shrubbery)
	{
		std::cout << "[OK] Shrubbery form created successfully:" << std::endl;
		std::cout << *shrubbery << std::endl;
	}
	else
		std::cout << "[ERROR] Shrubbery form was NOT created" << std::endl;

	std::cout << std::endl;

	if (robotomy)
	{
		std::cout << "[OK] Robotomy form created successfully:" << std::endl;
		std::cout << *robotomy << std::endl;
	}
	else
		std::cout << "[ERROR] Robotomy form was NOT created" << std::endl;

	std::cout << std::endl;

	if (pardon)
	{
		std::cout << "[OK] Presidential Pardon form created successfully:" << std::endl;
		std::cout << *pardon << std::endl;
	}
	else
		std::cout << "[ERROR] Presidential Pardon form was NOT created" << std::endl;

	std::cout << std::endl;

	if (!invalid)
		std::cout << "[EXPECTED] Invalid form was NOT created (good behavior)" << std::endl;
	else
		std::cout << "[BUG] Invalid form SHOULD NOT have been created!" << std::endl;

	std::cout << "\n============================================" << std::endl;
	std::cout << "              CLEANUP                        " << std::endl;
	std::cout << "============================================\n" << std::endl;

	std::cout << "Deleting allocated forms..." << std::endl;

	delete shrubbery;
	delete robotomy;
	delete pardon;
	delete invalid;

	std::cout << "All forms deleted. End of program." << std::endl;
	std::cout << "============================================" << std::endl;

	return 0;
}


