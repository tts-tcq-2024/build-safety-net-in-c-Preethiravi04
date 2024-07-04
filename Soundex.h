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
    if (!name || !*name) {
        // Handle invalid input or empty name
        soundex[0] = '\0';
        return;
    }
     soundex[0] = toupper(name[0]);  // Always take the first character
    char previousCode = getSoundexCode(name[0]);  // Get initial soundex code
    int sIndex = 1;  // Initialize index for soundex array
    
   for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);  // Get soundex code for current character
        
        if (code != '0' && code != previousCode) {
            soundex[sIndex++] = code;  // Add valid code to soundex array
            previousCode = code;  // Update previous code
        }
    }
    
    // Fill remaining positions with '0' if necessary
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    
    soundex[4] = '\0';  // Ensure soundex string is null-terminated
}


#endif
