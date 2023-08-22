#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int readFileList(char *basePath, int level);

int main(void)
{
    char basePath[1000];

    //get the current absoulte path
    memset(basePath,'\0',sizeof(basePath));
    getcwd(basePath, 999);
    
    printf("The current dir is : %s\n",basePath);

    // get the file list
    //memset(basePath,'\0',sizeof(basePath));
    //strcpy(basePath,"./XL");
    readFileList(basePath, 1);
    
    printf( "output: done.\n" );
    return 0;
}

int readFileList(char *basePath, int level)
{
    DIR *dir;
    struct dirent *ptr;
    char base[1000];
    int i = 0;

    if ((dir=opendir(basePath)) == NULL)
    {   perror("Open dir error...");
        exit(1);
    }

    while ((ptr=readdir(dir)) != NULL)
    {
        //current dir OR parrent dir
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..") ==0 )    
        {   continue;            
        }
        
        for(i = 0; i < level; ++i )
        {   printf("    ");
        }
        
        if(ptr->d_type == 8)    //file
        {   printf("->File: %s/%s\n",basePath,ptr->d_name); 
            continue;
        }
        
        if(ptr->d_type == 10)    //link file
        {   printf("->Link:%s/%s\n",basePath,ptr->d_name);
            continue;
        }
        
        if(ptr->d_type == 4 )    //dir
        {
            memset(base,'\0',sizeof(base));
            strcpy(base, basePath);
            strcat(base,"/");
            strcat(base,ptr->d_name);            
            readFileList(base, level+1);
        }
    }

    closedir(dir);
    return 1;
}