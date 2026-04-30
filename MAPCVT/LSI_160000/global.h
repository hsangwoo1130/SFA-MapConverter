/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  FILE NAME	:	global.h 
  DESCRIPTION	:	Global definitions
  DATE		:	8/11/98
  edited by msyun@samsung.co.kr
  -----------------------------------------------------------
  revision history :

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

/* define DIE Notation */
#define BIN1         '1'
#define DEFECT_BIN   'D'
#define EDGE_BIN     '9'
#define NO_DIE_MK   '.'

/* COMM_MSG COMMAND Definitions */
#define MAP_REQ 1
#define MAP_DATA 2
#define MAP_SAVE 3
#define MAP_SAVE_REP 4
#define SECS_MESSAGE 5
#define SECS_MESSAGE_REP 6

/* define MAP_REQ source location */
#define FROM_EC 1
#define FROM_UI 2

/* define DUAL_SERV_TASK command */
#define MAP_INSERT 1
#define MAP_UPDATE 2


/* FLAG */
#define RECORD_INSERTED "1"
#define RECORD_UPDATED  "1"
#define RECORD_MATCHED  "0"


#define EXE_OK  0
