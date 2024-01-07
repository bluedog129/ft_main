#include "Warlock.hpp"

Warlock::Warlock(const std::string &_name, const std::string &_title)
    : name(_name), title(_title) {
  std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
  std::cout << name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const { return (name); }

const std::string &Warlock::getTitle() const { return (title); }

void Warlock::setTitle(const std::string &_title) { title = _title; }

void Warlock::introduce() const {
  std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell) {
  spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string &spell) {
  spellBook.forgetSpell(spell);
}

void Warlock::launchSpell(const std::string &spell, const ATarget &target) {
  ASpell *launchSpell = spellBook.createSpell(spell);

  if (launchSpell) {
    launchSpell->launch(target);
    delete launchSpell;
  }
}
