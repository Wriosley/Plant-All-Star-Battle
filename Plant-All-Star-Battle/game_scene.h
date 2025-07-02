#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H

#include "scene.h"
#include <iostream>
#include <easyx.h>
#include"scene_manager.h"
using namespace std;

extern SceneManager scene_manager;

class GameScene :public Scene
{
public:
    GameScene() = default;
    ~GameScene() = default;

    void on_enter()
    {
        std::cout << "������Ϸ����" << std::endl;
    }

    void on_update(int delta)
    {
        //std::cout << "���˵���������" << std::endl;
    }

    void on_draw(const Camera& camera)
    {
        outtextxy(10, 10, _T("��Ϸ�ڲ���ͼ����"));
    }

    void on_input(const ExMessage& msg) {
        if (msg.message == WM_KEYDOWN) {
            // ������������л�����Ϸ����
            scene_manager.switch_to(SceneManager::SceneType::Menu);
        }
    }

    void on_exit()
    {
        std::cout << "��Ϸ�����˳�" << std::endl;
    }
private:

};
#endif // !_MENU_SENCE_H_