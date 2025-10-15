/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 23:09:20 by joandre-          #+#    #+#             */
/*   Updated: 2025/10/15 16:48:38 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
    static const unsigned int sign = 25;
    static const unsigned int exec = 5;
    std::string target;
  public:
    unsigned int getSignGrade() const;
    unsigned int getExecGrade() const;
    std::string const& getTarget() const;
    void beExecuted() const;
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const& target);
    PresidentialPardonForm(PresidentialPardonForm const& other);
    PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
    ~PresidentialPardonForm();
};

#endif
