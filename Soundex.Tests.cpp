#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>


void testGenerateSoundex() {
    char soundex[5];

    // Test case 1: Basic name
    generateSoundex("Smith", soundex);
    assert(strcmp(soundex, "S530") == 0);

    // Test case 2: Name with repeated codes
    generateSoundex("Johnson", soundex);
    assert(strcmp(soundex, "J525") == 0);

    // Test case 3: Name with mixed vowels and consonants
    generateSoundex("Euler", soundex);
    assert(strcmp(soundex, "E460") == 0);

    // Test case 4: Short name
    generateSoundex("Lee", soundex);
    assert(strcmp(soundex, "L000") == 0);

    // Test case 5: Empty name
    generateSoundex("", soundex);
    assert(strcmp(soundex, "0000") == 0);

    printf("All test cases passed successfully!\n");
}

int main() {
    testGenerateSoundex();
    return 0;
}

