all: build
include $(ORACLE_HOME)/precomp/lib/env_precomp.mk

USERID=inkless/inkless
PROCFLAGS= sqlcheck=full userid=$(USERID) 
EXE=LSI_Map_CvtIns.exe
CC = cc -DD64

DFLAGS=-D_HPUX_SOURCE -w -D_DEBUG_LOG -D_DEBUG_MODE
CFLAGS= -Aa -D_HPUX_SOURCE

.SUFFIXES: .pc .c .o .typ .h

OBJS=Mapcvt_Insert.o RegistProcess.o InsertDB.o libm.a

.pc.c:
	$(PROC) $(PROCFLAGS) iname=$*

.pc.o:
	$(PROC) $(PROCFLAGS) iname=$*
	$(CC) $(CFLAGS) $(DFLAGS) -c $*.c

.c.o:
	$(CC) $(CFLAGS) $(DFLAGS) -c $*.c

build: 	$(OBJS)
	$(CC) -o $(EXE) $(OBJS) -L$(LIBHOME) $(LIBCLNTSH) $(LIBSQL)  #-pthread

clean:
	rm -f *.o
