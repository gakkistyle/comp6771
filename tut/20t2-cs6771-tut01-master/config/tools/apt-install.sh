#!/bin/bash
# Copyright (c) Christopher Di Bella.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
DISTRO=`lsb_release -a 2>&1 | egrep 'Distributor:\s+' | cut -d':' -f2 | tr -d '\t'`
CODENAME=`lsb_release -a 2>&1 | egrep 'Codename:\s+' | cut -d':' -f2 | tr -d '\t'`

# We need to know who runs non-root commands
if [[ $1 == "" ]]; then
   echo "$0: ./$0 username"
   echo "`username` should be \"`whoami`\" or \"root\""
   exit 1
fi

if [[ $(id -u) -ne 0 ]]; then
   echo "$0: must be run as root"
   exit 1
fi

if [[ $DISTRO == 'Ubuntu' ]]; then
   GCC10_REPO='ppa:ubuntu-toolchain-r/test'
else
   GCC10_REPO='deb http://deb.debian.org/debian testing main'
fi

install_cmake() {
   if [[ $1 == "root" ]]; then
      python3 -m pip install cmake
   else
      sudo -u $1 python3 -m pip install --user cmake
   fi
}

apt-get update                                                                                  && \
apt-get dist-upgrade -y                                                                         && \
apt-get install -y curl gnupg wget software-properties-common                                   && \
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -                            && \
add-apt-repository "deb http://apt.llvm.org/$CODENAME/ llvm-toolchain-$CODENAME main"           && \
if [[ $CODENAME != 'focal' ]]; then add-apt-repository "${GCC10_REPO}"; fi                      && \
apt-get update                                                                                  && \
apt-get install -y      \
    build-essential     \
    bzip2               \
    clang-format-11     \
    clang-tidy-11       \
    clang-tools-11      \
    clang-11            \
    clangd-11           \
    gcc-10              \
    g++-10              \
    gdb                 \
    git                 \
    gzip                \
    libc++-11-dev       \
    libc++abi-11-dev    \
    libclang-11-dev     \
    lld-11              \
    lldb-11             \
    llvm-11-dev         \
    llvm-11-runtime     \
    llvm                \
    ninja-build         \
    openssh-server      \
    python3             \
    python3-pip         \
    python3-clang-11    \
    sed                 \
    tar                 \
    unzip               \
    zip                 \
    zlib1g                                                && \
ln -s /usr/lib/llvm-11/include/c++/v1 /usr/include/c++/v1 && \
python3 -m pip install pip --upgrade                      && \
install_cmake $1
