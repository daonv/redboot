#ifndef CYGONCE_LIBM_ACOSH_H
#define CYGONCE_LIBM_ACOSH_H
//===========================================================================
//
//      acoshf.h
//
//      Test vectors for testing of acoshf() math library function
//
//===========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 2012 Free Software Foundation, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 or (at your option) any later
// version.
//
// eCos is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License
// along with eCos; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
// As a special exception, if other files instantiate templates or use
// macros or inline functions from this file, or you compile this file
// and link it with other works to produce a work based on this file,
// this file does not by itself cause the resulting work to be covered by
// the GNU General Public License. However the source code for this file
// must still be made available in accordance with section (3) of the GNU
// General Public License v2.
//
// This exception does not invalidate any other reasons why a work based
// on this file might be covered by the GNU General Public License.
// -------------------------------------------
// ####ECOSGPLCOPYRIGHTEND####
//===========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):
// Contributors:  visar, ilijak
// Date:        1998-02-13
// Purpose:
// Description:
// Usage:       #include "vectors/acoshf.h"
//
//####DESCRIPTIONEND####
//
//===========================================================================


// CONFIGURATION

#include <pkgconf/libm.h>   // Configuration header


// INCLUDES

#include <cyg/infra/cyg_type.h>    // Common type definitions and support
#include "vectors/vector_support_float.h"// extra support for math tests

#define ACOSH_TOLERANCE 1.0E-04

static const Cyg_libm_test_float_vec_t acoshf_vec[] = {

// AUTOMATICALLY GENERATED VECTORS START

{0, 3214514586u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{1, 3214430700u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{2, 3214346813u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{3, 3214262927u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{4, 3214179041u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{5, 3214095155u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{6, 3214011269u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{7, 3213927383u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{8, 3213843497u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{9, 3213759611u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{10, 3213675725u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{11, 3213591839u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{12, 3213507953u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{13, 3213424067u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{14, 3213340180u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{15, 3213256294u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{16, 3213172408u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{17, 3213088522u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{18, 3213004636u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{19, 3212920750u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{20, 3212836864u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{21, 3212669092u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{22, 3212501320u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{23, 3212333548u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{24, 3212165775u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{25, 3211998003u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{26, 3211830231u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{27, 3211662459u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{28, 3211494687u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{29, 3211326915u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{30, 3211159142u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{31, 3210991370u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{32, 3210823598u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{33, 3210655826u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{34, 3210488054u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{35, 3210320282u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{36, 3210152509u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{37, 3209984737u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{38, 3209816965u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{39, 3209649193u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{40, 3209481421u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{41, 3209313649u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{42, 3209145876u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{43, 3208978104u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{44, 3208810332u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{45, 3208642560u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{46, 3208474788u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{47, 3208307016u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{48, 3208139244u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{49, 3207971471u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{50, 3207803699u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{51, 3207635927u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{52, 3207468155u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{53, 3207300383u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{54, 3207132611u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{55, 3206964838u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{56, 3206797066u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{57, 3206629294u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{58, 3206461522u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{59, 3206293750u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{60, 3206125978u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{61, 3205958205u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{62, 3205790433u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{63, 3205622661u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{64, 3205454889u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{65, 3205287117u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{66, 3205119345u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{67, 3204951572u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{68, 3204783800u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{69, 3204616028u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{70, 3204448256u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{71, 3204112712u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{72, 3203777167u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{73, 3203441623u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{74, 3203106079u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{75, 3202770534u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{76, 3202434990u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{77, 3202099446u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{78, 3201763901u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{79, 3201428357u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{80, 3201092813u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{81, 3200757268u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{82, 3200421724u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{83, 3200086180u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{84, 3199750636u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{85, 3199415091u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{86, 3199079547u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{87, 3198744003u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{88, 3198408458u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{89, 3198072914u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{90, 3197737370u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{91, 3197401825u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{92, 3197066281u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{93, 3196730737u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{94, 3196395192u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{95, 3196059648u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{96, 3195388559u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{97, 3194717471u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{98, 3194046382u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{99, 3193375293u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{100, 3192704205u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{101, 3192033116u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{102, 3191362028u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{103, 3190690939u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{104, 3190019850u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{105, 3189348762u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{106, 3188677673u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{107, 3188006584u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{108, 3186999951u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{109, 3185657774u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{110, 3184315597u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{111, 3182973420u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{112, 3181631242u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{113, 3180289065u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{114, 3178611343u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{115, 3175926989u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{116, 3173242634u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{117, 3170222735u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{118, 3164854026u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{119, 3156465418u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{120, 1008981770u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{121, 1017370378u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{122, 1022739087u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{123, 1025758986u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{124, 1028443341u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{125, 1031127695u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{126, 1032805417u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{127, 1034147594u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{128, 1035489772u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{129, 1036831949u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{130, 1038174126u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{131, 1039516303u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{132, 1040522936u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{133, 1041194025u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{134, 1041865114u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{135, 1042536202u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{136, 1043207291u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{137, 1043878380u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{138, 1044549468u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{139, 1045220557u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{140, 1045891645u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{141, 1046562734u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{142, 1047233823u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{143, 1047904911u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{144, 1048576000u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{145, 1048911544u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{146, 1049247089u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{147, 1049582633u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{148, 1049918177u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{149, 1050253722u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{150, 1050589266u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{151, 1050924810u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{152, 1051260355u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{153, 1051595899u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{154, 1051931443u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{155, 1052266988u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{156, 1052602532u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{157, 1052938076u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{158, 1053273620u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{159, 1053609165u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{160, 1053944709u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{161, 1054280253u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{162, 1054615798u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{163, 1054951342u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{164, 1055286886u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{165, 1055622431u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{166, 1055957975u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{167, 1056293519u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{168, 1056629064u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{169, 1056964608u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{170, 1057132380u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{171, 1057300152u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{172, 1057467924u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{173, 1057635697u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{174, 1057803469u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{175, 1057971241u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{176, 1058139013u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{177, 1058306785u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{178, 1058474557u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{179, 1058642330u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{180, 1058810102u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{181, 1058977874u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{182, 1059145646u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{183, 1059313418u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{184, 1059481190u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{185, 1059648963u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{186, 1059816735u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{187, 1059984507u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{188, 1060152279u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{189, 1060320051u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{190, 1060487823u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{191, 1060655596u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{192, 1060823368u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{193, 1060991140u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{194, 1061158912u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{195, 1061326684u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{196, 1061494456u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{197, 1061662228u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{198, 1061830001u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{199, 1061997773u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{200, 1062165545u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{201, 1062333317u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{202, 1062501089u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{203, 1062668861u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{204, 1062836634u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{205, 1063004406u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{206, 1063172178u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{207, 1063339950u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{208, 1063507722u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{209, 1063675494u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{210, 1063843267u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{211, 1064011039u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{212, 1064178811u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{213, 1064346583u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{214, 1064514355u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{215, 1064682127u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{216, 1064849900u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{217, 1065017672u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{218, 1065185444u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{219, 1065437102u, 1041281514u, 1041281514u, 0, ACOSH_TOLERANCE, 0},
{220, 1065520988u, 1045198281u, 1045198281u, 0, ACOSH_TOLERANCE, 0},
{221, 1065604874u, 1048196204u, 1048196204u, 0, ACOSH_TOLERANCE, 0},
{222, 1065688760u, 1049646660u, 1049646660u, 0, ACOSH_TOLERANCE, 0},
{223, 1065772646u, 1050754509u, 1050754509u, 0, ACOSH_TOLERANCE, 0},
{224, 1065856532u, 1051753636u, 1051753636u, 0, ACOSH_TOLERANCE, 0},
{225, 1065940419u, 1052670210u, 1052670210u, 0, ACOSH_TOLERANCE, 0},
{226, 1066024305u, 1053521262u, 1053521262u, 0, ACOSH_TOLERANCE, 0},
{227, 1066108191u, 1054318670u, 1054318670u, 0, ACOSH_TOLERANCE, 0},
{228, 1066192077u, 1055071074u, 1055071074u, 0, ACOSH_TOLERANCE, 0},
{229, 1066275963u, 1055785005u, 1055785005u, 0, ACOSH_TOLERANCE, 0},
{230, 1066359849u, 1056465542u, 1056465542u, 0, ACOSH_TOLERANCE, 0},
{231, 1066443735u, 1057040669u, 1057040669u, 0, ACOSH_TOLERANCE, 0},
{232, 1066527621u, 1057353227u, 1057353227u, 0, ACOSH_TOLERANCE, 0},
{233, 1066611507u, 1057654105u, 1057654105u, 0, ACOSH_TOLERANCE, 0},
{234, 1066695393u, 1057944433u, 1057944433u, 0, ACOSH_TOLERANCE, 0},
{235, 1066779279u, 1058225171u, 1058225171u, 0, ACOSH_TOLERANCE, 0},
{236, 1066863165u, 1058497140u, 1058497140u, 0, ACOSH_TOLERANCE, 0},
{237, 1066947052u, 1058761049u, 1058761049u, 0, ACOSH_TOLERANCE, 0},
{238, 3234402267u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{239, 3231108068u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{240, 3226013659u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{241, 3217625051u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{242, 1070141403u, 1065548063u, 1065548063u, 0, ACOSH_TOLERANCE, 0},
{243, 1078530011u, 1072160792u, 1072160792u, 0, ACOSH_TOLERANCE, 0},
{244, 1083624420u, 1074714438u, 1074714438u, 0, ACOSH_TOLERANCE, 0},
{245, 3253731328u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{246, 3252840038u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{247, 3251948749u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{248, 3251057459u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{249, 3250166170u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{250, 3249274880u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{251, 3248383590u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{252, 3247492301u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{253, 3246601011u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{254, 3245028147u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{255, 3243245568u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{256, 3241462989u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{257, 3239680410u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{258, 3237792973u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{259, 3234227814u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{260, 3230662656u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{261, 3224580915u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{262, 3213675725u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{263, 1058642330u, 1115684864u, 2143289344u, EDOM, ACOSH_TOLERANCE, 0},
{264, 1075000115u, 1069338181u, 1069338181u, 0, ACOSH_TOLERANCE, 0},
{265, 1082130432u, 1074007898u, 1074007898u, 0, ACOSH_TOLERANCE, 0},
{266, 1085695590u, 1075527877u, 1075527877u, 0, ACOSH_TOLERANCE, 0},
{267, 1089260749u, 1076636021u, 1076636021u, 0, ACOSH_TOLERANCE, 0},
{268, 1091672474u, 1077509940u, 1077509940u, 0, ACOSH_TOLERANCE, 0},
{269, 1093455053u, 1078232007u, 1078232007u, 0, ACOSH_TOLERANCE, 0},
{270, 1095237632u, 1078847433u, 1078847433u, 0, ACOSH_TOLERANCE, 0},
{271, 1097020211u, 1079383779u, 1079383779u, 0, ACOSH_TOLERANCE, 0},
{272, 1098802790u, 1079859115u, 1079859115u, 0, ACOSH_TOLERANCE, 0},
{273, 1099746509u, 1080285937u, 1080285937u, 0, ACOSH_TOLERANCE, 0},
{274, 1100637798u, 1080673248u, 1080673248u, 0, ACOSH_TOLERANCE, 0},
{275, 1101529088u, 1081027759u, 1081027759u, 0, ACOSH_TOLERANCE, 0},
{276, 1102420378u, 1081354598u, 1081354598u, 0, ACOSH_TOLERANCE, 0},
{277, 1103311667u, 1081657776u, 1081657776u, 0, ACOSH_TOLERANCE, 0},
{278, 1104202957u, 1081940495u, 1081940495u, 0, ACOSH_TOLERANCE, 0},
{279, 1105094246u, 1082167886u, 1082167886u, 0, ACOSH_TOLERANCE, 0},
{280, 1105985536u, 1082292437u, 1082292437u, 0, ACOSH_TOLERANCE, 0}

// AUTOMATICALLY GENERATED VECTORS STOP

};

#endif // CYGONCE_LIBM_ACOSH_H multiple inclusion protection

// EOF acoshf.h
