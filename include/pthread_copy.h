#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>


int pram_check(int argc,const char* sfile,int pronum);

int file_block(const char*sfile ,int pronum);

int pthread_create(const char* sfile,const char*dfile,int blocksize,int pronum);

int copy(const char*,const char*,char*,char*);
