#include "App.h"


void Run() {

	initTaskArr();
	getTasksFromFile();

	int option = 0;
	int exit_app = 0;

	while (exit_app != -1) {
		
		option = showMenu();
		TaskHandler(option, &exit_app);

	}


	free(task_arr);

}

void TaskHandler(int option, int * exit_app)
{

	switch (option)
	{
	case 0:
		showAllTasks();
		clearInputBuffer();
		break;
	case 1:
		showToDoTasks();
		clearInputBuffer();
		break;
	case 2:
		showCompleteTasks();
		clearInputBuffer();
		break;
	case 3:
		enterNewTaskHandler();
		break;
	case 4:
		enterDeleteTaskHandler();
		clearInputBuffer();
		break;
	case 5:
		enterEditTasksHandler();
		break;
	case 6:
		enterMarkTasksHandler();
		break;
	case 7:
		*exit_app = -1;
		break;
	default:
		break;
	}
}