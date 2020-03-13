
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>

int main (int argc, char *argv[]){
	int detik = -1;
	int menit = -1;
	int jam = -1;
	if(argc != 5){
		printf("Error Arguments\n");
		exit(0);
	}
	else{
		if((strcmp(argv[1], "*")) != 0 ){
			int detik = atoi(argv[1]);
			if(detik > 59 && detik < -1){
				printf("Error Arguments\n");
				exit(0);
			}
		}
		if((strcmp(argv[2], "*")) != 0){
			int menit = atoi(argv[2]);
			if(menit > 59 && menit < -1){
				printf("Error Arguments\n");
				exit(0);
			}
		}
		if((strcmp(argv[3], "*")) != 0){
			int jam = atoi(argv[3]);
			if(jam > 23 && jam < -1){
				printf("Error Arguments\n");
				exit(0);
			}
		}
		int panjang = strlen(argv[4]);
		if(argv[4][panjang-3] != '.' && argv[4][panjang-2] != 's' && argv[4][panjang-1] != 'h'){
			printf("Error Arguments\n");
			exit(0);
		}
	}

	pid_t pid, sid;

	pid = fork();

	if(pid < 0){
		exit(EXIT_FAILURE);
	}

	if(pid > 0){
		exit(EXIT_SUCCESS);
	}

	umask(0);

	sid = setsid();
	if(sid < 0){
		exit(EXIT_FAILURE);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	while(1){
		time_t now;
		time(&now);
		struct tm *local = localtime(&now);

		if((detik == local->tm_sec || detik == -1) && (menit == local->tm_min || menit == -1) && (jam == local->tm_hour || jam == -1)){
			char *jalan[] = {"bash", argv[4], NULL};
			execv("bin/bash", jalan);
		}
	sleep(1);
	}

//	printf("%d %d %d %s\n", detik, menit, jam, argv[4]);

}
