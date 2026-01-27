/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:39:18 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/27 19:52:03 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}
Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return(*this);
}

AForm *Intern::makeShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}


AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string forms[] = {"shrubbery creation",
	"robotomy request",
	"presidential pardon"
	};
	int i = 0;
	while (i < 3)
	{
		if(forms[i] == name)
			break;
		i++;
	}
	switch(i)
	{
		case 0:return (makeShrubbery(target));
		case 1:return (makeRobotomy(target));
		case 2:return (makePresidential(target));
		default:
			std::cout << "Intern cannot create bacause it does not exist." << std::endl;
	}
	throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Intern error: Form name not found.";
}