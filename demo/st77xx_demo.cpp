#include "st77xx_demo.hpp"
#include "soc.hpp"
#include "accessor/command.hpp"
#include "device/st7735.hpp"
#include "graph.hpp"

namespace ww::device::demo
{
using namespace ww::accessor;
using namespace ww::device;
using namespace ww::os;
using namespace ww::peripheral;
using namespace ww::graph;

static SPI_HandleTypeDef hspi4;
// static Pin csPin();
static Pin dcPin(*GPIOE, GPIO_PIN_13);
static SpiWithPins spi4pDev(hspi4, nullptr, nullptr, &dcPin);
static EventGroup eg("");
static CommandSpi st7735_cmd(spi4pDev, eg, 0x01, 0x02, 0x04, 500);
#define ST7735_BUFFER_SIZE 160 * 80 * 2
// static uint8_t st7735Buffer[ST7735_BUFFER_SIZE];
static ST7735 st7735(st7735_cmd);

#define LCD_DATA_SIZE 100
static uint16_t lcddata[LCD_DATA_SIZE];

static void test05_init()
{
    auto &cfg = st7735.config_get();
    cfg.xOffset = 1;
    cfg.yOffset = 26;
    cfg.width = 160;
    cfg.height = 80;
    cfg.colorMode = ST7735_COLOR_MODE_16BIT;
    cfg.orientation = ST7735_DISPLAY_DIRECTION_XY_EXCHANGE_Y_MIRROR |
                      ST7735_DISPLAY_COLOR_DIRECTION_BGR |
                      ST7735_DISPLAY_REFRESH_ORDER_T2B_L2R;
    st7735.init();
    st7735.reset();
    // st77xx_inversion(&st7735, 1);
    for (size_t i = 0; i < LCD_DATA_SIZE; i++)
    {
        lcddata[i] = (0xF800);
    }
}

static void test05()
{
    Color565 color0 = {.value = 0x28A5};
    // Color565 color1 = {.value = 0x001F};
    Color565 color2 = {.value = 0xF800};
    Color565 color3 = {.value = 0x04F1};
    st7735.rect_fill(0, 0, st7735.config_get().width,
                     st7735.config_get().height,
                     color0.value); // inv:1=red; inv:0=yellow
    // st7735.hline_draw(10, 10, 20,
    //                   &color1.value); // inv:1=red+green; inv:0=sky+pink
    st7735.rect_fill(20, 20, 30, 30, color2.value); // inv:1=blue; inv:0=sky
    st7735.rect_fill(40, 20, 50, 50, color3.value); // inv:1=red; inv:0=yellow
}

static void run()
{
    float num = 0.1;

    test05_init();
    /* This thread simply sits in while-forever-sleep loop.  */
    while (1)
    {
        test05();
        num += 0.15;

        /* Sleep for 1000 ticks.  */
        Thread::sleep(1000 + (uint32_t)(num * 100));

        // printf("thread0 running\n");
        // HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
        // HAL_UART_Transmit(&CONVERT_REFERENCE(huart4, UART_HandleTypeDef),
        // memory_area, 10, HAL_MAX_DELAY);

        /* Check status.  */
        // if (status != TX_SUCCESS)
        //     break;
    }
}

void st77xx_demo()
{
    dcPin.config_get().inverse = false;
    dcPin.init();

    /* Create the main thread.  */
    run();
};
} // namespace ww::device::demo