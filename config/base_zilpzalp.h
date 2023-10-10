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
        COMBO(Sq, &kp LS(Q), 1 2 24)
        COMBO(Sz, &kp LS(Z), 18 19 24)
        COMBO(Sv, &kp LS(V), 0 1 24)
        COMBO(Ssch, &macro_shifted_sch, 0 2 24)
        COMBO(Sw, &kp LS(W), 0 24)
        COMBO(Sf, &kp LS(F), 1 24)
        COMBO(Sp, &kp LS(P), 2 24)
        COMBO(Sb, &kp LS(B), 3 24)
        COMBO(Sj, &kp LS(J), 4 27)
        COMBO(Sl, &kp LS(L), 5 27)
        COMBO(Su, &kp LS(U), 6 27)
        COMBO(Sy, &kp LS(Y), 7 27)
        COMBO(Sr, &kp LS(R), 8 24)
        COMBO(Ss, &kp LS(S), 9 24)
        COMBO(St, &kp LS(T), 10 24)
        COMBO(Sh, &kp LS(H), 11 24)
        COMBO(Sk, &kp LS(K), 12 24)
        COMBO(Sx, &kp LS(X), 13 27)
        COMBO(Sn, &kp LS(N), 14 27)
        COMBO(Sa, &kp LS(A), 15 27)
        COMBO(Si, &kp LS(I), 16 27)
        COMBO(So, &kp LS(O), 17 27)
        COMBO(Sc, &kp LS(C), 18 24)
        COMBO(Sg, &kp LS(G), 19 24)
        COMBO(Sd, &kp LS(D), 20 24)
        COMBO(Sm, &kp LS(M), 21 27)
        COMBO(Scomma, &kp SEMI, 22 27)
        COMBO(Sdot, &kp COLON, 23 27)
        COMBO(Se, &kp LS(E), 17 26)
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
