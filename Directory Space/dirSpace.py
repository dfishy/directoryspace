# About
# Simple Python program to calculate the size of a directory and all subdirectories using recursion

import os

def dirSpace(dir):
    # variables
    tempSum = 0
    entries = os.listdir(dir)

    # for each entry
    for entry in entries:

        # get path for the entry
        entryPath = os.path.join(dir, entry)

        # if entry is file, add to size
        if os.path.isfile(entryPath):
            tempSum += os.path.getsize(entryPath)

        # if entry is directory, recurse
        elif os.path.isdir(entryPath):
            tempSum += dirSpace(entryPath)

    return tempSum


def main():
    topDir = os.getcwd()
    size = dirSpace(topDir)
    print(size)


if __name__ == "__main__":
    main()