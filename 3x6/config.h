/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#pragma once

/* Trackball angle adjustment. */
#define ROTATIONAL_TRANSFORM_ANGLE -25

/* RGB settings. */
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_LED_COUNT 42
#    define RGB_MATRIX_SPLIT \
        { 18, 18 }
#endif
#define RGBLED_NUM 42
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define TAPPING_TERM 120
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#define CHARYBDIS_DRAGSCROLL_DPI 5
#define TAP_CODE_DELAY 20
#define RGBLIGHT_LIMIT_VAL 15
#define RGBLED_SPLIT {18, 18}

#define MOUSE_EXTENDED_REPORT

// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #define AUTO_MOUSE_DEFAULT_LAYER 4
// #define AUTO_MOUSE_TARGET_LAYER 4
// #define AUTO_MOUSE_DEBOUNCE 10
// #define AUTO_MOUSE_TIME 650
