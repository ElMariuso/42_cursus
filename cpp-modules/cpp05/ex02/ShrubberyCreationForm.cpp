/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:23:26 by root              #+#    #+#             */
/*   Updated: 2022/10/22 01:09:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Form", 145, 137)
{
    this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs): Form(rhs)
{
    *this = rhs;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    this->setTarget(rhs.getTarget());
    return (*this);
}

/* Functions */

void    ShrubberyCreationForm::setTarget(std::string target)
{
    this->_target = target;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::ofstream   out;
    std::string file;

    file = getTarget();
    file.append("_shrubbery");

    const char    *c_file = file.c_str();
    
    out.open(c_file);
    if (out)
    {
        out << "            .        +          .      .          ." << std::endl;
		out << "     .            _        .                    ." << std::endl;
		out << "  ,              /;-._,-.____        ,-----.__" << std::endl;
		out << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
		out << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
		out << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
		out << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
		out << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
		out << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
		out << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
		out << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
		out << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
		out << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
		out << "                    \\::.  :\\/:'  /              +" << std::endl;
		out << "   .                 `.:.  /:'  }      ." << std::endl;
		out << "           .           ):_(:;   \\           ." << std::endl;
		out << "                      /:. _/ ,  |" << std::endl;
		out << "                   . (|::.     ,`                  ." << std::endl;
		out << "     .                |::.    {\\" << std::endl;
		out << "                      |::.\\  \\ `." << std::endl;
		out << "                      |:::(\\    |" << std::endl;
		out << "              O       |:::/{ }  |                  (o" << std::endl;
		out << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
		out << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
		out << "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~" << std::endl;
        std::cout << "Shrubbery tree created by " << executor.getName() << std::endl;
    }
    else
        std::cout << "Shrubbery tree couldn't be created by " << executor.getName() << " because the target file couldn't be open" << std::endl;
}