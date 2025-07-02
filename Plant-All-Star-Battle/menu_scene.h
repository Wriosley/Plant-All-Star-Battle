#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H

#include "scene.h"
#include <iostream>
#include <easyx.h>
#include "Animation.h"
#include"scene_manager.h"
#include "camera.h"
#include"timer.h"
using namespace std;

extern SceneManager scene_manager;
extern Atlas atlasPeaShooterRunRight;
extern IMAGE imgMenuBackground;

class MenuScene :public Scene
{
public:
    MenuScene() = default;
    ~MenuScene() = default;

    void on_enter()
    {
		mciSendString(_T("play bgmMenu repeat from 0"), nullptr, 0, nullptr); //���Ų˵�����
    }

    void on_draw(const Camera& camera)
    {
        putimage(0, 0, &imgMenuBackground); //��Ⱦ������
    
    }


    void on_input(const ExMessage& msg) {
        if (msg.message == WM_KEYUP)
        {
			scene_manager.switch_to(SceneManager::SceneType::Selector); //����������л�����Ϸ����
			mciSendString(_T("play uiConfirm from 0"), nullptr, 0, nullptr); //ֹͣ�˵�����
        }
    }

private:
    Animation animation_peashooter_run_right;
};
#endif // !_MENU_SENCE_H_