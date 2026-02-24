#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "task.h"

void Fill_Struct(struct STUDENT st[7]){
	for(int i = 0; i < 7; i++){
		printf("Студент %d:\n", i + 1);
		printf("Введите фамилию и инициалы студента: ");
		scanf(" %s", st[i].name);
		printf("Введите группу студента: ");
		scanf(" %d", &st[i].group);
		printf("Успеваемость: ");
		for (int j = 0; j < 4; j++) {
			if (i == 0) {
					st[i].marks[j] = rand() % 2 + 4; 
			} else {
					st[i].marks[j] = rand() % 5 + 1; 
			}
			printf(" %d ", st[i].marks[j]);
		}
		printf("\n");
	}
}

void Print(struct STUDENT st[7]) {
	for (int i = 0; i < 7; i++) {
		printf("\nСтудент %d:\n", i + 1);
		printf("Фамилия и инициалы: %s\n", st[i].name);
		printf("Группа: %d\n", st[i].group);
		printf("Оценки: ");
		for (int j = 0; j < 4; j++) {
			printf("%d ", st[i].marks[j]);
		}
		printf("\n");
	}
}

void Print_One(struct STUDENT st){
	printf("Фамилия и инициалы: %s\n", st.name);
	printf("Группа: %d\n", st.group);
	printf("Оценки: ");
	for (int j = 0; j < 4; j++) {
		printf("%d ", st.marks[j]);
	}
	printf("\n");
}

void Average(struct STUDENT st[7], double avg[7]){
	for(int i = 0; i < 7; i++){
		double sum = 0;
		for(int j = 0; j < 4; j++){
			sum += st[i].marks[j];
		}
		avg[i] = sum / 4.0;
	}
}

void Decrease(struct STUDENT st[7], double avg[7]){
	printf("\n");
	printf("Студенты по убыванию среднего балла:\n");
	Average(st, avg);
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 6 - i; j++){
			if(avg[j] < avg[j + 1]){ 
				double t = avg[j]; 
				avg[j] = avg[j + 1]; 
				avg[j + 1] = t; 
				struct STUDENT temp = st[j]; 
				st[j] = st[j + 1]; 
				st[j + 1] = temp;
			}
		}
	}
	for(int i = 0; i < 7; i++){
		Print_One(st[i]);
		printf("Средний балл: %f\n", avg[i]);
		printf("\n");
	}
}

void Top_Student(struct STUDENT st[7], double avg[7]){
    Average(st, avg);
	printf("\n");
	printf("Информация об отличниках:\n");
	for (int i = 0; i < 7; i++){
		bool flag = true;
		for(int j = 0; j < 4; j++){
			if(st[i].marks[j] < 4){
				flag = false;
			}
		}
		if(flag){
			Print_One(st[i]);
			printf("\n");
		}
	}
	int min = 0;
	for(int k = 0; k < 7; k++){
		if (avg[k] < avg[min]){
			min = k;
		}
	}
	for (int i = min; i < 6; i++) {
		st[i] = st[i + 1];    
		avg[i] = avg[i + 1]; 
	}
	printf("Список после удаления самого слабого:\n");
	printf("\n");
	for (int i = 0; i < 6; i++){
		Print_One(st[i]);
		printf("\n");
	}
}
