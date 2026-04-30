/*
  []--------------------------------------------------------------------[]
  []  Program Name : Mapcvt_Insert()[]
  []  Argument : NONE[]
  []  Procedure define[]
  [] 0. Read Messages from Message Queue(KEYID:0x90000001)[]
  [] 1. call Read directory[]
  [] 2. call Mapcvt for each file_name[]
  []  Programmed by Kim chang kook @ System Engineering Team(TEL:7275)[]
  []  History[]
  []  1. Started at 13/Sep/98[]
  []  Return Value : None[]
  []--------------------------------------------------------------------[]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <syslog.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/signal.h>
/* #include <sys/fault.h> */
#include <sys/syscall.h>
/* #include <sys/procfs.h> */
#include <pthread.h>
#include "Map_data_task.h"
#include "ipcs.h"
	/* Added by stainles /99/01/07 */
pthread_t lThread;
void* pThreadWork(void* arg)
{
	int nRets;
	while( waitpid( (int)arg, &nRets, 0 ) <= 0 );
	return 0;
} 

     /* parameters of strtok function */
#define DELIMITER1 "[- "
#define DELIMITER2 "[/&"
#define DELIMITER3 "[# "
#define DELIMITER4 "= "
#define DELIMITER5 "."

#define LotId_Lth 6
#define LotId_Lth_alpha 5



     /* Fixed data  */
#define MapIdType '\0'
#define MapFormat  '\1'
#define EDS_OrLoc '\3'
#define EDS_RPSel 1

void 	InitMsgQ();
int  	Mapcvt_Call();
int  	nGetRunId();          /** Added by stainles 2000.10.16 **/
int  	Mapcvt_Insert();
char 	cCheckGoodBin();
extern int nInsertDb();
extern int InsertLog();
int 	Error_Log();
void 	Get_Date();

extern int errno;
extern char* sys_errlist[];
extern int RegistProcess();
extern int nInsertHalfInfo();

RunFilesMsgQ  MsgQ_WaferList;
int Msg_Qid;

int     gnBin_SecondCnt; /*2007.06.21 */
char    gsPartNo[40]; /* 2007.06.21 */
/* 2010-05-04  DDR3(2G RLE) <-9vGb x4, x8 A&G0?!  */
/* int	gsBin_SecondCnt; */


#ifdef _MANUAL_MODE   /** you just want to handle One Map file, NOT Map file Group(RUN)` **/  
void main(argc,argv)
int argc;
int *argv[];
{
   	if(argc < 2) 
	{
     		printf("Usage Error!! : usage:%s eds_file_name\n",argv[0]);
     		exit(-1);
   	}
   	Mapcvt_Insert(argv[1]);
}
#else    /** you want to handle RUN  **/

void main()
{
        int Rdmsg;
             /** Added by stainles 2000.07.12 **/
        char stCvtfile[256];
        char stMovefile[256];
        char *stTok;
        char stLogMsg[256];
             /** End of Addition 2000.07.12 **/

        printf("Inkless D/A MAPCVTmgr started !!\n");

        setpgrp();     /* Become Session leader */
              /* Fork for making daemon process */
        switch (fork())
        {
        case -1:        /* Unable to fork, for some reason. */
                fprintf(stderr, "unable to fork daemon\n");
                exit(1);

        case 0 :                /* The Child process (daemon) comes here. */
            signal(SIGCLD, SIG_IGN);   /* Ignore signals from child process */

                    /* modified by msyun 98/11/24 */
                    /* Inserting process_id registration routine for managing inkless processes */
            if(RegistProcess() != EXE_OK)
            {
                printf("Critical Error[%s] : ProcessRegist Error[%s] ....program exit!\n",sys_errlist[errno]);
                exit(errno);
            }

            InitMsgQ();
            for (;;)
            {
                memset(&MsgQ_WaferList, '\0', sizeof(Map_infor));
                        /* Read Message queue -  Wafer List of Run*/
                Rdmsg = msgrcv(Msg_Qid, &MsgQ_WaferList, sizeof(Map_infor), MsgType, 0);

                if(Rdmsg < 0)
                    continue;
                else
                    /* make child processes for each messages */
                switch(fork())
                {
                    case -1 :
                        /** Added by stainles  2000.07.12 **/
                        memset(stCvtfile, '\0', 256);
                        memset(stMovefile, '\0', 256);
                        sprintf(stCvtfile,"%s%s",MAP_DATA_DIRECTORY, MsgQ_WaferList.msgData.Wafer_List[0]);
                        stTok = strtok(MsgQ_WaferList.msgData.Wafer_List[0],DELIMITER5);
                        sprintf(stMovefile,"%s%s.REQ",MAP_DATA_DIRECTORY,stTok);
                        if(rename(stCvtfile, stMovefile) < 0)
                        {
                            sleep(1);
                            rename(stCvtfile, stMovefile);
                        }
                        memset(stLogMsg, '\0', sizeof(stLogMsg));
                        sprintf(stLogMsg, "rename %s ==> %s",stCvtfile,stMovefile);
                        Error_Log(MapcvtForkErr, stLogMsg);
                        #ifdef _DEBUG_LOG
                            printf("Process FORK Error: rename[%s]==>[%s]\n",stCvtfile,stMovefile);
                        #endif
                                        /**
                                        exit(1);
                                        **/
                        break;
                                            /** end of Addition  2000.07.12 **/
                    case  0 :
                            Mapcvt_Call(&MsgQ_WaferList.msgData);
                            exit(0);
                    default :
                            break;
                }  /* end of switch */
            }  /* end of for(;;) */
            break;
        default :               /* Parent process commes here */
                        exit(0);
        }  /* end of switch(fork()) for making daemon process */
}   /* end of main */
#endif   /** End of _MANUAL_MODE **/





/****************************************************
 *  Message queue create or connection process      *
 ****************************************************/

void InitMsgQ()
{
	/* Message Queue Creation */ 
	/* Create message queue if non exist */
        if((Msg_Qid = msgget(ftok(Qkey_F,Qkey), IPC_CREAT|QPERM)) < 0) 
	{
             	printf("can't create message queue");
             	exit(2);
        }
}

/*******************************
 *  Make Log file 
 *******************************/

int Error_Log(LogType, ErrMsg)
int LogType;
char *ErrMsg;
{
	time_t logtime;
	FILE *fp;
	char log_date[20];
	char filename[256];
	memset (filename, '\0', 256);

#ifdef _DEBUG_LOG
	printf(" LogType: [%d]\n",LogType);
#endif

 	Get_Date(log_date);
	/********** Modified by stainles 2000.03.06, ************/
	/**** change if() els if() else ..... => switch(LogType) .... ****/
	/********************
	if (LogType == InsertGood) 
	{
		sprintf(filename, "/users/inkless/LOG/CvtInsertGood.%s", log_date);
 	} 
	else if (LogType == DataFormatErr) 
	{
 		sprintf(filename, "/users/inkless/LOG/FileFormatErr.%s", log_date);
	} 
	else if (LogType == InsertErr) 
	{
		sprintf(filename, "/users/inkless/LOG/InsertErr.%s", log_date);
        } 
	else 
   	{
 		sprintf(filename, "/users/inkless/LOG/CvtInsertErr.%s", log_date);
        }	
	*********************/

 	switch ( LogType ) 
	{
     		case InsertGood :
			sprintf(filename, "/users/STS/inkless/LOG/SERVER/CvtInsertGood.%s", log_date);
			break;
     		case DataFormatErr :
 			sprintf(filename, "/users/STS/inkless/LOG/SERVER/FileFormatErr.%s", log_date);
			break;
     		case InsertErr :
			sprintf(filename, "/users/STS/inkless/LOG/SERVER/InsertErr.%s", log_date);
			break;
     		case MapRotationErr :
			sprintf(filename, "/users/STS/inkless/LOG/SERVER/MapRotationErr.%s", log_date);
			break;
     		/*** case ConvertErr : ***/
      		case Cvt_FileOpenErr : 
      		case Cvt_EowCountErr : 
 			sprintf(filename, "/users/STS/inkless/LOG/SERVER/CvtInsertErr.%s", log_date);
			break;
      		case MapcvtForkErr : 
 			sprintf(filename, "/users/STS/inkless/LOG/SERVER/MapcvtForkErr.%s", log_date);
			break;
      		default : break;
    	}/** end of switch(LogType)... **/	


 	if( (fp=fopen(filename, "a+")) == NULL) 
	{
        	usleep(200000);	
        	if( (fp=fopen(filename, "a+")) == NULL) 
		{ 
 	      		printf("Error File Open Error\n");
              		return (-1);
        	}
 	}

 	time(&logtime);
 	switch(LogType) 
	{
		case InsertGood :
 			fprintf(fp,"[#%d Inserting Success[%s] at %s]\n", LogType, ErrMsg, ctime(&logtime));
 			break;
 		/**************
		case ConvertErr :
 			fprintf(fp,"[#%d Converting Error[%s] at %s]\n", LogType, ErrMsg, ctime(&logtime));
 	        	break;
		***************/
 		case Cvt_FileOpenErr :
 			fprintf(fp,"[#%d Map File Open Error[%s] at %s]\n", LogType, ErrMsg, ctime(&logtime));
 			break;
 		case Cvt_EowCountErr :
 			fprintf(fp,"[#%d Eow Count Error[%s] at %s]\n", LogType, ErrMsg, ctime(&logtime));
 			break;
		case InsertErr :
 			fprintf(fp,"[#%d Inserting Error[%s] at %s]\n", LogType, ErrMsg, ctime(&logtime));
 			break;
		case MapRotationErr :
 			fprintf(fp,"[#%d Map Roation Error[%s] at %s]\n", LogType, ErrMsg, ctime(&logtime));
 			break;
		case DataFormatErr :
 			fprintf(fp,"[#%d Data Format Error[%s] at %s]\n", LogType, ErrMsg, ctime(&logtime));
 			break;
		case MapcvtForkErr :
 			fprintf(fp,"[#%d Mapcvt_Insert Process Fork Error[%s] at %s]\n", LogType, ErrMsg, ctime(&logtime));
 			break;
		default : break;
 	}
        fclose(fp);
        return (0);

}  /*** end of  void Error_Log(LogType, ErrMsg) **/

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


/********************************************************
 *  Call Converting and Inserting function              *
 ********************************************************/

int Mapcvt_Call(stWafer_List)
Map_infor *stWafer_List;
{
	char stCvtfile[256];
	char stMovefile[256];
	char *stTok;
	int  nLoop;
	int  nFileCnt;
	int  nErrCnt;
	int  nDataFormatErr;
	int  nTemp;
	int  ErrCode;
        char stErrorCode[30];    /* Added by stainles 2000.07.12 */
        char stRunid[50];       /* Added by stainles 2000.10.16 */

	nFileCnt = stWafer_List->Wafer_Count;
	nErrCnt = 0;
	nDataFormatErr = 0;
#ifdef _DEBUG_LOG
	printf(" Wafer Count: [%d]\n", nFileCnt); fflush(stdout);
	for(nLoop=1; nLoop<=nFileCnt; nLoop++) 
		printf(" Wafer File[%d] = [%s]\n", nLoop, stWafer_List->Wafer_List[nLoop]);
#endif

              /** Get Run id from *.REQ file  :  Added by stainles 2000.10.16 **/
	      /** Because Run_id in Map file is able to be different from Run_id in *.REQ file **/
	memset(stCvtfile, '\0', 256);   /** *.REF file **/
	sprintf(stCvtfile, "%s%s", MAP_DATA_DIRECTORY, stWafer_List->Wafer_List[0]);
	memset(stRunid, '\0', sizeof(stRunid));
        ErrCode = nGetRunId(stCvtfile,stRunid);
	if (ErrCode != EXE_OK )
	      memset(stRunid, '\0', sizeof(stRunid));
#ifdef _DEBUG_LOG
	printf("stRunid: [%s] \n", stRunid);
#endif
	      /** End of Added **/

	for(nLoop=1; nLoop<=nFileCnt; nLoop++) 
	{
		memset(stCvtfile, '\0', 256);
		sprintf(stCvtfile, "%s%s", MAP_DATA_DIRECTORY, stWafer_List->Wafer_List[nLoop]);
		/** ErrCode = Mapcvt_Insert(stCvtfile);  **/
		#ifdef _DEBUG_LOG
		printf("Mapcvt_Insert for %s\n", stCvtfile);
		#endif
		ErrCode = Mapcvt_Insert(stCvtfile, stRunid);  /** Modified by stainles 2000.10.16 **/
		if( ErrCode == Cvt_EowCountErr ) 
		{  /* If Eow Count Error, Retry to Convert */
		        usleep(300000);	
		           /** ErrCode = Mapcvt_Insert(stCvtfile); **/
			   /** Modified by stainles 2000.10.16     **/
		        ErrCode = Mapcvt_Insert(stCvtfile, stRunid); 
                }
 		switch (ErrCode ) 
		{ 
		   	case  InsertErr :               /* if Inserting Error occurs */
				Error_Log(InsertErr,stCvtfile);
                                nErrCnt++;
				break;
		   	case  MapRotationErr :          /* if Map Rotation Error occurs */
				Error_Log(MapRotationErr,stCvtfile);
                                nErrCnt++;
				break;
		   	case  DataFormatErr :           /* if Converting Error occurs */
				Error_Log(DataFormatErr, stCvtfile); /* write log file */
				nDataFormatErr++;
                                nErrCnt++;
				break;
	        	/* case  ConvertErr :  if Converting Error occurs */
		   	case  Cvt_FileOpenErr :          /* if Map file Open Error occurs */
				Error_Log(Cvt_FileOpenErr, stCvtfile); /* write log file */
                                nErrCnt++;
				break;
		  	 case  Cvt_EowCountErr :          /* if Eow Count Error occurs */
				Error_Log(Cvt_EowCountErr, stCvtfile); /* write log file */
				nDataFormatErr++;
                                nErrCnt++;
				break;
                   	case InsertGood :                /* Map file Convert and Insert Success */
				Error_Log(InsertGood, stCvtfile);    /* write log file */
#ifdef _DEBUG_LOG
                                printf("#%d Insert Success: [%s]\n", InsertGood, stCvtfile);
#endif
				break;
                  	default : break;
	        }/** end of switch(ErrCode) .... **/	

        } /* end of for(nLoop=1; nLoop<=nFileCnt; nLoop++).... */

#ifdef _DEBUG_LOG
	printf("Error Count: [%d]\n",nErrCnt);


#endif
	printf("Error Count: [%d]\n",nErrCnt);


                        /* Not occur converting or Insertng error */
        if( nErrCnt < 1 ) 
	{
		memset(stCvtfile, '\0', 256);
		sprintf(stCvtfile, "%s%s", MAP_DATA_DIRECTORY, stWafer_List->Wafer_List[0]);
		/** sprintf(stCvtfile, "%s%s", MAP_DATA_BACKUP_DIRECTORY, stWafer_List->Wafer_List[0]); **/
#ifdef _DEBUG_MODE
		printf("send [%s] to InsertLog function \n", stCvtfile);
#endif
                       /* Send REF file to Log Function */
		ErrCode = InsertLog(stCvtfile); 
		if( ErrCode != EXE_OK ) 
		{  /* If it is fail to insert Log data into Log table */
		        usleep(300000);	
		        ErrCode = InsertLog(stCvtfile); 
                }
                       /** Added by stainles 2000.07.12 **/
                switch (ErrCode) 
		{
                   	case EXE_OK :             /* REF file Read and Insert Success */
                                 Error_Log(InsertGood, stCvtfile);    /* write log file */
                                 break;
                   	case Cvt_FileOpenErr :    /* If REF file Open Error occurs */
                                 Error_Log(Cvt_FileOpenErr, stCvtfile); /* write log file */
                                 break;
                   	default :                 /* If Inserting Error occurs */                                        
                                 memset(stErrorCode, '\0', sizeof(stErrorCode));
                                 sprintf(stErrorCode, "ORACLE ERROR: %d", ErrCode);
                                 Error_Log(InsertErr, stErrorCode);
                                 Error_Log(InsertErr, stCvtfile);
                                 break; 
                }   /* End of switch(ErrCode) ... */
                       /** End of Addition 2000.07.12 **/
		for(nLoop=0; nLoop<=nFileCnt; nLoop++) 
		{
 			memset(stCvtfile, '\0', 256);
 			memset(stMovefile, '\0', 256);
 			sprintf(stCvtfile,"%s%s",MAP_DATA_DIRECTORY, stWafer_List->Wafer_List[nLoop]);
 			sprintf(stMovefile,"%s%s",MAP_DATA_BACKUP_DIRECTORY, stWafer_List->Wafer_List[nLoop]);
 			if(rename(stCvtfile, stMovefile) < 0) 
			{
#ifdef _DEBUG_MODE
 				printf("rename [%s] ==> [%s] Error NO[%d] \n", stCvtfile, stMovefile, errno);
#endif
                        }
#ifdef _DEBUG_MODE
			printf("rename [%s] ==> [%s] \n", stCvtfile, stMovefile);
#endif
 		}  /* end of for(nLoop;.... */
	} 
	else 
	{ 
		if(nDataFormatErr < 1) 
		{
 			memset(stCvtfile, '\0', 256);
 			memset(stMovefile, '\0', 256);
 			sprintf(stCvtfile,"%s%s",MAP_DATA_DIRECTORY, stWafer_List->Wafer_List[0]);
			stTok = strtok(stWafer_List->Wafer_List[0],DELIMITER5);
 			sprintf(stMovefile,"%s%s.REQ",MAP_DATA_DIRECTORY,stTok);
 			if(rename(stCvtfile, stMovefile) < 0) 
			{
#ifdef _DEBUG_MODE
 				printf("rename [%s] ==> [%s] Error NO[%d] \n", stCvtfile, stMovefile, errno);
#endif
                        }
		} 
		else 
		{    /*  if Data Format Error occurs ... */
			for(nLoop=0; nLoop<=nFileCnt; nLoop++) 
			{
				memset(stCvtfile, '\0', 256);
 				memset(stMovefile, '\0', 256);
 				sprintf(stCvtfile,"%s%s",MAP_DATA_DIRECTORY, stWafer_List->Wafer_List[nLoop]);
 				sprintf(stMovefile,"%s%s",MAP_DATA_ERROR_DIRECTORY, stWafer_List->Wafer_List[nLoop]);
 				if(rename(stCvtfile, stMovefile) < 0) 
				{
#ifdef _DEBUG_MODE
 					printf("rename [%s] ==> [%s] Error NO[%d] \n", stCvtfile, stMovefile, errno);
#endif
                        	}
#ifdef _DEBUG_MODE
				printf("rename [%s] ==> [%s] \n", stCvtfile, stMovefile);
#endif
 			}  /* end of for(nLoop;.... */
		}  /* if(nDataFormatErr < 1) .....*/
	} /* end of if(nErrCnt < 1)...else.... */	
	
	return(1);

} /* end of Mapcvt_Call() */



/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  Function NAME:nGetRunId()
  DESCRIPTION:  Get Run id from *.REF file 
  DATE:10/16/2000
  -----------------------------------------------------------
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
int nGetRunId(stReqFile,stRunid)
char *stReqFile;
char *stRunid;
{
  	FILE *fpREQ;
  	char stBuff[512];
  	char stTemp[256];
  	char *ptr;

  	if ( (fpREQ = fopen(stReqFile, "r")) == NULL) 
	{
	  	usleep(100000);
	  	if ( (fpREQ = fopen(stReqFile, "r")) == NULL) 
		{
#ifdef _DEBUG_LOG
		 	printf("Can't open : [%s] \n", stReqFile);
		 	return(Cvt_FileOpenErr);   /* *.REF file open Error */
#endif
          	}
  	}

  	while(!feof(fpREQ)) 
	{
      		memset(stBuff, '\0', sizeof(stBuff));
      		fgets(stBuff, sizeof(stBuff), fpREQ);
      		ptr = stBuff;
     		ptr = (char*)strstr((char *)ptr,"LOTID=");
      		if (ptr)
       		{
	  		ptr += 6;
	  		memset(stTemp, '\0', sizeof(stTemp));
	  		sscanf((char *)ptr, "%s", stTemp);
	  		memcpy(stRunid,  stTemp, strlen(stTemp));
	  		return (EXE_OK);
       		}
  	} /* end of while(!feof(fpREQ) ... */

  	return (-1);

} /** end of int nGetRunId(..... **/
		 

/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  Function NAME:mapcvt_Insert()
  DESCRIPTION:  converting  map file, insert db
  DATE:9/20/98
  -----------------------------------------------------------
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
     /** Modified by stainles 2000.10.16 **/
#ifdef _MANUAL_MODE   /** you just want to handle One Map file, NOT Map file Group(RUN)` **/  

int Mapcvt_Insert(filename)
char *filename;
#else    /** You want to handle RUN  **/

int Mapcvt_Insert(filename, stRunId_REQ)
char *filename;
char *stRunId_REQ;
#endif  /** End of _MANUAL_MODE **/
/*** 
int Mapcvt_Insert(filename)
char *filename;
***/
     /** end of Modification **/
{
 	FILE *fpRead;
	MAP_BODY MapBody;
        char stPartId[32];
	POINT pntFirstDie;
        int  nMax_X;
        int  nMax_Y;
        int  nMin_X;
        int  nMin_Y;
	int  nTemp_X;
	int  nTemp_Y;
	char cTempBin;
	char stGoodBinFlag[16];
        char stBinArray[400][400];
	int  nLoopRow, nLoopCol;
	int  nGoodBinCount;
 	char *stTok; 
        char stBuff[256];
        char stTemp[256];
	int  nCount;
        int  nEowCnt;
	long fpOffset;
	long fpOffsetEow1;
	long fpOffsetEow2;
	int  nErrorCode;
	char stErrorCode[30];
	char *stemptemp;
	char stemp1[30];


	char tmpWaferId[15];  /** Modified by stainles 2001.04.19 **/

        memset(&MapBody, '\0', sizeof(MAP_BODY));

	if( (fpRead = fopen(filename, "r")) == NULL) 
	{
		usleep(300000); 	
        	if( (fpRead = fopen(filename, "r")) == NULL) 
		{
#ifdef _DEBUG_MODE
                	printf("Can't Open File [%s] with errno [%d]!\n", filename,errno);
#endif
               	    /** return(ConvertErr);  Modified by stainles 2000.03.06 **/
                	return(Cvt_FileOpenErr); 
                }
         }
   /** Modified by stainles 2000.03.06                                **/
   /** Map file Check and get offset value of 1st Eow, 2nd Eow        **/
   /** Eow Count Check, If Eow Count is not 2, Map file must be wrong **/
       	fseek(fpRead, 0L, SEEK_SET);
	    /** Initialize variables for Eow Checking  **/
       	nEowCnt = 0;
       	fpOffsetEow1 = 0L;
      	fpOffsetEow2 = 0L;
      	while ( !feof(fpRead) ) 
       	{
	   	fpOffset = ftell(fpRead);
	   	memset(stBuff, '\0', sizeof(stBuff) );
	   	fgets(stBuff, 256, fpRead);
#ifdef _DEBUG_LOG
		printf("Read : [%s]\n", stBuff);
#endif
	   	if ( !memcmp(stBuff, "E= EOW", 6) ) 
		{
	       		nEowCnt++;
#ifdef _DEBUG_LOG
	       		printf("EOW line : %s\n", stBuff);
#endif
               		if (nEowCnt == 2) 
			{
			 /* Get offset of Second "E= EOW" line */
                     		fpOffsetEow2 = fpOffset;
		     		break;
                	}
			 /* Get offset of First "E= EOW" line */
			fpOffsetEow1 = fpOffset;
            	} /** end of if( !memcmp(stBuff, ...) .... **/
       	} /** end of while( !feof(fpRead) ) .... **/

#ifdef _DEBUG_LOG
      	printf("Offset of 1st EOW : %ld\n", fpOffsetEow1);
       	printf("Offset of 2nd EOW : %ld\n", fpOffsetEow2);
#endif
    
	if ( nEowCnt != 2)  
       	{
#ifdef _DEBUG_LOG
       		printf("Eow count : %d\n", nEowCnt);
#endif
            	fclose(fpRead);
	    	return (Cvt_EowCountErr);
       	}
/*****  end of Modification  ****/


        fseek(fpRead, 0L, SEEK_SET);  /** Move to Start position of file **/


		/* Read Wafer Id */
        memset(stBuff, '\0', 256);
	fgets(stBuff, 256, fpRead);
#ifdef _DEBUG_MODE
	printf("Read : [%s]\n", stBuff);
#endif
/**** Modified by stainles on DEC. 16. 1999  ****/

	stTok = strtok(stBuff, DELIMITER1);  /** DELIMITER1 : "[- " **/
	
	/** Modified by stainles, 2001.04.19  **/
	memset(tmpWaferId, '\0', sizeof(tmpWaferId));
	memcpy(tmpWaferId, stTok, strlen(stTok));

           /*** Modified by stainles 2000.10.16 **/
	   /** Because the Run_id in Map file is able to be different from Run_id in REQ file **/
#ifdef _MANUAL_MODE   /** you just want to handle One Map file, NOT Map file Group(RUN)` **/  

        memcpy(MapBody.stRUN_ID, stTok, strlen(stTok));

#else  /** you want to handle a RUN **/

        if ( 0 != strcmp(stRunId_REQ, stTok) )
	{
 printf("RUN Id1: %s\n", MapBody.stRUN_ID);
               	memcpy(MapBody.stRUN_ID, stRunId_REQ, strlen(stRunId_REQ));
printf("RUN I31: %s\n", MapBody.stRUN_ID);

        }
        else 
	{

		
	printf("RUN Id2o: %s\n", MapBody.stRUN_ID);
               	memcpy(MapBody.stRUN_ID, stTok, strlen(stTok));
 printf("RUN Id21: %s\n", MapBody.stRUN_ID);

		
        }
#endif  /** End of _MANUAL_MODE **/
	    
 printf("RUN I32o: %s\n", MapBody.stRUN_ID);
#ifdef _DEBUG_MODE
	printf("RUN Id: %s\n", MapBody.stRUN_ID);
#endif
        /** Modified by stainles, 2001.04.19  **/
        /** if waferid in Map file is diffent with RunId in REQfile,  **/
	/** you must use waferid in mapfile for real waferid          **/
        /** memcpy(MapBody.stMID, MapBody.stRUN_ID, strlen(MapBody.stRUN_ID)); **/
 
	memset(stemp1,0x00,sizeof(stemp1));
        if (strstr(tmpWaferId, ".") != NULL)
    {		

	if( strstr(MapBody.stRUN_ID,".") != NULL)
	{
	strcpy(stemp1, MapBody.stRUN_ID);
        stemptemp = strstr(stemp1,".");
        
        memset(MapBody.stRUN_ID, 0x00, sizeof(MapBody.stRUN_ID));
        
        strncpy(MapBody.stRUN_ID, stemp1, strlen(stemp1)- strlen(stemptemp));
	}
        printf("id 2 -%s\n", MapBody.stRUN_ID);
	memcpy(MapBody.stMID, tmpWaferId, LotId_Lth);        
        strncat(MapBody.stMID, "-", 1);
        strncat(MapBody.stMID, tmpWaferId + (strlen(tmpWaferId) - 2), 2);
        stTok = strtok(NULL, DELIMITER1);
	}
	else
	{
	printf("point #2\n");
	memcpy(MapBody.stMID, tmpWaferId, strlen(tmpWaferId));
        strncat(MapBody.stMID, "-", 1);
        printf("ID1 %s\n", MapBody.stMID);
        stTok = strtok(NULL, DELIMITER1);
        strncat(MapBody.stMID, stTok + (strlen(stTok) - 2), 2);
}

/*     2006.04.05  
memcpy(MapBody.stMID, tmpWaferId, strlen(tmpWaferId));
	strncat(MapBody.stMID, "-", 1);

	stTok = strtok(NULL, DELIMITER1);
	strncat(MapBody.stMID, stTok + (strlen(stTok) - 2), 2);
*/
#ifdef _DEBUG_MODE
	printf("Wafer Ida: %s\n", MapBody.stMID);
#endif
/*** Wafer_id is needed to check in followed "product name routine" ***/

/*********************
	memcpy(MapBody.stMID, stTok, LotId_Lth);
	strncat(MapBody.stMID, "-", 1);
	strncat(MapBody.stMID, stTok + (strlen(stTok) - 2), 2);
#ifdef _DEBUG_MODE
	printf("Wafer Id: %s\n", MapBody.stMID);
#endif
        stTok = strtok(stBuff,"[-");
	memcpy(MapBody.stRUN_ID, stTok, strlen(stTok));
#ifdef _DEBUG_MODE
	printf("RUN Id: %s\n", MapBody.stRUN_ID);
#endif
************************/
/************** End of Modification ***************/


		/* Read Wafer Id Type and Map Format */
	MapBody.cIDTYP = MapIdType; 
	MapBody.cMAPFT = MapFormat;
#ifdef _DEBUG_MODE
	printf("Id Type: %x\n", MapBody.cIDTYP);
	printf("Map Format : %x\n", MapBody.cMAPFT);
#endif

	/* 2010-05-04 START BIN 11 @L A8@gGO0m 11 9x BIN @L A8@gGR=C */
/*
    gnBin11toBin2 = 0;
    if ( strncmp(MapBody.stRUN_ID, "EL", 2) == 0)
    {
        gnBin11toBin2 = 1;
        
    }
*/

		/* Read Part Id */
        memset(stBuff, '\0', 256);
	fgets(stBuff, 256, fpRead);
#ifdef _DEBUG_MODE
	printf("Read : [%s]\n", stBuff);
#endif
	stTok = strtok(stBuff, DELIMITER2);
	nCount = 1;
	while( (stTok = strtok(NULL, DELIMITER2)) != NULL) 
	{
                            /*** Read Part ID ***/
		if(nCount == 2) 
		{
			/*memcpy(stPartId, stTok, strlen(stTok)); */
			strcpy(stPartId, stTok);
            		printf("stpartid : %s, stTok : %s\n ", stPartId, stTok);
		}
		             /** Data Validation **/
	        if (stPartId == NULL) 
		{
			fclose(fpRead);
			return(DataFormatErr);
		}
		      /* Location of Flat Zone */ 
		if(nCount ==4) 
		{ 
		               /** Data Validation **/
		     	if (stTok[0] != '0' && atoi(stTok) == 0 ) 
			{  
				fclose(fpRead);
		    		return(DataFormatErr);
		     	}	    
#ifdef _DEBUG_MODE
	             	printf("stTok for FlatZoneLocation : %s\n", stTok);
#endif
	    	             /* Read location of Flat Zone  */
	            	switch(atoi(stTok)) 
			{
		          	case 0 :          /* Flat Zone is on Top side */
			          	MapBody.uFNLOC = 180;
			          	break;
		          	case 3 :          /* Flat Zone is on Right hand side */
			          	MapBody.uFNLOC = 270;
			          	break;
		          	case 5 :          /* Flat Zone is on Bottom side */
			          	MapBody.uFNLOC = 0;
			          	break;
		          	case 7 :          /* Flat Zone is on Left hand side */
			          	MapBody.uFNLOC = 90;
			          	break;
		          	default :
	                          	fclose(fpRead);
			          	return(DataFormatErr);
			          	break;
	             	}   /* end of switch */
	        } /* end of if(nCount == 4) */
		if(nCount ==8) 
		{ /* Net die count */ 
	           	MapBody.uNET_DIE_CNT = atoi(stTok);
#ifdef _DEBUG_MODE
	           	printf("stPartId : %s\n", stPartId);
	           	printf("Flat Zone Location: %d\n", MapBody.uFNLOC);
		   	printf("Netdiecnt = [%d]\n",MapBody.uNET_DIE_CNT); 
#endif
		   	break;
                }

	        nCount++;

	} /* end of while */

#ifdef _DEBUG_MODE
	printf("PART Id: %s\n", stPartId);
#endif

		/* Read Original Location and Reference Point Selection */
	MapBody.cORLOC = EDS_OrLoc;
	MapBody.uRPSEL = EDS_RPSel;
#ifdef _DEBUG_MODE
	printf("Original Location: %x\n", MapBody.cORLOC);
	printf("Ref Point Selection: %d\n", MapBody.uRPSEL);
#endif
	

/*******  Modified by stainles on Dec. 17. 1999  *******/
/***  Because Wafer Id is different alpha chip and the others ***/
                /* Skip one line */
/***  fgets(stBuff, 256, fpRead);  ***/

           /**** Read Product Name : 'alpha chip' or 'the other' ****/
        memset(stBuff, '\0', 256);
        fgets(stBuff, 256, fpRead);
#ifdef _DEBUG_MODE
	printf("Read [%s]\n", stBuff);
#endif
        stTok = strtok(stBuff, DELIMITER2);
        stTok = strtok(NULL, DELIMITER2);

	/* modify 2003.2.13 bws for stTok = NULL */
	/* if( memcmp(stTok, "alpha", 5) != 0 ) */

        if( stTok !=NULL && memcmp(stTok,"alpha", 5) != 0 )
	{ /** if stTok is not "alpha" **/
		
              	memset(stTemp, '\0', sizeof(stTemp));
              	strcpy(stTemp, MapBody.stMID);
              	memset(MapBody.stMID, '\0', sizeof(MapBody.stMID));
		printf("not alpah\n");	
		/** Modified by stainles, 2001.04.19  **/
              /*	if (strlen(tmpWaferId) >= LotId_Lth)*/
              		memcpy(MapBody.stMID, tmpWaferId, LotId_Lth);
	     /* 	else	
			memcpy(MapBody.stMID, MapBody.stRUN_ID, LotId_Lth);*/
                
        	printf("Wafer Id1: %s\n", MapBody.stMID);
	      	strncat(MapBody.stMID, "-", 1);
              	strncat(MapBody.stMID, stTemp + (strlen(stTemp) - 2), 2);

        	printf("Wafer Id2: %s\n", MapBody.stMID);
#ifdef _DEBUG_MODE
        	printf("Wafer I3d: %s\n", MapBody.stMID);
#endif
        } 
	else if( stTok != NULL ) 
	{
              	memset(stTemp, '\0', sizeof(stTemp));
              	strcpy(stTemp, MapBody.stMID);
              	memset(MapBody.stMID, '\0', sizeof(MapBody.stMID));

#ifdef _DEBUG_MODE
        	printf("######################### ALPHA: %s\n", MapBody.stMID);
#endif

              	
		/** Modified by stainles, 2001.04.19  **/
	    /*  	if (strlen(tmpWaferId) >= LotId_Lth_alpha)*/
			memcpy(MapBody.stMID, tmpWaferId, LotId_Lth_alpha);
	      /*	else
	      		memcpy(MapBody.stMID, MapBody.stRUN_ID, LotId_Lth_alpha);
             */
 
	      	strncat(MapBody.stMID, "-", 1);
              	strncat(MapBody.stMID, stTemp + (strlen(stTemp) - 2), 2);
#ifdef _DEBUG_MODE
        	printf("Wafer Id5: %s\n", MapBody.stMID);
#endif
      	} /** end of if(memcomp....) else.... **/
       else
       {
		

              	memset(stTemp, '\0', sizeof(stTemp));
              	strcpy(stTemp, MapBody.stMID);
              	memset(MapBody.stMID, '\0', sizeof(MapBody.stMID));
		printf("not alpah\n");	
		/** Modified by stainles, 2001.04.19  **/
              /*	if (strlen(tmpWaferId) >= LotId_Lth)*/
              		memcpy(MapBody.stMID, tmpWaferId, LotId_Lth);
	     /* 	else	
			memcpy(MapBody.stMID, MapBody.stRUN_ID, LotId_Lth);*/
                
        	printf("Wafer Id1: %s\n", MapBody.stMID);
	      	strncat(MapBody.stMID, "-", 1);
              	strncat(MapBody.stMID, stTemp + (strlen(stTemp) - 2), 2);

	}	 
#ifdef _DEBUG_MODE
                printf("Wafer I65: %s\n", MapBody.stMID);
#endif

              		memcpy(MapBody.stMID, tmpWaferId, LotId_Lth);
#ifdef _DEBUG_MODE
                printf("Wafer I75: %s\n", MapBody.stMID);
#endif

/******* end of 'Modified by stainles on Dec. 17. 1999' *******/


		/* Read Good bin Flag */
	memset(stBuff, '\0', 256);
	fgets(stBuff, 256, fpRead);
	stTok = strtok(stBuff, DELIMITER3);
	nCount = 1;
	while( (stTok = strtok(NULL, DELIMITER3)) != NULL) 
	{
		if(nCount == 2) break;
		nCount ++;
	} /* end of while */
	memset(stGoodBinFlag, '\0', 16);
	memcpy(stGoodBinFlag, stTok, strlen(stTok));
	if(stGoodBinFlag == NULL) 
	{
	        fclose(fpRead);
		return (DataFormatErr);
        }
#ifdef _DEBUG_MODE
	printf("Good Bin Flag: %s\n", stGoodBinFlag);
#endif

		/* Skip Bin list block */
	while(stBuff[0] == '[') 
	{
		fpOffset = ftell(fpRead);
		memset(stBuff, '\0', 256);
		fgets(stBuff, 256, fpRead);
	}   /* end of while */
#ifdef _DEBUG_MODE
	printf("Current Offset: %ld\n", fpOffset);
	printf("Current line: %s\n", stBuff);
#endif

		/* Initialize Bin data Array */
	for(nLoopRow = 0; nLoopRow < 400; nLoopRow++) 
	{
		for(nLoopCol = 0; nLoopCol < 400; nLoopCol++) 
		{
	        	stBinArray[nLoopCol][nLoopRow] = NO_DIE_MK;
		}
	}

		/* move to starting position of bin data */
	gnBin_SecondCnt = 0; /* 2007.06.21 init */
	fseek(fpRead, fpOffset, SEEK_SET);
	memset(stBuff, '\0', 256);
	fgets(stBuff, 256, fpRead);
	while( stBuff[0] != 'X' ) 
	{
		memset(stBuff, '\0', 256);
		fgets(stBuff, 256, fpRead);
	}  /* if First character of stBuff is X, exit while statement */
		/* Read first Bin(X,Y) record  */
	stTok = strtok(stBuff, DELIMITER4);
	nCount = 1;
	while( (stTok = strtok(NULL, DELIMITER4)) != NULL ) 
	{
		if(nCount == 1) 
		{
		                   /** Data Validation **/
		        if (stTok[0] != '0' && atoi(stTok) == 0 ) 
			{  
	                      	fclose(fpRead);
		              	return(DataFormatErr);
	                }	    
			      /** X Position **/
			pntFirstDie.sXpos = atoi(stTok);
			pntFirstDie.sXpos = 30;   /* fix First Die Position(30) for Reference die */  
			nTemp_X = atoi(stTok);
		}
		if(nCount == 3) 
		{
		                   /** Data Validation **/
		        if (stTok[0] != '0' && atoi(stTok) == 0 ) 
			{  
	                      	fclose(fpRead);
		              	return(DataFormatErr);
	                }	    
			      /** Y Position **/
			pntFirstDie.sYpos = atoi(stTok);
			pntFirstDie.sYpos = 30;   /* fix First Die Position(30) for Reference die */  
			nTemp_Y = atoi(stTok);
		}
		if(nCount == 5)  
		{
		                   /** Data Validation **/
		        if (stTok[0] != '0' && atoi(stTok) == 0 ) 
			{  
	                      fclose(fpRead);
		              return(DataFormatErr);
	                }	    
			      /** Bin Flag  **/
			cTempBin = cCheckGoodBin(stGoodBinFlag, atoi(stTok));
#ifdef _DEBUG_MODE
	                printf("BIN[%d]==> [%c]\n",atoi(stTok),cTempBin);
#endif
        	}
		nCount++;
	} /* end of while */
	if( nCount < 6 ) 
	{    /* Good Bin flag don't exist */
	        fclose(fpRead);
		return (DataFormatErr);
        }
#ifdef _DEBUG_MODE
	printf("First Die(%d,%d) = %c\n", pntFirstDie.sXpos, pntFirstDie.sYpos, cTempBin);
	printf("nTemp(X,Y) : (%d,%d)\n", nTemp_X, nTemp_Y);
#endif
	nMax_X = nMin_X = nTemp_X;
	nMax_Y = nMin_Y = nTemp_Y;

	nGoodBinCount = 0;


	
		/* Wirte First Die Bin to bin temp array */
	stBinArray[nTemp_X][nTemp_Y] = cTempBin;
	if(cTempBin == BIN1)  nGoodBinCount++;
/*
    if(cTempBin == BIN2 && gnBin11toBin2 == 1  ) 
        nGoodBinCount++;
*/
	while( !feof(fpRead) ) 
	{
		fpOffsetEow1 = ftell(fpRead);
		memset(stBuff, '\0', 256);
		fgets(stBuff, 256, fpRead);
		if( feof(fpRead) ) break;
		stTok = strtok(stBuff, DELIMITER4);
		nCount = 1;
		if( !memcmp(stTok, "E", 1) ) 
		{
			fseek(fpRead, 0L, SEEK_END);
	   	} 
		else if( !memcmp(stTok, "X", 1)) 
		{
			while( (stTok = strtok(NULL, DELIMITER4)) != NULL ) 
			{
			            /** X Position **/
				if(nCount == 1) 
				{
		                	/** Data Validation **/
		                        if (stTok[0] != '0' && atoi(stTok) == 0 ) 
					{  
	                                	fclose(fpRead);
		                                return(DataFormatErr);
	                                }	    
					nTemp_X = atoi(stTok);
                                }
			           /** Y Position **/
				if(nCount == 3) 
				{
		                        /** Data Validation **/
		                        if (stTok[0] != '0' && atoi(stTok) == 0 ) 
					{  
	                                	fclose(fpRead);
		                        	return(DataFormatErr);
	                                }	    
					nTemp_Y = atoi(stTok);
                                }
			            /** Bin Flag **/
				if(nCount == 5) 
				{
				      /** Data Validation **/
					if (stTok[0] != '0' && atoi(stTok) == 0 ) 
					{  
					         fclose(fpRead);
					         return(DataFormatErr);
					}	    
					cTempBin = cCheckGoodBin(stGoodBinFlag, atoi(stTok) );
					if(cTempBin == BIN1)  nGoodBinCount++;
/*
                    if(cTempBin == BIN2 && gnBin11toBin2 == 1  )  
                        nGoodBinCount++;
*/
                    #ifdef _DEBUG_MODE
	                    printf("BIN[%d]==> [%c]\n",atoi(stTok),cTempBin);
                    #endif
				}
					nCount++;
			} /* end of while( (stTok = strtok(NULL, DELIMITER4)) != NULL) */
			if( nCount < 6 )  
			{   /* Good Bin flag don't exist */
	                	fclose(fpRead);
				return (DataFormatErr);
                        }
			nMin_X = (nTemp_X < nMin_X ? nTemp_X : nMin_X); 
			nMin_Y = (nTemp_Y < nMin_Y ? nTemp_Y : nMin_Y); 
			nMax_X = (nTemp_X > nMax_X ? nTemp_X : nMax_X); 
			nMax_Y = (nTemp_Y > nMax_Y ? nTemp_Y : nMax_Y); 
			stBinArray[nTemp_X][nTemp_Y] = cTempBin;
		}  /* end of if( !memcmp(stTok, "X", 1) ) */
	}  /* end of while( !feof(fpRead) ) */

		/* Get Edge Dies */
	fseek(fpRead, (fpOffset - fpOffsetEow2), SEEK_END);
        while(stBuff[0] != 'E') 
	{
                memset(stBuff, '\0', 256);
                fgets(stBuff, 256, fpRead);
        }  /* end of while */
	while( !feof(fpRead) ) 
	{
		memset(stBuff, '\0', 256);
		fgets(stBuff, 256, fpRead);
		if( feof(fpRead) ) break;
		stTok = strtok(stBuff, DELIMITER4);
		nCount = 1;
		if( !memcmp(stTok, "E", 1) ) 
		{
			fpOffset = ftell(fpRead);
			fseek(fpRead, 0L, SEEK_END);
		} 
		else if( !memcmp(stTok, "X", 1) ) 
		{
			while( (stTok = strtok(NULL, DELIMITER4)) != NULL ) 
			{ 
			        /** X Position **/
				if(nCount == 1) 
				{
		                           /** Data Validation **/
		                	if (stTok[0] != '0' && atoi(stTok) == 0 ) 
					{  
	                                                 fclose(fpRead);
		                                         return(DataFormatErr);
	                                }	    
					nTemp_X = atoi(stTok);
                                }
			        /** Y Position **/
				if(nCount == 3) 
				{
		                           /** Data Validation **/
		               		if (stTok[0] != '0' && atoi(stTok) == 0 ) 
					{  
	                                	fclose(fpRead);
		                                return(DataFormatErr);
	                                }	    
					nTemp_Y = atoi(stTok);
                                }  
                                /** Bin Flag **/
				if(nCount == 5)
					cTempBin = EDGE_BIN;
				nCount++;	
			}  /* end of while(stTok = strtok(NULL, DELIMITER) ... */
			nMin_X = (nTemp_X < nMin_X ? nTemp_X : nMin_X); 
			nMin_Y = (nTemp_Y < nMin_Y ? nTemp_Y : nMin_Y); 
			nMax_X = (nTemp_X > nMax_X ? nTemp_X : nMax_X); 
			nMax_Y = (nTemp_Y > nMax_Y ? nTemp_Y : nMax_Y); 
			stBinArray[nTemp_X][nTemp_Y] = cTempBin;
		}  /* end of if( !memcmp(stTok, "X", 1) ) */
	}  /* end of while( !feof(fpRead) ) */
#ifdef _DEBUG_MODE
	printf("Min_X[%d], Min_Y[%d], Max_X[%d], Max_Y[%d]\n", nMin_X, nMin_Y, nMax_X, nMax_Y);
	printf("Map Data .....\n");
	for (nLoopRow = nMin_Y; nLoopRow <= nMax_Y; nLoopRow++)  
	{
		for (nLoopCol = nMin_X; nLoopCol <= nMax_X; nLoopCol++) 
		{
			printf(" %c ", stBinArray[nLoopCol][nLoopRow]);
		}
		printf("\n");
	}
#endif
		/* write Bin data to MapBody */ 
	nCount = 0;
	for(nLoopRow = nMin_Y; nLoopRow <= nMax_Y; nLoopRow++) 
	{
		for(nLoopCol = nMin_X; nLoopCol <= nMax_X; nLoopCol++) 
		{
			MapBody.stBINLT[nCount] =  stBinArray[nLoopCol][nLoopRow];
			nCount++;
		}
	}

	MapBody.REFP1.sXpos = pntFirstDie.sXpos - nMin_X;
	MapBody.REFP1.sYpos = (pntFirstDie.sYpos - nMax_Y) * -1;
	MapBody.uROWCT = (nMax_Y - nMin_Y) + 1;
	MapBody.uCOLCT = (nMax_X - nMin_X) + 1;
	MapBody.uPDRCT =  nGoodBinCount;
	MapBody.STRP.sXpos = 0;
	MapBody.STRP.sYpos = 0;
#ifdef _DEBUG_MODE
	printf("Map Body Bin List[%s]\n",MapBody.stBINLT);
	printf("Reference Die Position(X, Y): (%d, %d)\n", MapBody.REFP1.sXpos, MapBody.REFP1.sYpos);
	printf("Row Count : %d\n", MapBody.uROWCT);
	printf("Column Count : %d\n", MapBody.uCOLCT);
	printf("Good Die Count : %d\n", MapBody.uPDRCT);
	printf("Start Position(X, Y): (%d, %d)\n", MapBody.STRP.sXpos, MapBody.STRP.sYpos);
#endif
	fclose(fpRead);
	memset(gsPartNo, 0x00, sizeof(gsPartNo));
    	strcpy(gsPartNo, stPartId);
		/* Insert Map data into DB Table */
	nErrorCode = nInsertDb(&MapBody, stPartId);
	if(nErrorCode != EXE_OK) 
	{
	       	if (nErrorCode == MapRotationErr) 
		{
			#ifdef _DEBUG_MODE
				printf("Map Data Rotation Error!!  ErrorCode=[%d]\n", nErrorCode);
			#endif
			return (MapRotationErr);
               	} 
		else 
		{
			#ifdef _DEBUG_MODE
				printf("Data Inserting Error With sqlcode=[%d]\n", nErrorCode);
			#endif
                	sprintf(stErrorCode,"ORACLE ERROR: %d", nErrorCode);
			Error_Log(InsertErr, stErrorCode);
			return (InsertErr);
		}
	}/** end of if(nErrorCode != EXE_OK)... **/		
/*
	nErrorCode = nInsertHalfInfo(MapBody.stMID, MapBody.stRUN_ID,nGoodBinCount, gnBin_SecondCnt, nGoodBinCount+gnBin_SecondCnt, gsPartNo);
*/
	return (InsertGood);    /* Succeed Inserting DB */ 

} /* end of MapCvt_Insert() */



char cCheckGoodBin(stGoodBinFlag, nBin)
char stGoodBinFlag[16];
int nBin;
{
	unsigned int lData;
	char stHBin[32];
	char stLBin[32];

	if ( nBin < 33 )
	{
		lData = strtoul(stGoodBinFlag, (char **)NULL, 16);
		
		 /* 2007.06.21 28.29 bin count */
/*
        if (nBin == 28 || nBin == 29)
        {
           gnBin_SecondCnt = gnBin_SecondCnt + 1;
        }
*/
         /* 2007.06.21 28.29 bin count */


		lData = lData >> (nBin - 1);
		if(lData & 0x00000001) 
		{
/*
            if (nBin == 11 && gnBin11toBin2 == 1) 
            {            
                return (BIN2);
            }
*/
			return(BIN1);  		/* if Good Bin */
		}
/*
		if (nBin == 28 || nBin == 29 )
		{
			return(BIN2);
		}
*/
 	       /* modified by msyun 98/11/04 for dividing DUMMY_BIN from defects */
        	lData = strtoul(DC_FAIL_FLAG, (char **)NULL, 16);

 	       lData = lData >> (nBin - 1);
        	if(lData & 0x00000001)  
		{
           		return(DUMMY_BIN);  /* if DC_FAIL Bin */
        	}
	}

        /* Added by stainles 98/12/10 for dividing POST LASER FAIL BIN */
	/* modified 98/01/07                                           */
	memset(stHBin, '\0', 32);
	memset(stLBin, '\0', 32);
	memcpy(stHBin, EDGE_BIN_FLAG, 8);
	memcpy(stLBin, EDGE_BIN_FLAG+8, 8);

	if(nBin < 33) 
	{
			/* Do Low 8 bytes */
        	lData = strtoul(stLBin, (char **)NULL, 16);

        	lData = lData >> (nBin - 1);
        	if(lData & 0x00000001)  
		{
           		return(EDGE_BIN);  /* if Post laser fail Bin... */
		}
	} 
	else 
	{
        	lData = strtoul(stHBin, (char **)NULL, 16);

        	lData = lData >> (nBin - 1 - 32);
        	if(lData & 0x00000001)  
		{
           		return(EDGE_BIN);  /* if Post laser fail Bin... */
		}
	}   /* end of if (nBin < 33) ... else .... */

        return(DEFECT_BIN);                   /* if Reject Bin */

}


