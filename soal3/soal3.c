
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
pid_t anakan,child_id ;
int status;

anakan = fork();
if(anakan == 0)
{
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
// bagian C
sleep(2);
struct dirent *check;
DIR *masuk = opendir("/home/alberto/modul2/jpg");
if(masuk==NULL)
{
return 0;
}

while((check = readdir(masuk))!= NULL)
{
	
	char nama[100];
	struct stat typestat;
		strcpy(nama,"/home/alberto/modul2/jpg/");
		strcat(nama,check->d_name);
		printf("%s \n",nama);
		if(stat(nama,&typestat) == 0)
		{
			if(typestat.st_mode & S_IFDIR)
			{
				if(anakan = fork() == 0)
				{
					char *argv[] = {"mv",nama,"/home/alberto/modul2/indomie",NULL};
					execv("/bin/mv",argv);
				}
			}
			else if (typestat.st_mode & S_IFREG)
			{
				
				if (anakan = fork() == 0)
				{
					char *argv[] = {"mv",nama,"/home/alberto/modul2/sedaap",NULL};
					execv("/bin/mv",argv);
				}
			}
		}
	

}
closedir(masuk);

//bagian D

sleep(2);
struct dirent *buat;
DIR *dir = opendir("/home/alberto/modul2/indomie");
if(dir==NULL)
{
	return 0;
}

while((buat = readdir(dir))!= NULL)
{
	if(strcmp(buat->d_name,".")==0 || strcmp(buat->d_name,"..")==0)
	{
        	continue;
	}
	else
	{
		char nama[100];
		strcpy(nama,"/home/alberto/modul2/indomie/");
		strcat(nama,buat->d_name);
		anakan=fork();
		if(anakan == 0)
		{
			chdir(nama);
			char *temp[]={"touch","coba1.txt",NULL};
			execv("/bin/touch",temp);
		}
		sleep(3);
		anakan=fork();
		if(anakan == 0)
		{
			chdir(nama);
			char *temp[]={"touch","coba2.txt",NULL};
			execv("/bin/touch",temp);
		}	
	}
}
closedir(dir);




}
