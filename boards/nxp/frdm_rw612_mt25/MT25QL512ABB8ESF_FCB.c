/*
 * Copyright 2021-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <flash_config.h>
__attribute__((section(".flash_conf"), used)) const fc_flexspi_nor_config_t
flexspi_config = {
    .memConfig =
        {
        		.tag                 = FC_BLOCK_TAG,
        		            .version             = FC_BLOCK_VERSION,
        		            .readSampleClkSrc    = 1,
        		            .csHoldTime          = 3,
        		            .csSetupTime         = 3,
        		            .deviceModeCfgEnable = 1,
        		            .deviceModeSeq       = {.seqNum = 1, .seqId = 2},
        		            .deviceModeArg       = 0x02,
        		            .configCmdEnable     = 0,
        		            .deviceType          = 0x1,
        		            .sflashPadType       = kSerialFlash_4Pads,
        		            .serialClkFreq       = 5,
        		            .sflashA1Size        = 0x4000000U,
        		            .sflashA2Size        = 0,
        		            .sflashB1Size        = 0,
        		            .sflashB2Size        = 0,
        					.controllerMiscOption = 0x10,
							.lookupTable =
							        {
							            FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 236, FC_RADDR_SDR, FC_FLEXSPI_4PAD, 32),
							            FC_FLEXSPI_LUT_SEQ(FC_MODE4_SDR, FC_FLEXSPI_4PAD, 0, FC_DUMMY_SDR, FC_FLEXSPI_4PAD, 9),
							            FC_FLEXSPI_LUT_SEQ(FC_READ_SDR, FC_FLEXSPI_4PAD, 4, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 5, FC_READ_SDR, FC_FLEXSPI_1PAD, 4),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 6, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 33, FC_RADDR_SDR, FC_FLEXSPI_1PAD, 32),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 220, FC_RADDR_SDR, FC_FLEXSPI_1PAD, 32),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 62, FC_RADDR_SDR, FC_FLEXSPI_4PAD, 32),
							            FC_FLEXSPI_LUT_SEQ(FC_WRITE_SDR, FC_FLEXSPI_4PAD, 4, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 96, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),

							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							            FC_FLEXSPI_LUT_SEQ(0, 0, 0, 0, 0, 0),
							        },
        },
    .pageSize           = 0x100,
    .sectorSize         = 0x1000,
    .ipcmdSerialClkFreq = 0x01,
    .blockSize          = 0x10000,
    .fcb_fill[0]        = 0xFFFFFFFF,
};