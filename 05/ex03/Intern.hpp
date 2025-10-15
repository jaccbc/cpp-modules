/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:24:58 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 21:35:07 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

typedef struct s_FormList {
  const std::string name;
  AForm* (*newForm)(std::string const& target);
} formList_t;

class Intern {
  private:
    static const formList_t formType[3];
  public:
    AForm* makeForm(std::string const& form, std::string const& target) const;
    class InvalidFormNameException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
    Intern();
    Intern(Intern const& other);
    Intern& operator=(Intern const& other);
    ~Intern();
};

#endif
