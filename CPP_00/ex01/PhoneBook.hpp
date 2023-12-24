#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "my_awesome_phonebook.hpp"
#include "Contact.hpp"

#define GREEN 	"\033[32m"
#define BLUE    "\033[34m"
#define RED 	"\033[31m"
#define YELLOW 	"\x1b[33m"
#define CYAN 	"\x1b[36m"
#define PURPLE 	"\x1b[35m"
#define RESET 	"\033[0m"

class PhoneBook
{
    private:
        Contact     contacts[8];
        std::string data[5];

    public:

        // default constructor
        PhoneBook();

        // dispays message 
        void    greeting();
        void    put_msg(std::string msg, bool no_nl, std::string color);
        void    put_msg(std::string msgs[], int size, std::string color);

        // waits sor user's input
        void    input_loop();

        // adds a new contactto the list
        void    add();

        // looks for s apecific contact
        void    search();

        // prints a table of all the contacts
        bool    display_contacts();
};

#endif