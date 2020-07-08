#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
int main()
{
    DIR *dir;
    struct dirent *ent;
    const char l[]="0123456789";

    if ((dir = opendir("/proc")) == NULL)
        perror("operation error");
    else 
    {
        printf(" PID      \n");

        while ((ent = readdir(dir)) != NULL)

            if(strspn(ent->d_name, l)) 
            {
                printf(" %s\n", ent->d_name);
            }

        closedir(dir);
    }

    return 0;
}
