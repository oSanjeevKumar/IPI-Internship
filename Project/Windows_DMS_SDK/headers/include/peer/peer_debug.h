#ifndef PEER_DEBUG_H
#define PEER_DEBUG_H

#ifdef _DEBUG
# define PEER_DEBUG
#endif /* _DEBUG */

#ifdef PEER_DEBUG

# define _PEER_DEBUG_MAX_INDENT_	32

static int _peer_debug_indent_counter = 0;

# define _PEER_FUN_IN_() do {									\
	slim_char indent[_PEER_DEBUG_MAX_INDENT_ + 1];				\
	memset(indent, '-', _PEER_DEBUG_MAX_INDENT_ + 1);			\
	if (_peer_debug_indent_counter > _PEER_DEBUG_MAX_INDENT_)	\
		indent[_PEER_DEBUG_MAX_INDENT_] = '\0';					\
	else														\
		indent[_peer_debug_indent_counter] = '\0';				\
		dlnaDebugPrintfPeer("%s> IN  %s:%i\n",					\
	indent, __FUNCTION__, __LINE__);							\
	_peer_debug_indent_counter ++; } while (0)

# define _PEER_FUN_IN_TODO_() do {								\
	slim_char indent[_PEER_DEBUG_MAX_INDENT_ + 1];				\
	memset(indent, '-', _PEER_DEBUG_MAX_INDENT_ + 1);			\
	if (_peer_debug_indent_counter > _PEER_DEBUG_MAX_INDENT_)	\
		indent[_PEER_DEBUG_MAX_INDENT_] = '\0';					\
	else														\
		indent[_peer_debug_indent_counter] = '\0';				\
	dlnaDebugPrintfPeer("%s> IN(todo)  %s:%i\n",				\
	indent, __FUNCTION__, __LINE__);							\
	_peer_debug_indent_counter ++; } while (0)

# define _PEER_FUN_OUT_() do {									\
	slim_char indent[_PEER_DEBUG_MAX_INDENT_ + 1] = {'-'};		\
	memset(indent, '-', _PEER_DEBUG_MAX_INDENT_ + 1);			\
	_peer_debug_indent_counter --;								\
	if (_peer_debug_indent_counter > _PEER_DEBUG_MAX_INDENT_)	\
		indent[_PEER_DEBUG_MAX_INDENT_] = '\0';					\
	else														\
		indent[_peer_debug_indent_counter] = '\0';				\
	dlnaDebugPrintfPeer("%s> OUT %s:%i\n",						\
	indent, __FUNCTION__, __LINE__); } while (0)

# define _PEER_FUN_OUT_TODO_() do {								\
	slim_char indent[_PEER_DEBUG_MAX_INDENT_ + 1] = {'-'};		\
	memset(indent, '-', _PEER_DEBUG_MAX_INDENT_ + 1);			\
	_peer_debug_indent_counter --;								\
	if (_peer_debug_indent_counter > _PEER_DEBUG_MAX_INDENT_)	\
		indent[_PEER_DEBUG_MAX_INDENT_] = '\0';					\
	else														\
		indent[_peer_debug_indent_counter] = '\0';				\
	dlnaDebugPrintfPeer("%s> OUT(todo) %s:%i\n",				\
	indent, __FUNCTION__, __LINE__); } while (0)

# define _PEER_TODO_FUNCTION_() do {								\
	dlnaDebugPrintfPeer(">> TODO function call << - %s:%i\n",	\
	__FUNCTION__, __LINE__); } while (0)

#else

# define _PEER_FUN_IN_()
# define _PEER_FUN_IN_TODO_()
# define _PEER_FUN_OUT_()
# define _PEER_FUN_OUT_TODO_()
# define _PEER_TODO_FUNCTION_()

#endif /* PEER_DEBUG */

#endif /* PEER_DEBUG_H */
