#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	std::string _target;

  public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &assignment);
	void execute(const Bureaucrat &executor) const;
	void PresidentialPardoning() const;
	~PresidentialPardonForm();
};
