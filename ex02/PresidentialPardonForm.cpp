#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default PresidentialPardonForm", 25, 5), _target("No target")
{
    std::cout << "Default constructor Presidential Pardon Form called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target)
{
    std::cout << "Parameterized Presidential Pardon Form called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "Copy constuctor Presidential Pardon Form called!" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
    if (this != &assign)
    {
        AForm::operator=(assign);
        this->_target = assign._target;
    }
    std::cout << "Assignment Presidential Pardon Form operator called" << std::endl;
    return *this;
}

void    PresidentialPardonForm::PresidentialPardoning() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor)const
{
    if (!this->getSignature())
        throw AForm::DocumentNotSignedException();
    if (executor.GetGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
        PresidentialPardoning();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor Presidential Pardon Form called!" << std::endl;
}
