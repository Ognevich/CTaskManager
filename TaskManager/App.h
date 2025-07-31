#define _CRT_SECURE_NO_WARNINGS
#ifndef APP_H
#define APP_H	
#include <stdio.h>
#include "Menu.h"
#include "Utills.h"
#include "TaskControler.h"
#include <windows.h>

void Run();

void taskHandler(int option, int* exit_app);
void editTaskHandler(int option);

void editTaskMenu();

#endif