#include "target.h"
#include <iostream>

void parse_data(const std::string input) {
    // We need at least 5 characters to proceed
    if (input.size() >= 5) {
        // A series of nested conditions that libFuzzer will easily solve
        if (input[0] == 'C') {
            if (input[1] == 'R') {
                if (input[2] == 'A') {
                    if (input[3] == 'S') {
                        if (input[4] == 'H') {
                            // The fuzzer figured out the magic string "CRASH"!
                            // Let's trigger a classic vulnerability: an out-of-bounds write.
                            int array[3] = {1, 2, 3};
                            array[5] = 99; // BOOM!
                        }
                    }
                }
            }
        }
    }
}