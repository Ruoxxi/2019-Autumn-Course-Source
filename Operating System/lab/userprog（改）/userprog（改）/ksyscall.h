/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>


void SysHalt()
{
  kernel->interrupt->Halt();
}


int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

// add by QvPeng,12.11.15
int SysWrite(char *buffer,int size,OpenFileId id)
{
	return write(id,buffer,size);
}

int SysRead(char *buffer,int size,OpenFileId id)
{
	return read(id,buffer,size);
}

int SysJoin(SpaceId id)
{
	return waitpid(id,(int*)0,0);
}

SpaceId SysExec(char* exec_name)
{
	char* argv[]={"bash","-c",exec_name,NULL};
	pid_t pid;
	if(pid=fork()==0){
		execvp("bash",argv);
		exit(0);
	}else if(pid==1){
		return (SpaceId)pid;
	}
	else
		return -1;
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
