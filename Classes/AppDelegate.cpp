#include "AppDelegate.h"
#include "MenuScene.h"

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(960, 640);

AppDelegate::AppDelegate() {}
AppDelegate::~AppDelegate() {}

void AppDelegate::initGLContextAttrs() {
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};
    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
        glview = GLViewImpl::createWithRect("Cocos2d-x Feature Demo",
                                            cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(
        designResolutionSize.width, designResolutionSize.height,
        ResolutionPolicy::SHOW_ALL);

    director->setDisplayStats(true);
    director->setAnimationInterval(1.0f / 60);

    auto scene = MenuScene::createScene();
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
