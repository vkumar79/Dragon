#include "Background.h"
#include "Definitions.h"

USING_NS_CC;

Background::Background( cocos2d::Layer *layer )
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    backgroundSprite1 = Sprite::create( "Background.png" );
    backgroundSprite1->setPosition( Point( visibleSize.width / 2  + origin.x, visibleSize.height / 2 + origin.y ) );
    
    backgroundSprite2 = Sprite::create( "Background.png" );
    backgroundSprite2->setPosition( Point( visibleSize.width / 2+origin.x+backgroundSprite1->getTextureRect().size.width, visibleSize.height / 2 + origin.y ) );
    //CCLOG( "BACGROUND1 X %f",visibleSize.width / 2+origin.x );
    //CCLOG( "BACGROUND2 X %f",visibleSize.width / 2+origin.x+backgroundSprite1->getTextureRect().size.width );
    layer->addChild(backgroundSprite1);
    layer->addChild(backgroundSprite2);
    
    biggroundSprite1 = Sprite::create( "bigground.png" );
    biggroundSprite1->setPosition( Point( visibleSize.width / 2  + origin.x, origin.y ) );
    
    biggroundSprite2 = Sprite::create( "bigground.png" );
    biggroundSprite2->setPosition( Point( visibleSize.width / 2+origin.x+biggroundSprite1->getTextureRect().size.width, origin.y ) );
    //CCLOG( "BIGGROUND1 X %f",visibleSize.width / 2+origin.x );
    //CCLOG( "BIGGROUND2 X %f",visibleSize.width / 2+origin.x+biggroundSprite1->getTextureRect().size.width );
    layer->addChild(biggroundSprite1);
    layer->addChild(biggroundSprite2);
}

void Background::move()
{
    //CCLOG( "MOVING BACKGROUND" );
    backgroundSprite1->setPositionX( backgroundSprite1->getPositionX()-(BACKGROUND_SPEED));
    backgroundSprite2->setPositionX( backgroundSprite2->getPositionX()-(BACKGROUND_SPEED));
    if(backgroundSprite1->getPositionX()<-backgroundSprite1->getTextureRect().size.width){
        backgroundSprite1->setPositionX( backgroundSprite2->getPositionX()+backgroundSprite1->getTextureRect().size.width);
    }
    if(backgroundSprite2->getPositionX()<-backgroundSprite2->getTextureRect().size.width){
        backgroundSprite2->setPositionX( backgroundSprite1->getPositionX()+backgroundSprite2->getTextureRect().size.width);
    }
    
    biggroundSprite1->setPositionX( biggroundSprite1->getPositionX()-(GROUND_SPEED));
    biggroundSprite2->setPositionX( biggroundSprite2->getPositionX()-(GROUND_SPEED));
    if(biggroundSprite1->getPositionX()<-biggroundSprite1->getTextureRect().size.width){
        biggroundSprite1->setPositionX( biggroundSprite2->getPositionX()+biggroundSprite1->getTextureRect().size.width);
    }
    if(biggroundSprite2->getPositionX()<-biggroundSprite2->getTextureRect().size.width){
        biggroundSprite2->setPositionX( biggroundSprite1->getPositionX()+biggroundSprite2->getTextureRect().size.width);
    }
}