// fuzz_target.cpp
#include <cstdint>
#include <string>

// Include your headers here to test your logic.
// Note: You may need to extract the core logic from main.cpp into a separate
// .h/.cpp file so both main.cpp and this fuzzer can call it.

#include "target.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    // 1. Convert fuzzer data to a usable format (e.g., a string or struct)
    std::string input(reinterpret_cast<const char*>(Data), Size);


    // 2. Feed it into the function you want to test
    parse_data(input);



    // Return 0 indicates the fuzzer executed successfully.
    // If your code crashes or triggers a sanitizer, the fuzzer catches it.
    return 0;
}