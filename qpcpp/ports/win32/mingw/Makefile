##############################################################################
# Product:  QP/C++, Win32 build, GNU compiler
# Last Updated for Version: 5.2.0
# Date of the Last Update:  Dec 03, 2013
#
#                    Q u a n t u m     L e a P s
#                    ---------------------------
#                    innovating embedded systems
#
# Copyright (C) 2002-2013 Quantum Leaps, LLC. All rights reserved.
#
# This program is open source software: you can redistribute it and/or
# modify it under the terms of the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Alternatively, this program may be distributed and modified under the
# terms of Quantum Leaps commercial licenses, which expressly supersede
# the GNU General Public License and are specifically designed for
# licensees interested in retaining the proprietary status of their code.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#
# Contact information:
# Quantum Leaps Web sites: http://www.quantum-leaps.com
#                          http://www.state-machine.com
# e-mail:                  info@quantum-leaps.com
##############################################################################

# examples of invoking this Makefile:
# building configurations: Debug (default), Release, and Spy
# mingw32-make
# mingw32-make CONF=rel
# mingw32-make CONF=spy
#
# cleaning configurations: Debug (default), Release, and Spy
# mingw32-make clean
# mingw32-make CONF=rel clean
# mingw32-make CONF=spy clean

#-----------------------------------------------------------------------------
# NOTE: this Makefile assumes that the MinGW\bin directory is added
# to the PATH variable.
#
CC  = gcc
CPP = g++
LIB = ar
RM  = rm

QPCPP      = ../../..
QP_INCDIR  = $(QPCPP)/include
QEP_SRCDIR = $(QPCPP)/qep/source
QF_SRCDIR  = $(QPCPP)/qf/source
QS_SRCDIR  = $(QPCPP)/qs/source
QP_PRTDIR  = ..

CCINC      = -I$(QP_PRTDIR) -I$(QP_INCDIR)
LIBFLAGS   = rs

#-----------------------------------------------------------------------------
# build options for various configurations
#
ifeq (rel, $(CONF))       # Release configuration ............................

BINDIR  = rel

# gcc options
CCFLAGS = -c -O2 -Wall -o$@

# g++ options
CPPFLAGS  = -c -O2 -fno-rtti -fno-exceptions -Wall -o$@

else ifeq (spy, $(CONF))  # Spy configuration ................................

BINDIR   = spy

# gcc options
CCFLAGS = -c -g -O -DQ_SPY -Wall -o$@

# g++ options
CPPFLAGS  = -c -g -O -DQ_SPY -fno-rtti -fno-exceptions -Wall -o$@

QS_OBJS = \
	$(BINDIR)/qs.o \
	$(BINDIR)/qs_.o \
	$(BINDIR)/qs_blk.o \
	$(BINDIR)/qs_byte.o \
	$(BINDIR)/qs_dict.o \
	$(BINDIR)/qs_f32.o \
	$(BINDIR)/qs_f64.o \
	$(BINDIR)/qs_mem.o \
	$(BINDIR)/qs_str.o \
	$(BINDIR)/qs_u64.o

else                     # default Debug configuration .......................

BINDIR  = dbg
QP_DEP  = $(QP_INCDIR)/qassert.h

# gcc options
CCFLAGS = -c -g -O -Wall -o$@

# g++ options
CPPFLAGS  = -c -g -O -fno-rtti -fno-exceptions -Wall -o$@

endif

VPATH = $(QEP_SRCDIR) $(QF_SRCDIR) $(QS_SRCDIR)

# the objects to build =======================================================
QEP_OBJS = \
	$(BINDIR)/qep.o \
	$(BINDIR)/qmsm_ini.o \
	$(BINDIR)/qmsm_dis.o \
	$(BINDIR)/qfsm_ini.o \
	$(BINDIR)/qfsm_dis.o \
	$(BINDIR)/qhsm_ini.o \
	$(BINDIR)/qhsm_dis.o \
	$(BINDIR)/qhsm_top.o \
	$(BINDIR)/qhsm_in.o

QF_OBJS = \
	$(BINDIR)/qa_defer.o \
	$(BINDIR)/qa_fifo.o \
	$(BINDIR)/qa_lifo.o \
	$(BINDIR)/qa_get_.o \
	$(BINDIR)/qa_sub.o \
	$(BINDIR)/qa_usub.o \
	$(BINDIR)/qa_usuba.o \
	$(BINDIR)/qeq_init.o \
	$(BINDIR)/qeq_fifo.o \
	$(BINDIR)/qeq_lifo.o \
	$(BINDIR)/qeq_get.o \
	$(BINDIR)/qf_act.o \
	$(BINDIR)/qf_gc.o \
	$(BINDIR)/qf_log2.o \
	$(BINDIR)/qf_new.o \
	$(BINDIR)/qf_pool.o \
	$(BINDIR)/qf_psini.o \
	$(BINDIR)/qf_pspub.o \
	$(BINDIR)/qf_pwr2.o \
	$(BINDIR)/qf_tick.o \
	$(BINDIR)/qmp_get.o \
	$(BINDIR)/qmp_init.o \
	$(BINDIR)/qmp_put.o \
	$(BINDIR)/qte_ctor.o \
	$(BINDIR)/qte_arm.o \
	$(BINDIR)/qte_darm.o \
	$(BINDIR)/qte_rarm.o \
	$(BINDIR)/qte_ctr.o \
	$(BINDIR)/qf_port.o \
	$(BINDIR)/win32_gui.o

# the 'all' target ===========================================================

all: $(BINDIR)/libqp.a $(BIN_DIR)
	-$(RM) $(BINDIR)/*.o

$(BIN_DIR):
	mkdir $@

$(BINDIR)/libqp.a: 	$(QEP_OBJS) $(QF_OBJS) $(QS_OBJS)
	-$(RM) $(BINDIR)/libqp.a
	$(LIB) $(LIBFLAGS) $(BINDIR)/libqp.a \
	$(QEP_OBJS) \
	$(QF_OBJS) \
	$(QS_OBJS)

# QEP -----------------------------------------
$(BINDIR)/qep.o: $(QEP_SRCDIR)/qep.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QEP_SRCDIR) $<

$(BINDIR)/qmsm_ini.o: $(QEP_SRCDIR)/qmsm_ini.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QEP_SRCDIR) $<

$(BINDIR)/qmsm_dis.o: $(QEP_SRCDIR)/qmsm_dis.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QEP_SRCDIR) $<

$(BINDIR)/qfsm_ini.o: $(QEP_SRCDIR)/qfsm_ini.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QEP_SRCDIR) $<

$(BINDIR)/qfsm_dis.o: $(QEP_SRCDIR)/qfsm_dis.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QEP_SRCDIR) $<

$(BINDIR)/qhsm_ini.o: $(QEP_SRCDIR)/qhsm_ini.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QEP_SRCDIR) $<

$(BINDIR)/qhsm_dis.o: $(QEP_SRCDIR)/qhsm_dis.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QEP_SRCDIR) $<

$(BINDIR)/qhsm_top.o: $(QEP_SRCDIR)/qhsm_top.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QEP_SRCDIR) $<

$(BINDIR)/qhsm_in.o: $(QEP_SRCDIR)/qhsm_in.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QEP_SRCDIR) $<

# QF -----------------------------------------
$(BINDIR)/qa_defer.o: $(QF_SRCDIR)/qa_defer.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qa_fifo.o: $(QF_SRCDIR)/qa_fifo.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qa_lifo.o: $(QF_SRCDIR)/qa_lifo.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qa_get_.o: $(QF_SRCDIR)/qa_get_.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qa_sub.o: $(QF_SRCDIR)/qa_sub.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qa_usub.o: $(QF_SRCDIR)/qa_usub.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qa_usuba.o: $(QF_SRCDIR)/qa_usuba.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qeq_init.o: $(QF_SRCDIR)/qeq_init.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qeq_fifo.o: $(QF_SRCDIR)/qeq_fifo.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qeq_lifo.o: $(QF_SRCDIR)/qeq_lifo.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qeq_get.o: $(QF_SRCDIR)/qeq_get.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qf_act.o: $(QF_SRCDIR)/qf_act.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qf_gc.o: $(QF_SRCDIR)/qf_gc.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qf_log2.o: $(QF_SRCDIR)/qf_log2.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qf_new.o: $(QF_SRCDIR)/qf_new.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qf_pool.o: $(QF_SRCDIR)/qf_pool.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qf_psini.o: $(QF_SRCDIR)/qf_psini.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qf_pspub.o: $(QF_SRCDIR)/qf_pspub.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qf_pwr2.o: $(QF_SRCDIR)/qf_pwr2.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qf_tick.o: $(QF_SRCDIR)/qf_tick.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qmp_get.o: $(QF_SRCDIR)/qmp_get.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qmp_init.o: $(QF_SRCDIR)/qmp_init.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qmp_put.o: $(QF_SRCDIR)/qmp_put.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qte_ctor.o: $(QF_SRCDIR)/qte_ctor.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qte_arm.o: $(QF_SRCDIR)/qte_arm.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qte_darm.o: $(QF_SRCDIR)/qte_darm.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qte_rarm.o: $(QF_SRCDIR)/qte_rarm.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qte_ctr.o: $(QF_SRCDIR)/qte_ctr.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/qf_port.o: $(QP_PRTDIR)/qf_port.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

$(BINDIR)/win32_gui.o: $(QP_PRTDIR)/win32_gui.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QF_SRCDIR) $<

# QS -----------------------------------------

$(BINDIR)/qs.o: $(QS_SRCDIR)/qs.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QS_SRCDIR) $<

$(BINDIR)/qs_.o: $(QS_SRCDIR)/qs_.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QS_SRCDIR) $<

$(BINDIR)/qs_blk.o: $(QS_SRCDIR)/qs_blk.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QS_SRCDIR) $<

$(BINDIR)/qs_byte.o: $(QS_SRCDIR)/qs_byte.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QS_SRCDIR) $<

$(BINDIR)/qs_dict.o: $(QS_SRCDIR)/qs_dict.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QS_SRCDIR) $<

$(BINDIR)/qs_f32.o: $(QS_SRCDIR)/qs_f32.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QS_SRCDIR) $<

$(BINDIR)/qs_f64.o: $(QS_SRCDIR)/qs_f64.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QS_SRCDIR) $<

$(BINDIR)/qs_mem.o: $(QS_SRCDIR)/qs_mem.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QS_SRCDIR) $<

$(BINDIR)/qs_str.o: $(QS_SRCDIR)/qs_str.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QS_SRCDIR) $<

$(BINDIR)/qs_u64.o: $(QS_SRCDIR)/qs_u64.cpp
	$(CPP) $(CPPFLAGS) $(CCINC) -I$(QS_SRCDIR) $<

# clean ======================================================================
.PHONY : clean
clean:
	-$(RM) $(BINDIR)/*.o
	-$(RM) $(BINDIR)/*.a

