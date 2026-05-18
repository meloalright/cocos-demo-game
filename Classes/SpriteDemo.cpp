#include "SpriteDemo.h"

USING_NS_CC;

bool SpriteDemo::init() {
    if (!DemoBase::init()) return false;
    addTitle("Sprite Demo");

    // 1. Basic colored sprite (DrawNode as programmatic sprite)
    auto sprite1 = DrawNode::create();
    sprite1->drawSolidRect(Vec2(-40, -40), Vec2(40, 40), Color4F(0.2f, 0.6f, 1.0f, 1.0f));
    sprite1->setPosition(Vec2(_center.x - 200, _center.y + 80));
    this->addChild(sprite1);

    auto label1 = Label::createWithSystemFont("Basic Sprite", "Arial", 14);
    label1->setPosition(Vec2(_center.x - 200, _center.y + 20));
    this->addChild(label1);

    // 2. Sprite with rotation
    auto sprite2 = DrawNode::create();
    sprite2->drawSolidRect(Vec2(-35, -35), Vec2(35, 35), Color4F(1.0f, 0.4f, 0.2f, 1.0f));
    sprite2->setPosition(Vec2(_center.x, _center.y + 80));
    sprite2->setRotation(45.0f);
    this->addChild(sprite2);

    auto label2 = Label::createWithSystemFont("Rotated (45°)", "Arial", 14);
    label2->setPosition(Vec2(_center.x, _center.y + 20));
    this->addChild(label2);

    // 3. Sprite with scale
    auto sprite3 = DrawNode::create();
    sprite3->drawSolidRect(Vec2(-25, -25), Vec2(25, 25), Color4F(0.2f, 0.9f, 0.4f, 1.0f));
    sprite3->setPosition(Vec2(_center.x + 200, _center.y + 80));
    sprite3->setScale(1.5f);
    this->addChild(sprite3);

    auto label3 = Label::createWithSystemFont("Scaled (1.5x)", "Arial", 14);
    label3->setPosition(Vec2(_center.x + 200, _center.y + 20));
    this->addChild(label3);

    // 4. Sprite with opacity
    auto sprite4 = DrawNode::create();
    sprite4->drawSolidRect(Vec2(-40, -40), Vec2(40, 40), Color4F(1.0f, 0.8f, 0.0f, 1.0f));
    sprite4->setPosition(Vec2(_center.x - 200, _center.y - 100));
    sprite4->setOpacity(128);
    this->addChild(sprite4);

    auto label4 = Label::createWithSystemFont("Opacity (50%)", "Arial", 14);
    label4->setPosition(Vec2(_center.x - 200, _center.y - 160));
    this->addChild(label4);

    // 5. Sprite with anchor point demo
    auto sprite5 = DrawNode::create();
    sprite5->drawSolidRect(Vec2(0, 0), Vec2(60, 60), Color4F(0.8f, 0.2f, 0.8f, 1.0f));
    sprite5->setPosition(Vec2(_center.x, _center.y - 100));
    sprite5->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(sprite5);

    auto dot5 = DrawNode::create();
    dot5->drawDot(Vec2(_center.x, _center.y - 100), 4, Color4F::RED);
    this->addChild(dot5, 5);

    auto label5 = Label::createWithSystemFont("Anchor (0,0)", "Arial", 14);
    label5->setPosition(Vec2(_center.x, _center.y - 160));
    this->addChild(label5);

    // 6. Flipped sprite
    auto sprite6 = DrawNode::create();
    Vec2 triangle[3] = {Vec2(-30, -30), Vec2(30, -30), Vec2(0, 30)};
    sprite6->drawSolidPoly(triangle, 3, Color4F(0.0f, 0.8f, 0.8f, 1.0f));
    sprite6->setPosition(Vec2(_center.x + 200, _center.y - 100));
    sprite6->setScaleX(-1.0f);
    this->addChild(sprite6);

    auto label6 = Label::createWithSystemFont("Flipped X", "Arial", 14);
    label6->setPosition(Vec2(_center.x + 200, _center.y - 160));
    this->addChild(label6);

    auto desc = Label::createWithSystemFont(
        "Demonstrates: create, position, rotation, scale, opacity, anchor point, flip",
        "Arial", 13);
    desc->setPosition(Vec2(_center.x, _origin.y + 30));
    desc->setColor(Color3B(160, 160, 160));
    this->addChild(desc);

    return true;
}
