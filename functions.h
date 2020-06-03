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

//books

struct book {
    long long ISBN;
    char author[30];
    char name[30];
    int all;
    int st;
};

struct book *read_books();

int str_book();

int find_book_ISBN(struct book *book_arr, int n, long long ISBN);

struct book *add_book(struct book *book_arr, int* n);

struct book *new_num(struct book *book_arr, int *n);

void save_books(struct book *book_arr, int n);

void print_top_b();
void print_bottom_b();
void print_book(struct book book);
void printing_all_b(struct book *book_arr,int *n);

// users

struct user {
	char login[20];
	char pass[15];
	char b[2];
	char s[2];
};

struct user *read_users();

int str_users();

struct user authorizing(struct user *us_arr);