#include "AForm.hpp"
#include <cstdio>

AForm::AForm(): _name("Default"), _signed(false), _grade_to_sign(3), _grade_to_execute(2)
{
    std::cout << "Default constructor for AForm called" << std::endl;
}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
    if (grade_to_sign > 150 || grade_to_execute > 150 )
        throw GradeTooLowException();
    else if (grade_to_sign < 0 || grade_to_execute < 0)
        throw GradeTooHighException();
    std::cout << "Parameterised constructor for AForm called" << std::endl;
}

AForm::AForm(const AForm &copy) :   _name(copy._name), _signed(copy._signed), _grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute)
{
    std::cout << "Copy consturctor for AForm called" << std::endl;
}

AForm &AForm::operator=(const AForm &assign)
{
    if (this != &assign)
    {
        if (assign._grade_to_sign > 150 || assign._grade_to_execute > 150 )
            throw GradeTooLowException();
        if (assign._grade_to_sign < 1 || assign._grade_to_execute < 1)
            throw GradeTooHighException();
        this->_signed = assign._signed;
    }
    std::cout << "Assignment operator for AForm called" << std::endl;
    return *this;
}

std::string    AForm::getName(void) const
{
    return this->_name;
}

int     AForm::getGradeToExecute(void) const
{
    return this->_grade_to_execute;
}

int     AForm::getGradeToSign(void) const
{
    return this->_grade_to_sign;
}

bool    AForm::getSignature() const
{
    return this->_signed;
}

void    AForm::setSignature(bool signature)
{
    this->_signed = signature;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade too high";
}

const char *AForm::GradeTooLowException::what()  const throw()
{
    return "AForm grade too low";
}

const char *AForm::DocumentNotSignedException::what()  const throw()
{
    return "The form has not been";
}
const char *AForm::GradeTooLowExceptionExec::what()  const throw()
{
    return ("grade to execute is too low");
}


bool AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.GetGrade() <= getGradeToSign())
        setSignature(true);
    else
        throw GradeTooLowException();
    return getSignature();
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << "AForm: " << obj.getName() << ", grade to sign is: " << obj.getGradeToSign()
    << ", grade to execute is: "<< obj.getGradeToExecute()
    << ", signature status: " << obj.getSignature() << "."<< std::endl;
	return (out);
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}
