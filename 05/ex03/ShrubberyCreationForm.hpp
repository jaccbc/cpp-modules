/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 23:09:20 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/28 15:39:09 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
  private:
    static const unsigned int sign = 145;
    static const unsigned int exec = 137;
    std::string target;
  public:
    unsigned int getSignGrade() const;
    unsigned int getExecGrade() const;
    std::string const& getTarget() const;
    void beExecuted() const;
    class ShrubberyCreationFailureException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const& target);
    ShrubberyCreationForm(ShrubberyCreationForm const& other);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
    ~ShrubberyCreationForm();
};

#endif
