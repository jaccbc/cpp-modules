/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:11:01 by joandre-          #+#    #+#             */
/*   Updated: 2025/09/15 19:22:21 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
  private:
    const std::string name;
    const unsigned int sign;
    const unsigned int exec;
    bool signature;
  public:
    std::string const& getName() const;
    bool getSign() const;
    unsigned int getGrade(bool g) const;
    void beSigned(Bureaucrat const& bureau);
    class GradeTooHighException: public std::exception {
      public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
      public:
        virtual const char* what() const throw();
    };
    Form(const std::string name, const unsigned int sign, const unsigned int exec);
    Form(Form const& other);
    Form& operator=(Form const& other);
    ~Form();
};

std::ostream& operator<<(std::ostream& out, Form const& form);

#endif
