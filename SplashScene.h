#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__

#include "cocos2d.h"

class SplashScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void goToMainMenuScene(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(SplashScene);
};

#endif // __SPLASH_SCENE_H__
