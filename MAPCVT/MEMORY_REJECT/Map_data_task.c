/*
  []--------------------------------------------------------------------[]
  []  Program Name : Map_data_task                                      []
  []  Argument : NONE                                                   []
  []  Procedure define                                                  []
  []     1. Map data file check                                         []
  []     2. Map data converting                                         []
  []     3. Map data Insert                                             []
  []  Programmed by Kim chang kook @ System Engineering Team(TEL:7275)  []
  []  History                                                           []
  []      1. Started at 29/Sep/98                                       []
  []  Return Value : None                                               []
  []--------------------------------------------------------------------[]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <syslog.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "Map_data_task.h"
#include "ipcs.h"

#define TRUE  1
#define FALSE 0
#define DELIMITER1 "= \n"
#define DELIMITER2 "(, )\n"
#define DELIMITER3 "."
#define FILE_PERM 0755  /* Map file permission change flag: -rwxr-xr-x , /99/01/05 */


void 	Map_data_task();
int  	Map_file_check();
int 	Error_Log();
void 	Get_Date();
int 	SendToCvtInsert(); 
int  	timeout();
     /*** First log insert function
extern int DBLog_First();
          Do not use from 98/01/08 ***/

extern int errno;
extern char* sys_errlist[];
extern int RegistProcess();

int Msg_Qid;
int alarm_flag = FALSE;

int main()
{
/*  setpgrp(getpid(), 1); */
setpgrp();

  switch(fork()) {
	case -1:	/* Unable to fork, for some reason. */
		printf("Map_data_task is unable to fork daemon \n");
		exit(1);
	case  0: 
			/* 
			 * Set SIGCLD to SIG_IGN, in order to prevent
			 * the accumulation of zombies as each child
			 * terminates. This means the daemon does not
			 * have to make wait calls to clean them up.
			 */
		signal(SIGCLD, SIG_IGN);

                /* modified by msyun 98/11/24 */
                /* Inserting process_id registration routine for
                   managing inkless processes */
                if(RegistProcess() != EXE_OK) {
                     printf("Critical Error[%s] : ProcessRegist Error[%s] ....program exit!\n",sys_errlist[errno]);
                     exit(errno);
                }

		printf("\nMap_data_task Process start!! \n");
		Map_data_task();
		exit(0);
		break;
	default :		/* Parent process comes here */ 
		exit(0);
  }
}

char Wafer_Files[30][100];


void Map_data_task()
{
  DIR *pDir;
  struct dirent * pDirent;
  char stReqFile[100];
  char stBuff[256];
  int  nTemp;
  int  nCvt_result;
  int  nInsert_result;
  int  nInsertErrCnt;
  int  nFileCnt;
  int  nSdmsg;
 			/* Create Message Queue */ 
        if((Msg_Qid = msgget(ftok(Qkey_F, Qkey), IPC_CREAT|QPERM)) == -1) {
                printf("\nMessage Queue Creation fail!!\n");
                exit(0);
        }
			/* Open directory of Wafer_Map_files */
  	if((pDir = opendir(MAP_DATA_DIRECTORY)) == NULL) {
		printf("Directory [%s] open error [%d]\n", MAP_DATA_DIRECTORY, errno);
		exit(-1);
  	} /* end of if */	

#ifdef _DEBUG_MODE
	printf("Directory : %s\n", MAP_DATA_DIRECTORY);
#endif

  	while(1) {
		if( (pDirent = readdir(pDir)) == NULL) {
			closedir(pDir);

#ifdef _DEBUG_MODE
			printf("Directory Close and open again after 2 second!\n"); 
			printf("Directory : %s\n", MAP_DATA_DIRECTORY);
#endif

			sleep(2);
  			if( (pDir = opendir(MAP_DATA_DIRECTORY)) == NULL) {
				printf("Directory [%s] open error [%d]\n", MAP_DATA_DIRECTORY, errno);
				exit(-1);
			}
	        	pDirent = readdir(pDir);
		} /* end of if( (pDirent = readdir(pDir))....*/

        	/* modified by msyun 98/11/20 for porting DEC machine */
        	memset(stBuff,'\0',256);
        	memcpy(stBuff,MAP_DATA_DIRECTORY,strlen(MAP_DATA_DIRECTORY));
		strncat(stBuff,pDirent->d_name,strlen(pDirent->d_name));
        	/* end of modification */
		if( !memcmp(pDirent->d_name, ".", 1) )   continue;     /* skip directory */

		/* modified by msyun 98/11/20 for porting on DEC machine 
		if( opendir(pDirent->d_name) != NULL ) { */
			if( opendir(stBuff) != NULL ) {
#ifdef _DEBUG_MODE
				printf("Skip!, This is not a file: %s !!\n", pDirent->d_name);
#endif
	       			continue;         /* skip, this is Not a file */
			}
			if( (memcmp(strstr(pDirent->d_name, "."), ".REX", 4)) != 0 ) { 
				continue;
			} else {
				memset(stReqFile, '\0', 100);
				memcpy( stReqFile, pDirent->d_name, strlen(pDirent->d_name) );
#ifdef _DEBUG_MODE
				printf("============== START NEW RUN ======================\n");
				printf("Check Req file of %s !!\n", stReqFile);
#endif
				nFileCnt = Map_file_check(stReqFile, Wafer_Files);
#ifdef _DEBUG_MODE
				printf("Run[%s] - Wafer Map file Total : %d\n", stReqFile, nFileCnt); 
				for(nTemp=0; nTemp<=nFileCnt; nTemp++)
					printf("Wafer Map file[%d] = [%s] \n", nTemp, Wafer_Files[nTemp] ); 
#endif
				if (nFileCnt > 0)  {
	  	    			nSdmsg=SendToCvtInsert(Wafer_Files, nFileCnt);  /* Send data of Run to covert_insert()*/
		    			if(nSdmsg < 0) {
		    				Error_Log(MsgQErr, Wafer_Files[0], errno);    /* if message send Error */
#ifdef _DEBUG_MODE
						printf("Message Queue Send Error : Run[%s] \n", stReqFile); 
#endif
						exit(-1);
				}
	        	} /* if (nFilecnt > 0) ..*/ 
		}  /* end of if( !memcmp(strstr(..... */
  	} /* end of while(1)  */	
}  /* end of Map_data_task() */ 

			
	

int Error_Log(LogType, ErrMsg, Err_No)
	int LogType;
        char *ErrMsg;
	int Err_No;
{
        time_t logtime;
        FILE *fp;
        char log_date[20];
        char filename[256];
        memset (filename, '\0', 256);

        Get_Date(log_date);
	if( LogType == MsgQErr) { 
        	sprintf(filename, "/mapap/inkless/LOG/LOG/SERVER/ErrMsgQ.%s", log_date);
	} else {
       		sprintf(filename, "/mapap/inkless/LOG/LOG/SERVER/WF_Check.%s", log_date);
	       }
        if( (fp=fopen(filename, "a+")) == NULL) {
             usleep(100000);
             if( (fp=fopen(filename, "a+")) == NULL) {
                printf("Error File Open Error\n");
		return(-1);
		}
        }

        time(&logtime);
        switch(LogType) {
                case CountErr :
                        fprintf(fp,"#%d File Count Error[%d-%s]: [%s] at %s\n", LogType, Err_No, sys_errlist[Err_No], ErrMsg, ctime(&logtime));
                        break;

                case OpenErr :
                        if (Err_No == -1) {   /** modified by stainles 99/01/05 **/
                                fprintf(fp,"#%d LOG DATA FIRST INSERT FAIL [%s] at %s\n", LogType, ErrMsg, ctime(&logtime));
                        } else if (Err_No == -2) {
                                fprintf(fp,"#%d INKLESS FLAG NOT EXIST [%s] at %s\n", LogType, ErrMsg, ctime(&logtime));
                          } else if (Err_No == -3) {
                                fprintf(fp,"#%d REQ FILE [EOF] NOT EXIST [%s] at %s\n", LogType, ErrMsg, ctime(&logtime));
                            } else {
                                fprintf(fp,"#%d File Open Error[%d-%s]: [%s] at %s\n", LogType, Err_No, sys_errlist[Err_No], ErrMsg, ctime(&logtime));
                              }
                        break;

                case EowErr :
                        fprintf(fp,"#%d Not exist EOW[%d]: [%s] at %s\n", LogType, Err_No, ErrMsg, ctime(&logtime));
                        break;

                case MsgQErr :
                        fprintf(fp,"#%d MsgQ Send Error[%d-%s]: [%s] at %s\n", LogType, Err_No, sys_errlist[Err_No], ErrMsg, ctime(&logtime));
                        break;

                default : break;
        }
        fclose(fp);
	return(0);
}

		/*  Get date of today for Log file*/
void Get_Date(log_time)
        char *log_time;
{
        time_t tTime;
        struct tm *p_tm;
        char buffer[50];

        time(&tTime);
        p_tm = localtime(&tTime);
        sprintf(buffer, "%04d%02d%02d", p_tm->tm_year+1900, p_tm->tm_mon+1, p_tm->tm_mday);
        sprintf(log_time, "%s", buffer);
}



/**********************************************
 *  Send Run Id to Map Convert process
 *********************************************/

int SendToCvtInsert(Wafer_List, nFileCnt) 
	char Wafer_List[30][100];
	int  nFileCnt;  
{
        RunFilesMsgQ   WaferList_MsgQ;
        int Sdmsg;
        int nLoop;

        signal(SIGALRM, timeout);

        memset(&WaferList_MsgQ, '\0', sizeof(WaferList_MsgQ));
	WaferList_MsgQ.msgData.Wafer_Count = nFileCnt;
        for(nLoop=0;  nLoop<= nFileCnt; nLoop++) 
        	strcpy(WaferList_MsgQ.msgData.Wafer_List[nLoop], Wafer_List[nLoop]);
#ifdef _DEBUG_MODE
	printf("Befor Seinding Message Queue!!\n");
	printf("%s WAFER FILE TOTAL=[%d]\n", WaferList_MsgQ.msgData.Wafer_List[0], WaferList_MsgQ.msgData.Wafer_Count);
	for(nLoop=0; nLoop <= nFileCnt; nLoop++) 
		printf("MSG Queue Map File[%d]=[%s]\n", nLoop, WaferList_MsgQ.msgData.Wafer_List[nLoop]);
#endif

        WaferList_MsgQ.mtype = MsgType;
        alarm(3);
        Sdmsg = msgsnd(Msg_Qid, &WaferList_MsgQ, sizeof(Map_infor), 0);
        alarm(0);

        if(alarm_flag == TRUE || Sdmsg < 0 ){
	        printf("\n Message Queue Send Error !! \n");
       		/*  msgctl(Msg_Qid, IPC_RMID, 0); */
        	return (-1);
        }

        return (1);
}

	/* For alarm flag */ 
int timeout()
{
        alarm_flag = TRUE;
        return 0;
 }


/*************************************************
 *      Check Wafer file state 
 *************************************************/


int Map_file_check(stReqFile, stFile_List)
	char *stReqFile;
	/* char *stFile_List[30][100]; */
	char stFile_List[30][100];
{
	FILE *fpREQ;
	FILE *fpWafer;
	FILE *fpRPY;
	char stRunId[20];
	char stErr_Files[30][100];
	char stFileCnt[5];
	char stTempfile[256];
	char stRenfile[256];
	char stErrfile[256];
	char stBuff[512];
	char *stTok;
	char stRpyFile[100];
	char stCmd[256];
	int  nFileCnt;
	int  nErrOpenCnt;
	int  nNoExistCnt;
	int  nErrEowCnt;	
	int  nErrTotal;
	int  nEowCnt;
	int  nLoop;
	int  nTemp;
	int  nInkless_Flag;
	int  nREQ_Check;
	struct stat statbuf;   /* For Map file Permission check  /98/01/05 */

        for(nLoop=0; nLoop < 30 ; nLoop++) {
	   memset(stFile_List[nLoop], '\0', sizeof(stFile_List[nLoop]));
	   memset(stErr_Files[nLoop], '\0', sizeof(stErr_Files[nLoop]));
        }
        
        memset(stTempfile, '\0', sizeof(stTempfile));
	memcpy(stTempfile, stReqFile, strlen(stReqFile));
        stTok = strtok(stTempfile, DELIMITER3);
        memset(stRunId, '\0', sizeof(stRunId));
	memcpy(stRunId, stTok, strlen(stTok));

	memset(stFile_List[0], '\0', 100);
	memcpy(stFile_List[0], stReqFile, strlen(stReqFile));
	memset(stErr_Files[0], '\0', 100);
	memcpy(stErr_Files[0], stReqFile, strlen(stReqFile));
	memset(stTempfile, '\0', 256);
	sprintf(stTempfile, "%s%s", MAP_DATA_DIRECTORY, stReqFile);

#ifdef _DEBUG_MODE
		printf("target file = [%s] \n", stReqFile);
		/* printf("RunId = [%s]\n", stRunId); */
		printf("stTempfile = [%s] \n", stTempfile);
		printf("stFile_List[0] = [%s] !!\n", stFile_List[0]);
		printf("stErr_Files[0] = %s !!\n", stErr_Files[0]);
#endif

                /**** REQ file Mode change : FILE_PERM(-rw-r--r--)  /98/01/05 ****/
#ifdef _DEBUG_MODE
        if ( stat(stTempfile, &statbuf) < 0 )   /* get current file mode */
                fprintf(stderr, "REX File[%s]: couldn't get current stat \n", stTempfile);
#endif
        if( S_ISREG(statbuf.st_mode) ) {  /** if Directory, Skip **/
            statbuf.st_mode = (statbuf.st_mode|FILE_PERM);
            if (chmod(stTempfile, statbuf.st_mode) < 0 )
                  fprintf(stderr, "REX File[%s]: couldn't change mode to  -rw-r--r-- \n", stTempfile);
        } /* end of if( S_ISREG(... */  
                /**** end of REQ file Mode change ..... ****/

	if( (fpREQ=fopen(stTempfile, "r")) == NULL ) {
		usleep(300000);
		if( (fpREQ=fopen(stTempfile, "r")) == NULL ) {
			printf("Can't open : %s \n", stTempfile);
			memset(stReqFile, '\0', 100);
			strcpy(stReqFile, stTempfile);
			Error_Log(OpenErr, stTempfile, errno);
				/* goto RPY transfer statement */
			nNoExistCnt = 1;
			nErrOpenCnt = 1;
			nErrEowCnt = 1;
			nErrTotal = 2;
            memset(stErr_Files[1], '\0', 100);
			strcpy(stErr_Files[1], "REQ file open error"); 
			goto REQopen_Error;
		}	
	}  /* end of if ((fpREQ=fopen .....*/
#ifdef _DEBUG_MODE
		printf("[%s] Open Success!! \n", stTempfile);
#endif

                /******* modified by stainles 98/12/03/ *********/
        fseek( fpREQ, 0, SEEK_SET);
        nREQ_Check = FALSE;
        while (!feof(fpREQ)) {  /** REQ File Format  Check.. **/
               memset(stBuff, '\0', sizeof(stBuff));
               fgets(stBuff, sizeof(stBuff), fpREQ);
               if( strstr(stBuff,"[EOF]") != (char *)NULL ) nREQ_Check = TRUE;
        } /* end of while... */
        if ( nREQ_Check == FALSE ) {  /* If REQ file is not perfect format, */
               fclose(fpREQ);    /* this process exit */
               errno =  -3;
               Error_Log(OpenErr, stTempfile, errno);
	       return(-1);
        } /* end of if( nREQ_Check == FALSE).. */

	nInkless_Flag = 0;
        nFileCnt = 0;
        fseek( fpREQ, 0, SEEK_SET);
        while (!feof(fpREQ)) {
                memset(stBuff, '\0', sizeof(stBuff));
                fgets(stBuff, sizeof(stBuff), fpREQ);
                if( feof(fpREQ)) break;
                stTok = strtok(stBuff, DELIMITER1);
		if(!stTok) continue;;

                if(!memcmp(stTok, "LOTID", 5) ) {       /* this line : LOTID=8SH062A */
                        stTok = strtok(NULL, DELIMITER1);
                        memset(stRunId, '\0', 20);
                        memcpy(stRunId, stTok, strlen(stTok));

			/* 2011-04-08 */
			if ( stRunId[strlen(stRunId)-1]  ==  0x0d )
			{
				printf("stRunId : %s\n", stRunId);
				stRunId[strlen(stRunId)-1] = 0X00;
			}

                }

                if(!memcmp(stTok, "INKLESS", 7) ) {       /* this line : INKLESS=ON (or OFF) */
			nInkless_Flag =1;                 /* if INKLESS flag exist, nInkless_Flag = 1 */
                }    /* end of if(!memcmp(stTok, "INKLESS", 7) )   */     

                if(!memcmp(stTok, "WAFERTOTAL", 10) ) {      /* this line : WAFERTOTAL=24 */
                        stTok = strtok(NULL, DELIMITER1);
                        memset(stFileCnt, '\0', 5);
                        memcpy(stFileCnt, stTok, strlen(stTok));
                        nFileCnt = atoi(stFileCnt);
                }
#ifdef _DEBUG_MODE
		printf("WAFERTOTAL COUNT[%d]\n",nFileCnt);
#endif

                if(!memcmp(stTok, "COMPONENTS", 10) ) {   /*this line:COMPONENTS=(runid.01,*.02..)*/
                        for(nLoop=1; nLoop <= nFileCnt; nLoop++) {
                                stTok = strtok(NULL, DELIMITER2); /*Retoken stBuff with DELIMITER2*/
#ifdef _DEBUG_MODE
                                printf("COMPONENTS(%d):stTok=[%s],stBuff[%s]\n",nLoop, stTok,stBuff);
#endif
                                memset(stFile_List[nLoop], '\0', 100);
				if( stTok != (char *)NULL )
                                    memcpy(stFile_List[nLoop], stTok, strlen(stTok));
                        } /* end of for( nLoop=1; nLoop <= nFileCnt; nLoop++) .... */
                }

                        /*****
                         *  if stTok = PARTID=KN77A6B        or  *
                         *     stTok = CHIPTOTAL=4503        or  *
                         *     stTok = GOODDIES=(212,235,..) or  *
                         *     stTok = ETC....   then   continue *
                                                             *******/
        } /* end of while(!feof(fpREQ))  */
#ifdef _DEBUG_MODE
        if(fclose(fpREQ)) printf("File Close error with errno[%d]\n",errno); else printf("File CLose competed\n");
#else
        fclose(fpREQ);
#endif
#ifdef _DEBUG_MODE
	printf("RunId = [%s] [%d] bytes \n", stRunId, strlen(stRunId));
	printf("[%s] WAFER FILE TOTAL = [%d] , nLoop = [%d]\n", stRunId, nFileCnt, nLoop);
	for(nTemp=0; nTemp <= nFileCnt; nTemp++) 
		printf(" Map File[%d] = [%s] \n", nTemp, stFile_List[nTemp]);
#endif

        /******* First time,  Insert into Log Table(RUNIDLOG_TIME) ******/
        /******* Add  98/12/03  modified /99/01/06                 ******/
	/******* if occur log insertng error or Inkless flag not Exist **/
	/******* send Fail message                                 ******/ 
	/*******  Do not use  from /98/01/08 ......
        nTemp = DBLog_First(stTempfile);
	if (nTemp == -1 || nInkless_Flag != 1) {
                        memset(stReqFile, '\0', 100);
                        strcpy(stReqFile, stTempfile);
                                ****** goto RPY transfer statement *******
                        nNoExistCnt = 1;
                        nErrOpenCnt = 1;
                        nErrEowCnt = 1;
                        nErrTotal = 2;

                        if ( nTemp == -1 ) {
                                printf("Log data DB Inserting Error: [%s] \n", stTempfile);
                                errno = nTemp;
                                strcpy(stErr_Files[1], "Log data DB Inserting error");
                           } else if (nInkless_Flag != 1) {
                                printf("INKLESS Flag not Exist: [%s] \n", stTempfile);
                                errno = -2;
                                strcpy(stErr_Files[1], "REQ file Format error INKLESS FLAG NOT EXIST");
                             } else  {
                                printf(" Something Wrong: [%s] \n", stTempfile);
                                errno = 22;   *******  Error ETC =>  ErrNO[22]=Invaild Argument ******
                                strcpy(stErr_Files[1], " Something Wrong");
                                }
                        Error_Log(OpenErr, stTempfile, errno);
                        goto REQopen_Error;
	}
	**** end of first log insert and inkless flag check .... Do not use from /98/01/08 *****/

		/********** if REQ file is good format, Check wafer map file ********/
	nNoExistCnt = 1;
	nErrOpenCnt = 1;
	nErrEowCnt = 1;
	nErrTotal = 1;
	for(nTemp=1; nTemp <= nFileCnt; nTemp++) {
		memset(stTempfile, '\0', 256);
		sprintf(stTempfile, "%s%s", MAP_DATA_DIRECTORY, stFile_List[nTemp]);

                        /**** Map file Mode change : FILE_PERM(-rw-r--r--)  /98/01/05 ****/
#ifdef _DEBUG_MODE
                if ( stat(stTempfile, &statbuf) < 0 )   /* get current file mode */
                        fprintf(stderr, "Map File[%s]: couldn't get current stat \n", stTempfile);
#endif
                if( S_ISREG(statbuf.st_mode) ) {  /** if Directory, Skip **/
                    statbuf.st_mode = (statbuf.st_mode|FILE_PERM);
                    if (chmod(stTempfile, statbuf.st_mode) < 0 )
			fprintf(stderr, "Map File[%s]: Couldn't change mode to -rwxr-xr-x\n ", stTempfile);
                }  /** end of if( S_ISREG... **/

		if( (fpWafer = fopen(stTempfile, "r")) == NULL ) {
			usleep(100000);
			if( (fpWafer = fopen(stTempfile, "r")) == NULL ) {
				if( errno == ENOENT) { 		 /* if file don't exist */
					memset(stErr_Files[nErrTotal], '\0', 100);
					strcpy(stErr_Files[nErrTotal], stFile_List[nTemp]);
					nNoExistCnt++;	
					nErrTotal++;
					Error_Log(CountErr, stTempfile, errno);
					continue;
				} /* end of if( errno == ....*/
				memset(stErr_Files[nErrTotal], '\0', 100);
				strcpy(stErr_Files[nErrTotal], stFile_List[nTemp]);
				nErrOpenCnt++;	
				nErrTotal++;
				Error_Log(OpenErr, stTempfile, errno);
				continue;
			} /* end of if( (fpWafer = fopen(......) == NULL ) , after usleep(100000)  */
		} /* end of if( (fpWafer = fopen(......) == NULL ) */
			/*   Check data state */ 
		nEowCnt = 0;
		while(!feof(fpWafer)) {
			memset(stBuff, '\0', sizeof(stBuff));
			fgets(stBuff, sizeof(stBuff), fpWafer);
			if( !memcmp(stBuff, "E= EOW", 6) )  nEowCnt++;
		} /* end of while (!feof(fpWafer)) */ 
		if( nEowCnt != 2 )  {
			memset(stErr_Files[nErrTotal], '\0', 100);
			strcpy(stErr_Files[nErrTotal], stFile_List[nTemp]);
			nErrEowCnt++;	
			nErrTotal++;
			Error_Log(EowErr, stTempfile, nEowCnt);
			continue;
		} /* end of if( nEowcnt... */
		fclose(fpWafer);
	}  /* end of for(nTemp=1; nTemp <= nFileCnt; nTemp++).. */
	

   REQopen_Error:                     /******  <=== Occur Open Error in REQ File ******/
	memset(stRpyFile, '\0', 100);
	sprintf(stRpyFile, "%s%s.RPY",MAP_DATA_ERROR_DIRECTORY, stRunId); 

	if(nErrTotal > 1 ) {           /**** if occur error ***/
		if( (fpRPY = fopen(stRpyFile, "w+")) == NULL) {			
			printf("Can't open : %s \n", stRpyFile);
			Error_Log(OpenErr, stRpyFile, errno);
			return(OpenErr);
		}
		fprintf(fpRPY, "LOTID=%s\n",stRunId);
		fprintf(fpRPY, "RESULT=FAIL\n");
		fprintf(fpRPY, "ERROR=(ErrorTotal:%d,CountErr:%d,OpenErr:%d,EowErr:%d",nErrTotal-1, nNoExistCnt-1, nErrOpenCnt-1, nErrEowCnt-1);
		fprintf(fpRPY, ",ErrMapFile:%s",stErr_Files[1]);
		for(nLoop=2; nLoop<nErrTotal; nLoop++)
			fprintf(fpRPY, ",%s", stErr_Files[nLoop]); 
		fprintf(fpRPY, ")\n[EOF]\n");
		fclose(fpRPY);

			/* send *.RPY to EDS Server (/MAP/inkless/_ONYANG/) */
		memset(stCmd, '\0', 256);
		sprintf(stCmd,"%stransfer_RPY -r %s -l -h %s %s.RPY",TRANSFER_BIN_DIRECTORY,KH_EDS_DIRECTORY,KH_EDS_SERVER,stRunId);
		system(stCmd);

				/* Move Error files to MAP_DATA_ERROR_DIRECTORY */
		for(nLoop=0; nLoop<=nFileCnt; nLoop++) {
			memset(stTempfile, '\0', 256);
			memset(stErrfile, '\0', 256);
			sprintf(stTempfile,"%s%s",MAP_DATA_DIRECTORY,stFile_List[nLoop]);
			sprintf(stErrfile,"%s%s",MAP_DATA_ERROR_DIRECTORY,stFile_List[nLoop]);
	 		if(rename(stTempfile, stErrfile) < 0)
				printf("rename [%s] ==> [%s] error [%d]\n", stTempfile, stErrfile, errno);
		}  /* end of for(nLoop;.... */
		return(-1);
	} /* end of if(nErrTotal > 1) */

		/******** REQ and Wafer Map file all good ********/
	if( (fpRPY = fopen(stRpyFile, "w+")) == NULL) {			
		printf("Can't open : %s \n", stRpyFile);
		Error_Log(OpenErr, stRpyFile, errno);
		return(OpenErr);
	}
	fprintf(fpRPY, "LOTID=%s\n",stRunId);
	fprintf(fpRPY, "RESULT=SUCCESS\n");
	fprintf(fpRPY, "ERROR=(ErrorTotal:%d,CountErr:%d,OpenErr:%d,EowErr:%d",nErrTotal-1, nNoExistCnt-1, nErrOpenCnt-1, nErrEowCnt-1);
	fprintf(fpRPY, ",ErrMapFile:");
	fprintf(fpRPY, ")\n[EOF]\n");
	fclose(fpRPY);
			/* send *.RPY to EDS Server (/MAP/inkless/_ONYANG/) */
	memset(stCmd, '\0', 256);
	sprintf(stCmd,"%stransfer_RPY -r %s -l -h %s %s.RPY",TRANSFER_BIN_DIRECTORY,KH_EDS_DIRECTORY,KH_EDS_SERVER,stRunId);
	system(stCmd);

		/* Rename *.REQ ==> *.REF */
	memset(stTempfile, '\0', 256);
	memset(stRenfile, '\0', 256);
	sprintf(stTempfile,"%s%s",MAP_DATA_DIRECTORY,stFile_List[0]);
	sprintf(stRenfile,"%s%s.REF",MAP_DATA_DIRECTORY,stRunId);
	if(rename(stTempfile, stRenfile) < 0)
		printf("rename [%s] ==> [%s] error No[%d]\n", stTempfile, stErrfile, errno);
	memset(stFile_List[0], '\0', 100);
	memset(stRenfile, '\0', 256);
	sprintf(stRenfile,"%s.REF", stRunId);
	memcpy(stFile_List[0], stRenfile, strlen(stRenfile));  /* Change stFile_List[0]: *.REQ ==> *.REF */

	return(nFileCnt);
}
