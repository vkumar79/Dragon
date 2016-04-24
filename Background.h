#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"

class Background
{
public:
    Background(cocos2d::Layer *layer);
    
    void move( );
    
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    cocos2d::Sprite *backgroundSprite1;
    cocos2d::Sprite *backgroundSprite2;
    
    cocos2d::Sprite *biggroundSprite1;
    cocos2d::Sprite *biggroundSprite2;
    
};

#endif // __BACKGROUND_H__