# The FX C Library

This directory contains the sources of the FxLibc Library.
See the `make version` command to see for what release version you have.

The Fx C Library is the standard system C library implementation for all Casio
Fx calculator, and is an important part of what makes up programs on these
devices. It provides the system API for all programs written in C and
C-compatible languages such as C++ and Objective-C; the runtime facilities of
other programming languages use the C library to access the underlying operating
system.

---

## Dependencies
Fx C library depends on a suitable GCC toolchain in the PATH. You can absolutely
not build `fxlibc` with your system compiler!

* The tutorial on Planète Casio builds an sh-elf that works everywhere.
* For fx-9860G II, `sh3eb-elf` is strongly advised.
* For fx-CG 50, `sh4eb-elf` (with `-m4-nofpu`) is slightly better but `sh3eb-elf`
is completely fine.

---

## Building and installating FxLibc
You can choose to build `fxlibc` standalone or with the support of the fx-9860G
II (monochrome calculators, aka Graph 85 family) Casio ABI, fx-CG 50 (color
calculators, aka Prizm or Graph 90 family), Vhex kernel ABI or all of them (this
will generate 3 distinct libraries).

Each ABI support add many functionalities provided by the operating system, like
I/O abstraction (open, close, fcntl, stat, ...). (see "supported features" on
the wiki)

#### Configuration and support
The Fx C library supports these ABI:
* `fx9860g` for the support of Casio ABI used by fx9860g-like devices.
* `fxcg50` for the support of Casio ABI used by the fxcg50 device.
* `vhex` for the support of Vhex kernel ABI.
* (nothing) compile only standing functions.

The Fx C library support these format:
* `static` generate static libraries.
* `dynamic` generate dynamic libraries (Only for the Vhex kernel).

Note that the shared feature  is not currently implemented because of
non-support of the shared library generation by the GCC compiler for SuperH
architecture. A workaround can be used  but it requires a static library to do
the dynamic symbols resolving (Thanks Kristaba).

For more information about library build configuration, you can use the
`./configure --help` command.

#### Building
Create a build directory and configure in it:
```
% mkdir build && cd build
% ../configure --static --support=vhex,fx9860g,fxcg50
```

Then build the source and install the library files to the selected directory.
You might need root access if you selected a target directory owned by root with
`--prefix`, or if you built your compiler as root.

```
% make
% make install
```

---

### Contributing
Bug reports, feature suggestions and especially code contributions are most
welcome.

If you are interested in doing a port, or want to contribute to this project,
please, try to respect these constraints:
* Document your code.
* One function per files.
* Each file name content only the name of the function.
* Respect the Linux Coding style as much as possible (if you are not familiar
	with this norm, you can use `indent -linux` utility to help to format).
* Header must respect the `/usr/include` architecture.
* Avoid modules hardware-specific code which can generate interruptions
	(DMA, SPU, ...) except if you are absolutely sure that the operating
	system can handle them.

---

### Using Fx C Library

To use Fx C library as your runtime environment, the bare minimum is:

* You must add `fxlibc/` instead of each include file (for example, if you want
	to include `stdio.h` you mush use `#include <fxlibc/stdio.h>`.
* Link with:
	* `-lfxlibc-fx9860g` for Casio ABI support for monochrome devices
	* `-lfxlibc-fxcg50` for Casio ABI support for primz devices
	* `-lfxlibc-vhex` for Vhex kernel support.
	* `-lfxlibc` for standalone features

---

### Licences
This work is licensed under a CC0 1.0 Universal License. To view a copy of this
license, visit: https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt
Or see the LICENSE file.

---

### Special thanks to
* Lephenixnoir - For all <3
* Kristaba - For the idea with the shared libraries workaround !
