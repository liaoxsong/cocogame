#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	void ccTouchesBeg(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	bool onTouchBegan(cocos2d::Touch *touch,cocos2d::Event *event);
	void onTouchMoved(cocos2d::Touch *touch,cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *event);
        // a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(HelloWorld);

    cocos2d::Sprite *myHero;
    cocos2d::Sprite *background;

};

#endif // __HELLOWORLD_SCENE_H__
