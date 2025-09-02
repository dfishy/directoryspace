//About
//Simple program to calculate the size of a directory and all subdirectories using recursion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // for is directory/file and size
#include <dirent.h> // for directory entry names

// for filepath string
#define MAX_LEN 1024

long dirSpace(char* topDir)
{
    // variables
    long tempSum = 0;    
    struct dirent *entry;
    DIR* dirStream;
    struct stat fileStats;

    // open target directory
    if((dirStream = opendir(topDir)) == NULL){
        perror("opendir");
        return -1;
    }

    // for each directory entry
    while(entry = readdir(dirStream))
    {

        // ignore "." + ".." (current and parent directories)
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // get path for the entry
        char pathName[MAX_LEN];
        snprintf(pathName, sizeof(pathName), "%s/%s", topDir, entry->d_name);

        // get file stats
        if (stat(pathName, &fileStats) == -1) {
            perror("stat");
            continue;
        }

        // if entry is a file, add to size
        if (S_ISREG(fileStats.st_mode)) {
            tempSum += fileStats.st_size;
        }
        // if entry is a directory, recurse
        if (S_ISDIR(fileStats.st_mode)) {
            tempSum += dirSpace(pathName);  
        }
    }

    closedir(dirStream);

    return tempSum;

}

int main() {

    long sum = 0;
    sum += dirSpace(".");
    printf("%ld\n", sum);
    return 0;

}