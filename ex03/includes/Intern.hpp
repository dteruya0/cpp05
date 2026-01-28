/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:38:37 by dteruya           #+#    #+#             */
/*   Updated: 2026/01/27 21:53:31 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	private:
		AForm	*makePresidential(const std::string &target);
		AForm	*makeRobotomy(const std::string &target);
		AForm	*makeShrubbery(const std::string &target);

	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif