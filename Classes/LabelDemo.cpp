#include "LabelDemo.h"

USING_NS_CC;

bool LabelDemo::init() {
    if (!DemoBase::init()) return false;
    addTitle("Label Demo");

    float colLeft = _center.x - 200;
    float colRight = _center.x + 200;

    // 1. System font
    auto label1 = Label::createWithSystemFont("System Font Label", "Arial", 26);
    label1->setPosition(Vec2(colLeft, _center.y + 150));
    label1->setColor(Color3B::WHITE);
    this->addChild(label1);

    auto desc1 = Label::createWithSystemFont("createWithSystemFont", "Arial", 12);
    desc1->setPosition(Vec2(colLeft, _center.y + 125));
    desc1->setColor(Color3B(150, 150, 150));
    this->addChild(desc1);

    // 2. Colored label
    auto label2 = Label::createWithSystemFont("Colored Label", "Arial", 26);
    label2->setPosition(Vec2(colRight, _center.y + 150));
    label2->setTextColor(Color4B(255, 100, 50, 255));
    this->addChild(label2);

    auto desc2 = Label::createWithSystemFont("setTextColor()", "Arial", 12);
    desc2->setPosition(Vec2(colRight, _center.y + 125));
    desc2->setColor(Color3B(150, 150, 150));
    this->addChild(desc2);

    // 3. Outline label
    auto label3 = Label::createWithSystemFont("Outline Effect", "Arial", 28);
    label3->setPosition(Vec2(colLeft, _center.y + 50));
    label3->setColor(Color3B::WHITE);
    label3->enableOutline(Color4B::BLACK, 3);
    this->addChild(label3);

    auto desc3 = Label::createWithSystemFont("enableOutline()", "Arial", 12);
    desc3->setPosition(Vec2(colLeft, _center.y + 25));
    desc3->setColor(Color3B(150, 150, 150));
    this->addChild(desc3);

    // 4. Shadow label
    auto label4 = Label::createWithSystemFont("Shadow Effect", "Arial", 28);
    label4->setPosition(Vec2(colRight, _center.y + 50));
    label4->setColor(Color3B(100, 200, 255));
    label4->enableShadow(Color4B(0, 0, 0, 180), Size(3, -3), 0);
    this->addChild(label4);

    auto desc4 = Label::createWithSystemFont("enableShadow()", "Arial", 12);
    desc4->setPosition(Vec2(colRight, _center.y + 25));
    desc4->setColor(Color3B(150, 150, 150));
    this->addChild(desc4);

    // 5. Glow label
    auto label5 = Label::createWithSystemFont("Glow Effect", "Arial", 28);
    label5->setPosition(Vec2(colLeft, _center.y - 50));
    label5->setColor(Color3B(255, 255, 100));
    label5->enableGlow(Color4B(255, 200, 0, 200));
    this->addChild(label5);

    auto desc5 = Label::createWithSystemFont("enableGlow()", "Arial", 12);
    desc5->setPosition(Vec2(colLeft, _center.y - 75));
    desc5->setColor(Color3B(150, 150, 150));
    this->addChild(desc5);

    // 6. Word-wrapped label
    auto label6 = Label::createWithSystemFont(
        "This is a long text that demonstrates word wrapping with setDimensions and enableWrap.",
        "Arial", 16);
    label6->setPosition(Vec2(colRight, _center.y - 50));
    label6->setDimensions(250, 0);
    label6->enableWrap(true);
    label6->setAlignment(TextHAlignment::LEFT, TextVAlignment::TOP);
    this->addChild(label6);

    auto desc6 = Label::createWithSystemFont("setDimensions() + enableWrap()", "Arial", 12);
    desc6->setPosition(Vec2(colRight, _center.y - 110));
    desc6->setColor(Color3B(150, 150, 150));
    this->addChild(desc6);

    // 7. Dynamic counter label
    _dynamicLabel = Label::createWithSystemFont("Counter: 0", "Arial", 30);
    _dynamicLabel->setPosition(Vec2(_center.x, _center.y - 180));
    _dynamicLabel->setColor(Color3B(100, 255, 100));
    this->addChild(_dynamicLabel);

    auto desc7 = Label::createWithSystemFont("Dynamic update via setString() — increments every 0.5s", "Arial", 12);
    desc7->setPosition(Vec2(_center.x, _center.y - 210));
    desc7->setColor(Color3B(150, 150, 150));
    this->addChild(desc7);

    this->scheduleUpdate();
    return true;
}

void LabelDemo::update(float dt) {
    static float elapsed = 0;
    elapsed += dt;
    if (elapsed >= 0.5f) {
        elapsed = 0;
        _counter++;
        _dynamicLabel->setString(StringUtils::format("Counter: %d", _counter));
    }
}
