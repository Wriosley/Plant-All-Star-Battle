#ifndef _CAMERA_H_
#define _CAMERA_H_    

#include "vector2.h"
#include "timer.h"

class Camera
{
public:
    Camera() {
        timer_shake.set_one_shot(true);
        timer_shake.set_callback([&]() {
            is_shaking = false;
            reset();
            });


    };
    ~Camera() = default;

    void shake(float strength, int duration) {
        is_shaking = true;
        shake_strength = strength;

        timer_shake.set_wait_time(duration);
        timer_shake.restart();
    }

    //返回摄像机位置的常量引用
    const Vector2& getPosition() const {
        return position;
    }

    //将摄像机位置归零
    void reset() {
        position = Vector2(0, 0);
    }

    void on_update(int delta) {
        timer_shake.on_update(delta);

        if
            (is_shaking) {
            position.x = (-50 + rand() % 100) / 50.0f * shake_strength;
            position.y = (-50 + rand() % 100) / 50.0f * shake_strength;
        }

    }

private:
    Vector2 position;                // 相机位置
    Timer timer_shake;               // 摄像机抖动计时器
    bool is_shaking = false;        // 摄像机是否正在抖动
    float shake_strength = 0.0f;    // 摄像机抖动幅度
};



#endif // !_CAMERA_H_