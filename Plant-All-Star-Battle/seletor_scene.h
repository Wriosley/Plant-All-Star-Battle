#ifndef _SELECTOR_SCENE_H_
#define _SELECTOR_SCENE_H_

#include "scene.h"
#include <iostream>
#include <easyx.h>
#include "Animation.h"
#include"scene_manager.h"
using namespace std;

extern SceneManager scene_manager;

// 背景与界面
extern IMAGE imgMenuBackground;

// VS 艺术字
extern IMAGE imgVS;

// 玩家文本与键位描述
extern IMAGE img1P;
extern IMAGE img2P;
extern IMAGE img1PDesc;
extern IMAGE img2PDesc;

// 墓碑与选择提示
extern IMAGE imgGraveStoneLeft;
extern IMAGE imgGraveStoneRight;
extern IMAGE imgSelectorTip;
extern IMAGE imgSelectorBackground;

// 1P选择按钮
extern IMAGE img1PSelectorButtonIdleLeft;
extern IMAGE img1PSelectorButtonIdleRight;
extern IMAGE img1PSelectorButtonDownLeft;
extern IMAGE img1PSelectorButtonDownRight;

// 2P选择按钮
extern IMAGE img2PSelectorButtonIdleLeft;
extern IMAGE img2PSelectorButtonIdleRight;
extern IMAGE img2PSelectorButtonDownLeft;
extern IMAGE img2PSelectorButtonDownRight;

// 角色选择界面背景
extern IMAGE imgPeaShooterSelectorBackgroundLeft;
extern IMAGE imgPeaShooterSelectorBackgroundRight;
extern IMAGE imgSunFlowerSelectorBackgroundLeft;
extern IMAGE imgSunFlowerSelectorBackgroundRight;

// 背景元素
extern IMAGE imgSky;
extern IMAGE imgHills;
extern IMAGE imgLargePlatform;
extern IMAGE imgSmallPlatform;

// 玩家光标
extern IMAGE img1PCursor;
extern IMAGE img2PCursor;

// 豌豆射手动画图集
extern Atlas atlasPeaShooterIdleLeft;
extern Atlas atlasPeaShooterIdleRight;
extern Atlas atlasPeaShooterRunLeft;
extern Atlas atlasPeaShooterRunRight;
extern Atlas atlasPeaShooterAttackExLeft;
extern Atlas atlasPeaShooterAttackExRight;
extern Atlas atlasPeaShooterDieLeft;
extern Atlas atlasPeaShooterDieRight;

// 向日葵动画图集
extern Atlas atlasSunFlowerIdleLeft;
extern Atlas atlasSunFlowerIdleRight;
extern Atlas atlasSunFlowerRunLeft;
extern Atlas atlasSunFlowerRunRight;
extern Atlas atlasSunFlowerAttackExLeft;
extern Atlas atlasSunFlowerAttackExRight;
extern Atlas atlasSunFlowerDieLeft;
extern Atlas atlasSunFlowerDieRight;

// 子弹与特效
extern IMAGE imgPea;
extern Atlas atlasPeaBreak;
extern Atlas atlasSun;
extern Atlas atlasSunExplode;
extern Atlas atlasSunEx;
extern Atlas atlasSunExExplode;
extern Atlas atlasSunText;

// 通用动作特效
extern Atlas atlasRunEffect;
extern Atlas atlasJumpEffect;
extern Atlas atlasLandEffect;

// 胜利文本与头像
extern IMAGE img1PWinner;
extern IMAGE img2PWinner;
extern IMAGE imgWinnerBar;

extern IMAGE imgPeaShooterAvatar;
extern IMAGE imgSunFlowerAvatar;


class SelectorScene :public Scene
{
public:
    SelectorScene() = default;
    ~SelectorScene() = default;

    void on_enter()
	{
        cout << "进入选择界面" << std::endl;

		animation_peashooter.set_atlas(&atlasPeaShooterIdleRight);
        animation_sunflower.set_atlas(&atlasSunFlowerIdleRight);
        animation_peashooter.set_interval(100);
        animation_sunflower.set_interval(100);

        static const int OFFSET_X = 50;

        //getwidth:窗口width
            //图片窗口居中 = (窗口 - 图片) / 2
        pos_img_VS.x = (getwidth() - imgVS.getwidth()) / 2;
        pos_img_VS.y = (getheight() - imgVS.getheight()) / 2;
        pos_img_tip.x = (getwidth() - imgSelectorTip.getwidth()) / 2;
        pos_img_tip.y = getheight() - 125;
        pos_img_1P.x = (getwidth() / 2 - img1P.getwidth()) / 2 - OFFSET_X;
        pos_img_1P.y = 35;
        pos_img_2P.x = getwidth() / 2 + (getwidth() / 2 - img2P.getwidth()) / 2 + OFFSET_X;
        pos_img_2P.y = pos_img_1P.y;
        pos_img_1P_desc.x = (getwidth() / 2 - img1PDesc.getwidth()) / 2 - OFFSET_X;
        pos_img_1P_desc.y = getheight() - 150;
        pos_img_2P_desc.x = getwidth() / 2 + (getwidth() / 2 - img2PDesc.getwidth()) / 2 + OFFSET_X;
        pos_img_2P_desc.y = pos_img_1P_desc.y;
        pos_img_1P_gravestone.x = (getwidth() / 2 - imgGraveStoneRight.getwidth()) / 2 - OFFSET_X;
        pos_img_1P_gravestone.y = pos_img_1P.y + img1P.getheight() + 35;
        pos_img_2P_gravestone.x = getwidth() / 2 + (getwidth() / 2 - imgGraveStoneLeft.getwidth()) / 2 + OFFSET_X;
        pos_img_2P_gravestone.y = pos_img_1P_gravestone.y;
        pos_animation_1P.x = (getwidth() / 2 - atlasPeaShooterIdleRight.get_image(0)->getwidth()) / 2 - OFFSET_X;
        pos_animation_1P.y = pos_img_1P_gravestone.y + 80;
        pos_animation_2P.x = getwidth() / 2 + (getwidth() / 2 - atlasPeaShooterIdleRight.get_image(0)->getwidth()) / 2 + OFFSET_X;
        pos_animation_2P.y = pos_animation_1P.y;
        pos_img_1P_name.y = pos_animation_1P.y + 155;
        pos_img_2P_name.y = pos_img_1P_name.y;
        pos_1P_selector_btn_left.x = pos_img_1P_gravestone.x - img1PSelectorButtonIdleLeft.getwidth();
        pos_1P_selector_btn_left.y = pos_img_1P_gravestone.y + (imgGraveStoneRight.getheight() - img1PSelectorButtonIdleLeft.getheight()) / 2;
        pos_1P_selector_btn_right.x = pos_img_1P_gravestone.x + imgGraveStoneRight.getwidth();
        pos_1P_selector_btn_right.y = pos_1P_selector_btn_left.y;
        pos_2P_selector_btn_left.x = pos_img_2P_gravestone.x - img2PSelectorButtonIdleLeft.getwidth();
        pos_2P_selector_btn_left.y = pos_1P_selector_btn_left.y;
        pos_2P_selector_btn_right.x = pos_img_2P_gravestone.x + imgGraveStoneLeft.getwidth();
        pos_2P_selector_btn_right.y = pos_1P_selector_btn_left.y;
        cout << "选择界面退出" << endl;

      
    }

    void on_update(int delta)
    {
        animation_peashooter.on_update(delta);
        animation_sunflower.on_update(delta);
    }

    void on_draw(const Camera& camera)
    {
        

		putimage(0, 0, &imgSelectorBackground); // 渲染背景
		
        putimage(pos_img_VS.x, pos_img_VS.y, &imgVS); // 渲染VS艺术字
		
        putimage(pos_img_1P.x, pos_img_1P.y, &img1P); // 渲染1P文本
		putimage(pos_img_2P.x, pos_img_2P.y, &img2P); // 渲染2P文本
		
        putimage(pos_img_1P_gravestone.x, pos_img_1P_gravestone.y, &imgGraveStoneRight); // 渲染1P墓碑
		putimage(pos_img_2P_gravestone.x, pos_img_2P_gravestone.y, &imgGraveStoneLeft); // 渲染2P墓碑
		
        switch (player_type_1)
        {
        case PlayerType::PeaShooter:
            animation_peashooter.on_draw(camera, pos_animation_1P.x, pos_animation_1P.y);
            break;
        case PlayerType::SunFlower:
            animation_sunflower.on_draw(camera, pos_animation_1P.x, pos_animation_1P.y);
            break;
        }
        switch (player_type_2)
        {
        case PlayerType::PeaShooter:
            animation_peashooter.on_draw(camera, pos_animation_2P.x, pos_animation_2P.y);
            break;
        case PlayerType::SunFlower:
            animation_sunflower.on_draw(camera, pos_animation_2P.x, pos_animation_2P.y);
            break;
        default:
            break;
        }

        putimage_alpha(camera,pos_img_1P_desc.x, pos_img_1P_desc.y, &img1PDesc); // 渲染1P键位描述)
        putimage_alpha(camera,pos_img_2P_desc.x, pos_img_2P_desc.y, &img2PDesc); // 渲染1P键位描述)

        putimage_alpha(camera,pos_img_tip.x, pos_img_tip.y, &imgSelectorTip); // 渲染选择提示
        
    }

    void on_input(const ExMessage& msg) {
        if (msg.message == WM_KEYDOWN) {
            // 按下任意键，切换到游戏场景
            scene_manager.switch_to(SceneManager::SceneType::Menu);
        }
    }

    void on_exit()
    {
        std::cout << "角色选择界面退出" << std::endl;
    }

private:
    enum class PlayerType
    {
		PeaShooter=0,
		SunFlower,
        Invalid
    };

private:
    POINT pos_img_VS = { 0 };
    // vs艺术字图片位置
    POINT pos_img_tip = { 0 };
    //提示信息文本图片位置
    POINT pos_img_1P = { 0 };
    // 1P 文本图片位置
    POINT pos_img_2P = { 0 };
    // 2P文本图片位置
    POINT pos_img_1P_desc = { 0 };
    //1P键位描述图片位置
    POINT pos_img_2P_desc = { 0 };
    //2P键位描述图片位置
    POINT pos_img_1P_name = { 0 };
    //1P角色姓名文本位置
    POINT pos_img_2P_name = { 0 };
    //2P角色姓名文本位置
    POINT pos_animation_1P = { 0 };
    //1P角色动画位置
    POINT pos_animation_2P = { 0 };
    // 2P角色动画位置
    POINT pos_img_1P_gravestone = { 0 };
    //1P墓碑图片位置
    POINT pos_img_2P_gravestone = { 0 };
    //2P墓碑图片位置
    POINT pos_1P_selector_btn_left = { 0 };
    //1P向左切换按钮位置
    POINT
        pos_1P_selector_btn_right = { 0 };
    //1P向右切换按钮位置
    POINT pos_2P_selector_btn_left = { 0 };
    //2P向左切换按钮位置
    POINT pos_2P_selector_btn_right = { 0 };
    //2P向右切换按钮位置

	Animation animation_peashooter;//豌豆射手动画
	Animation animation_sunflower;//向日葵动画

    PlayerType player_type_1 = PlayerType::PeaShooter;
	PlayerType player_type_2 = PlayerType::SunFlower;

};
#endif // !_MENU_SENCE_H_