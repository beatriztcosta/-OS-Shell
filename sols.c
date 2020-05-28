#include "shell.h"

void sols(int argc, char **argv)
{
    DIR *dp;
    struct dirent *dirp;
    
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s Um argumento é necessário\n", argv[0]);
        return ;
    }
    
    if ((dp = opendir(argv[1])) == NULL){
        
        fprintf(stderr, "Can’t open %s\n",argv[1]);
        return;
    }
    while ((dirp = readdir(dp)) != NULL)
    {
        struct stat var;

            stat( dirp->d_name, &var);
             if ( (var.st_mode & S_IFREG) == S_IFREG ) 
                   printf("%s   %ld\n", dirp->d_name,(long)var.st_size);
             else 
                  printf("%s Not Reg file \n", dirp->d_name);
    }
    
    closedir(dp);
}
