#include<stdio.h>
#include<easyx.h>

int main()
{
	initgraph(359, 515, EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	//����ͼƬ����
	IMAGE img_game;
	//����ͼƬ
	loadimage(&img_game, "C:\\Users\\yqy\\Desktop\\a game.png");//Ҳ���������·��
	//���ͼƬ
	putimage(0, 0, &img_game);

	//͸��ͼ��ͼ

	IMAGE img_plane[2];//���������飬��������������&
	
	loadimage(img_plane+0, "");
	loadimage(img_plane+1, "");
	putimage(50, 100, img_plane+0,NOTSRCERASE);//�Ȼ�������ͼ
	putimage(50, 100, img_plane+1,SRCINVERT);//�ٻ���ԭͼ

	/*
	//PNGͼƬ͸����ͼ,��Ҫ��д��tools��
	IMAGE img_png;
	loadimage(&img_png, "");
	putimage(50, 100, &img_png);
	drawImg(200, 200, &img_png);
	*/

	getchar();
	return 0;
}