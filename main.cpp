#include<stdio.h>
#include<easyx.h>
#include<time.h>


//����
//˫����
//֡�ʿ���

int main()
{
	initgraph(640, 480, EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	setbkmode(TRANSPARENT);

	//FPS 60f
	const clock_t FPS = 1000 / 60;   //1��60֡
	int startTime = 0;
	int freamTime = 0;  //��ǰ֡ʵ��ִ��ʱ��

	int score = 0;
	char str[50] = "";
	while (true)
	{

		startTime = clock();  //50ms

		sprintf(str, "Score:%d", score++);
		settextcolor(BLACK);

		//˫�����ֹ����
		BeginBatchDraw();
		cleardevice();//����

		outtextxy(20, 20, str);

		EndBatchDraw();
		
		freamTime = clock() - startTime;
		if (freamTime > 0)
		{
			Sleep(FPS - freamTime);
		}

	}
	return 0;
}