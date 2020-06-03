#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

struct book *read_books(){

	FILE *fp = fopen("books.csv", "r");

	struct book *book_arr = malloc(sizeof(struct book));
	int k = str_book();

	char string[100];
	int i = 0;

	while(i < k){

		book_arr = realloc(book_arr, (i+1) * sizeof(struct book));

		fgets(string, 100, fp);

		book_arr[i].ISBN = atoll(strtok(string, ";"));
        strcpy(book_arr[i].author, strtok(NULL,";"));
        strcpy(book_arr[i].name, strtok(NULL,";"));
        book_arr[i].all = atoi(strtok(NULL,";"));
        book_arr[i].st = atoi(strtok(NULL,"\n"));

        i++;
	}
	fclose(fp);

	return book_arr;
}	

int str_book(){
	int line = 0;
	FILE *f = fopen("books.csv", "r");
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

int find_book_ISBN(struct book *book_arr, int n, long long ISBN){
	for (int k = 0; k<n; k++){
		if(book_arr[k].ISBN == ISBN)
			return k;
	}
	return -1;
}


struct book *add_book(struct book *book_arr, int *n){
		struct book book_new;

		printf("ISBN of book: \n");
		scanf("%lld", &book_new.ISBN);

		if (find_book_ISBN(book_arr, *n, book_new.ISBN) != -1){
			printf("ERROR: we alredy have a book with this ISBN\n");
			return book_arr;
		}

		printf("Author of book: \n");
        scanf("%s", book_new.author);

        printf("Name of book: \n");
        scanf("%s", book_new.name);

        printf("Number of all books: \n");
        scanf("%d", &book_new.all);

        printf("Availible books: \n");
        scanf("%d", &book_new.st);


        		(*n)++;
        		book_arr = realloc(book_arr, (*n+1) * sizeof(struct book));
        		book_arr[*n-1].ISBN = book_new.ISBN;
        		strcpy(book_arr[*n-1].author, book_new.author);
        		strcpy(book_arr[*n-1].name, book_new.name);
        		book_arr[*n-1].all = book_new.all;
        		book_arr[*n-1].st = book_new.st;

        		printf("DONE!\n");

        		return book_arr;
}

struct book *new_num(struct book *book_arr, int *n){

	long long ISBN;
	printf("ISBN of book: \n");
	scanf("%lld", &ISBN);
	int k = find_book_ISBN(book_arr, *n, ISBN);

	if (k == -1){
		printf("ERROR: we have not a book with this ISBN\n");
		return book_arr;
	}

	int a = 0;
	int st = 0;
	printf("New num of all books: ");
	scanf("%d", &a);

	book_arr[k].all = a;

	printf("New num of availible books: ");
	scanf("%d", &st);

	book_arr[k].st = st;

	printf("DONE!\n");

	return book_arr;
}



void save_books(struct book *book_arr, int n){
	FILE *fp = fopen("books.csv", "w");

	for (int i = 0; i<n; i++) {

		fprintf(fp, "%lld;", book_arr[i].ISBN);
		fprintf(fp, "%s;", book_arr[i].author);
		fprintf(fp, "%s;", book_arr[i].name);
		fprintf(fp, "%d;", book_arr[i].all);
		fprintf(fp, "%d;", book_arr[i].st);

		if(i<n-1)
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void print_top_b(){
	printf("+------------------+--------------------+--------------------+---------+-------------+\n");
	printf("|       ISBN       |       Author       |    Name of book    |   All   |  Availible  |\n");
	printf("+------------------+--------------------+--------------------+---------+-------------+\n");
}
void print_bottom_b(){
	printf("+------------------+--------------------+--------------------+---------+-------------+\n");
}

void print_book(struct book book){
		printf("| %16lld ", book.ISBN);
		printf("| %18s ", book.author);
		printf("| %18s ", book.name);
		printf("| %7d ", book.all);
		printf("| %11d |\n", book.st);
}

void printing_all_b(struct book *book_arr,int *n){

	print_top_b();

	for (int i = 0; i < *n; i++){
		print_book(book_arr[i]);
		print_bottom_b();
	}
}