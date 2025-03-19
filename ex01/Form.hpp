#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
	const std::string _name;
	bool _signed;
	const int _grade_to_sign;
	const int _grade_to_execute;

  public:
	Form();
	Form(const std::string name, const int grade_to_sign,
		const int grade_to_execute);
	Form(const Form &copy);
	Form &operator=(const Form &assign);
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	bool beSigned(const Bureaucrat &bureaucrat);
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getName() const;
	bool getSignature() const;
	void setSignature(bool signature);
    ~Form();
};

std::ostream &operator<<(std::ostream &out, const Form &obj);
