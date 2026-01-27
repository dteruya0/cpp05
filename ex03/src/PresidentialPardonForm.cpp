/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:25:31 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/27 17:34:19 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
	:	AForm("PresidentialPardonForm", 25, 5), target(_target)
{
	std::cout << "Presidential constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	:	AForm(other), target(other.target)
{
	std::cout << "Presidential copy constructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw(FormNotSignedException());
	if (executor.getGrade() > this->getGradeToExecute())
		throw(GradeTooLowException());
	std::cout << this->target
				<< " has been pardoned by Zaphod Beeblebrox."
				<< std::endl;
}