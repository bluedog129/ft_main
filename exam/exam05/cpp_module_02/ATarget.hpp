#pragma once

#include "ASpell.hpp"

class ASpell;

class ATarget {
public:
  ATarget(const std::string &_type);
  virtual ~ATarget();

  const std::string &getType() const;

  void getHitBySpell(const ASpell &spell) const;

  virtual ATarget *clone() const = 0;

protected:
  std::string type;
};