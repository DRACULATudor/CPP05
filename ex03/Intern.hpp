#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

//Yes, typedef is part of the C++98 standard. It is used to create type aliases, 
//which can simplify complex type declarations and make code more readable.

class Intern
{
private:
    typedef AForm* (Intern::*Forms)(const std::string &target) const;
     AForm* createShrubberyCreationForm(const std::string &target)const;
     AForm* createRobotomyRequestForm(const std::string &target)const;
     AForm* createPresidentialPardonForm(const std::string &target)const;
public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &assign);
    AForm *makeForm(const std::string form_name,const std::string target);
    ~Intern();
};
