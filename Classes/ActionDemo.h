#ifndef __ACTION_DEMO_H__
#define __ACTION_DEMO_H__

#include "DemoBase.h"

class ActionDemo : public DemoBase {
public:
    virtual bool init() override;
    CREATE_FUNC(ActionDemo);
};

#endif
