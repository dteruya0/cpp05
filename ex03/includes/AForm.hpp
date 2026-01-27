/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:04:51 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/27 17:56:36 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP 
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		AForm(const std::string &_name, int _gradeToSign, int _gradeToExecute);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

		std::string getName() const;
		bool	getIsSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;
		void	beSigned(const Bureaucrat &x);
		virtual void execute(Bureaucrat const &executor) const = 0;

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
			class FormNotSignedException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& b);


#endif