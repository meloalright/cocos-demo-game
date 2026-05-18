#ifndef __LABEL_DEMO_H__
#define __LABEL_DEMO_H__

#include "DemoBase.h"

class LabelDemo : public DemoBase {
public:
    virtual bool init() override;
    CREATE_FUNC(LabelDemo);

private:
    int _counter = 0;
    cocos2d::Label* _dynamicLabel = nullptr;
    void update(float dt) override;
};

#endif
