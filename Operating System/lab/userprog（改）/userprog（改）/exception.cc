// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "main.h"
#include "syscall.h"
#include "ksyscall.h"
//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// If you are handling a system call, don't forget to increment the pc
// before returning. (Or else you'll loop making the same system call forever!)
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	is in machine.h.
//----------------------------------------------------------------------

void
ExceptionHandler(ExceptionType which)
{
    int type = kernel->machine->ReadRegister(2);
	/**
	 * add by QvPeng,this array is used save argvs.
	 */
	unsigned int argv[5];
	int result;// return value if exist.
	char buf[80]; // buffer of write.Copy user's data to here.
	int iterator=0;
    DEBUG(dbgSys, "Received Exception " << which << " type: " << type << "\n");

    switch (which) {
    case SyscallException:
		switch(type) {
		case SC_Halt:
			DEBUG(dbgSys, "Shutdown, initiated by user program.\n");
			SysHalt();

			ASSERTNOTREACHED();
			break;

		case SC_Add:
			DEBUG(dbgSys, "Add " << kernel->machine->ReadRegister(4) << " + " << kernel->machine->ReadRegister(5) << "\n");
	
				/* Process SysAdd Systemcall*/
			result = SysAdd(/* int op1 */(int)kernel->machine->ReadRegister(4),
				/* int op2 */(int)kernel->machine->ReadRegister(5));

			DEBUG(dbgSys, "Add returning with " << result << "\n");
				/* Prepare Result */
			kernel->machine->WriteRegister(2, (int)result);
	
				/* set previous programm counter (debugging only)*/
				kernel->machine->WriteRegister(PrevPCReg, kernel->machine->ReadRegister(PCReg));

				/* set programm counter to next instruction (all Instructions are 4 byte wide)*/
				kernel->machine->WriteRegister(PCReg, kernel->machine->ReadRegister(PCReg) + 4);
	  
				/* set next programm counter for brach execution */
				kernel->machine->WriteRegister(NextPCReg, kernel->machine->ReadRegister(PCReg)+4);

			return;
			ASSERTNOTREACHED();
			break;

		case SC_Read:
			for(int i=1;i<=4;++i)
				argv[i]=(unsigned int)kernel->machine->ReadRegister(i+3);
			DEBUG(dbgSys,"SC_Read with papameters are: "<<argv[1]<<"\t"
							<<argv[2]<<"\t"<<argv[3]<<"\n");

			do{
				int size=(int)argv[2];	// assume that it is less than 80.
				int addr=(int)argv[1];
				result=SysRead(buf,size,(OpenFileId)argv[3]);
				for(iterator=0;iterator!=size;++iterator)
					kernel->machine->WriteMem(addr++,1,buf[iterator]);
			}while(false);
			kernel->machine->WriteRegister(2,result);

			/* Modify return point */
				/* set previous programm counter (debugging only)*/
			kernel->machine->WriteRegister(PrevPCReg, kernel->machine->ReadRegister(PCReg));

			/* set programm counter to next instruction (all Instructions are 4 byte wide)*/
			kernel->machine->WriteRegister(PCReg, kernel->machine->ReadRegister(PCReg) + 4);
	  
			/* set next programm counter for brach execution */
			kernel->machine->WriteRegister(NextPCReg, kernel->machine->ReadRegister(PCReg)+4);
			
			return;
			ASSERTNOTREACHED();

		case SC_Write:
			for(int i=1;i<=4;++i)
				argv[i]=(unsigned int)kernel->machine->ReadRegister(i+3);
			DEBUG(dbgSys,"SC_Write with parameters are:"<<argv[1]<<"\t"
							<<argv[2]<<"\t"<<argv[3]<<"\n");
			
			iterator=0;
			do{
				kernel->machine->ReadMem((int)argv[1]++,1,(int*)&buf[iterator]);
			}while(buf[iterator] != '\0' && iterator++ != 80);

			result=SysWrite((char*)buf,(int)argv[2],(OpenFileId)argv[3]);
			kernel->machine->WriteRegister(2,result);

			/* Modify return point */
				/* set previous programm counter (debugging only)*/
			kernel->machine->WriteRegister(PrevPCReg, kernel->machine->ReadRegister(PCReg));

			/* set programm counter to next instruction (all Instructions are 4 byte wide)*/
			kernel->machine->WriteRegister(PCReg, kernel->machine->ReadRegister(PCReg) + 4);
	  
			/* set next programm counter for brach execution */
			kernel->machine->WriteRegister(NextPCReg, kernel->machine->ReadRegister(PCReg)+4);
			
			return;
			ASSERTNOTREACHED();

		case SC_Exec:
			argv[1]=(unsigned int)kernel->machine->ReadRegister(4);
			DEBUG(dbgSys,"SC_Exec with parameters are:"<<argv[1]<<"\n");

			iterator=0;
			do{
				kernel->machine->ReadMem((int)argv[1]+iterator,1,(int*)&buf[iterator]);
				++iterator;
			}while(iterator<80 && buf[iterator-1]!='\0');

			result=SysExec(buf);
			kernel->machine->WriteRegister(2,result);

			/* Modify return point */
				/* set previous programm counter (debugging only)*/
			kernel->machine->WriteRegister(PrevPCReg, kernel->machine->ReadRegister(PCReg));

			/* set programm counter to next instruction (all Instructions are 4 byte wide)*/
			kernel->machine->WriteRegister(PCReg, kernel->machine->ReadRegister(PCReg) + 4);
	  
			/* set next programm counter for brach execution */
			kernel->machine->WriteRegister(NextPCReg, kernel->machine->ReadRegister(PCReg)+4);
			
			return;
			ASSERTNOTREACHED();

		case SC_Join:
			argv[1]=(unsigned int)kernel->machine->ReadRegister(4);
			DEBUG(dbgSys,"SC_Exec with parameters are:"<<argv[1]<<"\n");

			result=SysJoin((SpaceId)argv[1]);
			kernel->machine->WriteRegister(2,result);

			/* Modify return point */
				/* set previous programm counter (debugging only)*/
			kernel->machine->WriteRegister(PrevPCReg, kernel->machine->ReadRegister(PCReg));

			/* set programm counter to next instruction (all Instructions are 4 byte wide)*/
			kernel->machine->WriteRegister(PCReg, kernel->machine->ReadRegister(PCReg) + 4);
	  
			/* set next programm counter for brach execution */
			kernel->machine->WriteRegister(NextPCReg, kernel->machine->ReadRegister(PCReg)+4);
			
			return;
			ASSERTNOTREACHED();

			// end. by QvPeng,12.11.15 //
		default:
			cerr << "Unexpected system call " << type << "\n";
			break;
		}
		break;
	case PageFaultException:
		// what should I do?
		//break;
		return; 
    default:
      cerr << "Unexpected user mode exception" << (int)which << "\n";
      break;
    }
    ASSERTNOTREACHED();
}
