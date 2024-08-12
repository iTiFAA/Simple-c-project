#include "SDB.h"
#include <stdio.h>
#include "SDBAPP.h"
#define MAX_SIZE 10
void SDB_APP (){
    while(1){
        uint8 choice = 0;
        printf("1. To add entry, enter 1\n"
               "2. To get used size in database, enter 2\n"
               "3. To read student data, enter 3\n"
               "4. To get the list of all student IDs, enter 4\n"
               "5. To check is ID is existed, enter 5\n"
               "6. To delete student data, enter 6\n"
               "7. To check is database is full, enter 7\n"
               "8. To exit enter 0\n"
               "enter your choice:");
        scanf("%d",&choice);
        if(choice == 8) {
            printf("thank you!\n");
            return;
        }
       action(choice);
    }
}
void action(uint8 choice){
    switch(choice){
        case 1: {
            SDB_AddEntry();
            break;
        }
        case 2: {
            uint8 used_size;
            used_size = SDB_GetUsedSize();
            printf("the used size is %d ouf of %d",used_size,MAX_SIZE);
            break;
        }
        case 3: {
            uint32 student_id;
            printf("enter the student id:");
            scanf("%d",&student_id);
            bool exists = SDB_ReadEntry(student_id);
            if(!exists)
                printf("student id doesn't exist!\n");
            break;
        }
        case 4: {
            uint8 num_of_ids = 0;
            uint32 arr[MAX_SIZE];
            SDB_GetList(&num_of_ids,arr);
            break;
        }
        case 5:{
            uint32 student_id;
            bool exists;
            printf("enter the student id:");
            scanf("%d",&student_id);
            exists = SDB_IsIdExist(student_id);
            if(exists)
                printf("id exists\n");
            else
                printf("id doesn't exist\n");
            break;
        }
        case 6:{
            uint32 student_id;
            printf("enter the student id:");
            scanf("%d",&student_id);
            SDB_DeleteEntry(student_id);
            break;
        }
        case 7: {
            bool is_full;
            is_full = SDB_IsFull();
            if(is_full)
                printf("data base is full\n");
            else
                printf("data base isn't full\n");
            break;
        }
        default:
            printf("not a valid choice\n");
    }
}