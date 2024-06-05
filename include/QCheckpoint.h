#pragma once
#include <memory>

#include "Checker.h"
#include "Recorder.h"

namespace qcheckpoint {

class QCheckpoint {
   public:
    bool isCheckpoint(const BasicBlock &basicBlock);
    void record();

   private:
    std::unique_ptr<Checker> checker_;
    std::unique_ptr<Recorder> recorder_;
};
}  // namespace qcheckpoint