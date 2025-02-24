#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() 
{
    int fd;
    char buffer[100];
    struct stat fileStat;
    struct dirent *de;
    DIR *dir;

    // Open a file
    fd = open("example.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) 
    {
        perror("Error opening file");
        return 1;
    }
    
    // Write to the file
    write(fd, "Hello, World!", 13);
    
    // Seek to the beginning
    lseek(fd, 0, SEEK_SET);
    
    // Read from the file
    read(fd, buffer, 13);
    buffer[13] = '\0';
    printf("File Content: %s\n", buffer);
    
    // Get file statistics
    if (stat("example.txt", &fileStat) == 0) 
    {
        printf("File Size: %ld bytes\n", fileStat.st_size);
    } 
    else 
    {
        perror("stat error");
    }
    
    // Close the file
    close(fd);
    
    // Open and read directory
    dir = opendir(".");
    if (dir == NULL) 
    {
        perror("Unable to open directory");
        return 1;
    }
    printf("Directory contents:\n");
    while ((de = readdir(dir)) != NULL) 
    {
        printf("%s\n", de->d_name);
    }
    closedir(dir);
    
    return 0;
}