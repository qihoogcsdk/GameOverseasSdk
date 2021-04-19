//
//  QHS.h
//  QHSAnalyticsSdk
//
//  Created by sunyimin on 16/6/1.
//  Copyright © 2016年 北京奇虎科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QHSConfiguration.h"


typedef NS_ENUM(NSInteger, QHSType){
    QHSTypeStart = 1, //直播开始
    QHSTypeValid = 2, //直播有效
    QHSTypeEnd = 3    //直播结束
};

/*
 QHSStartType 和 QHSEndType 存在一一对应关系，在QHSTypeStart情况下，只存在QHSStartType值。在QHSTypeValid情况下，都不存在。在QHSTypeEnd情况下，都存在。
 eg：
 liveType为：
 QHSTypeStart：
 需要调用setLiveValue       可以调用setLiveNumValue
 QHSTypeValid：
 无需调用
 QHSTypeEnd：
 需要调用setLiveValue       可以调用setLiveNumValue
 */

typedef NS_ENUM(int,QHSValueKey){
    QHSValueKeyOne = 1,
    QHSValueKeyTwo = 2,
    QHSValueKeyThree = 3,
    QHSValueKeyFour = 4,
    QHSValueKeyFive = 5,
    QHSValueKeySix = 6,
    QHSValueKeySeven = 7,
    QHSValueKeyEight = 8,
    QHSValueKeyNine = 9,
    QHSValueKeyTen = 10
};


@interface QHSLive : NSObject
@property(nonatomic,assign) QHSType type; //观看类型
@property(nullable,nonatomic,strong)  NSMutableDictionary *attr1; //拓展1
@property(nullable,nonatomic,strong)  NSMutableDictionary *attr2; //拓展2

- (void)setLiveValue:(nonnull NSString*)value withKey:(QHSValueKey )key;

- (void)setLiveNumValue:(nonnull NSString*)value withKey:(QHSValueKey )key;

@end


@interface QHSLiveEvent : QHSLive

@property(nullable,nonatomic,strong) NSDate *startTime; //开始时间
@property(nullable,nonatomic,strong) NSDate *endTime; //结束时间
@property(nonatomic,assign) unsigned long long dur; //时长
@property(nullable,nonatomic,strong) NSString *title; //主题
@property(nullable,nonatomic,strong) NSString *vid; //视频ID

- (nonnull NSMutableDictionary *)toDictionary;

@end

@interface QHSPlayEvent : QHSLive

@property(nullable,nonatomic,strong) NSDate *startTime; //开始时间
@property(nullable,nonatomic,strong) NSDate *endTime; //结束时间
@property(nonatomic,assign) BOOL replay; //NO为非回放；YES为观看回放
@property(nonatomic,assign) unsigned long long dur; //时长
@property(nonatomic,assign) BOOL completion; //是否完整播放
@property(nullable,nonatomic,strong) NSString *vid; //视频ID
@property(nullable,nonatomic,strong) NSString *ownerId; //主播ID
@property(nonatomic,assign) BOOL isFollower; //是否关注 默认NO

- (nonnull NSMutableDictionary *)toDictionary;

@end
