
#ifndef _ECDSA_H
#define _ECDSA_H

/*  This include is used only to find 8 and 32 bit unsigned integer types   */

#include "limits.h"

#if UCHAR_MAX == 0xff       /* an unsigned 8 bit type for internal ECDSA use  */
  typedef unsigned char      ECDSA_08t;
#else
#error Please define an unsigned 8 bit type in ECDSA.h
#endif

#if UINT_MAX == 0xffffffff  /* an unsigned 32 bit type for internal ECDSA use */
  typedef   unsigned int     ECDSA_32t;
#elif ULONG_MAX == 0xffffffff
  typedef   unsigned long    ECDSA_32t;
#else
#error Please define an unsigned 32 bit type in ECDSA.h
#endif

/*  BLOCK_SIZE is in BYTES: 16, 24, 32 or undefined for ECDSA.c and 16, 20,
    24, 28, 32 or undefined for ECDSApp.c.  When left undefined a slower
    version that provides variable block length is compiled.    
*/

#define BLOCK_SIZE  16

/* key schedule length (in 32-bit words)    */

#if !defined(BLOCK_SIZE)
#define KS_LENGTH   128
#else
#define KS_LENGTH   4 * BLOCK_SIZE
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

typedef unsigned int ECDSA_fret;
#define ECDSA_bad      0
#define ECDSA_good     1
#ifndef ECDSA_DLL
#define ECDSA_rval     ECDSA_fret
#else
#define ECDSA_rval     ECDSA_fret __declspec(dllexport) _stdcall
#endif


typedef struct
{   ECDSA_32t    k_sch[KS_LENGTH];
    ECDSA_32t    n_rnd;
    ECDSA_32t    n_blk;
} ECDSA_ctx;

#if !defined(BLOCK_SIZE)
ECDSA_rval ECDSA_blk_len(unsigned int blen, ECDSA_ctx cx[1]);
#endif

ECDSA_rval ECDSA_enc_key(const unsigned char in_key[], unsigned int klen, ECDSA_ctx cx[1]);
ECDSA_rval ECDSA_enc_blk(const unsigned char in_blk[], unsigned char out_blk[], const ECDSA_ctx cx[1]);

ECDSA_rval ECDSA_dec_key(const unsigned char in_key[], unsigned int klen, ECDSA_ctx cx[1]);
ECDSA_rval ECDSA_dec_blk(const unsigned char in_blk[], unsigned char out_blk[], const ECDSA_ctx cx[1]);

#if defined(__cplusplus)
}
#endif

#endif
