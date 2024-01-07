#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
private:
    std::string _type;

public:
    ATarget(const std::string &type);
    virtual ~ATarget();

    const std::string &getType() const;

    virtual ATarget *clone() const;

    void getHitBySpell(const ASpell &spell) const;
};