#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator {
public:
  TargetGenerator();
  ~TargetGenerator();

  void learnTargetType(ATarget *target);
  void forgetTargetType(std::string const &target);
  ATarget *createTarget(std::string const &target);

private:
  TargetGenerator(const TargetGenerator &copy);
  TargetGenerator &operator=(const TargetGenerator &copy);

private:
  std::map<std::string, ATarget *> targets;
};