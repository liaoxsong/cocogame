#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

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

    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    CCSize size = CCDirector::sharedDirector()->getWinSize();

    //from lynda course, now this is using sublime text theme..
    background = CCSprite::create("moles_bg-hd.png");
    background->setPosition(ccp(size.width/2,size.height/2));
    this->addChild(background,1);

    float ratioX = size.width/ background->getContentSize().width;
    float ratioY = size.height/ background->getContentSize().height;

    background->setScaleX(ratioX);
    background->setScaleY(ratioY);

    auto label = LabelTTF::create("Good game2 ", "Arial", 34);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer

    this->addChild(label, 1);

    this->setTouchEnabled(true);

    auto listener=EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan=CC_CALLBACK_2(HelloWorld::onTouchBegan,this);
        listener->onTouchMoved=CC_CALLBACK_2(HelloWorld::onTouchMoved,this);
        listener->onTouchEnded=CC_CALLBACK_2(HelloWorld::onTouchEnded,this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

        setTouchMode(kCCTouchesOneByOne);

    return true;
}
bool HelloWorld::onTouchBegan(cocos2d::Touch *touch,cocos2d::Event *event){
	CCLOG("onTouchBegan x=%f,y=%f",touch->getLocation().x,touch->getLocation().y);
	return true;
}
void HelloWorld::onTouchMoved(cocos2d::Touch *touch,cocos2d::Event *event){
	CCLOG("onTouchMoved x=%f,y=%f",touch->getLocation().x,touch->getLocation().y);
}
void HelloWorld::onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *event){
	CCLOG("onTouchEnded x=%f,y=%f",touch->getLocation().x,touch->getLocation().y);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto sprite = Sprite::create("moles_icon.png");
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(touch->getLocation().x, touch->getLocation().y));
    // add the sprite as a child to this layer
    this->addChild(sprite, 1);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
