#ifndef _SELECTOR_SCENE_H_
#define _SELECTOR_SCENE_H_

#include "scene.h"
#include <iostream>
#include <easyx.h>
#include"scene_manager.h"
using namespace std;

extern SceneManager scene_manager;

class SelectorScene :public Scene
{
public:
    SelectorScene() = default;
    ~SelectorScene() = default;

    void on_enter()
    {
        std::cout << "�����ɫѡ�����" << std::endl;
    }

    void on_update(int delta)
    {
        //std::cout << "���˵���������" << std::endl;
    }

    void on_draw()
    {
        outtextxy(10, 10, _T("��Ϸѡ���ͼ����"));
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

};
#endif // !_MENU_SENCE_H_