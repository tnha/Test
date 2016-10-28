#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Xin Chao", "fonts/Marker Felt.ttf", 24);
	CCLOG("visible size height: %f", visibleSize.height);
	CCLOG("visible size wid: %f", visibleSize.width);
	
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    //-------------------------------------------Tạo sprite

    auto sprite = Sprite::create("HelloWorld.png");

	sprite->setScale(0.5);//---kích thước

    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));//---vị trí

	sprite->setAnchorPoint(Vec2(0.5,0.5));//--chọn điểm cố định làm trọng tâm của sprite

	sprite->setRotation(45); //--góc xoay( âm sang trái, dương sang phải)

	//--------------------di chuyển sprite

	auto moveBy = MoveBy::create(2, Vec2(400, sprite->getPositionY()));

	auto moveTo = MoveTo::create(2, Vec2(50, sprite->getPositionY()));

	auto delay = DelayTime::create(1);

	auto seq = Sequence::create(moveBy, delay, moveTo, nullptr);

	//sprite->runAction(seq);

	sprite->runAction(RepeatForever::create(seq));

    this->addChild(sprite, 0);
	//--------------------------------------------------------------------Tạo sprite1

	auto sprite1 = Sprite::create("HelloWorld.png");

	sprite1->setAnchorPoint(Vec2(0, 0));

	sprite1->setPosition(1, 1);
	
	sprite1->setScale(0.5);

	sprite1->setSkewX(20);//---góc nghiêng(âm sang trái, dương sang phải)

	sprite1->setColor(Color3B::GREEN);//---thay đổi màu của sprite

	//---------------------di chuyển sprite1 tới vị trí cố định

	auto moveTo1 = MoveTo::create(2, Vec2(100, 0));

	sprite1->runAction(moveTo1);

	auto moveBy1 = MoveBy::create(2, Vec2(100, 0));

	sprite1->runAction(moveBy1);           
	//--------------------------------------

/*	auto moveBy2 = MoveBy::create(10, Vec2(400, 100));
	auto fadeTo = FadeTo::create(2.0f, 120.0f);
	auto mySpawn = Spawn::createWithTwoActions(moveBy, fadeTo);

	sprite1->runAction(mySpawn->reverse());            */



	this->addChild(sprite1, 0);
	//------------------------------------ Tạo sprite 2

	auto sprite2 = Sprite::create("HelloWorld.png");

	sprite2->setAnchorPoint(Vec2(0.5, 0.5));

	sprite2->setPosition(Vec2(100, visibleSize.height / 2 + origin.y));

	sprite2->setScale(0.5);

	sprite2->setOpacity(50);

	//------------------------------------------Chuyển động xoay

	auto rotateBy = RotateBy::create(5.0f, 360.0f);

	sprite2->runAction(rotateBy);



	auto rotateTo = RotateTo::create(5.0f,360.0f);
	
	sprite2->runAction(rotateTo);

	this->addChild(sprite2, 0);

	//---------------------------------------------chuyển động tăng giảm kích thước

	auto sprite3 = Sprite::create("HelloWorld.png");

	sprite3->setAnchorPoint(Vec2(0.5, 0.5));

	sprite3->setPosition(Vec2(100, visibleSize.height / 2 + origin.y));

	sprite3->setScale(0.5);

	sprite3->setOpacity(100);

	auto scaleBy = ScaleBy::create(5.0f, 3.0f);
	
	sprite3->runAction(scaleBy);

	
	auto scaleTo = ScaleTo::create(5.0f, 3.0f);
	
	sprite3->runAction(scaleTo);

	

	this->addChild(sprite3, 0);
	//--------------------------------------------------   
	
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
