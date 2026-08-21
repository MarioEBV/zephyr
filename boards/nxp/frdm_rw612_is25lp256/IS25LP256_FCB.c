#include <flash_config.h>

#define IS25LP256M_FLASH_SIZE_BYTES   0x02000000U  /* 32 MBytes */
#define IS25LP256M_PAGE_SIZE_BYTES    0x00000100U  /* 256 bytes */
#define IS25LP256M_SECTOR_SIZE_BYTES  0x00001000U  /* 4 KBytes */
#define IS25LP256M_BLOCK_SIZE_BYTES   0x00010000U  /* 64 KBytes */

/* LUT sequence indices. Each sequence consumes four LUT words. */
#define LUT_IDX_READ                  0U
#define LUT_IDX_READ_STATUS           1U
#define LUT_IDX_WRITE_STATUS          2U
#define LUT_IDX_WRITE_ENABLE          3U
#define LUT_IDX_WRITE_DISABLE         4U
#define LUT_IDX_ERASE_SECTOR_4K       5U
#define LUT_IDX_READ_ID               6U
#define LUT_IDX_READ_SFDP             7U
#define LUT_IDX_ERASE_BLOCK_64K       8U
#define LUT_IDX_PAGE_PROGRAM_QUAD     9U
#define LUT_IDX_ENTER_4BYTE_MODE      10U
#define LUT_IDX_EXIT_4BYTE_MODE       11U
#define LUT_IDX_CHIP_ERASE            12U
#define LUT_IDX_READ_FLAG_STATUS      13U
#define LUT_IDX_SOFT_RESET_ENABLE     14U
#define LUT_IDX_SOFT_RESET            15U


__attribute__((section(".flash_conf"), used)) const fc_flexspi_nor_config_t
flexspi_config = {
    .memConfig =
    {
        .tag                    = FC_BLOCK_TAG,
        .version                = FC_BLOCK_VERSION,
        .readSampleClkSrc       = 1,
        .csHoldTime             = 3,
        .csSetupTime            = 3,
        .columnAddressWidth     = 0,
        .deviceModeCfgEnable    = 1,
        .deviceModeType         = 0,
        .waitTimeCfgCommands    = 0,
        .deviceModeSeq          = {.seqNum = 1 , .seqId = LUT_IDX_WRITE_STATUS},
        .deviceModeArg          = 0x40,
        .configCmdEnable        = 0,
        .controllerMiscOption   = 16,
        .deviceType             = 1,
        .sflashPadType          = 4,
        .serialClkFreq          = 4,
        .sflashA1Size           = 0x2000000,
        .sflashA2Size           = 0,
        .sflashB1Size           = 0,
        .sflashB2Size           = 0,
        .lookupTable =
        {
            /*
             * Sequence 0: XIP READ
             * 4-byte Quad I/O Fast Read, opcode 0xEC.
             * Command: 1-pad, Address: 4-pad/32-bit, Mode: 0xF0 on 4 pads,
             * Dummy: 4 cycles on 4 pads, Data: 4-pad.
             */
            [4 * LUT_IDX_READ + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0xEC, FC_RADDR_SDR, FC_FLEXSPI_4PAD, 0x20), 
            [4 * LUT_IDX_READ + 1] = FC_FLEXSPI_LUT_SEQ(FC_MODE8_SDR, FC_FLEXSPI_4PAD, 0xF0, FC_DUMMY_SDR, FC_FLEXSPI_4PAD, 0x04),
            [4 * LUT_IDX_READ + 2] = FC_FLEXSPI_LUT_SEQ(FC_READ_SDR,  FC_FLEXSPI_4PAD, 0x04, FC_STOP_EXE,  FC_FLEXSPI_1PAD, 0x00),

            /* Sequence 1: Read Status Register, opcode 0x05. */
            [4 * LUT_IDX_READ_STATUS + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR,  FC_FLEXSPI_1PAD, 0x05, FC_READ_SDR, FC_FLEXSPI_1PAD, 0x04), 

            /* Sequence 2: Write Status Register, opcode 0x01. Used to set QE bit = 0x40. */
            [4 * LUT_IDX_WRITE_STATUS + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0x01, FC_WRITE_SDR, FC_FLEXSPI_1PAD, 0x01),

            /* Sequence 3: Write Enable, opcode 0x06. */
            [4 * LUT_IDX_WRITE_ENABLE + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0x06, FC_STOP_EXE, FC_FLEXSPI_1PAD, 0x00),  

            /* Sequence 4: Write Disable, opcode 0x04. */
            [4 * LUT_IDX_WRITE_DISABLE + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0x04, FC_STOP_EXE, FC_FLEXSPI_1PAD, 0x00),

            /* Sequence 5: 4-byte 4 KByte Sector Erase, opcode 0x21. */
            [4 * LUT_IDX_ERASE_SECTOR_4K + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0x21, FC_RADDR_SDR, FC_FLEXSPI_1PAD, 0x20),

            /* Sequence 6: Read JEDEC ID, opcode 0x9F. Expected ISSI: 9D 60 1A. */
            [4 * LUT_IDX_READ_ID + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0x9F, FC_READ_SDR, FC_FLEXSPI_1PAD, 0x03),
            
            /* Sequence 7: Read SFDP, opcode 0x5A, 24-bit address plus 8 dummy bits. */
            [4 * LUT_IDX_READ_SFDP + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0x5A, FC_RADDR_SDR, FC_FLEXSPI_1PAD, 0x18),
            [4 * LUT_IDX_READ_SFDP + 1] = FC_FLEXSPI_LUT_SEQ(FC_DUMMY_SDR, FC_FLEXSPI_1PAD, 0x08, FC_READ_SDR,  FC_FLEXSPI_1PAD, 0x04),

            /* Sequence 8: 4-byte 64 KByte Block Erase, opcode 0xDC. */
            [4 * LUT_IDX_ERASE_BLOCK_64K + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0xDC, FC_RADDR_SDR, FC_FLEXSPI_1PAD, 0x20),

            /* Sequence 9: 4-byte Quad Page Program, opcode 0x34. */
            [4 * LUT_IDX_PAGE_PROGRAM_QUAD + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0x34, FC_RADDR_SDR, FC_FLEXSPI_1PAD, 0x20),
            [4 * LUT_IDX_PAGE_PROGRAM_QUAD + 1] = FC_FLEXSPI_LUT_SEQ(FC_WRITE_SDR, FC_FLEXSPI_4PAD, 0x00, FC_STOP_EXE,  FC_FLEXSPI_1PAD, 0x00),

            /* Sequence 10: Enter 4-byte address mode, opcode 0xB7. Optional with 4-byte opcodes. */
            [4 * LUT_IDX_ENTER_4BYTE_MODE + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0xB7, FC_STOP_EXE, FC_FLEXSPI_1PAD, 0x00),

            /* Sequence 11: Exit 4-byte address mode, opcode 0xE9. Optional with 4-byte opcodes. */
            [4 * LUT_IDX_EXIT_4BYTE_MODE + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0xE9, FC_STOP_EXE, FC_FLEXSPI_1PAD, 0x00),

            /* Sequence 12: Chip Erase, opcode 0xC7. */
            [4 * LUT_IDX_CHIP_ERASE + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0xC7, FC_STOP_EXE, FC_FLEXSPI_1PAD, 0x00),

            /* Sequence 13: Read Function/Register Status, opcode 0x48. Optional debug/helper. */
            [4 * LUT_IDX_READ_FLAG_STATUS + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0x48, FC_READ_SDR, FC_FLEXSPI_1PAD, 0x01),

            /* Sequence 14: Software Reset Enable, opcode 0x66. */
            [4 * LUT_IDX_SOFT_RESET_ENABLE + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0x66, FC_STOP_EXE, FC_FLEXSPI_1PAD, 0x00),

            /* Sequence 15: Software Reset, opcode 0x99. */
            [4 * LUT_IDX_SOFT_RESET + 0] = FC_FLEXSPI_LUT_SEQ(FC_CMD_SDR, FC_FLEXSPI_1PAD, 0x99, FC_STOP_EXE, FC_FLEXSPI_1PAD, 0x00),
        },
   },
        .pageSize               = IS25LP256M_PAGE_SIZE_BYTES,
        .sectorSize             = IS25LP256M_SECTOR_SIZE_BYTES,
        .ipcmdSerialClkFreq     = 0,
        .blockSize              = IS25LP256M_BLOCK_SIZE_BYTES,
        .fcb_fill[0]            = 0xFFFFFFFF,
};
