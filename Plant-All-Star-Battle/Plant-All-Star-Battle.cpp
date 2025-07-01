#include<iostream>
#include<easyx.h>
#include<graphics.h>
#include"scene.h"
#include"menu_scene.h"
#include"game_scene.h"
#include"scene_manager.h"


Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;

int main()
{
    ExMessage msg;
    const int FPS = 60;

    initgraph(1280, 720, EW_SHOWCONSOLE);

    BeginBatchDraw();

    menu_scene = new MenuScene();
    game_scene = new GameScene();

    scene->on_enter();

    while (true)
    {
        DWORD frame_start_time = GetTickCount();

        while (peekmessage(&msg))
        {
            scene->on_input(msg);
        }

        scene->on_update();

        cleardevice();
        scene->on_draw();
        FlushBatchDraw();

        DWORD frame_end_time = GetTickCount();
        DWORD frame_delte_time = frame_end_time - frame_start_time;
        if (frame_delte_time < 1000 / FPS)
            Sleep(1000 / FPS - frame_delte_time);
    }

    EndBatchDraw();

    return 0;
}