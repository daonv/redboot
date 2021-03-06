/*****************************************************************************
* Model: game.qm
* File:  ./missile.c
*
* This file has been generated automatically by QP Modeler (QM).
* DO NOT EDIT THIS FILE MANUALLY.
*
* Please visit www.state-machine.com/qm for more information.
*****************************************************************************/
#include "qpn_port.h"
#include "bsp.h"
#include "game.h"

/* Q_DEFINE_THIS_MODULE(missile) */

/* encapsulated delcaration of the Missile active object -------------------*/
/* @(/1/2) .................................................................*/
/** 
* Missile Active Object
*/
typedef struct MissileTag {
/* protected: */
    QActive super;

/* private: */
    uint8_t x;
    uint8_t y;
    uint8_t exp_ctr;

/* public: */
    uint8_t speed;
} Missile;

/* protected: */
static QState Missile_initial(Missile * const me);
static QState Missile_armed(Missile * const me);
static QState Missile_flying(Missile * const me);
static QState Missile_exploding(Missile * const me);


/* global objects ----------------------------------------------------------*/
Missile AO_Missile;

/* Active object definition ------------------------------------------------*/
/* @(/1/11) ................................................................*/
void Missile_ctor(uint8_t speed) {
    Missile *me = &AO_Missile;
    QActive_ctor(&me->super, (QStateHandler)&Missile_initial);
    me->speed = speed;
}
/* @(/1/2) .................................................................*/
/* @(/1/2/4) ...............................................................*/
/* @(/1/2/4/0) */
static QState Missile_initial(Missile * const me) {
    return Q_TRAN(&Missile_armed);
}
/* @(/1/2/4/1) .............................................................*/
static QState Missile_armed(Missile * const me) {
    QState status;
    switch (Q_SIG(me)) {
        /* @(/1/2/4/1/0) */
        case MISSILE_FIRE_SIG: {
            me->x = (uint8_t)Q_PAR(me); /* init position from the Ship */
            me->y = (uint8_t)(Q_PAR(me) >> 8);
            status = Q_TRAN(&Missile_flying);
            break;
        }
        default: {
            status = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status;
}
/* @(/1/2/4/2) .............................................................*/
static QState Missile_flying(Missile * const me) {
    QState status;
    switch (Q_SIG(me)) {
        /* @(/1/2/4/2/0) */
        case TIME_TICK_SIG: {
            /* @(/1/2/4/2/0/0) */
            if (me->x + GAME_MISSILE_SPEED_X < GAME_SCREEN_WIDTH) {
                me->x += me->speed;
                /*tell the Tunnel to draw the Missile and test for wall hits*/
                QActive_post((QActive *)&AO_Tunnel, MISSILE_IMG_SIG,
                             ((QParam)MISSILE_BMP << 16)
                             | (QParam)me->x
                             | ((QParam)me->y << 8));
                status = Q_HANDLED();
            }
            /* @(/1/2/4/2/0/1) */
            else {
                status = Q_TRAN(&Missile_armed);
            }
            break;
        }
        /* @(/1/2/4/2/1) */
        case HIT_WALL_SIG: {
            status = Q_TRAN(&Missile_exploding);
            break;
        }
        /* @(/1/2/4/2/2) */
        case DESTROYED_MINE_SIG: {
            /* tell the Ship the score for destroing this Mine */
            QActive_post((QActive *)&AO_Ship, Q_SIG(me), Q_PAR(me));
            /* re-arm immediately & let the destroyed Mine do the exploding */
            status = Q_TRAN(&Missile_armed);
            break;
        }
        default: {
            status = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status;
}
/* @(/1/2/4/3) .............................................................*/
static QState Missile_exploding(Missile * const me) {
    QState status;
    switch (Q_SIG(me)) {
        /* @(/1/2/4/3) */
        case Q_ENTRY_SIG: {
            me->exp_ctr = 0;
            status = Q_HANDLED();
            break;
        }
        /* @(/1/2/4/3/0) */
        case TIME_TICK_SIG: {
            /* @(/1/2/4/3/0/0) */
            if ((me->x >= GAME_SPEED_X) && (me->exp_ctr < 15)) {
                ++me->exp_ctr;             /* advance the explosion counter */
                me->x -= me->speed;       /* move the explosion by one step */

                /* tell the Tunnel to render the current stage of Explosion */
                QActive_post((QActive *)&AO_Tunnel, EXPLOSION_SIG,
                         ((QParam)(EXPLOSION0_BMP + (me->exp_ctr >> 2)) << 16)
                         | (QParam)(me->x + 3)
                         | ((QParam)((int)me->y - 4) << 8));
                status = Q_HANDLED();
            }
            /* @(/1/2/4/3/0/1) */
            else {
                /* explosion finished or moved outside the game */
                status = Q_TRAN(&Missile_armed);
            }
            break;
        }
        default: {
            status = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status;
}

