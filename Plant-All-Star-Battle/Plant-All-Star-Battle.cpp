#include<iostream>
#include<easyx.h>
#include<graphics.h>
#pragma comment(lib,"Winmm.lib")
#include"scene.h"
#include"menu_scene.h"
#include"game_scene.h"
#include"seletor_scene.h"
#include"scene_manager.h"
#include "util.h"
#include "atlas.h"


IMAGE	imgMenuBackground;

IMAGE	imgVS;										//VS艺术字

IMAGE	img1P;										//文本
IMAGE	img2P;
IMAGE	img1PDesc;									//键位描述
IMAGE	img2PDesc;

IMAGE	imgGraveStoneLeft;							//向左墓碑
IMAGE	imgGraveStoneRight;
IMAGE	imgSelectorTip;								//选择提示
IMAGE	imgSelectorBackground;

IMAGE	img1PSelectorButtonIdleLeft;				//1P向左选择按钮默认
IMAGE	img1PSelectorButtonIdleRight;
IMAGE	img1PSelectorButtonDownLeft;
IMAGE	img1PSelectorButtonDownRight;				//1P向左选择按钮按下

IMAGE	img2PSelectorButtonIdleLeft;
IMAGE	img2PSelectorButtonIdleRight;
IMAGE	img2PSelectorButtonDownLeft;
IMAGE	img2PSelectorButtonDownRight;

IMAGE	imgPeaShooterSelectorBackgroundLeft;		//豌豆向左选择界面
IMAGE	imgPeaShooterSelectorBackgroundRight;
IMAGE	imgSunFlowerSelectorBackgroundLeft;			//向日葵向左选择界面
IMAGE	imgSunFlowerSelectorBackgroundRight;

IMAGE	imgSky;										//天空
IMAGE	imgHills;									//山脉
IMAGE	imgLargePlatform;							//平台
IMAGE	imgSmallPlatform;

IMAGE	img1PCursor;
IMAGE	img2PCursor;

Atlas	atlasPeaShooterIdleLeft;			//豌豆向左
Atlas	atlasPeaShooterIdleRight;
Atlas	atlasPeaShooterRunLeft;
Atlas	atlasPeaShooterRunRight;
Atlas	atlasPeaShooterAttackExLeft;		//豌豆向左特殊攻击
Atlas	atlasPeaShooterAttackExRight;
Atlas	atlasPeaShooterDieLeft;				//向左死亡
Atlas	atlasPeaShooterDieRight;

Atlas	atlasSunFlowerIdleLeft;				//向日葵
Atlas	atlasSunFlowerIdleRight;
Atlas	atlasSunFlowerRunLeft;
Atlas	atlasSunFlowerRunRight;
Atlas	atlasSunFlowerAttackExLeft;
Atlas	atlasSunFlowerAttackExRight;
Atlas	atlasSunFlowerDieLeft;
Atlas	atlasSunFlowerDieRight;

IMAGE	imgPea;								//豌豆
Atlas	atlasPeaBreak;
Atlas	atlasSun;
Atlas	atlasSunExplode;					//太阳爆炸
Atlas	atlasSunEx;							//特殊动画
Atlas	atlasSunExExplode;					//特殊爆炸
Atlas	atlasSunText;						//文本动画

Atlas	atlasRunEffect;						//奔跑特效
Atlas	atlasJumpEffect;
Atlas	atlasLandEffect;

IMAGE	img1PWinner;						//1P获胜文本
IMAGE	img2PWinner;
IMAGE	imgWinnerBar;						//获胜背景

IMAGE	imgPeaShooterAvatar;				//豌豆头像
IMAGE	imgSunFlowerAvatar;					//向日葵头像

Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* selector_scene = nullptr;
SceneManager scene_manager;

//void flip_atlas(Atlas& src,Atlas& dst)
//{
//	dst.clear();
//	for (int i = 0; i < src.get_size(); i++)
//	{
//        IMAGE img_flipipped;
//		flip_image(src.get_image(i), &img_flipipped);
//		dst.add_image(img_flipipped);
//
//	}
//}

void flip_atlas(Atlas& src, Atlas& dst)
{
	dst.clear();
	for (int i = 0; i < src.get_size(); i++)
	{
		IMAGE* src_img = src.get_image(i);
		if (!src_img) continue; // 避免 nullptr 崩溃

		IMAGE img_flipped;
		flip_image(src_img, &img_flipped); // 你已有的翻转函数
		dst.add_image(img_flipped);        // 拷贝安全，栈变量无问题
	}
}



void load_game_resources()
{
	//加载字体
	//将 IPix.ttf" 加载到系统字体中，并将其设置为私有字体。
	AddFontResourceEx(_T("resources/IPix.ttf"), FR_PRIVATE, nullptr);

	loadimage(&imgMenuBackground, _T("resources/menu_background.png"));

	loadimage(&imgVS, _T("resources/VS.png"));
	loadimage(&img1P, _T("resources/1P.png"));
	loadimage(&img2P, _T("resources/2P.png"));
	loadimage(&img1PDesc, _T("resources/1P_desc.png"));
	loadimage(&img2PDesc, _T("resources/2P_desc.png"));
	loadimage(&imgGraveStoneRight, _T("resources/gravestone.png"));
	flip_image(&imgGraveStoneRight, &imgGraveStoneLeft);

	loadimage(&imgSelectorTip, _T("resources/selector_tip.png"));
	loadimage(&imgSelectorBackground, _T("resources/selector_background.png"));

	loadimage(&img1PSelectorButtonIdleRight, _T("resources/1P_selector_btn_idle.png"));
	flip_image(&img1PSelectorButtonIdleRight, &img1PSelectorButtonIdleLeft);
	loadimage(&img1PSelectorButtonDownRight, _T("resources/1P_selector_btn_down.png"));
	flip_image(&img1PSelectorButtonDownRight, &img1PSelectorButtonDownLeft);

	loadimage(&img2PSelectorButtonIdleRight, _T("resources/2P_selector_btn_idle.png"));
	flip_image(&img2PSelectorButtonIdleRight, &img2PSelectorButtonIdleLeft);
	loadimage(&img2PSelectorButtonDownRight, _T("resources/2P_selector_btn_down.png"));
	flip_image(&img2PSelectorButtonDownRight, &img2PSelectorButtonDownLeft);

	loadimage(&imgPeaShooterSelectorBackgroundRight, _T("resources/peashooter_selectorbackground.png"));
	flip_image(&imgPeaShooterSelectorBackgroundRight, &imgPeaShooterSelectorBackgroundLeft);
	loadimage(&imgSunFlowerSelectorBackgroundRight, _T("resources/sunflower_selector_background.png"));
	flip_image(&imgSunFlowerSelectorBackgroundRight, &imgSunFlowerSelectorBackgroundLeft);

	loadimage(&imgSky, _T("resources/sky.png"));
	loadimage(&imgHills, _T("resources/hills.png"));
	loadimage(&imgLargePlatform, _T("resources/platform_large.png"));
	loadimage(&imgSmallPlatform, _T("resources/platform_small.png"));

	loadimage(&img1PCursor, _T("resources/1P_cursor.png"));
	loadimage(&img2PCursor, _T("resources/2P_cursor.png"));

	//豌豆射手
	atlasPeaShooterIdleRight.load_from_file(_T("resources/peashooter_idle_%d.png"), 9);
	flip_atlas(atlasPeaShooterIdleRight, atlasPeaShooterIdleLeft);
	//atlasPeaShooterRunRight.load_from_file(_T("resources/peashooter_run_%d.png"), 5);
	//flip_atlas(atlasPeaShooterRunRight, atlasPeaShooterRunLeft);
	//atlasPeaShooterAttackExRight.load_from_file(_T("resources/peashooter_attack_ex_%d.png"), 3);
	//flip_atlas(atlasPeaShooterAttackExRight, atlasPeaShooterAttackExLeft);
	//atlasPeaShooterDieRight.load_from_file(_T("resources/peashooter_die_%d.png"), 4);
	//flip_atlas(atlasPeaShooterDieRight, atlasPeaShooterDieLeft);

	////向日葵
	//atlasSunFlowerIdleRight.load_from_file(_T("resources/sunflower_idle_%d.png"), 8);
	//flip_atlas(atlasSunFlowerIdleRight, atlasSunFlowerIdleLeft);
	//atlasSunFlowerRunRight.load_from_file(_T("resources/sunflower_run_%d.png"), 5);
	//flip_atlas(atlasSunFlowerRunRight, atlasSunFlowerRunLeft);
	//atlasSunFlowerAttackExRight.load_from_file(_T("resources/sunflower_attack_ex_%d.png"), 9);
	//flip_atlas(atlasSunFlowerAttackExRight, atlasSunFlowerAttackExLeft);
	//atlasSunFlowerDieRight.load_from_file(_T("resources/sunflower_die_%d.png"), 2);
	//flip_atlas(atlasSunFlowerDieRight, atlasSunFlowerDieLeft);

	//loadimage(&imgPea, _T("resources/pea.png"));
	//atlasPeaBreak.load_from_file(_T("resources/pea_break_%d.png"), 3);
	//atlasSun.load_from_file(_T("resources/sun_%d.png"), 5);
	//atlasSunExplode.load_from_file(_T("resources/sun_explode_%d.png"), 5);
	//atlasSunEx.load_from_file(_T("resources/sun_ex_%d.png"), 5);
	//atlasSunExExplode.load_from_file(_T("resources/sun_ex_explode_%d.png"), 5);
	//atlasSunText.load_from_file(_T("resources/sun_text_%d.png"), 6);

	//atlasRunEffect.load_from_file(_T("resources/run_effect_%d.png"), 4);
	//atlasJumpEffect.load_from_file(_T("resources/jump_effect_%d.png"), 5);
	//atlasLandEffect.load_from_file(_T("resources/land_effect_%d.png"), 2);

	//loadimage(&img1PWinner, _T("resources/1P_winner.png"));
	//loadimage(&img2PWinner, _T("resources/2P_winner.png"));
	//loadimage(&imgWinnerBar, _T("resources/winnner_bar.png"));

	//loadimage(&imgPeaShooterAvatar, _T("resources/avatar_peashooter.png"));
	//loadimage(&imgSunFlowerAvatar, _T("resources/avatar_sunflower.png"));
//	//加载音乐
//	mciSendString(_T("open resources/bgm_game.mp3 alias bgmGame"), nullptr, 0, nullptr);
//	mciSendString(_T("open resources/bgm_menu.mp3 alias bgmMenu"), nullptr, 0, nullptr);
//
//	mciSendString(_T("open resources/pea_break_1.mp3 alias peaBreak1"), nullptr, 0, nullptr);
//	mciSendString(_T("open resources/pea_break_2.mp3 alias peaBreak2"), nullptr, 0, nullptr);
//	mciSendString(_T("open resources/pea_break_3.mp3 alias peaBreak3"), nullptr, 0, nullptr);
//	mciSendString(_T("open resources/pea_shoot_1.mp3 alias peaShoot1"), nullptr, 0, nullptr);
//	mciSendString(_T("open resources/pea_shoot_2.mp3 alias peaShoot2"), nullptr, 0, nullptr);
//	mciSendString(_T("open resources/pea_shoot_ex.mp3 alias peaShootEx"), nullptr, 0, nullptr);
//
//	mciSendString(_T("open resources/sun_explode.mp3 alias sunExplode"), nullptr, 0, nullptr);
//	mciSendString(_T("open resources/sun_explode_ex.mp3 alias sunExplodeEx"), nullptr, 0, nullptr);
//	mciSendString(_T("open resources/sun_text.mp3 alias sunText"), nullptr, 0, nullptr);
//
//	mciSendString(_T("open resources/ui_confirm.wav alias uiConfirm"), nullptr, 0, nullptr);
//	mciSendString(_T("open resources/ui_switch.wav alias uiSwitch"), nullptr, 0, nullptr);
//	mciSendString(_T("open resources/ui_win.wav alias uiWin"), nullptr, 0, nullptr);
}

int main()
{
    ExMessage msg;
    const int FPS = 60;

	load_game_resources();
	cout << "加载成功" << endl;

    /*initgraph(1280, 720, EW_SHOWCONSOLE);

    
    BeginBatchDraw();
    menu_scene = new MenuScene();
    game_scene = new GameScene();
    selector_scene = new SelectorScene();

    scene_manager.set_current_state(menu_scene);
	
	cout << "初始化成功" << endl;

    while (true)
    {

        DWORD frame_start_time = GetTickCount();

        while (peekmessage(&msg))
        {
            scene_manager.on_input(msg);
        }

		static DWORD last_tick_time = GetTickCount();
		DWORD current_tick_time = GetTickCount();
		DWORD delta_tick = current_tick_time - last_tick_time;
		scene_manager.on_update(delta_tick);

		last_tick_time = current_tick_time;

        cleardevice();
        scene_manager.on_draw();
        FlushBatchDraw();

        DWORD frame_end_time = GetTickCount();
        DWORD frame_delte_time = frame_end_time - frame_start_time;
        if (frame_delte_time < 1000 / FPS)
            Sleep(1000 / FPS - frame_delte_time);
    }

    EndBatchDraw();*/

    return 0;
}