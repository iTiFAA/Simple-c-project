#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#define MAS_SIZE 10
#define MIN_SIZE 3

uint8 num_of_entries = 0;
Node* start = NULL;

bool SDB_IsFull(void){
    //returns true of it's full and false if else
    return (num_of_entries >= MAS_SIZE);
}
uint8 SDB_GetUsedSize(void){
    //it returns the number of entries
    return num_of_entries;
}
bool SDB_AddEntry(void){
    //declaring a variable to mark if the adding is done or not
    bool isAdded = false;
    //checking if the DB is full or not
    if(num_of_entries <= MAS_SIZE-1) {
        //checking if the list is empty or not
        if (num_of_entries == 0) {
            //creating a list with the minimum number of entries MIN_SIZE
            for (uint8 i = 0; i < MIN_SIZE; ++i) {
                //allocating a new memory of size node on the heap and assigning its address to a pointer
                Node *temp = malloc(sizeof(Node));
                //assigning the first node address to the new node through temp
                temp->link = start;
                //assigning the new node address to start through temp
                start = temp;
                //getting data from user
                //student info
                printf("enter student id:");
                scanf("%d", &start->student.student_id);
                printf("enter student year:");
                scanf("%d", &start->student.student_year);
                //course 1
                printf("enter course1 id:");
                scanf("%d", &start->student.course1_id);
                printf("enter course1 grade:");
                scanf("%d", &start->student.course1_grade);
                //course 2
                printf("enter course2 id:");
                scanf("%d", &start->student.course2_id);
                printf("enter course2 grade:");
                scanf("%d", &start->student.course2_grade);
                //course 3
                printf("enter course3 id:");
                scanf("%d", &start->student.course3_id);
                printf("enter course3 grade:");
                scanf("%d", &start->student.course3_grade);
            }
            //increase the num of entries by the minimum number of entries we added
            num_of_entries += MIN_SIZE;
        } else {
            //if the list isn't empty we add only a one entry
            Node *temp = malloc(sizeof(Node));
            temp->link = start;
            start = temp;
            //student info
            printf("enter student id:");
            scanf("%d", &start->student.student_id);
            printf("enter student year:");
            scanf("%d", &start->student.student_year);
            //course 1
            printf("enter course1 id:");
            scanf("%d", &start->student.course1_id);
            printf("enter course1 grade:");
            scanf("%d", &start->student.course1_grade);
            //course 2
            printf("enter course2 id:");
            scanf("%d", &start->student.course2_id);
            printf("enter course2 grade:");
            scanf("%d", &start->student.course2_grade);
            //course 3
            printf("enter course3 id:");
            scanf("%d", &start->student.course3_id);
            printf("enter course3 grade:");
            scanf("%d", &start->student.course3_grade);
            ++num_of_entries;
        }
        //after addition is done we mark isAdded as true
        isAdded = true;
    }
    else{
        //if the list is full we print this statement and return false
        printf("data base is full!");
    }
    //we return isAdded to the user
    return isAdded;
}
void SDB_DeleteEntry (uint32 id){
    //we check if the wanted node is the first one or not
    if(start->student.student_id == id){
        //we declare a new pointer and assign start address to it
        Node* temp = start;
        //we assign the second node address to start through temp
        start = start->link;
        //we free the storage of the first node
        free(temp);
    }
    else {
        //we declare a new pointer and assign start address to it
        Node *temp = start;
        //we loop through the whole list to find the wanted entry
        while (temp->link != NULL) {
            if (temp->link->student.student_id == id) {
                //we declare a new pointer to node and assign the wanted node's addresss to it
                Node *t = temp->link;
                //we assign the address of the node after the wanted one to the node before the wanted one
                temp->link = temp->link->link;
                //we free the memory of the wanted entry
                free(t);
                //we break after finding the wanted one
                break;
            } else {
                //we keep looping through the list
                temp = temp->link;
            }
        }
    }
}
bool SDB_ReadEntry(uint32 id){
    //we declare a pointer to node and a variable to track if we found the entry or not
    Node* temp = start;
    bool isFound = false;
    //we loop through the whole list
    while(temp != NULL){
        if(temp->student.student_id == id){
            //if we found the wanted entry we mark isFound as true
            isFound = true;
            //we print the entry's info
            //student info
            printf("student id:%d\n",temp->student.student_id);
            printf("student year:%d\n",temp->student.student_year);
            printf("---------------\n");
            //course 1
            printf("course1 id:%d\n",temp->student.course1_id);
            printf("course1 grade:%d\n",temp->student.course1_grade);
            //course 2
            printf("course2 id:%d\n",temp->student.course2_id);
            printf("course2 grade:%d\n",temp->student.course2_grade);
            //course 3
            printf("course3 id:%d\n",temp->student.course3_id);
            printf("course3 grade:%d\n",temp->student.course3_grade);
            break;
        }
        else{
            //we keep iterating through the list
            temp = temp->link;
        }
    }
    return isFound;
}
void SDB_GetList(uint8* num_of_ids, uint32* arr){
    //we assign the num of entries to the variable num_of_ids
    *num_of_ids = num_of_entries;
    //we declare a new pointer to a node
    Node*temp = start;
    //we loop through the whole list and add id's values to the array
    for(int i = 0;i<num_of_entries;++i){
        arr[i] = temp->student.student_id;
        temp = temp->link;
    }
}
bool SDB_IsIdExist(uint32 id){
    //declaring a new pointer to a node
    Node* temp = start;
    //declaring a new bool variable to track if the id exists or not
    bool isFound = false;
    //we loop through the whole list looking for id
    while(temp != NULL){
        if(temp->student.student_id == id){
            //if the id exists we mark isFound as true and break the loop
            isFound = true;
            break;
        }
        else{
            //we keep iterating through the loop
            temp = temp->link;
        }
    }
    return isFound;
}

