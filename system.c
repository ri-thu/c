#include<stdio.h> 
#include<sys/stat.h> 
void main( int argc, char * argv []) 
{
    struct stat s;     
     stat(argv[1],&s); 
    if(S_ISDIR(s.st_mode))              
        printf("\nIt is a Directory.\n");       
    else if(S_ISREG(s.st_mode))  
        printf("\nIt is a Regular File.\n"); 
} 
