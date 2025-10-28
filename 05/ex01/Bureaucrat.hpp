/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 02:47:18 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/28 10:16:27 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Form;

class Bureaucrat {
  private:
    const std::string name;
    unsigned int grade;
  public:
    std::string const& getName() const;
    unsigned int getGrade() const;
    void signForm(Form& form);
    class GradeTooHighException: public std::exception {
      public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
      public:
        virtual const char* what() const throw();
    };
    Bureaucrat();
    Bureaucrat(std::string const& name, const unsigned int n);
    Bureaucrat(Bureaucrat const& other);
    Bureaucrat& operator=(Bureaucrat const& other);
    Bureaucrat& operator++();
    Bureaucrat operator++(int);
    Bureaucrat& operator--();
    Bureaucrat operator--(int);
    ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& b);

#endif
