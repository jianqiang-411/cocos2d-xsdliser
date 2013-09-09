#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace extension;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCNode *node = CCNode::create();
    node->setPosition(CCPoint(100,100));
    //addChild(node);
    
    CCControlSlider *slider2 = CCControlSlider::create("sliderTrack.png", "sliderProgress.png", "sliderThumb.png");
    slider2->setAnchorPoint(ccp(0.5f, 1.0f));
    slider2->setMinimumValue(0.0f); // Sets the min value of range
    slider2->setMaximumValue(5.0f); // Sets the max value of range
    slider2->setPosition(ccp(300, 600));
    slider2->setTag(1);
    slider2->setTouchEnabled(true);
    //slider2->addTargetWithActionForControlEvents(this, cccontrol_selector(GameMain::moveMenuContainer), CCControlEventValueChanged);
    this->addChild(slider2,1);

    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
