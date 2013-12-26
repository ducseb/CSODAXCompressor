#ifndef _DAXFILE_H_

#define _DAXFILE_H_

#include "ptypes.h"

#define DAXFILE_SIGNATURE 0x00584144 /* "DAX\0" */

#define DAX_FRAME_SIZE	8192

#define DAXFORMAT_VERSION_0	0
#define DAXFORMAT_VERSION_1	1

#define MAX_NCAREAS 192

typedef struct
{
	u32 signature; 
	u32 decompsize; /* Size of original non-compressed file */
	u32 version;   /* DAX format version */
	u32 nNCareas; /* Number of non-compressed areas. */
	u32 reserved[4]; /* Reserved for future use. It must be zero */
} DAXHeader;

typedef struct
{
	u32 frame; /* First frame of the NC Area */
	u32 size; /*  Size of the NC Area in frames */
} NCArea;


#endif /* _DAXFILE_H_ */
