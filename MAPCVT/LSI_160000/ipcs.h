struct _shm {
   pid_t  nPROCESSmgrPid;
   pid_t  nMap_data_taskPid;
   pid_t  nMapcvt_InsertPid;
   pid_t  nDualServerPid;
   pid_t  nEC_COMMmgrPid;
};
#define PERMS 0666
#define SHM_KEY 0x90000000
