#! /usr/bin/python3

import sys
import subprocess
import struct

patchData = {
	0x002eafcc : b'\x01', #dungeon select: `cmp r0, #0` immediate changed to `#1`
	0x00352dd0 : b'\x01', #double damage:  `cmp r0, #0` immediate changed to `#1`
}


off = lambda vaddr: struct.pack(">I",vaddr - 0x100000)[1:]
sz = lambda size: struct.pack(">H", size)

ips = b'PATCH'
for vaddr, patch in patchData.items():
	size = len(patch)
	
	ips += off(vaddr)
	ips += sz(size)
	ips += patch
ips += b'EOF'

with open("code.ips", 'wb') as patchFile:
    patchFile.write(ips)
#print(ips)