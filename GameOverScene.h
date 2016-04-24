#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"

class GameOverScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(unsigned int tempScore);

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOverScene);
    
private:
    void GoToMainMenuScene( cocos2d::Ref *sender );
    void GoToGameScene( cocos2d::Ref *sender );
};

#endif // __GAMEOVER_SCENE_H__
