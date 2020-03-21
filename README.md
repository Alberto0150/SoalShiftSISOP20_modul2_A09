# SoalShiftSISOP20_modul2_A09
#### ADAM ABELARD GARIBALDI 05111840000125
#### ALBERTO SANJAYA 05111840000150
---

## Soal 1 
 > Source code 
 > **[soal1.c](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal1/soal1.c)**
---
Pada Soal 1a diminta program menerima 4 argumen yaitu detik, menit, jam dan file dengan tipe .sh
```
int main (int argc, char *argv[]){
	int detik = -1;
	int menit = -1;
	int jam = -1;
	if(argc != 5){
		printf("Error Arguments\n");
		exit(0);
```
kodingan diatas memiliki fungsi untuk deklarasi state awal detik, menit, jam dengan -1 agar jika inputan argumen merupakan * tetap jalan. lalu ada kondisi if untuk mendapatkan 4 argumen tidak boleh lebih atau kurang, jika lebih atau kurang akan mengeluarkan pesan error arguments.
```
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
```
kodingan diatas berguna untuk melakukan pengecekan terhadap argumen yang telah dimasukan, jikq tidak sesuai dengan aturan yang diinginkan maka akan mengeluarkan pesan Error Arguments.
```
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
```
kodingan diatas dilakukan ketika argumen telah cocok maka melakukan kondisi if untuk menyamakan waktu sekarang dengan waktu yang dimasukan pada argumen. jika waktu sekarang dan waktu argummen telah cocok maka program akan berjalan


## Soal 3
> Source code 
> **[soal3.c](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal3/soal3.c)**

Pada soal 3, terdapat 4 tahap pengerjaan yang terdiri dari  :

A. pembuatan directory "indomie" dan "sedaap" pada /home/[USER]/modul2 dengan cara pembuatan child dengan fork dan menggunakan mkdir dengan syarat jeda waktu pembuatan directory 5 detik, seperti kode berikut :

```
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
```
B. melakukan unzip pada file jpg.zip yang didapat, dengan cara :

```
sleep(1);
child_id = fork();
if(child_id == 0)
{
	char *argv[] = {"unzip","jpg.zip",NULL};
	execv("/usr/bin/unzip", argv);
}
```
C. memisahkan semua direktori  ke “/home/[USER]/modul2/indomie/” dan semua file ke
“/home/[USER]/modul2/sedaap/”, dengan cara :

```
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

```


D. Membuat 2 file.txt yang diletakkan pada setiap directory yg dipindahkan pada directory "indomie" dimana setiap .txt berjeda 3 detik.
```
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
```
