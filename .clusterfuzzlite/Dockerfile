FROM gcr.io/oss-fuzz-base/base-builder
RUN apt-get update && apt-get install -y make autoconf automake libtool
COPY . $SRC/cluster_fuzzer
WORKDIR $SRC/cluster_fuzzer
COPY .clusterfuzzlite/build.sh $SRC/