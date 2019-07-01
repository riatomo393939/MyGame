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
	//�d���{�^��
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

		//// �e�N�X�`���t�@�C�������w�肵�āA
		////�X�v���C�g���쐬
		//Sprite* sprite = Sprite::create("a-.png"); 
		//// �V�[���O���t�ɂȂ�
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
	

#if(�X�v���C�g�n�ȗ�)
	//�e�N�X�`���t�@�C�������w�肵�āA�X�v���C�g���쐬
	//sprite2 = Sprite::create("sample05.png");

	//�V�[���O���t�Ɍq��
	//this->addChild(sprite2);


	////�����x
	////sprite->setOpacity(128);
	//////�\�����W���w��
	//sprite2->setPosition(Vec2(visibleSize.width / 3.0f, visibleSize.height / 3.0f));

	//////�g�k���w��i��3�{�A�c4�{�j
	////sprite->setScale(3.0f,3.0f);
	////�摜�̊�_��ݒ�:��Ղ͍����i�A���J�[�|�C���g�j(0,0)�ˍ���/(1.1)�ˉE��
	//sprite->setAnchorPoint(Vec2(0, 1.0f));

	////�摜�̐؂���(���WX�A���WY�A�؂���Width�A�؂���Height
	////�y�C���g�c�[���̉��ɕ\������Ă���悤�Ȃ̂ɂ���΂悢)
	//sprite->setTextureRect(Rect(0, 0, 32, 32));

	////�A���`�G�C���A�X(�ڂ₯�J�b�g)
	//sprite->getTexture()->setAliasTexParameters();
#endif

	//update���Ăяo�������悤��
	this->scheduleUpdate();

#if(�A�N�V�����̍쐬)
	//�A�N�V�����̍쐬�i1�b�����ā@�E��200�A���100�����j
	//MoveTo* action1 = MoveTo::create(1.0f, Vec2(200, 100));
	//ScaleBy* action1 = ScaleBy::create(1.0f,5.0f);
	//JumpTo* action1 = JumpTo::create(1.0f, Vec2(200, 100),100,1);//�Ō�̓W�����v�񐔁itime�ł͂Ȃ��j
	//ccBezierConfig conf;
	//conf.controlPoint_1 = Vec2(800, 700);
	//conf.controlPoint_2 = Vec2(1000, 700);
	//conf.endPosition = Vec2(1000, 360);
	//BezierTo* action1 = BezierTo::create(2.0f,conf);
	//FadeIn* action1 = FadeIn::create(1.0f);//	������Ԃ�100���Ƌ@�\���Ȃ�
    //FadeOut* action1 = FadeOut::create(1.0f);
	//RotateBy* action1 = RotateBy::create(10, 10);
	//Blink* action1 = Blink::create(100, 100);-�_��
	//SkewTo* action1 = SkewTo::create(10,10,20);-�c��

	////�A�N�V�����̍쐬�i1�b�����ā@�E��200�A���100�����j
	//MoveTo* action1 = MoveTo::create(1.0f, Vec2(200, 100));
	////MoveTo* action2 = MoveTo::create(1.0f, Vec2(-200, 100));

	////�m�[�h�ɑ΂��ăA�N�V���������s����
	//sprite->runAction(action1);
	//sprite2->runAction(action1->clone());//clone���Ȃ���2�ڂ͓����Ȃ�

	//ALT+���ōs����ɑ}���ł���
	//EaseBackIn* action2 = EaseBackIn::create(action1);	
	//EaseElasticIn*action2 = EaseElasticIn::create(action1);
	//EaseIn* action2 = EaseIn::create(action1, 2.0f);

#endif

#if(�A�N�V�����̍쐬2)

	//�A�N�V����1�̍쐬
	MoveBy* action1 = MoveBy::create(0.5f, Vec2(300.0f, 150.0f));
	//�A�N�V����2�̍쐬
	JumpTo* action2 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);
	//�����@
	//Hide* destroy = Hide::create();

	//�A���A�N�V�����̍쐬
	//Sequence* action3 = Sequence::create(action1, action2, nullptr);
	//�����A�N�V�����̍쐬
	//Spawn* action3 = Spawn::create(action1, action2, nullptr);
	//�i���ɌJ��Ԃ��A�N�V����->RepeatForever
	//����A�N�V�����̍쐬
	//RemoveSelf* remove = RemoveSelf::create();
	//�J��Ԃ��A�N�V�����̍쐬
	Repeat*action3 = Repeat::create(action1, 2);

	//�A���A�N�V�����̎��s
	sprite->runAction(action3);
	//�X�v���C�g�̉��
	//sprite->removeFromParent();
#endif

#if(�R�����g�A�E�g����)

	//���]
	//sprite->setFlippedX(true);

	////RGB
	//sprite->setColor(Color3B(255, 0, 0));��
	//sprite->setColor(Color3B(0, 0, 255));��
	////��]�p���w��(�A���J�[�𒆐S�ɉ�])
	//sprite->setRotation(45.0f);
	//���E���]
	//sprite->setFlippedX(true);
	////�㉺���]
	//sprite->setFlippedY(true);
	////��\���ɂ���
	//sprite->setVisible(false);
	////�F������ݒ�
	//sprite->setColor(Color3B(0xff, 0x00, 0x00));
	////�s�����x��ݒ�
	//sprite->setOpacity(0x80);

	////���K���P�@
	//sprite->setPosition(Vec2(1280-100,720-100));

	////���K���Q
	//sprite->setOpacity(255);
	//counter = 0;
	////���K���R
	//state = 0;

	////����Ă݂悤�P
	//rot = 0;
	////����Ă݂悤�Q
	//blue = 0;
	////����Ă݂悤�R
	//opacity = 0;

#endif

#if(����Ă݂悤-Action)
	////����Ă݂悤�P
	//JumpBy*action1 = JumpBy::create(1.0f, Vec2(200, 0), 100, 1);
	//sprite->runAction(action1);
	//JumpBy*action2 = JumpBy::create(1.0f, Vec2(200, 0), 100, 1);
	//sprite2->runAction(action1.clone());//�N���[���Ŏ��s����

	//����Ă݂悤�Q
	//�����̏�����
	//srand(time(nullptr));//nllptr=null�̑���
	//for(int i=0;i<5;i++)
	//{
	//	sprite[i] = Sprite::create("HelloWorld.png");
	//	this->addChild(sprite[i]);
	//	sprite[i]->setPosition(Vec2(200*i, visibleSize.height / 2.0f));

	//	//����
	//	float mx, my;
	//	mx = (float)rand()/RAND_MAX*500;//0-500�܂ł̗�����*��visiblesize.width�Ȃǂɂ���Ɖ�ʂ���͂ݏo�Ȃ�
	//	my = (float)rand()/RAND_MAX*500-250;//�}�C�i�X�������Ă���

	//	MoveTo* action1 = MoveTo::create(1.0f, Vec2(mx, my));
	//	sprite[i]->runAction(action1);
	//}
#endif

#if(����Ă݂悤-Action2)
	Sprite* sprite = Sprite::create("HelloWorld.png");
	this->addChild(sprite);
	sprite->setScale(0.4f, 0.4f);
	sprite->setPosition(1150,650);//�E��ɕ\��

	//����Ă݂悤1
	MoveTo* l_moveTo = MoveTo::create(5.0f,Vec2(100, 650));
	MoveTo* r_moveTo = MoveTo::create(5.0f, Vec2(1150, 100));
	Sequence* Seq = Sequence::create(l_moveTo, r_moveTo, nullptr);

	//����Ă݂悤2
	FadeOut* fadeout = FadeOut::create(5.0f);
	FadeIn* fadein = FadeIn::create(5.0f);
	Sequence* Seq2 = Sequence::create(fadeout, fadein, nullptr);
	Spawn* spa = Spawn::create(Seq, Seq2, nullptr);

	//����Ă݂悤3
	Repeat* rep = Repeat::create(spa,5);
	
	//����Ă݂悤4
	MoveTo* u_moveTo = MoveTo::create(5.0f, Vec2(1150, 650));
	MoveTo* b_moveTo = MoveTo::create(5.0f, Vec2(100, 100));
	Sequence* Seq4 = Sequence::create(l_moveTo, b_moveTo,r_moveTo, u_moveTo,nullptr);

	//����Ă݂悤5
	RepeatForever* RF = RepeatForever::create(Seq4);

	sprite->runAction(RF);
#endif

	//init��-----------------------------------------------


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
	////����Ă݂悤�P
	//rot += 1.0f;
	//sprite->setRotation(rot);

	////����Ă݂悤�Q
	////255��180���������ʂ𑫂�(60*3(3�b))
	//blue += 255.0f / 180.0f;

	//if (blue > 255.0f)//�ő�l�ݒ�
	//	blue = 255.0f;

	//sprite->setColor(Color3B(255 - blue, 0, blue));

	////����Ă݂悤�R
	//opacity += 1.0f;
	//if (opacity > 255.0f)
	//	opacity = 255.0f;
	////�t�F�[�h
	//sprite->setOpacity(255 - opacity);
	//sprite2->setOpacity(opacity);

	//����Ă݂悤�S
	//Vec2 pos;
	//switch (state)
	//{
	//case 0://���ړ�
	//	sprite->setFlippedX(false);
	//	//���݂̍��W�擾
	//	pos = sprite->getPosition();
	//	//���W�����炷
	//	pos += Vec2(-5.0f, 0.0f);
	//	//���W�𔽉f
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100)//�ړ��ʁi?�j
	//	{
	//		state = 1;//�E�ړ��ɐ؂�ւ�
	//	}
	//	break;
	//case 1://�E�ړ�
	//	sprite->setFlippedX(true);
	////���݂̍��W�擾
	//	pos = sprite->getPosition();
	//	//���W�����炷
	//	pos += Vec2(5.0f, 0.0f);
	//	//���W�𔽉f
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100)//�ړ��ʁi?�j
	//	{
	//		state = 2;//���ړ��ɐ؂�ւ�
	//	}
	//	break;
#endif


}


#if(sprite�n)

	////�X�v���C�g�̌��ݍ��W���擾
	//Vec2 pos = sprite->getPosition();
	////���W���ړ�������
	////pos += Vec2(1.0f, 1.0f);

	////���K���P
	//pos += Vec2(-0.5f, 0.0f);

	////�ړ���̍��W�𔽉f
	//sprite->setPosition(pos);

	////���K���Q
	//counter++;
	//float opacity = counter / 300.0f*255.0f;
	//opacity = 255 - opacity;
	//if (opacity < 0)
	//	opacity = 0;

	//sprite->setOpacity(opacity);

	//���K���R
	//Vec2 pos;
	//switch (state)
	//{
	//case 0://���ړ�
	//	//���݂̍��W�擾
	//	pos = sprite->getPosition();
	//	//���W�����炷
	//	pos += Vec2(-5.0f, 0.0f);
	//	//���W�𔽉f
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100)//�ړ��ʁi?�j
	//	{
	//		state = 1;//���ړ��ɐ؂�ւ�
	//	}
	//	break;
	//case 1:// ���ړ�
	//// ���݂̍��W���擾
	//	pos = sprite->getPosition();
	//	// ���W�����炷
	//	pos += Vec2(0.0f, -5.0f);
	//	// ���W�𔽉f
	//	sprite->setPosition(pos);
	//	if (pos.y <= 100)
	//	{
	//		state = 2; // ���ړ��ɐ؂�ւ�
	//	}
	//	break;
	//case 2://�E�ړ�
	////���݂̍��W�擾
	//	pos = sprite->getPosition();
	//	//���W�����炷
	//	pos += Vec2(5.0f, 0.0f);
	//	//���W�𔽉f
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100)
	//	{
	//		state = 3;//��ړ��ɐ؂�ւ�
	//	}
	//	break;
	//case 3:// ��ړ�
	//// ���݂̍��W���擾
	//	pos = sprite->getPosition();
	//	// ���W�����炷
	//	pos += Vec2(0.0f, 5.0f);
	//	// ���W�𔽉f
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

