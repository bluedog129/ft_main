#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practive Dummy") {}

Dummy::~Dummy() {}

ATarget *Dummy::clone() const {
  return (new Dummy(*this));
}