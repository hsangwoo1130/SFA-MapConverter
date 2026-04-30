/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  FILE NAME	:	messages.h 
  DESCRIPTION	:	message struct descriptions  
  DATE		:	8/11/98
  edited by msyun@samsung.co.kr
  -----------------------------------------------------------
  revision history :

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

typedef struct _point {
	short sXpos;
	short sYpos;
} POINT;

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
	char           stBINLT[8000];
	unsigned short uDATLC;
	unsigned char  cMAPER;
	unsigned char  cFINISH_FLAG;
} MAP_BODY;

typedef struct _msg{
	unsigned short uCommand;
	char           stWaferId[20];
	MAP_BODY       mbMapBody;
	char           stComment[256];
} MSG;

/**************************************************/

typedef struct _c_msg_hdr {
	char           stClientType[2];
	char           stEquipId[8];
} C_MSG_HDR;

typedef struct _c_msg {
	C_MSG_HDR  mhMessageHeader;
	MSG      msgMessage;
}C_MSG; 
