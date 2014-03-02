// This file was generated by the create_regs script
#define PWM_BASE                                                 0x7e20c000
#define PWM_APB_ID                                               0x70776d30
#define PWM_CTL                                                  HW_REGISTER_RW( 0x7e20c000 ) 
   #define PWM_CTL_MASK                                          0xbfbfbfff
   #define PWM_CTL_WIDTH                                         32
   #define PWM_CTL_RESET                                         0000000000
      #define PWM_CTL_PWEN1_BITS                                 0:0
      #define PWM_CTL_PWEN1_SET                                  0x00000001
      #define PWM_CTL_PWEN1_CLR                                  0xfffffffe
      #define PWM_CTL_PWEN1_MSB                                  0
      #define PWM_CTL_PWEN1_LSB                                  0
      #define PWM_CTL_MODE1_BITS                                 1:1
      #define PWM_CTL_MODE1_SET                                  0x00000002
      #define PWM_CTL_MODE1_CLR                                  0xfffffffd
      #define PWM_CTL_MODE1_MSB                                  1
      #define PWM_CTL_MODE1_LSB                                  1
      #define PWM_CTL_RPTL1_BITS                                 2:2
      #define PWM_CTL_RPTL1_SET                                  0x00000004
      #define PWM_CTL_RPTL1_CLR                                  0xfffffffb
      #define PWM_CTL_RPTL1_MSB                                  2
      #define PWM_CTL_RPTL1_LSB                                  2
      #define PWM_CTL_SBIT1_BITS                                 3:3
      #define PWM_CTL_SBIT1_SET                                  0x00000008
      #define PWM_CTL_SBIT1_CLR                                  0xfffffff7
      #define PWM_CTL_SBIT1_MSB                                  3
      #define PWM_CTL_SBIT1_LSB                                  3
      #define PWM_CTL_POLA1_BITS                                 4:4
      #define PWM_CTL_POLA1_SET                                  0x00000010
      #define PWM_CTL_POLA1_CLR                                  0xffffffef
      #define PWM_CTL_POLA1_MSB                                  4
      #define PWM_CTL_POLA1_LSB                                  4
      #define PWM_CTL_USEF1_BITS                                 5:5
      #define PWM_CTL_USEF1_SET                                  0x00000020
      #define PWM_CTL_USEF1_CLR                                  0xffffffdf
      #define PWM_CTL_USEF1_MSB                                  5
      #define PWM_CTL_USEF1_LSB                                  5
      #define PWM_CTL_CLRF1_BITS                                 6:6
      #define PWM_CTL_CLRF1_SET                                  0x00000040
      #define PWM_CTL_CLRF1_CLR                                  0xffffffbf
      #define PWM_CTL_CLRF1_MSB                                  6
      #define PWM_CTL_CLRF1_LSB                                  6
      #define PWM_CTL_MSEN1_BITS                                 7:7
      #define PWM_CTL_MSEN1_SET                                  0x00000080
      #define PWM_CTL_MSEN1_CLR                                  0xffffff7f
      #define PWM_CTL_MSEN1_MSB                                  7
      #define PWM_CTL_MSEN1_LSB                                  7
      #define PWM_CTL_PWEN2_BITS                                 8:8
      #define PWM_CTL_PWEN2_SET                                  0x00000100
      #define PWM_CTL_PWEN2_CLR                                  0xfffffeff
      #define PWM_CTL_PWEN2_MSB                                  8
      #define PWM_CTL_PWEN2_LSB                                  8
      #define PWM_CTL_MODE2_BITS                                 9:9
      #define PWM_CTL_MODE2_SET                                  0x00000200
      #define PWM_CTL_MODE2_CLR                                  0xfffffdff
      #define PWM_CTL_MODE2_MSB                                  9
      #define PWM_CTL_MODE2_LSB                                  9
      #define PWM_CTL_RPTL2_BITS                                 10:10
      #define PWM_CTL_RPTL2_SET                                  0x00000400
      #define PWM_CTL_RPTL2_CLR                                  0xfffffbff
      #define PWM_CTL_RPTL2_MSB                                  10
      #define PWM_CTL_RPTL2_LSB                                  10
      #define PWM_CTL_SBIT2_BITS                                 11:11
      #define PWM_CTL_SBIT2_SET                                  0x00000800
      #define PWM_CTL_SBIT2_CLR                                  0xfffff7ff
      #define PWM_CTL_SBIT2_MSB                                  11
      #define PWM_CTL_SBIT2_LSB                                  11
      #define PWM_CTL_POLA2_BITS                                 12:12
      #define PWM_CTL_POLA2_SET                                  0x00001000
      #define PWM_CTL_POLA2_CLR                                  0xffffefff
      #define PWM_CTL_POLA2_MSB                                  12
      #define PWM_CTL_POLA2_LSB                                  12
      #define PWM_CTL_USEF2_BITS                                 13:13
      #define PWM_CTL_USEF2_SET                                  0x00002000
      #define PWM_CTL_USEF2_CLR                                  0xffffdfff
      #define PWM_CTL_USEF2_MSB                                  13
      #define PWM_CTL_USEF2_LSB                                  13
      #define PWM_CTL_MSEN2_BITS                                 15:15
      #define PWM_CTL_MSEN2_SET                                  0x00008000
      #define PWM_CTL_MSEN2_CLR                                  0xffff7fff
      #define PWM_CTL_MSEN2_MSB                                  15
      #define PWM_CTL_MSEN2_LSB                                  15
      #define PWM_CTL_PWEN3_BITS                                 16:16
      #define PWM_CTL_PWEN3_SET                                  0x00010000
      #define PWM_CTL_PWEN3_CLR                                  0xfffeffff
      #define PWM_CTL_PWEN3_MSB                                  16
      #define PWM_CTL_PWEN3_LSB                                  16
      #define PWM_CTL_MODE3_BITS                                 17:17
      #define PWM_CTL_MODE3_SET                                  0x00020000
      #define PWM_CTL_MODE3_CLR                                  0xfffdffff
      #define PWM_CTL_MODE3_MSB                                  17
      #define PWM_CTL_MODE3_LSB                                  17
      #define PWM_CTL_RPTL3_BITS                                 18:18
      #define PWM_CTL_RPTL3_SET                                  0x00040000
      #define PWM_CTL_RPTL3_CLR                                  0xfffbffff
      #define PWM_CTL_RPTL3_MSB                                  18
      #define PWM_CTL_RPTL3_LSB                                  18
      #define PWM_CTL_SBIT3_BITS                                 19:19
      #define PWM_CTL_SBIT3_SET                                  0x00080000
      #define PWM_CTL_SBIT3_CLR                                  0xfff7ffff
      #define PWM_CTL_SBIT3_MSB                                  19
      #define PWM_CTL_SBIT3_LSB                                  19
      #define PWM_CTL_POLA3_BITS                                 20:20
      #define PWM_CTL_POLA3_SET                                  0x00100000
      #define PWM_CTL_POLA3_CLR                                  0xffefffff
      #define PWM_CTL_POLA3_MSB                                  20
      #define PWM_CTL_POLA3_LSB                                  20
      #define PWM_CTL_USEF3_BITS                                 21:21
      #define PWM_CTL_USEF3_SET                                  0x00200000
      #define PWM_CTL_USEF3_CLR                                  0xffdfffff
      #define PWM_CTL_USEF3_MSB                                  21
      #define PWM_CTL_USEF3_LSB                                  21
      #define PWM_CTL_MSEN3_BITS                                 23:23
      #define PWM_CTL_MSEN3_SET                                  0x00800000
      #define PWM_CTL_MSEN3_CLR                                  0xff7fffff
      #define PWM_CTL_MSEN3_MSB                                  23
      #define PWM_CTL_MSEN3_LSB                                  23
      #define PWM_CTL_PWEN4_BITS                                 24:24
      #define PWM_CTL_PWEN4_SET                                  0x01000000
      #define PWM_CTL_PWEN4_CLR                                  0xfeffffff
      #define PWM_CTL_PWEN4_MSB                                  24
      #define PWM_CTL_PWEN4_LSB                                  24
      #define PWM_CTL_MODE4_BITS                                 25:25
      #define PWM_CTL_MODE4_SET                                  0x02000000
      #define PWM_CTL_MODE4_CLR                                  0xfdffffff
      #define PWM_CTL_MODE4_MSB                                  25
      #define PWM_CTL_MODE4_LSB                                  25
      #define PWM_CTL_RPTL4_BITS                                 26:26
      #define PWM_CTL_RPTL4_SET                                  0x04000000
      #define PWM_CTL_RPTL4_CLR                                  0xfbffffff
      #define PWM_CTL_RPTL4_MSB                                  26
      #define PWM_CTL_RPTL4_LSB                                  26
      #define PWM_CTL_SBIT4_BITS                                 27:27
      #define PWM_CTL_SBIT4_SET                                  0x08000000
      #define PWM_CTL_SBIT4_CLR                                  0xf7ffffff
      #define PWM_CTL_SBIT4_MSB                                  27
      #define PWM_CTL_SBIT4_LSB                                  27
      #define PWM_CTL_POLA4_BITS                                 28:28
      #define PWM_CTL_POLA4_SET                                  0x10000000
      #define PWM_CTL_POLA4_CLR                                  0xefffffff
      #define PWM_CTL_POLA4_MSB                                  28
      #define PWM_CTL_POLA4_LSB                                  28
      #define PWM_CTL_USEF4_BITS                                 29:29
      #define PWM_CTL_USEF4_SET                                  0x20000000
      #define PWM_CTL_USEF4_CLR                                  0xdfffffff
      #define PWM_CTL_USEF4_MSB                                  29
      #define PWM_CTL_USEF4_LSB                                  29
      #define PWM_CTL_MSEN4_BITS                                 31:31
      #define PWM_CTL_MSEN4_SET                                  0x80000000
      #define PWM_CTL_MSEN4_CLR                                  0x7fffffff
      #define PWM_CTL_MSEN4_MSB                                  31
      #define PWM_CTL_MSEN4_LSB                                  31
#define PWM_STA                                                  HW_REGISTER_RW( 0x7e20c004 ) 
   #define PWM_STA_MASK                                          0x00001fff
   #define PWM_STA_WIDTH                                         13
   #define PWM_STA_RESET                                         0000000000
      #define PWM_STA_FULL1_BITS                                 0:0
      #define PWM_STA_FULL1_SET                                  0x00000001
      #define PWM_STA_FULL1_CLR                                  0xfffffffe
      #define PWM_STA_FULL1_MSB                                  0
      #define PWM_STA_FULL1_LSB                                  0
      #define PWM_STA_EMPT1_BITS                                 1:1
      #define PWM_STA_EMPT1_SET                                  0x00000002
      #define PWM_STA_EMPT1_CLR                                  0xfffffffd
      #define PWM_STA_EMPT1_MSB                                  1
      #define PWM_STA_EMPT1_LSB                                  1
      #define PWM_STA_WERR1_BITS                                 2:2
      #define PWM_STA_WERR1_SET                                  0x00000004
      #define PWM_STA_WERR1_CLR                                  0xfffffffb
      #define PWM_STA_WERR1_MSB                                  2
      #define PWM_STA_WERR1_LSB                                  2
      #define PWM_STA_RERR1_BITS                                 3:3
      #define PWM_STA_RERR1_SET                                  0x00000008
      #define PWM_STA_RERR1_CLR                                  0xfffffff7
      #define PWM_STA_RERR1_MSB                                  3
      #define PWM_STA_RERR1_LSB                                  3
      #define PWM_STA_GAPO1_BITS                                 4:4
      #define PWM_STA_GAPO1_SET                                  0x00000010
      #define PWM_STA_GAPO1_CLR                                  0xffffffef
      #define PWM_STA_GAPO1_MSB                                  4
      #define PWM_STA_GAPO1_LSB                                  4
      #define PWM_STA_GAPO2_BITS                                 5:5
      #define PWM_STA_GAPO2_SET                                  0x00000020
      #define PWM_STA_GAPO2_CLR                                  0xffffffdf
      #define PWM_STA_GAPO2_MSB                                  5
      #define PWM_STA_GAPO2_LSB                                  5
      #define PWM_STA_GAPO3_BITS                                 6:6
      #define PWM_STA_GAPO3_SET                                  0x00000040
      #define PWM_STA_GAPO3_CLR                                  0xffffffbf
      #define PWM_STA_GAPO3_MSB                                  6
      #define PWM_STA_GAPO3_LSB                                  6
      #define PWM_STA_GAPO4_BITS                                 7:7
      #define PWM_STA_GAPO4_SET                                  0x00000080
      #define PWM_STA_GAPO4_CLR                                  0xffffff7f
      #define PWM_STA_GAPO4_MSB                                  7
      #define PWM_STA_GAPO4_LSB                                  7
      #define PWM_STA_BERR_BITS                                  8:8
      #define PWM_STA_BERR_SET                                   0x00000100
      #define PWM_STA_BERR_CLR                                   0xfffffeff
      #define PWM_STA_BERR_MSB                                   8
      #define PWM_STA_BERR_LSB                                   8
      #define PWM_STA_STA1_BITS                                  9:9
      #define PWM_STA_STA1_SET                                   0x00000200
      #define PWM_STA_STA1_CLR                                   0xfffffdff
      #define PWM_STA_STA1_MSB                                   9
      #define PWM_STA_STA1_LSB                                   9
      #define PWM_STA_STA2_BITS                                  10:10
      #define PWM_STA_STA2_SET                                   0x00000400
      #define PWM_STA_STA2_CLR                                   0xfffffbff
      #define PWM_STA_STA2_MSB                                   10
      #define PWM_STA_STA2_LSB                                   10
      #define PWM_STA_STA3_BITS                                  11:11
      #define PWM_STA_STA3_SET                                   0x00000800
      #define PWM_STA_STA3_CLR                                   0xfffff7ff
      #define PWM_STA_STA3_MSB                                   11
      #define PWM_STA_STA3_LSB                                   11
      #define PWM_STA_STA4_BITS                                  12:12
      #define PWM_STA_STA4_SET                                   0x00001000
      #define PWM_STA_STA4_CLR                                   0xffffefff
      #define PWM_STA_STA4_MSB                                   12
      #define PWM_STA_STA4_LSB                                   12
#define PWM_DMAC                                                 HW_REGISTER_RW( 0x7e20c008 ) 
   #define PWM_DMAC_MASK                                         0x8000ffff
   #define PWM_DMAC_WIDTH                                        32
   #define PWM_DMAC_RESET                                        0x00000707
      #define PWM_DMAC_DREQ_BITS                                 7:0
      #define PWM_DMAC_DREQ_SET                                  0x000000ff
      #define PWM_DMAC_DREQ_CLR                                  0xffffff00
      #define PWM_DMAC_DREQ_MSB                                  7
      #define PWM_DMAC_DREQ_LSB                                  0
      #define PWM_DMAC_PANIC_BITS                                15:8
      #define PWM_DMAC_PANIC_SET                                 0x0000ff00
      #define PWM_DMAC_PANIC_CLR                                 0xffff00ff
      #define PWM_DMAC_PANIC_MSB                                 15
      #define PWM_DMAC_PANIC_LSB                                 8
      #define PWM_DMAC_ENAB_BITS                                 31:31
      #define PWM_DMAC_ENAB_SET                                  0x80000000
      #define PWM_DMAC_ENAB_CLR                                  0x7fffffff
      #define PWM_DMAC_ENAB_MSB                                  31
      #define PWM_DMAC_ENAB_LSB                                  31
#define PWM_RNG1                                                 HW_REGISTER_RW( 0x7e20c010 ) 
   #define PWM_RNG1_MASK                                         0xffffffff
   #define PWM_RNG1_WIDTH                                        32
   #define PWM_RNG1_RESET                                        0x00000020
#define PWM_DAT1                                                 HW_REGISTER_RW( 0x7e20c014 ) 
   #define PWM_DAT1_MASK                                         0xffffffff
   #define PWM_DAT1_WIDTH                                        32
   #define PWM_DAT1_RESET                                        0000000000
#define PWM_FIF1                                                 HW_REGISTER_RW( 0x7e20c018 ) 
   #define PWM_FIF1_MASK                                         0xffffffff
   #define PWM_FIF1_WIDTH                                        32
   #define PWM_FIF1_RESET                                        0000000000
#define PWM_RNG2                                                 HW_REGISTER_RW( 0x7e20c020 ) 
   #define PWM_RNG2_MASK                                         0xffffffff
   #define PWM_RNG2_WIDTH                                        32
   #define PWM_RNG2_RESET                                        0x00000020
#define PWM_DAT2                                                 HW_REGISTER_RW( 0x7e20c024 ) 
   #define PWM_DAT2_MASK                                         0xffffffff
   #define PWM_DAT2_WIDTH                                        32
   #define PWM_DAT2_RESET                                        0000000000
#define PWM_RNG3                                                 HW_REGISTER_RW( 0x7e20c030 ) 
   #define PWM_RNG3_MASK                                         0000000000
   #define PWM_RNG3_WIDTH                                        0
   #define PWM_RNG3_RESET                                        0x00000020
#define PWM_DAT3                                                 HW_REGISTER_RW( 0x7e20c034 ) 
   #define PWM_DAT3_MASK                                         0000000000
   #define PWM_DAT3_WIDTH                                        0
   #define PWM_DAT3_RESET                                        0000000000
#define PWM_RNG4                                                 HW_REGISTER_RW( 0x7e20c040 ) 
   #define PWM_RNG4_MASK                                         0000000000
   #define PWM_RNG4_WIDTH                                        0
   #define PWM_RNG4_RESET                                        0x00000020
#define PWM_DAT4                                                 HW_REGISTER_RW( 0x7e20c044 ) 
   #define PWM_DAT4_MASK                                         0000000000
   #define PWM_DAT4_WIDTH                                        0
   #define PWM_DAT4_RESET                                        0000000000
