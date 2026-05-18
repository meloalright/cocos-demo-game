#include "NodeDemo.h"

USING_NS_CC;

bool NodeDemo::init() {
    if (!DemoBase::init()) return false;
    addTitle("Node Hierarchy Demo");

    // --- Left: Parent-child transform inheritance ---
    auto sectionLabel1 = Label::createWithSystemFont("Parent-Child Transforms", "Arial", 18);
    sectionLabel1->setPosition(Vec2(_center.x - 250, _center.y + 150));
    sectionLabel1->setColor(Color3B(200, 200, 255));
    this->addChild(sectionLabel1);

    auto parentNode = Node::create();
    parentNode->setPosition(Vec2(_center.x - 250, _center.y + 30));
    this->addChild(parentNode);

    auto parentBox = DrawNode::create();
    parentBox->drawSolidRect(Vec2(-60, -60), Vec2(60, 60), Color4F(0.3f, 0.3f, 0.6f, 0.5f));
    parentBox->drawRect(Vec2(-60, -60), Vec2(60, 60), Color4F::WHITE);
    parentNode->addChild(parentBox);

    auto parentLabel = Label::createWithSystemFont("Parent", "Arial", 12);
    parentLabel->setPosition(Vec2(0, 50));
    parentNode->addChild(parentLabel);

    auto child1 = DrawNode::create();
    child1->drawSolidRect(Vec2(-20, -20), Vec2(20, 20), Color4F(1.0f, 0.3f, 0.3f, 1.0f));
    child1->setPosition(Vec2(-30, -20));
    parentNode->addChild(child1);

    auto c1Label = Label::createWithSystemFont("Child 1", "Arial", 10);
    c1Label->setPosition(Vec2(-30, -45));
    parentNode->addChild(c1Label);

    auto child2 = DrawNode::create();
    child2->drawSolidRect(Vec2(-20, -20), Vec2(20, 20), Color4F(0.3f, 1.0f, 0.3f, 1.0f));
    child2->setPosition(Vec2(30, -20));
    parentNode->addChild(child2);

    auto c2Label = Label::createWithSystemFont("Child 2", "Arial", 10);
    c2Label->setPosition(Vec2(30, -45));
    parentNode->addChild(c2Label);

    parentNode->runAction(RepeatForever::create(RotateBy::create(4.0f, 360.0f)));

    auto rotateHint = Label::createWithSystemFont("Parent rotates → children follow", "Arial", 12);
    rotateHint->setPosition(Vec2(_center.x - 250, _center.y - 60));
    rotateHint->setColor(Color3B(160, 160, 160));
    this->addChild(rotateHint);

    // --- Center: Z-order layering ---
    auto sectionLabel2 = Label::createWithSystemFont("Z-Order Layering", "Arial", 18);
    sectionLabel2->setPosition(Vec2(_center.x, _center.y + 150));
    sectionLabel2->setColor(Color3B(200, 200, 255));
    this->addChild(sectionLabel2);

    Color4F zColors[] = {
        Color4F(0.8f, 0.2f, 0.2f, 0.8f),
        Color4F(0.2f, 0.8f, 0.2f, 0.8f),
        Color4F(0.2f, 0.2f, 0.8f, 0.8f),
    };
    for (int i = 0; i < 3; i++) {
        auto box = DrawNode::create();
        box->drawSolidRect(Vec2(-35, -35), Vec2(35, 35), zColors[i]);
        box->drawRect(Vec2(-35, -35), Vec2(35, 35), Color4F::WHITE);
        box->setPosition(Vec2(_center.x - 25 + i * 25, _center.y + 55 - i * 25));
        this->addChild(box, i);

        auto zLabel = Label::createWithSystemFont(StringUtils::format("z=%d", i), "Arial", 14);
        zLabel->setPosition(Vec2(0, 0));
        box->addChild(zLabel);
    }

    auto zHint = Label::createWithSystemFont("Higher z-order draws on top", "Arial", 12);
    zHint->setPosition(Vec2(_center.x, _center.y - 30));
    zHint->setColor(Color3B(160, 160, 160));
    this->addChild(zHint, 10);

    // --- Right: Anchor point visualization ---
    auto sectionLabel3 = Label::createWithSystemFont("Anchor Points", "Arial", 18);
    sectionLabel3->setPosition(Vec2(_center.x + 250, _center.y + 150));
    sectionLabel3->setColor(Color3B(200, 200, 255));
    this->addChild(sectionLabel3);

    struct AnchorEntry {
        Vec2 anchor;
        std::string name;
        float offsetY;
    };
    std::vector<AnchorEntry> anchors = {
        {Vec2(0.5f, 0.5f), "Center (0.5,0.5)", 70},
        {Vec2(0.0f, 0.0f), "BottomLeft (0,0)", 0},
        {Vec2(1.0f, 1.0f), "TopRight (1,1)", -70},
    };

    for (auto& a : anchors) {
        Vec2 boxPos = Vec2(_center.x + 250, _center.y + a.offsetY);

        auto box = DrawNode::create();
        box->drawSolidRect(Vec2(0, 0), Vec2(50, 50), Color4F(0.5f, 0.5f, 0.2f, 0.7f));
        box->drawRect(Vec2(0, 0), Vec2(50, 50), Color4F::WHITE);
        box->setAnchorPoint(a.anchor);
        box->setPosition(boxPos);
        this->addChild(box, 5);

        auto dot = DrawNode::create();
        dot->drawDot(boxPos, 4, Color4F::RED);
        this->addChild(dot, 6);

        auto anchorLabel = Label::createWithSystemFont(a.name, "Arial", 10);
        anchorLabel->setPosition(Vec2(boxPos.x, boxPos.y - 35));
        this->addChild(anchorLabel, 6);
    }

    // --- Bottom: Coordinate conversion ---
    auto coordLabel = Label::createWithSystemFont(
        "Coordinate System: origin at bottom-left (OpenGL style), Y-axis up",
        "Arial", 13);
    coordLabel->setPosition(Vec2(_center.x, _origin.y + 55));
    coordLabel->setColor(Color3B(160, 160, 160));
    this->addChild(coordLabel, 10);

    auto apiLabel = Label::createWithSystemFont(
        "APIs: setPosition, setRotation, setScale, setAnchorPoint, addChild(node, zOrder)",
        "Arial", 13);
    apiLabel->setPosition(Vec2(_center.x, _origin.y + 30));
    apiLabel->setColor(Color3B(130, 130, 130));
    this->addChild(apiLabel, 10);

    return true;
}
