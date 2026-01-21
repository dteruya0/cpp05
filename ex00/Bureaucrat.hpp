/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:01:56 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/21 18:59:54 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#define DEBUG false

class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;

	public:
		Bureaucrat(const std::string &_name, int _grade);
		Bureaucrat(const &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string	getName() const;
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
};

#endif