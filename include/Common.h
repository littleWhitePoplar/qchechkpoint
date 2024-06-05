#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>
namespace qcheckpoint {
constexpr auto DATA_ALIGN = 8;
struct Inst {
    uint64_t vaddr = 0;
    uint64_t paddr = 0;
    std::vector<uint8_t> opcode;
    std::string disassembly;
    std::string symbol;
};
struct BasicBlock {
    uint64_t vaddr = 0;
    uint64_t paddr = 0;
    std::vector<Inst> insts;
};
struct MemoryAccess {
    Inst *inst = nullptr;
    uint64_t vaddr = 0;
    uint64_t paddr = 0;
    std::vector<uint8_t> data;
    bool signExtend = false;
    bool bigEndian = false;
    bool store = false;
};

using IdToReg=std::unordered_map<std::string,uint64_t>;
using AddrToData=std::unordered_map<uint64_t,uint64_t>;

namespace dataHelper {
static inline uint64_t deposit64(uint64_t value, int start, int length,
                                 uint64_t fieldval)
{
    uint64_t mask;
    mask = (~0ULL >> (64 - length)) << start;
    return (value & ~mask) | ((fieldval << start) & mask);
}
const IdToReg &getIdToReg();
uint64_t getReg(const std::string &id);
void updateReg(const std::string &id,uint64_t val);

const AddrToData &getMemory();
void updateMemory(const BasicBlock &baiscBlock);
void updateMemory(const MemoryAccess &memoryAccess);
}
}  // namespace qcheckpoint