#!/bin/bash -eu

export DOCKER_DEFAULT_PLATFORM=linux/amd64

# 1. Compile your target code into an object file.
# We use $CXX and $CXXFLAGS so ClusterFuzzLite can inject its instrumentation.
# (Added -Isrc just in case your headers are relative to the src directory)
$CXX $CXXFLAGS -I. -Isrc -c target.cpp -o target.o

# 2. Compile the fuzz target and link it with the fuzzing engine and your object file.
# The output binary MUST be placed in the $OUT directory.
$CXX $CXXFLAGS -I. -Isrc $LIB_FUZZING_ENGINE \
    fuzz_target.cpp \
    target.o \
    -o $OUT/fuzz_target

# (Optional) If you have a seed corpus (a zip file of initial good inputs),
# copy it to $OUT so the fuzzer can use it as a starting point.
# cp fuzz/my_fuzzer_seed_corpus.zip $OUT/