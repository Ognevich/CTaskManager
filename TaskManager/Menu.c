#include "Menu.h"

const char* main_menu[MAIN_MENU_SIZE] = {
    "All Tasks\n",
    "All to do Tasks\n",
    "All Complete Tasks\n",
    "Add Task\n",
    "Delete Task\n",
    "Edit Task\n",
    "Change Task Status\n",
	"Exit\n"
};

const char* edit_task_menu[EDIT_MENU_SIZE] = {
    "Edit Full Task\n",
    "Edit Task Name\n",
    "Edit Task Description\n",
    "Exit\n"
};


int showMainMenu() {
    int menu_choice = 0;
    int pressedEnter = 0;

    while (1) {
        while (_kbhit()) _getch();

        clearScreen();

        for (int i = 0; i < MAIN_MENU_SIZE; i++) {
            if (i == menu_choice) {
                printf(" [*] %s", main_menu[i]);
            }
            else {
                printf("     %s", main_menu[i]);
            }
        }

        pressedEnter = definePressKey(&menu_choice, MAIN_MENU_SIZE);
        if (pressedEnter == 1) {
            return menu_choice;
        }

    }
}

int showEditTaskMenu()
{
    int menu_choice = 0;
    int pressedEnter = 0;

    while (1) {
        while (_kbhit()) _getch();

        clearScreen();

        for (int i = 0; i < EDIT_MENU_SIZE; i++) {
            if (i == menu_choice) {
                printf(" [*] %s", edit_task_menu[i]);
            }
            else {
                printf("     %s", edit_task_menu[i]);
            }
        }

        pressedEnter = definePressKey(&menu_choice, EDIT_MENU_SIZE);
        if (pressedEnter == 1) {
            return menu_choice;
        }

    }
}

int definePressKey(int* menu_choice, int menu_size)
{
    int ch = _getch();

    if (ch == 224) {
        ch = _getch();
        switch (ch) {
        case 72:
            if (*menu_choice > 0) (*menu_choice)--;
            break;
        case 80:
            if (*menu_choice < menu_size - 1) (*menu_choice)++;
            break;
        }
    }
    else if (ch == 13) {
        return 1;
    }
    return 0;
}