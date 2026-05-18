#include "MenuScene.h"
#include "SpriteDemo.h"
#include "ActionDemo.h"
#include "LabelDemo.h"
#include "InputDemo.h"
#include "SceneDemo.h"
#include "EventDemo.h"
#include "NodeDemo.h"
#include "AnimationDemo.h"

USING_NS_CC;

Scene* MenuScene::createScene() {
    return MenuScene::create();
}

bool MenuScene::init() {
    if (!Scene::init()) return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 center = Vec2(origin.x + visibleSize.width / 2,
                       origin.y + visibleSize.height / 2);

    auto bg = LayerColor::create(Color4B(32, 32, 48, 255));
    this->addChild(bg, 0);

    auto title = Label::createWithSystemFont("Cocos2d-x Feature Demo", "Arial", 36);
    title->setPosition(Vec2(center.x, origin.y + visibleSize.height - 50));
    title->setColor(Color3B(100, 200, 255));
    this->addChild(title, 1);

    auto subtitle = Label::createWithSystemFont("Select a feature to explore", "Arial", 18);
    subtitle->setPosition(Vec2(center.x, origin.y + visibleSize.height - 85));
    subtitle->setColor(Color3B(180, 180, 180));
    this->addChild(subtitle, 1);

    struct DemoEntry {
        std::string name;
        ccMenuCallback callback;
    };

    std::vector<DemoEntry> demos = {
        {"1. Sprite",          CC_CALLBACK_1(MenuScene::onSpriteDemo, this)},
        {"2. Actions",         CC_CALLBACK_1(MenuScene::onActionDemo, this)},
        {"3. Labels",          CC_CALLBACK_1(MenuScene::onLabelDemo, this)},
        {"4. Input Handling",  CC_CALLBACK_1(MenuScene::onInputDemo, this)},
        {"5. Scene Transitions", CC_CALLBACK_1(MenuScene::onSceneDemo, this)},
        {"6. Event System",    CC_CALLBACK_1(MenuScene::onEventDemo, this)},
        {"7. Node Hierarchy",  CC_CALLBACK_1(MenuScene::onNodeDemo, this)},
        {"8. Animation",       CC_CALLBACK_1(MenuScene::onAnimationDemo, this)},
    };

    Vector<MenuItem*> items;
    float startY = center.y + 120;
    for (size_t i = 0; i < demos.size(); i++) {
        auto label = Label::createWithSystemFont(demos[i].name, "Arial", 24);
        label->setColor(Color3B::WHITE);
        auto item = MenuItemLabel::create(label, demos[i].callback);
        item->setPosition(Vec2(center.x, startY - i * 45));
        items.pushBack(item);
    }

    auto menu = Menu::createWithArray(items);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}

void MenuScene::onSpriteDemo(Ref* sender) {
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.3f, SpriteDemo::create()));
}

void MenuScene::onActionDemo(Ref* sender) {
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.3f, ActionDemo::create()));
}

void MenuScene::onLabelDemo(Ref* sender) {
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.3f, LabelDemo::create()));
}

void MenuScene::onInputDemo(Ref* sender) {
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.3f, InputDemo::create()));
}

void MenuScene::onSceneDemo(Ref* sender) {
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.3f, SceneDemo::create()));
}

void MenuScene::onEventDemo(Ref* sender) {
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.3f, EventDemo::create()));
}

void MenuScene::onNodeDemo(Ref* sender) {
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.3f, NodeDemo::create()));
}

void MenuScene::onAnimationDemo(Ref* sender) {
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.3f, AnimationDemo::create()));
}
