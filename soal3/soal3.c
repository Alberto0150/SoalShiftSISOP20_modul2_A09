#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{
//bagian A
pid_t child_id;
int status;

child_id = fork();

if (child_id < 0) 
	{
		exit(EXIT_FAILURE); 
	}

if (child_id == 0) 
	{

		char *argv[] = {"mkdir", "-p", "/home/alberto/modul2/indomie", NULL};
		execv("/bin/mkdir", argv);
	}
sleep(5);
child_id = fork();
if (child_id == 0) 
	{	
		char *argv[] = {"mkdir", "-p", "/home/alberto/modul2/sedaap", NULL};
		execv("/bin/mkdir", argv);
	}

// bagian B
sleep(1);
child_id = fork();
if(child_id == 0)
{
	char *argv[] = {"unzip","jpg.zip",NULL};
	execv("/usr/bin/unzip", argv);
}
}
