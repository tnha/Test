#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "bestScene.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
//Khai báo tạo thêm vùng nhớ
Sprite *ovuong;
//-----------------------------
//Khởi tạo màn hình
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
//-----------------------------------------------
// Hàm init sẽ là hàm bao gồm các hàm hiển thị trên màn hình
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
	//-------Tạo background
	auto background = Sprite::create("background.jpg");
	background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	background->setScale(2);
	addChild(background);


    //-----------------------
	auto loadingbk = Sprite::create("ldb1.jpg");
	loadingbk->setPosition(Vec2(visibleSize.width / 2, 30));
	addChild(loadingbk);

	//--------------------------------
	auto loadingbar = ui::LoadingBar::create("ldb2.jpg");
	loadingbar->setPosition(Vec2(visibleSize.width/2, 30));
	loadingbar->setDirection(ui::LoadingBar::Direction::LEFT);
	loadingbar->setPercent(0);
	addChild(loadingbar);
	this->schedule([=](float delta){
		float percent = loadingbar->getPercent();
		percent++;
		loadingbar->setPercent(percent);
		if (percent >= 100.0f);
		{
			this->unschedule("updateLoadingBar");
		}



	}, 0.1f, "updateLoadingbar");
    // 2. Tạo hàm nút tắt ứng dụng

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	//---------------------------------------------------
	//-----------------------button chuyển scene
	

	auto button = ui::Button::create("muitenphai.png");
	button->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2 + 100));
	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType Type){
		switch (Type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			
			break;
		case ui::Widget::TouchEventType::ENDED:
			auto bestScene = bestScene::createScene();
			Director::getInstance()->replaceScene(TransitionSlideInR::create(1, bestScene));
			break;
		}
});
	addChild(button, 1);

	//---------------------------------checkbox
		auto checkbox = ui::CheckBox::create("cb2.png", "cb1.jpg");
		checkbox->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
					origin.y + closeItem->getContentSize().height / 2 + 200));
		checkbox->addEventListener([&](Ref *sender, ui::CheckBox::EventType type){
			switch (type)
			{
			case ui::CheckBox::EventType::SELECTED:
				break;
			case ui::CheckBox::EventType::UNSELECTED:
				break;


			default:
				break;
			}

	});

		addChild(checkbox, 1);


    // 3. Thêm label hiển thị trên màn hình
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);

	//Tạo 1 Sprite
    auto sprite = Sprite::create("vuong1.jpg");
    sprite->setPosition(Vec2(50, 50));
	sprite->setScale(0.5);

    // Chuyển động
    this->addChild(sprite, 0);
	auto actionMoveTo = MoveTo::create(3, Vec2(300, 300));
	auto actionRotate = RotateBy::create(3, 360);

	auto sequence = Sequence::create(actionMoveTo, actionRotate, nullptr);
	auto spawn = Spawn::create(actionMoveTo, actionRotate, nullptr);
	auto repeat = RepeatForever::create(spawn);
	sprite->runAction(repeat);

	ovuong = Sprite::create("vuong2.jpg");
	ovuong->setScale(0.3f);
	ovuong->setPosition(Vec2(0, 0));
	addChild(ovuong);

	//--------------------------------------------
	//-----khởi tạo hàm sự kiện
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::OnTouchBegan, this);
	//touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::OnTouchMoved, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    return true;
}
//------Gọi các hàm để truyền các hành động và hiển thị
bool HelloWorld::OnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
		Vec2 touchLocation = touch->getLocation();
		auto  actionMoveTo = MoveTo::create(2, touchLocation);
		ovuong->stopActionByTag(99);
		actionMoveTo->setTag(99);
		ovuong->runAction(actionMoveTo);
		return true;
}
//void HelloWorld::OnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event){
//	Vec2 touchLocation = touch->getLocation();
//	auto actionMoveTo1 = MoveTo::create(0, touchLocation);
//	ovuong->runAction(actionMoveTo1);

//}


/*void HelloWorld::gotobestScene(float dt)
{
	auto menuscene = bestScene::createScene();
	Director::getInstance()->replaceScene(menuscene);
}*/
//---Gọi hàm tắt ứng dụng
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
