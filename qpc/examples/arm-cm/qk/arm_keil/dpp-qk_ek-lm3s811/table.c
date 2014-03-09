/*****************************************************************************
* Model: dpp.qm
* File:  ./table.c
*
* This code has been generated by QM tool (see state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*****************************************************************************/
/* @(/3/2) .................................................................*/
#include "qp_port.h"
#include "dpp.h"
#include "bsp.h"

Q_DEFINE_THIS_FILE

/* Active object class -----------------------------------------------------*/
/* @(/2/1) .................................................................*/
typedef struct TableTag {
/* protected: */
    QMActive super;

/* private: */
    uint8_t fork[N_PHILO];
    uint8_t isHungry[N_PHILO];
} Table;

/* protected: */
static QState Table_initial(Table * const me, QEvt const * const e);
static QState Table_active  (Table * const me, QEvt const * const e);
static QMState const Table_active_s = {
    (QMState const *)0,
    Q_STATE_CAST(&Table_active),
    Q_ACTION_CAST(0)
};
static QState Table_serving  (Table * const me, QEvt const * const e);
static QState Table_serving_e(Table * const me);
static QMState const Table_serving_s = {
    &Table_active_s,
    Q_STATE_CAST(&Table_serving),
    Q_ACTION_CAST(0)
};
static QState Table_paused  (Table * const me, QEvt const * const e);
static QState Table_paused_e(Table * const me);
static QState Table_paused_x(Table * const me);
static QMState const Table_paused_s = {
    &Table_active_s,
    Q_STATE_CAST(&Table_paused),
    Q_ACTION_CAST(&Table_paused_x)
};


#define RIGHT(n_) ((uint8_t)(((n_) + (N_PHILO - 1U)) % N_PHILO))
#define LEFT(n_)  ((uint8_t)(((n_) + 1U) % N_PHILO))
#define FREE      ((uint8_t)0)
#define USED      ((uint8_t)1)

/* Local objects -----------------------------------------------------------*/
static Table l_table; /* the single instance of the Table active object */

/* Global-scope objects ----------------------------------------------------*/
QActive * const AO_Table = &l_table.super; /* "opaque" AO pointer */

/*..........................................................................*/
/* @(/2/5) .................................................................*/
void Table_ctor(void) {
    uint8_t n;
    Table *me = &l_table;

    QMActive_ctor(&me->super, Q_STATE_CAST(&Table_initial));

    for (n = 0U; n < N_PHILO; ++n) {
        me->fork[n] = FREE;
        me->isHungry[n] = 0U;
    }
}
/* @(/2/1) .................................................................*/
/* @(/2/1/2) ...............................................................*/
/* @(/2/1/2/0) */
static QState Table_initial(Table * const me, QEvt const * const e) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&Table_serving_e),
        Q_ACTION_CAST(0)
    };
    uint8_t n;
    (void)e; /* suppress the compiler warning about unused parameter */

    QS_OBJ_DICTIONARY(&l_table);
    QS_FUN_DICTIONARY(&QHsm_top);
    QS_FUN_DICTIONARY(&Table_initial);
    QS_FUN_DICTIONARY(&Table_serving);

    QS_SIG_DICTIONARY(DONE_SIG,      (void *)0); /* global signals */
    QS_SIG_DICTIONARY(EAT_SIG,       (void *)0);
    QS_SIG_DICTIONARY(PAUSE_SIG,     (void *)0);
    QS_SIG_DICTIONARY(TERMINATE_SIG, (void *)0);

    QS_SIG_DICTIONARY(HUNGRY_SIG,    me); /* signal just for Table */

    QActive_subscribe(&me->super, DONE_SIG);
    QActive_subscribe(&me->super, PAUSE_SIG);
    QActive_subscribe(&me->super, TERMINATE_SIG);

    for (n = 0U; n < N_PHILO; ++n) {
        me->fork[n] = FREE;
        me->isHungry[n] = 0U;
        BSP_displayPhilStat(n, "thinking");
    }
    return QM_INITIAL(&Table_serving_s, act_);
}
/* @(/2/1/2/1) .............................................................*/
static QState Table_active(Table * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/2/1/2/1/0) */
        case TERMINATE_SIG: {
            BSP_terminate(0);
            status_ = QM_HANDLED();
            break;
        }
        /* @(/2/1/2/1/1) */
        case EAT_SIG: {
            Q_ERROR();
            status_ = QM_HANDLED();
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/2/1/2/1/2) ...........................................................*/
static QState Table_serving_e(Table * const me) {
    uint8_t n;
    for (n = 0U; n < N_PHILO; ++n) { /* give permissions to eat... */
        if ((me->isHungry[n] != 0U)
            && (me->fork[LEFT(n)] == FREE)
            && (me->fork[n] == FREE))
        {
            TableEvt *te;

            me->fork[LEFT(n)] = USED;
            me->fork[n] = USED;
            te = Q_NEW(TableEvt, EAT_SIG);
            te->philoNum = n;
            QF_PUBLISH(&te->super, me);
            me->isHungry[n] = 0U;
            BSP_displayPhilStat(n, "eating  ");
        }
    }
    return QM_ENTRY(&Table_serving_s);
}
static QState Table_serving(Table * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/2/1/2/1/2/0) */
        case HUNGRY_SIG: {
            uint8_t n, m;

            n = Q_EVT_CAST(TableEvt)->philoNum;
            /* phil ID must be in range and he must be not hungry */
            Q_ASSERT((n < N_PHILO) && (me->isHungry[n] == 0U));

            BSP_displayPhilStat(n, "hungry  ");
            m = LEFT(n);
            /* @(/2/1/2/1/2/0/0) */
            if ((me->fork[m] == FREE) && (me->fork[n] == FREE)) {
                TableEvt *pe;
                me->fork[m] = USED;
                me->fork[n] = USED;
                pe = Q_NEW(TableEvt, EAT_SIG);
                pe->philoNum = n;
                QF_PUBLISH(&pe->super, me);
                BSP_displayPhilStat(n, "eating  ");
                status_ = QM_HANDLED();
            }
            /* @(/2/1/2/1/2/0/1) */
            else {
                me->isHungry[n] = 1U;
                status_ = QM_HANDLED();
            }
            break;
        }
        /* @(/2/1/2/1/2/1) */
        case DONE_SIG: {
            uint8_t n, m;
            TableEvt *pe;

            n = Q_EVT_CAST(TableEvt)->philoNum;
            /* phil ID must be in range and he must be not hungry */
            Q_ASSERT((n < N_PHILO) && (me->isHungry[n] == 0U));

            BSP_displayPhilStat(n, "thinking");
            m = LEFT(n);
            /* both forks of Phil[n] must be used */
            Q_ASSERT((me->fork[n] == USED) && (me->fork[m] == USED));

            me->fork[m] = FREE;
            me->fork[n] = FREE;
            m = RIGHT(n); /* check the right neighbor */

            if ((me->isHungry[m] != 0U) && (me->fork[m] == FREE)) {
                me->fork[n] = USED;
                me->fork[m] = USED;
                me->isHungry[m] = 0U;
                pe = Q_NEW(TableEvt, EAT_SIG);
                pe->philoNum = m;
                QF_PUBLISH(&pe->super, me);
                BSP_displayPhilStat(m, "eating  ");
            }
            m = LEFT(n); /* check the left neighbor */
            n = LEFT(m); /* left fork of the left neighbor */
            if ((me->isHungry[m] != 0U) && (me->fork[n] == FREE)) {
                me->fork[m] = USED;
                me->fork[n] = USED;
                me->isHungry[m] = 0U;
                pe = Q_NEW(TableEvt, EAT_SIG);
                pe->philoNum = m;
                QF_PUBLISH(&pe->super, me);
                BSP_displayPhilStat(m, "eating  ");
            }
            status_ = QM_HANDLED();
            break;
        }
        /* @(/2/1/2/1/2/2) */
        case EAT_SIG: {
            Q_ERROR();
            status_ = QM_HANDLED();
            break;
        }
        /* @(/2/1/2/1/2/3) */
        case PAUSE_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Table_paused_e),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Table_paused_s, act_);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/2/1/2/1/3) ...........................................................*/
static QState Table_paused_e(Table * const me) {
    BSP_displayPaused(1U);
    return QM_ENTRY(&Table_paused_s);
}
static QState Table_paused_x(Table * const me) {
    BSP_displayPaused(0U);
    return QM_EXIT(&Table_paused_s);
}
static QState Table_paused(Table * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/2/1/2/1/3/0) */
        case PAUSE_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Table_paused_x),
                Q_ACTION_CAST(&Table_serving_e),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Table_serving_s, act_);
            break;
        }
        /* @(/2/1/2/1/3/1) */
        case HUNGRY_SIG: {
            uint8_t n = Q_EVT_CAST(TableEvt)->philoNum;
            /* philo ID must be in range and he must be not hungry */
            Q_ASSERT((n < N_PHILO) && (me->isHungry[n] == 0U));
            me->isHungry[n] = 1U;
            BSP_displayPhilStat(n, "hungry  ");
            status_ = QM_HANDLED();
            break;
        }
        /* @(/2/1/2/1/3/2) */
        case DONE_SIG: {
            uint8_t n, m;

            n = Q_EVT_CAST(TableEvt)->philoNum;
            /* phil ID must be in range and he must be not hungry */
            Q_ASSERT((n < N_PHILO) && (me->isHungry[n] == 0U));

            BSP_displayPhilStat(n, "thinking");
            m = LEFT(n);
            /* both forks of Phil[n] must be used */
            Q_ASSERT((me->fork[n] == USED) && (me->fork[m] == USED));

            me->fork[m] = FREE;
            me->fork[n] = FREE;
            status_ = QM_HANDLED();
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
