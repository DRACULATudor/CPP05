#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// Test 1
int	main(void)
{
    try
	{
        Intern someRnadom;
        AForm* importantForm;
        importantForm = someRnadom.makeForm("robotomy request", "slander");
        if (importantForm)
        {
            std::cout << *importantForm << std::endl;
            delete importantForm;
        }
        
        importantForm = someRnadom.makeForm("presidential pardon", "slander");
        if (importantForm)
        {
            std::cout << *importantForm << std::endl;
            delete importantForm;
        }
        importantForm = someRnadom.makeForm("shrubbery creation", "slander");
        if (importantForm)
        {
            std::cout << *importantForm << std::endl;
            delete importantForm;
        }
    }
    catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Execption caught: Form: " << e.what() << std::endl;
	}
    catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Execption caught: Form: " << e.what() << std::endl;
	}
    catch (const AForm::DocumentNotSignedException &e)
    {
        std::cerr << "Execption caught: Form: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execption caught: Form: " << e.what() << std::endl;
    }
    return (0);
}

//Test 2
// int	main(void)
// {
//     try
// 	{
//         Intern someRnadom;
//         AForm* importantForm[3];
//         importantForm[0] = someRnadom.makeForm("robotomy request", "slander");
//         importantForm[1] = someRnadom.makeForm("presidential pardon", "vendor");
//         importantForm[2] = someRnadom.makeForm("shrubbery creation", "bender");
//         Bureaucrat boss("Jhonn", 1);
//         boss.signAForm(*importantForm[0]);
//         boss.executeForm(*importantForm[0]);
//         boss.signAForm(*importantForm[1]);
//         boss.executeForm(*importantForm[1]);
//         boss.signAForm(*importantForm[2]);
//         boss.executeForm(*importantForm[2]);
//         for (int i = 0; i < 3; i++)
//             delete importantForm[i];
//     }catch (const Bureaucrat::GradeTooHighException &e)
// 	{
// 		std::cerr << "Execption caught: Form: " << e.what() << std::endl;
// 	}catch (const Bureaucrat::GradeTooLowException &e)
// 	{
// 		std::cerr << "Execption caught: Form: " << e.what() << std::endl;
// 	}
//     catch (const AForm::DocumentNotSignedException &e)
//     {
//         std::cerr << "Execption caught: Form: " << e.what() << std::endl;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Execption caught: Form: " << e.what() << std::endl;
//     }
//     return (0);
// }