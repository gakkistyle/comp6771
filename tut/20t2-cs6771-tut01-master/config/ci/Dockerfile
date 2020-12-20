# Copyright (c) Christopher Di Bella.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
FROM ubuntu:latest

# Install LLVM system prerequistes
RUN apt-get update
RUN apt-get dist-upgrade -y
RUN apt-get install -y gnupg wget software-properties-common
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN add-apt-repository 'deb http://apt.llvm.org/focal/ llvm-toolchain-focal main'
RUN apt-get update

RUN apt-get install -y \
   build-essential    \
   bzip2              \
   clang-format-11    \
   clang-tidy-11      \
   clang-tools-11     \
   clang-11           \
   clangd-11          \
   cmake              \
   curl               \
   gdb                \
   git                \
   gzip               \
   libc++-11-dev      \
   libc++abi-11-dev   \
   libclang-11-dev    \
   lld-11             \
   lldb-11            \
   llvm-11-dev        \
   llvm-11-runtime    \
   llvm               \
   ninja-build        \
   openssh-server     \
   python3            \
   python3-clang-11   \
   sed                \
   tar                \
   unzip              \
   zip                \
   zlib1g
RUN ln -s /usr/lib/llvm-11/include/c++/v1 /usr/include/c++/v1

WORKDIR /
RUN apt-get remove -y software-properties-common
RUN apt-get dist-upgrade -y
RUN apt-get autoremove -y
