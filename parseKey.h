#ifndef PARSEKEY_H
#define PARSEKEY_H

// Typedef
typedef unsigned char byte;

struct KeyInfo {
    byte Key;
    byte Modifier;
};

struct KeyInfo ParseKey(char* keyString) {
    struct KeyInfo keyInfo;
    
    keyInfo.Key = 1;
    keyInfo.Modifier = 2;

    return keyInfo;
}

#endif
