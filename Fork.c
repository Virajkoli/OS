#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include<time.h>
#include <fcntl.h>
#include <dirent.h>

int main() {
    
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } 
    
    else if (pid == 0) { 
        printf("Child process ID = %d\n",pid);
        printf("Child process created with PID: %d\n", getpid());
       
       char *args[] = {"/bin/ls", "-l", NULL};
        execv(args[0], args);

        perror("Exec failed");
        exit(EXIT_FAILURE);
    } 
    
    else { 
        
        int status;
        wait(&status);
        printf("Parent process executed !\n");
        printf("Child process with PID %d exited with status %d\n", pid, status);
        
    

    
    printf("Current process ID: %d\n", getpid());

    
    //exit(EXIT_SUCCESS);

    
    int fd = open("example.txt", O_RDONLY);
    
    if (fd == -1) {
        perror("Open failed");
        exit(EXIT_FAILURE);
    }
    
    if (close(fd) == -1) {
        perror("Close failed");
        exit(EXIT_FAILURE);
    }

    
    struct stat file_stat;
    
    if (stat("example.txt", &file_stat) == -1) {
        perror("Stat failed");
        exit(EXIT_FAILURE);
    }
    printf("File size: %ld bytes\n", file_stat.st_size);

   
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if (dir == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }
    
    printf("Contents of the current directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    
    closedir(dir);
    }

    return 0;
}
