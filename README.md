# Z3d Hacking / general notes
This is intended as an archive of my various z3d romhacks and notes. Hopefully someone will be willing take what this and continue on. Each project's folder has its own README.md that explains it a bit more of the specifics of each project.

Basically consider all of these projects abandoned for the time being. I might update this repo if I find notes / various related stuff, but I have no plans to improve these or expand on them in any way. If someone feels in incline to try to, I would accept pull request.

## Background
All of these romhacks run in process with the respective games using luma's loader reimplementation to hotpatch the game. As such they rather constrained with how big the projects can be. Mm3d is a bit less constrained as the main executable can be extended to get extra memory pages, while oot3d has an *intresting quirk* that with luma's loader reimplementation adding any additional memory pages to the main executable causes some type of cache issue I have yet to figure out, and will cause performance issues in the form of crackling audio (potentially others subtle difference).

Each of these patches are compiled to use the leftover *padding* (for lack of a better word) bytes from the end of a given section to the end the memory page it resides in. As space was limited these are all compiled with -no-std-lib to save on space and as C library functions were needed they were either reimplemented or *borrowed* from the statically linked C/C++ runtime from each game



## Folders

### Frame Advance: fa/
Simple frame advance.

### Input Macros Playback: macro/
Simple input macro playback that plays back prechosen inputs on a loop.


### BetaQuest 3D: bq3d/
Entrance randomizer for oot3d

### MQ Unmirroed: mqum/
Unmirror Master Quest in oot3d.

### Notes: notes/
General notes on the z3d games

## How to build
To build the patches install:
- [devkitPro + libctru](https://devkitpro.org/wiki/Getting_Started) and properly include them in your path. Techncially any ARMv6 compiler compadible with gcc's CLI should be able to work, but the makefiles still require devkitPro enviroment variables that probably could be removed.
- [Python 3](https://www.python.org/downloads/) to convert the compiled binary into the ips patch.

Once devkitPro and Python 3 is installed and included in path, simply run the makefile in each project. For the patches this will generate a **code.ips** file that can be applied using [luma's loader reimplementation](https://github.com/AuroraWright/Luma3DS/wiki/Optional-features#IPS%20patching) (ctrl+f "IPS patching").

The ips patch can be applied to a rom itself. Just unpack the rom and apply the ips to code.bin. Note that the offsets are relative to the start of **code.bin** not the virtual address it is loaded to.

## Potential TODOs
Something that I was planning on doing was to either write a custom **fs:USER** implementation (or if possible reuse the one in the game) to potentially load larger patches and remove the *padding* limitation mentioned above. This would probably have to use heap memeory due to the performance issue with oot3d mentioned above

Another option would have been to write a custom daemon that could use load the custom code into its own address space and then generate a patch with a small chainloader using the ```svcMapProcessMemoryEx``` syscall luma added to chainload the customs code and the needed hooks to the custom code.

I currently have no plans on doing either of those things I suggested, but if someone feels like they would take up the mantel those would be 2 places to start.


## License

 Some of the files in this repo are modified versions of files from [devkitPro](https://devkitpro.org/wiki/Getting_Started) and [libctru](https://github.com/smealum/ctrulib). Namely the Makefiles and some implementations of the syscalls wrapper functions. To comply with their licensing here is the copy of their license / how I'm licensing this repo.

------------------------------------------------------------------------

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any
  damages arising from the use of this software.

  Permission is granted to anyone to use this software for any
  purpose, including commercial applications, and to alter it and
  redistribute it freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you
     must not claim that you wrote the original software. If you use
     this software in a product, an acknowledgment in the product
     documentation would be appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and
     must not be misrepresented as being the original software.
  3. This notice may not be removed or altered from any source
     distribution.