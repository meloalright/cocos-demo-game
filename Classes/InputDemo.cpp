#include "InputDemo.h"

USING_NS_CC;

bool InputDemo::init() {
    if (!DemoBase::init()) return false;
    addTitle("Input Demo");

    _statusLabel = Label::createWithSystemFont("Use arrow keys to move | Click/touch anywhere", "Arial", 16);
    _statusLabel->setPosition(Vec2(_center.x, _origin.y + _visibleSize.height - 70));
    _statusLabel->setColor(Color3B(180, 180, 180));
    this->addChild(_statusLabel, 5);

    _playerNode = DrawNode::create();
    _playerNode->drawSolidRect(Vec2(-25, -25), Vec2(25, 25), Color4F(0.2f, 0.7f, 1.0f, 1.0f));
    _playerNode->drawSolidRect(Vec2(-8, 5), Vec2(8, 20), Color4F(1.0f, 1.0f, 1.0f, 1.0f));
    _playerNode->setPosition(_center);
    this->addChild(_playerNode);

    // Keyboard input
    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event* event) {
        _pressedKeys.insert(keyCode);
        _statusLabel->setString(StringUtils::format("Key pressed: %d", static_cast<int>(keyCode)));
    };
    keyListener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event* event) {
        _pressedKeys.erase(keyCode);
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

    // Touch input
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(false);
    touchListener->onTouchBegan = [this](Touch* touch, Event* event) -> bool {
        Vec2 loc = touch->getLocation();
        _statusLabel->setString(StringUtils::format("Touch: (%.0f, %.0f)", loc.x, loc.y));

        auto marker = DrawNode::create();
        marker->drawDot(Vec2::ZERO, 10, Color4F(1.0f, 0.3f, 0.3f, 0.8f));
        marker->setPosition(loc);
        this->addChild(marker, 3);

        auto fadeSeq = Sequence::create(
            FadeOut::create(1.0f),
            RemoveSelf::create(),
            nullptr);
        marker->runAction(fadeSeq);

        auto moveTo = MoveTo::create(0.5f, loc);
        _playerNode->runAction(EaseExponentialOut::create(moveTo));
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    // Mouse input
    auto mouseListener = EventListenerMouse::create();
    mouseListener->onMouseMove = [this](EventMouse* event) {
        Vec2 loc = event->getLocationInView();
        loc.y += _visibleSize.height;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

    auto hint = Label::createWithSystemFont(
        "Arrow keys: move player | Click: teleport player | Touch markers fade out",
        "Arial", 13);
    hint->setPosition(Vec2(_center.x, _origin.y + 30));
    hint->setColor(Color3B(160, 160, 160));
    this->addChild(hint);

    this->scheduleUpdate();
    return true;
}

void InputDemo::update(float dt) {
    float speed = 200.0f * dt;
    Vec2 pos = _playerNode->getPosition();

    if (_pressedKeys.count(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
        pos.x -= speed;
    if (_pressedKeys.count(EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
        pos.x += speed;
    if (_pressedKeys.count(EventKeyboard::KeyCode::KEY_UP_ARROW))
        pos.y += speed;
    if (_pressedKeys.count(EventKeyboard::KeyCode::KEY_DOWN_ARROW))
        pos.y -= speed;

    pos.x = clampf(pos.x, _origin.x + 25, _origin.x + _visibleSize.width - 25);
    pos.y = clampf(pos.y, _origin.y + 25, _origin.y + _visibleSize.height - 25);

    _playerNode->setPosition(pos);
}
