#include "AnimationDemo.h"

USING_NS_CC;

bool AnimationDemo::init() {
    if (!DemoBase::init()) return false;
    addTitle("Animation Demo");

    auto bg = LayerColor::create(Color4B(30, 30, 45, 255));
    this->addChild(bg, -1);

    auto subtitle = Label::createWithSystemFont(
        "Simulated sprite-frame animation using programmatic shapes",
        "Arial", 14);
    subtitle->setPosition(Vec2(_center.x, _origin.y + _visibleSize.height - 70));
    subtitle->setColor(Color3B(160, 160, 160));
    this->addChild(subtitle, 5);

    // Character (DrawNode based)
    _character = DrawNode::create();
    _character->drawSolidRect(Vec2(-30, -40), Vec2(30, 40), Color4F(0.2f, 0.5f, 1.0f, 1.0f));
    _character->drawSolidRect(Vec2(-10, 15), Vec2(10, 30), Color4F(1.0f, 1.0f, 1.0f, 1.0f));
    _character->setPosition(Vec2(_center.x, _center.y + 40));
    this->addChild(_character);

    _stateLabel = Label::createWithSystemFont("State: Idle", "Arial", 22);
    _stateLabel->setPosition(Vec2(_center.x, _center.y - 40));
    _stateLabel->setColor(Color3B(200, 200, 255));
    this->addChild(_stateLabel);

    // Buttons
    auto btnIdle = MenuItemLabel::create(
        Label::createWithSystemFont("[Idle]", "Arial", 24),
        [this](Ref*) { playIdle(); });
    btnIdle->setColor(Color3B(100, 200, 255));

    auto btnWalk = MenuItemLabel::create(
        Label::createWithSystemFont("[Walk]", "Arial", 24),
        [this](Ref*) { playWalk(); });
    btnWalk->setColor(Color3B(100, 255, 100));

    auto btnJump = MenuItemLabel::create(
        Label::createWithSystemFont("[Jump]", "Arial", 24),
        [this](Ref*) { playJump(); });
    btnJump->setColor(Color3B(255, 255, 100));

    auto btnAttack = MenuItemLabel::create(
        Label::createWithSystemFont("[Attack]", "Arial", 24),
        [this](Ref*) { playAttack(); });
    btnAttack->setColor(Color3B(255, 100, 100));

    btnIdle->setPosition(Vec2(_center.x - 200, _center.y - 100));
    btnWalk->setPosition(Vec2(_center.x - 60, _center.y - 100));
    btnJump->setPosition(Vec2(_center.x + 80, _center.y - 100));
    btnAttack->setPosition(Vec2(_center.x + 220, _center.y - 100));

    auto menu = Menu::create(btnIdle, btnWalk, btnJump, btnAttack, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    // Code reference
    auto codeRef = Label::createWithSystemFont(
        "Real games: SpriteFrameCache + Animation::createWithSpriteFrames + Animate",
        "Arial", 13);
    codeRef->setPosition(Vec2(_center.x, _origin.y + 55));
    codeRef->setColor(Color3B(160, 160, 160));
    this->addChild(codeRef);

    auto codeRef2 = Label::createWithSystemFont(
        "Pattern: stopAllActions → runAction(RepeatForever/Sequence(Animate, CallFunc))",
        "Arial", 13);
    codeRef2->setPosition(Vec2(_center.x, _origin.y + 30));
    codeRef2->setColor(Color3B(130, 130, 130));
    this->addChild(codeRef2);

    playIdle();
    return true;
}

void AnimationDemo::playIdle() {
    _character->stopAllActions();
    _stateLabel->setString("State: Idle");

    auto breatheUp = ScaleTo::create(1.0f, 1.0f, 1.05f);
    auto breatheDown = ScaleTo::create(1.0f, 1.0f, 0.95f);
    _character->runAction(RepeatForever::create(
        Sequence::create(
            EaseInOut::create(breatheUp, 2.0f),
            EaseInOut::create(breatheDown, 2.0f),
            nullptr)));
}

void AnimationDemo::playWalk() {
    _character->stopAllActions();
    _stateLabel->setString("State: Walk");

    auto tiltLeft = RotateTo::create(0.15f, -10.0f);
    auto tiltRight = RotateTo::create(0.15f, 10.0f);
    auto moveRight = MoveBy::create(0.3f, Vec2(30, 0));

    auto walkCycle = Sequence::create(tiltLeft, tiltRight, nullptr);
    auto walkMove = RepeatForever::create(Sequence::create(
        moveRight->clone(), moveRight->reverse(), nullptr));

    _character->runAction(RepeatForever::create(walkCycle));
    _character->runAction(walkMove);
}

void AnimationDemo::playJump() {
    _character->stopAllActions();
    _stateLabel->setString("State: Jump");

    auto squash = ScaleTo::create(0.1f, 1.2f, 0.8f);
    auto jumpUp = Spawn::create(
        ScaleTo::create(0.3f, 0.9f, 1.1f),
        MoveBy::create(0.3f, Vec2(0, 120)),
        nullptr);
    auto fall = Spawn::create(
        ScaleTo::create(0.25f, 1.0f, 1.0f),
        MoveBy::create(0.25f, Vec2(0, -120)),
        nullptr);
    auto land = Sequence::create(
        ScaleTo::create(0.08f, 1.3f, 0.7f),
        ScaleTo::create(0.15f, 1.0f, 1.0f),
        nullptr);
    auto done = CallFunc::create([this]() { playIdle(); });

    _character->runAction(Sequence::create(squash, jumpUp, fall, land, done, nullptr));
}

void AnimationDemo::playAttack() {
    _character->stopAllActions();
    _stateLabel->setString("State: Attack");

    auto windUp = Sequence::create(
        ScaleTo::create(0.1f, 0.85f, 1.1f),
        RotateTo::create(0.1f, -15.0f),
        nullptr);
    auto strike = Spawn::create(
        RotateTo::create(0.08f, 15.0f),
        ScaleTo::create(0.08f, 1.3f, 0.9f),
        nullptr);
    auto recover = Spawn::create(
        RotateTo::create(0.2f, 0.0f),
        ScaleTo::create(0.2f, 1.0f, 1.0f),
        nullptr);
    auto done = CallFunc::create([this]() { playIdle(); });

    _character->runAction(Sequence::create(windUp, strike, recover, done, nullptr));
}
