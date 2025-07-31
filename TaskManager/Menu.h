#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include "TaskControler.h"
#include <conio.h>

#define MAIN_MENU_SIZE 8
#define EDIT_MENU_SIZE 4

int showMainMenu();
int showEditTaskMenu();

int definePressKey(int * menu_choice, int menu_size);

#endif 
