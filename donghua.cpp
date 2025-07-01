#include<stdio.h>
#include<easyx.h>
#include<time.h>

int main()
{
	initgraph(480, 800, EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice;

	//¶¯»­
	IMAGE img_enemy[4];
	char path[100] = { 0 };
	for (int i = 0;i < 4;i++)
	{
		sprintf(path, "   %d.png", i+1);
		loadimage(img_enemy + i, path);
	}
	const int frameDelay = 1000 / 60;
	int frameStart = 0;
	int frameTime = 0;
	int index = 0;
	int speed = 500;
	int freams = 4;

	while (true)
	{
		frameStart = clock();

		BeginBatchDraw();
		cleardevice;

		drawImg(0, 0, img_enemy + index);

		EndBatchDraw();

		index = (clock() / speed)%freams;

		frameTime = clock() - frameStart;
		if (frameDelay - frameTime > 0)
		{
			Sleep(frameDelay - frameTime);
		}

	}

	getchar();
	return 0;
}