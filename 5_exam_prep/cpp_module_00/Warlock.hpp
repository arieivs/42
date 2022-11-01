#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

/*
 * Coplien's form:
 * - constructor
 * - copy constructor
 * - operator= overload
 * - destructor
 *
 * However, our Warlock cannot be:
 * - instantiated without name and title => no default constructor
 * - instatiated by copy => no copy constructor
 * - able to be copied => no opeartor= overload
*/

class Warlock {
    public:
        Warlock(std::string name, std::string title);
        ~Warlock(void);

        std::string const & getName(void) const;
        std::string const & getTitle(void) const;
        void                setTitle(std::string const & new_title);
    
    private:
        std::string name;
        std::string title;
};

#endif