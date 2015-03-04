//
//  JsonScene.h
//  Json
//
//  Created by MAEDAHAJIME on 2015/03/04.
//
//

#ifndef __Json__JsonScene__
#define __Json__JsonScene__

#include "cocos2d.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class JsonScene : public cocos2d::Layer
{
protected:
    JsonScene();
    virtual ~JsonScene();
    //初期化のメソッド
    bool init() override;
    
public:
    static cocos2d::Scene* createScene();
    
    // create()を使えるようにしている。
    CREATE_FUNC(JsonScene);
    
};

#endif /* defined(__Json__JsonScene__) */
