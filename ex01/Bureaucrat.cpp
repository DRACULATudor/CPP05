#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(5)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    std::cout << "Parameterised constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :  _name(copy._name), _grade(copy._grade)
{
    std::cout << "Copy consturctor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
    if (this != &assign)
    {
        if (assign._grade > 150)
            throw GradeTooLowException();
        if (assign._grade < 1)
            throw GradeTooHighException();
        this->_grade = assign._grade;
    }
        std::cout << "Assignment operator called" << std::endl;
    return *this;
}

std::string    Bureaucrat::GetName(void) const
{
    return this->_name;
}

int     Bureaucrat::GetGrade(void) const
{
    return this->_grade;
}

void     Bureaucrat::setGrade(int num)
{
    if (num < 1)
        throw GradeTooHighException();
    else if (num > 150)
        throw GradeTooLowException();
    this->_grade = num;
}

void    Bureaucrat::decrementGrade(void)
{
    if (GetGrade() + 1 > 150)
        throw GradeTooLowException();
    setGrade(GetGrade()+1);
}

void    Bureaucrat::incrementGrade(void)
{
    if (GetGrade() - 1 <= 0 )
        throw GradeTooHighException();
    setGrade((GetGrade()) - 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what()  const throw()
{
    return ("Grade too low");
}

void Bureaucrat::signForm(Form &formular)
{
    try
    {
        formular.beSigned(*this);
        std::cout << GetName() << " signed " << formular.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << GetName() << " couldn't sign " << formular.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.GetName() << ", bureaucrat grade is: " << obj.GetGrade() << "."<< std::endl;
	return (out);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Deconstructor called" << std::endl;
} 