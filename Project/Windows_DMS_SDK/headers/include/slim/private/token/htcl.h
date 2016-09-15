/*
	htcl.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/htcl.h 20    05/12/28 12:08 Someya $ */

/* DO NOT EDIT! This file is generated automatically. */

#ifndef SLIM_TOKEN_HTCL_H
#define SLIM_TOKEN_HTCL_H

#include <slim/basis/base.h>
#include <slim/basis/token.h>
#include <slim/private/token/htclid.h>

SLIM_BEGIN_C_LINKAGE

struct THTMLColorInfo_ {
	TToken fBase;	/* must be the first field */
	TColor fColor;
};
typedef struct THTMLColorInfo_ THTMLColorInfo;

#define SLIM_TKOFF_BASE_HTCL0	(0)
#define SLIM_TKNAM_BASE_HTCL0	((slim_char *)cSlim_TokenName_HTCL)
#define SLIM_TKOFF_HTCL_aliceblue	(SLIM_TKOFF_BASE_HTCL0 + 0)
#define SLIM_TKNAM_HTCL_aliceblue	(SLIM_TKNAM_BASE_HTCL0 + 0)
#define SLIM_TKLEN_HTCL_aliceblue	(9)
#define SLIM_TKOFF_HTCL_antiquewhite	(SLIM_TKOFF_BASE_HTCL0 + 10)
#define SLIM_TKNAM_HTCL_antiquewhite	(SLIM_TKNAM_BASE_HTCL0 + 10)
#define SLIM_TKLEN_HTCL_antiquewhite	(12)
#define SLIM_TKOFF_HTCL_aqua	(SLIM_TKOFF_BASE_HTCL0 + 23)
#define SLIM_TKNAM_HTCL_aqua	(SLIM_TKNAM_BASE_HTCL0 + 23)
#define SLIM_TKLEN_HTCL_aqua	(4)
#define SLIM_TKOFF_HTCL_aquamarine	(SLIM_TKOFF_BASE_HTCL0 + 28)
#define SLIM_TKNAM_HTCL_aquamarine	(SLIM_TKNAM_BASE_HTCL0 + 28)
#define SLIM_TKLEN_HTCL_aquamarine	(10)
#define SLIM_TKOFF_HTCL_azure	(SLIM_TKOFF_BASE_HTCL0 + 39)
#define SLIM_TKNAM_HTCL_azure	(SLIM_TKNAM_BASE_HTCL0 + 39)
#define SLIM_TKLEN_HTCL_azure	(5)
#define SLIM_TKOFF_HTCL_beige	(SLIM_TKOFF_BASE_HTCL0 + 45)
#define SLIM_TKNAM_HTCL_beige	(SLIM_TKNAM_BASE_HTCL0 + 45)
#define SLIM_TKLEN_HTCL_beige	(5)
#define SLIM_TKOFF_HTCL_bisque	(SLIM_TKOFF_BASE_HTCL0 + 51)
#define SLIM_TKNAM_HTCL_bisque	(SLIM_TKNAM_BASE_HTCL0 + 51)
#define SLIM_TKLEN_HTCL_bisque	(6)
#define SLIM_TKOFF_HTCL_black	(SLIM_TKOFF_BASE_HTCL0 + 58)
#define SLIM_TKNAM_HTCL_black	(SLIM_TKNAM_BASE_HTCL0 + 58)
#define SLIM_TKLEN_HTCL_black	(5)
#define SLIM_TKOFF_HTCL_blanchedalmond	(SLIM_TKOFF_BASE_HTCL0 + 64)
#define SLIM_TKNAM_HTCL_blanchedalmond	(SLIM_TKNAM_BASE_HTCL0 + 64)
#define SLIM_TKLEN_HTCL_blanchedalmond	(14)
#define SLIM_TKOFF_HTCL_blue	(SLIM_TKOFF_BASE_HTCL0 + 79)
#define SLIM_TKNAM_HTCL_blue	(SLIM_TKNAM_BASE_HTCL0 + 79)
#define SLIM_TKLEN_HTCL_blue	(4)
#define SLIM_TKOFF_HTCL_blueviolet	(SLIM_TKOFF_BASE_HTCL0 + 84)
#define SLIM_TKNAM_HTCL_blueviolet	(SLIM_TKNAM_BASE_HTCL0 + 84)
#define SLIM_TKLEN_HTCL_blueviolet	(10)
#define SLIM_TKOFF_HTCL_brown	(SLIM_TKOFF_BASE_HTCL0 + 95)
#define SLIM_TKNAM_HTCL_brown	(SLIM_TKNAM_BASE_HTCL0 + 95)
#define SLIM_TKLEN_HTCL_brown	(5)
#define SLIM_TKOFF_HTCL_burlywood	(SLIM_TKOFF_BASE_HTCL0 + 101)
#define SLIM_TKNAM_HTCL_burlywood	(SLIM_TKNAM_BASE_HTCL0 + 101)
#define SLIM_TKLEN_HTCL_burlywood	(9)
#define SLIM_TKOFF_HTCL_cadetblue	(SLIM_TKOFF_BASE_HTCL0 + 111)
#define SLIM_TKNAM_HTCL_cadetblue	(SLIM_TKNAM_BASE_HTCL0 + 111)
#define SLIM_TKLEN_HTCL_cadetblue	(9)
#define SLIM_TKOFF_HTCL_chartreuse	(SLIM_TKOFF_BASE_HTCL0 + 121)
#define SLIM_TKNAM_HTCL_chartreuse	(SLIM_TKNAM_BASE_HTCL0 + 121)
#define SLIM_TKLEN_HTCL_chartreuse	(10)
#define SLIM_TKOFF_HTCL_chocolate	(SLIM_TKOFF_BASE_HTCL0 + 132)
#define SLIM_TKNAM_HTCL_chocolate	(SLIM_TKNAM_BASE_HTCL0 + 132)
#define SLIM_TKLEN_HTCL_chocolate	(9)
#define SLIM_TKOFF_HTCL_coral	(SLIM_TKOFF_BASE_HTCL0 + 142)
#define SLIM_TKNAM_HTCL_coral	(SLIM_TKNAM_BASE_HTCL0 + 142)
#define SLIM_TKLEN_HTCL_coral	(5)
#define SLIM_TKOFF_HTCL_cornflower	(SLIM_TKOFF_BASE_HTCL0 + 148)
#define SLIM_TKNAM_HTCL_cornflower	(SLIM_TKNAM_BASE_HTCL0 + 148)
#define SLIM_TKLEN_HTCL_cornflower	(10)
#define SLIM_TKOFF_HTCL_cornflowerblue	(SLIM_TKOFF_BASE_HTCL0 + 159)
#define SLIM_TKNAM_HTCL_cornflowerblue	(SLIM_TKNAM_BASE_HTCL0 + 159)
#define SLIM_TKLEN_HTCL_cornflowerblue	(14)
#define SLIM_TKOFF_HTCL_cornsilk	(SLIM_TKOFF_BASE_HTCL0 + 174)
#define SLIM_TKNAM_HTCL_cornsilk	(SLIM_TKNAM_BASE_HTCL0 + 174)
#define SLIM_TKLEN_HTCL_cornsilk	(8)
#define SLIM_TKOFF_HTCL_crimson	(SLIM_TKOFF_BASE_HTCL0 + 183)
#define SLIM_TKNAM_HTCL_crimson	(SLIM_TKNAM_BASE_HTCL0 + 183)
#define SLIM_TKLEN_HTCL_crimson	(7)
#define SLIM_TKOFF_HTCL_cyan	(SLIM_TKOFF_BASE_HTCL0 + 191)
#define SLIM_TKNAM_HTCL_cyan	(SLIM_TKNAM_BASE_HTCL0 + 191)
#define SLIM_TKLEN_HTCL_cyan	(4)
#define SLIM_TKOFF_HTCL_darkblue	(SLIM_TKOFF_BASE_HTCL0 + 196)
#define SLIM_TKNAM_HTCL_darkblue	(SLIM_TKNAM_BASE_HTCL0 + 196)
#define SLIM_TKLEN_HTCL_darkblue	(8)
#define SLIM_TKOFF_HTCL_darkcyan	(SLIM_TKOFF_BASE_HTCL0 + 205)
#define SLIM_TKNAM_HTCL_darkcyan	(SLIM_TKNAM_BASE_HTCL0 + 205)
#define SLIM_TKLEN_HTCL_darkcyan	(8)
#define SLIM_TKOFF_HTCL_darkgoldenrod	(SLIM_TKOFF_BASE_HTCL0 + 214)
#define SLIM_TKNAM_HTCL_darkgoldenrod	(SLIM_TKNAM_BASE_HTCL0 + 214)
#define SLIM_TKLEN_HTCL_darkgoldenrod	(13)
#define SLIM_TKOFF_HTCL_darkgray	(SLIM_TKOFF_BASE_HTCL0 + 228)
#define SLIM_TKNAM_HTCL_darkgray	(SLIM_TKNAM_BASE_HTCL0 + 228)
#define SLIM_TKLEN_HTCL_darkgray	(8)
#define SLIM_TKOFF_HTCL_darkgreen	(SLIM_TKOFF_BASE_HTCL0 + 237)
#define SLIM_TKNAM_HTCL_darkgreen	(SLIM_TKNAM_BASE_HTCL0 + 237)
#define SLIM_TKLEN_HTCL_darkgreen	(9)
#define SLIM_TKOFF_HTCL_darkkhaki	(SLIM_TKOFF_BASE_HTCL0 + 247)
#define SLIM_TKNAM_HTCL_darkkhaki	(SLIM_TKNAM_BASE_HTCL0 + 247)
#define SLIM_TKLEN_HTCL_darkkhaki	(9)
#define SLIM_TKOFF_HTCL_darkmagenta	(SLIM_TKOFF_BASE_HTCL0 + 257)
#define SLIM_TKNAM_HTCL_darkmagenta	(SLIM_TKNAM_BASE_HTCL0 + 257)
#define SLIM_TKLEN_HTCL_darkmagenta	(11)
#define SLIM_TKOFF_HTCL_darkolivegreen	(SLIM_TKOFF_BASE_HTCL0 + 269)
#define SLIM_TKNAM_HTCL_darkolivegreen	(SLIM_TKNAM_BASE_HTCL0 + 269)
#define SLIM_TKLEN_HTCL_darkolivegreen	(14)
#define SLIM_TKOFF_HTCL_darkorange	(SLIM_TKOFF_BASE_HTCL0 + 284)
#define SLIM_TKNAM_HTCL_darkorange	(SLIM_TKNAM_BASE_HTCL0 + 284)
#define SLIM_TKLEN_HTCL_darkorange	(10)
#define SLIM_TKOFF_HTCL_darkorchid	(SLIM_TKOFF_BASE_HTCL0 + 295)
#define SLIM_TKNAM_HTCL_darkorchid	(SLIM_TKNAM_BASE_HTCL0 + 295)
#define SLIM_TKLEN_HTCL_darkorchid	(10)
#define SLIM_TKOFF_HTCL_darkred	(SLIM_TKOFF_BASE_HTCL0 + 306)
#define SLIM_TKNAM_HTCL_darkred	(SLIM_TKNAM_BASE_HTCL0 + 306)
#define SLIM_TKLEN_HTCL_darkred	(7)
#define SLIM_TKOFF_HTCL_darksalmon	(SLIM_TKOFF_BASE_HTCL0 + 314)
#define SLIM_TKNAM_HTCL_darksalmon	(SLIM_TKNAM_BASE_HTCL0 + 314)
#define SLIM_TKLEN_HTCL_darksalmon	(10)
#define SLIM_TKOFF_HTCL_darkseagreen	(SLIM_TKOFF_BASE_HTCL0 + 325)
#define SLIM_TKNAM_HTCL_darkseagreen	(SLIM_TKNAM_BASE_HTCL0 + 325)
#define SLIM_TKLEN_HTCL_darkseagreen	(12)
#define SLIM_TKOFF_HTCL_darkslateblue	(SLIM_TKOFF_BASE_HTCL0 + 338)
#define SLIM_TKNAM_HTCL_darkslateblue	(SLIM_TKNAM_BASE_HTCL0 + 338)
#define SLIM_TKLEN_HTCL_darkslateblue	(13)
#define SLIM_TKOFF_HTCL_darkslategray	(SLIM_TKOFF_BASE_HTCL0 + 352)
#define SLIM_TKNAM_HTCL_darkslategray	(SLIM_TKNAM_BASE_HTCL0 + 352)
#define SLIM_TKLEN_HTCL_darkslategray	(13)
#define SLIM_TKOFF_HTCL_darkturquoise	(SLIM_TKOFF_BASE_HTCL0 + 366)
#define SLIM_TKNAM_HTCL_darkturquoise	(SLIM_TKNAM_BASE_HTCL0 + 366)
#define SLIM_TKLEN_HTCL_darkturquoise	(13)
#define SLIM_TKOFF_HTCL_darkviolet	(SLIM_TKOFF_BASE_HTCL0 + 380)
#define SLIM_TKNAM_HTCL_darkviolet	(SLIM_TKNAM_BASE_HTCL0 + 380)
#define SLIM_TKLEN_HTCL_darkviolet	(10)
#define SLIM_TKOFF_HTCL_deeppink	(SLIM_TKOFF_BASE_HTCL0 + 391)
#define SLIM_TKNAM_HTCL_deeppink	(SLIM_TKNAM_BASE_HTCL0 + 391)
#define SLIM_TKLEN_HTCL_deeppink	(8)
#define SLIM_TKOFF_HTCL_deepskyblue	(SLIM_TKOFF_BASE_HTCL0 + 400)
#define SLIM_TKNAM_HTCL_deepskyblue	(SLIM_TKNAM_BASE_HTCL0 + 400)
#define SLIM_TKLEN_HTCL_deepskyblue	(11)
#define SLIM_TKOFF_HTCL_dimgray	(SLIM_TKOFF_BASE_HTCL0 + 412)
#define SLIM_TKNAM_HTCL_dimgray	(SLIM_TKNAM_BASE_HTCL0 + 412)
#define SLIM_TKLEN_HTCL_dimgray	(7)
#define SLIM_TKOFF_HTCL_dodgerblue	(SLIM_TKOFF_BASE_HTCL0 + 420)
#define SLIM_TKNAM_HTCL_dodgerblue	(SLIM_TKNAM_BASE_HTCL0 + 420)
#define SLIM_TKLEN_HTCL_dodgerblue	(10)
#define SLIM_TKOFF_HTCL_firebrick	(SLIM_TKOFF_BASE_HTCL0 + 431)
#define SLIM_TKNAM_HTCL_firebrick	(SLIM_TKNAM_BASE_HTCL0 + 431)
#define SLIM_TKLEN_HTCL_firebrick	(9)
#define SLIM_TKOFF_HTCL_floralwhite	(SLIM_TKOFF_BASE_HTCL0 + 441)
#define SLIM_TKNAM_HTCL_floralwhite	(SLIM_TKNAM_BASE_HTCL0 + 441)
#define SLIM_TKLEN_HTCL_floralwhite	(11)
#define SLIM_TKOFF_HTCL_forestgreen	(SLIM_TKOFF_BASE_HTCL0 + 453)
#define SLIM_TKNAM_HTCL_forestgreen	(SLIM_TKNAM_BASE_HTCL0 + 453)
#define SLIM_TKLEN_HTCL_forestgreen	(11)
#define SLIM_TKOFF_HTCL_fuchsia	(SLIM_TKOFF_BASE_HTCL0 + 465)
#define SLIM_TKNAM_HTCL_fuchsia	(SLIM_TKNAM_BASE_HTCL0 + 465)
#define SLIM_TKLEN_HTCL_fuchsia	(7)
#define SLIM_TKOFF_HTCL_gainsboro	(SLIM_TKOFF_BASE_HTCL0 + 473)
#define SLIM_TKNAM_HTCL_gainsboro	(SLIM_TKNAM_BASE_HTCL0 + 473)
#define SLIM_TKLEN_HTCL_gainsboro	(9)
#define SLIM_TKOFF_HTCL_ghostwhite	(SLIM_TKOFF_BASE_HTCL0 + 483)
#define SLIM_TKNAM_HTCL_ghostwhite	(SLIM_TKNAM_BASE_HTCL0 + 483)
#define SLIM_TKLEN_HTCL_ghostwhite	(10)
#define SLIM_TKOFF_HTCL_gold	(SLIM_TKOFF_BASE_HTCL0 + 494)
#define SLIM_TKNAM_HTCL_gold	(SLIM_TKNAM_BASE_HTCL0 + 494)
#define SLIM_TKLEN_HTCL_gold	(4)
#define SLIM_TKOFF_HTCL_goldenrod	(SLIM_TKOFF_BASE_HTCL0 + 499)
#define SLIM_TKNAM_HTCL_goldenrod	(SLIM_TKNAM_BASE_HTCL0 + 499)
#define SLIM_TKLEN_HTCL_goldenrod	(9)
#define SLIM_TKOFF_HTCL_gray	(SLIM_TKOFF_BASE_HTCL0 + 509)
#define SLIM_TKNAM_HTCL_gray	(SLIM_TKNAM_BASE_HTCL0 + 509)
#define SLIM_TKLEN_HTCL_gray	(4)
#define SLIM_TKOFF_HTCL_green	(SLIM_TKOFF_BASE_HTCL0 + 514)
#define SLIM_TKNAM_HTCL_green	(SLIM_TKNAM_BASE_HTCL0 + 514)
#define SLIM_TKLEN_HTCL_green	(5)
#define SLIM_TKOFF_HTCL_greenyellow	(SLIM_TKOFF_BASE_HTCL0 + 520)
#define SLIM_TKNAM_HTCL_greenyellow	(SLIM_TKNAM_BASE_HTCL0 + 520)
#define SLIM_TKLEN_HTCL_greenyellow	(11)
#define SLIM_TKOFF_HTCL_honeydew	(SLIM_TKOFF_BASE_HTCL0 + 532)
#define SLIM_TKNAM_HTCL_honeydew	(SLIM_TKNAM_BASE_HTCL0 + 532)
#define SLIM_TKLEN_HTCL_honeydew	(8)
#define SLIM_TKOFF_HTCL_hotpink	(SLIM_TKOFF_BASE_HTCL0 + 541)
#define SLIM_TKNAM_HTCL_hotpink	(SLIM_TKNAM_BASE_HTCL0 + 541)
#define SLIM_TKLEN_HTCL_hotpink	(7)
#define SLIM_TKOFF_HTCL_indianred	(SLIM_TKOFF_BASE_HTCL0 + 549)
#define SLIM_TKNAM_HTCL_indianred	(SLIM_TKNAM_BASE_HTCL0 + 549)
#define SLIM_TKLEN_HTCL_indianred	(9)
#define SLIM_TKOFF_HTCL_indigo	(SLIM_TKOFF_BASE_HTCL0 + 559)
#define SLIM_TKNAM_HTCL_indigo	(SLIM_TKNAM_BASE_HTCL0 + 559)
#define SLIM_TKLEN_HTCL_indigo	(6)
#define SLIM_TKOFF_HTCL_ivory	(SLIM_TKOFF_BASE_HTCL0 + 566)
#define SLIM_TKNAM_HTCL_ivory	(SLIM_TKNAM_BASE_HTCL0 + 566)
#define SLIM_TKLEN_HTCL_ivory	(5)
#define SLIM_TKOFF_HTCL_khaki	(SLIM_TKOFF_BASE_HTCL0 + 572)
#define SLIM_TKNAM_HTCL_khaki	(SLIM_TKNAM_BASE_HTCL0 + 572)
#define SLIM_TKLEN_HTCL_khaki	(5)
#define SLIM_TKOFF_HTCL_lavender	(SLIM_TKOFF_BASE_HTCL0 + 578)
#define SLIM_TKNAM_HTCL_lavender	(SLIM_TKNAM_BASE_HTCL0 + 578)
#define SLIM_TKLEN_HTCL_lavender	(8)
#define SLIM_TKOFF_HTCL_lavenderblush	(SLIM_TKOFF_BASE_HTCL0 + 587)
#define SLIM_TKNAM_HTCL_lavenderblush	(SLIM_TKNAM_BASE_HTCL0 + 587)
#define SLIM_TKLEN_HTCL_lavenderblush	(13)
#define SLIM_TKOFF_HTCL_lawngreen	(SLIM_TKOFF_BASE_HTCL0 + 601)
#define SLIM_TKNAM_HTCL_lawngreen	(SLIM_TKNAM_BASE_HTCL0 + 601)
#define SLIM_TKLEN_HTCL_lawngreen	(9)
#define SLIM_TKOFF_HTCL_lemonchiffon	(SLIM_TKOFF_BASE_HTCL0 + 611)
#define SLIM_TKNAM_HTCL_lemonchiffon	(SLIM_TKNAM_BASE_HTCL0 + 611)
#define SLIM_TKLEN_HTCL_lemonchiffon	(12)
#define SLIM_TKOFF_HTCL_lightblue	(SLIM_TKOFF_BASE_HTCL0 + 624)
#define SLIM_TKNAM_HTCL_lightblue	(SLIM_TKNAM_BASE_HTCL0 + 624)
#define SLIM_TKLEN_HTCL_lightblue	(9)
#define SLIM_TKOFF_HTCL_lightcoral	(SLIM_TKOFF_BASE_HTCL0 + 634)
#define SLIM_TKNAM_HTCL_lightcoral	(SLIM_TKNAM_BASE_HTCL0 + 634)
#define SLIM_TKLEN_HTCL_lightcoral	(10)
#define SLIM_TKOFF_HTCL_lightcyan	(SLIM_TKOFF_BASE_HTCL0 + 645)
#define SLIM_TKNAM_HTCL_lightcyan	(SLIM_TKNAM_BASE_HTCL0 + 645)
#define SLIM_TKLEN_HTCL_lightcyan	(9)
#define SLIM_TKOFF_HTCL_lightgoldenrodyellow	(SLIM_TKOFF_BASE_HTCL0 + 655)
#define SLIM_TKNAM_HTCL_lightgoldenrodyellow	(SLIM_TKNAM_BASE_HTCL0 + 655)
#define SLIM_TKLEN_HTCL_lightgoldenrodyellow	(20)
#define SLIM_TKOFF_HTCL_lightgray	(SLIM_TKOFF_BASE_HTCL0 + 676)
#define SLIM_TKNAM_HTCL_lightgray	(SLIM_TKNAM_BASE_HTCL0 + 676)
#define SLIM_TKLEN_HTCL_lightgray	(9)
#define SLIM_TKOFF_HTCL_lightgreen	(SLIM_TKOFF_BASE_HTCL0 + 686)
#define SLIM_TKNAM_HTCL_lightgreen	(SLIM_TKNAM_BASE_HTCL0 + 686)
#define SLIM_TKLEN_HTCL_lightgreen	(10)
#define SLIM_TKOFF_HTCL_lightgrey	(SLIM_TKOFF_BASE_HTCL0 + 697)
#define SLIM_TKNAM_HTCL_lightgrey	(SLIM_TKNAM_BASE_HTCL0 + 697)
#define SLIM_TKLEN_HTCL_lightgrey	(9)
#define SLIM_TKOFF_HTCL_lightpink	(SLIM_TKOFF_BASE_HTCL0 + 707)
#define SLIM_TKNAM_HTCL_lightpink	(SLIM_TKNAM_BASE_HTCL0 + 707)
#define SLIM_TKLEN_HTCL_lightpink	(9)
#define SLIM_TKOFF_HTCL_lightsalmon	(SLIM_TKOFF_BASE_HTCL0 + 717)
#define SLIM_TKNAM_HTCL_lightsalmon	(SLIM_TKNAM_BASE_HTCL0 + 717)
#define SLIM_TKLEN_HTCL_lightsalmon	(11)
#define SLIM_TKOFF_HTCL_lightseagreen	(SLIM_TKOFF_BASE_HTCL0 + 729)
#define SLIM_TKNAM_HTCL_lightseagreen	(SLIM_TKNAM_BASE_HTCL0 + 729)
#define SLIM_TKLEN_HTCL_lightseagreen	(13)
#define SLIM_TKOFF_HTCL_lightskyblue	(SLIM_TKOFF_BASE_HTCL0 + 743)
#define SLIM_TKNAM_HTCL_lightskyblue	(SLIM_TKNAM_BASE_HTCL0 + 743)
#define SLIM_TKLEN_HTCL_lightskyblue	(12)
#define SLIM_TKOFF_HTCL_lightslategray	(SLIM_TKOFF_BASE_HTCL0 + 756)
#define SLIM_TKNAM_HTCL_lightslategray	(SLIM_TKNAM_BASE_HTCL0 + 756)
#define SLIM_TKLEN_HTCL_lightslategray	(14)
#define SLIM_TKOFF_HTCL_lightsteelblue	(SLIM_TKOFF_BASE_HTCL0 + 771)
#define SLIM_TKNAM_HTCL_lightsteelblue	(SLIM_TKNAM_BASE_HTCL0 + 771)
#define SLIM_TKLEN_HTCL_lightsteelblue	(14)
#define SLIM_TKOFF_HTCL_lightyellow	(SLIM_TKOFF_BASE_HTCL0 + 786)
#define SLIM_TKNAM_HTCL_lightyellow	(SLIM_TKNAM_BASE_HTCL0 + 786)
#define SLIM_TKLEN_HTCL_lightyellow	(11)
#define SLIM_TKOFF_HTCL_lime	(SLIM_TKOFF_BASE_HTCL0 + 798)
#define SLIM_TKNAM_HTCL_lime	(SLIM_TKNAM_BASE_HTCL0 + 798)
#define SLIM_TKLEN_HTCL_lime	(4)
#define SLIM_TKOFF_HTCL_limegreen	(SLIM_TKOFF_BASE_HTCL0 + 803)
#define SLIM_TKNAM_HTCL_limegreen	(SLIM_TKNAM_BASE_HTCL0 + 803)
#define SLIM_TKLEN_HTCL_limegreen	(9)
#define SLIM_TKOFF_HTCL_linen	(SLIM_TKOFF_BASE_HTCL0 + 813)
#define SLIM_TKNAM_HTCL_linen	(SLIM_TKNAM_BASE_HTCL0 + 813)
#define SLIM_TKLEN_HTCL_linen	(5)
#define SLIM_TKOFF_HTCL_magenta	(SLIM_TKOFF_BASE_HTCL0 + 819)
#define SLIM_TKNAM_HTCL_magenta	(SLIM_TKNAM_BASE_HTCL0 + 819)
#define SLIM_TKLEN_HTCL_magenta	(7)
#define SLIM_TKOFF_HTCL_maroon	(SLIM_TKOFF_BASE_HTCL0 + 827)
#define SLIM_TKNAM_HTCL_maroon	(SLIM_TKNAM_BASE_HTCL0 + 827)
#define SLIM_TKLEN_HTCL_maroon	(6)
#define SLIM_TKOFF_HTCL_mediumaquamarine	(SLIM_TKOFF_BASE_HTCL0 + 834)
#define SLIM_TKNAM_HTCL_mediumaquamarine	(SLIM_TKNAM_BASE_HTCL0 + 834)
#define SLIM_TKLEN_HTCL_mediumaquamarine	(16)
#define SLIM_TKOFF_HTCL_mediumblue	(SLIM_TKOFF_BASE_HTCL0 + 851)
#define SLIM_TKNAM_HTCL_mediumblue	(SLIM_TKNAM_BASE_HTCL0 + 851)
#define SLIM_TKLEN_HTCL_mediumblue	(10)
#define SLIM_TKOFF_HTCL_mediumorchid	(SLIM_TKOFF_BASE_HTCL0 + 862)
#define SLIM_TKNAM_HTCL_mediumorchid	(SLIM_TKNAM_BASE_HTCL0 + 862)
#define SLIM_TKLEN_HTCL_mediumorchid	(12)
#define SLIM_TKOFF_HTCL_mediumpurple	(SLIM_TKOFF_BASE_HTCL0 + 875)
#define SLIM_TKNAM_HTCL_mediumpurple	(SLIM_TKNAM_BASE_HTCL0 + 875)
#define SLIM_TKLEN_HTCL_mediumpurple	(12)
#define SLIM_TKOFF_HTCL_mediumseagreen	(SLIM_TKOFF_BASE_HTCL0 + 888)
#define SLIM_TKNAM_HTCL_mediumseagreen	(SLIM_TKNAM_BASE_HTCL0 + 888)
#define SLIM_TKLEN_HTCL_mediumseagreen	(14)
#define SLIM_TKOFF_HTCL_mediumslateblue	(SLIM_TKOFF_BASE_HTCL0 + 903)
#define SLIM_TKNAM_HTCL_mediumslateblue	(SLIM_TKNAM_BASE_HTCL0 + 903)
#define SLIM_TKLEN_HTCL_mediumslateblue	(15)
#define SLIM_TKOFF_HTCL_mediumspringgreen	(SLIM_TKOFF_BASE_HTCL0 + 919)
#define SLIM_TKNAM_HTCL_mediumspringgreen	(SLIM_TKNAM_BASE_HTCL0 + 919)
#define SLIM_TKLEN_HTCL_mediumspringgreen	(17)
#define SLIM_TKOFF_HTCL_mediumturquoise	(SLIM_TKOFF_BASE_HTCL0 + 937)
#define SLIM_TKNAM_HTCL_mediumturquoise	(SLIM_TKNAM_BASE_HTCL0 + 937)
#define SLIM_TKLEN_HTCL_mediumturquoise	(15)
#define SLIM_TKOFF_HTCL_mediumvioletred	(SLIM_TKOFF_BASE_HTCL0 + 953)
#define SLIM_TKNAM_HTCL_mediumvioletred	(SLIM_TKNAM_BASE_HTCL0 + 953)
#define SLIM_TKLEN_HTCL_mediumvioletred	(15)
#define SLIM_TKOFF_HTCL_midnightblue	(SLIM_TKOFF_BASE_HTCL0 + 969)
#define SLIM_TKNAM_HTCL_midnightblue	(SLIM_TKNAM_BASE_HTCL0 + 969)
#define SLIM_TKLEN_HTCL_midnightblue	(12)
#define SLIM_TKOFF_HTCL_mintcream	(SLIM_TKOFF_BASE_HTCL0 + 982)
#define SLIM_TKNAM_HTCL_mintcream	(SLIM_TKNAM_BASE_HTCL0 + 982)
#define SLIM_TKLEN_HTCL_mintcream	(9)
#define SLIM_TKOFF_HTCL_mistyrose	(SLIM_TKOFF_BASE_HTCL0 + 992)
#define SLIM_TKNAM_HTCL_mistyrose	(SLIM_TKNAM_BASE_HTCL0 + 992)
#define SLIM_TKLEN_HTCL_mistyrose	(9)
#define SLIM_TKOFF_HTCL_moccasin	(SLIM_TKOFF_BASE_HTCL0 + 1002)
#define SLIM_TKNAM_HTCL_moccasin	(SLIM_TKNAM_BASE_HTCL0 + 1002)
#define SLIM_TKLEN_HTCL_moccasin	(8)
#define SLIM_TKOFF_HTCL_navajowhite	(SLIM_TKOFF_BASE_HTCL0 + 1011)
#define SLIM_TKNAM_HTCL_navajowhite	(SLIM_TKNAM_BASE_HTCL0 + 1011)
#define SLIM_TKLEN_HTCL_navajowhite	(11)
#define SLIM_TKOFF_HTCL_navy	(SLIM_TKOFF_BASE_HTCL0 + 1023)
#define SLIM_TKNAM_HTCL_navy	(SLIM_TKNAM_BASE_HTCL0 + 1023)
#define SLIM_TKLEN_HTCL_navy	(4)
#define SLIM_TKOFF_HTCL_oldlace	(SLIM_TKOFF_BASE_HTCL0 + 1028)
#define SLIM_TKNAM_HTCL_oldlace	(SLIM_TKNAM_BASE_HTCL0 + 1028)
#define SLIM_TKLEN_HTCL_oldlace	(7)
#define SLIM_TKOFF_HTCL_olive	(SLIM_TKOFF_BASE_HTCL0 + 1036)
#define SLIM_TKNAM_HTCL_olive	(SLIM_TKNAM_BASE_HTCL0 + 1036)
#define SLIM_TKLEN_HTCL_olive	(5)
#define SLIM_TKOFF_HTCL_olivedrab	(SLIM_TKOFF_BASE_HTCL0 + 1042)
#define SLIM_TKNAM_HTCL_olivedrab	(SLIM_TKNAM_BASE_HTCL0 + 1042)
#define SLIM_TKLEN_HTCL_olivedrab	(9)
#define SLIM_TKOFF_HTCL_orange	(SLIM_TKOFF_BASE_HTCL0 + 1052)
#define SLIM_TKNAM_HTCL_orange	(SLIM_TKNAM_BASE_HTCL0 + 1052)
#define SLIM_TKLEN_HTCL_orange	(6)
#define SLIM_TKOFF_HTCL_orangered	(SLIM_TKOFF_BASE_HTCL0 + 1059)
#define SLIM_TKNAM_HTCL_orangered	(SLIM_TKNAM_BASE_HTCL0 + 1059)
#define SLIM_TKLEN_HTCL_orangered	(9)
#define SLIM_TKOFF_HTCL_orchid	(SLIM_TKOFF_BASE_HTCL0 + 1069)
#define SLIM_TKNAM_HTCL_orchid	(SLIM_TKNAM_BASE_HTCL0 + 1069)
#define SLIM_TKLEN_HTCL_orchid	(6)
#define SLIM_TKOFF_HTCL_palegoldenrod	(SLIM_TKOFF_BASE_HTCL0 + 1076)
#define SLIM_TKNAM_HTCL_palegoldenrod	(SLIM_TKNAM_BASE_HTCL0 + 1076)
#define SLIM_TKLEN_HTCL_palegoldenrod	(13)
#define SLIM_TKOFF_HTCL_palegreen	(SLIM_TKOFF_BASE_HTCL0 + 1090)
#define SLIM_TKNAM_HTCL_palegreen	(SLIM_TKNAM_BASE_HTCL0 + 1090)
#define SLIM_TKLEN_HTCL_palegreen	(9)
#define SLIM_TKOFF_HTCL_paleturquoise	(SLIM_TKOFF_BASE_HTCL0 + 1100)
#define SLIM_TKNAM_HTCL_paleturquoise	(SLIM_TKNAM_BASE_HTCL0 + 1100)
#define SLIM_TKLEN_HTCL_paleturquoise	(13)
#define SLIM_TKOFF_HTCL_palevioletred	(SLIM_TKOFF_BASE_HTCL0 + 1114)
#define SLIM_TKNAM_HTCL_palevioletred	(SLIM_TKNAM_BASE_HTCL0 + 1114)
#define SLIM_TKLEN_HTCL_palevioletred	(13)
#define SLIM_TKOFF_HTCL_papayawhip	(SLIM_TKOFF_BASE_HTCL0 + 1128)
#define SLIM_TKNAM_HTCL_papayawhip	(SLIM_TKNAM_BASE_HTCL0 + 1128)
#define SLIM_TKLEN_HTCL_papayawhip	(10)
#define SLIM_TKOFF_HTCL_peachpuff	(SLIM_TKOFF_BASE_HTCL0 + 1139)
#define SLIM_TKNAM_HTCL_peachpuff	(SLIM_TKNAM_BASE_HTCL0 + 1139)
#define SLIM_TKLEN_HTCL_peachpuff	(9)
#define SLIM_TKOFF_HTCL_peru	(SLIM_TKOFF_BASE_HTCL0 + 1149)
#define SLIM_TKNAM_HTCL_peru	(SLIM_TKNAM_BASE_HTCL0 + 1149)
#define SLIM_TKLEN_HTCL_peru	(4)
#define SLIM_TKOFF_HTCL_pink	(SLIM_TKOFF_BASE_HTCL0 + 1154)
#define SLIM_TKNAM_HTCL_pink	(SLIM_TKNAM_BASE_HTCL0 + 1154)
#define SLIM_TKLEN_HTCL_pink	(4)
#define SLIM_TKOFF_HTCL_plum	(SLIM_TKOFF_BASE_HTCL0 + 1159)
#define SLIM_TKNAM_HTCL_plum	(SLIM_TKNAM_BASE_HTCL0 + 1159)
#define SLIM_TKLEN_HTCL_plum	(4)
#define SLIM_TKOFF_HTCL_powderblue	(SLIM_TKOFF_BASE_HTCL0 + 1164)
#define SLIM_TKNAM_HTCL_powderblue	(SLIM_TKNAM_BASE_HTCL0 + 1164)
#define SLIM_TKLEN_HTCL_powderblue	(10)
#define SLIM_TKOFF_HTCL_purple	(SLIM_TKOFF_BASE_HTCL0 + 1175)
#define SLIM_TKNAM_HTCL_purple	(SLIM_TKNAM_BASE_HTCL0 + 1175)
#define SLIM_TKLEN_HTCL_purple	(6)
#define SLIM_TKOFF_HTCL_red	(SLIM_TKOFF_BASE_HTCL0 + 1182)
#define SLIM_TKNAM_HTCL_red	(SLIM_TKNAM_BASE_HTCL0 + 1182)
#define SLIM_TKLEN_HTCL_red	(3)
#define SLIM_TKOFF_HTCL_rosybrown	(SLIM_TKOFF_BASE_HTCL0 + 1186)
#define SLIM_TKNAM_HTCL_rosybrown	(SLIM_TKNAM_BASE_HTCL0 + 1186)
#define SLIM_TKLEN_HTCL_rosybrown	(9)
#define SLIM_TKOFF_HTCL_royalblue	(SLIM_TKOFF_BASE_HTCL0 + 1196)
#define SLIM_TKNAM_HTCL_royalblue	(SLIM_TKNAM_BASE_HTCL0 + 1196)
#define SLIM_TKLEN_HTCL_royalblue	(9)
#define SLIM_TKOFF_HTCL_saddlebrown	(SLIM_TKOFF_BASE_HTCL0 + 1206)
#define SLIM_TKNAM_HTCL_saddlebrown	(SLIM_TKNAM_BASE_HTCL0 + 1206)
#define SLIM_TKLEN_HTCL_saddlebrown	(11)
#define SLIM_TKOFF_HTCL_salmon	(SLIM_TKOFF_BASE_HTCL0 + 1218)
#define SLIM_TKNAM_HTCL_salmon	(SLIM_TKNAM_BASE_HTCL0 + 1218)
#define SLIM_TKLEN_HTCL_salmon	(6)
#define SLIM_TKOFF_HTCL_sandybrown	(SLIM_TKOFF_BASE_HTCL0 + 1225)
#define SLIM_TKNAM_HTCL_sandybrown	(SLIM_TKNAM_BASE_HTCL0 + 1225)
#define SLIM_TKLEN_HTCL_sandybrown	(10)
#define SLIM_TKOFF_HTCL_seagreen	(SLIM_TKOFF_BASE_HTCL0 + 1236)
#define SLIM_TKNAM_HTCL_seagreen	(SLIM_TKNAM_BASE_HTCL0 + 1236)
#define SLIM_TKLEN_HTCL_seagreen	(8)
#define SLIM_TKOFF_HTCL_seashell	(SLIM_TKOFF_BASE_HTCL0 + 1245)
#define SLIM_TKNAM_HTCL_seashell	(SLIM_TKNAM_BASE_HTCL0 + 1245)
#define SLIM_TKLEN_HTCL_seashell	(8)
#define SLIM_TKOFF_HTCL_sienna	(SLIM_TKOFF_BASE_HTCL0 + 1254)
#define SLIM_TKNAM_HTCL_sienna	(SLIM_TKNAM_BASE_HTCL0 + 1254)
#define SLIM_TKLEN_HTCL_sienna	(6)
#define SLIM_TKOFF_HTCL_silver	(SLIM_TKOFF_BASE_HTCL0 + 1261)
#define SLIM_TKNAM_HTCL_silver	(SLIM_TKNAM_BASE_HTCL0 + 1261)
#define SLIM_TKLEN_HTCL_silver	(6)
#define SLIM_TKOFF_HTCL_skyblue	(SLIM_TKOFF_BASE_HTCL0 + 1268)
#define SLIM_TKNAM_HTCL_skyblue	(SLIM_TKNAM_BASE_HTCL0 + 1268)
#define SLIM_TKLEN_HTCL_skyblue	(7)
#define SLIM_TKOFF_HTCL_slateblue	(SLIM_TKOFF_BASE_HTCL0 + 1276)
#define SLIM_TKNAM_HTCL_slateblue	(SLIM_TKNAM_BASE_HTCL0 + 1276)
#define SLIM_TKLEN_HTCL_slateblue	(9)
#define SLIM_TKOFF_HTCL_slategray	(SLIM_TKOFF_BASE_HTCL0 + 1286)
#define SLIM_TKNAM_HTCL_slategray	(SLIM_TKNAM_BASE_HTCL0 + 1286)
#define SLIM_TKLEN_HTCL_slategray	(9)
#define SLIM_TKOFF_HTCL_snow	(SLIM_TKOFF_BASE_HTCL0 + 1296)
#define SLIM_TKNAM_HTCL_snow	(SLIM_TKNAM_BASE_HTCL0 + 1296)
#define SLIM_TKLEN_HTCL_snow	(4)
#define SLIM_TKOFF_HTCL_springgreen	(SLIM_TKOFF_BASE_HTCL0 + 1301)
#define SLIM_TKNAM_HTCL_springgreen	(SLIM_TKNAM_BASE_HTCL0 + 1301)
#define SLIM_TKLEN_HTCL_springgreen	(11)
#define SLIM_TKOFF_HTCL_steelblue	(SLIM_TKOFF_BASE_HTCL0 + 1313)
#define SLIM_TKNAM_HTCL_steelblue	(SLIM_TKNAM_BASE_HTCL0 + 1313)
#define SLIM_TKLEN_HTCL_steelblue	(9)
#define SLIM_TKOFF_HTCL_tan	(SLIM_TKOFF_BASE_HTCL0 + 1323)
#define SLIM_TKNAM_HTCL_tan	(SLIM_TKNAM_BASE_HTCL0 + 1323)
#define SLIM_TKLEN_HTCL_tan	(3)
#define SLIM_TKOFF_HTCL_teal	(SLIM_TKOFF_BASE_HTCL0 + 1327)
#define SLIM_TKNAM_HTCL_teal	(SLIM_TKNAM_BASE_HTCL0 + 1327)
#define SLIM_TKLEN_HTCL_teal	(4)
#define SLIM_TKOFF_HTCL_thistle	(SLIM_TKOFF_BASE_HTCL0 + 1332)
#define SLIM_TKNAM_HTCL_thistle	(SLIM_TKNAM_BASE_HTCL0 + 1332)
#define SLIM_TKLEN_HTCL_thistle	(7)
#define SLIM_TKOFF_HTCL_tomato	(SLIM_TKOFF_BASE_HTCL0 + 1340)
#define SLIM_TKNAM_HTCL_tomato	(SLIM_TKNAM_BASE_HTCL0 + 1340)
#define SLIM_TKLEN_HTCL_tomato	(6)
#define SLIM_TKOFF_HTCL_turquoise	(SLIM_TKOFF_BASE_HTCL0 + 1347)
#define SLIM_TKNAM_HTCL_turquoise	(SLIM_TKNAM_BASE_HTCL0 + 1347)
#define SLIM_TKLEN_HTCL_turquoise	(9)
#define SLIM_TKOFF_HTCL_violet	(SLIM_TKOFF_BASE_HTCL0 + 1357)
#define SLIM_TKNAM_HTCL_violet	(SLIM_TKNAM_BASE_HTCL0 + 1357)
#define SLIM_TKLEN_HTCL_violet	(6)
#define SLIM_TKOFF_HTCL_wheat	(SLIM_TKOFF_BASE_HTCL0 + 1364)
#define SLIM_TKNAM_HTCL_wheat	(SLIM_TKNAM_BASE_HTCL0 + 1364)
#define SLIM_TKLEN_HTCL_wheat	(5)
#define SLIM_TKOFF_HTCL_white	(SLIM_TKOFF_BASE_HTCL0 + 1370)
#define SLIM_TKNAM_HTCL_white	(SLIM_TKNAM_BASE_HTCL0 + 1370)
#define SLIM_TKLEN_HTCL_white	(5)
#define SLIM_TKOFF_HTCL_whitesmoke	(SLIM_TKOFF_BASE_HTCL0 + 1376)
#define SLIM_TKNAM_HTCL_whitesmoke	(SLIM_TKNAM_BASE_HTCL0 + 1376)
#define SLIM_TKLEN_HTCL_whitesmoke	(10)
#define SLIM_TKOFF_HTCL_yellow	(SLIM_TKOFF_BASE_HTCL0 + 1387)
#define SLIM_TKNAM_HTCL_yellow	(SLIM_TKNAM_BASE_HTCL0 + 1387)
#define SLIM_TKLEN_HTCL_yellow	(6)
#define SLIM_TKOFF_HTCL_yellowgreen	(SLIM_TKOFF_BASE_HTCL0 + 1394)
#define SLIM_TKNAM_HTCL_yellowgreen	(SLIM_TKNAM_BASE_HTCL0 + 1394)
#define SLIM_TKLEN_HTCL_yellowgreen	(11)
#define SLIM_TKOFF_BASE_HTCL1	(SLIM_TKOFF_BASE_HTCL0 + 1406)
#define SLIM_TKNAM_BASE_HTCL1	(SLIM_TKNAM_BASE_HTCL0 + SLIM_TKOFF_BASE_HTCL1)
#define SLIM_TKLEN_TOTAL_HTCL	SLIM_TKOFF_BASE_HTCL1

extern SLIM_ROM slim_char cSlim_TokenName_HTCL[SLIM_TKLEN_TOTAL_HTCL];

extern SLIM_ROM THTMLColorInfo cSlim_Token_HTCL[SLIM_TOKEN_HTCL_TOKENS];
#define HTMLColorInfo_GetItem(id)		((THTMLColorInfo *)&cSlim_Token_HTCL[(id)])
#define HTMLColorInfo_GetItemName(id)	((slim_char *)cSlim_TokenName_HTCL + ((TToken *)&cSlim_Token_HTCL[(id)])->fOffset)
#define HTMLColorInfo_GetItemNameLen(id)	(((TToken *)&cSlim_Token_HTCL[(id)])->fLength)

THTMLColorInfo *HTMLColorInfo_FindSS(slim_char *in_s, slim_int in_slen);

SLIM_END_C_LINKAGE
#endif
