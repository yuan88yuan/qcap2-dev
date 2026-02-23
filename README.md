# QCAP Library

This repository contains the QCAP library, a comprehensive suite of functions for various multimedia and communication tasks, including video capture, recording, broadcasting, and specialized functionalities like DICOM, HL7, WebRTC, and more.

## Modularized Version

The `qcap.h` header file was initially monolithic, making it challenging to navigate and maintain. This version introduces a modular structure, breaking down the extensive `qcap.h` into smaller, logically grouped header files. This enhances readability, maintainability, and allows developers to include only the functionalities they need.

The `qcap2.h` header has also been modularized into smaller headers (for types, utilities, buffers, formats, synchronization, processing, devices, and graphics). You can include `qcap2.h` to pull everything in, or include the specific `qcap2.*.h` modules you need.

### New Header Structure

The `include/` directory now contains the following modular header files:

*   `qcap.types.h`: Contains core type definitions and common enumerations like `QRESULT`, `QRETURN`, input types, color spaces, encoder formats, etc.
*   `qcap.callbacks.h`: Defines all callback function prototypes used throughout the library for asynchronous event handling and data processing.
*   `qcap.system.h`: Includes system-level functions for version querying, system configuration, and debug settings.
*   `qcap.device.h`: Manages device enumeration, creation, destruction, starting/stopping devices, and basic video/audio input/output configurations. It also includes NVIDIA GPUDirect, lock/unlock, and snapshot functions.
*   `qcap.recording.h`: Provides functions for single and multi-channel recording, including share recording, 3D video recording, audio mixing, and synchronized recording/playback.
*   `qcap.osd.h`: Handles On-Screen Display (OSD) functionalities, allowing text and picture overlays on video streams.
*   `qcap.broadcast.h`: Contains APIs for broadcasting media streams, including server and client functionalities for various protocols like RTSP, RTMP, HLS, TS, MMS, and NDI.
*   `qcap.onvif.h`: Implements ONVIF communication functionalities for server, emulator, and client roles, supporting various ONVIF services.
*   `qcap.dicom.h`: Offers DICOM workstation features, including querying PACS servers, downloading/uploading studies, and DICOM file access utilities.
*   `qcap.hl7.h`: Provides HL7 communication functions for patient data management, clinical orders, and report uploading.
*   `qcap.webrtc.h`: Enables WebRTC functionalities for chat rooms and peer-to-peer communication, including SDP property management and data/file transfer.
*   `qcap.sip.h`: Implements SIP functionalities for chat and media streaming.
*   `qcap.playback.h`: Contains functions for file playback, editing (exporting, merging), repair, and transcoding.
*   `qcap.animation.h`: Provides APIs for creating and controlling animation clips, including sprite transformations and effects.
*   `qcap.virtualcamera.h`: Offers functionalities for managing virtual cameras, including property settings and buffer manipulation.
*   `qcap.serial.h`: Manages serial port (RS232/RS485) communication, including data sending/receiving and signal control.
*   `qcap.burning.h`: Provides functions for disc burning, including drive management and disc information.
*   `qcap.timer.h`: Implements high-precision media timer functionalities.
*   `qcap.helper.h`: Contains various utility and helper functions for encoder, video, audio, and system operations.

## Usage

To use the QCAP library, simply include the main `qcap.h` header file:

```c
#include "qcap.h"
```

This will transitively include all the modular headers, providing access to the entire API.

If you only need specific functionalities and want to minimize compile times, you can include individual modular headers directly. However, be aware of dependencies; a module might require types or functions defined in earlier modules in the dependency chain. It's generally recommended to include `qcap.h` unless you have a strong reason not to.

## Building

(Assuming a standard C/C++ build process)

To build projects using the QCAP library, ensure that your compiler can find the `include/` directory. Link against the QCAP library (`.lib` or `.so` file) as appropriate for your platform.

Example for GCC/Clang:

```bash
g++ your_program.cpp -I/path/to/qcap/include -L/path/to/qcap/lib -lqcap -o your_program
```

## Contributing

Contributions to the QCAP library are welcome. Please adhere to the existing coding style and submit pull requests for any enhancements or bug fixes.

## License

(Please add your license information here)
