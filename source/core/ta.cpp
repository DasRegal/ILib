//*****************************************************************************
//
// ��� �����    : 'ta.cpp'
// ���������    : ������� ������ Timer A (TA)
// �����        : ���������� �. �.
// ��������     : plexus_bra@rambler.ru
// ����         : 03/06/2012
//
// ��������:
// ���������� ������������ ������� �������� SMCLK.
// ��� ������������� ������� ���������� ���������, ����� ��������� ACLK �
// �������� �������� ������������ ��� ������� A �� TASSEL_1.
//
//*****************************************************************************

#include "core\ta.h"
#include "core\core.h"
#include "core\clock.h"

// ============================================================================
//                          ���������� ����������
// ============================================================================
    
    CTimerA  ta;

// ============================================================================
///
///                            �����������
///
// ============================================================================

CTimerA::CTimerA()
{
}

// ============================================================================
///
///         ����� ������� �������� MCK ��� ��������� ������� �������
///
// ============================================================================
/// ��������� ����� ������������� �������:
///
///   (MCK / (DIV * 65536)) <= freq <= (MCK / DIV)
///
/// � ��������� DIV ����������� ���������
// ============================================================================
/// \param  freq     �������� ������� �������
/// \param  mck      ������� MCK
/// \param  tcclks   �������� ���� TCCLKS
/// \param  counter  �������� �������� 
/// \return 1 ���� �������� ������; ����� 0
// ============================================================================

void CTimerA::FindMckDivisor (uint freq, uint32 mck, uint* div, uint* counter)
{
    uint index = 0;
    uint divisors[4] = {1, 2, 4, 8};
    
    // ����� ��������
    while ((uint32)freq <= (uint32)((mck / divisors[index]) / 65536) && (++index < 4));
    
    // ���������� �����������
    if (index < 4)    
    {
        *div  = index;
        *counter = (mck / divisors[index]) / freq;
    }
    else
    {
        // ���������� ���������� ��������� ������� ������� ��� ��������� MCK
        while(1);
    }
}

// ============================================================================
///
///                          ������������ �������
///
// ============================================================================
/// \param  freq      ������� �������
/// \param  handler   �������-���������� ����������
/// \param  priority  ��������� ���������� �������
/// \param  param     �������������� ����� �������� TC_CMR
// ============================================================================

void CTimerA::Configure (uint freq,/* THandlerISR* handler,*/ uint param)
{
    uint div;
    uint counter;
    // ��������� ������� �� ��������� �������
    FindMckDivisor(freq, MckClock, &div, &counter);
    // ��������� ������ ������ (�������� ������������ - SMCLK)
    // ���������� ���������� ����������
    // ��������� ������� (����� "����", ��������� MCx = 00h)
    TACTL = (div << 5) | MC_0 | TASSEL_2 | param;  
    TACCR0 = counter;
    
    // ���������� ���������� (� ����������� �� �������)
    //if (handler) 
    //{
        #warning ��������
        //configure_aic(m_Id, priority, AT91C_AIC_SRCTYPE_INT_HIGH_LEVEL, handler);
        //enable_aic(m_Id); 
    //}
}

// ============================================================================
///
///                       ��������������� �������
///
// ============================================================================

void CTimerA::UnInit (void)
{
    // ��������� �������
    Stop();    
    //// ������ ���������� 
    //disable_aic(m_Id);
}

// ============================================================================
///
///                            ������ �������
///
// ============================================================================

void CTimerA::Start (void)
{
    // ������ ������� � ������ "�����" �� TACCR0, ���������� ����������
    TACTL |= MC_1;  // | TAIE;
    TACCTL0 = CCIE;
}

// ============================================================================
///
///                            ��������� �������
///
// ============================================================================

void CTimerA::Stop (void)
{
    // ��������� �������
    TACTL |= MC_0;
    // ������ ����������
    TACCTL0 &= ~CCIE;
    //TACTL &= ~TAIE;
}

#warning ��������� TACCTL (������)

// ============================================================================
///
///                          ���������� �������
///
// ============================================================================

void CTimerA::Restart (void)
{

}

// ============================================================================
///
///                        ���������� ����������
///
// ============================================================================

void CTimerA::EnableIrq (void)
{
    TACCTL0 = CCIE;
}

// ============================================================================
///
///                          ������ ����������
///
// ============================================================================

void CTimerA::DisableIrq (void)
{
    TACCTL0 &= ~CCIE;
}