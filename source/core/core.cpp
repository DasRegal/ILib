//*****************************************************************************
//
// ��� �����    : 'core.cpp'
// ���������    : ���� �����������
// �����        : ������� �.�. 
// ��������     : andrewtomsk@mail.ru
// ����         : 25/09/2010
//
//*****************************************************************************

#include "types.h"
#include "core\core.h"
#include "core\processor.h"
//#include "core\aic.h"
//#include "core\wdt.h"
//#include "core\pmc.h"
//#include "core\rstc.h"
//#include "core\spi.h"
//#include "core\efc.h"
//#include "core\adc.h"
//#include "core\systimer.h"
#include "def_board.h"
//#include "def_timer.h"

// ============================================================================
//                          ������� ��������
// ============================================================================

#if !defined(BOARD_WDT)
    #define  BOARD_WDT       0  
#endif
//#if !defined(BOARD_REMAP)
//    #define  BOARD_REMAP     1  
//#endif

// ============================================================================
//                        ��������� �������
// ============================================================================
  
    //extern "C" __ARM void LowLevelInit     (void);    
    extern           void AppMain          (void);
    
// ============================================================================
//                        ���������� ����������
// ============================================================================

    // ������� Mck � �������
    uint32  MckClock;
    
// ============================================================================
///
///                     ��������� ������������� ����
///    
// ============================================================================    
/// ���������� �� ������������� ��������� .bss    
// ============================================================================
///                             LowLevelInit
// ============================================================================

//__ARM void LowLevelInit (void) 
//{
//    // ������������� ����������� EFC
//    init_efc();
//    // ������������� ������������
//    init_pmc();
//    // ������������� ������ AIC
//    init_aic();
//    // ���������� ����������������� ������
//    init_rtsc();
//
//    // ������ Watchdog �������
//    #if !defined(__RELEASE__) && (!defined(BOARD_WDT) || (BOARD_WDT == 0))
//    disable_wdt();
//    #else
//    enable_wdt();
//    #endif
//    
//    // ���������� RTT � PIT ���������� (�������� �������� ��� ������������� ����������
//    // �� RTT � PIT � ����� ������������). �.�. ������� ��������, ������� ������
//    // ��������� ���������� �� ���� ������������� AT91C_ID_SYS
//    #if defined(__ARM__)
//    AT91C_BASE_RTTC->RTTC_RTMR &= ~(AT91C_RTTC_ALMIEN | AT91C_RTTC_RTTINCIEN);
//    AT91C_BASE_PITC->PITC_PIMR &= ~AT91C_PITC_PITIEN;
//    #endif
//}

// ============================================================================
///
///                          ����� ����� main
///
// ============================================================================
/// Core - ������� ������, ���������� �� ������� ������������� �����������. �
/// ������ ����������� ������� main, ������������������ ������ �������� ����
///
///  1. reset                    (startup.asm)
///  2. ������������� ������     (startup.asm)
///  3. LowLevelInit             (core.cpp)
///  4. ������������� ���������� (runtime)
///  5. ������������             (runtime)
///  6. main                     (core.cpp)
///  7. AppMain                  (����� ����� ����������������� ����������)
/// 
// ============================================================================

int main (void) 
{
    // ������������� ���������� �������
    // ���������� ���������� ������� ������� MCK
    MckClock = BOARD_MCK;

//    // ������ ���������� �������
//    #if !defined(SYSTIMER_DISABLE_AUTOSTART) || (SYSTIMER_DISABLE_AUTOSTART == 0)
//    ServerTimer.Configure();
//    #endif
    
    // ���������� ����������
    _BIS_SR(GIE);
     
    // ����� ����� � ��������� ������������
    AppMain();
    
    return 0;
}
