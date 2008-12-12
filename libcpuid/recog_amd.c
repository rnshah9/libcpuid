/*
 * Copyright 2008  Veselin Georgiev,
 * anrieffNOSPAM @ mgail_DOT.com (convert to gmail)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <string.h>
#include "libcpuid.h"
#include "recog_amd.h"
#include "libcpuid_util.h"

enum _amd_code_t {
	NA,
	NO_CODE,
	OPTERON_GENERIC,
	OPTERON_800,
	ATHLON_XP,
	ATHLON_XP_M,
	ATHLON_XP_M_LV,
	ATHLON,
	ATHLON_MP,
	MOBILE_ATHLON64,
	ATHLON_FX,
	DURON,
	DURON_MP,
	MOBILE_DURON,
	MOBILE_SEMPRON,
	OPTERON_SINGLE,
	OPTERON_DUALCORE,
	OPTERON_800_DUALCORE,
	MOBILE_TURION,
	ATHLON_64,
	ATHLON_64_X2,
	ATHLON_64_FX,
	TURION_64,
	TURION_X2,
	SEMPRON,
	M_SEMPRON,
	SEMPRON_DUALCORE,
	PHENOM,
};
typedef enum _amd_code_t amd_code_t;

const struct match_entry_t cpudb_amd[] = {
	{ -1, -1, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown AMD CPU"               },
	
	/* 486 and the likes */
	{  4, -1, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown AMD 486"               },
	{  4,  3, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "AMD 486DX2"                    },
	{  4,  7, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "AMD 486DX2WB"                  },
	{  4,  8, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "AMD 486DX4"                    },
	{  4,  9, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "AMD 486DX4WB"                  },
	
	/* Pentia clones */
	{  5, -1, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown AMD 586"               },
	{  5,  0, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "K5"                            },
	{  5,  1, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "K5"                            },
	{  5,  2, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "K5"                            },
	{  5,  3, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "K5"                            },
	
	/* The K6 */
	{  5,  6, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "K6"                            },
	{  5,  7, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "K6"                            },
	
	{  5,  8, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "K6-2"                          },
	{  5,  9, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "K6-III"                        },
	{  5, 10, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown K6"                    },
	{  5, 11, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown K6"                    },
	{  5, 12, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown K6"                    },
	{  5, 13, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "K6-2+"                         },
	
	/* Athlon et al. */
	{  6,  1, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Athlon (Slot-A)"               },
	{  6,  2, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Athlon (Slot-A)"               },
	{  6,  3, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Duron (Spitfire)"              },
	{  6,  4, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Athlon (ThunderBird)"          },
	
	{  6,  6, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown Athlon"                },
	{  6,  6, -1, -1,   -1,   1,    -1, ATHLON                  ,     0, "Athlon (Palomino)"             },
	{  6,  6, -1, -1,   -1,   1,    -1, ATHLON_MP               ,     0, "Athlon MP (Palomino)"          },
	{  6,  6, -1, -1,   -1,   1,    -1, DURON                   ,     0, "Duron (Palomino)"              },
	{  6,  6, -1, -1,   -1,   1,    -1, ATHLON_XP               ,     0, "Athlon XP"                     },
	
	{  6,  7, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown Athlon XP"             },
	{  6,  7, -1, -1,   -1,   1,    -1, DURON                   ,     0, "Duron (Morgan)"                },
	
	{  6,  8, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Athlon XP"                     },
	{  6,  8, -1, -1,   -1,   1,    -1, ATHLON                  ,     0, "Athlon XP (Thoroughbred)"      },
	{  6,  8, -1, -1,   -1,   1,    -1, ATHLON_XP               ,     0, "Athlon XP (Thoroughbred)"      },
	{  6,  8, -1, -1,   -1,   1,    -1, DURON                   ,     0, "Duron (Applebred)"             },
	{  6,  8, -1, -1,   -1,   1,    -1, SEMPRON                 ,     0, "Sempron (Thoroughbred)"        },
	{  6,  8, -1, -1,   -1,   1,   128, SEMPRON                 ,     0, "Sempron (Thoroughbred)"        },
	{  6,  8, -1, -1,   -1,   1,   256, SEMPRON                 ,     0, "Sempron (Thoroughbred)"        },
	{  6,  8, -1, -1,   -1,   1,    -1, ATHLON_MP               ,     0, "Athlon MP (Thoroughbred)"      },
	{  6,  8, -1, -1,   -1,   1,    -1, ATHLON_XP_M             ,     0, "Mobile Athlon (T-Bred)"        },
	{  6,  8, -1, -1,   -1,   1,    -1, ATHLON_XP_M_LV          ,     0, "Mobile Athlon (T-Bred)"        },
	
	{  6, 10, -1, -1,   -1,   1,    -1, NO_CODE                 ,     0, "Athlon XP (Barton)"            },
	{  6, 10, -1, -1,   -1,   1,   512, ATHLON_XP               ,     0, "Athlon XP (Barton)"            },
	{  6, 10, -1, -1,   -1,   1,   512, SEMPRON                 ,     0, "Sempron (Barton)"              },
	{  6, 10, -1, -1,   -1,   1,   256, SEMPRON                 ,     0, "Sempron (Thorton)"             },
	{  6, 10, -1, -1,   -1,   1,   256, ATHLON_XP               ,     0, "Athlon XP (Thorton)"           },
	{  6, 10, -1, -1,   -1,   1,    -1, ATHLON_MP               ,     0, "Athlon MP (Barton)"            },
	{  6, 10, -1, -1,   -1,   1,    -1, ATHLON_XP_M             ,     0, "Mobile Athlon (Barton)"        },
	{  6, 10, -1, -1,   -1,   1,    -1, ATHLON_XP_M_LV          ,     0, "Mobile Athlon (Barton)"        },
	
	/* K8 Architecture */
	{ 15, -1, -1, 15,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown K8"                    },
	{ 15, -1, -1, 16,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown K9"                    },
	
	{ 15, -1, -1, 15,   -1,   1,    -1, NO_CODE                 ,     0, "Unknown A64"                   },
	{ 15, -1, -1, 15,   -1,   1,    -1, OPTERON_SINGLE          ,     0, "Opteron"                       },
	{ 15, -1, -1, 15,   -1,   2,    -1, OPTERON_DUALCORE        ,     0, "Opteron (Dual Core)"           },
	{ 15,  3, -1, 15,   -1,   1,    -1, OPTERON_SINGLE          ,     0, "Opteron"                       },
	{ 15,  3, -1, 15,   -1,   2,    -1, OPTERON_DUALCORE        ,     0, "Opteron (Dual Core)"           },
	{ 15, -1, -1, 15,   -1,   1,   512, ATHLON_64               ,     0, "Athlon 64 (512K)"              },
	{ 15, -1, -1, 15,   -1,   1,  1024, ATHLON_64               ,     0, "Athlon 64 (1024K)"             },
	{ 15, -1, -1, 15,   -1,   1,    -1, ATHLON_FX               ,     0, "Athlon FX"                     },
	{ 15, -1, -1, 15,   -1,   1,    -1, ATHLON_64_FX            ,     0, "Athlon 64 FX"                  },
	{ 15, -1, -1, 15,   -1,   2,   512, ATHLON_64_X2            ,     0, "Athlon 64 X2 (512K)"           },
	{ 15, -1, -1, 15,   -1,   2,  1024, ATHLON_64_X2            ,     0, "Athlon 64 X2 (1024K)"          },
	{ 15, -1, -1, 15,   -1,   1,   512, TURION_64               ,     0, "Turion 64 (512K)"              },
	{ 15, -1, -1, 15,   -1,   1,  1024, TURION_64               ,     0, "Turion 64 (1024K)"             },
	{ 15, -1, -1, 15,   -1,   2,   512, TURION_X2               ,     0, "Turion 64 X2 (512K)"           },
	{ 15, -1, -1, 15,   -1,   2,  1024, TURION_X2               ,     0, "Turion 64 X2 (1024K)"          },
	{ 15, -1, -1, 15,   -1,   1,   128, SEMPRON                 ,     0, "A64 Sempron (128K)"            },
	{ 15, -1, -1, 15,   -1,   1,   256, SEMPRON                 ,     0, "A64 Sempron (256K)"            },
	{ 15, -1, -1, 15,   -1,   1,   512, SEMPRON                 ,     0, "A64 Sempron (512K)"            },
	{ 15, -1, -1, 15, 0x4f,   1,   512, ATHLON_64               ,     0, "Athlon 64 (Orleans/512K)"      },
	{ 15, -1, -1, 15, 0x5f,   1,   512, ATHLON_64               ,     0, "Athlon 64 (Orleans/512K)"      },
	{ 15, -1, -1, 15, 0x2f,   1,   512, ATHLON_64               ,     0, "Athlon 64 (Venice/512K)"       },
	{ 15, -1, -1, 15, 0x2c,   1,   512, ATHLON_64               ,     0, "Athlon 64 (Venice/512K)"       },
	{ 15, -1, -1, 15, 0x1f,   1,   512, ATHLON_64               ,     0, "Athlon 64 (Winchester/512K)"   },
	{ 15, -1, -1, 15, 0x0c,   1,   512, ATHLON_64               ,     0, "Athlon 64 (Newcastle/512K)"    },
	{ 15, -1, -1, 15, 0x27,   1,   512, ATHLON_64               ,     0, "Athlon 64 (San Diego/512K)"    },
	{ 15, -1, -1, 15, 0x37,   1,   512, ATHLON_64               ,     0, "Athlon 64 (San Diego/512K)"    },
	{ 15, -1, -1, 15, 0x04,   1,   512, ATHLON_64               ,     0, "Athlon 64 (ClawHammer/512K)"   },
	
	{ 15, -1, -1, 15, 0x5f,   1,  1024, ATHLON_64               ,     0, "Athlon 64 (Orleans/1024K)"     },
	{ 15, -1, -1, 15, 0x27,   1,  1024, ATHLON_64               ,     0, "Athlon 64 (San Diego/1024K)"   },
	{ 15, -1, -1, 15, 0x04,   1,  1024, ATHLON_64               ,     0, "Athlon 64 (ClawHammer/1024K)"  },
	
	{ 15, -1, -1, 15, 0x4b,   2,   256, SEMPRON_DUALCORE        ,     0, "Athlon 64 X2 (Windsor/256K)"   },
	
	{ 15, -1, -1, 15, 0x23,   2,   512, ATHLON_64_X2            ,     0, "Athlon 64 X2 (Toledo/512K)"    },
	{ 15, -1, -1, 15, 0x4b,   2,   512, ATHLON_64_X2            ,     0, "Athlon 64 X2 (Windsor/512K)"   },
	{ 15, -1, -1, 15, 0x43,   2,   512, ATHLON_64_X2            ,     0, "Athlon 64 X2 (Windsor/512K)"   },
	{ 15, -1, -1, 15, 0x6b,   2,   512, ATHLON_64_X2            ,     0, "Athlon 64 X2 (Brisbane/512K)"  },
	{ 15, -1, -1, 15, 0x2b,   2,   512, ATHLON_64_X2            ,     0, "Athlon 64 X2 (Manchester/512K)"},
	
	{ 15, -1, -1, 15, 0x23,   2,  1024, ATHLON_64_X2            ,     0, "Athlon 64 X2 (Toledo/1024K)"   },
	{ 15, -1, -1, 15, 0x43,   2,  1024, ATHLON_64_X2            ,     0, "Athlon 64 X2 (Windsor/1024K)"  },
	
	{ 15, -1, -1, 15, 0x2c,   1,   128, SEMPRON                 ,     0, "Sempron 64 (Palermo/128K)"     },
	{ 15, -1, -1, 15, 0x2c,   1,   256, SEMPRON                 ,     0, "Sempron 64 (Palermo/256K)"     },
	{ 15, -1, -1, 15, 0x2f,   1,   128, SEMPRON                 ,     0, "Sempron 64 (Palermo/128K)"     },
	{ 15, -1, -1, 15, 0x2f,   1,   256, SEMPRON                 ,     0, "Sempron 64 (Palermo/256K)"     },
	{ 15, -1, -1, 15, 0x4f,   1,   128, SEMPRON                 ,     0, "Sempron 64 (Manila/128K)"      },
	{ 15, -1, -1, 15, 0x4f,   1,   256, SEMPRON                 ,     0, "Sempron 64 (Manila/256K)"      },
	{ 15, -1, -1, 15, 0x7f,   1,   256, SEMPRON                 ,     0, "Sempron 64 (Sparta/256K)"      },
	{ 15, -1, -1, 15, 0x7f,   1,   512, SEMPRON                 ,     0, "Sempron 64 (Sparta/512K)"      },
	{ 15, -1, -1, 15,   -1,   1,   256, M_SEMPRON               ,     0, "Mobile Sempron 64 (Keene/256K)"},
	{ 15, -1, -1, 15,   -1,   1,   512, M_SEMPRON               ,     0, "Mobile Sempron 64 (Keene/512K)"},
	{ 15, -1, -1, 15,   -1,   2,    -1, SEMPRON_DUALCORE        ,     0, "Sempron Dual Core"             },
	
	/* K9 Architecture */
	{ 15, -1, -1, 16,   -1,   1,    -1, PHENOM                  ,     0, "Unknown AMD Phenom"            },
	{ 15,  2, -1, 16,   -1,   1,    -1, PHENOM                  ,     0, "Phenom"                        },
	{ 15,  2, -1, 16,   -1,   3,    -1, PHENOM                  ,     0, "Phenom X3 (Toliman)"           },
	{ 15,  2, -1, 16,   -1,   4,    -1, PHENOM                  ,     0, "Phenom X4 (Agena)"             },
};


static void load_amd_features(struct cpu_raw_data_t* raw, struct cpu_id_t* data)
{
	const struct feature_map_t matchtable_edx81[] = {
		{ 20, CPU_FEATURE_NX },
		{ 22, CPU_FEATURE_MMXEXT },
		{ 25, CPU_FEATURE_FXSR_OPT },
		{ 27, CPU_FEATURE_RDTSCP },
		{ 30, CPU_FEATURE_3DNOWEXT },
		{ 31, CPU_FEATURE_3DNOW },
	};
	const struct feature_map_t matchtable_ecx81[] = {
		{  1, CPU_FEATURE_CMP_LEGACY },
		{  2, CPU_FEATURE_SVM },
		{  5, CPU_FEATURE_ABM },
		{  6, CPU_FEATURE_SSE4A },
		{  7, CPU_FEATURE_MISALIGNSSE },
		{  8, CPU_FEATURE_3DNOWPREFETCH },
		{  9, CPU_FEATURE_OSVW },
		{ 10, CPU_FEATURE_IBS },
		{ 11, CPU_FEATURE_SSE5 },
		{ 12, CPU_FEATURE_SKINIT },
		{ 13, CPU_FEATURE_WDT },
	};
	const struct feature_map_t matchtable_edx87[] = {
		{  0, CPU_FEATURE_TS },
		{  1, CPU_FEATURE_FID },
		{  2, CPU_FEATURE_VID },
		{  3, CPU_FEATURE_TTP },
		{  4, CPU_FEATURE_TM_AMD },
		{  5, CPU_FEATURE_STC },
		{  6, CPU_FEATURE_100MHZSTEPS },
		{  7, CPU_FEATURE_HWPSTATE },
		{  8, CPU_FEATURE_CONSTANT_TSC },
	};
	if (raw->ext_cpuid[0][0] >= 1) {
		match_features(matchtable_edx81, COUNT_OF(matchtable_edx81), raw->ext_cpuid[1][3], data);
		match_features(matchtable_ecx81, COUNT_OF(matchtable_ecx81), raw->ext_cpuid[1][2], data);
	}
	if (raw->ext_cpuid[0][0] >= 7)
		match_features(matchtable_edx87, COUNT_OF(matchtable_edx87), raw->ext_cpuid[7][3], data);
}

static void decode_amd_cache_info(struct cpu_raw_data_t* raw, struct cpu_id_t* data)
{
	int l3_result;
	const int assoc_table[16] = {
		0, 1, 2, 0, 4, 0, 8, 0, 16, 0, 32, 48, 64, 92, 128, 255
	};
	unsigned n = raw->ext_cpuid[0][0];
	
	if (n >= 0x80000005) {
		data->l1_data_cache = (raw->ext_cpuid[5][2] >> 24) & 0xff;
		data->l1_assoc = (raw->ext_cpuid[5][2] >> 16) & 0xff;
		data->l1_cacheline = (raw->ext_cpuid[5][2]) & 0xff;
		data->l1_instruction_cache = (raw->ext_cpuid[5][3] >> 24) & 0xff;
	}
	if (n >= 0x80000006) {
		data->l2_cache = (raw->ext_cpuid[6][2] >> 16) & 0xffff;
		data->l2_assoc = assoc_table[(raw->ext_cpuid[6][2] >> 12) & 0xf];
		data->l2_cacheline = (raw->ext_cpuid[6][2]) & 0xff;
		
		l3_result = (raw->ext_cpuid[6][3] >> 18);
		if (l3_result > 0) {
			l3_result = 512 * l3_result; /* AMD spec says it's a range,
			                                but we take the lower bound */
			data->l3_cache = l3_result;
			data->l3_assoc = assoc_table[(raw->ext_cpuid[6][3] >> 12) & 0xf];
			data->l3_cacheline = (raw->ext_cpuid[6][3]) & 0xff;
		} else {
			data->l3_cache = 0;
		}
	}
}

static void decode_amd_number_of_cores(struct cpu_raw_data_t* raw, struct cpu_id_t* data)
{
	int logical_cpus = -1, num_cores = -1;
	
	if (raw->basic_cpuid[0][0] >= 1) {
		logical_cpus = (raw->basic_cpuid[1][1] >> 16) & 0xff;
		if (raw->ext_cpuid[0][0] >= 8) {
			num_cores = 1 + (raw->ext_cpuid[8][2] & 0xff);
		}
	}
	if (data->flags[CPU_FEATURE_HT]) {
		if (num_cores > 1) {
			data->num_cores = num_cores;
			data->num_logical_cpus = logical_cpus;
		} else {
			data->num_cores = 1;
			data->num_logical_cpus = (logical_cpus >= 2 ? logical_cpus : 2);
		}
	} else {
		data->num_cores = data->num_logical_cpus = 1;
	}
}

static amd_code_t decode_amd_codename_part1(const char *bs)
{
	if (strstr(bs, "Opteron")) {
		if (strstr(bs, "Dual Core")) return OPTERON_DUALCORE;
		return OPTERON_SINGLE;
	}
	if (strstr(bs, "Phenom")) {
		return PHENOM;
	}
	if (strstr(bs, "Athlon(tm) 64 FX")) return ATHLON_64_FX;
	if (strstr(bs, "Athlon(tm) FX")) return ATHLON_FX;
	if (strstr(bs, "Athlon(tm) 64")) {
		if (strstr(bs, "Dual Core")) return ATHLON_64_X2;
		return ATHLON_64;
	}
	if (strstr(bs, "Athlon(tm) X2")) {
		return ATHLON_64_X2;
	}
	if (strstr(bs, "Turion(tm)")) {
		if (strstr(bs, "X2"))
			return TURION_X2;
		else
			return TURION_64;
	}
	
	if (strstr(bs, "mobile") || strstr(bs, "Mobile")) {
		if (strstr(bs, "Athlon(tm) XP-M (LV)")) return ATHLON_XP_M_LV;
		if (strstr(bs, "Athlon(tm) XP")) return ATHLON_XP_M;
		if (strstr(bs, "Sempron(tm)")) return M_SEMPRON;
		if (strstr(bs, "Athlon")) return MOBILE_ATHLON64;
		if (strstr(bs, "Duron")) return MOBILE_DURON;
		
	} else {
		if (strstr(bs, "Athlon(tm) XP")) return ATHLON_XP;
		if (strstr(bs, "Athlon(tm) MP")) return ATHLON_MP;
		if (strstr(bs, "Sempron(tm)")) return SEMPRON;
		if (strstr(bs, "Duron")) return DURON;
		if (strstr(bs, "Athlon")) return ATHLON;
	}
	
	return NO_CODE;
}

static void decode_amd_codename(struct cpu_raw_data_t* raw, struct cpu_id_t* data)
{
	amd_code_t code = decode_amd_codename_part1(data->brand_str);
	
	if (code == ATHLON_64_X2 && data->l2_cache < 512)
		code = SEMPRON_DUALCORE;
	match_cpu_codename(cpudb_amd, COUNT_OF(cpudb_amd), data, code, 0);
}

int cpuid_identify_amd(struct cpu_raw_data_t* raw, struct cpu_id_t* data)
{
	load_amd_features(raw, data);
	decode_amd_cache_info(raw, data);
	decode_amd_number_of_cores(raw, data);
	decode_amd_codename(raw, data);
	return 0;
}
