#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

int main(int argc, char *argv[], char *env[])
{
  
  char *args[] = {"ping", "localhost", 0};
  
  printf("\nProgram Start Successful.\n");

  /*
  	The purpose of fork() is to create a new process, which becomes the child process of the caller. 
  */
    
  pid_t childPID = fork();
  int PPID = getppid();
  int PID	= getpid();
  
  printf("\n Process ID : %d",PID);
  printf("\n Parent Process ID : %d",PPID);
  
  if(childPID == -1){
    printf( "\n Failed To Fork A Child Process :(\n" );
  
	exit( 1 );
  }
  
  else if(childPID == 0){
       
   /*
   	The execv() functions provide an array of pointers to null-terminated strings that 
   	represent the argument list available to the new program. The first argument, by convention,
   	should point to the filename associated with the file being executed. The array of 
  	pointers must be terminated by a NULL pointer. 
   */
        
	execv( "/bin/ping", args );
  }

  while ( 1 )
  {
    printf( "\n Press 'Q' Kill Ping (Child) Process.\n " );
  
    char c = getchar();

    if (c == 'q'){
    /*
    The kill() system call can be used to send any signal to any process group or process.
    */
    
    	kill( childPID, SIGKILL );
    	printf("\n Process %d killed by 'SIGKILL'Signal.",childPID);  
    	
    	break; 
    }

	/*
	sleep() makes the calling thread sleep until seconds seconds have elapsed or a signal arrives which is not ignored.
	*/
	
    sleep(1);
  }

	printf("\n Program Exit Successful.\n");
	return 0;
} 
