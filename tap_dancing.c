td_state_t cur_dance(qk_tap_dance_state_t *state);

void lr_finished(qk_tap_dance_state_t *state, void *user_data);
void lr_reset(qk_tap_dance_state_t *state, void *user_data);

void ll_finished(qk_tap_dance_state_t *state, void *user_data);
void ll_reset(qk_tap_dance_state_t *state, void *user_data);

void alt_media_finished(qk_tap_dance_state_t *state, void *user_data);
void alt_media_reset(qk_tap_dance_state_t *state, void *user_data);

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return TD_SINGLE_TAP;
        } else {
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        return TD_DOUBLE_TAP;
    } else {
        return TD_UNKNOWN;
    }
    return TD_UNKNOWN;
}

static td_tap_t lr_tap_state = {.is_press_action = true, .state = TD_NONE};

static td_tap_t ll_tap_state = {.is_press_action = true, .state = TD_NONE};

static td_tap_t alt_media_tap_state = {.is_press_action = true, .state = TD_NONE};

void alt_media_finished(qk_tap_dance_state_t *state, void *user_data) {
    alt_media_tap_state.state = cur_dance(state);
    switch (alt_media_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_LALT);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_MEDIA);
            break;
        case TD_DOUBLE_TAP:
            if (layer_state_is(_MEDIA)) {
                layer_off(_MEDIA);
            } else {
                layer_on(_MEDIA);
            }
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void alt_media_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (alt_media_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_MEDIA);
    }
    alt_media_tap_state.state = TD_NONE;
}

void lr_finished(qk_tap_dance_state_t *state, void *user_data) {
    lr_tap_state.state = cur_dance(state);
    switch (lr_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_ENT);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_RAISE);
            break;
        case TD_DOUBLE_TAP:
            if (layer_state_is(_RAISE)) {
                layer_off(_RAISE);
            } else {
                layer_on(_RAISE);
            }
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void lr_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (lr_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_RAISE);
    }
    lr_tap_state.state = TD_NONE;
}

void ll_finished(qk_tap_dance_state_t *state, void *user_data) {
    ll_tap_state.state = cur_dance(state);
    switch (ll_tap_state.state) {
        case TD_SINGLE_HOLD:
            layer_on(_LOWER);
            break;
        case TD_DOUBLE_TAP:
            if (layer_state_is(_LOWER)) {
                layer_off(_LOWER);
            } else {
                layer_on(_LOWER);
            }
            break;
        case TD_SINGLE_TAP:
            break;            
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void ll_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (ll_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_LOWER);
    }
    ll_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TT_LAYER_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, lr_finished, lr_reset, 175), 
    [TT_LAYER_LOWER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ll_finished, ll_reset),
    [TT_ALT_MEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_media_finished, alt_media_reset)
};