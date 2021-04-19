//
//  QHSStatAgent.h
//  QHSAnalyticsSdk
//
//  Created by sunyimin on 16/5/23.
//  Copyright © 2016年 北京奇虎科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QHSConfiguration.h"
#import "QHSCustomEvent.h"
#import "QHSLive.h"

@interface QHSStatAgent : NSObject

///---------------------------------------------------------------------------------------
/// @name  设置
///---------------------------------------------------------------------------------------

/**
 *  设置是否打印sdk的log信息
 *
 *  @param isEnabled BOOL类型 默认 NO 设置为YES,SDK 会输出log信息,记得release产品时要设置回NO.
 */
- (void)setLogEnabled:(BOOL)isEnabled;


/**
 *  设置打印数据监控信息
 *
 *  @param debug BOOL类型 默认 NO
 */
- (void)setDebugMode:(BOOL)debug;


/**
*  设置启用广告监测功能开关
*
*  @param isReproted BOOL类型 默认 NO
*/
- (void)setReportADDataEnabled:(BOOL)isReproted;


///---------------------------------------------------------------------------------------
/// @name  开启统计
///---------------------------------------------------------------------------------------

/**
 *  开启sdk统计，默认以下次启动方式发送log
 *
 *  @param appKey    在QDAS上注册app的key
 *  @param policy    发送策略
 *  @param channelId 渠道名称,为nil或@""时,默认会被被当作@"App Store"渠道
 */
+(nonnull QHSStatAgent *)startWithappKey:(nonnull NSString *)appKey reportPolicy:(QHSReportPolicy)policy channelId:(nullable NSString *)channelId;


/**
 *  获取m2值，只生成一次uuid存入keychain中，下次直接从keychain中获取。
 *
 *  @return  返回keychain中读取的uuid
 */
- (nullable NSString *)getM2;


/**
 * 手动设置app当前版本信息
 *
 *  @param appVersion app当前版本信息
 */
- (void)setappVersion:(nonnull NSString *)appVersion;


/**
 *  为了更精确的统计用户地理位置，可以调用此方法传入经纬度信息
 需要链接 CoreLocation.framework 并且 #import <CoreLocation/CoreLocation.h>
 *
 *  @param latitude  纬度
 *  @param longitude 经度
 */
- (void)setLocationWithLatitude:(double)latitude longitude:(double)longitude;


/**
 *  设置用户id
 *
 *  @param userId 字符串类型
 */
- (void)setUserId:(nullable NSString *)userId;


/**
 *  设置tag值
 *
 *  @param tag 字符串类型
 */
- (void)setTag:(nullable NSString *)tag;


/**
 *  设置多个tag值在header.ext里存放
 *
 *  @param tagValue  tag值  如果传空值则将把之前的赋值删除
 *  @param tagIndex  tag的key
 */
- (void)setExtraTag:(nullable NSString *)tagValue index:(QHSExtraTagIndex)tagIndex;

/**
 *  设置发送策略
 *
 *  @param reportPolicy 发送策略
 */
- (void)setReportPolicy:(QHSReportPolicy)reportPolicy;


/**
 *  设置上报当前用户位置信息
 *
 *  @param isEnabled BOOL类型 默认 NO
 */
- (void)setLocationReportEnabled:(BOOL)isEnabled;


/**
 *  设置自动定位位置信息
 *
 *  @param isEnabled BOOL类型 默认 NO
 */
- (void)setAutoLocationEnabled:(BOOL)isEnabled;


/**
 *  设置使用测试版本的云控（使用时注意）
 *
 *  @param isBeta BOOL类型 默认 NO 记得release产品时要设置回NO.
 */
- (void)setOnlineConfigBeBetaVersion:(BOOL)isBeta;


/**
 *  设置A/B Test：本次test设置名字，然后通过设置不同tag值。
 *
 *  @param name 标示
 *  @param tag  类型
 */
- (void)setABTestName:(nonnull NSString *)name andValue:(QHSAbTestTag)tag;

/**
 *  设置域名，包括前缀部分，比如“https://abc.com”
 *
 *  @param report 上报数据的域名
 *  @param config 请求云控数据的域名
 */
- (void)setDomainForReporting:(nullable NSString *)report onlineConfig:(nullable NSString *)config;

///---------------------------------------------------------------------------------------
/// @name  自定义事件统计
///---------------------------------------------------------------------------------------


/**
 *  使用前，请先到QDAS管理后台的设置->编辑自定义事件 中添加相应的事件ID，然后在工程中传入相应的事件ID
 *  @param event 自定义事件实例
 */
- (void)onEvent:(nonnull QHSCustomEvent *)event;


/**
 *  数据优先级为L5，采样类型是A的计数事件发生一次
 *  使用前，请先到QDAS管理后台的设置->编辑自定义事件 中添加相应的事件ID，然后在工程中传入相应的事件ID
 *  @param eventId 事件ID
 */
- (void)onTimeEvent:(nonnull NSString *)eventId;


/**
 * 远程推送事件
 * @param pushId 远程推送信息的标识
 * @param type 推送事件类型
 * @param label 分类标签。不同的标签会分别进行统计，方便同一事件的不同标签的对比,为nil或空字符串时后台会生成和pushId同名的标签.
 */
- (void)onPushEvent:(nonnull NSString *)pushId type:(QHSPushType)type label:(nullable NSString *)label;


/**在登录成功后调用
 *  使用sign-In函数后，如果结束该UID的统计，需要调用sign-Off函数
 *
 *  @param userId : 用户登录ID
 *  @param provider  : 不能以下划线"_"开头，使用大写字母和数字标识; 如果是上市公司，建议使用股票代码。
 */
- (void)profileSignInWithUID:(nonnull NSString *)userId provider:(nullable NSString *)provider;

- (void)profileSignInWithUID:(nonnull NSString *)userId;


/** 在注销成功后调用
 *
 */
- (void)profileSignOff;


/**
 在注册成功后调用

 @param accountId 注册的账号唯一标识.可能是useriId,email等
 @param provider 注册的账号来源.可能是微信,微博等
 @param props 其它扩展属性
 */
- (void)onRegister:(nonnull NSString *)accountId andAccountProvider:(nullable NSString *)provider andProps:(nullable NSDictionary *)props;

- (void)onRegister:(nonnull NSString *)accountId andProps:(nullable NSDictionary *)props;


/**
 在支付完成后调用

 @param item 商品名称或编号
 @param amount 支付金额
 @param props 其它扩展属性
 */
- (void)onPay:(nullable NSString *)item andAmount:(double)amount AndProps:(nullable NSDictionary *)props;



/**
 成功下单后调用

 @param transactionId  唯一交易流水号
 @param currenyType 货币类型  人民币 CNY 按ISO 4217标准
 @param currencyAmount 交易金额
 */
- (void)onOrder:(nonnull NSString *)transactionId andCurrenyType:(nonnull NSString *)currenyType andCurrencyAmount:(nullable NSString *)currencyAmount;


#pragma mark 视频直播和观看功能
/**
 * 视频直播
 * @param vid 视频id
 * 返回值为QHSLiveEvent实例化对象
 */
- (nonnull QHSLiveEvent *)liveEventWithId:(nonnull NSString *)vid type:(QHSType)type;

/**
* @param event QHSLiveEvent对象
* @param dataLevel 数据优先级
*/
- (void)onLiveEvent:(nonnull QHSLiveEvent *)event dataLevel:(QHSDataLevel)dataLevel;
- (void)onLiveEvent:(nonnull QHSLiveEvent *)event;


/**
 * 视频观看
 * @param vid 视频id
 * 返回值为QHSPlayEvent实例化对象
 */
- (nonnull QHSPlayEvent *)playEventWithId:(nonnull NSString *)vid type:(QHSType)type;

/**
 * @param event QHSPlayEvent对象
 * @param dataLevel 数据优先级
 */
- (void)onPlayEvent:(nonnull QHSPlayEvent *)event dataLevel:(QHSDataLevel)dataLevel;

- (void)onPlayEvent:(nonnull QHSPlayEvent *)event;


@end
