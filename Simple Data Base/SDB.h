#ifndef EMBEDDED_SYS_SDB_H
#define EMBEDDED_SYS_SDB_H
#include "STD.h"
typedef struct studentDataBase{
    uint32 student_id;
    uint32 student_year;
    uint32 course1_id;
    uint32 course1_grade;
    uint32 course2_id;
    uint32 course2_grade;
    uint32 course3_id;
    uint32 course3_grade;
}s;
typedef struct N{
    s student;
    struct N* link;
}Node;
bool SDB_IsFull      (void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry    (void);
void SDB_DeleteEntry (uint32 id);
bool SDB_ReadEntry   (uint32 id);
void SDB_GetList     (uint8* num_of_ids, uint32* arr);
bool SDB_IsIdExist   (uint32 id);

#endif
