#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>

#define APT 0
#define NUM 1
#define NAV 2
#define SYM 3
#define FUN 4

// &lt {
//     quick_tap_ms = <170>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
    macros {
        macro_sch: macro_sch {
            label = "Macro_sch";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&macro_tap &kp S &kp C &kp H>;
        };
        macro_shifted_sch: macro_shifted_sch {
            label = "Macro_Sch";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&macro_tap &kp LS(S) &kp C &kp H>;
        };
    };
};


#define COMBO(NAME, BINDINGS, KEYPOS) \
combo_##NAME { \
    timeout-ms = <20>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        COMBO(q, &kp Q, 1 2)
        COMBO(z, &kp Z, 18 19)
        COMBO(v, &kp V, 0 1)
        COMBO(sch, &macro_sch, 0 2)
        COMBO(slash, &kp SLASH, 22 23)
        COMBO(dash, &kp MINUS, 21 22)
//        COMBO(enter, &kp ENTER, 21 22 23)
        COMBO(enter, &kp ENTER, 21 23)
        COMBO(esc, &kp ESC, 19 20)
/* parentheticals */
        COMBO(lbrc, &kp LBRC, 0 9)
        COMBO(lbkt, &kp LBKT, 1 10)
        COMBO(lpar, &kp LPAR, 2 11)
        COMBO(lt, &kp LT, 3 12)
        COMBO(gt, &kp GT, 4 13)
        COMBO(rpar, &kp RPAR, 5 14)
        COMBO(rbkt, &kp RBKT, 6 15)
        COMBO(rbrc, &kp RBRC, 7 16)
/* caps */
        COMBO(caps, &caps_word, 11 14)
        COMBO(capslock, &kp CAPSLOCK, 0 7)
/* deletion */
        COMBO(bspc, &kp BSPC, 5 6)
        COMBO(del, &kp DEL, 6 7)
        COMBO(delword, &kp LC(BSPC), 5 7)
/* alternative shifting */
	COMBO(shifted_q, &kp LS(Q), 24 1 2)
	COMBO(shifted_z, &kp LS(Z), 24 18 19)
	COMBO(shifted_v, &kp LS(V), 24 0 1)
        COMBO(shifted_sch, &macro_shifted_sch, 24 0 2)
	COMBO(shifted_w, &kp LS(W), 24 0)
	COMBO(shifted_f, &kp LS(F), 24 1)
	COMBO(shifted_p, &kp LS(P), 24 2)
	COMBO(shifted_b, &kp LS(B), 24 3)
	COMBO(shifted_j, &kp LS(J), 27 4)
	COMBO(shifted_l, &kp LS(L), 27 5)
	COMBO(shifted_u, &kp LS(U), 27 6)
	COMBO(shifted_y, &kp LS(Y), 27 7)
	COMBO(shifted_r, &kp LS(R), 24 4)
	COMBO(shifted_s, &kp LS(S), 24 5)
	COMBO(shifted_t, &kp LS(T), 24 6)
	COMBO(shifted_h, &kp LS(H), 24 7)
	COMBO(shifted_k, &kp LS(K), 24 8)
	COMBO(shifted_x, &kp LS(X), 27 9)
	COMBO(shifted_n, &kp LS(N), 27 10)
	COMBO(shifted_a, &kp LS(A), 27 11)
	COMBO(shifted_i, &kp LS(I), 27 12)
	COMBO(shifted_o, &kp LS(O), 27 13)
	COMBO(shifted_c, &kp LS(C), 24 14)
	COMBO(shifted_g, &kp LS(G), 24 15)
	COMBO(shifted_d, &kp LS(D), 24 16)
	COMBO(shifted_m, &kp LS(M), 27 17)
	COMBO(shifted_e, &kp LS(E), 17 26)
    };
};

//     __________________________  __________________________
//    /     0  |  1  |  2  |  3  \/   4 |   5 |   6 |   7    \
// |  8  |  9  | 10  | 11  | 12  /\  13 |  14 |  15 |  16 | 17  |
//    \    18  | 19  | 20    /        \    21 |  22 |  23   /
//          \    24  | 25  /            \  26 |  27    /
//           --------------              --------------


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <4 5 6 7 13 14 15 16 17 21 22 23 24 25 26 27>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 8 9 10 11 12 18 19 20 24 25 26 27>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            // hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23>;
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
