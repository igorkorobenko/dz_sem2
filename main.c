#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"


void students(){
	int n = str_num();
	struct students *stud_arr = read_list();
	int num = 0;

	while (num != 7){
		printf("Students list:\n");
		printf("1 - add new student\n");
		printf("2 - delete a student by an id\n");
		printf("3 - create backup\n");
		printf("4 - recovering of list from backup\n");
		printf("5 - find a student by lastname\n");
		printf("6 - print all \n");
		printf("7 - exit\n");
		printf("\ncommand: ");
		scanf("%d", &num);

		if (num > 7 || num < 1){
			printf("ERROR: print numbers from 1 to 6\n");
			printf("\ncommand: ");
			scanf("%d", &num);
		}

		switch (num){
			case 1:
			stud_arr = add_stud(stud_arr, &n);
			break;

			case 2:
			stud_arr = delete_student(stud_arr, &n);
			break;

			case 3:
			backup_creating(stud_arr, n);
			break;

			case 4:
			stud_arr = recover_back();
			break;

			case 5:
			find_by_lastname(stud_arr, n);
			break;

			case 6:
			printing_all(stud_arr, &n);
			break;
		
		}
		putchar('\n');
	}

	save(stud_arr, n);
	free(stud_arr);

}

void books(){
	int n = str_book();
	struct book *book_arr = read_books();
	int num = 0;

	while (num != 4){
		printf("Books list:\n");
		printf("1 - add new book\n");
		printf("2 - change books num by ISBN\n");
		printf("3 - print all books\n");
		printf("4 - exit\n");
		printf("\ncommand: ");
		scanf("%d", &num);

		if (num > 4  || num < 1){
			printf("ERROR: print numbers from 1 to 6\n");
			printf("\ncommand: ");
			scanf("%d", &num);
		}

		switch (num){
			case 1:
			book_arr = add_book(book_arr, &n);
			break;

			case 2:
			book_arr = new_num(book_arr, &n);
			break;

			case 3:
			printing_all_b(book_arr, &n);
			break;
		
		}
		putchar('\n');
	}
	save_books(book_arr, n);
	free(book_arr);
}


int main(){
	struct user *us_arr = read_users();
	struct user comp = authorizing(us_arr);
	int num = 0;
 
	if ((strcmp(comp.s,"1") == 0) && (strcmp(comp.b,"1") == 0)){
		while (num != 3){
		printf("Command list:\n");
		printf("1 - students\n");
		printf("2 - books\n");
		printf("3 - exit\n");
		printf("\ncommand: ");
		scanf("%d", &num);

		switch (num) {
			case 1:
			students();
			break;

			case 2:
			books();
			break;
		}
	}

	} else if ((strcmp(comp.s,"1") == 0) && (strcmp(comp.b,"1") != 0)){
		while (num != 2){
		printf("Command list:\n");
		printf("1 - students\n");
		printf("2 - exit\n");
		printf("\ncommand: ");
		scanf("%d", &num);

		switch (num) {
			case 1:
			students();
			break;
		}

	}

	} else if ((strcmp(comp.s,"1") != 0) && (strcmp(comp.b,"1") == 0)){
		while (num != 2){
		printf("Command list:\n");
		printf("1 - books\n");
		printf("2 - exit\n");
		printf("\ncommand: ");
		scanf("%d", &num);

		switch (num) {
			case 1:
			books();
			break;
		}
	}
	}	
	free(us_arr);
	return 0;
}
