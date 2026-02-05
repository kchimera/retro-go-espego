// Target definition
#define RG_TARGET_NAME "espego"

// Storage
#define RG_STORAGE_ROOT             "/sd"
#define RG_STORAGE_SDSPI_HOST       SPI3_HOST
#define RG_STORAGE_SDSPI_SPEED      SDMMC_FREQ_DEFAULT
// #define RG_STORAGE_SDMMC_HOST       SDMMC_HOST_SLOT_1
// #define RG_STORAGE_SDMMC_SPEED      SDMMC_FREQ_DEFAULT
// #define RG_STORAGE_FLASH_PARTITION  "vfs"


// Audio
#define RG_AUDIO_USE_INT_DAC        0   // 0 = Disable, 1 = GPIO25, 2 = GPIO26, 3 = Both
#define RG_AUDIO_USE_EXT_DAC        1   // 0 = Disable, 1 = Enable

// Video
#define RG_SCREEN_DRIVER            0   // 0 = ILI9341/ST7789
#define RG_SCREEN_HOST              SPI2_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_80M // SPI_MASTER_FREQ_80M
#define RG_SCREEN_BACKLIGHT         1
#define RG_SCREEN_ROTATE            2
#define RG_SCREEN_WIDTH             320  //1.3 inch 240  2.4 inch 320
#define RG_SCREEN_HEIGHT            172
#define RG_SCREEN_VISIBLE_AREA      {0,0, 0, 0}
#define RG_SCREEN_SAFE_AREA         {0, 0, 0, 0}
#define RG_SCREEN_INIT()                                                                             \
    ILI9341_CMD(0x3A, 0x55);                                                                         \
    ILI9341_CMD(0x36, 0x60);                                                                        \
    ILI9341_CMD(0xB2, 0x0C, 0x0c, 0x00, 0x33, 0x33);                                                 \
    ILI9341_CMD(0xB7, 0x35);                                                                         \
    ILI9341_CMD(0xBB, 0x20);                                                                         \
    ILI9341_CMD(0xC0, 0x2C);                                                                         \
    ILI9341_CMD(0xC2, 0x01);                                                                         \
    ILI9341_CMD(0xC3, 0x0B);                                                                         \
    ILI9341_CMD(0xC4, 0x20);                                                                         \
    ILI9341_CMD(0xC6, 0x0F);                                                                         \
    ILI9341_CMD(0xE0, 0xD0,0x04,0x0D,0x11,0x13,0x2B,0x3F,0x54,0x4C,0x18,0x0D,0x0B,0x1F,0x23);        \
    ILI9341_CMD(0xE1, 0xD0,0x04,0x0C,0x11,0x13,0x2C,0x3F,0x44,0x51,0x2F,0x1F,0x1F,0x20,0x23);        \
    ILI9341_CMD(0x21);                                                                               \
    ILI9341_CMD(0x29);

// Input
// Refer to rg_input.h to see all available RG_KEY_* and RG_GAMEPAD_*_MAP types
#define RG_GAMEPAD_GPIO_MAP {\
    {RG_KEY_UP,     .num = GPIO_NUM_1,  .pullup = 1, .level = 0},\
    {RG_KEY_RIGHT,  .num = GPIO_NUM_2,  .pullup = 1, .level = 0},\
    {RG_KEY_DOWN,   .num = GPIO_NUM_3, .pullup = 1, .level = 0},\
    {RG_KEY_LEFT,   .num = GPIO_NUM_4, .pullup = 1, .level = 0},\
    {RG_KEY_SELECT, .num = GPIO_NUM_5, .pullup = 1, .level = 0},\
    {RG_KEY_START,  .num = GPIO_NUM_6, .pullup = 1, .level = 0},\
    {RG_KEY_MENU,   .num = GPIO_NUM_7, .pullup = 1, .level = 0},\
    {RG_KEY_OPTION, .num = GPIO_NUM_8,  .pullup = 1, .level = 0},\
    {RG_KEY_A,      .num = GPIO_NUM_9, .pullup = 1, .level = 0},\
    {RG_KEY_B,      .num = GPIO_NUM_10,  .pullup = 1, .level = 0},\
}

// Battery
#define RG_BATTERY_DRIVER           0
#define RG_BATTERY_ADC_UNIT         ADC_UNIT_1
#define RG_BATTERY_ADC_CHANNEL      ADC_CHANNEL_3
#define RG_BATTERY_CALC_PERCENT(raw) (((raw) * 2.f - 3500.f) / (4200.f - 3500.f) * 100.f)
#define RG_BATTERY_CALC_VOLTAGE(raw) ((raw) * 2.f * 0.001f)

// Status LED
#define RG_GPIO_LED                 GPIO_NUM_38

// SPI Display
#define RG_GPIO_LCD_MISO            GPIO_NUM_NC
#define RG_GPIO_LCD_MOSI            GPIO_NUM_45
#define RG_GPIO_LCD_CLK             GPIO_NUM_40
#define RG_GPIO_LCD_CS              GPIO_NUM_42
#define RG_GPIO_LCD_DC              GPIO_NUM_41
#define RG_GPIO_LCD_BCKL            GPIO_NUM_46
#define RG_GPIO_LCD_RST             GPIO_NUM_39

// SPI SD Card
#define RG_GPIO_SDSPI_MISO          GPIO_NUM_16
#define RG_GPIO_SDSPI_MOSI          GPIO_NUM_15
#define RG_GPIO_SDSPI_CLK           GPIO_NUM_14
#define RG_GPIO_SDSPI_CS            GPIO_NUM_21

// External I2S DAC
#define RG_GPIO_SND_I2S_BCK         GPIO_NUM_NC
#define RG_GPIO_SND_I2S_WS          GPIO_NUM_NC
#define RG_GPIO_SND_I2S_DATA        GPIO_NUM_NC
#define RG_GPIO_SND_AMP_ENABLE      GPIO_NUM_NC
