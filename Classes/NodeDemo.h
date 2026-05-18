#ifndef __NODE_DEMO_H__
#define __NODE_DEMO_H__

#include "DemoBase.h"

class NodeDemo : public DemoBase {
public:
    virtual bool init() override;
    CREATE_FUNC(NodeDemo);
};

#endif
