#ifndef __DEMO_BASE_H__
#define __DEMO_BASE_H__

#include "cocos2d.h"

class DemoBase : public cocos2d::Scene {
public:
    virtual bool init() override;

protected:
    void addTitle(const std::string& title);
    void addBackButton();
    void onBack(cocos2d::Ref* sender);

    cocos2d::Size _visibleSize;
    cocos2d::Vec2 _origin;
    cocos2d::Vec2 _center;
};

#endif
