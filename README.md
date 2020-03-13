# SoalShiftSISOP20_modul1_A09
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

Pada soal 3, terdapat 4 tahap pengerjaan yang terdiri dari 
A. pembuatan directory "indomie" dan "sedaap" pada /home/[USER]/modul2 dengan cara pembuatan child dengan fork dan menggunakan mkdir seperti kode berikut :

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
A. pembuatan directory "indomie" dan "sedaap" pada /home/[USER]/modul2 dengan cara pembuatan child dengan fork dan menggunakan mkdir seperti kode berikut :

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
