#ifndef _SELECTOR_SCENE_H_
#define _SELECTOR_SCENE_H_

#include "scene.h"
#include <iostream>
#include <easyx.h>
#include "Animation.h"
#include"scene_manager.h"
using namespace std;

extern SceneManager scene_manager;

// ���������
extern IMAGE imgMenuBackground;

// VS ������
extern IMAGE imgVS;

// ����ı����λ����
extern IMAGE img1P;
extern IMAGE img2P;
extern IMAGE img1PDesc;
extern IMAGE img2PDesc;

// Ĺ����ѡ����ʾ
extern IMAGE imgGraveStoneLeft;
extern IMAGE imgGraveStoneRight;
extern IMAGE imgSelectorTip;
extern IMAGE imgSelectorBackground;

// 1Pѡ��ť
extern IMAGE img1PSelectorButtonIdleLeft;
extern IMAGE img1PSelectorButtonIdleRight;
extern IMAGE img1PSelectorButtonDownLeft;
extern IMAGE img1PSelectorButtonDownRight;

// 2Pѡ��ť
extern IMAGE img2PSelectorButtonIdleLeft;
extern IMAGE img2PSelectorButtonIdleRight;
extern IMAGE img2PSelectorButtonDownLeft;
extern IMAGE img2PSelectorButtonDownRight;

// ��ɫѡ����汳��
extern IMAGE imgPeaShooterSelectorBackgroundLeft;
extern IMAGE imgPeaShooterSelectorBackgroundRight;
extern IMAGE imgSunFlowerSelectorBackgroundLeft;
extern IMAGE imgSunFlowerSelectorBackgroundRight;

// ����Ԫ��
extern IMAGE imgSky;
extern IMAGE imgHills;
extern IMAGE imgLargePlatform;
extern IMAGE imgSmallPlatform;

// ��ҹ��
extern IMAGE img1PCursor;
extern IMAGE img2PCursor;

// �㶹���ֶ���ͼ��
extern Atlas atlasPeaShooterIdleLeft;
extern Atlas atlasPeaShooterIdleRight;
extern Atlas atlasPeaShooterRunLeft;
extern Atlas atlasPeaShooterRunRight;
extern Atlas atlasPeaShooterAttackExLeft;
extern Atlas atlasPeaShooterAttackExRight;
extern Atlas atlasPeaShooterDieLeft;
extern Atlas atlasPeaShooterDieRight;

// ���տ�����ͼ��
extern Atlas atlasSunFlowerIdleLeft;
extern Atlas atlasSunFlowerIdleRight;
extern Atlas atlasSunFlowerRunLeft;
extern Atlas atlasSunFlowerRunRight;
extern Atlas atlasSunFlowerAttackExLeft;
extern Atlas atlasSunFlowerAttackExRight;
extern Atlas atlasSunFlowerDieLeft;
extern Atlas atlasSunFlowerDieRight;

// �ӵ�����Ч
extern IMAGE imgPea;
extern Atlas atlasPeaBreak;
extern Atlas atlasSun;
extern Atlas atlasSunExplode;
extern Atlas atlasSunEx;
extern Atlas atlasSunExExplode;
extern Atlas atlasSunText;

// ͨ�ö�����Ч
extern Atlas atlasRunEffect;
extern Atlas atlasJumpEffect;
extern Atlas atlasLandEffect;

// ʤ���ı���ͷ��
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
        cout << "����ѡ�����" << std::endl;

		animation_peashooter.set_atlas(&atlasPeaShooterIdleRight);
        animation_sunflower.set_atlas(&atlasSunFlowerIdleRight);
        animation_peashooter.set_interval(100);
        animation_sunflower.set_interval(100);

        static const int OFFSET_X = 50;

        //getwidth:����width
            //ͼƬ���ھ��� = (���� - ͼƬ) / 2
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
        cout << "ѡ������˳�" << endl;

      
    }

    void on_update(int delta)
    {
        animation_peashooter.on_update(delta);
        animation_sunflower.on_update(delta);
    }

    void on_draw(const Camera& camera)
    {
        

		putimage(0, 0, &imgSelectorBackground); // ��Ⱦ����
		
        putimage(pos_img_VS.x, pos_img_VS.y, &imgVS); // ��ȾVS������
		
        putimage(pos_img_1P.x, pos_img_1P.y, &img1P); // ��Ⱦ1P�ı�
		putimage(pos_img_2P.x, pos_img_2P.y, &img2P); // ��Ⱦ2P�ı�
		
        putimage(pos_img_1P_gravestone.x, pos_img_1P_gravestone.y, &imgGraveStoneRight); // ��Ⱦ1PĹ��
		putimage(pos_img_2P_gravestone.x, pos_img_2P_gravestone.y, &imgGraveStoneLeft); // ��Ⱦ2PĹ��
		
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

        putimage_alpha(camera,pos_img_1P_desc.x, pos_img_1P_desc.y, &img1PDesc); // ��Ⱦ1P��λ����)
        putimage_alpha(camera,pos_img_2P_desc.x, pos_img_2P_desc.y, &img2PDesc); // ��Ⱦ1P��λ����)

        putimage_alpha(camera,pos_img_tip.x, pos_img_tip.y, &imgSelectorTip); // ��Ⱦѡ����ʾ
        
    }

    void on_input(const ExMessage& msg) {
        if (msg.message == WM_KEYDOWN) {
            // ������������л�����Ϸ����
            scene_manager.switch_to(SceneManager::SceneType::Menu);
        }
    }

    void on_exit()
    {
        std::cout << "��ɫѡ������˳�" << std::endl;
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
    // vs������ͼƬλ��
    POINT pos_img_tip = { 0 };
    //��ʾ��Ϣ�ı�ͼƬλ��
    POINT pos_img_1P = { 0 };
    // 1P �ı�ͼƬλ��
    POINT pos_img_2P = { 0 };
    // 2P�ı�ͼƬλ��
    POINT pos_img_1P_desc = { 0 };
    //1P��λ����ͼƬλ��
    POINT pos_img_2P_desc = { 0 };
    //2P��λ����ͼƬλ��
    POINT pos_img_1P_name = { 0 };
    //1P��ɫ�����ı�λ��
    POINT pos_img_2P_name = { 0 };
    //2P��ɫ�����ı�λ��
    POINT pos_animation_1P = { 0 };
    //1P��ɫ����λ��
    POINT pos_animation_2P = { 0 };
    // 2P��ɫ����λ��
    POINT pos_img_1P_gravestone = { 0 };
    //1PĹ��ͼƬλ��
    POINT pos_img_2P_gravestone = { 0 };
    //2PĹ��ͼƬλ��
    POINT pos_1P_selector_btn_left = { 0 };
    //1P�����л���ťλ��
    POINT
        pos_1P_selector_btn_right = { 0 };
    //1P�����л���ťλ��
    POINT pos_2P_selector_btn_left = { 0 };
    //2P�����л���ťλ��
    POINT pos_2P_selector_btn_right = { 0 };
    //2P�����л���ťλ��

	Animation animation_peashooter;//�㶹���ֶ���
	Animation animation_sunflower;//���տ�����

    PlayerType player_type_1 = PlayerType::PeaShooter;
	PlayerType player_type_2 = PlayerType::SunFlower;

};
#endif // !_MENU_SENCE_H_