#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(Brain const &other);
    Brain &operator=(Brain const &other);
    ~Brain();

    Brain *getIdeas(std::string *ideas);
    void setIdeas(const std::string &ideas, int index);
};

#endif