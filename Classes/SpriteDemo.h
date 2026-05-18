#ifndef __SPRITE_DEMO_H__
#define __SPRITE_DEMO_H__

#include "DemoBase.h"

class SpriteDemo : public DemoBase {
public:
    virtual bool init() override;
    CREATE_FUNC(SpriteDemo);
};

#endif
