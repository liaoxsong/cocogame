#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
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
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("testing_audio.wav");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "039-Mage07.png",
                                           "039-Mage07.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2((origin.x + visibleSize.width - closeItem->getContentSize().width/2) ,
                                (origin.y + visibleSize.height-closeItem->getContentSize().height/2))/2);
	closeItem->setScaleX(2);
	closeItem->setScaleY(2);
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Testing jpg", "fonts/Marker Felt.ttf", 30);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    label->setScaleX(2);
    label->setScaleY(2);
    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("001-Title01.jpg");


    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite->setScaleX(2.8);
    sprite->setScaleY(2.2);
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    auto listener=EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan=CC_CALLBACK_2(HelloWorld::onTouchBegan,this);
    listener->onTouchMoved=CC_CALLBACK_2(HelloWorld::onTouchMoved,this);
    listener->onTouchEnded=CC_CALLBACK_2(HelloWorld::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("testing_audio.wav");
    this->setTouchEnabled(true);
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
    auto sprite = Sprite::create("039-Mage07.png");
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(touch->getLocation().x, touch->getLocation().y));
    // add the sprite as a child to this layer
    this->addChild(sprite, 1);
}


/*void HelloWorld::ccTouchesBeg(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent){
	auto touch=(CCTouch*)pTouches->anyObject();
	auto location=touch->getLocationInView();
	location=CCDirector::getInstance()->convertToGL(location);
	auto sprite=Sprite::create("039-Mage07.png");
	sprite->setPosition(location);
	this->addChild(sprite,1);
}*/


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
