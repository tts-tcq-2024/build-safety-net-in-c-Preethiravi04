#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <string.h>


int main() {
    char soundex[5];

    // Test case 1: Basic test with a simple name
    generateSoundex("Smith", soundex);
    printf("Soundex for Smith: %s\n", soundex);

    // Test case 2: Test with a single-character name
    generateSoundex("A", soundex);
    printf("Soundex for A: %s\n", soundex);

    // Test case 3: Test with an empty name
    generateSoundex("", soundex);
    printf("Soundex for empty name: %s\n", soundex);

    // Test case 4: Test with a null pointer for name
    generateSoundex(NULL, soundex);
    printf("Soundex for null name: %s\n", soundex);

    return 0;
}
