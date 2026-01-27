/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:25:45 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/27 17:34:25 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
	:	AForm("RobotomyRequestForm", 72, 45), target(_target)
{
	std::cout << "Robotomy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	:	AForm(other), target(other.target)
{
	std::cout << "Robotomy copy constructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << "* drilling noises * 🤖🔧" << std::endl;

	if (this->getIsSigned() == false)
		throw(FormNotSignedException());
	if (executor.getGrade() > this->getGradeToExecute())
		throw(GradeTooLowException());
	int	random = std::rand() % 2;
	if (random == 0)
	{
		std::cout << this->target 
					<< " has been robotomized successfully!"
					<< std::endl;
	}
	else
	{
		std::cout 
		<< "Robotomy failed on " 
		<< this->target 
		<< std::endl;
	}
}