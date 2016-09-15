/*
	guibase.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/basis/guibase.h 97    06/08/22 20:28 Someya $ */

#ifndef SLIM_GUIBASE_H
#define SLIM_GUIBASE_H

SLIM_BEGIN_C_LINKAGE

/* Color */
typedef slim_word TColor;

#ifdef SLIM_CONFIG_COLOR_ALPHA_TRANSPARENT
#define SLIM_COLOR_ALPHA_TRANSPARENT (0xFF)
#define SLIM_COLOR_ALPHA_OPAQUE (0x00)
#define SLIM_COLOR_ALPHA_TO_TRANSPARENT(a) (a)
#define SLIM_COLOR_ALPHA_TO_OPAQUE(a) (0xFF-(a))
#define SLIM_COLOR_ALPHA_IS_OPAQUE(c) (((c)&0xFF)!=0xFF)
#define SLIM_COLOR_TRANSPARENT_TO_ALPHA(t) (t)
#define SLIM_COLOR_OPAQUE_TO_ALPHA(o) (0xFF-(o))
#define SLIM_COLOR_PEEK_TRANSPARENT(c) (((c)>>24)&0xFF)
#define SLIM_COLOR_PEEK_OPAQUE(c) ((~((c)>>24))&0xFF)
#endif
#ifdef SLIM_CONFIG_COLOR_ALPHA_OPAQUE
#define SLIM_COLOR_ALPHA_TRANSPARENT (0x00)
#define SLIM_COLOR_ALPHA_OPAQUE (0xFF)
#define SLIM_COLOR_ALPHA_TO_TRANSPARENT(a) (0xFF-(a))
#define SLIM_COLOR_ALPHA_TO_OPAQUE(a) (a)
#define SLIM_COLOR_ALPHA_IS_OPAQUE(c) (((c)&0xFF)!=0x00)
#define SLIM_COLOR_TRANSPARENT_TO_ALPHA(t) (0xFF-(t))
#define SLIM_COLOR_OPAQUE_TO_ALPHA(o) (o)
#define SLIM_COLOR_PEEK_TRANSPARENT(c) ((~((c)>>24))&0xFF)
#define SLIM_COLOR_PEEK_OPAQUE(c) (((c)>>24)&0xFF)
#endif

#ifdef SLIM_CONFIG_COLOR_RGB
#define SLIM_COLOR_ARGB(a,r,g,b) ((TColor)(a)<<24|(TColor)(r)<<16|(TColor)(g)<<8|(TColor)(b))
#define SLIM_COLOR_RGB(r,g,b) ((TColor)SLIM_COLOR_ALPHA_OPAQUE<<24|(TColor)(r)<<16|(TColor)(g)<<8|(TColor)(b))
#define SLIM_COLOR_PEEK_ALPHA(c) (((c)>>24)&0xFF)
#define SLIM_COLOR_PEEK_RED(c) (((c)>>16)&0xFF)
#define SLIM_COLOR_PEEK_GREEN(c) (((c)>>8)&0xFF)
#define SLIM_COLOR_PEEK_BLUE(c) ((c)&0xFF)
#endif
#ifdef SLIM_CONFIG_COLOR_BGR
#define SLIM_COLOR_ARGB(a,r,g,b) ((TColor)(a)<<24|(TColor)(b)<<16|(TColor)(g)<<8|(TColor)(r))
#define SLIM_COLOR_RGB(r,g,b) ((TColor)SLIM_COLOR_ALPHA_OPAQUE<<24|(TColor)(b)<<16|(TColor)(g)<<8|(TColor)(r))
#define SLIM_COLOR_PEEK_ALPHA(c) (((c)>>24)&0xFF)
#define SLIM_COLOR_PEEK_RED(c) ((c)&0xFF)
#define SLIM_COLOR_PEEK_GREEN(c) (((c)>>8)&0xFF)
#define SLIM_COLOR_PEEK_BLUE(c) (((c)>>16)&0xFF)
#endif

#define SLIM_COLOR_WHITE		SLIM_COLOR_RGB(255, 255, 255)
#define SLIM_COLOR_LIGHTGRAY	SLIM_COLOR_RGB(192, 192, 192)
#define SLIM_COLOR_GRAY 		SLIM_COLOR_RGB(128, 128, 128)
#define SLIM_COLOR_DARKGRAY 	SLIM_COLOR_RGB(64, 64, 64)
#define SLIM_COLOR_BLACK		SLIM_COLOR_RGB(0, 0, 0)
#define SLIM_COLOR_RED			SLIM_COLOR_RGB(255, 0, 0)
#define SLIM_COLOR_PINK 		SLIM_COLOR_RGB(255, 175, 175)
#define SLIM_COLOR_ORANGE		SLIM_COLOR_RGB(255, 200, 0)
#define SLIM_COLOR_YELLOW		SLIM_COLOR_RGB(255, 255, 0)
#define SLIM_COLOR_GREEN		SLIM_COLOR_RGB(0, 255, 0)
#define SLIM_COLOR_MAGENTA		SLIM_COLOR_RGB(255, 0, 255)
#define SLIM_COLOR_CYAN 		SLIM_COLOR_RGB(0, 255, 255)
#define SLIM_COLOR_BLUE 		SLIM_COLOR_RGB(0, 0, 255)
#define SLIM_COLOR_TRANSPARENT	SLIM_COLOR_ARGB(SLIM_COLOR_ALPHA_TRANSPARENT, 0, 0, 0)


/* Rect */
struct TRect_ {
	slim_int fX;
	slim_int fY;
	slim_int fWidth;
	slim_int fHeight;
};
typedef struct TRect_ TRect;


enum {
	SLIM_EDGE_LEFT = 0,
	SLIM_EDGE_TOP = 1,
	SLIM_EDGE_RIGHT = 2,
	SLIM_EDGE_BOTTOM = 3,

	SLIM_EDGES
};
#define TRect_InsetEdgesA(self, ea) TRect_InsetEdges((self), (ea)[SLIM_EDGE_TOP], (ea)[SLIM_EDGE_RIGHT], (ea)[SLIM_EDGE_BOTTOM], (ea)[SLIM_EDGE_LEFT])

/* Region */

typedef struct iTRegion_ iTRegion;
struct iTRegion_ {
	TSpecList fRectList;
#ifdef SLIM_CONFIG_MEMORY_DEBUG
	slim_int fFrom;
#endif
};

#define Region_Initialize()
#define Region_Finalize()

typedef TListVisit	iTRegionVisit;
struct TRegionVisit_ {
	iTRegionVisit fBase;
	iTRegion *fLockPtr;
};
typedef struct TRegionVisit_ TRegionVisit;


/*       */
/* event */
/*       */

/* event ID base constant */
#define SLIM_EVENTBASE_RAW			0x0000
#define SLIM_EVENTBASE_GENERIC		0x1000
#define SLIM_EVENTBASE_EXTEND		0x2000
#define SLIM_EVENTBASE_USER			0x3000

/* raw event ID constant */
enum {
	SLIM_EVENT_COMMAND				= -1,
	SLIM_EVENT_NIL  				= SLIM_EVENTBASE_RAW,
	SLIM_EVENT_KEYPRESS,
	SLIM_EVENT_KEYRELEASE,
	SLIM_EVENT_MOUSEDOWN,
	SLIM_EVENT_MOUSEUP,
	SLIM_EVENT_MOUSEMOVE,
	SLIM_EVENT_MOUSEWHEEL,
	SLIM_EVENT_CLICK,
	SLIM_EVENT_DBLCLICK,
	SLIM_EVENT_CONTEXTMENU,
	SLIM_EVENT_PAINT
};

/* generic event ID constant */
enum {
	SLIM_EVENT_INITIALIZE			= SLIM_EVENTBASE_GENERIC,
	SLIM_EVENT_FINALIZE,
	SLIM_EVENT_CALCCONTENTRECT,
	SLIM_EVENT_ACTIVATE,
	SLIM_EVENT_DEACTIVATE,
	SLIM_EVENT_MOUSEENTER,
	SLIM_EVENT_MOUSEEXIT,
	SLIM_EVENT_MOUSEDRAG,
	SLIM_EVENT_BEGINDIALOG,
	SLIM_EVENT_ENDDIALOG,
	SLIM_EVENT_KEYACTION,
	SLIM_EVENT_ACTION,
	SLIM_EVENT_GOTFOCUS,
	SLIM_EVENT_LOSTFOCUS,
	SLIM_EVENT_PICK,
	SLIM_EVENT_CALCSCROLLRECTS,
	SLIM_EVENT_SCROLLPAINT,
	SLIM_EVENT_SCROLLLINEUP,
	SLIM_EVENT_SCROLLLINEDOWN,
	SLIM_EVENT_SCROLLPAGEUP,
	SLIM_EVENT_SCROLLPAGEDOWN,
	SLIM_EVENT_SCROLLABSOLUTE,
	SLIM_EVENT_FRAMEACTIVATE,
	SLIM_EVENT_FRAMEDEACTIVATE,
	SLIM_EVENT_FRAMEPAINT,
	SLIM_EVENT_FRAMEMOUSEDOWN,
	SLIM_EVENT_FRAMEMOUSEUP,
	SLIM_EVENT_FRAMEMOUSEMOVE,
	SLIM_EVENT_FRAMEMOUSEWHEEL,
	SLIM_EVENT_SHOW,
	SLIM_EVENT_HIDE,
	SLIM_EVENT_ENABLE,
	SLIM_EVENT_DISABLE,
	SLIM_EVENT_RESHAPE,
	SLIM_EVENT_WML_ACTION,
	SLIM_EVENT_SKIN_CHANGED,
	SLIM_EVENT_UPDATEGUIDANCE
};

/*            */
/* font style */
/*            */

enum {
	SLIM_FONT_SIZE_XXXLARGE	= -1,
	SLIM_FONT_SIZE_XXLARGE	= -2,
	SLIM_FONT_SIZE_XLARGE	= -3,
	SLIM_FONT_SIZE_LARGE	= -4,
	SLIM_FONT_SIZE_MEDIUM	= -5,
	SLIM_FONT_SIZE_SMALL	= -6,
	SLIM_FONT_SIZE_XSMALL	= -7,
	SLIM_FONT_SIZE_XXSMALL	= -8,
	SLIM_FONT_SIZE_enums	= 9
};

enum {
	SLIM_FONT_STRETCH_ULTRAEXPANDED = 0,
	SLIM_FONT_STRETCH_EXTRAEXPANDED,
	SLIM_FONT_STRETCH_EXPANDED,
	SLIM_FONT_STRETCH_SEMIEXPANDED,
	SLIM_FONT_STRETCH_NORMAL,
	SLIM_FONT_STRETCH_SEMICONDENSED,
	SLIM_FONT_STRETCH_CONDENSED,
	SLIM_FONT_STRETCH_EXTRACONDENSED,
	SLIM_FONT_STRETCH_ULTRACONDENSED,
	SLIM_FONT_STRETCH_enums
};

enum {
	SLIM_FONT_STYLE_NORMAL = 0,
	SLIM_FONT_STYLE_ITALIC,
	SLIM_FONT_STYLE_OBLIQUE,
	SLIM_FONT_STYLE_enums
};

enum {
	SLIM_FONT_VARIANT_NORMAL = 0,
	SLIM_FONT_VARIANT_SMALLCAPS,
	SLIM_FONT_VARIANT_enums
};

enum {
	SLIM_FONT_WEIGHT_100 = 0,
	SLIM_FONT_WEIGHT_200,
	SLIM_FONT_WEIGHT_300,
	SLIM_FONT_WEIGHT_400,
	SLIM_FONT_WEIGHT_500,
	SLIM_FONT_WEIGHT_600,
	SLIM_FONT_WEIGHT_700,
	SLIM_FONT_WEIGHT_800,
	SLIM_FONT_WEIGHT_900,
	SLIM_FONT_WEIGHT_enums,
	/* aliases */
	SLIM_FONT_WEIGHT_NORMAL = SLIM_FONT_WEIGHT_400,
	SLIM_FONT_WEIGHT_BOLD = SLIM_FONT_WEIGHT_700
};

struct TFontStyle_ {
	slim_int fFontSize;
	slim_int fFontSizeAdjust;								/* CSS2 */
	slim_byte fFontStretch;									/* CSS2 */
	slim_byte fFontStyle;
	slim_byte fFontVariant;
	slim_byte fFontWeight;
};
typedef struct TFontStyle_ TFontStyle;

struct TFontStyleSet_ {
	slim_byte fFontSize;
	slim_byte fFontSizeAdjust;								/* CSS2 */
	slim_byte fFontStretch;									/* CSS2 */
	slim_byte fFontStyle;
	slim_byte fFontVariant;
	slim_byte fFontWeight;
};
typedef struct TFontStyleSet_ TFontStyleSet;


/*      */
/* font */
/*      */

typedef slim_int TFont;
#define SLIM_SYSTEM_FONT	((TFont)0)

struct TFontMetrics_ {
	slim_int fAscent;
	slim_int fDescent;
	slim_int fHeight;
	slim_int fMinWidth;
	slim_int fMaxWidth;
};
typedef struct TFontMetrics_ TFontMetrics;

/*             */
/* virtual key */
/*             */
/*
	The rule with the name, The value and some of the comments are
	from java.awt.event.KeyEvent of JDK 1.3.

	Except for Basic and Modified Key Groups, use isn't recommended
	because target dependence is very strong.

	The value which is undefined are the followings.

		0x0001, 0x0002, 0x0004 - 0x0007, 0x000B, 0x000D - 0x000F,
		0x0016, 0x0017, 0x001A, 0x0029 - 0x002B, 0x003A, 0x003C, 0x003E - 0x0040,
		0x005E, 0x005F, 0x007C - 0x007E, 0x0092 - 0x0095, 0x009E, 0x009F,
		0x00A3 - 0x00BF, 0x00D0 - 0x00DC, 0x00DF, 0x00E4 - 0x00EF, 0x00F6 - 0x00FF,
		0x0108 - 0x01FF, 0x020C - 0xEFFF, 0xF00C - 0xFF1F, 0xFF21 - 0xFF7D, 0xFF7F - 0xFFC7,
		0xFFCC, 0xFFCE, 0xFFD2 - 0xFFFF
*/

/* undefined char constant */ /* see slim/.../guibase.h */
#define SLIM_CHAR_UNDEFINED 0xFFFF

/* virtual key ID base constant */
#define SLIM_VKBASE 0x10000

/* Basic Group */
#define SLIM_VK_UNDEFINED	(SLIM_VKBASE + 0x0000)
#define SLIM_VK_BACK_SPACE	(SLIM_VKBASE + 0x0008)
#define SLIM_VK_TAB			(SLIM_VKBASE + 0x0009)
#define SLIM_VK_ENTER		(SLIM_VKBASE + SLIM_INTERNAL_NEWLINE) /* 0x0A */
#define SLIM_VK_ESCAPE		(SLIM_VKBASE + 0x001B)
#define SLIM_VK_DELETE		(SLIM_VKBASE + 0x007F)
#define SLIM_VK_INSERT		(SLIM_VKBASE + 0x009B)

#define SLIM_VK_PAGE_UP		(SLIM_VKBASE + 0x0021)
#define SLIM_VK_PAGE_DOWN	(SLIM_VKBASE + 0x0022)
#define SLIM_VK_END			(SLIM_VKBASE + 0x0023)
#define SLIM_VK_HOME		(SLIM_VKBASE + 0x0024)
#define SLIM_VK_LEFT		(SLIM_VKBASE + 0x0025)
#define SLIM_VK_UP			(SLIM_VKBASE + 0x0026)
#define SLIM_VK_RIGHT		(SLIM_VKBASE + 0x0027)
#define SLIM_VK_DOWN		(SLIM_VKBASE + 0x0028)

#define SLIM_VK_SPACE		(SLIM_VKBASE + 0x0020)

#define SLIM_VK_0			(SLIM_VKBASE + 0x0030)
#define SLIM_VK_1			(SLIM_VKBASE + 0x0031)
#define SLIM_VK_2			(SLIM_VKBASE + 0x0032)
#define SLIM_VK_3			(SLIM_VKBASE + 0x0033)
#define SLIM_VK_4			(SLIM_VKBASE + 0x0034)
#define SLIM_VK_5			(SLIM_VKBASE + 0x0035)
#define SLIM_VK_6			(SLIM_VKBASE + 0x0036)
#define SLIM_VK_7			(SLIM_VKBASE + 0x0037)
#define SLIM_VK_8			(SLIM_VKBASE + 0x0038)
#define SLIM_VK_9			(SLIM_VKBASE + 0x0039)

#define SLIM_VK_A			(SLIM_VKBASE + 0x0041)
#define SLIM_VK_B			(SLIM_VKBASE + 0x0042)
#define SLIM_VK_C			(SLIM_VKBASE + 0x0043)
#define SLIM_VK_D			(SLIM_VKBASE + 0x0044)
#define SLIM_VK_E			(SLIM_VKBASE + 0x0045)
#define SLIM_VK_F			(SLIM_VKBASE + 0x0046)
#define SLIM_VK_G			(SLIM_VKBASE + 0x0047)
#define SLIM_VK_H			(SLIM_VKBASE + 0x0048)
#define SLIM_VK_I			(SLIM_VKBASE + 0x0049)
#define SLIM_VK_J			(SLIM_VKBASE + 0x004A)
#define SLIM_VK_K			(SLIM_VKBASE + 0x004B)
#define SLIM_VK_L			(SLIM_VKBASE + 0x004C)
#define SLIM_VK_M			(SLIM_VKBASE + 0x004D)
#define SLIM_VK_N			(SLIM_VKBASE + 0x004E)
#define SLIM_VK_O			(SLIM_VKBASE + 0x004F)
#define SLIM_VK_P			(SLIM_VKBASE + 0x0050)
#define SLIM_VK_Q			(SLIM_VKBASE + 0x0051)
#define SLIM_VK_R			(SLIM_VKBASE + 0x0052)
#define SLIM_VK_S			(SLIM_VKBASE + 0x0053)
#define SLIM_VK_T			(SLIM_VKBASE + 0x0054)
#define SLIM_VK_U			(SLIM_VKBASE + 0x0055)
#define SLIM_VK_V			(SLIM_VKBASE + 0x0056)
#define SLIM_VK_W			(SLIM_VKBASE + 0x0057)
#define SLIM_VK_X			(SLIM_VKBASE + 0x0058)
#define SLIM_VK_Y			(SLIM_VKBASE + 0x0059)
#define SLIM_VK_Z			(SLIM_VKBASE + 0x005A)

#define SLIM_VK_F1			(SLIM_VKBASE + 0x0070)
#define SLIM_VK_F2			(SLIM_VKBASE + 0x0071)
#define SLIM_VK_F3			(SLIM_VKBASE + 0x0072)
#define SLIM_VK_F4			(SLIM_VKBASE + 0x0073)
#define SLIM_VK_F5			(SLIM_VKBASE + 0x0074)
#define SLIM_VK_F6			(SLIM_VKBASE + 0x0075)
#define SLIM_VK_F7			(SLIM_VKBASE + 0x0076)
#define SLIM_VK_F8			(SLIM_VKBASE + 0x0077)
#define SLIM_VK_F9			(SLIM_VKBASE + 0x0078)
#define SLIM_VK_F10			(SLIM_VKBASE + 0x0079)
#define SLIM_VK_F11			(SLIM_VKBASE + 0x007A)
#define SLIM_VK_F12			(SLIM_VKBASE + 0x007B)

/* Modifier Key Group */
#define SLIM_VK_SHIFT	(SLIM_VKBASE + 0x0010)
#define SLIM_VK_CONTROL	(SLIM_VKBASE + 0x0011)
#define SLIM_VK_ALT		(SLIM_VKBASE + 0x0012)
#define SLIM_VK_META	(SLIM_VKBASE + 0x009D)

/* Number Pad Group */
#define SLIM_VK_NUMPAD0		(SLIM_VKBASE + 0x0060)
#define SLIM_VK_NUMPAD1		(SLIM_VKBASE + 0x0061)
#define SLIM_VK_NUMPAD2		(SLIM_VKBASE + 0x0062)
#define SLIM_VK_NUMPAD3		(SLIM_VKBASE + 0x0063)
#define SLIM_VK_NUMPAD4		(SLIM_VKBASE + 0x0064)
#define SLIM_VK_NUMPAD5		(SLIM_VKBASE + 0x0065)
#define SLIM_VK_NUMPAD6		(SLIM_VKBASE + 0x0066)
#define SLIM_VK_NUMPAD7		(SLIM_VKBASE + 0x0067)
#define SLIM_VK_NUMPAD8		(SLIM_VKBASE + 0x0068)
#define SLIM_VK_NUMPAD9		(SLIM_VKBASE + 0x0069)
#define SLIM_VK_MULTIPLY	(SLIM_VKBASE + 0x006A)
#define SLIM_VK_ADD			(SLIM_VKBASE + 0x006B)
#define SLIM_VK_SEPARATER	(SLIM_VKBASE + 0x006C)
#define SLIM_VK_SUBTRACT	(SLIM_VKBASE + 0x006D)
#define SLIM_VK_DECIMAL		(SLIM_VKBASE + 0x006E)
#define SLIM_VK_DIVIDE		(SLIM_VKBASE + 0x006F)

/* Key Pad Group */
#define SLIM_VK_KP_UP		(SLIM_VKBASE + 0x00E0)
#define SLIM_VK_KP_DOWN		(SLIM_VKBASE + 0x00E1)
#define SLIM_VK_KP_LEFT		(SLIM_VKBASE + 0x00E2)
#define SLIM_VK_KP_RIGHT	(SLIM_VKBASE + 0x00E3)

/* Extended Function Key Group (IBM 3270 keyboard) */
#define SLIM_VK_F13	(SLIM_VKBASE + 0xF000)
#define SLIM_VK_F14	(SLIM_VKBASE + 0xF001)
#define SLIM_VK_F15	(SLIM_VKBASE + 0xF002)
#define SLIM_VK_F16	(SLIM_VKBASE + 0xF003)
#define SLIM_VK_F17	(SLIM_VKBASE + 0xF004)
#define SLIM_VK_F18	(SLIM_VKBASE + 0xF005)
#define SLIM_VK_F19	(SLIM_VKBASE + 0xF006)
#define SLIM_VK_F20	(SLIM_VKBASE + 0xF007)
#define SLIM_VK_F21	(SLIM_VKBASE + 0xF008)
#define SLIM_VK_F22	(SLIM_VKBASE + 0xF009)
#define SLIM_VK_F23	(SLIM_VKBASE + 0xF00A)
#define SLIM_VK_F24	(SLIM_VKBASE + 0xF00B)

/*  European Keyboards Group */
#define SLIM_VK_DEAD_GRAVE				(SLIM_VKBASE + 0x0080)
#define SLIM_VK_DEAD_ACUTE				(SLIM_VKBASE + 0x0081)
#define SLIM_VK_DEAD_CIRCUMFLEX			(SLIM_VKBASE + 0x0082)
#define SLIM_VK_DEAD_TILDE				(SLIM_VKBASE + 0x0083)
#define SLIM_VK_DEAD_MACRON				(SLIM_VKBASE + 0x0084)
#define SLIM_VK_DEAD_BREVE				(SLIM_VKBASE + 0x0085)
#define SLIM_VK_DEAD_ABOVEDOT			(SLIM_VKBASE + 0x0086)
#define SLIM_VK_DEAD_DIAERESIS			(SLIM_VKBASE + 0x0087)
#define SLIM_VK_DEAD_ABOVERING			(SLIM_VKBASE + 0x0088)
#define SLIM_VK_DEAD_DOUBLEACUTE		(SLIM_VKBASE + 0x0089)
#define SLIM_VK_DEAD_CARON				(SLIM_VKBASE + 0x008A)
#define SLIM_VK_DEAD_CEDILLA			(SLIM_VKBASE + 0x008B)
#define SLIM_VK_DEAD_OGONEK				(SLIM_VKBASE + 0x008C)
#define SLIM_VK_DEAD_IOTA				(SLIM_VKBASE + 0x008D)
#define SLIM_VK_DEAD_VOICED_SOUND		(SLIM_VKBASE + 0x008E)
#define SLIM_VK_DEAD_SEMIVOICED_SOUND	(SLIM_VKBASE + 0x008F)

/*  Sun Keyboards Group */
#define SLIM_VK_STOP	(SLIM_VKBASE + 0xFFC8)
#define SLIM_VK_AGAIN	(SLIM_VKBASE + 0xFFC9)
#define SLIM_VK_PROPS	(SLIM_VKBASE + 0xFFCA)
#define SLIM_VK_UNDO	(SLIM_VKBASE + 0xFFCB)
#define SLIM_VK_COPY	(SLIM_VKBASE + 0xFFCD)
#define SLIM_VK_PASTE	(SLIM_VKBASE + 0xFFCF)
#define SLIM_VK_FIND	(SLIM_VKBASE + 0xFFD0)
#define SLIM_VK_CUT		(SLIM_VKBASE + 0xFFD1)

/* Miscellaneous 0 */
#define SLIM_VK_CANCEL		(SLIM_VKBASE + 0x0003)
#define SLIM_VK_CLEAR		(SLIM_VKBASE + 0x000C)
#define SLIM_VK_PAUSE		(SLIM_VKBASE + 0x0013)
#define SLIM_VK_CAPS_LOCK	(SLIM_VKBASE + 0x0014)
#define SLIM_VK_NUM_LOCK	(SLIM_VKBASE + 0x0090)
#define SLIM_VK_SCROLL_LOCK	(SLIM_VKBASE + 0x0091)
#define SLIM_VK_PRINTSCREEN	(SLIM_VKBASE + 0x009A)
#define SLIM_VK_HELP		(SLIM_VKBASE + 0x009C)
#define SLIM_VK_COMPOSE		(SLIM_VKBASE + 0xFF20)
#define SLIM_VK_ALT_GRAPH	(SLIM_VKBASE + 0xFF7E)

/* Miscellaneous 1 */
#define SLIM_VK_COMMA						(SLIM_VKBASE + 0x002C) /* , */
#define SLIM_VK_MINUS						(SLIM_VKBASE + 0x002D) /* - */
#define SLIM_VK_PERIOD						(SLIM_VKBASE + 0x002E) /* . */
#define SLIM_VK_SLASH						(SLIM_VKBASE + 0x002F) /* / */
#define SLIM_VK_SEMICOLON					(SLIM_VKBASE + 0x003B) /* ; */
#define SLIM_VK_EQUALS						(SLIM_VKBASE + 0x003D) /* = */
#define SLIM_VK_OPEN_BRACKET				(SLIM_VKBASE + 0x005B) /* [ */
#define SLIM_VK_BACK_SLASH					(SLIM_VKBASE + 0x005C) /* \ */
#define SLIM_VK_CLOSE_BRACKET				(SLIM_VKBASE + 0x005D) /* ] */
#define SLIM_VK_AMPERSAND					(SLIM_VKBASE + 0x0096) /* & */
#define SLIM_VK_ASTERISK					(SLIM_VKBASE + 0x0097) /* * */
#define SLIM_VK_QUOTEDBL					(SLIM_VKBASE + 0x0098) /* " */
#define SLIM_VK_LESS						(SLIM_VKBASE + 0x0099) /* < */
#define SLIM_VK_GREATER						(SLIM_VKBASE + 0x00A0) /* > */
#define SLIM_VK_BRACELEFT					(SLIM_VKBASE + 0x00A1) /* { */
#define SLIM_VK_BRACERIGHT					(SLIM_VKBASE + 0x00A2) /* } */
#define SLIM_VK_BACK_QUOTE					(SLIM_VKBASE + 0x00C0) /* ` */
#define SLIM_VK_QUOTE						(SLIM_VKBASE + 0x00DE) /* ' */
#define SLIM_VK_AT							(SLIM_VKBASE + 0x0200) /* @ */
#define SLIM_VK_COLON						(SLIM_VKBASE + 0x0201) /* : */
#define SLIM_VK_CIRCUMFLEX					(SLIM_VKBASE + 0x0202) /* ^ */
#define SLIM_VK_DOLLAR						(SLIM_VKBASE + 0x0203) /* $ */
#define SLIM_VK_EURO_SIGN					(SLIM_VKBASE + 0x0204) /*   */
#define SLIM_VK_EXCLAMATION_MARK			(SLIM_VKBASE + 0x0205) /* ! */
#define SLIM_VK_INVERTED_EXCLAMATION_MARK	(SLIM_VKBASE + 0x0206) /*   */
#define SLIM_VK_LEFT_PARENTHESIS			(SLIM_VKBASE + 0x0207) /* ( */
#define SLIM_VK_NUMBER_SIGN					(SLIM_VKBASE + 0x0208) /* # */
#define SLIM_VK_PLUS						(SLIM_VKBASE + 0x0209) /* + */
#define SLIM_VK_RIGHT_PARENTHESIS			(SLIM_VKBASE + 0x020A) /* ( */
#define SLIM_VK_UNDERSCORE					(SLIM_VKBASE + 0x020B) /* _ */

/* IME Group */
#define SLIM_VK_CONVERT				(SLIM_VKBASE + 0x001C) /* Japanese PC 106 keyboard, Japanese Solaris keyboard: henkan */
#define SLIM_VK_NONCONVERT			(SLIM_VKBASE + 0x001D) /* Japanese PC 106 keyboard: muhenkan */
#define SLIM_VK_ACCEPT				(SLIM_VKBASE + 0x001E) /* Japanese Solaris keyboard: kakutei */
#define SLIM_VK_ALPHANUMERIC		(SLIM_VKBASE + 0x00F0) /* Japanese PC 106 keyboard: eisuu */
#define SLIM_VK_KATAKANA			(SLIM_VKBASE + 0x00F1) /* Japanese PC 106 keyboard - VK_HIRAGANA + SHIFT: katakana */
#define SLIM_VK_HIRAGANA			(SLIM_VKBASE + 0x00F2) /* Japanese PC 106 keyboard: hiragana */
#define SLIM_VK_FULL_WIDTH			(SLIM_VKBASE + 0x00F3) /* Japanese PC 106 keyboard: zenkaku */
#define SLIM_VK_HALF_WIDTH			(SLIM_VKBASE + 0x00F4) /* Japanese PC 106 keyboard: hankaku */
#define SLIM_VK_ROMAN_CHARACTERS	(SLIM_VKBASE + 0x00F5) /* Japanese PC 106 keyboard - VK_HIRAGANA + ALT: roumaji */
#define SLIM_VK_ALL_CANDIDATES		(SLIM_VKBASE + 0x0100) /* Japanese PC 106 keyboard - VK_CONVERT + ALT: zenkouho */
#define SLIM_VK_PREVIOUS_CANDIDATE	(SLIM_VKBASE + 0x0101) /* Japanese PC 106 keyboard - VK_CONVERT + SHIFT: maekouho */
#define SLIM_VK_CODE_INPUT			(SLIM_VKBASE + 0x0102) /* Japanese PC 106 keyboard - VK_ALPHANUMERIC + ALT: kanji bangou */
#define SLIM_VK_JAPANESE_KATAKANA	(SLIM_VKBASE + 0x0103) /* Japanese Macintosh keyboard - VK_JAPANESE_HIRAGANA + SHIFT */
#define SLIM_VK_JAPANESE_HIRAGANA	(SLIM_VKBASE + 0x0104) /* Japanese Macintosh keyboard */
#define SLIM_VK_JAPANESE_ROMAN		(SLIM_VKBASE + 0x0105) /* Japanese Macintosh keyboard */
#define SLIM_VK_KANA_LOCK			(SLIM_VKBASE + 0x0106) /* Japanese PC 106 keyboard with special Windows driver - eisuu + Control */
#define SLIM_VK_INPUT_METHOD_ON_OFF	(SLIM_VKBASE + 0x0107) /* Japanese PC 106 keyboard: kanji. Japanese Solaris keyboard: nihongo */

/* xxx */
#define SLIM_VK_KANA		(SLIM_VKBASE + 0x0015) /* replaced by VK_KANA_LOCK for Win32 and Solaris */
#define SLIM_VK_FINAL		(SLIM_VKBASE + 0x0018) /* not clear what this means - listed in Win32 API */
#define SLIM_VK_KANJI		(SLIM_VKBASE + 0x0019) /* replaced by VK_INPUT_METHOD_ON_OFF for Win32 and Solaris */
#define SLIM_VK_MODECHANGE	(SLIM_VKBASE + 0x001F) /* not clear what this means - listed in Win32 API */

/* for user defined key code */
#define SLIM_VK_USER_START 0x20000

/*                        */
/* modifier key mask flag */
/*                        */

#define SLIM_SHIFT_MASK			0x00000001
#define SLIM_CTRL_MASK			0x00000002
#define SLIM_META_MASK			0x00000004
#define SLIM_ALT_MASK			0x00000008
#define SLIM_MOUSE_LEFT_MASK	0x00000010
#define SLIM_MOUSE_RIGHT_MASK	0x00000020
#define SLIM_MOUSE_CENTER_MASK	0x00000040

#define	SLIM_REPEAT_MASK		0x80000000

#define	SLIM_MODIFIER_MASK		(SLIM_SHIFT_MASK		| \
								 SLIM_CTRL_MASK			| \
								 SLIM_META_MASK			| \
								 SLIM_ALT_MASK			| \
								 SLIM_MOUSE_LEFT_MASK	| \
								 SLIM_MOUSE_RIGHT_MASK	| \
								 SLIM_MOUSE_CENTER_MASK)

/*                        */
/* mouse button id        */
/*                        */
#define SLIM_MOUSEBUTTON_NONE	(-1)
#define	SLIM_MOUSEBUTTON_LEFT	0
#define	SLIM_MOUSEBUTTON_RIGHT	1
#define	SLIM_MOUSEBUTTON_CENTER	2

/* guidance id */
#define SLIM_GUIDANCE_NONE		0x0000
#define SLIM_GUIDANCE_DIRECTION	0x000f

#define SLIM_GUIDANCE_LEFT		0x0001
#define SLIM_GUIDANCE_UP		0x0002
#define SLIM_GUIDANCE_RIGHT		0x0004
#define SLIM_GUIDANCE_DOWN		0x0008
#define SLIM_GUIDANCE_ENTER		0x0010
#define SLIM_GUIDANCE_CANCEL	0x0020

SLIM_END_C_LINKAGE
#endif
