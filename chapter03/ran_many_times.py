#!/usr/bin/python3

import sys, os

print("len(sys.argv): ", len(sys.argv))
print("argv: ", str(sys.argv))
print()

if (len(sys.argv) == 1):
    os.system('ls -l')
else:
    i = 2
    s = ""
    while (i < (len(sys.argv))):
        s += sys.argv[i] + " "
        i += 1

    i = 0
    while (i < int(sys.argv[1])):
        os.system(s)
        i += 1
