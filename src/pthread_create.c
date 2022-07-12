#include<pthread_copy.h>

struct Param
{
	char* sfile;
	char* dfile;
	int blocksize;
	int pronum;
	int flog;
};

void*jobs(void * arg)
{		
		struct Param *tmp = (struct param*)arg;
		int pos;
		pos =tmp->flog*tmp->blocksize;
		char str_blocksize[50];
		char str_pos[50];
		bzero(str_blocksize,sizeof(str_blocksize));
		bzero(str_pos,sizeof(str_pos));
		sprintf(str_blocksize,"%d",tmp->blocksize);
		sprintf(str_pos,"%d",pos);
		printf("Copy_pos %d Copy_size %d\n",pos,tmp->blocksize);
		//通过重载方式使用COPY功能
		//./COPY sfile dfile blocksize pos
		execl("/home/zhouyh/0913/Process/process_copy/moudle/COPY","COPY",tmp->sfile,tmp->dfile,str_blocksize,str_pos,NULL);
		//重载后被覆盖
}


int pthread_create(const char* sfile,const char* dfile,int blocksize,int pronum)
{
	int flog = 0;
	struct Param param1;
	param1.sfile = sfile;
	param1.dfile = dfile;
	param1.blocksize = blocksize;
	param1.pronum = pronum;
	param1.flog=flog;
	pthread_t tid;
	int err;
	for(; flog<pronum;flog++)
	{
		if((err=pthread_create(&tid,NULL,jobs,&param1))>0)
		{	printf("pthread crate err:%s\n",strerror(err));
			exit(0);
		}
		sleep(5);
		pthread_join(tid,NULL);
		return 0;
	}
}

