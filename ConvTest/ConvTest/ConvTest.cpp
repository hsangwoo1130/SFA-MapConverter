// ConvTest.cpp : 기본 프로젝트 파일입니다.

#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "string.h"

using namespace System;
char gszBinListInfo[256];
bool GetWaferBinListFromFile();
char GetBinValue(int nBinNo, char cCurValue);
int GetPrivateProfileStringHP(char* lpAppName, char* lpKeyName, char* lpReturnedString, char* lpFileName);

#define DB_INI_FILE_NAME "c:\\temp\\DBUserSFA.ini"
char gstUsername[50];
char gstPasswd[50];
char gstUsername_MES[50];
char gstPasswd_MES[50];
char gstDBName[100];

int main(array<System::String^>^ args)
{
	char	cRetValue;
	char	szBinList[256];
	bool	bReadBinList;

	char    szRetBuf[256];
	int     nRetValue;
	char    gszDbInfo[256];

	

	printf("Hello World\n");

	memset(gstUsername, '\0', sizeof(gstUsername));
	memset(gstPasswd, '\0', sizeof(gstPasswd));
	memset(gstUsername_MES, '\0', sizeof(gstUsername_MES));
	memset(gstPasswd_MES, '\0', sizeof(gstPasswd_MES));
	memset(gstDBName, '\0', sizeof(gstDBName));

	nRetValue = GetPrivateProfileStringHP("INKLESS", "DBUSER", gstUsername, DB_INI_FILE_NAME);
	nRetValue = GetPrivateProfileStringHP("INKLESS", "DBPASS", gstPasswd, DB_INI_FILE_NAME);
	nRetValue = GetPrivateProfileStringHP("MES", "DBUSER", gstUsername_MES, DB_INI_FILE_NAME);
	nRetValue = GetPrivateProfileStringHP("MES", "DBPASS", gstPasswd_MES, DB_INI_FILE_NAME);
	nRetValue = GetPrivateProfileStringHP("MES", "DBUSING", gstDBName, DB_INI_FILE_NAME);

	// USE Point 
	// '--- stBinArray[nTemp_X][nTemp_Y] = cTempBin;

	cRetValue = '1';

	/* Use WaferID => MapBody.stMID */
	bReadBinList = GetWaferBinListFromFile();

	/* ISH 2025/12/05 */
	/* bReadBinList = GetWaferBinListFromFile ( MapBody.stMID, szBinList ); */

	if (bReadBinList == true)
	{
		cRetValue = GetBinValue(15, cRetValue);
		printf("Conv Result [%c]\n", cRetValue);
	}

	cRetValue = getchar();
	return 0;
}

int GetPrivateProfileStringHP(char* lpAppName, char* lpKeyName, char* lpReturnedString,char* lpFileName)
{
	FILE* fpINIInfo;
	char stBuff[512];
	char stTemp[256];
	char* stTok;
	char* stTokBin;
	int  nFindAppName = 0;
	int  nFindKeyName = 0;

	if ((fpINIInfo = fopen(lpFileName, "r")) == NULL) {
		return 0;
	}

	while (!feof(fpINIInfo)) {
		memset(stBuff, '\0', sizeof(stBuff));
		if (fgets(stBuff, sizeof(stBuff), fpINIInfo))
		{
			if (stBuff[0] == ';' || stBuff[0] == '#')
			{
				/* Comment No Action */
			}
			else if (stBuff[0] == '[')
			{
				if (nFindAppName == 1) break; /* Exit While */

				stTok = strtok(stBuff, "[]\r\n");
				if (strcmp(stTok, lpAppName) == 0) nFindAppName = 1;
			}
			else if (nFindAppName == 1)
			{
				stTok = strtok(stBuff, "=\r\n");
				if (strcmp(stTok, lpKeyName) == 0)
				{
					stTok = strtok(NULL, "\r\n");
					strcpy(lpReturnedString, stTok);
					nFindKeyName = 1;
					break;
				}
			}
		}
	} /* end of while(!feof(fpINIInfo) ... */

	fclose(fpINIInfo);

	if (nFindKeyName == 1) return strlen(lpReturnedString);
	return 0;
}


bool GetWaferBinListFromFile()
{
	FILE* fpBinInfo;
	char stBinInfoFile[512];
	char stBuff[512];
	char stTemp[256];
	char* stTok;
	char* stTokBin;

	char szReadWaferID[256];
	char szReadBinList[512];

	//sprintf(stBinInfoFile, "c:\\temp\\wafer_bin_conv_list.cfg");	/* Wafer Bin Info*/
	sprintf(stBinInfoFile, "c:\\temp\\wafer_bin_conv_list_v2.cfg");	/* Wafer Bin Info*/

	memset(gszBinListInfo, 0x0, sizeof(gszBinListInfo));

	if ((fpBinInfo = fopen(stBinInfoFile, "r")) == NULL) {
		printf("Can't open : [%s] \n", stBinInfoFile);
		return 0;
	}

	while (!feof(fpBinInfo)) {
		memset(stBuff, '\0', sizeof(stBuff));
		if (fgets(stBuff, sizeof(stBuff), fpBinInfo))
		{
			printf("[%s]\n", stBuff);

			stTok = strtok(stBuff, " \r\n");
			printf("....[%s] \n", stTok);

			if (strcmp(stTok, "WAFERSPEC") == 0)
			{
				while ((stTok = strtok(NULL, "= \r\n")) != NULL)
				{
					printf("....[%s] \n", stTok);
					/*if (strcmp(stTok, "WAFERID") == 0)
					{
						stTok = strtok(NULL, "=() \r\n");
						if ( stTok == NULL ) break;

						strcpy ( szReadWaferID, stTok );
						printf(".....WAFERID.. [%s]\n", szReadWaferID );

						if ( strcmp( szReadWaferID, szWaferID ) != 0 ) break;
					}
					else if ( strcmp (stTok, "BINCONVLIST") == 0 )*/
					if (strcmp(stTok, "BINCONVLIST") == 0)
					{
						stTok = strtok(NULL, "=() \r\n");
						if (stTok == NULL) return 0;  /* break;*/

						strcpy(szReadBinList, stTok);
						printf(".....BINLIST.. [%s]\n", szReadBinList);

						strcpy(gszBinListInfo, szReadBinList);
						return 1;

					}

				} /* end of while */
			}
		}
	} /* end of while(!feof(fpBinInfo) ... */

	fclose(fpBinInfo);
	return 0;
}


char GetBinValue(int nBinNo, char cCurValue)
{
	char* stTokBin;
	int  nReadBinNo;
	char cSetBinNo;
	int  nLoopCount;
	char szBinList[256];

	strcpy(szBinList, gszBinListInfo);

	if (cCurValue == '1')		/* GOOD BIN인 경우만 처리함 (사고방지) */
	{

		printf(">>> SELECT BIN [%d] - BINLIST [%s]\n", nBinNo, szBinList);
		if (strlen(szBinList) == 0) return cCurValue; /* Noting Bin List */

		stTokBin = strtok(szBinList, ",:");
		if (stTokBin == NULL) return cCurValue;

		printf(">> Bin [%s]\n", stTokBin);

		nLoopCount = 0;
		nReadBinNo = atoi(stTokBin);
		if (nReadBinNo == nBinNo)
		{
			stTokBin = strtok(NULL, ",:");
			if (stTokBin == NULL) return cCurValue;

			cSetBinNo = stTokBin[0];

			printf("....SET BIN (%d) [%c->%c]\n", nBinNo, cCurValue, cSetBinNo);
			return cSetBinNo;
		}
		while ((stTokBin = strtok(NULL, ",:")) != NULL)
		{
			nLoopCount++;
			if (nLoopCount % 2 == 0)
			{
				printf(">> Bin [%s]\n", stTokBin);
				nReadBinNo = atoi(stTokBin);
				if (nReadBinNo == nBinNo)
				{
					stTokBin = strtok(NULL, ",:");
					if (stTokBin == NULL) return cCurValue;

					cSetBinNo = stTokBin[0];

					printf("....SET BIN (%d) [%c->%c]\n", nBinNo, cCurValue, cSetBinNo);
					return cSetBinNo;
				}
			}
		}
	}
	return cCurValue;
}