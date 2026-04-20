# SPDX-License-Identifier: BSD-2-Clause

flavor_dts_file-MP15 = stm32mp157d-exercise_1_1-mx.dts
flavorlist-MP15 += $(flavor_dts_file-MP15)
flavorlist-no_cryp += $(flavor_dts_file-MP15)
CFG_DRAM_SIZE = 0x20000000
