#pragma once
#include "Common.h"
namespace qcheckpoint {

class Checker {
   public:
    virtual bool isCheckpoint(const BasicBlock &baiscBlock) = 0;
};
}  // namespace qcheckpoint