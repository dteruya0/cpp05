/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:04:38 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/26 20:23:05 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(const std::string &_name, int _gradeToSign, int _gradeToExecute)
	: name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const Form &other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "Default copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
	std::cout << "Form copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form destrutor called" << std::endl;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &x)
{
	if (x.getGrade() <= this->getGradeToSign())
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", signed: " << f.getIsSigned() << ", grade to sign: "
		<< f.getGradeToSign() << ", grade to exec: " << f.getGradeToExecute() << std::endl;
	return os;
}
