#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/shm.h>
#include "ipcs.h"
#include "Map_data_task.h"
extern int errno;
extern char* sys_errlist[];
RegistProcess()
{
   key_t kShmKey;
   struct _shm* RegistData;



  return(EXE_OK);

     /******
        1999.10.27
        Instead of using PROCESSmgr,
        I will use Shell Program -> PROCESS_monitor
        So, Not use PROCESSmgr,
        and follow step is not necessary
      *******/


   printf("Process[%d] Registered\n",getpid());
   kShmKey = shmget(SHM_KEY,sizeof(struct _shm),PERMS | IPC_CREAT | IPC_EXCL);
   if(kShmKey < 0) {
      if(errno != EEXIST){
         printf("SHM Get Error [%d:%s]\n",errno,sys_errlist[errno]);
         return(errno);
      }
      kShmKey = shmget(SHM_KEY,0,0);

   }
   if((RegistData = (struct _shm*)shmat(kShmKey,(struct _shm*) 0, 0)) == (struct _shm*)-1) {
     printf("Shared Memory attach error [%d][%s]\n",errno,sys_errlist[errno]);
     return(errno);
   }
   RegistData->nMap_data_taskPid = getpid();
   shmdt(RegistData);
   return(EXE_OK);
}
