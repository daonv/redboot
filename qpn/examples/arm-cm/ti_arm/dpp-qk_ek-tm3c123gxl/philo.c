/*****************************************************************************
* Model: dpp.qm
* File:  ./philo.c
*
* This file has been generated automatically by QP Modeler (QM).
* DO NOT EDIT THIS FILE MANUALLY.
*
* Please visit www.state-machine.com/qm for more information.
*****************************************************************************/
#include "qpn_port.h"                                       /* QP-nano port */
#include "dpp.h"                                   /* application interface */
#include "bsp.h"

Q_DEFINE_THIS_MODULE("philo")

/* Active object class -----------------------------------------------------*/
/* @(/1/0) .................................................................*/
typedef struct PhiloTag {
/* protected: */
    QActive super;
} Philo;

/* protected: */
static QState Philo_initial(Philo * const me);
static QState Philo_thinking(Philo * const me);
static QState Philo_hungry(Philo * const me);
static QState Philo_eating(Philo * const me);


/* Global objects ----------------------------------------------------------*/
/* @(/1/2) .................................................................*/
struct PhiloTag AO_Philo0;
/* @(/1/3) .................................................................*/
struct PhiloTag AO_Philo1;
/* @(/1/4) .................................................................*/
struct PhiloTag AO_Philo2;
/* @(/1/5) .................................................................*/
struct PhiloTag AO_Philo3;
/* @(/1/6) .................................................................*/
struct PhiloTag AO_Philo4;

/* Local objects -----------------------------------------------------------*/
#define THINK_TIME  \
    (QTimeEvtCtr)((BSP_random() % BSP_TICKS_PER_SEC) + (BSP_TICKS_PER_SEC/2U))
#define EAT_TIME    \
    (QTimeEvtCtr)((BSP_random() % BSP_TICKS_PER_SEC) + BSP_TICKS_PER_SEC)

/* Philo definition --------------------------------------------------------*/
/* @(/1/8) .................................................................*/
void Philo_ctor(void) {
    QActive_ctor(&AO_Philo0.super, Q_STATE_CAST(&Philo_initial));
    QActive_ctor(&AO_Philo1.super, Q_STATE_CAST(&Philo_initial));
    QActive_ctor(&AO_Philo2.super, Q_STATE_CAST(&Philo_initial));
    QActive_ctor(&AO_Philo3.super, Q_STATE_CAST(&Philo_initial));
    QActive_ctor(&AO_Philo4.super, Q_STATE_CAST(&Philo_initial));
    BSP_randomSeed(123U);
}
/* @(/1/0) .................................................................*/
/* @(/1/0/0) ...............................................................*/
/* @(/1/0/0/0) */
static QState Philo_initial(Philo * const me) {
    return Q_TRAN(&Philo_thinking);
}
/* @(/1/0/0/1) .............................................................*/
static QState Philo_thinking(Philo * const me) {
    QState status;
    switch (Q_SIG(me)) {
        /* @(/1/0/0/1) */
        case Q_ENTRY_SIG: {
            QActive_arm((QActive *)me, THINK_TIME);
            status = Q_HANDLED();
            break;
        }
        /* @(/1/0/0/1/0) */
        case Q_TIMEOUT_SIG: {
            status = Q_TRAN(&Philo_hungry);
            break;
        }
        /* @(/1/0/0/1/1) */
        case EAT_SIG: /* intentionally fall through */
        case DONE_SIG: {
            Q_ERROR(); /* these events should never arrive in this state */
            status = Q_HANDLED();
            break;
        }
        default: {
            status = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status;
}
/* @(/1/0/0/2) .............................................................*/
static QState Philo_hungry(Philo * const me) {
    QState status;
    switch (Q_SIG(me)) {
        /* @(/1/0/0/2) */
        case Q_ENTRY_SIG: {
            QActive_post((QActive *)&AO_Table, HUNGRY_SIG, me->super.prio);
            status = Q_HANDLED();
            break;
        }
        /* @(/1/0/0/2/0) */
        case EAT_SIG: {
            status = Q_TRAN(&Philo_eating);
            break;
        }
        /* @(/1/0/0/2/1) */
        case DONE_SIG: {
            Q_ERROR(); /* this event should never arrive in this state */
            status = Q_HANDLED();
            break;
        }
        default: {
            status = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status;
}
/* @(/1/0/0/3) .............................................................*/
static QState Philo_eating(Philo * const me) {
    QState status;
    switch (Q_SIG(me)) {
        /* @(/1/0/0/3) */
        case Q_ENTRY_SIG: {
            QActive_arm((QActive *)me, EAT_TIME);
            status = Q_HANDLED();
            break;
        }
        /* @(/1/0/0/3) */
        case Q_EXIT_SIG: {
            QActive_post((QActive *)&AO_Table, DONE_SIG, me->super.prio);
            status = Q_HANDLED();
            break;
        }
        /* @(/1/0/0/3/0) */
        case Q_TIMEOUT_SIG: {
            status = Q_TRAN(&Philo_thinking);
            break;
        }
        /* @(/1/0/0/3/1) */
        case EAT_SIG: /* intentionally fall through */
        case DONE_SIG: {
            Q_ERROR(); /* these events should never arrive in this state */
            status = Q_HANDLED();
            break;
        }
        default: {
            status = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status;
}

