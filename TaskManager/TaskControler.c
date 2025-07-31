#include "TaskControler.h"

Tasks* task_arr = NULL;
size_t taskSize = 0;

void initTaskArr()
{
	Tasks* temp = malloc(sizeof(Tasks));

	if (temp != NULL) {
		task_arr = temp;
		taskSize = 1;
		memset(&task_arr[0], 0, sizeof(Tasks));
	}
	else {
		printf("allocated memory error\n ");
	}
}

void increaseArray()
{
	size_t new_capacity = taskSize + 1;

	Tasks* temp = realloc(task_arr, sizeof(Tasks) * new_capacity);

	if (temp != NULL) {
		task_arr = temp;
		memset(&task_arr[taskSize], 0, sizeof(Tasks));
		taskSize++;
	}
	else {
		printf("memory alloc error\n");
	}

}

void addTaskToFile(char* taskName, char* taskDescription, char * buffer, int task_status)
{
	FILE* file = fopen(TASK_PATH, "a");

	fprintf(file, "%s;%s;%s;%d\n", taskName, taskDescription, buffer, task_status);

	fclose(file);
}	

void showAllTasks()
{
	printf("=======================================\n");
	for (size_t index = 0; index < taskSize-1; index++) {
		printTaskInfo(index);
	}
	printf("=======================================\n");
}

void showToDoTasks()
{
	for (int index = 0; index < taskSize - 1; index++) {
		if (task_arr[index].taskStatus == TASK_STATUS_VALUE) {
			printTaskInfo(index);
		}
	}

}

void showCompleteTasks()
{
	for (int index = 0; index < taskSize - 1; index++) {
		if (task_arr[index].taskStatus == -TASK_STATUS_VALUE) {
			printTaskInfo(index);
		}
	}
}

void printTaskInfo(int index)
{
	char* charStatus;
	
	if (task_arr[index].taskStatus == -1) {
		charStatus = "Un Done";
	}
	else {
		charStatus = "Done";
	}

	printf("---------------------------------------\n");
	printf("Task id: %d\n", index+1);
	printf("Task Name: %s\n", task_arr[index].taskName);
	printf("Task Description: %s\n", task_arr[index].taskDescription);
	printf("Task Date: %s\n", task_arr[index].taskDate);
	printf("Task Status: %s\n", charStatus);
	printf("---------------------------------------\n\n");
}

int isIdSuitable(int taskId)
{
	if (taskId < 0 || taskId > taskSize - 2) {
		return 1;
	}
	return 0;
}

void getTasksFromFile()
{
	FILE* file = fopen(TASK_PATH, "r");

	if (!file) {
		perror("Cannot open file");
		exit(EXIT_FAILURE);
	}

	char task_name[TASK_NAME_LENGHT];
	char task_description[TASK_DESCRIPTION_LENGHT];
	char task_date[TASK_DATE_LENGTH];
	int task_status = TASK_STATUS_VALUE;

	while (fscanf(file, "%49[^;];%149[^;];%29[^;];%d\n", task_name, task_description, task_date, &task_status) == 4) {
		addTaskToArr(task_name, task_description, task_date, task_status);
	}

	fclose(file);
}

void overwriteTasksToFile()
{
	FILE* file = fopen(TASK_PATH, "w");

	for (int i = 0; i < taskSize-1; i++)
		fprintf(file, "%s;%s;%s;%d\n", task_arr[i].taskName, task_arr[i].taskDescription, task_arr[i].taskDate, task_arr[i].taskStatus);

	fclose(file);
}

void addTaskToArr(char* taskName, char* taskDescription, char* taskDate, int taskStatus)
{
	strcpy(task_arr[taskSize-1].taskName, taskName);
	strcpy(task_arr[taskSize - 1].taskDescription, taskDescription);
	strcpy(task_arr[taskSize - 1].taskDate, taskDate);
	task_arr[taskSize - 1].taskStatus = taskStatus;
	increaseArray();
}

void deleteTaskFromArray(int task_id)
{
	int newTaskId = task_id - 1;
	
	int idCheck = isIdSuitable(newTaskId);

	if(idCheck == 1){
		printf("Tasks with this id don't exitst\n");
		return;
	}

	for (int i = newTaskId; i < taskSize-1; i++) {
		if (i == taskSize - 2) {
			task_arr[i].taskName[0] = '\0';
			task_arr[i].taskDescription[0] = '\0';
			task_arr[i].taskDate[0] = '\0';
			task_arr[i].taskStatus = TASK_STATUS_VALUE;
		
			taskSize--;
		}
		else { 
			task_arr[i] = task_arr[i + 1]; }
	}



}

void editFullTask(int taskId, char* taskName, char* taskDescription)
{
	int newTaskId = taskId - 1;

	int idCheck = isIdSuitable(newTaskId);

	if (idCheck == 1) {
		printf("Tasks with this id don't exitst\n");
		return;
	}

	strcpy(task_arr[newTaskId].taskName, taskName);
	strcpy(task_arr[newTaskId].taskDescription, taskDescription);

}

void editTaskName(int taskId, char* taskName)
{
	int newTaskId = taskId - 1;

	int idCheck = isIdSuitable(newTaskId);

	if (idCheck == 1) {
		printf("Tasks with this id don't exitst\n");
		return;
	}

	strcpy(task_arr[newTaskId].taskName, taskName);
}

void editTaskDescription(int taskId, char* taskDescription) {

	int newTaskId = taskId - 1;

	int idCheck = isIdSuitable(newTaskId);

	if (idCheck == 1) {
		printf("Tasks with this id don't exitst\n");
		return;
	}

	strcpy(task_arr[newTaskId].taskDescription, taskDescription);
}


void editMark(int taskId)
{
	int newTaskId = taskId - 1;

	int idCheck = isIdSuitable(newTaskId);

	if (idCheck == 1) {
		printf("Tasks with this id don't exitst\n");
		return;
	}

	task_arr[newTaskId].taskStatus = -(task_arr[newTaskId].taskStatus);
}

void enterNewTaskHendler()
{
	
	char taskNameBuffer[TASK_NAME_LENGHT];
	char descriptionTaskBuffer[TASK_DESCRIPTION_LENGHT];
	char buffer[TASK_DATE_LENGTH];
	int task_status = TASK_STATUS_VALUE;

	printf("Enter Task Name: \n");
	fgets(taskNameBuffer, sizeof(taskNameBuffer), stdin);
	taskNameBuffer[strcspn(taskNameBuffer, "\n")] = '\0';

	printf("Enter Task Description: \n");
	fgets(descriptionTaskBuffer, sizeof(descriptionTaskBuffer), stdin);
	descriptionTaskBuffer[strcspn(descriptionTaskBuffer, "\n")] = '\0';

	getCurrentDate(buffer, sizeof(buffer));

	addTaskToArr(taskNameBuffer, descriptionTaskBuffer, buffer, task_status);
	addTaskToFile(taskNameBuffer, descriptionTaskBuffer, buffer, task_status);;
}

void enterDeleteTaskHandler()
{
	int taskID = 0;

	printf("Enter task id to delete: ");
	scanf("%d", &taskID);
	scanf("%*c");

	deleteTaskFromArray(taskID);
	overwriteTasksToFile();

}

void enterEditFullTasksHandler()
{
	int taskID = 0;
	char taskNameBuffer[TASK_NAME_LENGHT];
	char descriptionTaskBuffer[TASK_DESCRIPTION_LENGHT];

	printf("Enter task id to edit: ");
	scanf("%d", &taskID);
	scanf("%*c");

	printf("Enter Task Name: \n");
	fgets(taskNameBuffer, sizeof(taskNameBuffer), stdin);
	taskNameBuffer[strcspn(taskNameBuffer, "\n")] = '\0';

	printf("Enter Task Description: \n");
	fgets(descriptionTaskBuffer, sizeof(descriptionTaskBuffer), stdin);
	descriptionTaskBuffer[strcspn(descriptionTaskBuffer, "\n")] = '\0';

	editFullTask(taskID, taskNameBuffer, descriptionTaskBuffer);
	overwriteTasksToFile();

}

void enterEditNameTaskHandler()
{
	int taskID = 0;
	char taskNameBuffer[TASK_NAME_LENGHT];

	printf("Enter task id to edit: ");
	scanf("%d", &taskID);
	scanf("%*c");

	printf("Enter Task Name: \n");
	fgets(taskNameBuffer, sizeof(taskNameBuffer), stdin);
	taskNameBuffer[strcspn(taskNameBuffer, "\n")] = '\0';

	editTaskName(taskID, taskNameBuffer);
	overwriteTasksToFile();

}

void enterEditDescriptionTaskHandler()
{
	int taskID = 0;
	char descriptionTaskBuffer[TASK_DESCRIPTION_LENGHT];

	printf("Enter task id to edit: ");
	scanf("%d", &taskID);
	scanf("%*c");

	printf("Enter Task Description: \n");
	fgets(descriptionTaskBuffer, sizeof(descriptionTaskBuffer), stdin);
	descriptionTaskBuffer[strcspn(descriptionTaskBuffer, "\n")] = '\0';

	editTaskDescription(taskID, descriptionTaskBuffer);
	overwriteTasksToFile();
}

void enterMarkTasksHandler()
{
	int taskID = 0;

	printf("Enter task id to change mark: ");
	scanf("%d", &taskID);
	scanf("%*c");

	editMark(taskID);
	overwriteTasksToFile();
}

