#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
    /* Methods */
    public:
        Contact(); // Constructor
        ~Contact(); // Destructor
        /* Functions */
        void    set_index(int index);
        void    set_infos(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
        void    display_infos() const;
        void    alt_display_infos() const;
    
    /* Attributes */
    private:
        int         index;
        bool        is_empty;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

#endif