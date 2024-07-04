#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Function to get the Soundex code for a character
char getSoundexCode(char c) {
    static const char soundexCodes[26] = {'0', '1', '2', '3','0',  '1',  '2',  '0','0',  '2',  '2', '4','5', '5', '0',  '1', '2', '6','2', '3','0', '1',  '0', '2','0', '2'};

    c = toupper(c);
    unsigned int index = c - 'A';
    return (index < 26) ? soundexCodes[index] : '0';
}


#include "Soundex.h"
#include <ctype.h>
#include <string.h>

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    
    soundex[4] = '\0';
}
#endif
