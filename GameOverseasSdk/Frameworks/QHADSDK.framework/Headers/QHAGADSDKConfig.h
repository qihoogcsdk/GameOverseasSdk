//
//  QHAGADSDKConfig.h
//  QHADSDK
//
//  Created by wangfei-sal on 17/3/22.
//  Copyright © 2017年 360.cn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "QHADSDKConfig.h"
@interface QHAGADSDKConfig : QHADSDKConfig
+ (QHAGADSDKConfig *)shareInstance;
//聚合平台分配的app key
@property(nonatomic, copy) NSString* appkey;

@property(nonatomic,strong,readonly) __block NSMutableDictionary* akConfig;
@end
