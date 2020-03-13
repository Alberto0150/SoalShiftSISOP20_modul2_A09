#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>


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


// bagian C
sleep(1);
struct dirent *check;
DIR* masuk;

masuk = opendir("/home/alberto/modul2/jpg/");
check = readdir(masuk);
char nama[100];

while(1)
{
	if (check == NULL)
	{
		break;
	}
	else
	{
		strcpy(nama,"/home/alberto/modul2/jpg/");
		strcat(nama,check->d_name);
		if(check->d_type==DT_DIR)
		{
			char *argv[] = {"mv",nama,"/home/alberto/modul2/indomie",NULL};
			execv("/bin/mv",argv);
		}
		else if (check->d_type==DT_REG)
		{
			char *argv[] = {"mv",nama,"/home/alberto/modul2/sedaap",NULL};
			execv("/bin/mv",argv);
		}

	}
}
}
