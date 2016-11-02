#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	bool OnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void OnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void buttonPressed();
	void gotobestScene(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
