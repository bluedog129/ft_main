#pragma once

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>
#include <map>

class Warlock {
public:
  Warlock(const std::string &_name, const std::string &_title);
  ~Warlock();

  const std::string &getName() const;
  const std::string &getTitle() const;
  void setTitle(const std::string &_title);
  void introduce() const;

  void learnSpell(ASpell *spell);
  void forgetSpell(const std::string &spell);
  void launchSpell(const std::string &spell, const ATarget &target);

private:
  Warlock();
  Warlock(const Warlock &copy);
  Warlock &operator=(const Warlock &copy);

private:
  std::string name;
  std::string title;
  std::map<std::string, ASpell *> spells;
};