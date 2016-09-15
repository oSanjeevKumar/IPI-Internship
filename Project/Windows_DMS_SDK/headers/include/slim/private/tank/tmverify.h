/*
    (private) tmverify.h
    Copyright(c) 1996-2006 ACCESS CO., LTD.
    All rights are reserved by ACCESS CO., LTD., whether the whole or
    part of the source code including any modifications.
*/

#ifndef SLIM_MEMORY_VERIFY_H_PRIVATE_MODULE
#define SLIM_MEMORY_VERIFY_H_PRIVATE_MODULE

SLIM_BEGIN_C_LINKAGE

/*
 * SLIM_TANK_VERIFY enables to verify integrity of memory data structure.
 * N.B. 1) This is TANK module local.
 * N.B. 2) This makes program VERY VERY slow.
 */
/* #define SLIM_TANK_VERIFY */

/* If SLIM_CONFIG_MEMORY_DEBUG is not defined, defining SLIM_TANK_VERIFY is meaningless. */
#ifndef SLIM_CONFIG_MEMORY_DEBUG
	#undef SLIM_TANK_VERIFY
#endif /* !defined(SLIM_CONFIG_DEBUG_MEMORY) */

#ifdef SLIM_TANK_VERIFY
	slim_bool slim_tank_verify_all(void);
	slim_bool TTank_Verify(TTank *self);
	void Tank_VerifyPrint(slim_char *in_s);
	slim_bool TTank_VerifyTankShallow(TTank *self);
	slim_bool Tank_VerifyHandle(slim_handle in_handle);
	slim_bool Tank_VerifyHandleShallow(slim_handle in_handle);
	slim_bool TTank_VerifyMemBlock(TTank *self, TMemBlock *in_block);
	slim_bool TTank_VerifyHandle(TTank *self, slim_handle in_handle);
	slim_bool TTank_VerifyAddress(TTank *self, void *in_addr);
	slim_bool TTank_VerifyBlockNumber(TTank *self, slim_int in_block);
	#define SLIM_TANK_VERIFY_ALL()	slim_tank_verify_all()
	#define SLIM_TANK_VERIFY_PRINT(expr) Tank_VerifyPrint((slim_char *)(#expr))
	#define SLIM_TANK_VERIFY_ASSERT(expr) do { if (!(expr)) { SLIM_TANK_VERIFY_PRINT(expr); } } while (0)
	#define SLIM_TANK_VERIFY_MEMBLOCK(tank, mp) SLIM_TANK_VERIFY_ASSERT(TTank_VerifyMemBlock((tank), (mp)))
	#define SLIM_TANK_VERIFY_TANK(tank) SLIM_TANK_VERIFY_ASSERT(TTank_Verify(tank))
	#define SLIM_TANK_VERIFY_TANK_SHALLOW(tank) SLIM_TANK_VERIFY_ASSERT(TTank_VerifyTankShallow(tank))
	#define SLIM_TANK_VERIFY_HANDLE(handle) SLIM_TANK_VERIFY_ASSERT(Tank_VerifyHandle(handle))
	#define SLIM_TANK_VERIFY_HANDLE_SHALLOW(handle) SLIM_TANK_VERIFY_ASSERT(Tank_VerifyHandleShallow(handle))
	#define SLIM_TANK_VERIFY_ASSERT_ADDRESS(tank, addr) SLIM_TANK_VERIFY_ASSERT(TTank_VerifyAddress((tank), (addr)))
	#define SLIM_TANK_VERIFY_ASSERT_BLOCKNUMBER(tank, block) SLIM_TANK_VERIFY_ASSERT(TTank_VerifyBlockNumber((tank), (block)))
#else /* !defined(SLIM_TANK_VERIFY) */
	#define SLIM_TANK_VERIFY_ALL()	((void)0)
	#define SLIM_TANK_VERIFY_PRINT(expr) ((void)0)
	#define SLIM_TANK_VERIFY_ASSERT(exp) ((void)0)
	#define SLIM_TANK_VERIFY_MEMBLOCK(tank, mp) ((void)0)
	#define SLIM_TANK_VERIFY_TANK(tank) ((void)0)
	#define SLIM_TANK_VERIFY_TANK_SHALLOW(tank) ((void)0)
	#define SLIM_TANK_VERIFY_HANDLE(handle) ((void)0)
	#define SLIM_TANK_VERIFY_HANDLE_SHALLOW(handle) ((void 0))
	#define SLIM_TANK_VERIFY_ASSERT_ADDRESS(tank, addr) ((void)0)
	#define SLIM_TANK_VERIFY_ASSERT_BLOCKNUMBER(tank, block) ((void)0)
#endif /* !defined(SLIM_TANK_VERIFY) */

SLIM_END_C_LINKAGE

#endif /* !defined(SLIM_MEMORY_VERIFY_H_PRIVATE_MODULE) */
