#include "Menu.h"

const char* menu[MENU_SIZE] = {
    "All Tasks\n",
    "All to do Tasks\n",
    "All Complete Tasks\n",
    "Add Task\n",
    "Delete Task\n",
    "Edit Task\n",
    "Mark Task as Complete\n",
	"Exit\n"
};

int showMenu() {
    int menu_choice = 0;

    while (1) {
        while (_kbhit()) _getch();

        clearScreen();

        for (int i = 0; i < MENU_SIZE; i++) {
            if (i == menu_choice) {
                printf(" [*] %s", menu[i]);
            }
            else {
                printf("     %s", menu[i]);
            }
        }

        int ch = _getch();

        if (ch == 224) {
            ch = _getch();
            switch (ch) {
            case 72:
                if (menu_choice  > 0) menu_choice--;
                break;
            case 80:
                if (menu_choice < MENU_SIZE - 1) menu_choice++;
                break;
            }
        }
        else if (ch == 13) {
            return menu_choice;
        }
    }
}