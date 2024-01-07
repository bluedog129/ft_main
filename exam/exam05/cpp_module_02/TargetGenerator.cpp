#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
  for (std::map<std::string, ATarget *>::iterator it = targets.begin();
       it != targets.end(); it++) {
    delete it->second;
  }
}

void TargetGenerator::learnTargetType(ATarget *target) {
  if (target) {
    targets[target->getType()] = target->clone();
  }
}

void TargetGenerator::forgetTargetType(std::string const &target) {
  std::map<std::string, ATarget *>::iterator it = targets.find(target);
  if (it != targets.end()) {
    delete it->second;
    targets.erase(it);
  }
}

ATarget *TargetGenerator::createTarget(std::string const &target) {
  std::map<std::string, ATarget *>::iterator it = targets.find(target);
  if (it != targets.end()) {
    return it->second->clone();
  }
  return NULL;
}
