#include <stdio.h>
#include "parseKey.h"

int main() {
    struct KeyInfo key = ParseKeyInfo("b");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
    key = ParseKeyInfo("2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);

    key = ParseKeyInfo("^2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
    key = ParseKeyInfo("^+2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
    key = ParseKeyInfo("!+^2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
    key = ParseKeyInfo("!^#+2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);

    key = ParseKeyInfo("<^2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
    key = ParseKeyInfo("<^<+2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
    key = ParseKeyInfo("<!<+<^2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
    key = ParseKeyInfo("<!<^<#<+2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);

    key = ParseKeyInfo(">^2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
    key = ParseKeyInfo(">^>+2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
    key = ParseKeyInfo(">!>+>^2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
    key = ParseKeyInfo(">!>^>#>+2");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);

    key = ParseKeyInfo(">!>^>#>+{Enter}");
    printf("Key: 0d%d\n", key.Key);
    printf("Modifier: 0x%x\n", key.Modifier);
}
