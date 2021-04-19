//
//  QHADUnifiedNative.h
//  QHADSDK
//
//  Created by wangfei-sal on 2019/8/1.
//  Copyright © 2019 360.cn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "QHADUnifiedNativeView.h"
NS_ASSUME_NONNULL_BEGIN
@class QHADUnifiedNative;

@protocol QHADUnifiedNativeDelegate <NSObject>

/*
 *  原生广告已可用
 */
- (void)QHADUnifiedNativeDidLoad:(QHADUnifiedNative* _Nullable)  unifiedNatived;
/*
 *  原生广告获取失败
 *  原生广告失败不会重试,请开发者轮换下一个广告!
 *  尽量不要尝试在此代理方法中,再次加载新广告.以免在网络连接受限等情况下连续发生广告请求失败。
 */
- (void)QHADUnifiedNativeDidFaildLoad:(QHADUnifiedNative* _Nullable)  unifiedNatived withError:(NSError*) error;

/*
 *  原生广告已展示
 */
- (void)QHADUnifiedNativeDidFinishShow:(QHADUnifiedNative* _Nullable)  unifiedNatived;

@optional

/**
 *  广告被点击
 */
- (void)QHADUnifiedNativeClicked:(QHADUnifiedNative* _Nullable)  unifiedNatived;


/**
 *  广告被点击后弹出LandingPage
 */
- (void)QHADUnifiedNativeLandingPageShowed:(QHADUnifiedNative* _Nullable)  unifiedNatived;

/**
 *  广告弹出的LandingPage被关闭
 */
- (void)QHADUnifiedNativeLandingPageHided:(QHADUnifiedNative* _Nullable)  unifiedNatived;
@end

typedef void (^QHADUnifiedNativeLoaderCompletionHandler)(BOOL isAdValid,NSError* _Nullable  error);

@interface QHADUnifiedNative : NSObject

@property (nonatomic, copy) NSString *adspaceid;

@property (nonatomic, assign, readonly) BOOL isAdValid;

@property(nonatomic, weak) id<QHADUnifiedNativeDelegate> delegate;
/*
 广告平台来源。
 1，360广告。
 2，广点通API。
 6，广点通SDK。
 9，穿山甲SDK
 11，AdMob SDK
 12，Facebook SDK
 */
@property (nonatomic, strong,readonly) NSNumber* pl_id;

//当前界面的ViewController,用来present广告的详情页或下载页面.（不能为空）
@property(nonatomic, weak, nullable) UIViewController *rootViewController;

/*原生广告自渲染的约定:

1. 广告的渲染需要在容器nativeAdView中进行.

必须使用 nativeAdView 来展示广告元素,SDK 就可以自动处理以下任务：

记录广告点击。

记录广告展示（当第一个像素出现在屏幕上时）。

2. SDK 会自动获取图片或视频素材资源.

3. 图片或视频素材资源通过 mediaView 向用户展示.视频资源自动播放.

4. mediaView宽高比为素材的宽高比，请不要过度拉伸.
*/
@property (nonatomic, strong,readonly) QHADUnifiedNativeView * nativeAdView;

//是否为视频广告
@property (nonatomic, readonly) BOOL isVideoAd;

//广告元数据，可为nil。
@property (nonatomic, copy, readonly, nullable) NSString *title;//广告标题

@property (nonatomic, copy, readonly, nullable) NSString *desc;//广告描述

@property (nonatomic, copy, readonly, nullable) NSString *callToAction;//广告按钮文字

@property (nonatomic, copy, readonly, nullable) NSString *starRating; //星级(0 to 5).

@property (nonatomic, copy, readonly, nullable) NSString *price;//App 价格

@property (nonatomic, copy, readonly, nullable) NSString *advertiserName;//广告来源

@property (nonatomic, copy, readonly, nullable) NSString *socialContext;//激励性广告文案，如“10000人已评论”


//请求广告
//尽管预先提取广告是很好的做法，但切勿一直保留旧广告而不展示它们。对任何原生广告对象来说，如果在保留一小时后仍没有获得展示，就应该予以舍弃，并替换为来自新请求的新广告。
-(void)loadAd:(QHADUnifiedNativeLoaderCompletionHandler) completion;

@end

NS_ASSUME_NONNULL_END
