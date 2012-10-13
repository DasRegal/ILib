//*****************************************************************************
//
// ��� �����    : 'ta.h'
// ���������    : ������� ������ Timer A (TA)
// �����        : ���������� �. �.
// ��������     : plexus_bra@rambler.ru
// ����         : 03/06/2012
//
//*****************************************************************************

#ifndef _TA_H
#define _TA_H

//#include "core\aic.h"
#include "core\processor.h"

// ============================================================================
//                              ������
// ============================================================================

class CTimerA 
{
    private:
        // ����� ������� �������� MCK ��� ��������� ������� �������
        void FindMckDivisor   (uint freq, uint32 mck, uint* tcclks, uint* counter);
    public:
        // �����������
        CTimerA();
        // ������������ �������
        void Configure (uint freq, /*THandlerISR* handler,*/ uint param);
        // ��������������� �������
        void UnInit    (void);
        
        // ������ �������
        void Start      (void);
        // ��������� �������
        void Stop       (void);
        // ���������� �������
        void Restart    (void);
        // ���������� ����������
        void EnableIrq  (void);
        // ������ ����������
        void DisableIrq (void);
            
        // ��������� ���������� ���������� ������
        void SetPriority (uint priority);
};

// ============================================================================
//                          ������� �����������
// ============================================================================
    
    extern CTimerA  ta;
#endif //#ifndef _TA_H

