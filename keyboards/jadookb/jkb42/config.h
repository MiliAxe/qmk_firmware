
#pragma once

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_PIN_SWAP
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* any side can be master by default, enable split sync to support it */
#define EE_HANDS


// SPI pins
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP10
#define SPI_MOSI_PIN GP11
#define SPI_MISO_PIN GP12

// LCD Configuration
#define LCD_RST_PIN GP13
#define LCD_DC_PIN GP12
#define LCD_CS_PIN GP9
#define LCD_BLK_PIN GP14//-1 //GP7
#define LCD_SPI_DIVISOR 4
#define LCD_WAIT_TIME 1000
#define LCD_WIDTH 128
#define LCD_HEIGHT 128
#define LCD_ROTATION QP_ROTATION_0
#define LCD_OFFSET_X 0
#define LCD_OFFSET_Y 0


// QP Configuration
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
#define ST7735_NO_AUTOMATIC_VIEWPORT_OFFSETS


// Timeout configuration
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 120000
#define LIGHTS_TIMEOUT QUANTUM_PAINTER_DISPLAY_TIMEOUT
