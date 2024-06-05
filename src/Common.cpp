#include "Common.h"

#include <cstdint>
#include<unordered_set>
namespace qcheckpoint {

namespace dataHelper {
using BasicBlockSet=std::unordered_set<uint64_t>;
class DataHelper {
   public:
    const IdToReg &getIdToReg() {return idToReg_;}
    uint64_t getReg(const std::string &id) {return idToReg_[id];}
    void updateReg(const std::string &id, uint64_t val) {idToReg_[id]=val;}

    const AddrToData &getMemory() {return addrToData_;}
    // Because TB can be translated again, so we need filter same basic block before calling,
    void updateMemory(const BasicBlock &baiscBlock) {
        for(const auto &inst:baiscBlock.insts) {
            updateMemory(inst.opcode,inst.vaddr);
        }
    }
    void updateMemory(const MemoryAccess &memoryAccess) {
        updateMemory(memoryAccess.data,memoryAccess.vaddr);
    }

   private:
    IdToReg idToReg_;
    AddrToData addrToData_;

    void updateMemory(const std::vector<uint8_t> &dataVec,uint64_t vaddr) {
        for(auto i=0;i<dataVec.size();i++) {
            auto offset = vaddr % DATA_ALIGN;
            auto &data = addrToData_[vaddr-offset];
            data = deposit64(data,offset,8,dataVec[i]);
        }
    }
};
static DataHelper dataHelper;
const IdToReg &getIdToReg() {
    return dataHelper.getIdToReg();
}
uint64_t getReg(const std::string &id) {
    return dataHelper.getReg(id);
}
void updateReg(const std::string &id, uint64_t val) {
    dataHelper.updateReg(id, val);
}

const AddrToData &getMemory() {
    return dataHelper.getMemory();
}
void updateMemory(const BasicBlock &baiscBlock) {
    dataHelper.updateMemory(baiscBlock);
}
void updateMemory(const MemoryAccess &memoryAccess) {
    dataHelper.updateMemory(memoryAccess);
}
}  // namespace dataHelper
}  // namespace qcheckpoint