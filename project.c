/*
 ============================================================================
 Name        : project.c
 Author      : Abdelrahman Hassan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//structure containing variables that will be used for each student
struct student{
	char name[50];
	int id;
	float GPA;
	int Age;
};
//structure will be used for creating the linked list of students
struct node{
	struct student data;
	struct node *next;
};
struct node *head = NULL;
//declaration for all code functions
void AddStudent(void);
void displayAllStudents(void);
void searchByid(int id);
void updateByid(int id);
void deleteStudentByid(int id);
void calculateAvrg(void);
void findMax(void);
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);
	int flag = 1;  //flag will be equal zero when user decide to terminate the program
	int func;  //variable decide which function will be called
	int idsearch; //variable carry the id for the functions that need id to search
	while(flag){
		printf("enter 1 to add student \n");
		printf("enter 2 to display all \n");
		printf("enter 3 to search by id \n");
		printf("enter 4 to edit student info by id \n");
		printf("enter 5 to delete student by id \n");
		printf("enter 6 to calculate the average GPA \n");
		printf("enter 7 to get the highest GPA \n");
		printf("enter 0 to terminate \n");
		scanf("%d" , &func);
		//switch case to call the needed function
		switch (func){
		case 1 :
			AddStudent();
			break;
		case 2 :
			displayAllStudents();
			break;
		case 3 :
			printf("enter the id ");
			scanf("%d" , &idsearch);
			searchByid(idsearch);
			break;
		case 4 :
			printf("enter the id ");
			scanf("%d" , &idsearch);
			updateByid(idsearch);
			break;
		case 5 :
			printf("enter the id ");
			scanf("%d" , &idsearch);
			deleteStudentByid(idsearch);
			break;
		case 6 :
			calculateAvrg();
			break;
		case 7 :
			findMax();
			break;
		case 0 :
			flag = 0;  //making the flag equals zero to break the while loop
			printf("END");
			break;
		default :
			printf("please enter a valid input \n");
			break;
		}
	}
	return EXIT_SUCCESS;
}
//function to add new student to the linked list from right (away from the head)
void AddStudent(void){
	struct node *link = (struct node*)malloc(sizeof(struct node));
	//condition checks if the allocation failed
	if(link == NULL){
		printf("----------------------------------------- \n");
		printf("no enough space to add new student");
		printf("----------------------------------------- \n");
		return;
	}

	int ids;
	struct node *temp2 = head;
	// if condition to check if the linked list is empty to add the student in the first node
	if(head == NULL){
		link->next = NULL;
		head = link;
	}
	else{
		struct node *temp = head;
		link->next = NULL;
		while(temp->next != NULL){
			temp = temp -> next;
		}
		temp->next = link;
	}
	//taking all the inputs from the user
	printf("please enter student data \n");
	printf("please enter student id \n");
	scanf("%d" , &ids);
	//while loop checks if the entered id is already exist
	while(temp2 != NULL){
		if(temp2 ->data.id == ids){
			printf("----------------------------------------- \n");
			printf("this is is already exist \n");
			printf("----------------------------------------- \n");
			return;
		}
		temp2 = temp2->next;
	}
	link->data.id = ids;
	printf("please enter student name : ");
	scanf("%s" , &(link->data.name));
	printf("please enter student's GPA : ");
	scanf("%f" , &(link->data.GPA));
	printf("please enter student's Age : ");
	scanf("%d" ,&(link->data.Age));

	printf("----------------------------------------- \n");

}
//function loops on all the linked list and prints all the needed info
void displayAllStudents(void){
	struct node *temp = head;
	//if condition ensure that the linked list is not empty
	if( head == NULL){
		printf("the system is empty \n");
	}
	//while loop to print all linked list info
	while(temp != NULL){
		printf("student name : %s \n" , temp->data.name);
		printf("student ID : %d \n" , temp->data.id);
		printf("student GPA : %f \n" , temp->data.GPA);
		printf("student Age : %d \n" , temp->data.Age);
		printf("------------------------------------------------------- \n");
		temp = temp->next;
	}
}
//function takes the id as an input and print all the info if the id was found and print the student not found if the id not found
void searchByid(int id){
	struct node *temp = head;
	//if condition ensure that the linked list is not empty
	if( head == NULL){
		printf("the system is empty \n");
	}
	//while loop to print the info if the id was found
	while(temp != NULL){
		if(temp->data.id == id){
			printf("------------------------------------------------------- \n");
			printf("student name : %s \n" , temp->data.name);
			printf("student ID : %d \n" , temp->data.id);
			printf("student GPA : %f \n" , temp->data.GPA);
			printf("student Age : %d \n" , temp->data.Age);
			printf("------------------------------------------------------- \n");
			return;
		}
		temp = temp ->next;
	}
	printf("student not found \n");
}
//function takes the id as an input and search for it and if found makes the user able to edit the existing info
void updateByid(int id){
	struct node *temp = head;
	//if condition ensure that the linked list is not empty
	if( head == NULL){
		printf("the system is empty \n");
	}
	//while loop to edit the info if the id was found
	while(temp != NULL){
		if(temp->data.id == id){
			printf("please enter student data \n");
			printf("please enter student name : ");
			scanf("%s" , &(temp->data.name));
			printf("please enter student's GPA : ");
			scanf("%f" , &(temp->data.GPA));
			printf("please enter student's Age : ");
			scanf("%d" ,&(temp->data.Age));//all the prev code is to take the input from the user
			printf("-------------------------------------------------------- \n");
			printf("student info updated successfully \n");
			printf("-------------------------------------------------------- \n");
			return;
		}
		temp = temp -> next;
	}
	printf("student not found \n");
}
//function takes the id as an input and delete all the info if the id was found and print the student not found if the id not found
void deleteStudentByid(int id){
	struct node *temp = head;
	//if condition ensure that the linked list is not empty
	if( head == NULL){
		printf("the system is empty \n");
	}
	//if condition checks if the node to be deleted is the first node
	if(temp->data.id == id){
		head = temp->next;
		printf("the student deleted \n");
		return;
	}
	//while loop loops on the linked list till it finds the node to be deleted and delete it
	while(temp->next != NULL){
		if(temp->next->data.id == id){
			struct node *delete = temp->next;
			temp->next = temp->next->next;
			printf("-------------------------------------------------------- \n");
			printf("the student deleted \n");
			printf("-------------------------------------------------------- \n");
			free(delete);
			return;
		}
		temp = temp-> next;
	}
	printf("student not found \n");
}
//function loops on the linked list and calculate the average of the GPAs
void calculateAvrg(void){
	struct node *temp = head;
	float sum = 0; //variable will carry the sum of all GPAs
	int count = 0; //variable will carry the total number of students
	//if condition ensure that the linked list is not empty
	if( head == NULL){
		printf("the system is empty \n");
	}
	while(temp != NULL){
		sum += temp->data.GPA;
		count++;
		temp = temp -> next;
	}
	printf("-------------------------------------------------------- \n");
	printf("the average of all GPAs is : %f \n" , (sum/count)); // print the average --> (sum / number)
	printf("-------------------------------------------------------- \n");
}
//function find the max GPA of all students and print his/her info
void findMax(void){
	struct node *temp = head;
	int max = temp->data.GPA; //variable will carry the max GPA
	int id = temp->data.id;  // variable will carry the id of the student with highest GPA
	//if condition ensure that the linked list is not empty
	if( head == NULL){
		printf("the system is empty \n");
	}
	while(temp != NULL){
		if(temp->data.GPA > max){
			max = temp->data.GPA;
			id = temp->data.id;
		}

		temp = temp -> next;
	}
	searchByid(id); // calling the function searchByid to print the info of the student with highest id
}
