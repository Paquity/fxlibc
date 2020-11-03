#ifndef _ELF_H
#define	_ELF_H 1

/* Standard ELF types.  */

#include <stdint.h>

/* Type for a 16-bit quantity.  */
typedef uint16_t Elf32_Half;

/* Types for signed and unsigned 32-bit quantities.  */
typedef uint32_t Elf32_Word;
typedef	int32_t  Elf32_Sword;

/* Type of addresses.  */
typedef uint32_t Elf32_Addr;

/* Type of file offsets.  */
typedef uint32_t Elf32_Off;

/* Type for section indices, which are 16-bit quantities.  */
typedef uint16_t Elf32_Section;

/* Type for version symbol information.  */
typedef Elf32_Half Elf32_Versym;


/* The ELF file header.  This appears at the start of every ELF file.  */
#define EI_NIDENT (16)

typedef struct
{
	unsigned char	e_ident[EI_NIDENT];	/* Magic number and other info */
	Elf32_Half	e_type;			/* Object file type */
	Elf32_Half	e_machine;		/* Architecture */
	Elf32_Word	e_version;		/* Object file version */
	Elf32_Addr	e_entry;		/* Entry point virtual address */
	Elf32_Off	e_phoff;		/* Program header table file offset */
	Elf32_Off	e_shoff;		/* Section header table file offset */
	Elf32_Word	e_flags;		/* Processor-specific flags */
	Elf32_Half	e_ehsize;		/* ELF header size in bytes */
	Elf32_Half	e_phentsize;		/* Program header table entry size */
	Elf32_Half	e_phnum;		/* Program header table entry count */
	Elf32_Half	e_shentsize;		/* Section header table entry size */
	Elf32_Half	e_shnum;		/* Section header table entry count */
	Elf32_Half	e_shstrndx;		/* Section header string table index */
} Elf32_Ehdr;

/*
** Fields in the e_ident array.  The EI_* macros are indices into the array.
** The macros under each EI_* macro are the values the byte may have.
*/
#define EI_MAG0		0		/* File identification byte 0 index */
#define ELFMAG0		0x7f		/* Magic number byte 0 */

#define EI_MAG1		1		/* File identification byte 1 index */
#define ELFMAG1		'E'		/* Magic number byte 1 */

#define EI_MAG2		2		/* File identification byte 2 index */
#define ELFMAG2		'L'		/* Magic number byte 2 */

#define EI_MAG3		3		/* File identification byte 3 index */
#define ELFMAG3		'F'		/* Magic number byte 3 */

/* Conglomeration of the identification bytes, for easy testing as a word.  */
#define	ELFMAG		"\177ELF"
#define	SELFMAG		4

#define EI_CLASS	4		/* File class byte index */
#define ELFCLASSNONE	0		/* Invalid class */
#define ELFCLASS32	1		/* 32-bit objects */
#define ELFCLASS64	2		/* 64-bit objects */
#define ELFCLASSNUM	3

#define EI_DATA		5		/* Data encoding byte index */
#define ELFDATANONE	0		/* Invalid data encoding */
#define ELFDATA2LSB	1		/* 2's complement, little endian */
#define ELFDATA2MSB	2		/* 2's complement, big endian */
#define ELFDATANUM	3

#define EI_VERSION	6		/* File version byte index */
					/* Value must be EV_CURRENT */

#define EI_OSABI	7		/* OS ABI identification */
#define ELFOSABI_NONE		0	/* UNIX System V ABI */
#define ELFOSABI_SYSV		0	/* Alias.  */
#define ELFOSABI_HPUX		1	/* HP-UX */
#define ELFOSABI_NETBSD		2	/* NetBSD.  */
#define ELFOSABI_GNU		3	/* Object uses GNU ELF extensions.  */
#define ELFOSABI_LINUX		ELFOSABI_GNU /* Compatibility alias.  */
#define ELFOSABI_SOLARIS	6	/* Sun Solaris.  */
#define ELFOSABI_AIX		7	/* IBM AIX.  */
#define ELFOSABI_IRIX		8	/* SGI Irix.  */
#define ELFOSABI_FREEBSD	9	/* FreeBSD.  */
#define ELFOSABI_TRU64		10	/* Compaq TRU64 UNIX.  */
#define ELFOSABI_MODESTO	11	/* Novell Modesto.  */
#define ELFOSABI_OPENBSD	12	/* OpenBSD.  */
#define ELFOSABI_ARM_AEABI	64	/* ARM EABI */
#define ELFOSABI_ARM		97	/* ARM */
#define ELFOSABI_STANDALONE	255	/* Standalone (embedded) application */

#define EI_ABIVERSION	8		/* ABI version */

#define EI_PAD		9		/* Byte index of padding bytes */

/* Legal values for e_type (object file type).  */

#define ET_NONE		0		/* No file type */
#define ET_REL		1		/* Relocatable file */
#define ET_EXEC		2		/* Executable file */
#define ET_DYN		3		/* Shared object file */
#define ET_CORE		4		/* Core file */
#define	ET_NUM		5		/* Number of defined types */
#define ET_LOOS		0xfe00		/* OS-specific range start */
#define ET_HIOS		0xfeff		/* OS-specific range end */
#define ET_LOPROC	0xff00		/* Processor-specific range start */
#define ET_HIPROC	0xffff		/* Processor-specific range end */

/* Legal values for e_machine (architecture).  */

#define EM_NONE		 0	/* No machine */
#define EM_M32		 1	/* AT&T WE 32100 */
#define EM_SPARC	 2	/* SUN SPARC */
#define EM_386		 3	/* Intel 80386 */
#define EM_68K		 4	/* Motorola m68k family */
#define EM_88K		 5	/* Motorola m88k family */
#define EM_IAMCU	 6	/* Intel MCU */
#define EM_860		 7	/* Intel 80860 */
#define EM_MIPS		 8	/* MIPS R3000 big-endian */
#define EM_S370		 9	/* IBM System/370 */
#define EM_MIPS_RS3_LE	10	/* MIPS R3000 little-endian */
				/* reserved 11-14 */
#define EM_PARISC	15	/* HPPA */
				/* reserved 16 */
#define EM_VPP500	17	/* Fujitsu VPP500 */
#define EM_SPARC32PLUS	18	/* Sun's "v8plus" */
#define EM_960		19	/* Intel 80960 */
#define EM_PPC		20	/* PowerPC */
#define EM_PPC64	21	/* PowerPC 64-bit */
#define EM_S390		22	/* IBM S390 */
#define EM_SPU		23	/* IBM SPU/SPC */
				/* reserved 24-35 */
#define EM_V800		36	/* NEC V800 series */
#define EM_FR20		37	/* Fujitsu FR20 */
#define EM_RH32		38	/* TRW RH-32 */
#define EM_RCE		39	/* Motorola RCE */
#define EM_ARM		40	/* ARM */
#define EM_FAKE_ALPHA	41	/* Digital Alpha */
#define EM_SH		42	/* Hitachi SH */
#define EM_SPARCV9	43	/* SPARC v9 64-bit */
#define EM_TRICORE	44	/* Siemens Tricore */
#define EM_ARC		45	/* Argonaut RISC Core */
#define EM_H8_300	46	/* Hitachi H8/300 */
#define EM_H8_300H	47	/* Hitachi H8/300H */
#define EM_H8S		48	/* Hitachi H8S */
#define EM_H8_500	49	/* Hitachi H8/500 */
#define EM_IA_64	50	/* Intel Merced */
#define EM_MIPS_X	51	/* Stanford MIPS-X */
#define EM_COLDFIRE	52	/* Motorola Coldfire */
#define EM_68HC12	53	/* Motorola M68HC12 */
#define EM_MMA		54	/* Fujitsu MMA Multimedia Accelerator */
#define EM_PCP		55	/* Siemens PCP */
#define EM_NCPU		56	/* Sony nCPU embeeded RISC */
#define EM_NDR1		57	/* Denso NDR1 microprocessor */
#define EM_STARCORE	58	/* Motorola Start*Core processor */
#define EM_ME16		59	/* Toyota ME16 processor */
#define EM_ST100	60	/* STMicroelectronic ST100 processor */
#define EM_TINYJ	61	/* Advanced Logic Corp. Tinyj emb.fam */
#define EM_X86_64	62	/* AMD x86-64 architecture */
#define EM_PDSP		63	/* Sony DSP Processor */
#define EM_PDP10	64	/* Digital PDP-10 */
#define EM_PDP11	65	/* Digital PDP-11 */
#define EM_FX66		66	/* Siemens FX66 microcontroller */
#define EM_ST9PLUS	67	/* STMicroelectronics ST9+ 8/16 mc */
#define EM_ST7		68	/* STmicroelectronics ST7 8 bit mc */
#define EM_68HC16	69	/* Motorola MC68HC16 microcontroller */
#define EM_68HC11	70	/* Motorola MC68HC11 microcontroller */
#define EM_68HC08	71	/* Motorola MC68HC08 microcontroller */
#define EM_68HC05	72	/* Motorola MC68HC05 microcontroller */
#define EM_SVX		73	/* Silicon Graphics SVx */
#define EM_ST19		74	/* STMicroelectronics ST19 8 bit mc */
#define EM_VAX		75	/* Digital VAX */
#define EM_CRIS		76	/* Axis Communications 32-bit emb.proc */
#define EM_JAVELIN	77	/* Infineon Technologies 32-bit emb.proc */
#define EM_FIREPATH	78	/* Element 14 64-bit DSP Processor */
#define EM_ZSP		79	/* LSI Logic 16-bit DSP Processor */
#define EM_MMIX		80	/* Donald Knuth's educational 64-bit proc */
#define EM_HUANY	81	/* Harvard University machine-independent object files */
#define EM_PRISM	82	/* SiTera Prism */
#define EM_AVR		83	/* Atmel AVR 8-bit microcontroller */
#define EM_FR30		84	/* Fujitsu FR30 */
#define EM_D10V		85	/* Mitsubishi D10V */
#define EM_D30V		86	/* Mitsubishi D30V */
#define EM_V850		87	/* NEC v850 */
#define EM_M32R		88	/* Mitsubishi M32R */
#define EM_MN10300	89	/* Matsushita MN10300 */
#define EM_MN10200	90	/* Matsushita MN10200 */
#define EM_PJ		91	/* picoJava */
#define EM_OPENRISC	92	/* OpenRISC 32-bit embedded processor */
#define EM_ARC_COMPACT	93	/* ARC International ARCompact */
#define EM_XTENSA	94	/* Tensilica Xtensa Architecture */
#define EM_VIDEOCORE	95	/* Alphamosaic VideoCore */
#define EM_TMM_GPP	96	/* Thompson Multimedia General Purpose Proc */
#define EM_NS32K	97	/* National Semi. 32000 */
#define EM_TPC		98	/* Tenor Network TPC */
#define EM_SNP1K	99	/* Trebia SNP 1000 */
#define EM_ST200	100	/* STMicroelectronics ST200 */
#define EM_IP2K		101	/* Ubicom IP2xxx */
#define EM_MAX		102	/* MAX processor */
#define EM_CR		103	/* National Semi. CompactRISC */
#define EM_F2MC16	104	/* Fujitsu F2MC16 */
#define EM_MSP430	105	/* Texas Instruments msp430 */
#define EM_BLACKFIN	106	/* Analog Devices Blackfin DSP */
#define EM_SE_C33	107	/* Seiko Epson S1C33 family */
#define EM_SEP		108	/* Sharp embedded microprocessor */
#define EM_ARCA		109	/* Arca RISC */
#define EM_UNICORE	110	/* PKU-Unity & MPRC Peking Uni. mc series */
#define EM_EXCESS	111	/* eXcess configurable cpu */
#define EM_DXP		112	/* Icera Semi. Deep Execution Processor */
#define EM_ALTERA_NIOS2 113	/* Altera Nios II */
#define EM_CRX		114	/* National Semi. CompactRISC CRX */
#define EM_XGATE	115	/* Motorola XGATE */
#define EM_C166		116	/* Infineon C16x/XC16x */
#define EM_M16C		117	/* Renesas M16C */
#define EM_DSPIC30F	118	/* Microchip Technology dsPIC30F */
#define EM_CE		119	/* Freescale Communication Engine RISC */
#define EM_M32C		120	/* Renesas M32C */
				/* reserved 121-130 */
#define EM_TSK3000	131	/* Altium TSK3000 */
#define EM_RS08		132	/* Freescale RS08 */
#define EM_SHARC	133	/* Analog Devices SHARC family */
#define EM_ECOG2	134	/* Cyan Technology eCOG2 */
#define EM_SCORE7	135	/* Sunplus S+core7 RISC */
#define EM_DSP24	136	/* New Japan Radio (NJR) 24-bit DSP */
#define EM_VIDEOCORE3	137	/* Broadcom VideoCore III */
#define EM_LATTICEMICO32 138	/* RISC for Lattice FPGA */
#define EM_SE_C17	139	/* Seiko Epson C17 */
#define EM_TI_C6000	140	/* Texas Instruments TMS320C6000 DSP */
#define EM_TI_C2000	141	/* Texas Instruments TMS320C2000 DSP */
#define EM_TI_C5500	142	/* Texas Instruments TMS320C55x DSP */
#define EM_TI_ARP32	143	/* Texas Instruments App. Specific RISC */
#define EM_TI_PRU	144	/* Texas Instruments Prog. Realtime Unit */
				/* reserved 145-159 */
#define EM_MMDSP_PLUS	160	/* STMicroelectronics 64bit VLIW DSP */
#define EM_CYPRESS_M8C	161	/* Cypress M8C */
#define EM_R32C		162	/* Renesas R32C */
#define EM_TRIMEDIA	163	/* NXP Semi. TriMedia */
#define EM_QDSP6	164	/* QUALCOMM DSP6 */
#define EM_8051		165	/* Intel 8051 and variants */
#define EM_STXP7X	166	/* STMicroelectronics STxP7x */
#define EM_NDS32	167	/* Andes Tech. compact code emb. RISC */
#define EM_ECOG1X	168	/* Cyan Technology eCOG1X */
#define EM_MAXQ30	169	/* Dallas Semi. MAXQ30 mc */
#define EM_XIMO16	170	/* New Japan Radio (NJR) 16-bit DSP */
#define EM_MANIK	171	/* M2000 Reconfigurable RISC */
#define EM_CRAYNV2	172	/* Cray NV2 vector architecture */
#define EM_RX		173	/* Renesas RX */
#define EM_METAG	174	/* Imagination Tech. META */
#define EM_MCST_ELBRUS	175	/* MCST Elbrus */
#define EM_ECOG16	176	/* Cyan Technology eCOG16 */
#define EM_CR16		177	/* National Semi. CompactRISC CR16 */
#define EM_ETPU		178	/* Freescale Extended Time Processing Unit */
#define EM_SLE9X	179	/* Infineon Tech. SLE9X */
#define EM_L10M		180	/* Intel L10M */
#define EM_K10M		181	/* Intel K10M */
				/* reserved 182 */
#define EM_AARCH64	183	/* ARM AARCH64 */
				/* reserved 184 */
#define EM_AVR32	185	/* Amtel 32-bit microprocessor */
#define EM_STM8		186	/* STMicroelectronics STM8 */
#define EM_TILE64	187	/* Tileta TILE64 */
#define EM_TILEPRO	188	/* Tilera TILEPro */
#define EM_MICROBLAZE	189	/* Xilinx MicroBlaze */
#define EM_CUDA		190	/* NVIDIA CUDA */
#define EM_TILEGX	191	/* Tilera TILE-Gx */
#define EM_CLOUDSHIELD	192	/* CloudShield */
#define EM_COREA_1ST	193	/* KIPO-KAIST Core-A 1st gen. */
#define EM_COREA_2ND	194	/* KIPO-KAIST Core-A 2nd gen. */
#define EM_ARC_COMPACT2	195	/* Synopsys ARCompact V2 */
#define EM_OPEN8	196	/* Open8 RISC */
#define EM_RL78		197	/* Renesas RL78 */
#define EM_VIDEOCORE5	198	/* Broadcom VideoCore V */
#define EM_78KOR	199	/* Renesas 78KOR */
#define EM_56800EX	200	/* Freescale 56800EX DSC */
#define EM_BA1		201	/* Beyond BA1 */
#define EM_BA2		202	/* Beyond BA2 */
#define EM_XCORE	203	/* XMOS xCORE */
#define EM_MCHP_PIC	204	/* Microchip 8-bit PIC(r) */
				/* reserved 205-209 */
#define EM_KM32		210	/* KM211 KM32 */
#define EM_KMX32	211	/* KM211 KMX32 */
#define EM_EMX16	212	/* KM211 KMX16 */
#define EM_EMX8		213	/* KM211 KMX8 */
#define EM_KVARC	214	/* KM211 KVARC */
#define EM_CDP		215	/* Paneve CDP */
#define EM_COGE		216	/* Cognitive Smart Memory Processor */
#define EM_COOL		217	/* Bluechip CoolEngine */
#define EM_NORC		218	/* Nanoradio Optimized RISC */
#define EM_CSR_KALIMBA	219	/* CSR Kalimba */
#define EM_Z80		220	/* Zilog Z80 */
#define EM_VISIUM	221	/* Controls and Data Services VISIUMcore */
#define EM_FT32		222	/* FTDI Chip FT32 */
#define EM_MOXIE	223	/* Moxie processor */
#define EM_AMDGPU	224	/* AMD GPU */
				/* reserved 225-242 */
#define EM_RISCV	243	/* RISC-V */

#define EM_BPF		247	/* Linux BPF -- in-kernel virtual machine */
#define EM_CSKY		252     /* C-SKY */

#define EM_NUM		253

/* Old spellings/synonyms.  */

#define EM_ARC_A5	EM_ARC_COMPACT

/* If it is necessary to assign new unofficial EM_* values, please
   pick large random numbers (0x8523, 0xa7f2, etc.) to minimize the
   chances of collision with official or non-GNU unofficial values.  */

#define EM_ALPHA	0x9026

/* Legal values for e_version (version).  */

#define EV_NONE		0		/* Invalid ELF version */
#define EV_CURRENT	1		/* Current version */
#define EV_NUM		2

/* Section header.  */

typedef struct
{
	Elf32_Word	sh_name;		/* Section name (string tbl index) */
	Elf32_Word	sh_type;		/* Section type */
	Elf32_Word	sh_flags;		/* Section flags */
	Elf32_Addr	sh_addr;		/* Section virtual addr at execution */
	Elf32_Off	sh_offset;		/* Section file offset */
	Elf32_Word	sh_size;		/* Section size in bytes */
	Elf32_Word	sh_link;		/* Link to another section */
	Elf32_Word	sh_info;		/* Additional section information */
	Elf32_Word	sh_addralign;		/* Section alignment */
	Elf32_Word	sh_entsize;		/* Entry size if section holds table */
} Elf32_Shdr;

/* Special section indices.  */
#define SHN_UNDEF	0		/* Undefined section */
#define SHN_LORESERVE	0xff00		/* Start of reserved indices */
#define SHN_LOPROC	0xff00		/* Start of processor-specific */
#define SHN_BEFORE	0xff00		/* Order section before all others
					   (Solaris).  */
#define SHN_AFTER	0xff01		/* Order section after all others
					   (Solaris).  */
#define SHN_HIPROC	0xff1f		/* End of processor-specific */
#define SHN_LOOS	0xff20		/* Start of OS-specific */
#define SHN_HIOS	0xff3f		/* End of OS-specific */
#define SHN_ABS		0xfff1		/* Associated symbol is absolute */
#define SHN_COMMON	0xfff2		/* Associated symbol is common */
#define SHN_XINDEX	0xffff		/* Index is in extra table.  */
#define SHN_HIRESERVE	0xffff		/* End of reserved indices */

/* Legal values for sh_type (section type).  */

#define SHT_NULL	  0		/* Section header table entry unused */
#define SHT_PROGBITS	  1		/* Program data */
#define SHT_SYMTAB	  2		/* Symbol table */
#define SHT_STRTAB	  3		/* String table */
#define SHT_RELA	  4		/* Relocation entries with addends */
#define SHT_HASH	  5		/* Symbol hash table */
#define SHT_DYNAMIC	  6		/* Dynamic linking information */
#define SHT_NOTE	  7		/* Notes */
#define SHT_NOBITS	  8		/* Program space with no data (bss) */
#define SHT_REL		  9		/* Relocation entries, no addends */
#define SHT_SHLIB	  10		/* Reserved */
#define SHT_DYNSYM	  11		/* Dynamic linker symbol table */
#define SHT_INIT_ARRAY	  14		/* Array of constructors */
#define SHT_FINI_ARRAY	  15		/* Array of destructors */
#define SHT_PREINIT_ARRAY 16		/* Array of pre-constructors */
#define SHT_GROUP	  17		/* Section group */
#define SHT_SYMTAB_SHNDX  18		/* Extended section indeces */
#define	SHT_NUM		  19		/* Number of defined types.  */
#define SHT_LOOS	  0x60000000	/* Start OS-specific.  */
#define SHT_GNU_ATTRIBUTES 0x6ffffff5	/* Object attributes.  */
#define SHT_GNU_HASH	  0x6ffffff6	/* GNU-style hash table.  */
#define SHT_GNU_LIBLIST	  0x6ffffff7	/* Prelink library list */
#define SHT_CHECKSUM	  0x6ffffff8	/* Checksum for DSO content.  */
#define SHT_LOSUNW	  0x6ffffffa	/* Sun-specific low bound.  */
#define SHT_SUNW_move	  0x6ffffffa
#define SHT_SUNW_COMDAT   0x6ffffffb
#define SHT_SUNW_syminfo  0x6ffffffc
#define SHT_GNU_verdef	  0x6ffffffd	/* Version definition section.  */
#define SHT_GNU_verneed	  0x6ffffffe	/* Version needs section.  */
#define SHT_GNU_versym	  0x6fffffff	/* Version symbol table.  */
#define SHT_HISUNW	  0x6fffffff	/* Sun-specific high bound.  */
#define SHT_HIOS	  0x6fffffff	/* End OS-specific type */
#define SHT_LOPROC	  0x70000000	/* Start of processor-specific */
#define SHT_HIPROC	  0x7fffffff	/* End of processor-specific */
#define SHT_LOUSER	  0x80000000	/* Start of application-specific */
#define SHT_HIUSER	  0x8fffffff	/* End of application-specific */

/* Legal values for sh_flags (section flags).  */

#define SHF_WRITE	     (1 << 0)	/* Writable */
#define SHF_ALLOC	     (1 << 1)	/* Occupies memory during execution */
#define SHF_EXECINSTR	     (1 << 2)	/* Executable */
#define SHF_MERGE	     (1 << 4)	/* Might be merged */
#define SHF_STRINGS	     (1 << 5)	/* Contains nul-terminated strings */
#define SHF_INFO_LINK	     (1 << 6)	/* `sh_info' contains SHT index */
#define SHF_LINK_ORDER	     (1 << 7)	/* Preserve order after combining */
#define SHF_OS_NONCONFORMING (1 << 8)	/* Non-standard OS specific handling
					   required */
#define SHF_GROUP	     (1 << 9)	/* Section is member of a group.  */
#define SHF_TLS		     (1 << 10)	/* Section hold thread-local data.  */
#define SHF_COMPRESSED	     (1 << 11)	/* Section with compressed data. */
#define SHF_MASKOS	     0x0ff00000	/* OS-specific.  */
#define SHF_MASKPROC	     0xf0000000	/* Processor-specific */
#define SHF_ORDERED	     (1 << 30)	/* Special ordering requirement
					   (Solaris).  */
#define SHF_EXCLUDE	     (1U << 31)	/* Section is excluded unless
					   referenced or allocated (Solaris).*/
/* Symbol table entry.  */

typedef struct
{
	Elf32_Word	st_name;		/* Symbol name (string tbl index) */
	Elf32_Addr	st_value;		/* Symbol value */
	Elf32_Word	st_size;		/* Symbol size */
	unsigned char	st_info;		/* Symbol type and binding */
	unsigned char	st_other;		/* Symbol visibility */
	Elf32_Section	st_shndx;		/* Section index */
} Elf32_Sym;


/*
** The syminfo section if available contains additional information about
** every dynamic symbol.
*/

typedef struct
{
	Elf32_Half	si_boundto;		/* Direct bindings, symbol bound to */
	Elf32_Half	si_flags;		/* Per symbol flags */
} Elf32_Syminfo;


/* Possible values for si_boundto.  */
#define SYMINFO_BT_SELF		0xffff	/* Symbol bound to self */
#define SYMINFO_BT_PARENT	0xfffe	/* Symbol bound to parent */
#define SYMINFO_BT_LOWRESERVE	0xff00	/* Beginning of reserved entries */

/* Possible bitmasks for si_flags.  */
#define SYMINFO_FLG_DIRECT	0x0001	/* Direct bound symbol */
#define SYMINFO_FLG_PASSTHRU	0x0002	/* Pass-thru symbol for translator */
#define SYMINFO_FLG_COPY	0x0004	/* Symbol is a copy-reloc */
#define SYMINFO_FLG_LAZYLOAD	0x0008	/* Symbol bound to object to be lazy
					   loaded */
/* Syminfo version values.  */
#define SYMINFO_NONE		0
#define SYMINFO_CURRENT		1
#define SYMINFO_NUM		2


/* How to extract and insert information held in the st_info field.  */

#define ELF32_ST_BIND(val)		(((unsigned char) (val)) >> 4)
#define ELF32_ST_TYPE(val)		((val) & 0xf)
#define ELF32_ST_INFO(bind, type)	(((bind) << 4) + ((type) & 0xf))


/* Legal values for ST_BIND subfield of st_info (symbol binding).  */

#define STB_LOCAL	0		/* Local symbol */
#define STB_GLOBAL	1		/* Global symbol */
#define STB_WEAK	2		/* Weak symbol */
#define	STB_NUM		3		/* Number of defined types.  */
#define STB_LOOS	10		/* Start of OS-specific */
#define STB_GNU_UNIQUE	10		/* Unique symbol.  */
#define STB_HIOS	12		/* End of OS-specific */
#define STB_LOPROC	13		/* Start of processor-specific */
#define STB_HIPROC	15		/* End of processor-specific */

/* Legal values for ST_TYPE subfield of st_info (symbol type).  */

#define STT_NOTYPE	0		/* Symbol type is unspecified */
#define STT_OBJECT	1		/* Symbol is a data object */
#define STT_FUNC	2		/* Symbol is a code object */
#define STT_SECTION	3		/* Symbol associated with a section */
#define STT_FILE	4		/* Symbol's name is file name */
#define STT_COMMON	5		/* Symbol is a common data object */
#define STT_TLS		6		/* Symbol is thread-local data object*/
#define	STT_NUM		7		/* Number of defined types.  */
#define STT_LOOS	10		/* Start of OS-specific */
#define STT_GNU_IFUNC	10		/* Symbol is indirect code object */
#define STT_HIOS	12		/* End of OS-specific */
#define STT_LOPROC	13		/* Start of processor-specific */
#define STT_HIPROC	15		/* End of processor-specific */


/*
** Symbol table indices are found in the hash buckets and chain table
** of a symbol hash table section.  This special index value indicates
** the end of a chain, meaning no further symbols are found in that bucket.
*/
#define STN_UNDEF	0		/* End of a chain.  */


/* How to extract and insert information held in the st_other field.  */

#define ELF32_ST_VISIBILITY(o)	((o) & 0x03)

/* Symbol visibility specification encoded in the st_other field.  */
#define STV_DEFAULT	0		/* Default symbol visibility rules */
#define STV_INTERNAL	1		/* Processor specific hidden class */
#define STV_HIDDEN	2		/* Sym unavailable in other modules */
#define STV_PROTECTED	3		/* Not preemptible, not exported */


/* Relocation table entry without addend (in section of type SHT_REL).  */

typedef struct
{
	Elf32_Addr	r_offset;		/* Address */
	Elf32_Word	r_info;			/* Relocation type and symbol index */
} Elf32_Rel;


/* Relocation table entry with addend (in section of type SHT_RELA).  */

typedef struct
{
	Elf32_Addr	r_offset;		/* Address */
	Elf32_Word	r_info;			/* Relocation type and symbol index */
	Elf32_Sword	r_addend;		/* Addend */
} Elf32_Rela;

/* How to extract and insert information held in the r_info field.  */

#define ELF32_R_SYM(val)		((val) >> 8)
#define ELF32_R_TYPE(val)		((val) & 0xff)
#define ELF32_R_INFO(sym, type)		(((sym) << 8) + ((type) & 0xff))

/* Program segment header.  */

typedef struct
{
	Elf32_Word	p_type;			/* Segment type */
	Elf32_Off	p_offset;		/* Segment file offset */
	Elf32_Addr	p_vaddr;		/* Segment virtual address */
	Elf32_Addr	p_paddr;		/* Segment physical address */
	Elf32_Word	p_filesz;		/* Segment size in file */
	Elf32_Word	p_memsz;		/* Segment size in memory */
	Elf32_Word	p_flags;		/* Segment flags */
	Elf32_Word	p_align;		/* Segment alignment */
} Elf32_Phdr;


/*
** Special value for e_phnum.  This indicates that the real number of
** program headers is too large to fit into e_phnum.  Instead the real
** value is in the field sh_info of section 0.
*/
#define PN_XNUM		0xffff

/* Legal values for p_type (segment type).  */

#define	PT_NULL		0		/* Program header table entry unused */
#define PT_LOAD		1		/* Loadable program segment */
#define PT_DYNAMIC	2		/* Dynamic linking information */
#define PT_INTERP	3		/* Program interpreter */
#define PT_NOTE		4		/* Auxiliary information */
#define PT_SHLIB	5		/* Reserved */
#define PT_PHDR		6		/* Entry for header table itself */
#define PT_TLS		7		/* Thread-local storage segment */
#define	PT_NUM		8		/* Number of defined types */
#define PT_LOOS		0x60000000	/* Start of OS-specific */
#define PT_GNU_EH_FRAME	0x6474e550	/* GCC .eh_frame_hdr segment */
#define PT_GNU_STACK	0x6474e551	/* Indicates stack executability */
#define PT_GNU_RELRO	0x6474e552	/* Read-only after relocation */
#define PT_LOSUNW	0x6ffffffa
#define PT_SUNWBSS	0x6ffffffa	/* Sun Specific segment */
#define PT_SUNWSTACK	0x6ffffffb	/* Stack segment */
#define PT_HISUNW	0x6fffffff
#define PT_HIOS		0x6fffffff	/* End of OS-specific */
#define PT_LOPROC	0x70000000	/* Start of processor-specific */
#define PT_HIPROC	0x7fffffff	/* End of processor-specific */

/* Legal values for p_flags (segment flags).  */

#define PF_X		(1 << 0)	/* Segment is executable */
#define PF_W		(1 << 1)	/* Segment is writable */
#define PF_R		(1 << 2)	/* Segment is readable */
#define PF_MASKOS	0x0ff00000	/* OS-specific */
#define PF_MASKPROC	0xf0000000	/* Processor-specific */

/* Legal values for note segment descriptor types for core files. */

#define NT_PRSTATUS	1		/* Contains copy of prstatus struct */
#define NT_PRFPREG	2		/* Contains copy of fpregset
					   struct.  */
#define NT_FPREGSET	2		/* Contains copy of fpregset struct */
#define NT_PRPSINFO	3		/* Contains copy of prpsinfo struct */
#define NT_PRXREG	4		/* Contains copy of prxregset struct */
#define NT_TASKSTRUCT	4		/* Contains copy of task structure */
#define NT_PLATFORM	5		/* String from sysinfo(SI_PLATFORM) */
#define NT_AUXV		6		/* Contains copy of auxv array */
#define NT_GWINDOWS	7		/* Contains copy of gwindows struct */
#define NT_ASRS		8		/* Contains copy of asrset struct */
#define NT_PSTATUS	10		/* Contains copy of pstatus struct */
#define NT_PSINFO	13		/* Contains copy of psinfo struct */
#define NT_PRCRED	14		/* Contains copy of prcred struct */
#define NT_UTSNAME	15		/* Contains copy of utsname struct */
#define NT_LWPSTATUS	16		/* Contains copy of lwpstatus struct */
#define NT_LWPSINFO	17		/* Contains copy of lwpinfo struct */
#define NT_PRFPXREG	20		/* Contains copy of fprxregset struct */
#define NT_SIGINFO	0x53494749	/* Contains copy of siginfo_t,
					   size might increase */
#define NT_FILE		0x46494c45	/* Contains information about mapped
					   files */
#define NT_PRXFPREG	0x46e62b7f	/* Contains copy of user_fxsr_struct */
#define NT_PPC_VMX	0x100		/* PowerPC Altivec/VMX registers */
#define NT_PPC_SPE	0x101		/* PowerPC SPE/EVR registers */
#define NT_PPC_VSX	0x102		/* PowerPC VSX registers */
#define NT_PPC_TAR	0x103		/* Target Address Register */
#define NT_PPC_PPR	0x104		/* Program Priority Register */
#define NT_PPC_DSCR	0x105		/* Data Stream Control Register */
#define NT_PPC_EBB	0x106		/* Event Based Branch Registers */
#define NT_PPC_PMU	0x107		/* Performance Monitor Registers */
#define NT_PPC_TM_CGPR	0x108		/* TM checkpointed GPR Registers */
#define NT_PPC_TM_CFPR	0x109		/* TM checkpointed FPR Registers */
#define NT_PPC_TM_CVMX	0x10a		/* TM checkpointed VMX Registers */
#define NT_PPC_TM_CVSX	0x10b		/* TM checkpointed VSX Registers */
#define NT_PPC_TM_SPR	0x10c		/* TM Special Purpose Registers */
#define NT_PPC_TM_CTAR	0x10d		/* TM checkpointed Target Address
					   Register */
#define NT_PPC_TM_CPPR	0x10e		/* TM checkpointed Program Priority
					   Register */
#define NT_PPC_TM_CDSCR	0x10f		/* TM checkpointed Data Stream Control
					   Register */
#define NT_PPC_PKEY	0x110		/* Memory Protection Keys
					   registers.  */
#define NT_386_TLS	0x200		/* i386 TLS slots (struct user_desc) */
#define NT_386_IOPERM	0x201		/* x86 io permission bitmap (1=deny) */
#define NT_X86_XSTATE	0x202		/* x86 extended state using xsave */
#define NT_S390_HIGH_GPRS	0x300	/* s390 upper register halves */
#define NT_S390_TIMER	0x301		/* s390 timer register */
#define NT_S390_TODCMP	0x302		/* s390 TOD clock comparator register */
#define NT_S390_TODPREG	0x303		/* s390 TOD programmable register */
#define NT_S390_CTRS	0x304		/* s390 control registers */
#define NT_S390_PREFIX	0x305		/* s390 prefix register */
#define NT_S390_LAST_BREAK	0x306	/* s390 breaking event address */
#define NT_S390_SYSTEM_CALL	0x307	/* s390 system call restart data */
#define NT_S390_TDB	0x308		/* s390 transaction diagnostic block */
#define NT_S390_VXRS_LOW	0x309	/* s390 vector registers 0-15
					   upper half.  */
#define NT_S390_VXRS_HIGH	0x30a	/* s390 vector registers 16-31.  */
#define NT_S390_GS_CB	0x30b		/* s390 guarded storage registers.  */
#define NT_S390_GS_BC	0x30c		/* s390 guarded storage
					   broadcast control block.  */
#define NT_S390_RI_CB	0x30d		/* s390 runtime instrumentation.  */
#define NT_ARM_VFP	0x400		/* ARM VFP/NEON registers */
#define NT_ARM_TLS	0x401		/* ARM TLS register */
#define NT_ARM_HW_BREAK	0x402		/* ARM hardware breakpoint registers */
#define NT_ARM_HW_WATCH	0x403		/* ARM hardware watchpoint registers */
#define NT_ARM_SYSTEM_CALL	0x404	/* ARM system call number */
#define NT_ARM_SVE	0x405		/* ARM Scalable Vector Extension
					   registers */
#define NT_ARM_PAC_MASK	0x406		/* ARM pointer authentication
					   code masks.  */
#define NT_ARM_PACA_KEYS	0x407	/* ARM pointer authentication
					   address keys.  */
#define NT_ARM_PACG_KEYS	0x408	/* ARM pointer authentication
					   generic key.  */
#define NT_VMCOREDD	0x700		/* Vmcore Device Dump Note.  */
#define NT_MIPS_DSP	0x800		/* MIPS DSP ASE registers.  */
#define NT_MIPS_FP_MODE	0x801		/* MIPS floating-point mode.  */
#define NT_MIPS_MSA	0x802		/* MIPS SIMD registers.  */

/* Legal values for the note segment descriptor types for object files.  */

#define NT_VERSION	1		/* Contains a version string.  */


/* Dynamic section entry.  */

typedef struct
{
	Elf32_Sword	d_tag;		/* Dynamic entry type */
	union
	{
		Elf32_Word d_val;	/* Integer value */
		Elf32_Addr d_ptr;	/* Address value */
	} d_un;
} Elf32_Dyn;

/* Legal values for d_tag (dynamic entry type).  */

#define DT_NULL		0		/* Marks end of dynamic section */
#define DT_NEEDED	1		/* Name of needed library */
#define DT_PLTRELSZ	2		/* Size in bytes of PLT relocs */
#define DT_PLTGOT	3		/* Processor defined value */
#define DT_HASH		4		/* Address of symbol hash table */
#define DT_STRTAB	5		/* Address of string table */
#define DT_SYMTAB	6		/* Address of symbol table */
#define DT_RELA		7		/* Address of Rela relocs */
#define DT_RELASZ	8		/* Total size of Rela relocs */
#define DT_RELAENT	9		/* Size of one Rela reloc */
#define DT_STRSZ	10		/* Size of string table */
#define DT_SYMENT	11		/* Size of one symbol table entry */
#define DT_INIT		12		/* Address of init function */
#define DT_FINI		13		/* Address of termination function */
#define DT_SONAME	14		/* Name of shared object */
#define DT_RPATH	15		/* Library search path (deprecated) */
#define DT_SYMBOLIC	16		/* Start symbol search here */
#define DT_REL		17		/* Address of Rel relocs */
#define DT_RELSZ	18		/* Total size of Rel relocs */
#define DT_RELENT	19		/* Size of one Rel reloc */
#define DT_PLTREL	20		/* Type of reloc in PLT */
#define DT_DEBUG	21		/* For debugging; unspecified */
#define DT_TEXTREL	22		/* Reloc might modify .text */
#define DT_JMPREL	23		/* Address of PLT relocs */
#define	DT_BIND_NOW	24		/* Process relocations of object */
#define	DT_INIT_ARRAY	25		/* Array with addresses of init fct */
#define	DT_FINI_ARRAY	26		/* Array with addresses of fini fct */
#define	DT_INIT_ARRAYSZ	27		/* Size in bytes of DT_INIT_ARRAY */
#define	DT_FINI_ARRAYSZ	28		/* Size in bytes of DT_FINI_ARRAY */
#define DT_RUNPATH	29		/* Library search path */
#define DT_FLAGS	30		/* Flags for the object being loaded */
#define DT_ENCODING	32		/* Start of encoded range */
#define DT_PREINIT_ARRAY 32		/* Array with addresses of preinit fct*/
#define DT_PREINIT_ARRAYSZ 33		/* size in bytes of DT_PREINIT_ARRAY */
#define DT_SYMTAB_SHNDX	34		/* Address of SYMTAB_SHNDX section */
#define	DT_NUM		35		/* Number used */
#define DT_LOOS		0x6000000d	/* Start of OS-specific */
#define DT_HIOS		0x6ffff000	/* End of OS-specific */
#define DT_LOPROC	0x70000000	/* Start of processor-specific */
#define DT_HIPROC	0x7fffffff	/* End of processor-specific */
#define	DT_PROCNUM	DT_MIPS_NUM	/* Most used by any processor */

/*
** DT_* entries which fall between DT_VALRNGHI & DT_VALRNGLO use the
** Dyn.d_un.d_val field of the Elf*_Dyn structure.  This follows Sun's
** approach.
*/
#define DT_VALRNGLO	0x6ffffd00
#define DT_GNU_PRELINKED 0x6ffffdf5	/* Prelinking timestamp */
#define DT_GNU_CONFLICTSZ 0x6ffffdf6	/* Size of conflict section */
#define DT_GNU_LIBLISTSZ 0x6ffffdf7	/* Size of library list */
#define DT_CHECKSUM	0x6ffffdf8
#define DT_PLTPADSZ	0x6ffffdf9
#define DT_MOVEENT	0x6ffffdfa
#define DT_MOVESZ	0x6ffffdfb
#define DT_FEATURE_1	0x6ffffdfc	/* Feature selection (DTF_*).  */
#define DT_POSFLAG_1	0x6ffffdfd	/* Flags for DT_* entries, effecting
					   the following DT_* entry.  */
#define DT_SYMINSZ	0x6ffffdfe	/* Size of syminfo table (in bytes) */
#define DT_SYMINENT	0x6ffffdff	/* Entry size of syminfo */
#define DT_VALRNGHI	0x6ffffdff
#define DT_VALTAGIDX(tag)	(DT_VALRNGHI - (tag))	/* Reverse order! */
#define DT_VALNUM 12

/*
** DT_* entries which fall between DT_ADDRRNGHI & DT_ADDRRNGLO use the
** Dyn.d_un.d_ptr field of the Elf*_Dyn structure.
**
** If any adjustment is made to the ELF object after it has been
** built these entries will need to be adjusted.
*/
#define DT_ADDRRNGLO	0x6ffffe00
#define DT_GNU_HASH	0x6ffffef5	/* GNU-style hash table.  */
#define DT_TLSDESC_PLT	0x6ffffef6
#define DT_TLSDESC_GOT	0x6ffffef7
#define DT_GNU_CONFLICT	0x6ffffef8	/* Start of conflict section */
#define DT_GNU_LIBLIST	0x6ffffef9	/* Library list */
#define DT_CONFIG	0x6ffffefa	/* Configuration information.  */
#define DT_DEPAUDIT	0x6ffffefb	/* Dependency auditing.  */
#define DT_AUDIT	0x6ffffefc	/* Object auditing.  */
#define	DT_PLTPAD	0x6ffffefd	/* PLT padding.  */
#define	DT_MOVETAB	0x6ffffefe	/* Move table.  */
#define DT_SYMINFO	0x6ffffeff	/* Syminfo table.  */
#define DT_ADDRRNGHI	0x6ffffeff
#define DT_ADDRTAGIDX(tag)	(DT_ADDRRNGHI - (tag))	/* Reverse order! */
#define DT_ADDRNUM 11

/*
** The versioning entry types.  The next are defined as part of the
** GNU extension.
*/
#define DT_VERSYM	0x6ffffff0

#define DT_RELACOUNT	0x6ffffff9
#define DT_RELCOUNT	0x6ffffffa

/* These were chosen by Sun. */
#define DT_FLAGS_1	0x6ffffffb	/* State flags, see DF_1_* below.  */
#define	DT_VERDEF	0x6ffffffc	/* Address of version definition
					   table */
#define	DT_VERDEFNUM	0x6ffffffd	/* Number of version definitions */
#define	DT_VERNEED	0x6ffffffe	/* Address of table with needed
					   versions */
#define	DT_VERNEEDNUM	0x6fffffff	/* Number of needed versions */
#define DT_VERSIONTAGIDX(tag)	(DT_VERNEEDNUM - (tag))	/* Reverse order! */
#define DT_VERSIONTAGNUM 16

/*
** Sun added these machine-independent extensions in the "processor-specific"
** range.  Be compatible.
*/
#define DT_AUXILIARY    0x7ffffffd      /* Shared object to load before self */
#define DT_FILTER       0x7fffffff      /* Shared object to get values from */
#define DT_EXTRATAGIDX(tag)	((Elf32_Word)-((Elf32_Sword) (tag) <<1>>1)-1)
#define DT_EXTRANUM	3

/* Values of `d_un.d_val' in the DT_FLAGS entry.  */
#define DF_ORIGIN	0x00000001	/* Object may use DF_ORIGIN */
#define DF_SYMBOLIC	0x00000002	/* Symbol resolutions starts here */
#define DF_TEXTREL	0x00000004	/* Object contains text relocations */
#define DF_BIND_NOW	0x00000008	/* No lazy binding for this object */
#define DF_STATIC_TLS	0x00000010	/* Module uses the static TLS model */

/*
** State flags selectable in the `d_un.d_val' element of the DT_FLAGS_1
** entry in the dynamic section.
*/
#define DF_1_NOW	0x00000001	/* Set RTLD_NOW for this object.  */
#define DF_1_GLOBAL	0x00000002	/* Set RTLD_GLOBAL for this object.  */
#define DF_1_GROUP	0x00000004	/* Set RTLD_GROUP for this object.  */
#define DF_1_NODELETE	0x00000008	/* Set RTLD_NODELETE for this object.*/
#define DF_1_LOADFLTR	0x00000010	/* Trigger filtee loading at runtime.*/
#define DF_1_INITFIRST	0x00000020	/* Set RTLD_INITFIRST for this object*/
#define DF_1_NOOPEN	0x00000040	/* Set RTLD_NOOPEN for this object.  */
#define DF_1_ORIGIN	0x00000080	/* $ORIGIN must be handled.  */
#define DF_1_DIRECT	0x00000100	/* Direct binding enabled.  */
#define DF_1_TRANS	0x00000200
#define DF_1_INTERPOSE	0x00000400	/* Object is used to interpose.  */
#define DF_1_NODEFLIB	0x00000800	/* Ignore default lib search path.  */
#define DF_1_NODUMP	0x00001000	/* Object can't be dldump'ed.  */
#define DF_1_CONFALT	0x00002000	/* Configuration alternative created.*/
#define DF_1_ENDFILTEE	0x00004000	/* Filtee terminates filters search. */
#define	DF_1_DISPRELDNE	0x00008000	/* Disp reloc applied at build time. */
#define	DF_1_DISPRELPND	0x00010000	/* Disp reloc applied at run-time.  */
#define	DF_1_NODIRECT	0x00020000	/* Object has no-direct binding. */
#define	DF_1_IGNMULDEF	0x00040000
#define	DF_1_NOKSYMS	0x00080000
#define	DF_1_NOHDR	0x00100000
#define	DF_1_EDITED	0x00200000	/* Object is modified after built.  */
#define	DF_1_NORELOC	0x00400000
#define	DF_1_SYMINTPOSE	0x00800000	/* Object has individual interposers.  */
#define	DF_1_GLOBAUDIT	0x01000000	/* Global auditing required.  */
#define	DF_1_SINGLETON	0x02000000	/* Singleton symbols are used.  */
#define	DF_1_STUB	0x04000000
#define	DF_1_PIE	0x08000000
#define	DF_1_KMOD       0x10000000
#define	DF_1_WEAKFILTER 0x20000000
#define	DF_1_NOCOMMON   0x40000000

/* Flags for the feature selection in DT_FEATURE_1.  */
#define DTF_1_PARINIT	0x00000001
#define DTF_1_CONFEXP	0x00000002

/* Flags in the DT_POSFLAG_1 entry effecting only the next DT_* entry.  */
#define DF_P1_LAZYLOAD	0x00000001	/* Lazyload following object.  */
#define DF_P1_GROUPPERM	0x00000002	/* Symbols from next object are not
					   generally available.  */

#endif	/* elf.h */
