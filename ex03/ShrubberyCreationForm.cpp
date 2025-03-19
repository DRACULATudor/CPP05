#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("declaration of shrubbery")
{
    std::cout << "Default constructor Shrubbery Creation Form called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target)
{
    std::cout << "Parameterized Shrubbery Creation Form called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "Copy constuctor Shrubbery Creation Form called!" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
    if (this != &assign)
    {
        AForm::operator=(assign);
        this->_target = assign._target;
    }
    std::cout << "Assignment operator called by Shrubbery Creation Form" << std::endl;
    return *this;
}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if(!this->getSignature())
        throw AForm::DocumentNotSignedException();
    if (executor.GetGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
        drawTrees();
}

void ShrubberyCreationForm::drawTrees()const
{
    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "Error creating the file" << std::endl;
        return;
    }
    outfile << "       _-_ \n";
    outfile << "    /~~   ~~\\\n";
    outfile << " /~~         ~~\\\n";
    outfile << "{               }\n";
    outfile << " \\  _-     -_  / \n";
    outfile << "   ~  \\ //  ~\n";
    outfile << "_- -   | | _- _\n";
    outfile << "  _ -  | |   -_\n";
    outfile << "      // \\\\";

    outfile.close();
    std::cout << "file " << _target << "_shrubbery created w ASCII 3s." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor ShrubberyCreationForm called!" << std::endl;
}
