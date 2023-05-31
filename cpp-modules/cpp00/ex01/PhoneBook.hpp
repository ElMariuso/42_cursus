#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
    /* Methods */
    public:
        PhoneBook(); // Constructor
        ~PhoneBook(); // Destructor
        /* Functions  */
        void    add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
        void    search_contact(char ci) const;
        void    display_contacts() const;

    /* Attributes */
    private:
        int     index;
        int     max_index;
        Contact contact[8];
};

#endif