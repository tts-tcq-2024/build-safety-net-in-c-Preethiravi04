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

void generateSoundex(const char *name, char *soundex) {
    initializeSoundex(name, soundex);
    char previousCode = initializePreviousCode(name);
    processName(name, soundex, previousCode);
} 
    int i;
for (i = 1; name[i] != '\0'; i++) {
    if (sIndex >= 4) {
        break;  // Exit loop if we've filled soundex up to index 3
    }
    
    char code = getSoundexCode(name[i]);
    // Process code as needed, e.g., check if it's valid and add to soundex array
    
    sIndex++;  // Increment index for soundex array
}

// Ensure sIndex does not exceed 4
sIndex = (sIndex > 4) ? 4 : sIndex;

        
if (code != '0' && code != previousCode) {
    soundex[sIndex++] = code;
    previousCode = code;
}

for (; sIndex < 4; sIndex++) {
    soundex[sIndex] = '0';  // Fill remaining positions with '0'
}

soundex[sIndex] = '\0';  // Null-terminate soundex string


#endif
