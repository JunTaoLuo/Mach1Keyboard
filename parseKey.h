#ifndef PARSEKEY_H
#define PARSEKEY_H

#include <string.h>

// Modifiers
#define MOD_CONTROL_LEFT    (1<<0)
#define MOD_SHIFT_LEFT      (1<<1)
#define MOD_ALT_LEFT        (1<<2)
#define MOD_GUI_LEFT        (1<<3)
#define MOD_CONTROL_RIGHT   (1<<4)
#define MOD_SHIFT_RIGHT     (1<<5)
#define MOD_ALT_RIGHT       (1<<6)
#define MOD_GUI_RIGHT       (1<<7)

// Keys
#define KEY_A       4
#define KEY_1       30

// Typedef
typedef unsigned char byte;

struct KeyInfo {
    byte Key;
    byte Modifier;
};

byte ParseModifier(char modifier) {
    switch (modifier) {
        case '^':
            return MOD_CONTROL_LEFT;
        case '+':
            return MOD_SHIFT_LEFT;
        case '!':
            return MOD_ALT_LEFT;
        case '#':
            return MOD_GUI_LEFT;
        default:
            return 0;
    }
}

byte ParseKey(char key) {
    if ('A' <= key && key <= 'Z')
        return KEY_A + (key - 'A');
    if ('a' <= key && key <= 'z')
        return KEY_A + (key - 'a');
    if ('0' <= key && key <= '9')
        return KEY_1 + (key - '0');
    return 0;
}

struct KeyInfo ParseKeyInfo(char* keyString) {
    struct KeyInfo keyInfo;
    
    byte index;
    for (index = 0; index < strlen(keyString); index++) {
        char keyChar = keyString[index];
        byte parsedKey = 0;
        switch (keyChar) {
            case '<' :
                index++;
                keyInfo.Modifier |= ParseModifier(keyString[index]);
                break;
            case '>' :
                index++;
                keyInfo.Modifier |= ParseModifier(keyString[index]) << 4;
                break;
            default :
                parsedKey = ParseModifier(keyChar);
                if (parsedKey) {
                    keyInfo.Modifier |= parsedKey;
                    break;
                }
                parsedKey = ParseKey(keyChar);
                if (parsedKey) {
                    keyInfo.Key = parsedKey;
                    break;
                }
                break;
        }
    }
    return keyInfo;
}

#endif
