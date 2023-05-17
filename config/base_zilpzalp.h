#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>

#define APT 0
#define NUM 1
#define NAV 2
#define SYM 3
#define FUN 4

&lt {
    quick_tap_ms = <170>;
};

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};


/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        combo_q {
            timeout-ms = <40>;
            key-positions = <1 2>;
            bindings = <&kp Q>;
        };
        combo_z {
            timeout-ms = <40>;
            key-positions = <18 19>;
            bindings = <&kp Z>;
        };
        combo_v {
            timeout-ms = <40>;
            key-positions = <0 1>;
            bindings = <&kp V>;
        };
        combo_slash {
            timeout-ms = <40>;
            key-positions = <22 23>;
            bindings = <&kp SLASH>;
        };
        combo_minus {
            timeout-ms = <40>;
            key-positions = <21 22>;
            bindings = <&kp MINUS>;
        };
        combo_esc {
            timeout-ms = <40>;
            key-positions = <19 20>;
            bindings = <&kp ESC>;
        };
/* parentheticals */
        combo_lbrc {
            timeout-ms = <40>;
            key-positions = <0 9>;
            bindings = <&kp LBRC>;
        };
        combo_lbkt {
            timeout-ms = <40>;
            key-positions = <1 10>;
            bindings = <&kp LBKT>;
        };
        combo_lpar {
            timeout-ms = <40>;
            key-positions = <2 11>;
            bindings = <&kp LPAR>;
        };
        combo_lt {
            timeout-ms = <40>;
            key-positions = <3 12>;
            bindings = <&kp LT>;
        };
        combo_gt {
            timeout-ms = <40>;
            key-positions = <4 13>;
            bindings = <&kp GT>;
        };
        combo_rpar {
            timeout-ms = <40>;
            key-positions = <5 14>;
            bindings = <&kp RPAR>;
        };
        combo_rbkt {
            timeout-ms = <40>;
            key-positions = <6 15>;
            bindings = <&kp RBKT>;
        };
        combo_rbrc {
            timeout-ms = <40>;
            key-positions = <7 16>;
            bindings = <&kp RBRC>;
        };
/* caps */
        combo_caps-word {
            timeout-ms = <40>;
            key-positions = <11 14>;
            bindings = <&caps_word>;
        };
        combo_capslock {
            timeout-ms = <40>;
            key-positions = <0 7>;
            bindings = <&kp CAPSLOCK>;
        };
/* deletion */
        combo_bspc {
            timeout-ms = <40>;
            key-positions = <5 6>;
            bindings = <&kp BSPC>;
        };
        combo_del {
            timeout-ms = <40>;
            key-positions = <6 7>;
            bindings = <&kp DEL>;
        };
        combo_delword {
            timeout-ms = <40>;
            key-positions = <5 7>;
            bindings = <&kp LC(BSPC)>;
        };
    };
};


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            flavor = "balanced";
            tapping-term-ms = <170>;
            quick-tap-ms = <100>;
            global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <4 5 6 7 13 14 15 16 17 21 22 23 26 27>;
        };

        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            flavor = "balanced";
            tapping-term-ms = <170>;
            quick-tap-ms = <100>;
            global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 8 9 10 11 12 18 19 20 24 25>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
