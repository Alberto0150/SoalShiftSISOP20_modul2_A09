#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main(void) 
{
	pid_t pid, sid;        // Variabel untuk menyimpan PID

	pid = fork();     // Menyimpan PID dari Child Process

	/* Keluar saat fork gagal
	* (nilai variabel pid < 0) */
	if (pid < 0) 
	{
		exit(EXIT_FAILURE);
	}

	/* Keluar saat fork berhasil
	* (nilai variabel pid adalah PID dari child process) */
	if (pid > 0) 
	{
		exit(EXIT_SUCCESS);
	}

	umask(0);

	sid = setsid();
	if (sid < 0) 
	{
		exit(EXIT_FAILURE);
	}

	if ((chdir("/")) < 0) 
	{
		exit(EXIT_FAILURE);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);


	time_t now;

	while (1) 
	{
		pid_t newf;
		newf=fork();
		time(&now);
		struct tm *local= localtime(&now);
		char waktu[20];
		strftime(waktu,20,"%Y-%m-%d_%T",local):
		char namafile[1000];
		strcpy(namafile,"/home/alberto/praktikum2/Soal2praktikum2/");
		strcat(namafile,waktu);
		if(newf==0)
		{
			char *argv[] = {"mkdir", "-p", namafile, NULL};
			execv("/bin/mkdir", argv);
		}
		else if (newf!=0)
		{
			chdir(namafile);
			int jml=0;
			for(jml;jml<20;jml++)
			{
				
			}
		}
		else
		{
			sleep(30);
		}	
	}
}
