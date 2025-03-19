#pragma once
#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	bool _signed;
	const int _grade_to_sign;
	const int _grade_to_execute;

  public:
	AForm();
	AForm(const std::string name, const int grade_to_sign,
		const int grade_to_execute);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &assign);
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
	class DocumentNotSignedException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class GradeTooLowExceptionExec : public std::exception{
        public:
            const char* what() const throw();
    };
	bool beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getName() const;
	bool getSignature() const;
	void setSignature(bool signature);
    virtual ~AForm();
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);
