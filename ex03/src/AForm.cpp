/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:04:38 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/27 17:56:44 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm(const std::string &_name, int _gradeToSign, int _gradeToExecute)
	: name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "Default copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	std::cout << "AForm copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destrutor called" << std::endl;
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &x)
{
	if (x.getGrade() <= this->getGradeToSign())
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << ", signed: " << f.getIsSigned() << ", grade to sign: "
		<< f.getGradeToSign() << ", grade to exec: " << f.getGradeToExecute() << std::endl;
	return os;
}