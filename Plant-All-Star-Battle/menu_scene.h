#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H

#include "scene.h"
#include <iostream>
#include <easyx.h>
#include "Animation.h"
#include"scene_manager.h"
using namespace std;

extern SceneManager scene_manager;
extern Atlas atlasPeaShooterRunRight;

class MenuScene :public Scene
{
public:
    MenuScene() = default;
    ~MenuScene() = default;

    void on_enter()
    {
        cout << "进入主菜单" << endl;
        animation_peashooter_run_right.set_atlas(&atlasPeaShooterRunRight);
        animation_peashooter_run_right.set_inerval(75);
        animation_peashooter_run_right.set_loop(true);
    
    }

    void on_update(int delta)
    {
        animation_peashooter_run_right.on_update(delta);

    }

    void on_draw()
    {
        animation_peashooter_run_right.on_draw(100, 100);
    }

    void on_input(const ExMessage& msg) {
        if (msg.message == WM_KEYDOWN) {
            scene_manager.switch_to(SceneManager::SceneType::Game);
        }
    }

    void on_exit()
    {
        std::cout << "主菜单退出" << std::endl;
    }
private:
    Animation animation_peashooter_run_right;
};
#endif // !_MENU_SENCE_H_