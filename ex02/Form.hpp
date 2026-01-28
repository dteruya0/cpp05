/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:04:51 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/26 20:05:39 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP 
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		Form(const std::string &_name, int _gradeToSign, int _gradeToExecute);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &x);

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& b);


#endif