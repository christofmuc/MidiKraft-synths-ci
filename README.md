# Introduction

[![Build status](https://ci.appveyor.com/api/projects/status/i6ducabh1oi3usk9?svg=true)](https://ci.appveyor.com/project/christofmuc/midikraft-synths-ci)

[![Build status](https://ci.appveyor.com/api/projects/status/i6ducabh1oi3usk9/branch/master?svg=true)](https://ci.appveyor.com/project/christofmuc/midikraft-synths-ci/branch/master)

This is the super-repository for the CI for all synth components of the MidiKraft software. The main use for this is to provide a build environment that can build the submodules linked here
in isolation, as I really avoid nested submodules in my repositories.

## Usage

This repository allows us to build the git submodules independantly in an easy way. First checkout recursively:

    git clone --recurse-submodules -j8 https://github.com/christofmuc/MidiKraft-synths-ci.git
	
Then use CMake to build the makefile for Windows (use other generators as you see fit):

    cmake -S . -B Builds\Windows -G "Visual Studio 15 2017 Win64" 
	
Building with cmake:

    cmake --build Builds\Windows --config=Release

## Licensing

As some substantial work has gone into the development of this and related software, I decided to offer a dual license - AGPL, see the LICENSE.md file for the details, for everybody interested in how this works and willing to spend some time her- or himself on this, and a commercial MIT license available from me on request. Thus I can help the OpenSource community without blocking possible commercial applications.

## Contributing

All pull requests and issues welcome, I will try to get back to you as soon as I can. Due to the dual licensing please be aware that I will need to request transfer of copyright on accepting a PR. 

## About the author

Christof is a lifelong software developer having worked in various industries, and can't stop his programming hobby anyway. 
