/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:11:01 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 17:47:24 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

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
    unsigned int getSignGrade() const;
    unsigned int getExecGrade() const;
    void beSigned(Bureaucrat const& bureau);
    class GradeTooHighException: public std::exception {
      public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
      public:
        virtual const char* what() const throw();
    };
    class InvalidGradeException: public std::exception {
      public:
        virtual const char* what() const throw();
    };
    Form();
    Form(const std::string name, const unsigned int sign, const unsigned int exec);
    Form(Form const& other);
    Form& operator=(Form const& other);
    ~Form();
};

std::ostream& operator<<(std::ostream& out, Form const& form);

#endif
