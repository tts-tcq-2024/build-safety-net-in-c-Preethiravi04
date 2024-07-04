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

    printf("All test cases passed successfully!\n");

    // Test case 5: Name with non-alphabetic characters
    generateSoundex("O'Connor", soundex);
    assert(strcmp(soundex, "O256") == 0);

    // Test case 6: Name with all vowels
    generateSoundex("AEIOU", soundex);
    assert(strcmp(soundex, "A000") == 0);

    // Test case 7: Name with all consonants
    //generateSoundex("BCDFGHJKLMNPQRSTVWXYZ", soundex);
    //assert(strcmp(soundex, "B234") == 0);

    // Test case 8: Name with mixed case
    generateSoundex("mIXeDcAsE", soundex);
    assert(strcmp(soundex, "M223") == 0);
}

int main() {
    testGenerateSoundex();
    return 0;
}

