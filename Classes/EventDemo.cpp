#include "EventDemo.h"

USING_NS_CC;

static const std::string EVENT_SCORE_UP = "event_score_up";
static const std::string EVENT_RESET = "event_reset";
static const std::string EVENT_COLOR_CHANGE = "event_color_change";

bool EventDemo::init() {
    if (!DemoBase::init()) return false;
    addTitle("Event System Demo");

    auto bg = LayerColor::create(Color4B(35, 35, 50, 255));
    this->addChild(bg, -1);

    // Score display (listens to custom events)
    _scoreLabel = Label::createWithSystemFont("Score: 0", "Arial", 30);
    _scoreLabel->setPosition(Vec2(_center.x, _center.y + 140));
    _scoreLabel->setColor(Color3B(100, 255, 100));
    this->addChild(_scoreLabel);

    // Color-changing box (listens to color event)
    auto colorBox = DrawNode::create();
    colorBox->drawSolidRect(Vec2(-50, -50), Vec2(50, 50), Color4F(0.3f, 0.3f, 0.8f, 1.0f));
    colorBox->setPosition(Vec2(_center.x, _center.y + 40));
    colorBox->setTag(100);
    this->addChild(colorBox);

    // Event log area
    _logLabel = Label::createWithSystemFont("Event log:", "Arial", 14);
    _logLabel->setPosition(Vec2(_center.x, _center.y - 120));
    _logLabel->setDimensions(600, 100);
    _logLabel->enableWrap(true);
    _logLabel->setColor(Color3B(180, 180, 180));
    this->addChild(_logLabel);

    // --- Register custom event listeners ---

    auto scoreListener = EventListenerCustom::create(EVENT_SCORE_UP, [this](EventCustom* event) {
        int* points = static_cast<int*>(event->getUserData());
        _score += *points;
        _scoreLabel->setString(StringUtils::format("Score: %d", _score));
        addLog(StringUtils::format("EVENT_SCORE_UP: +%d (total: %d)", *points, _score));
    });
    _eventDispatcher->addEventListenerWithSceneGraphPriority(scoreListener, this);

    auto resetListener = EventListenerCustom::create(EVENT_RESET, [this](EventCustom* event) {
        _score = 0;
        _scoreLabel->setString("Score: 0");
        addLog("EVENT_RESET: score reset to 0");
    });
    _eventDispatcher->addEventListenerWithSceneGraphPriority(resetListener, this);

    auto colorListener = EventListenerCustom::create(EVENT_COLOR_CHANGE, [this](EventCustom* event) {
        auto box = this->getChildByTag(100);
        if (box) {
            auto oldBox = static_cast<DrawNode*>(box);
            oldBox->clear();
            float r = CCRANDOM_0_1(), g = CCRANDOM_0_1(), b = CCRANDOM_0_1();
            oldBox->drawSolidRect(Vec2(-50, -50), Vec2(50, 50), Color4F(r, g, b, 1.0f));
            addLog(StringUtils::format("EVENT_COLOR_CHANGE: (%.1f, %.1f, %.1f)", r, g, b));
        }
    });
    _eventDispatcher->addEventListenerWithSceneGraphPriority(colorListener, this);

    // --- Buttons that dispatch events ---

    auto btnAdd10 = Label::createWithSystemFont("[+10 Points]", "Arial", 22);
    btnAdd10->setColor(Color3B(100, 200, 255));
    auto itemAdd10 = MenuItemLabel::create(btnAdd10, [this](Ref*) {
        static int points = 10;
        EventCustom event(EVENT_SCORE_UP);
        event.setUserData(&points);
        _eventDispatcher->dispatchEvent(&event);
    });
    itemAdd10->setPosition(Vec2(_center.x - 200, _center.y - 40));

    auto btnAdd50 = Label::createWithSystemFont("[+50 Points]", "Arial", 22);
    btnAdd50->setColor(Color3B(100, 255, 200));
    auto itemAdd50 = MenuItemLabel::create(btnAdd50, [this](Ref*) {
        static int points = 50;
        EventCustom event(EVENT_SCORE_UP);
        event.setUserData(&points);
        _eventDispatcher->dispatchEvent(&event);
    });
    itemAdd50->setPosition(Vec2(_center.x, _center.y - 40));

    auto btnReset = Label::createWithSystemFont("[Reset]", "Arial", 22);
    btnReset->setColor(Color3B(255, 100, 100));
    auto itemReset = MenuItemLabel::create(btnReset, [this](Ref*) {
        EventCustom event(EVENT_RESET);
        _eventDispatcher->dispatchEvent(&event);
    });
    itemReset->setPosition(Vec2(_center.x + 200, _center.y - 40));

    auto btnColor = Label::createWithSystemFont("[Random Color]", "Arial", 22);
    btnColor->setColor(Color3B(255, 200, 100));
    auto itemColor = MenuItemLabel::create(btnColor, [this](Ref*) {
        EventCustom event(EVENT_COLOR_CHANGE);
        _eventDispatcher->dispatchEvent(&event);
    });
    itemColor->setPosition(Vec2(_center.x, _center.y - 80));

    auto menu = Menu::create(itemAdd10, itemAdd50, itemReset, itemColor, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    auto desc = Label::createWithSystemFont(
        "Demonstrates: EventListenerCustom, dispatchEvent, setUserData, decoupled messaging",
        "Arial", 13);
    desc->setPosition(Vec2(_center.x, _origin.y + 30));
    desc->setColor(Color3B(160, 160, 160));
    this->addChild(desc);

    return true;
}

void EventDemo::addLog(const std::string& msg) {
    std::string current = _logLabel->getString();
    std::string newLog = msg + "\n" + current;
    if (newLog.size() > 300) newLog = newLog.substr(0, 300);
    _logLabel->setString(newLog);
}
