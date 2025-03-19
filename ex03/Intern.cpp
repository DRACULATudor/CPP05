#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor has been called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
    std::cout << "Intern copy operator has been called" << std::endl;
}

Intern &Intern::operator=(const Intern &assign)
{
    if (this != &assign)
    {
        *this = assign;
    }
    std::cout << "Intern assignment operator has been called" << std::endl;
    return *this;
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)const
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target)const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string form_name,const  std::string target)
{
    const std::string arr[] = {"presidential pardon", "robotomy request",
        "shrubbery creation"};
    Forms formulars[] = {
        &Intern::createPresidentialPardonForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createShrubberyCreationForm
    };
    for (int i = 0; i < 3; i++)
    {
        if (form_name == arr[i])
        {
            std::cout << "Intern has created the form: " << form_name << std::endl;
            return (this->*formulars[i])(target);
        }
    }
    std::cerr << "Form :" << form_name << " doesn't exist" << std::endl;
    return NULL;
}

Intern::~Intern()
{
    std::cout << "Intern destructor has been called" << std::endl;
}
