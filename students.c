#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


struct students* read_list(){
	FILE *fp = fopen("students.csv", "r");

	struct students *stud_arr = calloc(1, sizeof(struct students));
	int k = str_num();

	char string[150];
	int i = 0;

	while(i < k){

		stud_arr = realloc(stud_arr, (i+1) * sizeof(struct students));

		fgets(string, 150, fp);

		strcpy(stud_arr[i].id, strtok(string, ";"));
        strcpy(stud_arr[i].fam, strtok(NULL,";"));
        strcpy(stud_arr[i].name, strtok(NULL,";"));
        strcpy(stud_arr[i].otch, strtok(NULL,";"));
        strcpy(stud_arr[i].facul, strtok(NULL,";"));
        strcpy(stud_arr[i].spec, strtok(NULL,"\n"));

        i++;
	}
	fclose(fp);
	return stud_arr;
}

int str_num(){
	int line = 0;
	FILE *f = fopen("students.csv", "r");
	if (f == NULL) {
		printf("No file!\n");
	} else {

	while (!feof(f)) {
		if (fgetc(f)=='\n')
			line++;
		}
	fclose(f);
	}

	return ++line;
}


struct students *add_stud(struct students *stud_arr, int* n){
		struct students stud_new;

		printf("ID of student: \n");
		scanf("%s", stud_new.id);
		if (find_student_id(stud_arr, *n, stud_new.id) != -1){
			printf("ERROR: we alredy have a student with this id\n");
			return stud_arr;
		}

		printf("Lastname of student: \n");
        scanf("%s", stud_new.fam);

        printf("Name of student: \n");
        scanf("%s", stud_new.name);

        printf("Patronumic of student: \n");
        scanf("%s", stud_new.otch);

        printf("Faculty of student: \n");
        scanf("%s", stud_new.facul);

        printf("Speciality of student: \n");
        scanf("%s", stud_new.spec);

        		(*n)++;
        		stud_arr = realloc(stud_arr, (*n+1) * sizeof(struct students));
        		strcpy(stud_arr[*n-1].id, stud_new.id);
        		strcpy(stud_arr[*n-1].fam, stud_new.fam);
        		strcpy(stud_arr[*n-1].name, stud_new.name);
        		strcpy(stud_arr[*n-1].otch, stud_new.otch);
        		strcpy(stud_arr[*n-1].facul, stud_new.facul);
        		strcpy(stud_arr[*n-1].spec, stud_new.spec);

        		printf("DONE!\n");
        		return stud_arr;
        	
        }

struct students *delete_student(struct students *stud_arr, int* n){

	char nomer[16];
	printf("id of student you want delete: ");
	scanf("%s", nomer);

	int k = find_student_id(stud_arr, *n, nomer);


	if (k == -1){
		printf("There is no student with this id");
	} else {
		(*n)--;
		for (; k < *n; k++){
			stud_arr[k] = stud_arr[k+1];
		}
	} 
	printf("Complete!\n");
	return stud_arr;
}

int find_student_id(struct students *stud_arr, int n, char* id){
	for (int k = 0; k < n; k++){
		if(strcmp(id, stud_arr[k].id) == 0)
			return k;
	}
	return -1;
}

void find_by_lastname(struct students *stud_arr, int n){
	char fam[16];
	printf("Lastname of student you want to find: ");
	scanf("%s", fam);
	print_top();
	for (int i = 0; i<n; i++){
		if((strcmp(fam, stud_arr[i].fam) == 0)){
			print_student(stud_arr[i]);
			print_bottom();
		} 
	}
}

void backup_creating(struct students *stud_arr, int n){
	char FileBack[120] = {0};
	long int s_time = time(NULL);
	struct tm *m_time = localtime(&s_time);
    strftime(FileBack, 120, "students_%d.%m.%Y_%H.%M.%S.csv", m_time);
        
    FILE *back = fopen(FileBack, "w");
	for (int i = 0; i<n; i++) {

		fprintf(back, "%s;", stud_arr[i].id);
		fprintf(back, "%s;", stud_arr[i].fam);
		fprintf(back, "%s;", stud_arr[i].name);
		fprintf(back, "%s;", stud_arr[i].otch);
		fprintf(back, "%s;", stud_arr[i].facul);
		fprintf(back, "%s", stud_arr[i].spec);

		if(i<n-1)
		fprintf(back, "\n");
	}
	fclose(back);
	printf("DONE! Backup created!\n");
}


struct students *recover_back(){

	char backup[120];
	printf("Print backup name: ");
	scanf("%s", backup);

	FILE *fp = fopen(backup, "r");

	struct students *back = calloc(1, sizeof(struct students));
	int k = str_num();

	char string[150];
	int i = 0;

	while(i < k){

		back = realloc(back, (i+1) * sizeof(struct students));

		fgets(string, 150, fp);

		strcpy(back[i].id, strtok(string, ";"));
        strcpy(back[i].fam, strtok(NULL,";"));
        strcpy(back[i].name, strtok(NULL,";"));
        strcpy(back[i].otch, strtok(NULL,";"));
        strcpy(back[i].facul, strtok(NULL,";"));
        strcpy(back[i].spec, strtok(NULL,"\n"));

        i++;
	}
	fclose(fp);

	printf("List recovered!\n");
	return back;
}

void print_top(){
	printf("+------------------+--------------------+--------------------+--------------------+-------------+--------------------------------------------------+\n");
	printf("|        id        |      Lastname      |      Firstname     |      Patronumic    |    Faculty  |                      Speciality                  |\n");
	printf("+------------------+--------------------+--------------------+--------------------+-------------+--------------------------------------------------+\n");
}
void print_bottom(){
	printf("+------------------+--------------------+--------------------+--------------------+-------------+--------------------------------------------------+\n");
}

void print_student(struct students stud){
		printf("| %16s ", stud.id);
		printf("| %18s ", stud.fam);
		printf("| %18s ", stud.name);
		printf("| %18s ", stud.otch);
		printf("| %11s ", stud.facul);
		printf("| %48s |\n", stud.spec);
}

void printing_all(struct students *stud_arr,int *n){

	print_top();

	for (int i = 0; i < *n; i++){
		print_student(stud_arr[i]);
		print_bottom();
	}
}

void save(struct students *stud_arr,int n){

	FILE *fp = fopen("students.csv", "w");

	for (int i = 0; i<n; i++) {

		fprintf(fp, "%s;", stud_arr[i].id);
		fprintf(fp, "%s;", stud_arr[i].fam);
		fprintf(fp, "%s;", stud_arr[i].name);
		fprintf(fp, "%s;", stud_arr[i].otch);
		fprintf(fp, "%s;", stud_arr[i].facul);
		fprintf(fp, "%s", stud_arr[i].spec);

		if(i<n-1)
		fprintf(fp, "\n");
	}
	fclose(fp);
}
