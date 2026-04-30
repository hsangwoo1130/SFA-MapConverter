
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[12];
};
static struct sqlcxp sqlfpn =
{
    11,
    "InsertDB.pc"
};


static unsigned int sqlctx = 154731;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[32];
   unsigned long  sqhstl[32];
            int   sqhsts[32];
            short *sqindv[32];
            int   sqinds[32];
   unsigned long  sqharm[32];
   unsigned long  *sqharc[32];
   unsigned short  sqadto[32];
   unsigned short  sqtdso[32];
} sqlstm = {12,32};

/* SQLLIB Prototypes */
extern sqlcxt ( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlcx2t( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlbuft( void **, char * );
extern sqlgs2t( void **, char * );
extern sqlorat( void **, unsigned int *, void * );

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem( unsigned char *, signed int * );

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,840,0,0,
5,0,0,0,0,0,27,83,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,
36,0,0,2,67,0,4,262,0,0,1,0,0,1,0,2,9,0,0,
55,0,0,3,498,0,3,272,0,0,32,32,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,
0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
198,0,0,4,334,0,5,353,0,0,21,21,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
297,0,0,5,0,0,30,391,0,0,0,0,0,1,0,
312,0,0,6,83,0,4,426,0,0,4,1,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,1,97,0,0,
343,0,0,7,87,0,3,431,0,0,1,1,0,1,0,1,97,0,0,
362,0,0,8,83,0,4,438,0,0,4,1,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,1,97,0,0,
393,0,0,0,0,0,27,683,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,
424,0,0,10,67,0,4,752,0,0,1,0,0,1,0,2,97,0,0,
443,0,0,11,62,0,4,769,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
466,0,0,12,112,0,5,778,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
501,0,0,13,133,0,3,782,0,0,5,5,0,1,0,1,9,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
536,0,0,14,0,0,29,790,0,0,0,0,0,1,0,
551,0,0,15,0,0,30,791,0,0,0,0,0,1,0,
566,0,0,0,0,0,27,813,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,
597,0,0,17,68,0,4,834,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
620,0,0,18,114,0,3,841,0,0,6,6,0,1,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
9,0,0,
659,0,0,19,128,0,5,847,0,0,6,6,0,1,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,
9,0,0,
698,0,0,20,0,0,30,858,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <string.h>
#include "Map_data_task.h"
/*
#include "global.h"
#include "messages.h"
*/

/* define for InsertLog function */
#define DELIMITER "=\n"

#define LPCTSTR         char *

/* EXEC SQL INCLUDE sqlca.h;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */


/* EXEC SQL BEGIN DECLARE SECTION; */ 

  /* VARCHAR	username[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } username;

  /* VARCHAR	passwd[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } passwd;


  /* VARCHAR       stWAFER_ID[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } stWAFER_ID;
 /* WAFER_ID*/
  /* VARCHAR       cIDTYP[1]; */ 
struct { unsigned short len; unsigned char arr[1]; } cIDTYP;
   /* ID TYPE*/
  /* VARCHAR       cMAPFT[1]; */ 
struct { unsigned short len; unsigned char arr[1]; } cMAPFT;
   /* MAP FORMAT*/
  int           nFNLOC;      /* FLAT ZONE LOCATION */
  int           nFFROT;      /* FILM FRAME ROTATION */
  /* VARCHAR       cORLOC[1]; */ 
struct { unsigned short len; unsigned char arr[1]; } cORLOC;
      /* ORIGIN LOCATION */
  /* VARCHAR       cPRAXI[1]; */ 
struct { unsigned short len; unsigned char arr[1]; } cPRAXI;
      /* PROCESS AXIS */
  /* VARCHAR       stBCEQU[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } stBCEQU;
  /* BIN CATEGORY */
  /* VARCHAR       stNULBC[1]; */ 
struct { unsigned short len; unsigned char arr[1]; } stNULBC;
   /* EMPTY DIES NOTATION */
  int           nRPSEL;      /* COUNT OF REFERENCE DIES */
  int           nREFP1_X;    /* X POSITION OF REFERENCE DIE#1 */
  int           nREFP1_Y;    /* Y POSITION OF REFERENCE DIE#1 */
  int           nREFP2_X;    /* X POSITION OF REFERENCE DIE#2 */
  int           nREFP2_Y;    /* Y POSITION OF REFERENCE DIE#2 */
  int           nREFP3_X;    /* X POSITION OF REFERENCE DIE#3 */
  int           nREFP3_Y;    /* Y POSITION OF REFERENCE DIE#3 */
  int           nREFP4_X;    /* X POSITION OF REFERENCE DIE#4 */
  int           nREFP4_Y;    /* Y POSITION OF REFERENCE DIE#4 */
  int           nROWCT;      /* ROW DIES COUNT */
  int           nCOLCT;      /* COLUMN DIES COUNT */
  int           nPDRCT;      /* BIN SUM COUNT OF BCEQU BINS */
  int           nSTRP_X;     /* X POSITION OF START DIE */
  int           nSTRP_Y;     /* Y POSITION OF START DIE */
  /* VARCHAR       stBIN_LIST[160000]; */ 
struct { unsigned short len; unsigned char arr[160000]; } stBIN_LIST;
 /* BIN LIST */
  /* VARCHAR       cMAPER[1]; */ 
struct { unsigned short len; unsigned char arr[1]; } cMAPER;
       /* MAP ERROR CODE */
  int           nDATLC;       /* LOCATION OF ERROR */
  /* VARCHAR       stRECV_TIME[14]; */ 
struct { unsigned short len; unsigned char arr[14]; } stRECV_TIME;
   /* WAFER RECEIVED TIME to YHS1 */
  /* VARCHAR       stSTART_TIME[14]; */ 
struct { unsigned short len; unsigned char arr[14]; } stSTART_TIME;
  /* START TIME FOR DIE BONDING */
  /* VARCHAR       stFINISH_TIME[14]; */ 
struct { unsigned short len; unsigned char arr[14]; } stFINISH_TIME;
 /* WAFER FINISH TIME FOR DIE BONDING */
  /* VARCHAR       stWORK_FINISHED[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } stWORK_FINISHED;
 /* WORK FINISHED FLAG */
  /* VARCHAR       stRECORD_INSERTED[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } stRECORD_INSERTED;
 /* RECORD_INSERTED */
  /* VARCHAR       stRECORD_UPDATED[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } stRECORD_UPDATED;
 /* RECORD_UPDATED */

  /* Host variables for map rotating function */
  /* VARCHAR      stPartId[32]; */ 
struct { unsigned short len; unsigned char arr[32]; } stPartId;

  int          nFFROT;
  int          nFNLOC;
  int          nORLOC;

  /* Added two variables for run-sheet by msyun 98/10/28 */
  /* VARCHAR       stRUN_ID[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } stRUN_ID;
 /* WAFER_ID*/
  int           nNET_DIE_CNT;      /* BIN SUM COUNT OF BCEQU BINS */

/* EXEC SQL END DECLARE SECTION; */ 

  
int nInsertDb(mbMapBody,stPartId)
MAP_BODY *mbMapBody;
char *stPartId;
{


    int nCount;
    char stTemp[20];
    char stBIN_LIST_Before[160000];
    int  nBIN_LIST_Len;
    int  nRotatingTimes;
    int  nMapCompare;
    int nTemp;


    /* Set local Data Base descriptions and connect*/
    username.len = sprintf((LPCTSTR)username.arr,"inkless");
    passwd.len = sprintf((LPCTSTR)passwd.arr,"inkless");
    /* EXEC SQL CONNECT :username IDENTIFIED BY :passwd ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&username;
    sqlstm.sqhstl[0] = (unsigned long )22;
    sqlstm.sqhsts[0] = (         int  )22;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&passwd;
    sqlstm.sqhstl[1] = (unsigned long )22;
    sqlstm.sqhsts[1] = (         int  )22;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if(sqlca.sqlcode != 0) {
#ifdef _DEBUG_MODE
       printf("DATA BASE CONNECTION ERROR [%d]\n",sqlca.sqlcode);
#endif
       return(sqlca.sqlcode);
    }
#ifdef _DEBUG_MODE
    printf("DATA BASE  CONNECTION COMPLETED!\n");
#endif


    /* Rotate MAP_BODY(NO ERROR EXCEPTION) */
    /* 
       Have no return values, means can ignore rotating error 
       If error occured during rotating map, original map data
       will be inserted, and query function can rotate this map
       correctly, using equipment setting values(FFROT,FNLOC,ORLOC) 
    */
#ifdef _DEBUG_MODE
    printf("ROTATEMAPBODY START\n");
#endif
            /*************
	      Check Map Rotation Work
	      Added by stainles. 2000.03.23
             *************/
    memset(stBIN_LIST_Before, '\0', sizeof(stBIN_LIST_Before));
    memcpy(stBIN_LIST_Before, mbMapBody->stBINLT, strlen(mbMapBody->stBINLT));
    nBIN_LIST_Len = strlen(stBIN_LIST_Before);

    nRotatingTimes = RotateMapBody(mbMapBody,stPartId);

	 /******
	     If Map Rotation Work is wrong 
	     It will return MapRotationErr Flag  
	  *********/
    nMapCompare = memcmp(stBIN_LIST_Before,mbMapBody->stBINLT,nBIN_LIST_Len);

#ifdef _DEBUG_MODE
    printf("nRotatinTimes = [%d] \n", nRotatingTimes);
    printf("nMapCompare = [%d] \n", nMapCompare);
#endif

    if(nRotatingTimes != 0 && nMapCompare == 0) {
#ifdef _DEBUG_MODE
                printf("MAP ROTATING FAIL I \n");
#endif
		return (MapRotationErr);
    }

    if(nMapCompare != 0 && nRotatingTimes == 0 ) {
#ifdef _DEBUG_MODE
                printf("MAP ROTATING FAIL II \n");
#endif
		return (MapRotationErr);
    }

#ifdef _DEBUG_MODE
    printf("ROTATEMAPBODY COMPLETED\n");
#endif

    /* Initialize all host variables for remove all gabages */ 
    memset(stWAFER_ID.arr,'\0',20);
    memset(cIDTYP.arr,'\0',1);
    memset(cMAPFT.arr,'\0',1);
    memset(cORLOC.arr,'\0',1);
    memset(cPRAXI.arr,'\0',1);
    nFNLOC = nFFROT =  0;
    memset(stBCEQU.arr,'\0',10);
    memset(stNULBC.arr,'\0',1);
    nRPSEL = nREFP1_X = nREFP1_Y = nREFP2_X = nREFP2_Y = nREFP3_X = 0;
    nREFP3_Y = nREFP4_X = nREFP4_Y = nROWCT = nCOLCT = 0;
    nPDRCT = nSTRP_X = nSTRP_Y = 0;
    memset(stBIN_LIST.arr,'\0',160000);
    memset(cMAPER.arr,'\0',1);
    nDATLC = 0;
    memset(stRECV_TIME.arr,'\0',14);
    memset(stSTART_TIME.arr,'\0',14);
    memset(stFINISH_TIME.arr,'\0',14);
    memset(stWORK_FINISHED.arr,'\0',2);
    memset(stRECORD_INSERTED.arr,'\0',2);
    memset(stRECORD_UPDATED.arr,'\0',2);


    /*
    []-------------------------------------------------------------[]
      Setting all host variables for Inserting using imsgMsg data 
    []-------------------------------------------------------------[]
    */
    
    /* Set WAFER_ID */
    stWAFER_ID.len = sprintf((LPCTSTR)stWAFER_ID.arr,mbMapBody->stMID);

    /* Set IDTYP */
    cIDTYP.arr[0] = mbMapBody->cIDTYP;
    cIDTYP.len = 1;

    /* Set MAPFT */
    cMAPFT.arr[0] = mbMapBody->cMAPFT;
    cMAPFT.len = 1;

    /* Set FNLOC */
    nFNLOC = mbMapBody->uFNLOC;

    /* Set FFROT */
    nFFROT = mbMapBody->uFFROT;

    /* Set ORLOC */
    cORLOC.arr[0] = mbMapBody->cORLOC;
    cORLOC.len = 1;

    /* Set PRAXI */
    cPRAXI.arr[0] = mbMapBody->cPRAXI;
    cPRAXI.len = 1;

    /* Set BCEQU */
    stBCEQU.len = sprintf((LPCTSTR)stBCEQU.arr,mbMapBody->stBCEQU);

    /* Set NULBC */
    stNULBC.arr[0] = mbMapBody->cNULBC;
    stNULBC.len = 1;

    /* Set RPSEL */
    nRPSEL = mbMapBody->uRPSEL;

    /* Set REFP1_X */
    nREFP1_X = mbMapBody->REFP1.sXpos;

    /* Set REFP1_Y */
    nREFP1_Y = mbMapBody->REFP1.sYpos;

    /* Set REFP2_X */
    nREFP2_X = mbMapBody->REFP2.sXpos;

    /* Set REFP2_Y */
    nREFP2_Y = mbMapBody->REFP2.sYpos;

    /* Set REFP3_X */
    nREFP3_X = mbMapBody->REFP3.sXpos;

    /* Set REFP3_Y */
    nREFP3_Y = mbMapBody->REFP3.sYpos;

    /* Set REFP4_X */
    nREFP4_X = mbMapBody->REFP4.sXpos;

    /* Set REFP4_Y */
    nREFP4_Y = mbMapBody->REFP4.sYpos;

    /* Set ROWCT */
    nROWCT = mbMapBody->uROWCT;

    /* Set COLCT */
    nCOLCT = mbMapBody->uCOLCT;

    /* Set PDRCT */
    nPDRCT = mbMapBody->uPDRCT;

    /* Set STRP_X */
    nSTRP_X = mbMapBody->STRP.sXpos;

    /* Set STRP_Y */
    nSTRP_Y = mbMapBody->STRP.sYpos;

    /* Set BINLIST */
    memcpy(stBIN_LIST.arr,mbMapBody->stBINLT,strlen(mbMapBody->stBINLT));
    stBIN_LIST.len = strlen((LPCTSTR)stBIN_LIST.arr);

    /* Set MAPER */
    cMAPER.arr[0] = mbMapBody->cMAPER;
    cMAPER.len = 1;

    /* Modified for run_sheet by msyun 98/10/18 */
    /* Set NET_DIE_CNT */
    nNET_DIE_CNT = mbMapBody->uNET_DIE_CNT;

    /* Set RUN_ID */
    stRUN_ID.len = sprintf((LPCTSTR)stRUN_ID.arr,mbMapBody->stRUN_ID);

    /* EXEC SQL SELECT TO_CHAR(SYSDATE, 'yyyymmddhh24miss') NOW
	       INTO :stRECV_TIME
	     FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TO_CHAR(SYSDATE,'yyyymmddhh24miss') NOW into :b0 \
 from DUAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )36;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&stRECV_TIME;
    sqlstm.sqhstl[0] = (unsigned long )16;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    memset(stRECORD_INSERTED.arr,'\0',2);
    memset(stRECORD_UPDATED.arr,'\0',2);
    stRECORD_INSERTED.len = sprintf((LPCTSTR)stRECORD_INSERTED.arr,"%s",RECORD_INSERTED);
    stRECORD_UPDATED.len = sprintf((LPCTSTR)stRECORD_UPDATED.arr,"%s",RECORD_MATCHED);
    memset(stWORK_FINISHED.arr,'\0',2);


    /* EXEC SQL INSERT INTO WAFER_MAP_HITACHI (
           WAFER_ID,
           IDTYP,
           MAPFT,
           FNLOC,
           FFROT,
           ORLOC,
           PRAXI,
           BCEQU,
           NULBC,
           RPSEL,
           REFP1_X,
           REFP1_Y,
           REFP2_X,
           REFP2_Y,
           REFP3_X,
           REFP3_Y,
           REFP4_X,
           REFP4_Y,
           ROWCT,
           COLCT,
           PDRCT,
           STRP_X,
           STRP_Y,
           BIN_LIST,
           MAPER,
           DATLC,
           RECV_TIME,
           RECORD_INSERTED,
           RECORD_UPDATED,
           UPDATE_TIME,
           /o Modified for run_sheet by msyun 98/10/18 o/
	   RUN_ID,NET_DIE_CNT
	 ) VALUES (
           :stWAFER_ID,
           :cIDTYP,
           :cMAPFT,
           :nFNLOC,
           :nFFROT,
           :cORLOC,
           :cPRAXI,
           :stBCEQU,
           :stNULBC,
           :nRPSEL,
           :nREFP1_X,
           :nREFP1_Y,
           :nREFP2_X,
           :nREFP2_Y,
           :nREFP3_X,
           :nREFP3_Y,
           :nREFP4_X,
           :nREFP4_Y,
           :nROWCT,
           :nCOLCT,
           :nPDRCT,
           :nSTRP_X,
           :nSTRP_Y,
           :stBIN_LIST,
           :cMAPER,
           :nDATLC,
           TO_DATE(:stRECV_TIME,'yyyymmddhh24miss'),
           :stRECORD_INSERTED,
           :stRECORD_UPDATED,
           TO_DATE(:stRECV_TIME,'yyyymmddhh24miss'),
           /o Modified for run_sheet by msyun 98/10/18 o/
	   :stRUN_ID,:nNET_DIE_CNT
	 ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 32;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into WAFER_MAP_HITACHI (WAFER_ID,IDTYP,MAPFT,FNLO\
C,FFROT,ORLOC,PRAXI,BCEQU,NULBC,RPSEL,REFP1_X,REFP1_Y,REFP2_X,REFP2_Y,REFP3_X\
,REFP3_Y,REFP4_X,REFP4_Y,ROWCT,COLCT,PDRCT,STRP_X,STRP_Y,BIN_LIST,MAPER,DATLC\
,RECV_TIME,RECORD_INSERTED,RECORD_UPDATED,UPDATE_TIME,RUN_ID,NET_DIE_CNT) val\
ues (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b\
16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,TO_DATE(:b26,'yyyymmddhh24mis\
s'),:b27,:b28,TO_DATE(:b26,'yyyymmddhh24miss'),:b30,:b31)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )55;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&stWAFER_ID;
    sqlstm.sqhstl[0] = (unsigned long )22;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&cIDTYP;
    sqlstm.sqhstl[1] = (unsigned long )3;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&cMAPFT;
    sqlstm.sqhstl[2] = (unsigned long )3;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&nFNLOC;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&nFFROT;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&cORLOC;
    sqlstm.sqhstl[5] = (unsigned long )3;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&cPRAXI;
    sqlstm.sqhstl[6] = (unsigned long )3;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&stBCEQU;
    sqlstm.sqhstl[7] = (unsigned long )12;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&stNULBC;
    sqlstm.sqhstl[8] = (unsigned long )3;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&nRPSEL;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)&nREFP1_X;
    sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&nREFP1_Y;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)&nREFP2_X;
    sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&nREFP2_Y;
    sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)&nREFP3_X;
    sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)&nREFP3_Y;
    sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)&nREFP4_X;
    sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         short *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (unsigned char  *)&nREFP4_Y;
    sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         short *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (unsigned char  *)&nROWCT;
    sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         short *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (unsigned char  *)&nCOLCT;
    sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         short *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (unsigned char  *)&nPDRCT;
    sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         short *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (unsigned char  *)&nSTRP_X;
    sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         short *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned long )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (unsigned char  *)&nSTRP_Y;
    sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         short *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned long )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (unsigned char  *)&stBIN_LIST;
    sqlstm.sqhstl[23] = (unsigned long )160002;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         short *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned long )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (unsigned char  *)&cMAPER;
    sqlstm.sqhstl[24] = (unsigned long )3;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         short *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned long )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (unsigned char  *)&nDATLC;
    sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         short *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned long )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (unsigned char  *)&stRECV_TIME;
    sqlstm.sqhstl[26] = (unsigned long )16;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         short *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned long )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (unsigned char  *)&stRECORD_INSERTED;
    sqlstm.sqhstl[27] = (unsigned long )4;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         short *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned long )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (unsigned char  *)&stRECORD_UPDATED;
    sqlstm.sqhstl[28] = (unsigned long )4;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         short *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned long )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (unsigned char  *)&stRECV_TIME;
    sqlstm.sqhstl[29] = (unsigned long )16;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         short *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned long )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (unsigned char  *)&stRUN_ID;
    sqlstm.sqhstl[30] = (unsigned long )22;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         short *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned long )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (unsigned char  *)&nNET_DIE_CNT;
    sqlstm.sqhstl[31] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         short *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned long )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if(sqlca.sqlcode != 0)
      {
	/**** Dont care for manual inserted data */
	/**** Except Duplicate Error  */
        if(sqlca.sqlcode != -1) {
#ifdef _DEBUG_MODE
	   printf("Error Insert [%d]\n",sqlca.sqlcode);
#endif
	   return(sqlca.sqlcode);
	 }
	     /** Modified by stainles 2000/1/10 **/
	     /** FNLOC, FFROT, ORLOC, RPSEL, REFP, **/
	     /** ROWCT, COLCT, PDRCT .. are updated too **/
	 /* EXEC SQL UPDATE WAFER_MAP_HITACHI
	    SET FNLOC = :nFNLOC,
	        FFROT = :nFFROT,
	        ORLOC = :cORLOC,
		RPSEL = :nRPSEL,
		REFP1_X = :nREFP1_X,
		REFP1_Y = :nREFP1_Y,
		REFP2_X = :nREFP2_X,
		REFP2_Y = :nREFP2_Y,
		REFP3_X = :nREFP3_X,
		REFP3_Y = :nREFP3_Y,
		REFP4_X = :nREFP4_X,
		REFP4_Y = :nREFP4_Y,
		ROWCT = :nROWCT,
		COLCT = :nCOLCT,
		PDRCT = :nPDRCT,
		STRP_X = :nSTRP_X,
		STRP_Y = :nSTRP_Y,
		BIN_LIST = :stBIN_LIST,
                RUN_ID = :stRUN_ID,           /o Modified by stainles 98/12/02 o/
                UPDATE_TIME = TO_DATE(:stRECV_TIME,'yyyymmddhh24miss'),
		RECORD_UPDATED = '1'
            WHERE WAFER_ID = :stWAFER_ID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 32;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update WAFER_MAP_HITACHI  set FNLOC=:b0,FFROT=:b1,ORLOC=:b\
2,RPSEL=:b3,REFP1_X=:b4,REFP1_Y=:b5,REFP2_X=:b6,REFP2_Y=:b7,REFP3_X=:b8,REFP3\
_Y=:b9,REFP4_X=:b10,REFP4_Y=:b11,ROWCT=:b12,COLCT=:b13,PDRCT=:b14,STRP_X=:b15\
,STRP_Y=:b16,BIN_LIST=:b17,RUN_ID=:b18,UPDATE_TIME=TO_DATE(:b19,'yyyymmddhh24\
miss'),RECORD_UPDATED='1' where WAFER_ID=:b20";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )198;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&nFNLOC;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&nFFROT;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&cORLOC;
  sqlstm.sqhstl[2] = (unsigned long )3;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&nRPSEL;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&nREFP1_X;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&nREFP1_Y;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&nREFP2_X;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&nREFP2_Y;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&nREFP3_X;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&nREFP3_Y;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&nREFP4_X;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&nREFP4_Y;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&nROWCT;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&nCOLCT;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&nPDRCT;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&nSTRP_X;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&nSTRP_Y;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&stBIN_LIST;
  sqlstm.sqhstl[17] = (unsigned long )160002;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&stRUN_ID;
  sqlstm.sqhstl[18] = (unsigned long )22;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&stRECV_TIME;
  sqlstm.sqhstl[19] = (unsigned long )16;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&stWAFER_ID;
  sqlstm.sqhstl[20] = (unsigned long )22;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

 
        if(sqlca.sqlcode != 0) {
#ifdef _DEBUG_MODE
	   printf("RECORD EXIST --> UPDATE Error [%d]\n",sqlca.sqlcode);
#endif
	   return(sqlca.sqlcode);
	 }
#ifdef _DEBUG_MODE
	   printf("RECOED EXIST==> UPDATED!!\n");
#endif
       }


#ifdef _DEBUG_MODE
    printf("INSERT COMPLETED \n");
#endif
    /* EXEC SQL COMMIT WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 32;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )297;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    return(EXE_OK);
}

int RotateMapBody(mbMapBody,stPartId)
MAP_BODY *mbMapBody;
char *stPartId;
{
    MAP_BODY mbTemp;
    int      nRotatingTimes;
    int      nRotatingDegree;
    int      nCount;
    int      nTemp;
    int      nEdsRowCt;
    int      nEdsColCt;
    POINT    pntTemp;
    char     stTempArray[600][600];
    char     stRotatedArray[600][600];
    int      nLoopCol;
    int      nLoopRow;
    POINT    pntCENTER;
    POINT    pntORG_QUAD1;
    POINT    pntORG_QUAD2;
    POINT    pntORG_QUAD3;
    POINT    pntORG_QUAD4;
    POINT    pntREFPvsCENTER;

    /* Copy MAP_BODY for handling temporary 
       for preparing situation for error occured,
       if error occured, do not modity original MAPBODY 
    */
    memset(&mbTemp,'\0',sizeof(MAP_BODY));
    memcpy(&mbTemp,mbMapBody,sizeof(MAP_BODY));

    /* EXEC SQL SELECT FNLOC, FFROT, ORLOC into :nFNLOC, :nFFROT, :nORLOC
		FROM MAPROTATION_REF WHERE PART_ID = :stPartId; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 32;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select FNLOC ,FFROT ,ORLOC into :b0,:b1,:b2  from MAPROT\
ATION_REF where PART_ID=:b3";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )312;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&nFNLOC;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&nFFROT;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&nORLOC;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)stPartId;
    sqlstm.sqhstl[3] = (unsigned long )0;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



   if(sqlca.sqlcode != 0) {
      printf("Can't Read reference information partid[%s] with[%d]\n",stPartId,sqlca.sqlcode);
      /* EXEC SQL INSERT INTO MAPROTATION_REF
	    (PART_ID,FNLOC,FFROT,ORLOC,UPDATED)
	    VALUES (
	       :stPartId,180,90,4,1); */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 32;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "insert into MAPROTATION_REF (PART_ID,FNLOC,FFROT,ORLOC\
,UPDATED) values (:b0,180,90,4,1)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )343;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)stPartId;
      sqlstm.sqhstl[0] = (unsigned long )0;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


      if(sqlca.sqlcode != 0) {
         printf("Can't Insert reference information partid[%s] with[%d]\n",stPartId,sqlca.sqlcode);
      }
    /* EXEC SQL SELECT FNLOC,FFROT,ORLOC
	 INTO  :nFNLOC,:nFFROT,:nORLOC
	 FROM MAPROTATION_REF
	 WHERE PART_ID = :stPartId; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 32;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select FNLOC ,FFROT ,ORLOC into :b0,:b1,:b2  from MAPROT\
ATION_REF where PART_ID=:b3";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )362;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&nFNLOC;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&nFFROT;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&nORLOC;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)stPartId;
    sqlstm.sqhstl[3] = (unsigned long )0;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   }
   /********************************temporary blocked 
   if(sqlca.sqlcode != 0) {
#ifdef _DEBUG_MODE
       printf("Can't Read reference information partid[%s]\n",stPartId);
#endif
       return;
   }
   ********************************temporary blocked ************/

   /* Change Quad coordination for reference die position */
   /* Calc Center position */
   pntCENTER.sXpos = (mbTemp.uCOLCT / 2) ;
   pntCENTER.sYpos = (mbTemp.uROWCT / 2) ;

   pntORG_QUAD1.sXpos =  (mbTemp.uCOLCT - 1) - pntCENTER.sXpos ;
   pntORG_QUAD1.sYpos =  pntCENTER.sYpos;
   pntORG_QUAD2.sXpos =  pntCENTER.sXpos * -1;
   pntORG_QUAD2.sYpos =  pntCENTER.sYpos;
   pntORG_QUAD3.sXpos =  pntCENTER.sXpos * -1;
   pntORG_QUAD3.sYpos =  ((mbTemp.uROWCT - 1 ) - pntCENTER.sYpos) * -1;
   pntORG_QUAD4.sXpos =  (mbTemp.uCOLCT - 1) - pntCENTER.sXpos ;
   pntORG_QUAD4.sYpos =  ((mbTemp.uROWCT - 1 ) - pntCENTER.sYpos) * -1;

#ifdef _DEBUG_MODE
   printf("mbTemp,cORLOC = [%x], CENTER[%d][%d],Q1[%d][%d], Q2[%d][%d], Q3[%d][%d], Q4[%d][%d]\n",mbTemp.cORLOC,
	   pntCENTER.sXpos,pntCENTER.sYpos, pntORG_QUAD1.sXpos,pntORG_QUAD1.sYpos,
	   pntORG_QUAD2.sXpos,pntORG_QUAD2.sYpos,
	   pntORG_QUAD3.sXpos,pntORG_QUAD3.sYpos,
	   pntORG_QUAD4.sXpos,pntORG_QUAD4.sYpos);
#endif
   switch(mbTemp.cORLOC){
      case  '\1'  : 
		    pntREFPvsCENTER.sXpos = mbTemp.REFP1.sXpos + pntORG_QUAD1.sXpos;
		    pntREFPvsCENTER.sYpos = mbTemp.REFP1.sYpos + pntORG_QUAD1.sYpos;
		    break;
      case  '\2'  : 
		    pntREFPvsCENTER.sXpos = mbTemp.REFP1.sXpos + pntORG_QUAD2.sXpos;
		    pntREFPvsCENTER.sYpos = mbTemp.REFP1.sYpos + pntORG_QUAD2.sYpos;
		    break;
      case  '\3'  : 
		    pntREFPvsCENTER.sXpos = mbTemp.REFP1.sXpos + pntORG_QUAD3.sXpos;
		    pntREFPvsCENTER.sYpos = mbTemp.REFP1.sYpos + pntORG_QUAD3.sYpos;
		    break;
      case  '\4'  : 
		    pntREFPvsCENTER.sXpos = mbTemp.REFP1.sXpos + pntORG_QUAD4.sXpos;
		    pntREFPvsCENTER.sYpos = mbTemp.REFP1.sYpos + pntORG_QUAD4.sYpos;
		    break;
   } /* end of switch */

#ifdef _DEBUG_MODE
   printf("pntREFPvsCENTER[%d][%d]\n", pntREFPvsCENTER.sXpos,pntREFPvsCENTER.sYpos);
   printf("EQUIPMENT SETTING CONDITION : nORLOC[%d]\n",nORLOC); 
#endif
   switch(nORLOC){
      case  1  : 
		    mbTemp.REFP1.sXpos = pntREFPvsCENTER.sXpos  - pntORG_QUAD1.sXpos;
		    mbTemp.REFP1.sYpos = pntREFPvsCENTER.sYpos  - pntORG_QUAD1.sYpos;
		    break;
      case  2  : 
		    mbTemp.REFP1.sXpos = pntREFPvsCENTER.sXpos  - pntORG_QUAD2.sXpos;
		    mbTemp.REFP1.sYpos = pntREFPvsCENTER.sYpos  - pntORG_QUAD2.sYpos;
		    break;
      case  3  : 
		    mbTemp.REFP1.sXpos = pntREFPvsCENTER.sXpos  - pntORG_QUAD3.sXpos;
		    mbTemp.REFP1.sYpos = pntREFPvsCENTER.sYpos  - pntORG_QUAD3.sYpos;
		    break;
      case  4  : 
		    mbTemp.REFP1.sXpos = pntREFPvsCENTER.sXpos  - pntORG_QUAD4.sXpos;
		    mbTemp.REFP1.sYpos = pntREFPvsCENTER.sYpos  - pntORG_QUAD4.sYpos;
		    break;
   } /* end of switch */
#ifdef _DEBUG_MODE
   printf("mbTemp.REFP1[%d][%d]\n", mbTemp.REFP1.sXpos, mbTemp.REFP1.sYpos);
#endif


   /* Save bin lists row/col counts for EDS MAP DATA */
   /* Because row/col counts can be modified during
      rotating reference die position 
   */
   nEdsRowCt = mbTemp.uROWCT;
   nEdsColCt = mbTemp.uCOLCT;

   nRotatingDegree = nFNLOC + nFFROT - mbTemp.uFNLOC;


   /* if nRotatingDegree is negative, add 360 for making positive value
      because, negative degree is hard to calculate rotating times */
   if(nRotatingDegree < 0) nRotatingDegree += 360;

   /* calculate how many times to rotate BIN_LIST */
   nRotatingTimes = nRotatingDegree / 90;

#ifdef _DEBUG_MODE
   printf("REFERENCE SETUP CONDITION : PART_ID[%s],FNLOC[%d],FFROT[%d],ORLOC[%d]\n",stPartId,nFNLOC,nFFROT,nORLOC);
   printf("EDS CONDITION : FNLOC[%d]\n",mbTemp.uFNLOC);
   printf("MAP ROTATION :  rotationdegree[%d],rotationtimes[%d]\n",nRotatingDegree,nRotatingTimes);
#endif

   for(nCount = 0 ; nCount < nRotatingTimes ; nCount++) {
#ifdef _DEBUG_MODE
     printf("Rotating reference die position right-hand side....");
#endif
     /* Rotate Reference Die position */
#ifdef _DEBUG_MODE
     printf("reference position[%d][%d]==>",mbTemp.REFP1.sXpos,mbTemp.REFP1.sYpos);
#endif
     pntTemp.sXpos =  mbTemp.REFP1.sYpos - (mbTemp.uROWCT -1);
     pntTemp.sYpos =  mbTemp.REFP1.sXpos * (-1);
     mbTemp.REFP1.sXpos =  pntTemp.sXpos;
     mbTemp.REFP1.sYpos =  pntTemp.sYpos;
#ifdef _DEBUG_MODE
     printf("[%d][%d]\n",mbTemp.REFP1.sXpos,mbTemp.REFP1.sYpos);
#endif

     /* rotate row count & column count */
     nTemp =  mbTemp.uROWCT;
     mbTemp.uROWCT = mbTemp.uCOLCT;
     mbTemp.uCOLCT = nTemp;
#ifdef _DEBUG_MODE
     printf("completed \n");
#endif
   } /* end of for */

   /* Read bin lists from MAP_BODY structure and set
      temp array 
   */
   nCount = 0;
   for(nLoopRow = 0 ; nLoopRow < nEdsRowCt ; nLoopRow++) {
      for(nLoopCol = 0 ; nLoopCol < nEdsColCt ; nLoopCol++) {
         stTempArray[nLoopCol][nLoopRow] = mbTemp.stBINLT[nCount++];
      } /* end of for(nLoopRowt = 0 ; nLoopRowt < nEdsRowCt ; nLoopRowt++)*/ 
   } /* end of for(nLoopCt = 0 ; nLoopCt < nEdsColCt ; nLoopCt ++)*/ 

   /* Rotate  bin lists from temp array to RotatedArry nRotatingTimes 
      must rotate 180 degrees for real bin list array .
      current nRotatingDegree matches real flatzone location
      on equipment, so bin_list array must be rotated 180 degree.

      This means if real wafer flat zone location was rotated right_hand side nRotatingTimes
      the bin list data must be rotated left-hand side nRotating Times
   */
   nCount = 0;
   /* Reverse Bin list, because real wafer is reversed to data */
   switch(nRotatingTimes){
       case 0 : nRotatingTimes = 2; break;
       case 2 : nRotatingTimes = 0; break;
       /* Case 1,3 has no problem because map bin list rotated left-hand side */
   }
   for(nCount = 0 ; nCount < nRotatingTimes ; nCount++) {
#ifdef _DEBUG_MODE
      printf("Rotating MAP BIN LIST left-hand side ColCt[%d],RowCt[%d]==>",nEdsColCt,nEdsRowCt);
#endif
      for(nLoopRow = 0 ; nLoopRow < nEdsRowCt ; nLoopRow++) {
         for(nLoopCol = 0 ; nLoopCol < nEdsColCt ; nLoopCol++) {
	    /* Rotate BIN-MAP left-hand site one time */
            stRotatedArray[nLoopRow][nEdsColCt - nLoopCol - 1] = stTempArray[nLoopCol][nLoopRow];
         } /* end of for(nLoopCol = 0 ; nLoopCol < nEdsColCt ; nLoopCol ++)*/ 
      } /* end of for(nLoopRow = 0 ; nLoopRowt < nEdsRowC ; nLoopRow++)*/ 
      nTemp = nEdsColCt;
      nEdsColCt = nEdsRowCt;
      nEdsRowCt = nTemp;
      for(nLoopRow = 0 ; nLoopRow < nEdsRowCt ; nLoopRow++) {
         for(nLoopCol = 0 ; nLoopCol < nEdsColCt ; nLoopCol++) {
            stTempArray[nLoopCol][nLoopRow] = stRotatedArray[nLoopCol][nLoopRow];
         } /* end of for(nLoopCol = 0 ; nLoopCol < nEdsColCt ; nLoopCol ++)*/ 
      } /* end of for(nLoopRow = 0 ; nLoopRowt < nEdsRowC ; nLoopRow++)*/ 

#ifdef _DEBUG_MODE
      printf("ColCt[%d],RowCt[%d]...Rotating completed!\n",nEdsColCt,nEdsRowCt);
      /***************************************************/
      for(nLoopRow = 0 ; nLoopRow < nEdsRowCt ; nLoopRow++) {
         for(nLoopCol = 0 ; nLoopCol < nEdsColCt ; nLoopCol++) {
	   printf(" %c ",stRotatedArray[nLoopCol][nLoopRow]);
	 }
	   printf("\n");
      }
      /***************************************************/
#endif
   }/* end of for(nCount = 0 ; nCount < nRotatingTimes ; nCount++)*/

   /* Update tempArray */
   nCount = 0;
   if(nRotatingTimes){
      memset(mbTemp.stBINLT,'\0',160000);
      for(nLoopRow = 0 ; nLoopRow < mbTemp.uROWCT ; nLoopRow++) {
         for(nLoopCol = 0 ; nLoopCol < mbTemp.uCOLCT ; nLoopCol++) {
	   mbTemp.stBINLT[nCount++] = stRotatedArray[nLoopCol][nLoopRow]; 
         }/* end of for(nLoopRow = 0 ; nLoopRow < mbTemp.uCOLCT ; nLoopRow++) */
      } /* end of for(nCount = 0 ; nCount < mbTemp.uCOLCT ; nCount++)*/
   } /* end of if(nRotatingTimes) */


   /* Set new FNLOC, FFROT, ORLOC to  mapdata */
   mbTemp.uFNLOC = nFNLOC;
   mbTemp.uFFROT = nFFROT;
   mbTemp.cORLOC = nORLOC;
   memcpy(mbMapBody,&mbTemp,sizeof(MAP_BODY));

         /******
	   Added by stainles. 2000.03.23
	   Return nRotatingTimes 
	   for Checking about MapRotating Work  
         ******/
   return (nRotatingTimes);

} /* end of function RotateMapBody*/







 /*************************************************
  * Insert into Log Table(RUNIDLOG_TIME) 
  *************************************************/

int InsertLog(stReqFile)
	char *stReqFile;
{
	char stLog_Time[15];
	char stBuff[512];
/* modified by msyun 98/11/11
	char  stRunId[15]; */
/* EXEC SQL BEGIN DECLARE SECTION; */ 

	/* VARCHAR stRunId[15]; */ 
struct { unsigned short len; unsigned char arr[15]; } stRunId;

/* EXEC SQL END DECLARE SECTION; */ 

/* end of modification */
	char stPartId[30];
	char stWafer_Count[3];
	int  nWafer_Count;
        int  nInkless_Flag;  /* Add 98/12/02 */
	int  nSelect_Count;
	char *stTok;
	FILE *fpREQ;
	
    /* Set local Data Base descriptions and connect*/
    username.len = sprintf((LPCTSTR)username.arr,"inkless");
    passwd.len = sprintf((LPCTSTR)passwd.arr,"inkless");
    /* EXEC SQL CONNECT :username IDENTIFIED BY :passwd ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 32;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )393;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&username;
    sqlstm.sqhstl[0] = (unsigned long )22;
    sqlstm.sqhsts[0] = (         int  )22;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&passwd;
    sqlstm.sqhstl[1] = (unsigned long )22;
    sqlstm.sqhsts[1] = (         int  )22;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if(sqlca.sqlcode != 0) {
#ifdef _DEBUG_LOG
       printf("DATA BASE CONNECTION ERROR [%d]\n",sqlca.sqlcode);
#endif
       return(sqlca.sqlcode);
    }
#ifdef _DEBUG_LOG
    printf("DATA BASE  CONNECTION COMPLETED!\n");
#endif

   if( (fpREQ=fopen(stReqFile, "r")) == NULL ) {
                usleep(100000);
                if( (fpREQ=fopen(stReqFile, "r")) == NULL ) {
                        printf("Can't open : %s \n", stReqFile);
			/** return -1;  Modified by stainles 2000.07.11 **/
			return (Cvt_FileOpenErr);  /** *.REF file Open  Error **/
                }
   }  /* end of if ((fpREQ=fopen .....*/
#ifdef _DEBUG_LOG
    printf("[%s] file open success!\n", stReqFile);
#endif

        /* moidified by stainles 98/12/02 */
   nInkless_Flag = 0;
   fseek (fpREQ, 0L, SEEK_SET);

   while(!feof(fpREQ)) {
        memset(stBuff, '\0', sizeof(stBuff));
        fgets(stBuff, sizeof(stBuff), fpREQ);
   	if ( feof(fpREQ) ) break;
        stTok = strtok(stBuff, DELIMITER);

        if ( !memcmp(stTok, "LOTID", 5) ) {   /* this line : LOTID=ZTF446 */
                stTok = strtok(NULL, DELIMITER);
                memset(stRunId.arr, '\0', 15);
                stRunId.len = sprintf((LPCTSTR)stRunId.arr,"%s", stTok);
        }

        if ( !memcmp(stTok, "PARTID", 6) ) {   /* this line : PARTID=KN72A2F */
                stTok = strtok(NULL, DELIMITER);
                memset(stPartId, '\0', 32);
                memcpy(stPartId, stTok, strlen(stTok));
        }

        if ( !memcmp(stTok, "INKLESS", 7) ) {   /* this line : INKLESS=ON (or OFF) */
                stTok = strtok(NULL, DELIMITER);
                if ( !memcmp(stTok, "ON", 2) )  nInkless_Flag = 1;     /* if INKLESS=ON  */
        }

        if ( !memcmp(stTok, "WAFERTOTAL", 10) ) {   /* this line : WAFERTOTAL=24 */
                stTok = strtok(NULL, DELIMITER);
                memset(stWafer_Count, '\0', 3);
                memcpy(stWafer_Count, stTok, strlen(stTok));
                nWafer_Count = atoi(stWafer_Count);
        }

			/*****
 			 *  if  stTok = CHIPTOTAL=4503   or 		        *
    			 *      stTok = COMPONENTS=(ZTI471.01,ZTI471.02 ..) or  *
      			 *      stTok = GOODDIES=(212, 225, ....)   or          *
		  	 *      stTok = ETC.... then   continue		        *
	 					                          *******/
   } /* end of while(!feof(fpREQ)...  */
   fclose(fpREQ);
                    /* end of modification  98/12/02/ .... stainles  */


   memset(stLog_Time, '\0', 15); 
   /* EXEC SQL SELECT TO_CHAR(SYSDATE, 'yyyymmddhh24miss') NOW
	       INTO :stLog_Time
	     FROM DUAL; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 32;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select TO_CHAR(SYSDATE,'yyyymmddhh24miss') NOW into :b0  \
from DUAL ";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )424;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)stLog_Time;
   sqlstm.sqhstl[0] = (unsigned long )15;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   stLog_Time[14] = '\0';
#ifdef _DEBUG_LOG
    /* modified by msyun 98/11/11
    printf("RunId : [%s]\n", stRunId); */
    printf("RunId : [%s]\n", stRunId.arr);
    /* end of modification */
    printf("PartId : [%s]\n", stPartId);
    printf("Wafer_Count : [%d]\n", nWafer_Count);
    printf("nInkless_Flag : [%d]\n", nInkless_Flag);
    printf("Current Time : [%s]\n", stLog_Time);
#endif


               /* moidified by stainles 98/12/02 */
    /* EXEC SQL SELECT COUNT(*) into :nSelect_Count FROM RUNIDLOG_TIME
             WHERE RUN_ID = :stRunId; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 32;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select count(*)  into :b0  from RUNIDLOG_TIME where RUN_\
ID=:b1";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )443;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&nSelect_Count;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&stRunId;
    sqlstm.sqhstl[1] = (unsigned long )17;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if(sqlca.sqlcode != 0)
          printf("RUNIDLOG_TIME: LOG DATA INSERT Error [%d]\n", sqlca.sqlcode);
#ifdef _DEBUG_LOG
    printf("nSelect_Count : [%d]\n", nSelect_Count);
#endif

    if (nSelect_Count > 0) {
        /* EXEC SQL UPDATE RUNIDLOG_TIME
             SET TIME_STAMP = :stLog_Time, PART_ID = :stPartId, WAFER_COUNT = :nWafer_Count ,UPDATED = 1, INKLESS_FLAG = :nInkless_Flag
             WHERE RUN_ID = :stRunId; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 32;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update RUNIDLOG_TIME  set TIME_STAMP=:b0,PART_ID=:b1\
,WAFER_COUNT=:b2,UPDATED=1,INKLESS_FLAG=:b3 where RUN_ID=:b4";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )466;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)stLog_Time;
        sqlstm.sqhstl[0] = (unsigned long )15;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)stPartId;
        sqlstm.sqhstl[1] = (unsigned long )30;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&nWafer_Count;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&nInkless_Flag;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&stRunId;
        sqlstm.sqhstl[4] = (unsigned long )17;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    } else {
        /* EXEC SQL INSERT INTO RUNIDLOG_TIME (RUN_ID, TIME_STAMP, PART_ID, WAFER_COUNT,UPDATED, INKLESS_FLAG, REMAIN_WF_CNT)
                  VALUES ( :stRunId, :stLog_Time, :stPartId, :nWafer_Count, 1, :nInkless_Flag, 0); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 32;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "insert into RUNIDLOG_TIME (RUN_ID,TIME_STAMP,PART_ID\
,WAFER_COUNT,UPDATED,INKLESS_FLAG,REMAIN_WF_CNT) values (:b0,:b1,:b2,:b3,1,:b\
4,0)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )501;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&stRunId;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)stLog_Time;
        sqlstm.sqhstl[1] = (unsigned long )15;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)stPartId;
        sqlstm.sqhstl[2] = (unsigned long )30;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&nWafer_Count;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&nInkless_Flag;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


           }

    if(sqlca.sqlcode != 0) {
          printf("RUNIDLOG_TIME TABLE: LOG DATA INSERT Error [%d]\n", sqlca.sqlcode);
	  return(sqlca.sqlcode);
    }
    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 32;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )536;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL COMMIT WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 32;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )551;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return(EXE_OK);
}

int nInsertHalfInfo(char *cszWaferId, char *cszRunId,int nFirstCnt, int nSecondCnt, int nTotalCnt, char *cszPartId )
{   

   	 /* EXEC SQL BEGIN DECLARE SECTION; */ 

        
        	/* VARCHAR ora_WaferId[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } ora_WaferId;

        	/* VARCHAR ora_RunId[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } ora_RunId;

        	int     ora_nFirstCnt;
        	int     ora_nSecondCnt;
        	int     ora_nTotal;
        	/* VARCHAR ora_PartId[33]; */ 
struct { unsigned short len; unsigned char arr[33]; } ora_PartId;
 /* 2007.05.28 */

    	/* EXEC SQL END DECLARE SECTION; */ 


	int nCnt ;

    	username.len = sprintf((LPCTSTR)username.arr,"inkless");
    	passwd.len = sprintf((LPCTSTR)passwd.arr,"inkless");
    	/* EXEC SQL CONNECT :username IDENTIFIED BY :passwd ; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 32;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )10;
     sqlstm.offset = (unsigned int  )566;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&username;
     sqlstm.sqhstl[0] = (unsigned long )22;
     sqlstm.sqhsts[0] = (         int  )22;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&passwd;
     sqlstm.sqhstl[1] = (unsigned long )22;
     sqlstm.sqhsts[1] = (         int  )22;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqphss = sqlstm.sqhsts;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqpins = sqlstm.sqinds;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlstm.sqpadto = sqlstm.sqadto;
     sqlstm.sqptdso = sqlstm.sqtdso;
     sqlstm.sqlcmax = (unsigned int )100;
     sqlstm.sqlcmin = (unsigned int )2;
     sqlstm.sqlcincr = (unsigned int )1;
     sqlstm.sqlctimeout = (unsigned int )0;
     sqlstm.sqlcnowait = (unsigned int )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    
    	if(sqlca.sqlcode != 0) 
    	{
        	#ifdef _DEBUG_LOG
            	printf("DATA BASE CONNECTION ERROR [%d]\n",sqlca.sqlcode);
        	#endif
        	return(sqlca.sqlcode);
    	}

	memset((char*)ora_RunId.arr, 0x00, sizeof(ora_RunId));
    	memset((char*)ora_WaferId.arr, 0x00, sizeof(ora_WaferId));
    	memset((char*)ora_PartId.arr, 0x00, sizeof(ora_PartId));    /* 2007.05.28 */

	ora_RunId.len = sprintf((char *)ora_RunId.arr, cszRunId);
    	ora_WaferId.len = sprintf((char *)ora_WaferId.arr, cszWaferId);
    	ora_nFirstCnt = nFirstCnt;
    	ora_nSecondCnt = nSecondCnt;
    	ora_nTotal  = nTotalCnt;
    	ora_PartId.len = sprintf((char *)ora_PartId.arr, cszPartId);  /* 2007.05.28 */

	 /* EXEC SQL SELECT COUNT(*) CNT  INTO  :nCnt FROM HALF_MAP_INFO WHERE WAFER_ID = :ora_WaferId; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 32;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(*)  CNT into :b0  from HALF_MAP_INFO where WA\
FER_ID=:b1";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )597;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&nCnt;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&ora_WaferId;
  sqlstm.sqhstl[1] = (unsigned long )22;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    	printf("RUNID : %s , WAFERID :%s\n",(char*)ora_RunId.arr, (char*)ora_WaferId.arr);

	if (nCnt == 0)  /* =E1T5%@LEM insert */
    	{
        	printf("INSERT RUNID:%s, WAFERID:%s, 512CNT:%d, 256CNT:%d, TOTAL:%d, \n",(char*)ora_RunId.arr, (char*)ora_WaferId.arr, ora_nFirstCnt, ora_nSecondCnt, ora_nTotal);
        	/* EXEC SQL INSERT INTO HALF_MAP_INFO(RUN_ID, WAFER_ID, BIN_1_CNT, BIN_2_CNT, TOTAL_CNT, PART_ID) VALUES(:ora_RunId, :ora_WaferId, :ora_nFirstCnt, :ora_nSecondCnt, :ora_nTotal, :ora_PartId); */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 32;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "insert into HALF_MAP_INFO (RUN_ID,WAFER_ID,BIN_1_CN\
T,BIN_2_CNT,TOTAL_CNT,PART_ID) values (:b0,:b1,:b2,:b3,:b4,:b5)";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )620;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&ora_RunId;
         sqlstm.sqhstl[0] = (unsigned long )12;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&ora_WaferId;
         sqlstm.sqhstl[1] = (unsigned long )22;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&ora_nFirstCnt;
         sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&ora_nSecondCnt;
         sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)0;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&ora_nTotal;
         sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)0;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&ora_PartId;
         sqlstm.sqhstl[5] = (unsigned long )35;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)0;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqphss = sqlstm.sqhsts;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqpins = sqlstm.sqinds;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlstm.sqpadto = sqlstm.sqadto;
         sqlstm.sqptdso = sqlstm.sqtdso;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    	}
    	else /* 1bA8 5%@LEM update  */
	{
        	printf("UPDATE RUNID:%s, WAFERID:%s, 512CNT:%d, 256CNT:%d, TOTAL:%d, \n",(char*)ora_RunId.arr, (char*)ora_WaferId.arr, ora_nFirstCnt, ora_nSecondCnt, ora_nTotal);
        	/* EXEC SQL UPDATE HALF_MAP_INFO SET RUN_ID = :ora_RunId, BIN_1_CNT = :ora_nFirstCnt, BIN_2_CNT = :ora_nSecondCnt, TOTAL_CNT = :ora_nTotal, TIME_STAMP = SYSDATE, PART_ID = :ora_PartId 
                 WHERE WAFER_ID = :ora_WaferId; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 32;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "update HALF_MAP_INFO  set RUN_ID=:b0,BIN_1_CNT=:b1,\
BIN_2_CNT=:b2,TOTAL_CNT=:b3,TIME_STAMP=SYSDATE,PART_ID=:b4 where WAFER_ID=:b5";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )659;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&ora_RunId;
         sqlstm.sqhstl[0] = (unsigned long )12;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&ora_nFirstCnt;
         sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&ora_nSecondCnt;
         sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&ora_nTotal;
         sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)0;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&ora_PartId;
         sqlstm.sqhstl[4] = (unsigned long )35;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)0;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&ora_WaferId;
         sqlstm.sqhstl[5] = (unsigned long )22;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)0;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqphss = sqlstm.sqhsts;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqpins = sqlstm.sqinds;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlstm.sqpadto = sqlstm.sqadto;
         sqlstm.sqptdso = sqlstm.sqtdso;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    	}
	
	if(sqlca.sqlcode != 0) 
   	{     
        	#ifdef _DEBUG_LOG
            	printf("DATA BASE ERROR HALF_MAP_INFO [%d]\n",sqlca.sqlcode);
        	#endif
        	return(sqlca.sqlcode);
    	}
    	/* EXEC SQL COMMIT WORK RELEASE; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 32;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )698;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    	return(EXE_OK);
}	
	
