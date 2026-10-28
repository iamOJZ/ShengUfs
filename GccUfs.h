// SPDX-License-Identifier: BSD-2-Clause-Patent
// SM8350 (lahaina / haydn) GCC registers used by UFS, transcribed as facts from
// the public Linux gcc-sm8350.c clock driver. No write is performed by NativeUfs
// yet: these are read-only checks that the boot chain left the UFS clocks on.
#ifndef NATIVE_UFS_GCC_UFS_H
#define NATIVE_UFS_GCC_UFS_H

// Physical windows from the haydn board DT (clock-controller@100000, ufshc@1d84000).
#define GCC_BASE                      0x00100000ULL
#define UFS_HC_BASE                   0x01d84000ULL
#define UFS_HC_SIZE                   0x3000ULL

// UFS PHY GDSC power-domain switch.
#define GCC_UFS_PHY_GDSCR             0x77004
#define GCC_UFS_MEM_PHY_GDSCR         0x9e000

// gcc-sm8350.c branch clock enable/halt registers (SM8350 offsets; they differ
// from the SM8550 ones ShengUfs shipped). BRANCH_HALT_VOTED: bit 31 = CLK_OFF.
#define GCC_UFS_PHY_AXI_ENABLE        0x77010
#define GCC_UFS_PHY_AHB_ENABLE        0x77018
#define GCC_UFS_PHY_TX_SYMBOL0_ENABLE 0x7701c
#define GCC_UFS_PHY_RX_SYMBOL0_ENABLE 0x77020
#define GCC_UFS_PHY_UNIPRO_CORE_ENABLE 0x7705c
#define GCC_UFS_PHY_ICE_CORE_ENABLE   0x77064
#define GCC_UFS_PHY_PHY_AUX_ENABLE    0x7709c
#define GCC_UFS_PHY_RX_SYMBOL1_ENABLE 0x770b8
// bus_aggr_clk in the board DT: gcc_aggre_ufs_phy_axi_clk; SM8350 enable 0x770e4.
#define GCC_AGGRE_UFS_PHY_AXI_ENABLE  0x770e4

#define GCC_UFS_BRANCH_ENABLE_BIT     0x1U

// gcc_ufs_phy_ahb_clk and gcc_aggre_ufs_phy_axi_clk set hwcg_bit=1 in gcc-sm8350.c,
// so CLK_OFF=1 on an idle branch is normal. The reset and RPMh/TCSR/QMP-PHY
// programming are not represented here: their semantics are not qualified and
// NativeUfs must not write them speculatively. The boot chain (XBL -> ABL) already
// initializes the QMP v4 lahaina PHY and leaves the controller in HCI mode.
#endif
