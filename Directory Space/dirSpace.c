//About
//Simple program to calculate the size of a directory and all subdirectories using recursion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    long sum = 0;
    sum += dirSpace(".");
    printf("%ld\n", sum);
    return 0;
}

long dirSpace(char* targetDir)
{
/*
	long tempSum = 0;
	entries = getEntries(targetDir);
	for each entry in entries
		ignore "." + ".."
		if entry is file
			tempSum += size(entry)
		if entry is Dir
			tempsum += DirSpace(entry)
	end for
	return tempsum
    */

    long tempSum = 0;
    char** entries = getEntries(targetDir);
    for (int i = 0; entries[i]; i++) {
        if (strcmp(entries[i], ".") == 0 || strcmp(entries[i], "..") == 0) {
            continue;
        }
        // if entry is a file
        if (entries[i])

    }
    return tempSum;
}