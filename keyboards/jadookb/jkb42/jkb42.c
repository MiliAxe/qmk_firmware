
#include "jkb42.h"

#include "quantum.h"
#include "qp.h"
#include "qp_comms.h"
#include "qp_st77xx_opcodes.h"
#include "gfx/logo/logo.qgf.h"
#include "gfx/winxp/winxp.qgf.h"
#include "gfx/cat/cat.qgf.h"
#include QMK_KEYBOARD_H

painter_device_t lcd;

static deferred_token my_anim;
static deferred_token my_anim1;
int count = 1;

void keyboard_post_init_kb(void) {




    wait_ms(LCD_WAIT_TIME);

    // Initialise the LCD
    lcd = qp_st7735_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, 0);
    qp_init(lcd, LCD_ROTATION);

    qp_clear(lcd);

    qp_comms_start(lcd);
    qp_comms_command(lcd, ST77XX_CMD_INVERT_ON);
    qp_comms_stop(lcd);

    // Apply Offset
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X+1, LCD_OFFSET_Y+1);

    qp_power(lcd, true);
    qp_flush(lcd);

   
        qp_stop_animation(my_anim1);
        qp_rect(lcd, 0, 0, LCD_WIDTH, LCD_HEIGHT, HSV_BLACK, true);
        painter_image_handle_t logo_image = qp_load_image_mem(gfx_cat);
        my_anim = qp_animate(lcd, 0, 0, logo_image);
        
        qp_flush(lcd);
   keyboard_post_init_user();

}
