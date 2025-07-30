#include "Utills.h"

void clearScreen()
{
	system("cls");
}

void getCurrentDate(char* buffer, size_t size) {
    time_t now = time(NULL);                 
    struct tm* local = localtime(&now);     
	strftime(buffer, size, "%d.%m.%Y %H:%M", local);
}

void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void wait(int milliseconds) {
	DWORD start = GetTickCount();
	while (GetTickCount() - start < milliseconds);
}