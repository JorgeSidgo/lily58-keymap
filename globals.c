enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _MEDIA,
    _PADS,
    _ADJUST,
};

typedef enum { 
    TD_NONE, 
    TD_UNKNOWN, 
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP 
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum tap_dance {
    TT_LAYER_RAISE,
    TT_LAYER_LOWER,
    TT_ALT_MEDIA
};
