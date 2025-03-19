#include "Bureaucrat.hpp"


// //Test1
// Main to prove the functionality of ortho canon form
// int main()
// {
//     Bureaucrat smart1("Jhon", 23);
//     Bureaucrat smart2(smart1);
//     Bureaucrat smart3("Andrei", 46);
//     Bureaucrat smart4("Sefu", 145);
//     Bureaucrat smart5("Sefu", 150);

//     smart5 = smart4;
//     std::cout << smart1;
//     std::cout << smart2;
//     std::cout << smart3;
//     std::cout << smart4;
//     std::cout << smart5;

//     std::cout << std::endl;
//     std::cout << "Ortho functionality for the class form"<< std::endl;

//     Form form1("Math", 3, 1);
//     Form form2("Chemestry", 15, 1);
//     std::cout << form2;
//     Form form3("History", 20, 1);
//     Form form4(form1);
//     form3 = form2;

//     std::cout << form1;
//     std::cout << form2;
//     std::cout << form3;
//     std::cout << form4;
// }

// Test 2
int	main(void)
{
    Form form1("chemestry", 2, 1);
    Form form2("biology", 1, 1);
    Form form3("romanian", 1, 1);
	
    try
	{
        Bureaucrat bossman("Patron", 1);
        bossman.signForm(form1);
        bossman.signForm(form2);
        bossman.signForm(form3);
		std::cout << form1;
		std::cout << form2;
		std::cout << form3;
    }catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Execption caught: Form: " << e.what() << std::endl;
	}catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Execption caught: Form: " << e.what() << std::endl;
	}
    return (0);
}
