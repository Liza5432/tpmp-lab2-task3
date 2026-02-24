#ifndef TASK_H
#define TASK_H

struct STUDENT {
    char name[50];
    int group;
    int marks[4];
};

void Fill_Struct(struct STUDENT st[7]);
void Average(struct STUDENT st[7], double avg[7]);
void Decrease(struct STUDENT st[7], double avg[7]);
void Top_Student(struct STUDENT st[7], double avg[7]);
void Print_One(struct STUDENT st);

#endif

