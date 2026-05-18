#include "SceneDemo.h"

USING_NS_CC;

bool SceneDemo::init() {
    if (!DemoBase::init()) return false;
    addTitle("Scene Transitions Demo");

    auto bg = LayerColor::create(Color4B(40, 40, 60, 255));
    this->addChild(bg, -1);

    struct TransEntry {
        std::string name;
        int type;
    };

    std::vector<TransEntry> transitions = {
        {"Fade",        0},
        {"FlipX",       1},
        {"FlipY",       2},
        {"SlideInR",    3},
        {"SlideInT",    4},
        {"ShrinkGrow",  5},
        {"CrossFade",   6},
        {"PageTurn",    7},
    };

    Vector<MenuItem*> items;
    float startY = _center.y + 100;

    for (size_t i = 0; i < transitions.size(); i++) {
        auto label = Label::createWithSystemFont(transitions[i].name, "Arial", 22);
        label->setColor(Color3B(200, 220, 255));
        int type = transitions[i].type;
        auto item = MenuItemLabel::create(label, [this, type](Ref* sender) {
            switchToScene(sender, type);
        });
        float col = (i < 4) ? _center.x - 150 : _center.x + 150;
        float row = startY - (i % 4) * 55;
        item->setPosition(Vec2(col, row));
        items.pushBack(item);
    }

    auto menu = Menu::createWithArray(items);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    auto desc = Label::createWithSystemFont("Click a transition to see it in action (returns in 2s)", "Arial", 13);
    desc->setPosition(Vec2(_center.x, _origin.y + 30));
    desc->setColor(Color3B(160, 160, 160));
    this->addChild(desc);

    return true;
}

void SceneDemo::switchToScene(Ref* sender, int type) {
    static const Color4B colors[] = {
        Color4B(120, 40, 40, 255), Color4B(40, 120, 40, 255),
        Color4B(40, 40, 120, 255), Color4B(120, 120, 40, 255),
        Color4B(120, 40, 120, 255), Color4B(40, 120, 120, 255),
        Color4B(80, 80, 40, 255),  Color4B(40, 80, 80, 255),
    };

    std::string names[] = {
        "Fade", "FlipX", "FlipY", "SlideInR",
        "SlideInT", "ShrinkGrow", "CrossFade", "PageTurn"
    };

    auto target = SceneDemoTarget::createWithColor(colors[type], names[type]);
    TransitionScene* transition = nullptr;

    switch (type) {
        case 0: transition = TransitionFade::create(1.0f, target); break;
        case 1: transition = TransitionFlipX::create(1.0f, target); break;
        case 2: transition = TransitionFlipY::create(1.0f, target); break;
        case 3: transition = TransitionSlideInR::create(1.0f, target); break;
        case 4: transition = TransitionSlideInT::create(1.0f, target); break;
        case 5: transition = TransitionShrinkGrow::create(1.0f, target); break;
        case 6: transition = TransitionCrossFade::create(1.0f, target); break;
        case 7: transition = TransitionPageTurn::create(1.0f, target, false); break;
    }

    if (transition) {
        Director::getInstance()->replaceScene(transition);
    }
}

SceneDemoTarget* SceneDemoTarget::createWithColor(const Color4B& color, const std::string& transName) {
    auto ret = SceneDemoTarget::create();
    ret->_bgColor = color;
    ret->_transitionName = transName;
    return ret;
}

bool SceneDemoTarget::init() {
    if (!DemoBase::init()) return false;

    auto bg = LayerColor::create(_bgColor);
    this->addChild(bg, -1);

    auto label = Label::createWithSystemFont(
        StringUtils::format("Transition: %s", _transitionName.c_str()),
        "Arial", 32);
    label->setPosition(_center);
    this->addChild(label);

    auto hint = Label::createWithSystemFont("Returning in 2 seconds...", "Arial", 18);
    hint->setPosition(Vec2(_center.x, _center.y - 50));
    hint->setColor(Color3B(200, 200, 200));
    this->addChild(hint);

    this->scheduleOnce([](float) {
        Director::getInstance()->replaceScene(
            TransitionFade::create(0.5f, SceneDemo::create()));
    }, 2.0f, "return_key");

    return true;
}
