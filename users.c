#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


struct user *read_users(){
	FILE *fp = fopen("users.csv", "r");

	struct user *us_arr = calloc(1, sizeof(struct user));
	int k = str_users();

	char string[60];
	int i = 0;

	while(i < k){

		fgets(string, 60, fp);

		strcpy(us_arr[i].login, strtok(string, ";"));
        strcpy(us_arr[i].pass, strtok(NULL,";"));
        strcpy(us_arr[i].b, strtok(NULL,";"));
        strcpy(us_arr[i].s, strtok(NULL,"\n"));

        i++;

        us_arr = realloc(us_arr, (i+1) * sizeof(struct user));
	}
	fclose(fp);
	return us_arr;
}

int str_users(){
	int line = 0;
	FILE *f = fopen("users.csv", "r");
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

struct user authorizing(struct user *us_arr){

	int flag = 0;
	struct user using;
	strcpy(using.b, "");
	strcpy(using.s, "");

	while(flag == 0){

	//login

		printf("Login:\n");
		scanf("%s", using.login);

	int k = 0;
	int n = str_users();
		for(int i = 0; i < n; i++){
			if(strcmp(using.login, us_arr[i].login) == 0){
				k = i;
			} 
		}
		

	//password
		printf("Password: \n");
		scanf("%s", using.pass);
	
		if(strcmp(using.pass, us_arr[k].pass) == 0){
			flag = 1;
			strcpy(using.b, us_arr[k].b);
			strcpy(using.s, us_arr[k].s);
		} else {
			printf("Wrong password\n");
		}
	}
	
	return using;
}
