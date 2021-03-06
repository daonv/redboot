/*****************************************************************************
* Model: game.qm
* File:  ./missile.c
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
/* @(/3/1) .................................................................*/
#include "qp_port.h"
#include "bsp.h"
#include "game.h"

/* Q_DEFINE_THIS_FILE */

/* local objects -----------------------------------------------------------*/
/* @(/2/2) .................................................................*/
typedef struct MissileTag {
/* protected: */
    QMActive super;

/* private: */
    uint8_t x;
    uint8_t y;
    uint8_t exp_ctr;
} Missile;

/* protected: */
static QState Missile_initial(Missile * const me, QEvt const * const e);
static QState Missile_armed  (Missile * const me, QEvt const * const e);
static QMState const Missile_armed_s = {
    (QMState const *)0,
    Q_STATE_CAST(&Missile_armed),
    Q_ACTION_CAST(0)
};
static QState Missile_flying  (Missile * const me, QEvt const * const e);
static QMState const Missile_flying_s = {
    (QMState const *)0,
    Q_STATE_CAST(&Missile_flying),
    Q_ACTION_CAST(0)
};
static QState Missile_exploding  (Missile * const me, QEvt const * const e);
static QState Missile_exploding_e(Missile * const me);
static QMState const Missile_exploding_s = {
    (QMState const *)0,
    Q_STATE_CAST(&Missile_exploding),
    Q_ACTION_CAST(0)
};

static Missile l_missile; /* the sole instance of the Missile active object */

/* Public-scope objects ----------------------------------------------------*/
QActive * const AO_Missile = (QActive *)&l_missile;       /* opaque pointer */

/* Active object definition ------------------------------------------------*/
/* @(/2/10) ................................................................*/
void Missile_ctor(void) {
    Missile *me = &l_missile;
    QMActive_ctor(&me->super, Q_STATE_CAST(&Missile_initial));
}
/* @(/2/2) .................................................................*/
/* @(/2/2/3) ...............................................................*/
/* @(/2/2/3/0) */
static QState Missile_initial(Missile * const me, QEvt const * const e) {
    (void)e;
    QActive_subscribe((QActive *)me, TIME_TICK_SIG);

    QS_OBJ_DICTIONARY(&l_missile);  /* object dictionary for Missile object */

    QS_FUN_DICTIONARY(&Missile_initial);    /* dictionaries for Missile HSM */
    QS_FUN_DICTIONARY(&Missile_armed);
    QS_FUN_DICTIONARY(&Missile_flying);
    QS_FUN_DICTIONARY(&Missile_exploding);

    QS_SIG_DICTIONARY(MISSILE_FIRE_SIG,   &l_missile);     /* local signals */
    QS_SIG_DICTIONARY(HIT_WALL_SIG,       &l_missile);
    QS_SIG_DICTIONARY(DESTROYED_MINE_SIG, &l_missile);
    return QM_INITIAL(&Missile_armed_s, &QMsm_emptyAction_[0]);
}
/* @(/2/2/3/1) .............................................................*/
static QState Missile_armed(Missile * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/2/2/3/1/0) */
        case MISSILE_FIRE_SIG: {
            me->x = Q_EVT_CAST(ObjectPosEvt)->x;
            me->y = Q_EVT_CAST(ObjectPosEvt)->y;
            status_ = QM_TRAN(&Missile_flying_s, &QMsm_emptyAction_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/2/2/3/2) .............................................................*/
static QState Missile_flying(Missile * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/2/2/3/2/0) */
        case TIME_TICK_SIG: {
            /* @(/2/2/3/2/0/0) */
            if (me->x + GAME_MISSILE_SPEED_X < GAME_SCREEN_WIDTH) {
                ObjectImageEvt *oie;
                me->x += GAME_MISSILE_SPEED_X;
                /*tell the Tunnel to draw the Missile and test for wall hits*/
                oie = Q_NEW(ObjectImageEvt, MISSILE_IMG_SIG);
                oie->x   = me->x;
                oie->y   = me->y;
                oie->bmp = MISSILE_BMP;
                QACTIVE_POST(AO_Tunnel, (QEvt *)oie, me);
                status_ = QM_HANDLED();
            }
            /* @(/2/2/3/2/0/1) */
            else {
                status_ = QM_TRAN(&Missile_armed_s, &QMsm_emptyAction_[0]);
            }
            break;
        }
        /* @(/2/2/3/2/1) */
        case HIT_WALL_SIG: {
            static QActionHandler const act_[] = {
                Q_ACTION_CAST(&Missile_exploding_e),
                Q_ACTION_CAST(0)
            };
            status_ = QM_TRAN(&Missile_exploding_s, &act_[0]);
            break;
        }
        /* @(/2/2/3/2/2) */
        case DESTROYED_MINE_SIG: {
            QACTIVE_POST(AO_Ship, e, me);
            status_ = QM_TRAN(&Missile_armed_s, &QMsm_emptyAction_[0]);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
/* @(/2/2/3/3) .............................................................*/
static QState Missile_exploding_e(Missile * const me) {
    me->exp_ctr = 0U;
    return QM_ENTRY(&Missile_exploding_s);
}
static QState Missile_exploding(Missile * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/2/2/3/3/0) */
        case TIME_TICK_SIG: {
            /* @(/2/2/3/3/0/0) */
            if ((me->x >= GAME_SPEED_X) && (me->exp_ctr < 15U)) {
                ObjectImageEvt *oie;

                ++me->exp_ctr;           /* advance the explosion counter */
                me->x -= GAME_SPEED_X;   /* move the explosion by one step */

                /* tell the Tunnel to render the current stage of Explosion */
                oie = Q_NEW(ObjectImageEvt, EXPLOSION_SIG);
                oie->x   = me->x + 3U;   /* x-pos of explosion */
                oie->y   = (int8_t)((int)me->y - 4U); /* y-pos */
                oie->bmp = EXPLOSION0_BMP + (me->exp_ctr >> 2);
                QACTIVE_POST(AO_Tunnel, (QEvt *)oie, me);
                status_ = QM_HANDLED();
            }
            /* @(/2/2/3/3/0/1) */
            else {
                status_ = QM_TRAN(&Missile_armed_s, &QMsm_emptyAction_[0]);
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

