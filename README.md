# SoalShiftSISOP20_modul2_A09
#### ADAM ABELARD GARIBALDI 05111840000125
#### ALBERTO SANJAYA 05111840000150
---

## Soal 1 
 > Source code 
 > **[soal1.c](https://github.com/Alberto0150/SoalShiftSISOP20_modul2_A09/blob/master/soal1/soal1.c)**

---

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
```
namun hingga tahap ini masih terdapat kesalahan karena belum dapat dipisah pada 2 file yang diminta.

D. Membuat 2 file.txt yang diletakkan pada setiap directory yg di pindahkan pada directory "indomie" dimana setiap .txt berjeda 3 detik.

Tahap D belum selesai pengerjaannya
