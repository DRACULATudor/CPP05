#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default RobotomyRequestForm", 72, 45), _target("declaration of robotomy")
{
    std::cout << "Default constructor Robotomy Request Form called!" << std::endl;
    srand(time(0));

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target)
{
    std::cout << "Parameterized Robotomy Request Form called!" << std::endl;
    srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "Copy constuctor Robotomy Request Form called!" << std::endl;
    srand(time(0));
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
    if (this != &assign)
    {
        AForm::operator=(assign);
        this->_target = assign._target;
    }
    std::cout << "Assignment Robotomy Request Form operator called" << std::endl;
    return *this;
}

void    RobotomyRequestForm::robotomy()const
{
    std::cout << "Drilling noises .................." << std::endl;
    if (rand() % 2 == 1)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy failed for " <<_target << std::endl; 
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor)const
{
    if (!this->getSignature())
        throw AForm::DocumentNotSignedException();
    if (executor.GetGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
        robotomy();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor Robotomy Request Form called!" << std::endl;
}
