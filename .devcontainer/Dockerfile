FROM ubuntu:23.04
LABEL maintainer="janhkrueger@gmail.com"

RUN TZ=UTC  && \
    export DEBIAN_FRONTEND=noninteractive


RUN apt-get update && \
    apt install -y tzdata gpg curl sudo && \
    apt-get update && apt-get -qq -y upgrade

RUN apt-get -qq -y upgrade

RUN apt-get -y --no-install-recommends -qq install clang clang-tools llvm llvm-runtime libclang-dev libclang-cpp-dev libclang-rt-dev make autoconf build-essential wget ca-certificates gnupg2 cmake make autoconf automake gdb curl libcurl4-openssl-dev libcurl4 software-properties-common libssl-dev gnu-standards git libspdlog-dev jq apt-file docker.io inetutils-ping apt-transport-https ssh dnsutils cron cron-daemon-common logrotate nano

RUN git clone https://gitlab.com/insulae_dev/external-components/rapidjson/ && \
    cd rapidjson/ && \
    mkdir build && \
    cd build/ && \
    cmake -DRAPIDJSON_BUILD_EXAMPLES=OFF -DRAPIDJSON_BUILD_DOC=OFF -DRAPIDJSON_BUILD_TESTS=OFF -DRAPIDJSON_BUILD_ASAN=ON -DRAPIDJSON_BUILD_UBSAN=ON .. && \
    make && \
    make install && \
    make clean && \
    cd .. && \
    cd .. && \
    git clone https://gitlab.com/insulae_dev/external-components/googletest.git && \
    cd googletest && \
    mkdir build && \
    cd build && \
    cmake .. -DBUILD_GMOCK=OFF && \
    make && \
    make install && \
    cd .. && \
    cd .. && \
    git clone https://github.com/jbeder/yaml-cpp.git && \
    cd yaml-cpp && \
    mkdir build && \
    cd build && \
    cmake -DYAML_BUILD_SHARED_LIBS=OFF .. && \
    make && \
    make install && \
    cd ..  && \
    rm -rf build

RUN apt-get clean autoclean && \
    apt-get autoremove -y && \
    rm -rf /var/lib/apt/lists/*
