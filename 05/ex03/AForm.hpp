/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:11:01 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/28 15:38:46 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
  private:
    const std::string name;
    const unsigned int sign;
    const unsigned int exec;
    bool signature;
  protected:
    virtual void beExecuted() const = 0;
  public:
    virtual std::string const& getTarget() const = 0;
    std::string const& getName() const;
    bool getSign() const;
    unsigned int getSignGrade() const;
    unsigned int getExecGrade() const;
    void beSigned(Bureaucrat const& bureau);
    void execute(Bureaucrat const& executor) const;
    class GradeTooHighException: public std::exception {
      public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
      public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
    class FormAlreadySignedException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
    AForm();
    AForm(const std::string name, const unsigned int sign, const unsigned int exec);
    AForm(AForm const& other);
    AForm& operator=(AForm const& other);
    virtual ~AForm();
};

std::ostream& operator<<(std::ostream& out, AForm const& form);

#endif
