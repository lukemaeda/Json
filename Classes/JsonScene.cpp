//
//  JsonScene.cpp
//  Json
//
//  Created by MAEDAHAJIME on 2015/03/04.
//
//

#include "JsonScene.h"
// Jsonをインクルード
#include "spine/Json.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

using namespace std; // String*

JsonScene::JsonScene()
{
    
}

JsonScene::~JsonScene()
{
    
}

Scene* JsonScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = JsonScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}

// 「INIT」初期化
bool JsonScene::init()
{
    if ( !Layer::init() )
    {
        
        return false;
    }
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー（ブルー）
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    this->addChild(background);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    // string型 文字（名前）
    auto label = Label::createWithSystemFont("JSON", "arial", 100);
    // ラベルの色:ホワイト
    label->setColor(Color3B::WHITE);
    label->setPosition(Point(winSize.width/2, winSize.height/1.1));
    // Layerにラベルを追加
    this->addChild(label);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    //JSONの内容(\はエスケープ):
    //{"key1":1, "key2":123.45, "key3":"string", "key4":{"value1":100, "value2":"a"}}
    Json* json = Json_create("{\"key1\":1, \"key2\":123.45, \"key3\":\"string\", \"key4\":{\"value1\":100, \"value2\":\"a\"}}");
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // int型のパース “key1″の値、1を取り出す
    //0は、"key1"が存在しなかった場合に代入される値。
    int _int = Json_getInt(json, "key1", 0);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // float型のパース “key2″の値、123.45を取り出す
    //0は、"key2"が存在しなかった場合に代入される値。
    float _float = Json_getFloat(json, "key2", 0);
    
    // string型のパース
    //""（空）は、"key3"が存在しなかった場合に代入される値。
    std::string _string = Json_getString(json, "key3", "");
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // オブジェクト型のパース “key4″の値を取り出す
    // "key4"の中身を取り出す
    Json* j = Json_getItem(json, "key4");
    
    // "key4"の"value1"のパース
    int ji = Json_getInt(j, "value1", 0); //jiの値は100
    
    //"key4"の"value2"のパース
    std::string js = Json_getString(j, "value2", ""); //jsの値はa
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // 要素数を数える JSONの中にいくつ要素があるか調べます。
    int num = json->size;
    log("全部で%d個です", num);  //全部で4個です
    
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // key1 int型ラベル
    auto label1 = Label::createWithSystemFont("key1 int型", "arial", 70);
    // ラベルの色:ホワイト
    label1->setColor(Color3B::WHITE);
    label1->setPosition(Point(winSize.width/2 - 300, winSize.height/1.3));
    // Layerにラベルを追加
    this->addChild(label1);
    
    // key1 int型 ラベルを作成し、初期化する。
    auto label01 = Label::createWithSystemFont(StringUtils::toString(_int),"arial", 70);
    // ラベルの色:ホワイト
    label01->setColor(Color3B::WHITE);
    label01->setPosition(Point(winSize.width/2 + 200, winSize.height/1.3));
    // Layerにラベルを追加
    this->addChild(label01);
    
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // key2 float型ラベル
    auto label2 = Label::createWithSystemFont("key2 float型", "arial", 70);
    // ラベルの色:ホワイト
    label2->setColor(Color3B::WHITE);
    label2->setPosition(Point(winSize.width/2 - 300, winSize.height/1.5));
    // Layerにラベルを追加
    this->addChild(label2);
    
    
    // key2 float型 ラベルを作成し、初期化する。
    auto label02 = Label::createWithSystemFont(StringUtils::toString(_float),"arial", 70);
    // ラベルの色:ホワイト
    label02->setColor(Color3B::WHITE);
    label02->setPosition(Point(winSize.width/2 + 200, winSize.height/1.5));
    // Layerにラベルを追加
    this->addChild(label02);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // key3 string型ラベル
    auto label3 = Label::createWithSystemFont("key3 string型", "arial", 70);
    // ラベルの色:ホワイト
    label3->setColor(Color3B::WHITE);
    label3->setPosition(Point(winSize.width/2 - 300, winSize.height/1.8));
    // Layerにラベルを追加
    this->addChild(label3);
    
    
    // key3 string型 ラベルを作成し、初期化する。
    auto label03 = Label::createWithSystemFont(_string, "arial", 70);
    // ラベルの色:ホワイト
    label03->setColor(Color3B::WHITE);
    label03->setPosition(Vec2(winSize.width/2 + 200, winSize.height/1.8));
    // Layerにラベルを追加
    this->addChild(label03);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // key4 value1 ラベル
    auto label4 = Label::createWithSystemFont("key4 value1", "arial", 70);
    // ラベルの色:ホワイト
    label4->setColor(Color3B::WHITE);
    label4->setPosition(Point(winSize.width/2 - 300, winSize.height/2.3));
    // Layerにラベルを追加
    this->addChild(label4);
    
    
    // key4 オブジェクト型 "value1"のパース ラベルを作成し、初期化する。
    auto label04 = Label::createWithSystemFont(StringUtils::toString(ji),"arial", 70);
    // ラベルの色:ホワイト
    label04->setColor(Color3B::WHITE);
    label04->setPosition(Vec2(winSize.width/2 + 200, winSize.height/2.3));
    // Layerにラベルを追加
    this->addChild(label04);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // key4 value2 ラベル
    auto label5 = Label::createWithSystemFont("key4 value2", "arial", 70);
    // ラベルの色:ホワイト
    label5->setColor(Color3B::WHITE);
    label5->setPosition(Point(winSize.width/2 - 300, winSize.height/3.0));
    // Layerにラベルを追加
    this->addChild(label5);
    
    
    // key4 オブジェクト型 "value2"のパース ラベルを作成し、初期化する。
    auto label05 = Label::createWithSystemFont(js, "arial", 70);
    // ラベルの色:ホワイト
    label05->setColor(Color3B::WHITE);
    label05->setPosition(Vec2(winSize.width/2 + 200, winSize.height/3.0));
    // Layerにラベルを追加
    this->addChild(label05);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // 要素数 ラベル
    auto label6 = Label::createWithSystemFont("JSONの中の要素数", "arial", 70);
    // ラベルの色:ホワイト
    label6->setColor(Color3B::WHITE);
    label6->setPosition(Point(winSize.width/2 - 300, winSize.height/4.5));
    // Layerにラベルを追加
    this->addChild(label6);
    
    
    // 要素数 ラベルを作成し、初期化する。
    auto label06 = Label::createWithSystemFont(StringUtils::toString(num),"arial", 70);
    // ラベルの色:ホワイト
    label06->setColor(Color3B::WHITE);
    label06->setPosition(Vec2(winSize.width/2 + 200, winSize.height/4.5));
    // Layerにラベルを追加
    this->addChild(label06);
    
    return true;
}
