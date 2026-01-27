/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:01:52 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/27 17:55:41 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : name(_name)
{
	if (_grade < 1)
		throw(GradeTooHighException());
	if (_grade > 150)
		throw(GradeTooLowException());
	grade = _grade;
	if (DEBUG)
		std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name) , grade(other.grade)
{
	if (DEBUG)
		std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (DEBUG)
		std::cout << "Bureaucrat copy assignment constructor called" << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	if (DEBUG)
		std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw(GradeTooHighException());
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw(GradeTooLowException());
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception caught: Grade too high! (Must be between 1 and 150)");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception caught: Grade too low! (Must be between 1 and 150)");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void Bureaucrat::signForm(AForm& x)
{
	try
	{
		x.beSigned(*this);
		std::cout << this->name << " signed " << x.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn’t sign " << x.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn’t execute "
				  << form.getName() << " because "
				  << e.what() << std::endl;
	}
}

