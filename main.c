#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "students.h"


int main() {
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
		printf("7 - program off\n");
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

	return 0;
}

int main(){
	struct user *us_arr = read_users();
	struct user comp = authorizing(us_arr);

	return 0;
}

