#include <stdio.h>
#include "parseKey.h"

int main() {
    struct KeyInfo key = ParseKey("");
    printf("0x%x\n", key.Key);
    printf("0x%x\n", key.Modifier);
}
