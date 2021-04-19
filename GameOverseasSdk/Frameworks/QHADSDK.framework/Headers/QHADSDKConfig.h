//
//  QHADSDKConfig.h
//  IOS_SDK
//
//  Created by wangfei-sal on 15/12/4.
//  Copyright © 2015年 360.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface QHADSDKConfig : NSObject

+(QHADSDKConfig*)shareInstance;

//媒体分发渠道(没有,可以不设置)
/*
 规则：
 a、只能输入英文字符/数字/下划线
 b、长度小于等于32
 c、不可是纯数字
 */
@property(nonatomic,copy) NSString* appchannel;//(可选设置)

//上线前请设置NO
@property(nonatomic,assign) BOOL isTest;

//YES,表示强制使用了HTTPS协议进行传输,SDK内部会过滤所以HTTP的链接.广告填充数量可能会收到影响.
//广告点击链接全部会转成外开的方式.
//第三方广告SDK的广告展示,点击可能会失败.
//默认值:NO.
@property(nonatomic,assign) BOOL isATS;

//海外发行的版本，请设置YES
@property(nonatomic, assign) BOOL isForeign;

//设置是否在应用内打开GPS,YES在应用内打开，NO关闭.(默认GPS是打开状态),在设置appkey之前调用
@property(nonatomic,assign) BOOL enableLocation;

//打印SDK内部的错误log.默认关闭.
@property(nonatomic,assign) BOOL enableDebug;

@property (copy, nonatomic) UIColor *barColor;//LandingPage页 UINavigationBar.barTintColor
@property (copy, nonatomic) UIColor *tintColor;//LandingPage页 UINavigationBar.tintColor
@end

@interface QHADUtility : NSObject

+(void) downloadAsset:(NSString*) url completed:(void (^)(NSString*fileUrl)) completion;
@end
