#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MenuScene);

private:
    void onSpriteDemo(cocos2d::Ref* sender);
    void onActionDemo(cocos2d::Ref* sender);
    void onLabelDemo(cocos2d::Ref* sender);
    void onInputDemo(cocos2d::Ref* sender);
    void onSceneDemo(cocos2d::Ref* sender);
    void onEventDemo(cocos2d::Ref* sender);
    void onNodeDemo(cocos2d::Ref* sender);
    void onAnimationDemo(cocos2d::Ref* sender);
};

#endif
