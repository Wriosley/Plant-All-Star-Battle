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
        std::cout << "进入角色选择界面" << std::endl;
    }

    void on_update(int delta)
    {
        //std::cout << "主菜单正在运行" << std::endl;
    }

    void on_draw()
    {
        outtextxy(10, 10, _T("游戏选择绘图内容"));
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

};
#endif // !_MENU_SENCE_H_