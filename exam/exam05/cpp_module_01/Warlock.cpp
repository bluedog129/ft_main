#include "Warlock.hpp"

Warlock::Warlock(const std::string &_name, const std::string &_title)
    : name(_name), title(_title) {
  std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
  std::cout << name << ": My job here is done!" << std::endl;
  for (std::map<std::string, ASpell *>::iterator it = spells.begin();
       it != spells.end(); it++) {
    delete it->second;
  }
}

const std::string &Warlock::getName() const { return (name); }

const std::string &Warlock::getTitle() const { return (title); }

void Warlock::setTitle(const std::string &_title) { title = _title; }

void Warlock::introduce() const {
  std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell) {
  if (spell) {
    spells[spell->getName()] = spell->clone();
  }
}

void Warlock::forgetSpell(const std::string &spell) {
  std::map<std::string, ASpell *>::iterator it = spells.find(spell);
  if (it != spells.end()) {
    delete it->second;
    spells.erase(it);
  }
}

void Warlock::launchSpell(const std::string &spell, const ATarget &target) {
  std::map<std::string, ASpell *>::iterator it = spells.find(spell);
  if (it != spells.end()) {
    it->second->launch(target);
  }
}
