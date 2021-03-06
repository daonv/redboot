/*****************************************************************************
* Model: pelican.qm
* File:  ./pelican.c
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
/* @(/2/1) .................................................................*/
#include "qpn_port.h"
#include "bsp.h"
#include "pelican.h"

/*Q_DEFINE_THIS_FILE*/

#define CARS_GREEN_MIN_TOUT (QTimeEvtCtr)(BSP_TICKS_PER_SEC * 8U)
#define CARS_YELLOW_TOUT    (QTimeEvtCtr)(BSP_TICKS_PER_SEC * 3U)
#define PEDS_WALK_TOUT      (QTimeEvtCtr)(BSP_TICKS_PER_SEC * 3U)
#define PEDS_FLASH_TOUT     (QTimeEvtCtr)(BSP_TICKS_PER_SEC / 5U)
#define PEDS_FLASH_NUM      (uint8_t)(5U * 2U)
#define OFF_FLASH_TOUT      (QTimeEvtCtr)(BSP_TICKS_PER_SEC / 2U)

/* Pelican class declaration -----------------------------------------------*/
/* @(/1/0) .................................................................*/
typedef struct PelicanTag {
/* protected: */
    QMActive super;

/* private: */
    uint8_t flashCtr;
} Pelican;

/* protected: */
static QState Pelican_initial(Pelican * const me);
static QState Pelican_operational  (Pelican * const me);
static QState Pelican_operational_e(Pelican * const me);
static QState Pelican_operational_i(Pelican * const me);
static QMState const Pelican_operational_s = {
    (QMState const *)0,
    Q_STATE_CAST(&Pelican_operational),
    Q_ACTION_CAST(0)
};
static QState Pelican_carsEnabled  (Pelican * const me);
static QState Pelican_carsEnabled_x(Pelican * const me);
static QState Pelican_carsEnabled_i(Pelican * const me);
static QMState const Pelican_carsEnabled_s = {
    &Pelican_operational_s,
    Q_STATE_CAST(&Pelican_carsEnabled),
    Q_ACTION_CAST(&Pelican_carsEnabled_x)
};
static QState Pelican_carsGreen  (Pelican * const me);
static QState Pelican_carsGreen_e(Pelican * const me);
static QState Pelican_carsGreen_x(Pelican * const me);
static QState Pelican_carsGreen_i(Pelican * const me);
static QMState const Pelican_carsGreen_s = {
    &Pelican_carsEnabled_s,
    Q_STATE_CAST(&Pelican_carsGreen),
    Q_ACTION_CAST(&Pelican_carsGreen_x)
};
static QState Pelican_carsGreenNoPed  (Pelican * const me);
static QState Pelican_carsGreenNoPed_e(Pelican * const me);
static QMState const Pelican_carsGreenNoPed_s = {
    &Pelican_carsGreen_s,
    Q_STATE_CAST(&Pelican_carsGreenNoPed),
    Q_ACTION_CAST(0)
};
static QState Pelican_carsGreenInt  (Pelican * const me);
static QState Pelican_carsGreenInt_e(Pelican * const me);
static QMState const Pelican_carsGreenInt_s = {
    &Pelican_carsGreen_s,
    Q_STATE_CAST(&Pelican_carsGreenInt),
    Q_ACTION_CAST(0)
};
static QState Pelican_carsGreenPedWait  (Pelican * const me);
static QState Pelican_carsGreenPedWait_e(Pelican * const me);
static QMState const Pelican_carsGreenPedWait_s = {
    &Pelican_carsGreen_s,
    Q_STATE_CAST(&Pelican_carsGreenPedWait),
    Q_ACTION_CAST(0)
};
static QState Pelican_carsYellow  (Pelican * const me);
static QState Pelican_carsYellow_e(Pelican * const me);
static QState Pelican_carsYellow_x(Pelican * const me);
static QMState const Pelican_carsYellow_s = {
    &Pelican_carsEnabled_s,
    Q_STATE_CAST(&Pelican_carsYellow),
    Q_ACTION_CAST(&Pelican_carsYellow_x)
};
static QState Pelican_pedsEnabled  (Pelican * const me);
static QState Pelican_pedsEnabled_x(Pelican * const me);
static QState Pelican_pedsEnabled_i(Pelican * const me);
static QMState const Pelican_pedsEnabled_s = {
    &Pelican_operational_s,
    Q_STATE_CAST(&Pelican_pedsEnabled),
    Q_ACTION_CAST(&Pelican_pedsEnabled_x)
};
static QState Pelican_pedsWalk  (Pelican * const me);
static QState Pelican_pedsWalk_e(Pelican * const me);
static QState Pelican_pedsWalk_x(Pelican * const me);
static QMState const Pelican_pedsWalk_s = {
    &Pelican_pedsEnabled_s,
    Q_STATE_CAST(&Pelican_pedsWalk),
    Q_ACTION_CAST(&Pelican_pedsWalk_x)
};
static QState Pelican_pedsFlash  (Pelican * const me);
static QState Pelican_pedsFlash_e(Pelican * const me);
static QState Pelican_pedsFlash_x(Pelican * const me);
static QMState const Pelican_pedsFlash_s = {
    &Pelican_pedsEnabled_s,
    Q_STATE_CAST(&Pelican_pedsFlash),
    Q_ACTION_CAST(&Pelican_pedsFlash_x)
};
static QState Pelican_offline  (Pelican * const me);
static QState Pelican_offline_e(Pelican * const me);
static QState Pelican_offline_x(Pelican * const me);
static QMState const Pelican_offline_s = {
    (QMState const *)0,
    Q_STATE_CAST(&Pelican_offline),
    Q_ACTION_CAST(&Pelican_offline_x)
};


/* Global objects ----------------------------------------------------------*/
struct PelicanTag AO_Pelican;      /* the single instance of the Pelican AO */

/* Pelican class definition ------------------------------------------------*/
/* @(/1/2) .................................................................*/
void Pelican_ctor(void) {
    QMActive_ctor(&AO_Pelican.super, Q_STATE_CAST(&Pelican_initial));
}
/* @(/1/0) .................................................................*/
/* @(/1/0/1) ...............................................................*/
/* @(/1/0/1/0) */
static QState Pelican_initial(Pelican * const me) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&Pelican_operational_e),
        Q_ACTION_CAST(&Pelican_operational_i),
        Q_ACTION_CAST(0)
    };
    return QM_INITIAL(&Pelican_operational_s, &act_[0]);
}
/* @(/1/0/1/1) .............................................................*/
static QState Pelican_operational_e(Pelican * const me) {
    BSP_signalCars(CARS_RED);
    BSP_signalPeds(PEDS_DONT_WALK);
    return QM_ENTRY(&Pelican_operational_s);
}
static QState Pelican_operational_i(Pelican * const me) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&Pelican_carsEnabled_i),
        Q_ACTION_CAST(0)
    };
    return QM_INITIAL(&Pelican_carsEnabled_s, &act_[0]);
}
static QState Pelican_operational(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /* @(/1/0/1/1/1) */
        case OFF_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Pelican_offline_e),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Pelican_offline_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/2) */
        case TERMINATE_SIG: {
            BSP_terminate(0);
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
/* @(/1/0/1/1/3) ...........................................................*/
static QState Pelican_carsEnabled_x(Pelican * const me) {
    BSP_signalCars(CARS_RED);
    return QM_EXIT(&Pelican_carsEnabled_s);
}
static QState Pelican_carsEnabled_i(Pelican * const me) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&Pelican_carsGreen_e),
        Q_ACTION_CAST(&Pelican_carsGreen_i),
        Q_ACTION_CAST(0)
    };
    return QM_INITIAL(&Pelican_carsGreen_s, &act_[0]);
}
static QState Pelican_carsEnabled(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/3/1) .........................................................*/
static QState Pelican_carsGreen_e(Pelican * const me) {
    BSP_signalCars(CARS_GREEN);
    QActive_armX(&me->super, 0U, CARS_GREEN_MIN_TOUT);
    return QM_ENTRY(&Pelican_carsGreen_s);
}
static QState Pelican_carsGreen_x(Pelican * const me) {
    QActive_disarmX(&me->super, 0U);
    return QM_EXIT(&Pelican_carsGreen_s);
}
static QState Pelican_carsGreen_i(Pelican * const me) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&Pelican_carsGreenNoPed_e),
        Q_ACTION_CAST(0)
    };
    return QM_INITIAL(&Pelican_carsGreenNoPed_s, &act_[0]);
}
static QState Pelican_carsGreen(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/3/1/1) .......................................................*/
static QState Pelican_carsGreenNoPed_e(Pelican * const me) {
    BSP_showState("carsGreenNoPed");
    return QM_ENTRY(&Pelican_carsGreenNoPed_s);
}
static QState Pelican_carsGreenNoPed(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /* @(/1/0/1/1/3/1/1/0) */
        case PEDS_WAITING_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Pelican_carsGreenPedWait_e),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Pelican_carsGreenPedWait_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/1/3/1/1/1) */
        case Q_TIMEOUT_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Pelican_carsGreenInt_e),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Pelican_carsGreenInt_s, &act_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/3/1/2) .......................................................*/
static QState Pelican_carsGreenInt_e(Pelican * const me) {
    BSP_showState("carsGreenInt");
    return QM_ENTRY(&Pelican_carsGreenInt_s);
}
static QState Pelican_carsGreenInt(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /* @(/1/0/1/1/3/1/2/0) */
        case PEDS_WAITING_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Pelican_carsGreen_x),
                Q_ACTION_CAST(&Pelican_carsYellow_e),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Pelican_carsYellow_s, &act_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/3/1/3) .......................................................*/
static QState Pelican_carsGreenPedWait_e(Pelican * const me) {
    BSP_showState("carsGreenPedWait");
    return QM_ENTRY(&Pelican_carsGreenPedWait_s);
}
static QState Pelican_carsGreenPedWait(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /* @(/1/0/1/1/3/1/3/0) */
        case Q_TIMEOUT_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Pelican_carsGreen_x),
                Q_ACTION_CAST(&Pelican_carsYellow_e),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Pelican_carsYellow_s, &act_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/3/2) .........................................................*/
static QState Pelican_carsYellow_e(Pelican * const me) {
    BSP_showState("carsYellow");
    BSP_signalCars(CARS_YELLOW);
    QActive_armX(&me->super, 0U, CARS_YELLOW_TOUT);
    return QM_ENTRY(&Pelican_carsYellow_s);
}
static QState Pelican_carsYellow_x(Pelican * const me) {
    QActive_disarmX(&me->super, 0U);
    return QM_EXIT(&Pelican_carsYellow_s);
}
static QState Pelican_carsYellow(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /* @(/1/0/1/1/3/2/0) */
        case Q_TIMEOUT_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Pelican_carsYellow_x),
                Q_ACTION_CAST(&Pelican_carsEnabled_x),
                Q_ACTION_CAST(&Pelican_pedsEnabled_i),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Pelican_pedsEnabled_s, &act_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/4) ...........................................................*/
static QState Pelican_pedsEnabled_x(Pelican * const me) {
    BSP_signalPeds(PEDS_DONT_WALK);
    return QM_EXIT(&Pelican_pedsEnabled_s);
}
static QState Pelican_pedsEnabled_i(Pelican * const me) {
    static QActionHandler const act_[] = {
        Q_ACTION_CAST(&Pelican_pedsWalk_e),
        Q_ACTION_CAST(0)
    };
    return QM_INITIAL(&Pelican_pedsWalk_s, &act_[0]);
}
static QState Pelican_pedsEnabled(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/4/1) .........................................................*/
static QState Pelican_pedsWalk_e(Pelican * const me) {
    BSP_showState("pedsWalk");
    BSP_signalPeds(PEDS_WALK);
    QActive_armX(&me->super, 0U, PEDS_WALK_TOUT);
    return QM_ENTRY(&Pelican_pedsWalk_s);
}
static QState Pelican_pedsWalk_x(Pelican * const me) {
    QActive_disarmX(&me->super, 0U);
    return QM_EXIT(&Pelican_pedsWalk_s);
}
static QState Pelican_pedsWalk(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /* @(/1/0/1/1/4/1/0) */
        case Q_TIMEOUT_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Pelican_pedsWalk_x),
                Q_ACTION_CAST(&Pelican_pedsFlash_e),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Pelican_pedsFlash_s, &act_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/1/4/2) .........................................................*/
static QState Pelican_pedsFlash_e(Pelican * const me) {
    BSP_showState("pedsFlash");
    QActive_armX(&me->super, 0U, PEDS_FLASH_TOUT);
    me->flashCtr = (PEDS_FLASH_NUM * 2U) + 1U;
    return QM_ENTRY(&Pelican_pedsFlash_s);
}
static QState Pelican_pedsFlash_x(Pelican * const me) {
    QActive_disarmX(&me->super, 0U);
    return QM_EXIT(&Pelican_pedsFlash_s);
}
static QState Pelican_pedsFlash(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /* @(/1/0/1/1/4/2/0) */
        case Q_TIMEOUT_SIG: {
            /* @(/1/0/1/1/4/2/0/0) */
            if (me->flashCtr != 0U) {
                --me->flashCtr;
                QActive_arm(&me->super, PEDS_FLASH_TOUT);
                /* @(/1/0/1/1/4/2/0/0/0) */
                if ((me->flashCtr & 1U) == 0U) {
                    BSP_signalPeds(PEDS_DONT_WALK);
                    status_ = QM_HANDLED();
                }
                /* @(/1/0/1/1/4/2/0/0/1) */
                else {
                    BSP_signalPeds(PEDS_BLANK);
                    status_ = QM_HANDLED();
                }
            }
            /* @(/1/0/1/1/4/2/0/1) */
            else {
                static QActionHandler const act_[] = {
                    Q_ACTION_CAST(&Pelican_pedsFlash_x),
                    Q_ACTION_CAST(&Pelican_pedsEnabled_x),
                    Q_ACTION_CAST(&Pelican_carsEnabled_i),
                    Q_ACTION_CAST(0)
                };
                status_ = QM_TRAN(&Pelican_carsEnabled_s, &act_[0]);
            }
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/1/0/1/2) .............................................................*/
static QState Pelican_offline_e(Pelican * const me) {
    BSP_showState("offline");
    QActive_armX(&me->super, 0U, OFF_FLASH_TOUT);
    me->flashCtr = 0U;
    return QM_ENTRY(&Pelican_offline_s);
}
static QState Pelican_offline_x(Pelican * const me) {
    QActive_disarmX(&me->super, 0U);
    return QM_EXIT(&Pelican_offline_s);
}
static QState Pelican_offline(Pelican * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /* @(/1/0/1/2/0) */
        case Q_TIMEOUT_SIG: {
            QActive_arm(&me->super, OFF_FLASH_TOUT);
            me->flashCtr ^= 1U;
            /* @(/1/0/1/2/0/0) */
            if ((me->flashCtr & 1U) == 0U) {
                BSP_signalCars(CARS_RED);
                BSP_signalPeds(PEDS_DONT_WALK);
                status_ = QM_HANDLED();
            }
            /* @(/1/0/1/2/0/1) */
            else {
                BSP_signalCars(CARS_BLANK);
                BSP_signalPeds(PEDS_BLANK);
                status_ = QM_HANDLED();
            }
            break;
        }
        /* @(/1/0/1/2/1) */
        case ON_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Pelican_offline_x),
                Q_ACTION_CAST(&Pelican_operational_e),
                Q_ACTION_CAST(&Pelican_operational_i),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Pelican_operational_s, &act_[0]);
            break;
        }
        /* @(/1/0/1/2/2) */
        case TERMINATE_SIG: {
            BSP_terminate(0);
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

