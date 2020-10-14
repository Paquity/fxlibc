#ifndef __ASM_UNISTD32_FXCG50_H__
# define __ASM_UNISTD32_FXCG50_H__

// File manipulation
#define __NR_BFile_Remove	0x00001db4
#define __NR_BFile_Create	0x00001dae
#define __NR_BFile_Open		0x00001da3
#define __NR_BFile_Close	0x00001da4
#define __NR_BFile_Size		0x00001da6
#define __NR_BFile_Write	0x00001daf
#define __NR_BFile_Read		0x00001dac
#define __NR_BFile_FindFirst	0x00001db7
#define __NR_BFile_FindNext	0x00001db9
#define __NR_BFile_FindClose	0x00001dba

// Keyboard interface
#define __NR_PutKeyCode		0x000012c6
#define __NR_GetKeyWait		0x000012bf
#define __NR_ClearKeyBuffer	0x000012c7
#define __NR_GetVRAMAddress	0x000001e6

// Memory management
#define __NR_Bmem_malloc	0x00001f44
#define __NR_Bmem_free		0x00001f42
#define __NR_Bmem_calloc	0x00001f40
#define __NR_Bmem_realloc	0x00001f46

// Timer interface
#define __NR_Timer_Install	0x000008d9
#define __NR_Timer_Deinstall	0x000008da
#define __NR_Timer_Start	0x000008db
#define __NR_Timer_Stop		0x000008dc

#endif /*__ASM_UNISTD32_FXCG50_H__*/
