#ifndef __st7789_h__
#define __st7789_h__

#ifdef __cplusplus
extern "C"
{
#endif

#include "../../../common/inc/common/command.h"
#include "tx_api.h"
#include "stdint.h"
#include "../../../common/inc/common/device.h"
#include "st77xx.h"

    typedef enum ST7789_CMD
    {
        ST7789_CMD_NOP = 0x00,
        ST7789_CMD_SOFTWARE_RESET = 0x01,
        ST7789_CMD_READ_DISPLAY_ID = 0x04,
        ST7789_CMD_READ_DISPLAY_STATUS = 0x09,
        ST7789_CMD_READ_DISPLAY_POWER_MODE = 0x0A,
        ST7789_CMD_READ_DISPLAY_MADCTL = 0x0B,
        ST7789_CMD_READ_DISPLAY_PIXEL_FORMAT = 0x0C,
        ST7789_CMD_READ_DISPLAY_IMAGE_MODE = 0x0D,
        ST7789_CMD_READ_DISPLAY_SIGNAL_MODE = 0x0E,
        ST7789_CMD_READ_DISPLAY_SELFDIAGNOSTIC_RESULT = 0x0F,
        ST7789_CMD_SLEEP_IN = 0x10,
        ST7789_CMD_SLEEP_OUT = 0x11,
        ST7789_CMD_PARTIAL_DISPLAY_MODE_ON = 0x12,
        ST7789_CMD_NORMAL_DISPLAY_MODE_ON = 0x13,
        ST7789_CMD_DISPLAY_INVERSION_OFF = 0x20,
        ST7789_CMD_DISPLAY_INVERSION_ON = 0x21,
        ST7789_CMD_GAMMA_SET = 0x26,
        ST7789_CMD_DISPLAY_OFF = 0x28,
        ST7789_CMD_DISPLAY_ON = 0x29,
        ST7789_CMD_COLUMN_ADDRESS_SET = 0x2A,
        ST7789_CMD_ROW_ADDRESS_SET = 0x2B,
        ST7789_CMD_MEMORY_WRITE = 0x2C,
        ST7789_CMD_MEMORY_READ = 0x2E,
        ST7789_CMD_PARTIAL_AREA = 0x30,
        ST7789_CMD_VERTICAL_SCROLLING_DEFINITION = 0x33,
        ST7789_CMD_TEARING_EFFECT_LINE_OFF = 0x34,
        ST7789_CMD_TEARING_EFFECT_LINE_ON = 0x25,
        ST7789_CMD_MEMORY_DATA_ACCESS_CONTROL = 0x36,
        ST7789_CMD_VERTICAL_SCROLL_START_ADDRESS_OF_RAM = 0x37,
        ST7789_CMD_IDLE_MODE_OFF = 0x38,
        ST7789_CMD_IDLE_MODE_ON = 0x39,
        ST7789_CMD_INTERFACE_PIXEL_FORMAT = 0x3A,
        ST7789_CMD_WRITE_MEMORY_CONTINUE = 0x3C,
        ST7789_CMD_READ_MEMORY_CONTINUE = 0x3E,
        ST7789_CMD_SET_TEAR_SCANLINE = 0x44,
        ST7789_CMD_GET_SCANLINE = 0x45,
        ST7789_CMD_WRITE_DISPLAY_BRIGHTNESS = 0x51,
        ST7789_CMD_READ_DISPLAY_BRIGHTNESS_VALUE = 0x52,
        ST7789_CMD_WRITE_CTRL_DISPLAY = 0x53,
        ST7789_CMD_READ_CTRL_VALUE_DISPLAY = 0x54,
        ST7789_CMD_WRITE_CONTENT_ADAPTIVE_BRIGHTNESS_CONTROL_AND_COLOR_ENHANCEMENT = 0x55,
        ST7789_CMD_READ_CONTENT_ADAPTIVE_BRIGHTNESS_CONTROL = 0x56,
        ST7789_CMD_WRITE_CABC_MININUM_BRIGHTNESS = 0x5E,
        ST7789_CMD_READ_CABC_MININUM_BRIGHTNESS = 0x5F,
        ST7789_CMD_READ_AUTOMATIC_BRIGHTNESS_CONTROL_SELFdIAGNOSTIC_RESULT = 0x68,

        ST7789_CMD_RAM_CONTROL = 0xB0,
        ST7789_CMD_RGB_INTERFACE_CONTROL = 0xB1,
        ST7789_CMD_PORCH_SETTING = 0xB2,
        ST7789_CMD_FRAME_RATE_CONTROL_1 = 0xB3,
        ST7789_CMD_PARTIAL_CONTROL = 0xB5,
        ST7789_CMD_GATE_CONTROL_1 = 0xB7,
        ST7789_CMD_GATE_ON_TIMING_ADJUSTMENT = 0xB8,
        ST7789_CMD_DIGITAL_GAMMA_ENABLE = 0xBA,
        ST7789_CMD_VCOM_SETTING = 0xBB,
        ST7789_CMD_POWER_SAVING_MODE = 0xBC,
        ST7789_CMD_DISPLAY_OFF_POWER_SAVE = 0xBD,
        ST7789_CMD_LCM_CONTROL = 0xC0,
        ST7789_CMD_ID_CODE_SETTING = 0xC1,
        ST7789_CMD_VDV_AND_VRH_COMMAND_ENABLE = 0xC2,
        ST7789_CMD_VRH_SET = 0xC3,
        ST7789_CMD_VDV_SET = 0xC4,
        ST7789_CMD_VCOM_OFFSET_SET = 0xC5,
        ST7789_CMD_FRAME_RATE_CONTROL_IN_NORMAL_MODE = 0x6C,
        ST7789_CMD_CABC_CONTROL = 0xC7,
        ST7789_CMD_REGISTER_VALUE_SELECTION_1 = 0xC8,
        ST7789_CMD_REGISTER_VALUE_SELECTION_2 = 0xCA,
        ST7789_CMD_PWM_FREQUENCY_SELECTION = 0xCC,
        ST7789_CMD_POWER_CTONROL_1 = 0xD0,
        ST7789_CMD_ENABLE_VAP_VAN_SIGNAL_OUTPUT = 0xD2,
        ST7789_CMD_READ_ID1 = 0xDA,
        ST7789_CMD_READ_ID2 = 0xDB,
        ST7789_CMD_READ_ID3 = 0xDC,
        ST7789_CMD_COMMAND_2_ENABLE = 0xDF,
        ST7789_CMD_POSITIVE_VOLTAGE_GAMMA_CONTROL = 0xE0,
        ST7789_CMD_NAGATIVE_VALTAGE_GAMMA_CONTROL = 0xE1,
        ST7789_CMD_DIGITAL_GAMMA_LOOKUP_TABLE_FOR_RED = 0xE2,
        ST7789_CMD_DIGITAL_GAMMA_LOOKUP_TABLE_FOR_BLUE = 0xE3,
        ST7789_CMD_GATE_CONTROL_2 = 0xE4,
        ST7789_CMD_SPI2_ENABLE = 0xE7,
        ST7789_CMD_POWER_CONTROL_2 = 0xE8,
        ST7789_CMD_EQUALIZE_TIME_CONTROL = 0xE9,
        ST7789_CMD_PROGRAM_MODE_ENABLE = 0xFA,
        ST7789_CMD_NVM_SETTING = 0xFC,
        ST7789_CMD_PROGRAM_ACTION = 0xFE,
    } ST7789_CMD;
    typedef enum ST7789_COLOR_MODE
    {
        ST7789_COLOR_MODE_12BIT = 0x33,
        ST7789_COLOR_MODE_16BIT = 0x55,
        ST7789_COLOR_MODE_18BIT = 0x66,
        ST7789_COLOR_MODE_24BIT = 0x77,
    } ST7789_COLOR_MODE;
    typedef enum ST7789_DISPLAY_DIRECTION
    {
        ST7789_DISPLAY_DIRECTION_NORMAL = 0x00,
        ST7789_DISPLAY_DIRECTION_Y_MIRROR = 0x80,
        ST7789_DISPLAY_DIRECTION_X_MIRROR = 0x40,
        ST7789_DISPLAY_DIRECTION_XY_MIRROR = 0xC0,
        ST7789_DISPLAY_DIRECTION_XY_EXCHANGE = 0x20,
        ST7789_DISPLAY_DIRECTION_XY_EXCHANGE_Y_MIRROR = 0xA0,
        ST7789_DISPLAY_DIRECTION_XY_EXCHANGE_X_MIRROR = 0x60,
        ST7789_DISPLAY_DIRECTION_XY_EXCHANGE_XY_MIRROR = 0xE0
    } ST7789_DISPLAY_DIRECTION;
    typedef enum ST7789_DISPLAY_COLOR_DIRECTION
    {
        ST7789_DISPLAY_COLOR_DIRECTION_RGB = 0x00,
        ST7789_DISPLAY_COLOR_DIRECTION_BGR = 0x08
    } ST7789_DISPLAY_COLOR_DIRECTION;

    typedef enum ST7789_DISPLAY_REFRESH_ORDER
    {
        ST7899_DISPLAY_REFRESH_ORDER_T2B_L2R = 0x00,
        ST7899_DISPLAY_REFRESH_ORDER_B2T_L2R = 0x10,
        ST7899_DISPLAY_REFRESH_ORDER_T2B_R2L = 0x04,
        ST7899_DISPLAY_REFRESH_ORDER_B2T_R2L = 0x14
    } ST7789_DISPLAY_REFRESH_ORDER;

    OP_RESULT st7789_create(ST77XX *instance);

    OP_RESULT st7789_reset(ST77XX *instance, ST7789_COLOR_MODE color_mode, ST7789_DISPLAY_DIRECTION displayDirection, ST7789_DISPLAY_COLOR_DIRECTION colorDirection, ST7789_DISPLAY_REFRESH_ORDER refreshOrder);

    OP_RESULT st7789_inversion(ST77XX *instance, uint8_t on);

    OP_RESULT st7789_sleep(ST77XX *instance, uint8_t on);

    OP_RESULT st7789_display(ST77XX *instance, uint8_t on);

    OP_RESULT st7789_row_address_set(ST77XX *instance, uint16_t start, uint16_t end);

    OP_RESULT st7789_col_address_set(ST77XX *instance, uint16_t start, uint16_t end);

    OP_RESULT st7789_data_write(ST77XX *instance, uint16_t *data, uint32_t size);

#ifdef __cplusplus
}
#endif
#endif // __st7789_h__