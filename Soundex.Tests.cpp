#include <gtest/gtest.h>
#include "Soundex.h"

#include <stdio.h>
#include <assert.h>

int main() {
    char soundex[5];

    // Test case 1: Basic test with a simple name
    generateSoundex("Smith", soundex);
    assert(strcmp(soundex, "S530") == 0);

    // Test case 2: Test with a single-character name
    generateSoundex("A", soundex);
    assert(strcmp(soundex, "A000") == 0);

    // Test case 3: Test with an empty name
    //generateSoundex("", soundex);
    //assert(strcmp(soundex, "0000") == 0);

    // Test case 4: Test with a null pointer for name
    generateSoundex(NULL, soundex);
    assert(strcmp(soundex, "0000") == 0);

    // All tests passed
    printf("All tests passed!\n");

    return 0;
}


