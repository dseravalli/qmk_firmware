#include QMK_KEYBOARD_H

#define LAYER_2_INDICATOR_LED_INDEX 64

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, MO(1), KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RALT, TG(2), KC_LEFT, KC_DOWN, KC_RGHT),
    [1] = LAYOUT_65_ansi(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, RGB_VAI, RGB_VAD, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_SPI, RGB_SPD, KC_TRNS, KC_TRNS, KC_VOLU, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT),
    [2] = LAYOUT_65_ansi(QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, KC_LCTL, KC_NO, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, TG(2), KC_LEFT, KC_DOWN, KC_RGHT),
    [3] = LAYOUT_65_ansi(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    bool layer_2_active = layer_state_is(2);

    // Check if the global RGB effect is essentially "off" via brightness=0
    // BUT ensure the matrix itself is still enabled.
    // Use rgb_matrix_get_val() instead of rgb_matrix_config.val
    if (rgb_matrix_config.enable && rgb_matrix_get_val() == 0) {
        // RGB brightness is 0, but we want the indicator
        if (layer_2_active) {
            // Set indicator to a visible color (e.g., dim red)
            rgb_matrix_set_color(LAYER_2_INDICATOR_LED_INDEX, 100, 0, 0); // Dim Red
        } else {
            // Ensure the indicator LED is off if layer 2 is not active and brightness is 0
            rgb_matrix_set_color(LAYER_2_INDICATOR_LED_INDEX, 0, 0, 0); // Explicitly off
        }
        return true;

    } else if (rgb_matrix_config.enable) {
        // RGB is enabled and brightness > 0 (normal operation)
        if (layer_2_active) {
            // Set indicator to bright red
            rgb_matrix_set_color(LAYER_2_INDICATOR_LED_INDEX, 255, 0, 0); // Bright Red
        }
        // Let default animation handle the LED color when layer 2 is off
        return true;
    }

    // If rgb_matrix_config.enable is false (RGB_TOG was used), let default processing run.
    return true;
}
#endif // RGB_MATRIX_ENABLE
