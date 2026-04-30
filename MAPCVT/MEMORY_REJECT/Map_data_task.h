/****
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  FILE NAME     :       Map_data_task.h
  DESCRIPTION   :  This header file is used by Map_data_task Module 
                   FUNCTION LIST : Map_file_check()
                                   Map_convert()
                                   Map_insert()
  DATE          :       9/29/98
  Modified Date :  2000.03.23
  edited by stainles@samsung.co.kr
  -----------------------------------------------------------------------
  revision history :

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
****/
/** 
   modified by msyun 98/11/04 
   for dividing Defect bin(O/S,Leakage,Stand by current )
   These Bins are used for Dummy package work
   
   Defect Bin : BIN3(IC2P2), BIN5(IC2PS), 
		BIN 16(I/I LEAKAGE), BIN 17(SHORT), BIN 18(OPEN)
   --- These D/C FAIL bins can be changed ..
       -if New product doesn't have a same bin system, 
	must have to make reference information table 
   #define DC_FAIL_FLAG  "38014"    0x0011 1000 0000 0001 0100 
**/
/***
   Modified by msyun 98/11/11 for excepting BIN5 from DC FAIL BINS
   Becase there is no assurence that BIN5 can be screened 
   at pre burn test(DC SCREEN).
   Approved by Byung-Jun Min(BURN-IN Dept)
	       Kyung-Sun Shin(EDS TEST) 98/11/11
   #define DC_FAIL_FLAG  "38004"    0x0011 1000 0000 0000 0100 
***/

/**** 
   Modified by msyun 99/1/13 for adding BIN4 for DC FAIL BINS
   Becase functional fail bin(BIN04) can be screened using fuse,
   and screenable rejected dies are not so many than they required for dummy dies.
   Approved by Byung-Jun Min(BURN-IN Dept)
	       Kyung-Sun Shin(EDS TEST) 99/1/13
****/
#define DC_FAIL_FLAG  "3800C" /* 0x0011 1000 0000 0000 1100 */

	/* Added by stainles 98/12/10 , 99/01/05 */
#define EDGE_BIN_FLAG "FFFFFFFFFFF80000"   /* post laser bin range : 20 ~ 64 */
	     /* 0x1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1000 0000 0000 0000 0000 */

       /* define die Notation */
#define BIN1         '1'
#define BIN2         '2'
/**** #define EDGE_BIN     '9'   <= change 9 into D with DUMMY_BIN,  /98/12/26  ***/
#define EDGE_BIN     'D'      /* also use for POST LASER FAIL BIN /98/12/10 */

/**** modified by msyun 98/11/04 for dividing D/C FAIL bin from defects   ***/
/***  #define DEFECT_BIN   'D' ****/
#define DEFECT_BIN   '8'

/*** #define DUMMY_BIN    'D'     <= change D into 9 with EDGE_BIN, /98/12/26/... ***/
#define DUMMY_BIN    '9'

#define NO_DIE_MK    '.'

#define MAP_DATA_DIRECTORY "/mapap/inkless/map_file_eds_half/"
#define MAP_DATA_BACKUP_DIRECTORY "/mapap/inkless/map_file_backup/"
#define MAP_DATA_ERROR_DIRECTORY "/mapap/inkless/map_file_error/"
#define TRANSFER_BIN_DIRECTORY "/mapap/inkless/bin/"
#define KH_EDS_SERVER "kh_eds"
#define KH_EDS_DIRECTORY "/MAP/inkless/_ONYANG/"
#define LOG_DIRECTORY "/mapap/inkless/LOG/SERVER/"

	/* Error File List */
#define MAP_FILE_ERROR "Map_file_err"
#define INSERT_ERROR "Map_insert_err"

	/* define Error Flag */
#define CountErr   	  -11
#define OpenErr    	  -12
#define EowErr     	  -13
#define MsgQErr    	  -20
#define ConvertErr 	  -30
#define Cvt_FileOpenErr   -31
#define Cvt_EowCountErr   -32
#define InsertErr  	  -40
#define DataFormatErr     -50
#define MapRotationErr    -60
#define MapcvtForkErr     -70
#define InsertGood 	  100

       /* Queue key for Dual Server */
#define  DUAL_SRV_KEYID   0x90000002     /* Queue key for Dual Server */


       /*  For Reference Die Position */
typedef struct _point {
        short sXpos;
        short sYpos;
        } POINT;

       /* Wafer Map Body structure */
typedef struct _map_body {
        char stMID[20];
        unsigned char  cIDTYP;
        unsigned char  cMAPFT;
        unsigned short uFNLOC;
        unsigned short uFFROT;
        unsigned char  cORLOC;
        unsigned char  cPRAXI;
        char           stBCEQU[10];
        char           cNULBC;
        unsigned short uRPSEL;
        POINT          REFP1;
        POINT          REFP2;
        POINT          REFP3;
        POINT          REFP4;
        unsigned short uROWCT;
        unsigned short uCOLCT;
        unsigned short uPDRCT;
        POINT          STRP;
        char           stBINLT[160000];
        unsigned short uDATLC;
        unsigned char  cMAPER;
        unsigned char  cFINISH_FLAG;

	/* Modified by msyun 98/10/18 */
	/* Add two data items for run-sheet */
        char stRUN_ID[20];
        unsigned short uNET_DIE_CNT;
} MAP_BODY;

        /* FLAG */
#define RECORD_INSERTED "1"
#define RECORD_UPDATED  "1"
#define RECORD_MATCHED  "0"

#define EXE_OK 0

		/* Message Queue for sending data to convert_insert.exe process */
#define Qkey_F    "/usr/include/stdio.h"
#define Qkey      'i'
#define QPERM     0666
#define MsgType   1

typedef struct _Map_infor {
	char Wafer_List[30][100];
	int  Wafer_Count;
	}Map_infor;

typedef struct{
	long mtype;
	Map_infor msgData;
	}RunFilesMsgQ;

