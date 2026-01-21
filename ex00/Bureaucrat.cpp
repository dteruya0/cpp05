/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:01:52 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/21 18:59:47 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : name(_name)
{
	if (_grade < 1)
		throw(GradeTooHighException());
	if (_grade > 150)
		throw(GradeTooLowException());
	grade = _grade;
	if (DEBUG)
		std::cout << "Bureaucrat parameter constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const &other) : name(other.name) , grade(other.grade)
{
	if (DEBUG)
		std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& operator=(const Bureaucrat &other)
{
	if (DEBUG)
		std::cout << "Bureaucrat copy assignment constructor called" << std::endl;
	if (this != &other)
		this.grade = other.grade;
	return this;
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

int	getGrade() const;
void	incrementGrade();
void	decrementGrade();
void	printGrade()

class GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw();
};
class GradeTooLowException : public std::exception 
{
	public:
		const char* what() const throw();
};