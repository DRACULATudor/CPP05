#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Tests
int	main(void)
{
    try
	{
        Bureaucrat bossman("g", 46);
        PresidentialPardonForm pardon("El Patron");
        ShrubberyCreationForm pardon2("El Jefe");
        RobotomyRequestForm pardon3("Boss");
        bossman.signAForm(pardon);
        bossman.executeForm(pardon);
        bossman.signAForm(pardon2);
        bossman.executeForm(pardon2);
        bossman.signAForm(pardon3);
        bossman.executeForm(pardon3);

    }catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Execption caught: Form: " << e.what() << std::endl;
	}catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Execption caught: Form: " << e.what() << std::endl;
	}
    catch (const AForm::DocumentNotSignedException &e)
    {
        std::cerr << "Execption caught: Form: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execption caught: " << e.what() << std::endl;
    }
    return (0);
}

// int	main(void)
// {
//     try
// 	{
//         Bureaucrat bossman("g", 46);
//         PresidentialPardonForm pardon("El Patron");
//         ShrubberyCreationForm pardon2("El Jefe");
//         RobotomyRequestForm pardon3("Boss");
//         bossman.signAForm(pardon);
//         bossman.executeForm(pardon);
//         bossman.signAForm(pardon2);
//         bossman.executeForm(pardon2);
//         bossman.signAForm(pardon3);
//         bossman.executeForm(pardon3);

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
//         std::cerr << "Execption caught: " << e.what() << std::endl;
//     }
//     return (0);
// }
