FROM ubuntu:23.04
LABEL maintainer="janhkrueger@outlook.com"

RUN TZ=UTC  && \
    export DEBIAN_FRONTEND=noninteractive


RUN apt-get update && \
    apt install -y tzdata gpg curl sudo && \
    apt-get update && apt-get -qq -y upgrade

RUN apt-get -qq -y upgrade

RUN apt-get -y --no-install-recommends -qq install clang clang-tools llvm llvm-runtime libclang-dev libclang-cpp-dev libclang-rt-dev make autoconf build-essential wget ca-certificates gnupg2 cmake make autoconf automake gdb curl libcurl4-openssl-dev libcurl4 software-properties-common libssl-dev gnu-standards git libspdlog-dev jq apt-file docker.io apt-transport-https ssh

RUN apt-get clean autoclean && \
    apt-get autoremove -y && \
    rm -rf /var/lib/apt/lists/*
