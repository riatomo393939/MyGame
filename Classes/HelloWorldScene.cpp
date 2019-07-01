/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	//電源ボタン
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);

		//// テクスチャファイル名を指定して、
		////スプライトを作成
		//Sprite* sprite = Sprite::create("a-.png"); 
		//// シーングラフにつなぐ
		//this->addChild(sprite); 
	}

	//// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("HelloWorld.png");
	//if (sprite == nullptr)
	//{
	//    problemLoading("'HelloWorld.png'");
	//}
	//else
	//{
	//    // position the sprite on the center of the screen
	//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//    // add the sprite as a child to this layer
	//    this->addChild(sprite, 0);
	//}
	

#if(スプライト系省略)
	//テクスチャファイル名を指定して、スプライトを作成
	//sprite2 = Sprite::create("sample05.png");

	//シーングラフに繋ぐ
	//this->addChild(sprite2);


	////透明度
	////sprite->setOpacity(128);
	//////表示座標を指定
	//sprite2->setPosition(Vec2(visibleSize.width / 3.0f, visibleSize.height / 3.0f));

	//////拡縮を指定（横3倍、縦4倍）
	////sprite->setScale(3.0f,3.0f);
	////画像の基準点を設定:基盤は左下（アンカーポイント）(0,0)⇒左下/(1.1)⇒右上
	//sprite->setAnchorPoint(Vec2(0, 1.0f));

	////画像の切り取り(座標X、座標Y、切り取りWidth、切り取りHeight
	////ペイントツールの下に表示されているようなのにすればよい)
	//sprite->setTextureRect(Rect(0, 0, 32, 32));

	////アンチエイリアス(ぼやけカット)
	//sprite->getTexture()->setAliasTexParameters();
#endif

	//updateが呼び出しされるように
	this->scheduleUpdate();

#if(アクションの作成)
	//アクションの作成（1秒かけて　右に200、上に100動く）
	//MoveTo* action1 = MoveTo::create(1.0f, Vec2(200, 100));
	//ScaleBy* action1 = ScaleBy::create(1.0f,5.0f);
	//JumpTo* action1 = JumpTo::create(1.0f, Vec2(200, 100),100,1);//最後はジャンプ回数（timeではない）
	//ccBezierConfig conf;
	//conf.controlPoint_1 = Vec2(800, 700);
	//conf.controlPoint_2 = Vec2(1000, 700);
	//conf.endPosition = Vec2(1000, 360);
	//BezierTo* action1 = BezierTo::create(2.0f,conf);
	//FadeIn* action1 = FadeIn::create(1.0f);//	初期状態が100だと機能しない
    //FadeOut* action1 = FadeOut::create(1.0f);
	//RotateBy* action1 = RotateBy::create(10, 10);
	//Blink* action1 = Blink::create(100, 100);-点滅
	//SkewTo* action1 = SkewTo::create(10,10,20);-歪み

	////アクションの作成（1秒かけて　右に200、上に100動く）
	//MoveTo* action1 = MoveTo::create(1.0f, Vec2(200, 100));
	////MoveTo* action2 = MoveTo::create(1.0f, Vec2(-200, 100));

	////ノードに対してアクションを実行する
	//sprite->runAction(action1);
	//sprite2->runAction(action1->clone());//cloneしないと2個目は動かない

	//ALT+↑で行を上に挿入できる
	//EaseBackIn* action2 = EaseBackIn::create(action1);	
	//EaseElasticIn*action2 = EaseElasticIn::create(action1);
	//EaseIn* action2 = EaseIn::create(action1, 2.0f);

#endif

#if(アクションの作成2)

	//アクション1の作成
	MoveBy* action1 = MoveBy::create(0.5f, Vec2(300.0f, 150.0f));
	//アクション2の作成
	JumpTo* action2 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);
	//消す　
	//Hide* destroy = Hide::create();

	//連続アクションの作成
	//Sequence* action3 = Sequence::create(action1, action2, nullptr);
	//同時アクションの作成
	//Spawn* action3 = Spawn::create(action1, action2, nullptr);
	//永遠に繰り返すアクション->RepeatForever
	//解放アクションの作成
	//RemoveSelf* remove = RemoveSelf::create();
	//繰り返しアクションの作成
	Repeat*action3 = Repeat::create(action1, 2);

	//連続アクションの実行
	sprite->runAction(action3);
	//スプライトの解放
	//sprite->removeFromParent();
#endif

#if(コメントアウト部分)

	//反転
	//sprite->setFlippedX(true);

	////RGB
	//sprite->setColor(Color3B(255, 0, 0));赤
	//sprite->setColor(Color3B(0, 0, 255));青
	////回転角を指定(アンカーを中心に回転)
	//sprite->setRotation(45.0f);
	//左右反転
	//sprite->setFlippedX(true);
	////上下反転
	//sprite->setFlippedY(true);
	////非表示にする
	//sprite->setVisible(false);
	////色合いを設定
	//sprite->setColor(Color3B(0xff, 0x00, 0x00));
	////不透明度を設定
	//sprite->setOpacity(0x80);

	////練習問題１　
	//sprite->setPosition(Vec2(1280-100,720-100));

	////練習問題２
	//sprite->setOpacity(255);
	//counter = 0;
	////練習問題３
	//state = 0;

	////やってみよう１
	//rot = 0;
	////やってみよう２
	//blue = 0;
	////やってみよう３
	//opacity = 0;

#endif

#if(やってみよう-Action)
	////やってみよう１
	//JumpBy*action1 = JumpBy::create(1.0f, Vec2(200, 0), 100, 1);
	//sprite->runAction(action1);
	//JumpBy*action2 = JumpBy::create(1.0f, Vec2(200, 0), 100, 1);
	//sprite2->runAction(action1.clone());//クローンで実行する

	//やってみよう２
	//乱数の初期化
	//srand(time(nullptr));//nllptr=nullの代わり
	//for(int i=0;i<5;i++)
	//{
	//	sprite[i] = Sprite::create("HelloWorld.png");
	//	this->addChild(sprite[i]);
	//	sprite[i]->setPosition(Vec2(200*i, visibleSize.height / 2.0f));

	//	//乱数
	//	float mx, my;
	//	mx = (float)rand()/RAND_MAX*500;//0-500までの乱数←*をvisiblesize.widthなどにすると画面からはみ出ない
	//	my = (float)rand()/RAND_MAX*500-250;//マイナスも入っている

	//	MoveTo* action1 = MoveTo::create(1.0f, Vec2(mx, my));
	//	sprite[i]->runAction(action1);
	//}
#endif

#if(やってみよう-Action2)
	Sprite* sprite = Sprite::create("HelloWorld.png");
	this->addChild(sprite);
	sprite->setScale(0.4f, 0.4f);
	sprite->setPosition(1150,650);//右上に表示

	//やってみよう1
	MoveTo* l_moveTo = MoveTo::create(5.0f,Vec2(100, 650));
	MoveTo* r_moveTo = MoveTo::create(5.0f, Vec2(1150, 100));
	Sequence* Seq = Sequence::create(l_moveTo, r_moveTo, nullptr);

	//やってみよう2
	FadeOut* fadeout = FadeOut::create(5.0f);
	FadeIn* fadein = FadeIn::create(5.0f);
	Sequence* Seq2 = Sequence::create(fadeout, fadein, nullptr);
	Spawn* spa = Spawn::create(Seq, Seq2, nullptr);

	//やってみよう3
	Repeat* rep = Repeat::create(spa,5);
	
	//やってみよう4
	MoveTo* u_moveTo = MoveTo::create(5.0f, Vec2(1150, 650));
	MoveTo* b_moveTo = MoveTo::create(5.0f, Vec2(100, 100));
	Sequence* Seq4 = Sequence::create(l_moveTo, b_moveTo,r_moveTo, u_moveTo,nullptr);

	//やってみよう5
	RepeatForever* RF = RepeatForever::create(Seq4);

	sprite->runAction(RF);
#endif

	//init内-----------------------------------------------


	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
#if(update)
	////やってみよう１
	//rot += 1.0f;
	//sprite->setRotation(rot);

	////やってみよう２
	////255を180分割した量を足す(60*3(3秒))
	//blue += 255.0f / 180.0f;

	//if (blue > 255.0f)//最大値設定
	//	blue = 255.0f;

	//sprite->setColor(Color3B(255 - blue, 0, blue));

	////やってみよう３
	//opacity += 1.0f;
	//if (opacity > 255.0f)
	//	opacity = 255.0f;
	////フェード
	//sprite->setOpacity(255 - opacity);
	//sprite2->setOpacity(opacity);

	//やってみよう４
	//Vec2 pos;
	//switch (state)
	//{
	//case 0://左移動
	//	sprite->setFlippedX(false);
	//	//現在の座標取得
	//	pos = sprite->getPosition();
	//	//座標をずらす
	//	pos += Vec2(-5.0f, 0.0f);
	//	//座標を反映
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100)//移動量（?）
	//	{
	//		state = 1;//右移動に切り替え
	//	}
	//	break;
	//case 1://右移動
	//	sprite->setFlippedX(true);
	////現在の座標取得
	//	pos = sprite->getPosition();
	//	//座標をずらす
	//	pos += Vec2(5.0f, 0.0f);
	//	//座標を反映
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100)//移動量（?）
	//	{
	//		state = 2;//左移動に切り替え
	//	}
	//	break;
#endif


}


#if(sprite系)

	////スプライトの現在座標を取得
	//Vec2 pos = sprite->getPosition();
	////座標を移動させる
	////pos += Vec2(1.0f, 1.0f);

	////練習問題１
	//pos += Vec2(-0.5f, 0.0f);

	////移動後の座標を反映
	//sprite->setPosition(pos);

	////練習問題２
	//counter++;
	//float opacity = counter / 300.0f*255.0f;
	//opacity = 255 - opacity;
	//if (opacity < 0)
	//	opacity = 0;

	//sprite->setOpacity(opacity);

	//練習問題３
	//Vec2 pos;
	//switch (state)
	//{
	//case 0://左移動
	//	//現在の座標取得
	//	pos = sprite->getPosition();
	//	//座標をずらす
	//	pos += Vec2(-5.0f, 0.0f);
	//	//座標を反映
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100)//移動量（?）
	//	{
	//		state = 1;//下移動に切り替え
	//	}
	//	break;
	//case 1:// 下移動
	//// 現在の座標を取得
	//	pos = sprite->getPosition();
	//	// 座標をずらす
	//	pos += Vec2(0.0f, -5.0f);
	//	// 座標を反映
	//	sprite->setPosition(pos);
	//	if (pos.y <= 100)
	//	{
	//		state = 2; // 下移動に切り替え
	//	}
	//	break;
	//case 2://右移動
	////現在の座標取得
	//	pos = sprite->getPosition();
	//	//座標をずらす
	//	pos += Vec2(5.0f, 0.0f);
	//	//座標を反映
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100)
	//	{
	//		state = 3;//上移動に切り替え
	//	}
	//	break;
	//case 3:// 上移動
	//// 現在の座標を取得
	//	pos = sprite->getPosition();
	//	// 座標をずらす
	//	pos += Vec2(0.0f, 5.0f);
	//	// 座標を反映
	//	sprite->setPosition(pos);
	//	if (pos.y <= 100)
	//	{
	//		state = 0; 
	//	}
	//	break;
	//default:
	//	break;
	//}
}

#endif

