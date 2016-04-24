#include "Bird.h"
#include "Definitions.h"
#include "MyBodyParser.h"

USING_NS_CC;

Bird::Bird( cocos2d::Layer *layer )
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
    
    //Code for animation --> start
    SpriteBatchNode* spritebatch = SpriteBatchNode::create("dragon.png");
    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("dragon.plist");
    
    flappyBird = Sprite::createWithSpriteFrameName("frame-1.png");
    flappyBird->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    spritebatch->addChild(flappyBird);
    layer->addChild(spritebatch);
    
    Vector<SpriteFrame*> animFrames(4);
    
    char str[100] = {0};
    for(int i = 1; i < 5; i++)
    {
        sprintf(str, "frame-%d.png", i);
        SpriteFrame* frame = cache->getSpriteFrameByName( str );
        animFrames.pushBack(frame);
    }
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    flappyBird->runAction( RepeatForever::create( Animate::create(animation) ) );
    //Code for animation --> end
    
    
    MyBodyParser::getInstance()->parseJsonFile( "dragon.json" );
    
    auto flappyBody = MyBodyParser::getInstance()->bodyFormJson(flappyBird, "DragonPoly", PhysicsMaterial( 1, 1, 0 ) );
    
    /*if ( flappyBody != nullptr )
    {
        flappyBody->setDynamic( true );
        
    }*/
    flappyBody->setDynamic( true );
    //flappyBird->setPhysicsBody( flappyBody );
    //flappyBird = Sprite::create( "Ball.png" );
    //flappyBird->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    //auto flappyBody = PhysicsBody::createBox( flappyBird->getContentSize( ), PhysicsMaterial( 0, 1, 0 ) );
    flappyBody->setCollisionBitmask( BIRD_COLLISION_BITMASK );
    flappyBody->setContactTestBitmask( true );
    
    flappyBird->setPhysicsBody( flappyBody );
    
    //layer->addChild( flappyBird, 100 );
    
    isFalling = true;
}

void Bird::Fall( )
{
    if ( true == isFalling )
    {
        flappyBird->setPositionX( visibleSize.width / 2 + origin.x );
        flappyBird->setPositionY( flappyBird->getPositionY() - ( BIRD_FALLING_SPEED * visibleSize.height ) );
    }
    else
    {
        flappyBird->setPositionX( visibleSize.width / 2 + origin.x );
        flappyBird->setPositionY( flappyBird->getPositionY() + ( BIRD_FALLING_SPEED * visibleSize.height ) );
    }
}