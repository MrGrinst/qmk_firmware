/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "rev1.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ELIXIR_PIPE:
        if (record->event.pressed) {
            SEND_STRING("|>");
        }
        break;
    case ELIXIR_FUNCTION:
        if (record->event.pressed) {
            SEND_STRING("->");
        }
        break;
    case ELIXIR_MAP:
        if (record->event.pressed) {
            SEND_STRING("%{");
        }
        break;
    }
    return true;
};

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (keyboard_report->mods & MOD_BIT(KC_LGUI)) {
            if (clockwise) {
                tap_code(KC_H);
            } else {
                tap_code(KC_L);
            }
        } else {
            // Up/down arrows
            if (clockwise) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_DOWN);
            }
        }
    }
    return true;
}
#endif
