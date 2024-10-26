# Leapify

> **WARNING!** This repository is a on-going developmental version of Leapify, there is no pre-builds or support, please check [this](https://github.com/Nyabsi/leapify) for stable releases.

**I REPEAT THIS IS NOT READY, I DO NOT GIVE PRE-BUILT BINARIES, OR HELP WITH BUILDING THE PROJECT, PLEASE CHECK OUT [THIS](https://github.com/Nyabsi/leapify) IF YOU WANT TO USE HAND TRACKING RIGHT NOW WITH YOUR LEAPMOTION CONTROLLER.**

**I REPEAT THIS IS NOT READY, I DO NOT GIVE PRE-BUILT BINARIES, OR HELP WITH BUILDING THE PROJECT, PLEASE CHECK OUT [THIS](https://github.com/Nyabsi/leapify) IF YOU WANT TO USE HAND TRACKING RIGHT NOW WITH YOUR LEAPMOTION CONTROLLER.**

**I REPEAT THIS IS NOT READY, I DO NOT GIVE PRE-BUILT BINARIES, OR HELP WITH BUILDING THE PROJECT, PLEASE CHECK OUT [THIS](https://github.com/Nyabsi/leapify) IF YOU WANT TO USE HAND TRACKING RIGHT NOW WITH YOUR LEAPMOTION CONTROLLER.**

Leapify is an SteamVR driver for Leapmotion Controller 1 & 2 (*And other compatible controllers*) which strives for hassle free experience.

# Features

- Cross-platform
    - Supports both Linux and Windows
- Hand Tracking Fallback
    - Driver automatically prioritizes controllers over hand tracking, and switches over when controllers disconnect or idle
- Hand offset estimation
    - Automatically sets position offset between sensor and your hands
- Skeletal / Position Passthrough
    - Allow Hand Tracking information to be used with other controller devices
- External Tracking 
    - Allows the use of External Tracking, IE. Vive Tracker 3.0 or Thundra Tracker, to replace Leap positioning
- Gesture Input System
    - Gesture input system built-in to the driver, which helps using finger tracking in non-supported titles

# Installation

### Prerequisites

- [Ultraleap Software](https://developer.leapmotion.com/tracking-software-download)
- Leapmotion controller supported by Ultraleap Hyperion or Gemini
- 2x Vive Tracker (**OPTIONAL**)

### Step 1

Install Ultraleap Software [here](https://developer.leapmotion.com/tracking-software-download) for your device.

>  use Gemini for Leapmotion Controller 1, Hyperion for Leapmotion Controller 2

*If you have issues activating Hyperion license, allow `LeapSvc.exe` in your firewall, if it still doesn't work. Contact Ultraleap directly.*

### Step 2

Download [the driver](https://github.com/Nyabsi/leapify/releases) and extract it to `C:\\Program Files (x86)\\Steam\\steamapps\\common\\SteamVR\\drivers\\` 

*NOTE: this path may vary depending on your Steam installation location and choice of operating system*

### Step 3

Start SteamVR and the driver should be registered.

# Building

This project is built with CMake and Visual Studio 2022 on Windows.

You can use instructions below for building on Linux.

```sh
git submodule init && git submodule update
cmake -B build .
cmake --build build
```

# Dependencies

- [OpenVR](https://github.com/ValveSoftware/openvr) by @ValveSoftware
- [rcmp](https://github.com/Smertig/rcmp) by @Smertig

# License

The code is licensed under `MIT` you can view the full license [here](LICENSE)
