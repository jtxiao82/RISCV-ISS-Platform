#include "ac_fi.H"


template <typename T>
ac_fi<T>::ac_fi(): activate_fi_permanent(false), random_bit(0), instr_format_index(0), instr_cnt(0) {}

template <typename T>
const int ac_fi<T>::instr_size[instr_num][max_reg_num] = {
  {Type_R_funct7_sz, Type_R_funct5_sz, Type_R_aq_sz, Type_R_rl_sz, Type_R_rs2_sz, Type_R_rs1_sz, Type_R_funct3_sz, Type_R_rd_sz, Type_R_op_sz, 0, 0, 0}, \
  {Type_R4_rs3_sz, Type_R4_funct2_sz, Type_R4_rs2_sz, Type_R4_rs1_sz, Type_R4_funct3_sz, Type_R4_rd_sz, Type_R4_op_sz, 0, 0, 0, 0, 0}, \
  {Type_I_imm4_sz, Type_I_imm3_sz, Type_I_imm2_sz, Type_I_imm1_sz, Type_I_imm8_sz, Type_I_imm7_sz, Type_I_imm6_sz, Type_I_csr_sz, Type_I_rs1_sz, Type_I_funct3_sz, Type_I_rd_sz, Type_I_op_sz}, \
  {Type_S_imm4_sz, Type_S_imm3_sz, Type_S_rs2_sz, Type_S_rs1_sz, Type_S_funct3_sz, Type_S_imm2_sz, Type_S_imm1_sz, Type_S_op_sz, 0, 0, 0, 0}, \
  {Type_SB_imm4_sz, Type_SB_imm2_sz, Type_SB_rs2_sz, Type_SB_rs1_sz, Type_SB_funct3_sz, Type_SB_imm1_sz, Type_SB_imm3_sz, Type_SB_op_sz, 0, 0, 0, 0}, \
  {Type_U_imm_sz, Type_U_rd_sz, Type_U_op_sz, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
  {Type_UJ_imm4_sz, Type_UJ_imm1_sz, Type_UJ_imm2_sz, Type_UJ_imm3_sz, Type_UJ_rd_sz, Type_UJ_op_sz, 0, 0, 0, 0, 0, 0}
};


template <typename T>
void ac_fi<T>::fi_bf(long fi_index, unsigned size, unsigned fi_bit, /*uint32_t*/T *reg) {
      unsigned fi_bytepos = fi_bit / 8;
      unsigned fi_bitpos = fi_bit % 8;
      reg[fi_bytepos] ^= 0x1 << fi_bitpos;
}

template <typename T>
void ac_fi<T>::select_fi(long fi_id, T *Data/*, unsigned fi_type*/) {
  #ifdef FI
  int byte = 8;
  unsigned size = byte * sizeof(T);

  std::srand(time(0));
  if(!activate_fi_permanent) {
    random_bit = std::rand() % size/*byte*/;
    //cerr << random_bit << endl;
  } else {
    cerr << "PC = " << *Data << endl;
    fi_bf(fi_id, size, random_bit, Data);   
    cerr << "After FI, PC = " << *Data << ", Bit pos = " << random_bit << endl;
  }
  activate_fi_permanent = true;
  #endif
}

template <typename T>
void ac_fi<T>::select_fi(riscv_type::DecCacheItem* instr_dec) {

  #ifdef INSTR_FI

  /*
  * Generator fault inject instruction type, register type, bit position randomly
  */
  std::srand(time(0));
  int random_instr_type = std::rand() % 7;
  int random_reg_type = 0;
  int random_bit = 0;
  switch(random_instr_type) {
    case 1:
      random_reg_type = std::rand() % Type_R_Num;
    break;
    case 2:
      random_reg_type = std::rand() % Type_R4_Num;
    break;
    case 3:
      random_reg_type = std::rand() % Type_I_Num;
    break;
    case 4:
      random_reg_type = std::rand() % Type_S_Num;
    break;
    case 5:
      random_reg_type = std::rand() % Type_SB_Num;
    break;
    case 6:
      random_reg_type = std::rand() % Type_U_Num;
    break;
    case 7:
      random_reg_type = std::rand() % Type_UJ_Num;
    break;
  }

  size_t instr_id = random_instr_type;
  size_t reg_id = random_reg_type;
  random_bit = instr_size[instr_id][reg_id];
   
  cerr << "instr_id " << instr_id << ", reg_id " << reg_id << ", random_bit " << random_bit << endl;

  select_instr(1, random_instr_type, random_reg_type, random_bit, instr_dec);

  #endif
}


template <typename T>
void ac_fi<T>::select_instr(long fi_index, unsigned instr_type, unsigned reg_type, unsigned fi_bit, riscv_type::DecCacheItem* instr_dec) {

  switch(instr_type) {
    case 1: {
       switch(reg_type) {
        case 1: {
          fi_bf(fi_index, Type_R_funct7_sz/*size*/, fi_bit, &instr_dec->F_Type_R.funct7);
          break;
        } 
        case 2: {
          fi_bf(fi_index, Type_R_funct5_sz/*size*/, fi_bit, &instr_dec->F_Type_R.funct5);
          break;
        }     
        case 3: {
          fi_bf(fi_index, Type_R_aq_sz/*size*/, fi_bit, &instr_dec->F_Type_R.aq);
          break;
        }     
        case 4: {
          fi_bf(fi_index, Type_R_rl_sz/*size*/, fi_bit, &instr_dec->F_Type_R.rl);
          break;
        }
        case 5: {
          fi_bf(fi_index, Type_R_rs2_sz/*size*/, fi_bit, &instr_dec->F_Type_R.rs2);
          break;
        }
        case 6: {
          fi_bf(fi_index, Type_R_funct3_sz/*size*/, fi_bit, &instr_dec->F_Type_R.funct3);
          break;
        }
        case 7: {
          fi_bf(fi_index, Type_R_rd_sz/*size*/, fi_bit, &instr_dec->F_Type_R.rd);
          break;
        }
        case 8: {
          fi_bf(fi_index, Type_R_op_sz/*size*/, fi_bit, &instr_dec->F_Type_R.op);
          break;
        }
      }    
      break;
    }
    case 2: {
      switch(reg_type) {
        case 1: {
          fi_bf(fi_index, Type_R4_rs3_sz/*size*/, fi_bit, &instr_dec->F_Type_R4.rs3);
          break;
        } 
        case 2: {
          fi_bf(fi_index, Type_R4_funct2_sz/*size*/, fi_bit, &instr_dec->F_Type_R4.funct2);
          break;
        }     
        case 3: {
          fi_bf(fi_index, Type_R4_rs2_sz/*size*/, fi_bit, &instr_dec->F_Type_R4.rs2);
          break;
        }     
        case 4: {
          fi_bf(fi_index, Type_R4_funct3_sz/*size*/, fi_bit, &instr_dec->F_Type_R4.funct3);
          break;
        }
        case 5: {
          fi_bf(fi_index, Type_R4_rd_sz/*size*/, fi_bit, &instr_dec->F_Type_R4.rd);
          break;
        }
        case 6: {
          fi_bf(fi_index, Type_R4_op_sz/*size*/, fi_bit, &instr_dec->F_Type_R4.op);
          break;
        }
      }
      break;
    }
    case 3: {
      switch(reg_type) {
        case 1: {
          fi_bf(fi_index, Type_I_imm4_sz/*size*/, fi_bit, &instr_dec->F_Type_I.imm4);
          break;
        } 
        case 2: {
          fi_bf(fi_index, Type_I_imm3_sz/*size*/, fi_bit, &instr_dec->F_Type_I.imm3);
          break;
        }     
        case 3: {
          fi_bf(fi_index, Type_I_imm2_sz/*size*/, fi_bit, &instr_dec->F_Type_I.imm2);
          break;
        }     
        case 4: {
          fi_bf(fi_index, Type_I_imm1_sz/*size*/, fi_bit, &instr_dec->F_Type_I.imm1);
          break;
        }     
        case 5: {
          fi_bf(fi_index, Type_I_imm8_sz/*size*/, fi_bit, &instr_dec->F_Type_I.imm8);
          break;
        }     
        case 6: {
          fi_bf(fi_index, Type_I_imm7_sz/*size*/, fi_bit, &instr_dec->F_Type_I.imm7);
          break;
        }     
        case 7: {
          fi_bf(fi_index, Type_I_imm6_sz/*size*/, fi_bit, &instr_dec->F_Type_I.imm6);
          break;
        }
        case 8: {
          fi_bf(fi_index, Type_I_csr_sz/*size*/, fi_bit, &instr_dec->F_Type_I.csr);
          break;
        }
        case 9: {
          fi_bf(fi_index, Type_I_rs1_sz/*size*/, fi_bit, &instr_dec->F_Type_I.rs1);
          break;
        }
        case 10: {
          fi_bf(fi_index, Type_I_funct3_sz/*size*/, fi_bit, &instr_dec->F_Type_I.funct3);
          break;
        }
        case 11: {
          fi_bf(fi_index, Type_I_rd_sz/*size*/, fi_bit, &instr_dec->F_Type_I.rd);
          break;
        }
        case 12: {
           fi_bf(fi_index, Type_I_op_sz/*size*/, fi_bit, &instr_dec->F_Type_I.op);
          break;
        }
      }
      break;
    }
    case 4: {
      switch(reg_type) {
        case 1: {
          fi_bf(fi_index, Type_S_imm4_sz/*size*/, fi_bit, &instr_dec->F_Type_S.imm4);
          break;
        } 
        case 2: {
          fi_bf(fi_index, Type_S_imm3_sz/*size*/, fi_bit, &instr_dec->F_Type_S.imm3);
          break;
        }     
        case 3: {
          fi_bf(fi_index, Type_S_rs2_sz/*size*/, fi_bit, &instr_dec->F_Type_S.rs2);
          break;
        }     
        case 4: {
          fi_bf(fi_index, Type_S_rs1_sz/*size*/, fi_bit, &instr_dec->F_Type_S.rs1);
          break;
        }     
        case 5: {
          fi_bf(fi_index, Type_S_funct3_sz/*size*/, fi_bit, &instr_dec->F_Type_S.funct3);
          break;
        }     
        case 6: {
          fi_bf(fi_index, Type_S_imm2_sz/*size*/, fi_bit, &instr_dec->F_Type_S.imm2);
          break;
        }     
        case 7: {
          fi_bf(fi_index, Type_S_imm1_sz/*size*/, fi_bit, &instr_dec->F_Type_S.imm1);
          break;
        }
        case 8: {
          fi_bf(fi_index, Type_S_op_sz/*size*/, fi_bit, &instr_dec->F_Type_S.op);
          break;
        }
      }
      break;
    }
    case 5: {
      switch(reg_type) {
        case 1: {
          fi_bf(fi_index, Type_SB_imm4_sz/*size*/, fi_bit, &instr_dec->F_Type_SB.imm4);
          break;
        } 
        case 2: {
          fi_bf(fi_index, Type_SB_imm2_sz/*size*/, fi_bit, &instr_dec->F_Type_SB.imm2);
          break;
        }     
        case 3: {
          fi_bf(fi_index, Type_SB_rs2_sz/*size*/, fi_bit, &instr_dec->F_Type_SB.rs2);
          break;
        }     
        case 4: {
          fi_bf(fi_index, Type_SB_rs1_sz/*size*/, fi_bit, &instr_dec->F_Type_SB.rs1);
          break;
        }     
        case 5: {
          fi_bf(fi_index, Type_SB_funct3_sz/*size*/, fi_bit, &instr_dec->F_Type_SB.funct3);
          break;
        }     
        case 6: {
          fi_bf(fi_index, Type_SB_imm1_sz/*size*/, fi_bit, &instr_dec->F_Type_SB.imm1);
          break;
        }     
        case 7: {
          fi_bf(fi_index, Type_SB_imm3_sz/*size*/, fi_bit, &instr_dec->F_Type_SB.imm3);
          break;
        }
        case 8: {
          fi_bf(fi_index, Type_SB_op_sz/*size*/, fi_bit, &instr_dec->F_Type_SB.op);
          break;
        }
      }   
      break;
    }
    case 6: {
      switch(reg_type) {
        case 1: {
          fi_bf(fi_index, Type_U_imm_sz/*size*/, fi_bit, &instr_dec->F_Type_U.imm);
          break;
        } 
        case 2: {
          fi_bf(fi_index, Type_U_rd_sz/*size*/, fi_bit, &instr_dec->F_Type_U.rd);
          break;
        }     
        case 3: {
          fi_bf(fi_index, Type_U_op_sz/*size*/, fi_bit, &instr_dec->F_Type_U.op);
          break;
        }     
      }   
      break;
    }
    case 7: {
       switch(reg_type) {
        case 1: {
          fi_bf(fi_index, Type_UJ_imm4_sz/*size*/, fi_bit, &instr_dec->F_Type_UJ.imm4);
          break;
        } 
        case 2: {
          fi_bf(fi_index, Type_UJ_imm1_sz/*size*/, fi_bit, &instr_dec->F_Type_UJ.imm1);
          break;
        }     
        case 3: {
          fi_bf(fi_index, Type_UJ_imm2_sz/*size*/, fi_bit, &instr_dec->F_Type_UJ.imm2);
          break;
        }     
        case 4: {
          fi_bf(fi_index, Type_UJ_imm3_sz/*size*/, fi_bit, &instr_dec->F_Type_UJ.imm3);
          break;
        }
        case 5: {
          fi_bf(fi_index, Type_UJ_rd_sz/*size*/, fi_bit, &instr_dec->F_Type_UJ.rd);
          break;
        }
        case 6: {
          fi_bf(fi_index, Type_UJ_op_sz/*size*/, fi_bit, &instr_dec->F_Type_UJ.op);
          break;
        }
      }  
      break;
    }
  }
}
