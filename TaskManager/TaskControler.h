#define _CRT_SECURE_NO_WARNINGS
#ifndef TASK_CONTROLER_H
#define TASK_CONTROLER_H
#include "stdio.h"
#include "Utills.h"

#define TASK_PATH "Tasks.txt"

// LENGHT DEFINES;
#define TASK_NAME_LENGHT 50
#define TASK_DESCRIPTION_LENGHT 150
#define TASK_DATE_LENGTH 30
#define TASK_STATUS_VALUE -1

typedef struct {

	char taskName[TASK_NAME_LENGHT];
	char taskDescription[TASK_DESCRIPTION_LENGHT];
	char taskDate[TASK_DATE_LENGTH];
	int taskStatus;
	
}Tasks;

extern Tasks* task_arr;
extern size_t taskSize;

void initTaskArr();

// FILE FUNCTIONS
void addTaskToFile(char *taskName, char *taskDescription, char * buffer, int task_status);
void getTasksFromFile();
void overwriteTasksToFile();

//FUNTIONS THAT OUTPUT MESSAGE
void showAllTasks();
void showToDoTasks();
void showCompleteTasks();
void printTaskInfo(int index);

int isIdSuitable(int taskId);

// HANDLERS
void addTaskToArr(char * taskName, char * taskDescription, char* taskDate, int taskStatus);
void deleteTaskFromArray(int task_id);
void editFullTask(int taskId, char* taskName, char* taskDescription);
void editTaskName(int taskId, char* taskName);
void editTaskDescription(int taskID, char *descriptionTaskBuffer);
void editMark(int taskId);

// ENTER SOME INFO
void enterNewTaskHendler();
void enterDeleteTaskHandler();
void enterEditFullTasksHandler();
void enterEditNameTaskHandler();
void enterEditDescriptionTaskHandler();
void enterMarkTasksHandler();

#endif