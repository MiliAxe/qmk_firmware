/* Copyright 2024 Vaarai
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cornia.h"

// 'Cornia', 32x32px
#define OLED_LOGO_CORNIA {\
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, \
        0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, \
        0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xfd, 0xe1, \
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, \
        0x00, 0x00, 0xc0, 0xf8, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x07, 0x3f, 0xff, 0xff, \
        0xff, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
        0x00, 0x1e, 0x1f, 0x1f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, \
        0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0e, 0x00  \
    }

void cornia_render_logo(void) {
#ifdef OLED_ENABLE
    static const char PROGMEM logo[] = OLED_LOGO_CORNIA;
    oled_write_raw_P(logo, sizeof(logo));
#endif
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    cornia_render_logo();
    return true;
}
