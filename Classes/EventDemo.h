#ifndef __EVENT_DEMO_H__
#define __EVENT_DEMO_H__

#include "DemoBase.h"

class EventDemo : public DemoBase {
public:
    virtual bool init() override;
    CREATE_FUNC(EventDemo);

private:
    cocos2d::Label* _logLabel = nullptr;
    int _score = 0;
    cocos2d::Label* _scoreLabel = nullptr;

    void addLog(const std::string& msg);
};

#endif
