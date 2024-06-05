#include"PcChecker.h"

namespace qcheckpoint {
    bool PcChecker::isCheckpoint(const BasicBlock &baiscBlock) {
        for(const auto &inst: baiscBlock.insts) {
            if(inst.vaddr==pc_) {
                return true;
            }
        }
        return false;
    }
}