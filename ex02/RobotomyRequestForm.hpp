#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &assignment);
    void execute(const Bureaucrat &executor)const;
    void robotomy()const;
    ~RobotomyRequestForm();
};
