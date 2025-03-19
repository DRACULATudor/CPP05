#include "Form.hpp"

Form::Form(): _name("Default"), _signed(false), _grade_to_sign(3), _grade_to_execute(2)
{
    std::cout << "Default constructor for FORM called" << std::endl;
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
    setSignature(false);
    if (grade_to_sign > 150 || grade_to_execute > 150 )
        throw GradeTooLowException();
    else if (grade_to_sign < 0 || grade_to_execute < 0)
        throw GradeTooHighException();
    std::cout << "Parameterised constructor for FORM called" << std::endl;
}

Form::Form(const Form &copy) :   _name(copy._name), _signed(copy._signed), _grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute)
{
    std::cout << "Copy consturctor for FORM called" << std::endl;
}

Form &Form::operator=(const Form &assign)
{
    if (this != &assign)
    {
        if (assign._grade_to_sign > 150 || assign._grade_to_execute > 150 )
            throw GradeTooLowException();
        if (assign._grade_to_sign < 1 || assign._grade_to_execute < 1)
            throw GradeTooHighException();
        this->_signed = assign._signed;
    }
    std::cout << "Assignment operator for FORM called" << std::endl;
    return *this;
}

std::string    Form::getName(void) const
{
    return this->_name;
}

int     Form::getGradeToExecute(void) const
{
    return this->_grade_to_execute;
}

int     Form::getGradeToSign(void) const
{
    return this->_grade_to_sign;
}

bool    Form::getSignature() const
{
    return this->_signed;
}

void    Form::setSignature(bool signature)
{
    this->_signed = signature;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char *Form::GradeTooLowException::what()  const throw()
{
    return "Form grade too low";
}

bool Form::beSigned(const Bureaucrat &bureaucrat)
{

    if (bureaucrat.GetGrade() <= getGradeToSign())
        setSignature(true);
    else
        throw GradeTooLowException();
    return getSignature();
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << "Form: " << obj.getName() << ", grade to sign is: " << obj.getGradeToSign()
    << ", grade to execute is: "<< obj.getGradeToExecute()
    << ", signature status: " << obj.getSignature() << "."<< std::endl;
	return (out);
}

Form::~Form()
{
    std::cout << "Form Deconstructor called" << std::endl;
}
