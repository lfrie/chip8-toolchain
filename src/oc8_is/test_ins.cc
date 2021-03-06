#include <catch2/catch.hpp>
#include <cstdint>
#include <string>

#include "oc8_is/ins.h"

#define OPCODE_SWAP(X) ((X << 8) | (X >> 8))

namespace {

void decode_op(oc8_is_ins_t *ins, const std::string &opcode) {
  uint16_t op16 = std::stoi(opcode, nullptr, 16);
  // need to swap to big-endian
  op16 = OPCODE_SWAP(op16);
  oc8_is_decode_ins(ins, (const char *)&op16);
}

} // namespace

TEST_CASE("Ins 0: 0NNN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "0B9D");
  REQUIRE(ins.type == OC8_IS_TYPE_0NNN);
  REQUIRE(ins.operands[0] == 0xB9D);
}

TEST_CASE("Ins 1: 00E0", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "00E0");
  REQUIRE(ins.type == OC8_IS_TYPE_00E0);
}

TEST_CASE("Ins 2: 00EE", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "00EE");
  REQUIRE(ins.type == OC8_IS_TYPE_00EE);
}

TEST_CASE("Ins 3: 1NNN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "17BE");
  REQUIRE(ins.type == OC8_IS_TYPE_1NNN);
  REQUIRE(ins.operands[0] == 0x7BE);
}

TEST_CASE("Ins 4: 2NNN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "20F8");
  REQUIRE(ins.type == OC8_IS_TYPE_2NNN);
  REQUIRE(ins.operands[0] == 0x0F8);
}

TEST_CASE("Ins 5: 3XNN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "37A8");
  REQUIRE(ins.type == OC8_IS_TYPE_3XNN);
  REQUIRE(ins.operands[0] == 7);
  REQUIRE(ins.operands[1] == 0xA8);
}

TEST_CASE("Ins 6: 4XNN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "4281");
  REQUIRE(ins.type == OC8_IS_TYPE_4XNN);
  REQUIRE(ins.operands[0] == 2);
  REQUIRE(ins.operands[1] == 0x81);
}

TEST_CASE("Ins 7: 5XY0", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "5B70");
  REQUIRE(ins.type == OC8_IS_TYPE_5XY0);
  REQUIRE(ins.operands[0] == 0xB);
  REQUIRE(ins.operands[1] == 0x7);
}

TEST_CASE("Ins 8: 6XNN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "6E2C");
  REQUIRE(ins.type == OC8_IS_TYPE_6XNN);
  REQUIRE(ins.operands[0] == 0xE);
  REQUIRE(ins.operands[1] == 0x2c);
}

TEST_CASE("Ins 9: 7XNN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "7FED");
  REQUIRE(ins.type == OC8_IS_TYPE_7XNN);
  REQUIRE(ins.operands[0] == 0xF);
  REQUIRE(ins.operands[1] == 0xED);
}

TEST_CASE("Ins 10: 8XY0", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "84E0");
  REQUIRE(ins.type == OC8_IS_TYPE_8XY0);
  REQUIRE(ins.operands[0] == 0x4);
  REQUIRE(ins.operands[1] == 0xE);
}

TEST_CASE("Ins 11: 8XY1", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "84E1");
  REQUIRE(ins.type == OC8_IS_TYPE_8XY1);
  REQUIRE(ins.operands[0] == 0x4);
  REQUIRE(ins.operands[1] == 0xE);
}

TEST_CASE("Ins 12: 8XY2", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "84E2");
  REQUIRE(ins.type == OC8_IS_TYPE_8XY2);
  REQUIRE(ins.operands[0] == 0x4);
  REQUIRE(ins.operands[1] == 0xE);
}

TEST_CASE("Ins 13: 8XY3", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "84E3");
  REQUIRE(ins.type == OC8_IS_TYPE_8XY3);
  REQUIRE(ins.operands[0] == 0x4);
  REQUIRE(ins.operands[1] == 0xE);
}

TEST_CASE("Ins 14: 8XY4", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "87E4");
  REQUIRE(ins.type == OC8_IS_TYPE_8XY4);
  REQUIRE(ins.operands[0] == 0x7);
  REQUIRE(ins.operands[1] == 0xE);
}

TEST_CASE("Ins 16: 8XY5", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "87E5");
  REQUIRE(ins.type == OC8_IS_TYPE_8XY5);
  REQUIRE(ins.operands[0] == 0x7);
  REQUIRE(ins.operands[1] == 0xE);
}

TEST_CASE("Ins 16: 8XY6", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "87E6");
  REQUIRE(ins.type == OC8_IS_TYPE_8XY6);
  REQUIRE(ins.operands[0] == 0x7);
  REQUIRE(ins.operands[1] == 0xE);
}

TEST_CASE("Ins 17: 8XY7", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "8B47");
  REQUIRE(ins.type == OC8_IS_TYPE_8XY7);
  REQUIRE(ins.operands[0] == 0xB);
  REQUIRE(ins.operands[1] == 0x4);
}

TEST_CASE("Ins 18: 8XYE", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "87CE");
  REQUIRE(ins.type == OC8_IS_TYPE_8XYE);
  REQUIRE(ins.operands[0] == 0x7);
  REQUIRE(ins.operands[1] == 0xC);
}

TEST_CASE("Ins 19: 9XY0", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "9480");
  REQUIRE(ins.type == OC8_IS_TYPE_9XY0);
  REQUIRE(ins.operands[0] == 0x4);
  REQUIRE(ins.operands[1] == 0x8);
}

TEST_CASE("Ins 20: ANNN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "A3BE");
  REQUIRE(ins.type == OC8_IS_TYPE_ANNN);
  REQUIRE(ins.operands[0] == 0x3BE);
}

TEST_CASE("Ins 21: BNNN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "B3CE");
  REQUIRE(ins.type == OC8_IS_TYPE_BNNN);
  REQUIRE(ins.operands[0] == 0x3CE);
}

TEST_CASE("Ins 22: CXNN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "C38E");
  REQUIRE(ins.type == OC8_IS_TYPE_CXNN);
  REQUIRE(ins.operands[0] == 0x3);
  REQUIRE(ins.operands[1] == 0x8E);
}

TEST_CASE("Ins 23: DXYN", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "D81C");
  REQUIRE(ins.type == OC8_IS_TYPE_DXYN);
  REQUIRE(ins.operands[0] == 0x8);
  REQUIRE(ins.operands[1] == 0x1);
  REQUIRE(ins.operands[2] == 0xC);
}

TEST_CASE("Ins 24: EX9E", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "E69E");
  REQUIRE(ins.type == OC8_IS_TYPE_EX9E);
  REQUIRE(ins.operands[0] == 0x6);
}

TEST_CASE("Ins 25: EXA1", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "E6A1");
  REQUIRE(ins.type == OC8_IS_TYPE_EXA1);
  REQUIRE(ins.operands[0] == 0x6);
}

TEST_CASE("Ins 26: FX07", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "F607");
  REQUIRE(ins.type == OC8_IS_TYPE_FX07);
  REQUIRE(ins.operands[0] == 0x6);
}

TEST_CASE("Ins 27: FX0A", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "F60A");
  REQUIRE(ins.type == OC8_IS_TYPE_FX0A);
  REQUIRE(ins.operands[0] == 0x6);
}

TEST_CASE("Ins 28: FX15", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "F615");
  REQUIRE(ins.type == OC8_IS_TYPE_FX15);
  REQUIRE(ins.operands[0] == 0x6);
}

TEST_CASE("Ins 29: FX18", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "F618");
  REQUIRE(ins.type == OC8_IS_TYPE_FX18);
  REQUIRE(ins.operands[0] == 0x6);
}

TEST_CASE("Ins 30: FX1E", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "F61E");
  REQUIRE(ins.type == OC8_IS_TYPE_FX1E);
  REQUIRE(ins.operands[0] == 0x6);
}

TEST_CASE("Ins 31: FX29", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "F629");
  REQUIRE(ins.type == OC8_IS_TYPE_FX29);
  REQUIRE(ins.operands[0] == 0x6);
}

TEST_CASE("Ins 32: FX33", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "F633");
  REQUIRE(ins.type == OC8_IS_TYPE_FX33);
  REQUIRE(ins.operands[0] == 0x6);
}

TEST_CASE("Ins 33: FX55", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "F655");
  REQUIRE(ins.type == OC8_IS_TYPE_FX55);
  REQUIRE(ins.operands[0] == 0x6);
}

TEST_CASE("Ins 34: FX65", "") {
  oc8_is_ins_t ins;
  decode_op(&ins, "FA65");
  REQUIRE(ins.type == OC8_IS_TYPE_FX65);
  REQUIRE(ins.operands[0] == 0xA);
}
