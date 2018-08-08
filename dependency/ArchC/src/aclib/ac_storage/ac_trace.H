/*
*
* @file        ac_trace.H
* @version     1.0
* @author      Jiang Tang
*
* @date        Feb 2018
* @brief       The ArchC RISC-V functional model
*
*
*/

#ifndef _AC_TRACE_H
#define _AC_TRACE_H

#include <iostream>
#include <bitset>
#include <iomanip>
#include "/home/jtxiao/NTHU/Research/GitHub/riscv/riscv_type.H"

using std::cerr;
using std::endl;
using std::bitset;

using namespace riscv_type;

template <typename T> class ac_trace {

  private:
    int instr_format_index;
    int instr_cnt;

  public:
 
    //ac_instr_trace();
 
    virtual void trace_instr_format(int instr_format) {
      #ifdef INSTR_TRACE
      cerr << /*instr_format <<*/ endl;
      #endif
      instr_format_index = instr_format;
    }

    virtual void trace_instr(riscv_type::DecCacheItem* instr_dec) {

      ++instr_cnt;
    
      switch(instr_format_index) {
        case 1: {
          #if defined(R_TRACE) || defined(INSTR_TRACE)
          cerr << "Instr" << instr_cnt << ": " << "R-Type" << endl;
          cerr << "funct7: " << static_cast<int>(instr_dec->F_Type_R.funct7) << setw(1) \
               << ", funct5: " << static_cast<int>(instr_dec->F_Type_R.funct5) << setw(1) \
               << ", aq: " << static_cast<int>(instr_dec->F_Type_R.aq) << setw(1) \
               << ", rl: " << static_cast<int>(instr_dec->F_Type_R.rl) << setw(1) \
               << ", rs2: " << static_cast<int>(instr_dec->F_Type_R.rs2) << setw(1) \
               << ", rs1: " << static_cast<int>(instr_dec->F_Type_R.rs1) << setw(1) \
               << ", funct3: " << static_cast<int>(instr_dec->F_Type_R.funct3) << setw(1) \
               << ", rd: " << static_cast<int>(instr_dec->F_Type_R.rd) << setw(1) \
               << ", op: " << static_cast<int>(instr_dec->F_Type_R.op) << endl;
          
          bitset<7> Type_R_funct7(/*&*/instr_dec->F_Type_R.funct7);
          bitset<5> Type_R_rs2(/*&*/instr_dec->F_Type_R.rs2);
          bitset<5> Type_R_rs1(/*&*/instr_dec->F_Type_R.rs1);
          bitset<3> Type_R_funct3(/*&*/instr_dec->F_Type_R.funct3);
          bitset<5> Type_R_rd(/*&*/instr_dec->F_Type_R.rd);
          bitset<7> Type_R_op(/*&*/instr_dec->F_Type_R.op);
    
          // Cerr Alignment
          cerr << "funct7: " << setw(10) \
               /*<< "funct5: " << setw(10) \
               << "aq: "    << setw(10) \
               << "rl: "    << setw(10) \*/
               << "rs2: "   << setw(10) \
               << "rs1: "   << setw(10) \
               << "funct3: " << setw(10) \
               << "rd: "    << setw(10) \
               << "op: "    << endl;
    
          cerr << (Type_R_funct7) << setw(11) \
               /*<< (Type_R_funct5) << setw(1) \
               << (Type_R_aq) << setw(1) \
               << (Type_R_rl) << setw(1) \*/
               << (Type_R_rs2) << setw(10) \
               << (Type_R_rs1) << setw(5) \
               << (Type_R_funct3) << setw(16) \
               << (Type_R_rd) << setw(12) \
               << (Type_R_op) << endl;
          #endif
          break;
        }
        case 2: {
    
          #if defined(R4_TRACE) || defined(INSTR_TRACE)
          cerr << "Instr" << instr_cnt << ": " << "R4-Type" << endl;
          cerr << "rs3: " << static_cast<int>(instr_dec->F_Type_R4.rs3) << setw(1) \
               << ", func2: " << static_cast<int>(instr_dec->F_Type_R4.funct2) << setw(1) \
               << ", rs2: " << static_cast<int>(instr_dec->F_Type_R4.rs2) << setw(1) \
               << ", rs1: " << static_cast<int>(instr_dec->F_Type_R4.rs1) << setw(1) \
               << ", func3: " << static_cast<int>(instr_dec->F_Type_R4.funct3) << setw(1) \
               << ", rd: " << static_cast<int>(instr_dec->F_Type_R4.rd) << setw(1) \
               << ", op: " << static_cast<int>(instr_dec->F_Type_R4.op) << endl;     
    
          bitset<5> Type_R4_rs3(/*&*/instr_dec->F_Type_R4.rs3);
          bitset<2> Type_R4_funct2(/*&*/instr_dec->F_Type_R4.funct2);
          bitset<5> Type_R4_rs2(/*&*/instr_dec->F_Type_R4.rs2);
          bitset<5> Type_R4_rs1(/*&*/instr_dec->F_Type_R4.rs1);
          bitset<3> Type_R4_funct3(/*&*/instr_dec->F_Type_R4.funct3);
          bitset<5> Type_R4_rd(/*&*/instr_dec->F_Type_R4.rd);
          bitset<7> Type_R4_op(/*&*/instr_dec->F_Type_R4.op);
    
          // Cerr Alignment
          cerr << "rs3: "    << setw(8) \
               << "func2: "    << setw(8) \
               << "rs2: "   << setw(8) \
               << "rs1: "   << setw(8) \
               << "func3: " << setw(8) \
               << "rd: "    << setw(8) \
               << "op: "    << endl;
         
          cerr << (Type_R4_rs3) << setw(3) \
               << (Type_R4_funct2) << setw(13) \
               << (Type_R4_rs2) << setw(8) \
               << (Type_R4_rs1) << setw(4) \
               << (Type_R4_funct3) << setw(13) \
               << (Type_R4_rd) << setw(10) \
               << (Type_R4_op) << endl;
          #endif
          break;
        }
        case 3: {
    
          #if defined(I_TRACE) || defined(INSTR_TRACE)
          cerr << "Instr" << instr_cnt << ": " << "I-Type" << endl;
          cerr << "imm4: " << static_cast<int>(instr_dec->F_Type_I.imm4) << setw(1) \
               << ", imm3: " << static_cast<int>(instr_dec->F_Type_I.imm3) << setw(1) \
               << ", imm2: " << static_cast<int>(instr_dec->F_Type_I.imm2) << setw(1) \
               << ", imm1: " << static_cast<int>(instr_dec->F_Type_I.imm1) << setw(1) \
               << ", imm8: " << static_cast<int>(instr_dec->F_Type_I.imm8) << setw(1) \
               << ", imm7: " << static_cast<int>(instr_dec->F_Type_I.imm7) << setw(1) \
               << ", imm6: " << static_cast<int>(instr_dec->F_Type_I.imm6) << setw(1) \
               << ", csr: " << static_cast<int>(instr_dec->F_Type_I.csr) << setw(1) \
               << ", rs1: " << static_cast<int>(instr_dec->F_Type_I.rs1) << setw(1) \
               << ", func3: " << static_cast<int>(instr_dec->F_Type_I.funct3) << setw(1) \
               << ", rd: " << static_cast<int>(instr_dec->F_Type_I.rd) << setw(1) \
               << ", op: " << static_cast<int>(instr_dec->F_Type_I.op) << endl;
    
          bitset<1> Type_I_imm4(/*&*/instr_dec->F_Type_I.imm4);
          bitset<6> Type_I_imm3(/*&*/instr_dec->F_Type_I.imm3);
          bitset<4> Type_I_imm2(/*&*/instr_dec->F_Type_I.imm2);
          bitset<1> Type_I_imm1(/*&*/instr_dec->F_Type_I.imm1);
    
          // Bit width in the following 4th ?
          bitset<5> Type_I_imm8(/*&*/instr_dec->F_Type_I.imm8); 
          bitset<5> Type_I_imm7(/*&*/instr_dec->F_Type_I.imm7);
          bitset<5> Type_I_imm6(/*&*/instr_dec->F_Type_I.imm6);
          bitset<5> Type_I_csr(/*&*/instr_dec->F_Type_I.csr);
    
          bitset<5> Type_I_rs1(/*&*/instr_dec->F_Type_I.rs1);
          bitset<3> Type_I_funct3(/*&*/instr_dec->F_Type_I.funct3);
          bitset<5> Type_I_rd(/*&*/instr_dec->F_Type_I.rd);
          bitset<7> Type_I_op(/*&*/instr_dec->F_Type_I.op);
    
          // Cerr Alignment
          cerr << "imm4: "    << setw(8) \
               << "imm3: "    << setw(8) \
               << "imm2: "    << setw(8) \
               << "imm1: "    << setw(8) \
               << "imm8: "    << setw(8) \
               << "imm7: "    << setw(8) \
               << "imm6: "    << setw(8) \
               << "csr: "   << setw(8) \
               << "rs1: "   << setw(8) \
               << "func3: " << setw(8) \
               << "rd: "    << setw(8) \
               << "op: "    << endl;
    
          cerr << (Type_I_imm4) << setw(13) \
               << (Type_I_imm3) << setw(6) \
               << (Type_I_imm2) << setw(5) \
               << (Type_I_imm1) << setw(12) \
               << (Type_I_imm8) << setw(8) \
               << (Type_I_imm7) << setw(8) \
               << (Type_I_imm6) << setw(9) \
               << (Type_I_csr) << setw(8) \
               << (Type_I_rs1) << setw(4) \
               << (Type_I_funct3) << setw(13) \
               << (Type_I_rd) << setw(10) \
               << (Type_I_op) << endl;
    
          #endif
          break;
        }
        case 4: {
    
          #if defined(S_TRACE) || defined(INSTR_TRACE)
          cerr << "Instr" << instr_cnt << ": " << "S-Type" << endl;
          cerr << "imm4: " << static_cast<int>(instr_dec->F_Type_S.imm4) << setw(1) \
               << ", imm3: " << static_cast<int>(instr_dec->F_Type_S.imm3) << setw(1) \
               << ", rs2: " << static_cast<int>(instr_dec->F_Type_S.rs2) << setw(1) \
               << ", rs1: " << static_cast<int>(instr_dec->F_Type_S.rs1) << setw(1) \
               << ", func3: " << static_cast<int>(instr_dec->F_Type_S.funct3) << setw(1) \
               << ", imm2: " << static_cast<int>(instr_dec->F_Type_S.imm2) << setw(1) \
               << ", imm1: " << static_cast<int>(instr_dec->F_Type_S.imm1) << setw(1) \
               << ", op: " << static_cast<int>(instr_dec->F_Type_S.op) << endl;
    
          bitset<1> Type_S_imm4(/*&*/instr_dec->F_Type_S.imm4);
          bitset<6> Type_S_imm3(/*&*/instr_dec->F_Type_S.imm3);
          bitset<5> Type_S_rs2(/*&*/instr_dec->F_Type_S.rs2);
          bitset<5> Type_S_rs1(/*&*/instr_dec->F_Type_S.rs1);
          bitset<3> Type_S_funct3(/*&*/instr_dec->F_Type_S.funct3);
          bitset<4> Type_S_imm2(/*&*/instr_dec->F_Type_S.imm2);
          bitset<1> Type_S_imm1(/*&*/instr_dec->F_Type_S.imm1);
          bitset<7> Type_S_op(/*&*/instr_dec->F_Type_S.op);
    
          // Cerr Alignment
          cerr << "imm4: "    << setw(8) \
               << "imm3: "    << setw(8) \
               << "rs2: "   << setw(8) \
               << "rs1: "   << setw(8) \
               << "func3: " << setw(8) \
               << "imm2: "    << setw(8) \
               << "imm1: "    << setw(8) \
               << "op: "    << endl;
    
          cerr << (Type_S_imm4) << setw(13) \
               << (Type_S_imm3) << setw(8) \
               << (Type_S_rs2) << setw(8) \
               << (Type_S_rs1) << setw(4) \
               << (Type_S_funct3) << setw(10) \
               << (Type_S_imm2) << setw(5) \
               << (Type_S_imm1) << setw(16) \
               << (Type_S_op) << endl;
          #endif
          break;
        }
        case 5: {
    
          #if defined(SB_TRACE) || defined(INSTR_TRACE)
          cerr << "Instr" << instr_cnt << ": " << "SB-Type" << endl;
          cerr << "imm4: " << static_cast<int>(instr_dec->F_Type_SB.imm4) << setw(1) \
               << ", imm2: " << static_cast<int>(instr_dec->F_Type_SB.imm2) << setw(1) \
               << ", rs2: " << static_cast<int>(instr_dec->F_Type_SB.rs2) << setw(1) \
               << ", rs1: " << static_cast<int>(instr_dec->F_Type_SB.rs1) << setw(1) \
               << ", func3: " << static_cast<int>(instr_dec->F_Type_SB.funct3) << setw(1) \
               << ", imm1: " << static_cast<int>(instr_dec->F_Type_SB.imm1) << setw(1) \
               << ", imm3: " << static_cast<int>(instr_dec->F_Type_SB.imm3) << setw(1) \
               << ", op: " << static_cast<int>(instr_dec->F_Type_SB.op) << endl;
    
          bitset<1> Type_SB_imm4(/*&*/instr_dec->F_Type_SB.imm4);
          bitset<6> Type_SB_imm2(/*&*/instr_dec->F_Type_SB.imm2);
          bitset<5> Type_SB_rs2(/*&*/instr_dec->F_Type_SB.rs2);
          bitset<5> Type_SB_rs1(/*&*/instr_dec->F_Type_SB.rs1);
          bitset<3> Type_SB_funct3(/*&*/instr_dec->F_Type_SB.funct3);
          bitset<4> Type_SB_imm1(/*&*/instr_dec->F_Type_SB.imm1);
          bitset<1> Type_SB_imm3(/*&*/instr_dec->F_Type_SB.imm3);
          bitset<7> Type_SB_op(/*&*/instr_dec->F_Type_SB.op);
    
          // Cerr Alignment
          cerr << "imm4: "    << setw(8) \
               << "imm2: "    << setw(8) \
               << "rs2: "   << setw(8) \
               << "rs1: "   << setw(8) \
               << "func3: " << setw(8) \
               << "imm1: "    << setw(8) \
               << "imm3: "    << setw(8) \
               << "op: "    << endl;
    
          cerr << (Type_SB_imm4) << setw(13) \
               << (Type_SB_imm2) << setw(8) \
               << (Type_SB_rs2) << setw(8) \
               << (Type_SB_rs1) << setw(4) \
               << (Type_SB_funct3) << setw(10) \
               << (Type_SB_imm1) << setw(5) \
               << (Type_SB_imm3) << setw(16) \
               << (Type_SB_op) << endl;
    
          #endif
          break;
        }
        case 6: {
    
          #if defined(U_TRACE) || defined(INSTR_TRACE)
          cerr << "Instr" << instr_cnt << ": " << "U-Type" << endl;
          cerr << "imm: " << static_cast<int>(instr_dec->F_Type_U.imm) << setw(1) \
               << ", rd: " << static_cast<int>(instr_dec->F_Type_U.rd) << setw(1) \
               << ", op: " << static_cast<int>(instr_dec->F_Type_U.op) << endl;
    
          bitset<20> Type_U_imm(/*&*/instr_dec->F_Type_U.imm);
          bitset<5> Type_U_rd(/*&*/instr_dec->F_Type_U.rd);
          bitset<7> Type_U_op(/*&*/instr_dec->F_Type_U.op);
    
          // Cerr Alignment
          cerr << "imm: "    << setw(25) \
               << "rd: "   << setw(15) \
               << "op: "    << endl;
    
          cerr << (Type_U_imm) << setw(11) \
               << (Type_U_rd) << setw(17) \
               << (Type_U_op) << endl;
          #endif
          break;
        }
        case 7: {
    
          #if defined(UJ_TRACE) || defined(INSTR_TRACE)
          cerr << "Instr" << instr_cnt << ": " << "UJ-Type" << endl;
          cerr << "imm4: " << static_cast<int>(instr_dec->F_Type_UJ.imm4) << setw(1) \
               << ", imm1: " << static_cast<int>(instr_dec->F_Type_UJ.imm1) << setw(1) \
               << ", imm2: " << static_cast<int>(instr_dec->F_Type_UJ.imm2) << setw(1) \
               << ", imm3: " << static_cast<int>(instr_dec->F_Type_UJ.imm3) << setw(1) \
               << ", rd: " << static_cast<int>(instr_dec->F_Type_UJ.rd) << setw(1) \
               << ", op: " << static_cast<int>(instr_dec->F_Type_UJ.op) << endl;
    
          bitset<1> Type_UJ_imm4(/*&*/instr_dec->F_Type_UJ.imm4);
          bitset<10> Type_UJ_imm1(/*&*/instr_dec->F_Type_UJ.imm1);
          bitset<1> Type_UJ_imm3(/*&*/instr_dec->F_Type_UJ.imm3);
          bitset<8> Type_UJ_imm2(/*&*/instr_dec->F_Type_UJ.imm2);
          bitset<5> Type_UJ_rd(/*&*/instr_dec->F_Type_UJ.rd);
          bitset<7> Type_UJ_op(/*&*/instr_dec->F_Type_UJ.op);
    
          // Cerr Alignement
          cerr << "imm4: "    << setw(15) \
               << "imm1: "    << setw(15) \
               << "imm3: "    << setw(15) \
               << "imm2: "    << setw(15) \
               << "rd: "   << setw(15) \
               << "op: "    << endl;
         
          cerr << (Type_UJ_imm4) << setw(24) \
               << (Type_UJ_imm1) << setw(6) \
               << (Type_UJ_imm3) << setw(22) \
               << (Type_UJ_imm2) << setw(14) \
               << (Type_UJ_rd) << setw(17) \
               << (Type_UJ_op) << endl;
          #endif
          break;
        }
        //default:
      }
    }
};

#endif
