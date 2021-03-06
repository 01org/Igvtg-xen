
/*
 * vpmu_core2.h: CORE 2 specific PMU virtualization for HVM domain.
 *
 * Copyright (c) 2007, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 *
 * Author: Haitao Shan <haitao.shan@intel.com>
 */

#ifndef __ASM_X86_HVM_VPMU_CORE_H_
#define __ASM_X86_HVM_VPMU_CORE_H_

/* Currently only 3 fixed counters are supported. */
#define VPMU_CORE2_NUM_FIXED 3
/* Currently only 3 Non-architectual Performance Control MSRs */
#define VPMU_CORE2_NUM_CTRLS 3

struct arch_msr_pair {
    u64 counter;
    u64 control;
};

struct core2_pmu_enable {
    char ds_area_enable;
    char fixed_ctr_enable[VPMU_CORE2_NUM_FIXED];
    char arch_pmc_enable[1];
};

struct core2_vpmu_context {
    struct core2_pmu_enable *pmu_enable;
    u64 fix_counters[VPMU_CORE2_NUM_FIXED];
    u64 ctrls[VPMU_CORE2_NUM_CTRLS];
    u64 global_ovf_status;
    struct arch_msr_pair arch_msr_pair[1];
};

#endif /* __ASM_X86_HVM_VPMU_CORE_H_ */

