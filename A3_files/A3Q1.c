#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "/proc/self/exe";  // Points to the executable binary of the currently running program (which is this one.)
    struct stat st; // create an instance of the stat struct, which is a cornerstone of file system interaction in C++. It is defined in the `sys/stat.h` header and is used to obtain information about a file or a directory. This includes various metadata that can be crucial for applications that require file system manipulation or checking.

    // Get file status
    if (stat(filename, &st) == -1) { // filename is the file we want to check, which as defined earlier is this file. &st is the pointer to the stat struct defined earlier where the info will be stored. -1 indicates a failure.
        perror("stat"); // output what caused the error
        return 1;
    }

    // Print permissions
    printf("Permissions: %o\n", st.st_mode & 0777); // st.st_mode contains the file type and mode. the mask 0777 represents a file in which the user, group, and others would have read, write, and execute permissions. Whichever bits in st.st_mode survive the AND operation with this mask would represent the file's permission.

    // Print UID and GID
    printf("Owner UID: %d\n", getuid()); // Gets the user Id of the calling process, which is the owner, which is me.
    printf("Effective UID: %d\n", geteuid()); // Gets the effective user ID, which is the user ID of the person who can set the permissions for the file. So in this case, because I am the one who sets the permissions, the ID is still me.
    printf("Group GID: %d\n", getgid()); //Gets the group ID. Because the only user Is me, the Id is still just me.
    printf("Effective GID: %d\n", getegid()); // Gets the effective group Id, which is the ID of the group of users who can set the permissions. 

    int fd = open(filename, O_RDONLY); // opens the file (this one) in Others Read only mode
    if (fd == -1) {
        perror("open");
        return 1;
    }



    // Change file mode to remove execute for others
    mode_t new_mode = (st.st_mode & 0777) & ~(S_IXOTH); // NOTs the execute bit for the others
    if (fchmod(fd, new_mode) == -1) {
        perror("fchmod");
        close(fd);
        return 1;
    }

    printf("Changed permissions (via fchmod) to: %o\n", new_mode);

    close(fd); // closes the file
    return 0;
}
