/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:04:09 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/27 21:56:27 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;

	std::cout << "===== Creating forms with Intern =====" << std::endl;

	AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm *form2 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Alice");
	AForm *form4 = someRandomIntern.makeForm("nonexistent form", "nobody");

	std::cout << std::endl;

	if (form1)
	std::cout << "Form created: " << *form1 << std::endl;
	if (form2)
	std::cout << "Form created: " << *form2 << std::endl;
	if (form3)
	std::cout << "Form created: " << *form3 << std::endl;
	if (!form4)
	std::cout << "Invalid form, it was not created!" << std::endl;

	delete form1;
	delete form2;
	delete form3;
	delete form4;
	return 0;
}
