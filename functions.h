#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// students

struct students {
	char id[16];
	char fam[18];
	char name[18];
	char otch[18];
	char facul[18];
	char spec[48];
};

struct students* read_list();

struct students *add_stud(struct students *stud_arr, int* n);

struct students *delete_student(struct students *stud_arr, int* n);

int find_student_id(struct students *stud_arr, int n, char* id);

void find_by_lastname(struct students *stud_arr, int n);

void backup_creating(struct students *stud_arr, int n);
struct students *recover_back();

void print_top();
void print_bottom();
void print_student(struct students stud);
void printing_all(struct students *stud_arr,int *n);

void save(struct students *stud_arr, int n);

int str_num();


// users

struct user {
	char login[20];
	char pass[15];
	char b;
	char s;
};

struct user users* read_users();