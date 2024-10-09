#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap& operator=(const FragTrap& other);
    FragTrap(const FragTrap& other);
    ~FragTrap();

    void highFivesGuys(void);
};

#endif