#include <graphics.h>
#include <conio.h>
#include<iostream>
using namespace std;
void init() {
	// »­ÇÙ¼ü
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
void playmic(int n, int* rythm) {
	fillrectangle(90 * n, 500, 90 * (n + 1), 600);//µã»÷Ð§¹û
	Beep(rythm[n], 500);//ÀÖ·û
	init();
}
int main()
{
	int rythm[7] = { 262,294,330,349,392,440,494 };
	initgraph(630, 600, SHOWCONSOLE);
	init();
	char n = ' ';
	cout << "a: do	s:re	d:mi	f:fa	j:so	k:la	l:si" << endl;
	while (1) {
		n = _getch();
		switch (n) {
		case 'a'://do
			playmic(0, rythm);
			break;
		case 's'://re
			playmic(1, rythm);
			break;
		case 'd'://mi
			playmic(2, rythm);
			break;
		case 'f'://fa
			playmic(3, rythm);
			break;
		case 'j'://so
			playmic(4, rythm);
			break;
		case 'k'://la
			playmic(5, rythm);
			break;
		case 'l'://si
			playmic(6, rythm);
			break;
		default:
			break;
		}
	}
	Sleep(30000);
	closegraph();
	return 0;
}