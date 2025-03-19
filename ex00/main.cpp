#include "Bureaucrat.hpp"

//Test1
// Main to prove the functionality of ortho canon form
int main()
{
    try
    {
        
        
        Bureaucrat smart1("Jhon", 150);
        Bureaucrat smart2(smart1);
        Bureaucrat smart3("Andrei", 46);
        Bureaucrat smart4("Sefu", 145);
        Bureaucrat smart5("Sefu", 150);
        smart5 = smart4;
        std::cout << smart1;
        std::cout << smart2;
        std::cout << smart3;
        std::cout << smart4;
        std::cout << smart5;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

//Test 2
// int	main(void)
// {
// 	try
// 	{
// 		Bureaucrat smart1("Jhon", 23);
// 		Bureaucrat smart4("Sefu", 145);
// 		Bureaucrat smart3("Sefu", 112);
// 		std::cout << smart1;
// 		std::cout << smart3;
// 		std::cout << smart4;

// 		smart1.incrementGrade();
// 		while (smart1.GetGrade() > 1)
// 		{
// 			smart1.incrementGrade();
// 			std::cout << smart1;
// 		}
//         smart3.setGrade(40);
//         std::cout << smart3;
//         smart4.setGrade(150);
//         std::cout << smart4;
// 		// smart1.incrementGrade(); 
//         // uncoment to see exception beeing corectly caught
// 	}
// 	catch (const Bureaucrat::GradeTooHighException &e)
// 	{
// 		std::cerr << "Execption caught: " << e.what() << std::endl;
// 	}
// 	catch (const Bureaucrat::GradeTooLowException &e)
// 	{
// 		std::cerr << "Execption caught: " << e.what() << std::endl;
// 	}
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     return (0);
// }

//Test 3
// int	main(void)
// {
// 	try
// 	{
// 		Bureaucrat smart1("TOP G", 35);
// 		Bureaucrat smart4("BUGATTI", 76);
// 		Bureaucrat smart3("FLORIN", 149);
// 		std::cout << smart1;
// 		std::cout << smart3;
// 		std::cout << smart4;

// 		smart1.decrementGrade();
// 		while (smart1.GetGrade() < 150 || smart4.GetGrade() > 1 || smart3.GetGrade() > 1)
// 		{
//             if (smart1.GetGrade() + 1 < 150)
//             {
// 			    smart1.decrementGrade();
//             }
//             if (smart4.GetGrade() - 1 > 1)
//             {
// 			    smart4.incrementGrade();
//             }
//             if (smart3.GetGrade() - 1 > 1)
//             {
// 			    smart3. incrementGrade();
//             }
//             else
//             {
//                 break;
//             }
// 		}
//         std::cout << smart1;
//         std::cout << smart3;
//         std::cout << smart4;
// 		// smart1.decrementGrade();
//         // uncoment to see exception beeing corectly caught
// 	}
// 	catch (const Bureaucrat::GradeTooHighException &e)
// 	{
// 		std::cerr << "Execption caught: " << e.what() << std::endl;
// 	}
// 	catch (const Bureaucrat::GradeTooLowException &e)
// 	{
// 		std::cerr << "Execption caught: " << e.what() << std::endl;
// 	}
//     return (0);
// }
