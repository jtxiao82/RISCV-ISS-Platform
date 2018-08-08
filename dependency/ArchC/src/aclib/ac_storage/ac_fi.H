/*
*
* @file        ac_fi.H
* @version     1.0
* @author      Jiang Tang
*
* @date        Feb 2018
* @brief       The ArchC RISC-V functional model
*
*
*/

#ifndef _AC_FI_H
#define _AC_FI_H

#include <iostream>
#include <stdio.h>
#include "/home/jtxiao/NTHU/Research/GitHub/riscv/riscv_type.H"

using std::cerr;
using std::endl;

using namespace riscv_type;

template <typename T> class ac_fi {

  private:
    bool activate_fi_permanent;
    unsigned random_bit;

    int instr_format_index;
    int instr_cnt;
    static const int instr_size[instr_num][max_reg_num];
  
  public: 

    ac_fi(); 

    virtual void fi_bf(long fi_index, unsigned size, unsigned fi_bit, /*uint32_t*/T *reg);

    /*************************************************************************
    Select fault inejction function in ac_reg component. For example, Program counter. Overload
    
    Modified date: 2018/02/26
    **************************************************************************/
    virtual void select_fi(long fi_id, T *Data/*, unsigned fi_type*/);  

    /*************************************************************************
    Select fault inejction function in instruction register component. Overload
    
    Modified date: 2018/02/26
    **************************************************************************/
    virtual void select_fi(riscv_type::DecCacheItem* instr_dec); 

    virtual void select_instr(long fi_index, unsigned instr_type, unsigned reg_type, unsigned fi_bit, riscv_type::DecCacheItem* instr_dec);



};

#endif
