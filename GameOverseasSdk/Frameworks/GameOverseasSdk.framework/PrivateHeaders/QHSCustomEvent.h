//
//  CustomEvent.h
//  AnalyticsSdkSource
//
//  Created by sunyimin on 16/5/23.
//  Copyright (c) 2015年 北京奇虎科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QHSConfiguration.h"
//事件类型
typedef NS_ENUM(NSUInteger, QHSCustomEventType){
    QHSCustomEventTypeNormal,//普通事件
    QHSCustomEventTypePush//推送事件
};
@interface QHSCustomEvent : NSObject
@property (nonatomic,assign) QHSCustomEventType type;//事件类型

@property (nonatomic,strong,nonnull) NSString *eventId;//事件ID
@property (nonatomic,assign) QHSCustomEventSamplingType samplingType;//事件采样类型
@property (nonatomic,assign) unsigned long long timeValue;//事件发生次数
@property (nonatomic,strong,nullable) NSString *statusValue;//事件状态值
@property (nonatomic,strong,nullable) NSString *label;//用户自定义标签
@property (nonatomic,strong,nullable) NSDictionary *customAttributes;//用户自定义属性
@property (nonatomic,assign) QHSDataLevel dataLevel;//数据优先级

@property (nonatomic,readonly) unsigned long long timestamp;//事件发生时间戳
@property (nonatomic,assign) QHSAbTestTag abTestValue;//用于做AB Test的标识
@property (nonatomic,strong,nullable) NSString *abTestName;
//=====
/**
 *创建自定义事件实例
 *@param eventId 事件ID
 */
+ (nonnull QHSCustomEvent *)eventWithId:(nonnull NSString *)eventId;
/**
 *自定义事件发生一次
 *@param event 自定义事件实例
 */
+ (void)onEvent:(nonnull QHSCustomEvent *)event andAppKey:(NSString *_Nonnull)appKey;
/**
 *数据优先级为L5的计数事件发生一次
 *@param eventId 事件ID
 */
+ (void)onTimeEvent:(nonnull NSString *)eventId andAppKey:(NSString *_Nonnull)appKey;
/**
 * 远程推送事件
 * @param pushId 远程推送信息的标识
 * @param type 推送事件类型
 * @param label 用户自定义标签
 */
+ (void)onPushEvent:(nonnull NSString *)pushId andAppKey:(nonnull NSString *)appKey type:(QHSPushType)type label:(nullable NSString *)label;
- (nonnull NSMutableDictionary *)toDictionary;
@end
