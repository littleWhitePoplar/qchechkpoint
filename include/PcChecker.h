#pragma once
#include "Checker.h"
namespace qcheckpoint {

class PcChecker : Checker {
   public:
    PcChecker(uint64_t pc) : pc_(pc) {}
    virtual bool isCheckpoint(const BasicBlock &baiscBlock) override;

   private:
    uint64_t pc_ = 0;
};
}  // namespace qcheckpoint