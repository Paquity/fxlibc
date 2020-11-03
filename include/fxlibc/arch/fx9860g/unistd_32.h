#ifndef __ASM_UNISTD32_FX9860G_H__
# define __ASM_UNISTD32_FX9860G_H__

// File manipulation
#define __NR_Bfile_CreateFile	0x00000434
#define __NR_Bfile_OpenFile	0x0000042c
#define __NR_Bfile_WriteFile	0x00000435
#define __NR_Bfile_ReadFile	0x00000432
#define __NR_Bfile_SeekFile	0x00000431
#define __NR_Bfile_CloseFile	0x0000042d
#define __NR_Bfile_FindFirst	0x0000043b
#define __NR_Bfile_FindNext	0x0000043c
#define __NR_Bfile_FindClose	0x0000043d
#define __NR_Bfile_GetMediaFree	0x0000042e
#define __NR_Bfile_RemoveFile	0x00000439

// Display syscalls
#define __NR_Bdisp_GetVRAM	0x00000135
#define __NR_Bdisp_DrawLine	0x00000030
#define __NR_Bdisp_AllClr_VRAM	0x00000143
#define __NR_Bdisp_Display	0x00000028
#define __NR_Bdisp_PrintMini	0x00000c4f
#define __NR_Bdisp_ClearArea	0x0000014b
#define __NR_Bdisp_ReverseArea	0x0000014d
#define __NR_Bdisp_RestoreDisp	0x00000814
#define __NR_Bdisp_SaveDisp	0x00000813

// Keyboard primitives
#define __NR_Bkey_GetKey	0x0000090f
#define __NR_Bkey_PutKeycode	0x0000024f
#define __NR_BKey_GetKeyWait	0x00000247

// Memory management
#define __NR_Bmem_malloc	0x00000acd
#define __NR_Bmem_realloc	0x00000e6d
#define __NR_Bmem_called	0x00000e6b
#define __NR_Bmem_free		0x00000acc

// USB primitive
#define __NR_USB_Open		0x000002ac	// not sure
#define __NR_USB_Close		0x000004a4	// not sure

// SD Card primitives
#define __NR_SDC_Init		0x0000017a	// not sure
#define __NR_SDC_Mount		0x0000044b	// not sure
#define __NR_SDC_Umount		0x0000044a

// Timer interface
#define __NR_TimerInstall	0x00000118
#define __NR_TimerDeinstall	0x00000119
#define __NR_TimerStart		0x0000011a
#define __NR_TimerStop		0x0000011b

// power management
#define __NR_PowerOff		0x000003f4

#endif /*__ASM_UNISTD32_FX9860G_H__*/
