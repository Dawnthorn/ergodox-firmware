/* ----------------------------------------------------------------------------
 * ergoDOX layout : Dvorak (modified from the Kinesis layout)
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

#include "../../../lib-other/pjrc/usb_keyboard/usb_keyboard.h"

void kbfun_layer_push_1_and_led_1_on(void) {
  _kb_led_1_set_percent(MAKEFILE_LED_BRIGHTNESS/100);
  kbfun_layer_push_1();
  keyboard_leds |= 1;
}

void kbfun_layer_push_1_and_move_led_1_to_2(void) {
  kbfun_layer_push_1();
  keyboard_leds &= 0xfe;
  _kb_led_2_set_percent(MAKEFILE_LED_BRIGHTNESS/100);
  keyboard_leds |= 0x02;
}

void kbfun_layer_pop_1_and_turn_off_led_1_and_2(void) {
  kbfun_layer_pop_1();
  keyboard_leds &= 0xfc;
}

#define push1led1 &kbfun_layer_push_1_and_led_1_on
#define push1move12 &kbfun_layer_push_1_and_move_led_1_to_2
#define pop1off12 &kbfun_layer_pop_1_and_turn_off_led_1_and_2

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // layout: layer 0: kenesis dvorak modified
// unused
0,
// left hand
      _equal,         _1,         _2,      _3,      _4, _5, _5,
        _tab,     _quote,     _comma, _period,      _P, _Y,    1,
KEY_CapsLock,         _A,         _O,      _E,      _U, _I,
     _shiftL, _semicolon,         _Q,      _J,      _K, _X,    1,
      _ctrlL,     _grave,     _grave, _arrowL, _arrowR,
                                                 _ctrlL, _altL,
                                              0,      0, _home,
                                            _bs,   _esc,  _end,
// right hand
       _6,  _6,      _7,       _8,         _9,         _0,       _dash,
_bracketL,  _F,      _G,       _C,         _R,         _L,      _slash,
            _D,      _H,       _T,         _N,         _S,  _backslash,
        1,  _B,      _M,       _W,         _V,         _Z,     _shiftR,
                _arrowU,  _arrowD,  _bracketL,  _bracketR,           1,
 _altR, _ctrlR,
_pageU,      0,      0,
_pageD, _enter, _space ),


	KB_MATRIX_LAYER(  // layout: layer 1: function keys and right hand keypad
// unused
0,
// left hand
  0,        _F1,        _F2,       _F3,       _F4,       _F5, _F5,
  0,          0,          0,         0,         0,         0,   0,
  0,          0,          0,         0,         0,         0,
  0,          0,          0,         0,         0,         0,   0,
  0,          0,          0,         0,         0,
                                                             0,  0,
                                                         0,  0,  0,
                                                         0,  0,  0,
// right hand
_F12,       _F6,    _F7,       _F8,       _F9,         _F10,   _power,
   0, _equal_kp,  _7_kp,     _8_kp,     _9_kp,      _sub_kp, _volumeU,
        _div_kp,  _4_kp,     _5_kp,     _6_kp,      _add_kp, _volumeD,
   0,   _mul_kp,  _1_kp,     _2_kp,     _3_kp,    _enter_kp,    _mute,
                      0,         0,   _period,    _enter_kp,        2,
  0,  0,
  0,  0,  0,
  0,  0,  0 ),


	KB_MATRIX_LAYER(  // layout: layer 2: game qwerty
// unused
0,
// left hand
      _grave,  _1,  _2,      _3,       _4,  _5,  _5,
        _tab,  0,  _Q,       _W,       _E,  _R,  _T,
KEY_CapsLock,  0,  _A,       _S,       _D,  _F,
     _shiftL,  0,  _Z,       _X,       _C,  _V,  _G,
      _ctrlL,  0,   0,  _arrowL,  _arrowR,
		                                    _altL,  _ctrlL,
		                                0,      0,   _home,
		                           _space,   _esc,    _end,
// right hand
      _6,  _6,       _7,        _8,         _9,          _0,         _bs,
      0,   _Y,       _U,        _I,         _O,          _P,  _backslash,
	   _H,       _J,        _K,         _L,  _semicolon,      _quote,
      0,   _B,       _N,        _M,     _comma,     _period,      _slash,
                _arrowU,   _arrowD,  _bracketL,  _bracketR,            0,
   _altR,  _ctrlR,
  _pageU,       0,       0,
  _pageD,  _enter,  _space ),


	KB_MATRIX_LAYER(  // layout: layer 3: numpad
// unused
0,
// left hand
0,       0, 0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0, 0,
0, _insert, 0, 0, 0,
                     0, 0,
                  0, 0, 0,
                  0, 0, 0,
// right hand
3, 0,     3, _equal_kp, _div_kp,   _mul_kp, 0,
0, 0, _7_kp,     _8_kp,   _9_kp,   _sub_kp, 0,
   0, _4_kp,     _5_kp,   _6_kp,   _add_kp, 0,
0, 0, _1_kp,     _2_kp,   _3_kp, _enter_kp, 0,
          0,         0, _period, _enter_kp, 0,
0, 0,
0, 0,     0,
0, 0, _0_kp ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// aliases

// basic
#define  kprrel  &kbfun_press_release
#define  ktog    &kbfun_toggle
#define  ktrans  &kbfun_transparent
// --- layer push/pop functions
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // press: layer 0: kinesis dvorak modified
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                         kprrel, kprrel, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
         kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
         kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
         kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                         kprrel, kprrel, kprrel, kprrel, push1led1,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // press: layer 1: right hand keypad
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                         kprrel, kprrel, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                        kprrel, kprrel, kprrel, kprrel, push1move12,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),

	KB_MATRIX_LAYER(  // press: layer 2: game qwerty
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                         kprrel, kprrel, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                        kprrel, kprrel, kprrel, kprrel, pop1off12,
 kprrel, kprrel,
 kprrel,   NULL,  NULL,
 kprrel, kprrel, kprrel ),


};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // release: layer 0: kinesis dvorak modified
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                        kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),

	KB_MATRIX_LAYER(  // release: layer 1: function keys and right hand keypad
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                        kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),

	KB_MATRIX_LAYER(  // release: layer 2: qwerty game
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                        kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // release: layer 3: nothing (just making sure unused
			  // functions don't get compiled out)
// unused
NULL,
// other
 kprrel, lpush8,  lpop8,   NULL,   NULL,   NULL,   NULL,   NULL,
   ktog, lpush9,  lpop9,   NULL,   NULL,   NULL,   NULL,   NULL,
 ktrans,lpush10, lpop10,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush1,  lpop1,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush2,  lpop2, dbtldr,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush3,  lpop3,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush4,  lpop4, s2kcap,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush5,  lpop5,slpunum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush6,  lpop6,slponum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush7,  lpop7,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL )

};

