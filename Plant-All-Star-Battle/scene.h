#ifndef _SCENE_H_
#define _SCENE_H_

#include <graphics.h>
#include "camera.h"



class  Scene
{
public:
    Scene() = default;
    ~Scene() = default;

    virtual void on_enter() {}  //����������ʱ�ĳ�ʼ���߼�
    virtual void on_update(int delta) {}  //��������
    virtual void on_draw(const Camera& camera) {}   //��Ⱦ��ͼ
    virtual void on_input(const ExMessage& msg) {} //�����������
    virtual void on_exit() {}  //�������˳�ʱ��ж���߼�

private:

};

#endif // ! _SCENE_H_