#ifndef __INPUT_DEMO_H__
#define __INPUT_DEMO_H__

#include "DemoBase.h"

class InputDemo : public DemoBase {
public:
    virtual bool init() override;
    CREATE_FUNC(InputDemo);

private:
    cocos2d::DrawNode* _playerNode = nullptr;
    cocos2d::Label* _statusLabel = nullptr;
    std::set<cocos2d::EventKeyboard::KeyCode> _pressedKeys;

    void update(float dt) override;
};

#endif
