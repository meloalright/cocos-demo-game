#ifndef __SCENE_DEMO_H__
#define __SCENE_DEMO_H__

#include "DemoBase.h"

class SceneDemo : public DemoBase {
public:
    virtual bool init() override;
    CREATE_FUNC(SceneDemo);

private:
    void switchToScene(cocos2d::Ref* sender, int transitionType);
};

class SceneDemoTarget : public DemoBase {
public:
    static SceneDemoTarget* createWithColor(const cocos2d::Color4B& color, const std::string& transName);
    virtual bool init() override;
    CREATE_FUNC(SceneDemoTarget);

private:
    cocos2d::Color4B _bgColor = cocos2d::Color4B(64, 64, 64, 255);
    std::string _transitionName;
};

#endif
