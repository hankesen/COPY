#include<pthread_copy.h>

int pram_check(int argc,const char* sfile,int pronum)
{	
	if(argc < 3){
		printf("argc error!\n");
		exit(0);	
	}
	if((access(sfile,F_OK))!=0){
		printf("sfile open failed\n");
		exit(0);
	}
	if(pronum <= 0|| pronum >100){
		printf("error: Pronum number error\n");
		exit(0);
	}
	return 0;
}
