#ifndef __ANIMATION_DEMO_H__
#define __ANIMATION_DEMO_H__

#include "DemoBase.h"

class AnimationDemo : public DemoBase {
public:
    virtual bool init() override;
    CREATE_FUNC(AnimationDemo);

private:
    cocos2d::DrawNode* _character = nullptr;
    cocos2d::Label* _stateLabel = nullptr;

    void playIdle();
    void playWalk();
    void playJump();
    void playAttack();
};

#endif
