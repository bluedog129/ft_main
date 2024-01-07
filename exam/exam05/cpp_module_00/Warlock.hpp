#pragma once

#include <iostream>

class Warlock {
public:
  Warlock(const std::string &_name, const std::string &_title);
  ~Warlock();

  const std::string &getName() const;
  const std::string &getTitle() const;
  void setTitle(const std::string &_title);
  void introduce() const;

private:
  Warlock();
  Warlock(const Warlock &copy);
  Warlock &operator=(const Warlock &copy);

private:
  std::string name;
  std::string title;
};