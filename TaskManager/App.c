#include "App.h"


void Run() {

	initTaskArr();
	getTasksFromFile();

	int option = 0;
	int exit_app = 0;

	while (exit_app != -1) {
		
		option = showMainMenu();
		taskHandler(option, &exit_app);

	}


	free(task_arr);

}

void taskHandler(int option, int * exit_app)
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
		enterNewTaskHendler();
		break;
	case 4:
		enterDeleteTaskHandler();
		clearInputBuffer();
		break;
	case 5:
		editTaskMenu();
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

void editTaskHandler(int option)
{
	switch (option)
	{
	case 0:
		enterEditFullTasksHandler();
	case 1:
		enterEditNameTaskHandler();
		break;
	case 2:
		enterEditDescriptionTaskHandler();
		break;
	case 3:
		break;
	default:
		break;
	}

}

void editTaskMenu()
{
	int option = 0;
	option = showEditTaskMenu();
	editTaskHandler(option);

}
