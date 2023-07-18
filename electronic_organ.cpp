#include <graphics.h>
#include <conio.h>
#include<iostream>
using namespace std;
int rythm[7] = { 262,294,330,349,392,440,494 };
void init() {
	// draw the keys
	int x = 0;
	for (int x = 0; x < 630; x++) {
		if (x < 90)	setlinecolor(RED);
		else if (x < 180)	setlinecolor(LIGHTRED);
		else if (x < 270)	setlinecolor(YELLOW);
		else if (x < 360)	setlinecolor(GREEN);
		else if (x < 450)	setlinecolor(LIGHTCYAN);
		else if (x < 540)	setlinecolor(BLUE);
		else setlinecolor(LIGHTMAGENTA);
		line(x, 0, x, 600);
	}
}

DWORD WINAPI playmic(char c) {
	int n = -1;
	if (c == 'a')	n = 0;
	else if (c == 's')	n = 1;
	else if (c == 'd')	n = 2;
	else if (c == 'f')	n = 3;
	else if (c == 'j')	n = 4;
	else if (c == 'k')	n = 5;
	else if (c == 'l')	n = 6;
	else n = -1;
	if (n != -1) {
		fillrectangle(90 * n, 500, 90 * (n + 1), 600);//show the reaction of pressing the key
		Beep(rythm[n], 500);
		init();
	}
	return 0;
}
int main()
{
	initgraph(630, 600, SHOWCONSOLE);
	init();
	char c = ' ';
	cout << "a: do	s:re	d:mi	f:fa	j:so	k:la	l:si" << endl;
	while (1) {
		c = _getch();
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)playmic, (LPVOID)c, NULL, NULL);
	}
	Sleep(30000);
	closegraph();
	return 0;
}
