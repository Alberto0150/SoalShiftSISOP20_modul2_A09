# SoalShiftSISOP20_modul2_A09
#### ADAM ABELARD GARIBALDI 05111840000125
#### ALBERTO SANJAYA 05111840000150
---

## Soal 1 
 > Source code 
 > **[soal1.c](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal1/soal1.c)**

---
## Soal 2
 > Source code 
 > **[soal2.c](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal2/soal2.c)**

Pada soal 2 terdapat 5 sub soal dimana terdapat catatan dan hint berupa
Catatan:
- Tidak boleh memakai system().
- Program utama harus ter-detach dari terminal
Hint:
- Gunakan fitur picsum.photos untuk mendapatkan gambar dengan ukuran
tertentu
- Epoch Unix bisa didapatkan dari time()

A. Diminta untuk membuat sebuah folder khusus, di dalamnya dia membuat
sebuah program C yang per 30 detik membuat sebuah folder dengan nama
timestamp [YYYY-mm-dd_HH:ii:ss].
```
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
```
dimana pada akhirnya ditambahkan 
```sleep(30) ```

Namun kendala untuk soal B sampai E adalah belum menemukan cara mengerjakan soal tersebut
hasil dari nomor 2 soal A


![alt text](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal2/soal2.png)





---

## Soal 3
> Source code 
> **[soal3.c](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal3/soal3.c)**

Pada soal 3, terdapat 4 tahap pengerjaan yang juga terdiri dari catatan:
- Tidak boleh memakai system().
- Tidak boleh memakai function C mkdir() ataupun rename().
- Gunakan exec dan fork
- Direktori “.” dan “..” tidak termasuk

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
didapatkan hasil directory untuk nomor 3 soal A dan B

![alt text](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal3/hasil%20file.png)

didapatkan hasil nomor 3 C

![alt text](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal3/dalam%20indomie.png)
![alt text](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal3/dalam%20sedaap.png)

didapatkan hasil nomor 3 D

![alt text](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal3/dalam%20file%20di%20indomie.png)

Kendala yang dialami adalah error yang muncul ketika menjalankan 3C dimana muncul
```
mv: cannot move '/home/alberto/modul2/jpg/.' to '/home/alberto/modul2/indomie/.': Device or resource busy
mv: '/home/alberto/modul2/jpg/..' and '/home/alberto/modul2/indomie/..' are the same file
```
