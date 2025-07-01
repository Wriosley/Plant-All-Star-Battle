#include<stdio.h>
#include<easyx.h>

int main()
{
	initgraph(359, 515, EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	//定义图片变量
	IMAGE img_game;
	//加载图片
	loadimage(&img_game, "C:\\Users\\yqy\\Desktop\\a game.png");//也可以用相对路径
	//输出图片
	putimage(0, 0, &img_game);

	//透明图贴图

	IMAGE img_plane[2];//可以用数组，不用数组下面有&
	
	loadimage(img_plane+0, "");
	loadimage(img_plane+1, "");
	putimage(50, 100, img_plane+0,NOTSRCERASE);//先绘制掩码图
	putimage(50, 100, img_plane+1,SRCINVERT);//再绘制原图

	/*
	//PNG图片透明贴图,需要编写的tools包
	IMAGE img_png;
	loadimage(&img_png, "");
	putimage(50, 100, &img_png);
	drawImg(200, 200, &img_png);
	*/

	getchar();
	return 0;
}