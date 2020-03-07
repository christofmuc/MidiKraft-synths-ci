# Copyright (c) 2019 Christof Ruch. All rights reserved.
#
# Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase

FROM ubuntu:latest

# Install basic packages
RUN apt-get update && apt-get -y install unzip less wget g++ make

# Stuff required to use JUCE in the basic version 
RUN apt-get -y install libasound2-dev libcurl4-openssl-dev pkg-config

# Stuff used by the GUI client, not the server or command line program. This is huge.
#RUN apt-get -y install libgl1-mesa-dev 
#RUN apt-get -y install mesa-common-dev libgtk-3-dev

# Stuff required for MidiKraft (python3-distutils is required to prevent pybind11 CMake from freaking out)
RUN apt-get -y install python3.6 python3-distutils libboost-all-dev

# Download and install CMake in a recent version
RUN cd / && wget https://github.com/Kitware/CMake/releases/download/v3.16.5/cmake-3.16.5-Linux-x86_64.sh
RUN cd / && chmod +x /cmake-3.16.5-Linux-x86_64.sh && /cmake-3.16.5-Linux-x86_64.sh --skip-license && rm /cmake-3.16.5-Linux-x86_64.sh

# For some reason, we do not have a proper CURL with SSL on Ubuntu
RUN apt-get -y install libssl-dev
COPY curl-7.67.0.tar.gz /root
RUN cd /root && tar -xzf curl-7.67.0.tar.gz && cd curl-7.67.0 && ./configure --with-ssl && make -j4 && make install && ldconfig
RUN rm /root/curl-7.67.0.tar.gz

RUN echo "cd /src && cmake -S . -B builds/LinuxBuilds -G 'Unix Makefiles' && cd builds/LinuxBuilds && make -j4" > /root/run_make.sh
RUN chmod +x /root/run_make.sh

#ENTRYPOINT /root/run_make.sh

# Build the container via
#
# docker build .
# 
# and then run it with 
#
# docker run --volume=//d/development/jammernetz:/src -it -p 7777:7777/udp --entrypoint=/bin/bash --rm <containerID>
#
