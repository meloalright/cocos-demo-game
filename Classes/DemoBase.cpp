#include "DemoBase.h"
#include "MenuScene.h"

USING_NS_CC;

bool DemoBase::init() {
    if (!Scene::init()) return false;

    auto director = Director::getInstance();
    _visibleSize = director->getVisibleSize();
    _origin = director->getVisibleOrigin();
    _center = Vec2(_origin.x + _visibleSize.width / 2,
                   _origin.y + _visibleSize.height / 2);

    addBackButton();
    return true;
}

void DemoBase::addTitle(const std::string& title) {
    auto label = Label::createWithSystemFont(title, "Arial", 28);
    label->setPosition(Vec2(_center.x,
                            _origin.y + _visibleSize.height - 30));
    label->setColor(Color3B::WHITE);
    this->addChild(label, 10);
}

void DemoBase::addBackButton() {
    auto label = Label::createWithSystemFont("< Back", "Arial", 20);
    auto item = MenuItemLabel::create(label, CC_CALLBACK_1(DemoBase::onBack, this));
    item->setPosition(Vec2(_origin.x + 50, _origin.y + _visibleSize.height - 30));

    auto menu = Menu::create(item, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 10);
}

void DemoBase::onBack(Ref* sender) {
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.3f, MenuScene::createScene()));
}
