#! /usr/bin/python3

import sys
import subprocess
import struct

patchData = {
    0x002C05A0 : b'\x0F', #invert first person gyro x-axis
    0x002D8D20 : b'\x0F', #invert targetted gyro x-axis
    0x002FC378 : b'\x0F', #culling effects and projectiles
    0x00419900 : b'\x0F', #main culling
    0x0041AB10 : b'\x0F', #invert circle pad x-axis
    0x0042DAF0 : b'\x0F', #mirror pause menu controls
    0x00479088 : b'\x0F', #mirror graphics
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
