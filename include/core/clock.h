//*****************************************************************************
//
// ��� �����    : 'clock.h'
// ���������    : �������� ������ ������������
// �����        : ���������� �. �.
// ��������     : plexus_bra@rambler.ru
// ����         : 12.10.2012
//
//*****************************************************************************

#ifndef _CLOCK_H
#define _CLOCK_H

#include "core\processor.h"

// =============================================================================
//                                ��������
// =============================================================================

    #define  MCLK_OFF       true
    #define  MCLK_ON        false

    #define  MCLK_DCO       (0x01 << 6)
    #define  MCLK_XT2       (0x02 << 6)
    #define  MCLK_LFXT      (0x03 << 6)

    #define  MCLK_DIV_1     (0x00 << 4)
    #define  MCLK_DIV_2     (0x01 << 4)
    #define  MCLK_DIV_4     (0x02 << 4)
    #define  MCLK_DIV_8     (0x03 << 4)

    #define  SMCLK_OFF      true
    #define  SMCLK_ON       false

    #define  SMCLK_DCO      (0x00 << 3)
    #define  SMCLK_XT2CLK   (0x01 << 3)

    #define  SMCLK_DIV_1    (0x00 << 1)
    #define  SMCLK_DIV_2    (0x01 << 1)
    #define  SMCLK_DIV_4    (0x02 << 1)
    #define  SMCLK_DIV_8    (0x03 << 1)

    #define  DCO_16MHZ      CALDCO_16MHZ_
    #define  DCO_12MHZ      CALDCO_12MHZ_
    #define  DCO_8MHZ       CALDCO_8MHZ_
    #define  DCO_1MHZ       CALDCO_1MHZ_

// =============================================================================
//                           ��������� �������
// =============================================================================
    
    // ������������ ���������������� ������������ ACLK
    void ConfigACLCK(uchar diva);
    // ������������ �������� ���������� ������������ MCLK
    void ConfigMCLK(uchar divm, uchar selm, bool cpuoff);
    // ������������ ��������������� ���������� ������������ SMCLK
    void ConfigSMCLK(uchar divs, uchar source, bool scg1);
    // ������������ DCO
    void ConfigDCO(uint frq);

// =============================================================================
//                          ������� �����������
// =============================================================================
    extern uint32 MckClock;
    
#endif // _CLOCK_H















