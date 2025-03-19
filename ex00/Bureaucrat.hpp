#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <stdexcept>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &assign);
    class GradeTooHighException : public std::exception{

        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            const char* what() const throw();
    };
    void setGrade(int grade) ;
    void incrementGrade(void) ;
    void decrementGrade(void) ;
    std::string GetName(void) const;
    int GetGrade(void) const;
    ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);
