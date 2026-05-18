#include "ActionDemo.h"

USING_NS_CC;

bool ActionDemo::init() {
    if (!DemoBase::init()) return false;
    addTitle("Action Demo");

    float row1Y = _center.y + 120;
    float row2Y = _center.y - 20;
    float row3Y = _center.y - 160;

    // 1. MoveTo / MoveBy
    auto box1 = DrawNode::create();
    box1->drawSolidRect(Vec2(-20, -20), Vec2(20, 20), Color4F(0.2f, 0.6f, 1.0f, 1.0f));
    box1->setPosition(Vec2(_origin.x + 100, row1Y));
    this->addChild(box1);
    auto moveRight = MoveBy::create(2.0f, Vec2(200, 0));
    auto moveLeft = moveRight->reverse();
    box1->runAction(RepeatForever::create(Sequence::create(moveRight, moveLeft, nullptr)));

    auto l1 = Label::createWithSystemFont("MoveBy (back & forth)", "Arial", 13);
    l1->setPosition(Vec2(_origin.x + 200, row1Y - 35));
    this->addChild(l1);

    // 2. RotateBy
    auto box2 = DrawNode::create();
    box2->drawSolidRect(Vec2(-20, -20), Vec2(20, 20), Color4F(1.0f, 0.4f, 0.2f, 1.0f));
    box2->setPosition(Vec2(_center.x, row1Y));
    this->addChild(box2);
    box2->runAction(RepeatForever::create(RotateBy::create(2.0f, 360.0f)));

    auto l2 = Label::createWithSystemFont("RotateBy (360°)", "Arial", 13);
    l2->setPosition(Vec2(_center.x, row1Y - 35));
    this->addChild(l2);

    // 3. ScaleBy
    auto box3 = DrawNode::create();
    box3->drawSolidRect(Vec2(-20, -20), Vec2(20, 20), Color4F(0.2f, 0.9f, 0.4f, 1.0f));
    box3->setPosition(Vec2(_origin.x + _visibleSize.width - 150, row1Y));
    this->addChild(box3);
    auto scaleUp = ScaleTo::create(1.0f, 2.0f);
    auto scaleDown = ScaleTo::create(1.0f, 1.0f);
    box3->runAction(RepeatForever::create(Sequence::create(scaleUp, scaleDown, nullptr)));

    auto l3 = Label::createWithSystemFont("ScaleTo (pulse)", "Arial", 13);
    l3->setPosition(Vec2(_origin.x + _visibleSize.width - 150, row1Y - 35));
    this->addChild(l3);

    // 4. FadeIn / FadeOut
    auto box4 = DrawNode::create();
    box4->drawSolidRect(Vec2(-20, -20), Vec2(20, 20), Color4F(1.0f, 0.8f, 0.0f, 1.0f));
    box4->setPosition(Vec2(_origin.x + 100, row2Y));
    this->addChild(box4);
    auto fadeOut = FadeOut::create(1.5f);
    auto fadeIn = FadeIn::create(1.5f);
    box4->runAction(RepeatForever::create(Sequence::create(fadeOut, fadeIn, nullptr)));

    auto l4 = Label::createWithSystemFont("Fade In/Out", "Arial", 13);
    l4->setPosition(Vec2(_origin.x + 100, row2Y - 35));
    this->addChild(l4);

    // 5. Sequence + Spawn
    auto box5 = DrawNode::create();
    box5->drawSolidRect(Vec2(-20, -20), Vec2(20, 20), Color4F(0.8f, 0.2f, 0.8f, 1.0f));
    box5->setPosition(Vec2(_center.x, row2Y));
    this->addChild(box5);
    auto move5 = MoveBy::create(1.5f, Vec2(100, 0));
    auto rotate5 = RotateBy::create(1.5f, 360.0f);
    auto spawn5 = Spawn::create(move5, rotate5, nullptr);
    auto spawnRev = Spawn::create(move5->reverse(), rotate5->reverse(), nullptr);
    box5->runAction(RepeatForever::create(Sequence::create(spawn5, spawnRev, nullptr)));

    auto l5 = Label::createWithSystemFont("Spawn (move+rotate)", "Arial", 13);
    l5->setPosition(Vec2(_center.x, row2Y - 35));
    this->addChild(l5);

    // 6. JumpBy
    auto box6 = DrawNode::create();
    box6->drawSolidRect(Vec2(-20, -20), Vec2(20, 20), Color4F(0.0f, 0.8f, 0.8f, 1.0f));
    box6->setPosition(Vec2(_origin.x + _visibleSize.width - 150, row2Y));
    this->addChild(box6);
    auto jump = JumpBy::create(2.0f, Vec2(0, 0), 80, 3);
    box6->runAction(RepeatForever::create(jump));

    auto l6 = Label::createWithSystemFont("JumpBy", "Arial", 13);
    l6->setPosition(Vec2(_origin.x + _visibleSize.width - 150, row2Y - 35));
    this->addChild(l6);

    // 7. EaseElastic
    auto box7 = DrawNode::create();
    box7->drawSolidRect(Vec2(-20, -20), Vec2(20, 20), Color4F(1.0f, 0.5f, 0.5f, 1.0f));
    box7->setPosition(Vec2(_origin.x + 100, row3Y));
    this->addChild(box7);
    auto easeMove = MoveBy::create(2.0f, Vec2(200, 0));
    auto easeMoveRev = MoveBy::create(2.0f, Vec2(-200, 0));
    box7->runAction(RepeatForever::create(Sequence::create(
        EaseElasticOut::create(easeMove->clone(), 0.4f),
        EaseElasticOut::create(easeMoveRev->clone(), 0.4f),
        nullptr)));

    auto l7 = Label::createWithSystemFont("EaseElasticOut", "Arial", 13);
    l7->setPosition(Vec2(_origin.x + 200, row3Y - 35));
    this->addChild(l7);

    // 8. EaseBounce
    auto box8 = DrawNode::create();
    box8->drawSolidRect(Vec2(-20, -20), Vec2(20, 20), Color4F(0.5f, 1.0f, 0.5f, 1.0f));
    box8->setPosition(Vec2(_center.x + 100, row3Y));
    this->addChild(box8);
    auto bounceMove = MoveBy::create(2.0f, Vec2(0, 100));
    auto bounceMoveRev = MoveBy::create(2.0f, Vec2(0, -100));
    box8->runAction(RepeatForever::create(Sequence::create(
        EaseBounceOut::create(bounceMove->clone()),
        EaseBounceOut::create(bounceMoveRev->clone()),
        nullptr)));

    auto l8 = Label::createWithSystemFont("EaseBounceOut", "Arial", 13);
    l8->setPosition(Vec2(_center.x + 100, row3Y - 35));
    this->addChild(l8);

    return true;
}
