#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void    add(PhoneBook &phone_book)
{
    static int  i = 0;
    std::string user_input; //TODO: check if it's input is empty in this funciotn

    std::cout << "NEW CONTACT\n";
    std::cin.ignore(); // FIXME: it fucks up if there's 2 spaces
    std::cin.clear();

    std::cout << "First name:";
    getline(std::cin, user_input);
    phone_book.contacts[i].set_first_name(user_input);
    user_input.clear();

    std::cout << "Last name:";
    getline(std::cin, user_input);
    phone_book.contacts[i].set_last_name(user_input);
    user_input.clear();

    std::cout << "Nickname:";
    getline(std::cin, user_input);
    phone_book.contacts[i].set_nick_name(user_input);
    user_input.clear();

    std::cout << "Phone number:";
    getline(std::cin, user_input);
    phone_book.contacts[i].set_phone_number(user_input);
    user_input.clear();

    std::cout << "Darkest secret:";
    getline(std::cin, user_input);
    phone_book.contacts[i].set_darkest_secret(user_input);
    user_input.clear();

    i++;
    if (i == 8)
        i = 0;
}

std::string format_string(std::string input)
{
    std::string copy;

    copy = input;
    copy[9] = '.';
    copy = copy.substr(0, 10);
    return (copy);
}

bool    display_contacts(PhoneBook phone_book)
{
    int         field_w;
    std::string output;

    field_w = 10;
    std::cout   << "---------------------------------------------\n"; //TODO: are we allowed to use non ASCII characters?
    std::cout   << "|" << "   Index  |" << "First name|"
                << "Last  name|" << " Nickname |";
    if (phone_book.contacts[0].name_is_empty())
    {
        std::cout << "\n---------------------------------------------\n";
        return (false);
    }
    for (int i = 0; i <= 7; i++)
    {
        if (phone_book.contacts[i].name_is_empty())
        {
            std::cout << "Buggy bug " << i << "\n";
            break ;
        }
    
        std::cout << "\n---------------------------------------------\n";
        std::cout << "|" << std::right << std::setw(field_w) << i;

        if (phone_book.contacts[i].get_first_name().size() > 10)
            output = format_string(phone_book.contacts[i].get_first_name());
        else
            output = phone_book.contacts[i].get_first_name();
        std::cout << "|" << std::right << std::setw(field_w) << output;

        if (phone_book.contacts[i].get_last_name().size() > 10)
            output = format_string(phone_book.contacts[i].get_last_name());
        else 
            output = phone_book.contacts[i].get_last_name();
        std::cout << "|" << std::right << std::setw(field_w) << output;

        if (phone_book.contacts[i].get_nick_name().size() > 10)
            output = format_string(phone_book.contacts[i].get_nick_name());
        else 
            output = phone_book.contacts[i].get_nick_name();
        std::cout << "|" << std::right << std::setw(field_w) << output << "|";
    }
    return (true);
    // std::cout << "\n---------------------------------------------\n";
}

void    search(PhoneBook phone_book)
{
    int index;

    index = 0;
    if (!display_contacts(phone_book))
        return ;
    std::cout << "ENTER THE INDEX: ";
    std::cin >> index;

    if (index < 0 || index > 7)
    {
        std::cout << "Wrong index!!\n"; //TODO:red
        std::cout << "Please choose an index between 0 and 7\n";
        return ;
    }
    for (int i = 0; i <= 7; i++)
    {
        if (i == index)
        {
            std::cout   << phone_book.contacts[i].get_first_name() << "\n"
                        << phone_book.contacts[i].get_last_name() << "\n"
                        << phone_book.contacts[i].get_nick_name() << "\n"
                        << phone_book.contacts[i].get_phone_number() << "\n"
                        << phone_book.contacts[i].get_darkest_secret() << "\n";
        }
    }
}