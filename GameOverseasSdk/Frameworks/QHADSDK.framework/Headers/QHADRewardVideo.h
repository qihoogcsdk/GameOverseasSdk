//
//  QHADRewardVideo.h
//  QHADSDK
//
//  Created by wangfei-sal on 2019/7/23.
//  Copyright © 2019 360.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class QHADRewardVideo;

@protocol QHADRewardVideoDelegate <NSObject>

/*
 *  视频广告已可用
 */
- (void)QHADRewardVideoVideoDidLoad:(QHADRewardVideo* _Nullable)  rewarded;
/*
 *  广告获取失败
 *  广告失败不会重试,请开发者轮换下一个广告!
 */
- (void)QHADRewardVideo:(QHADRewardVideo* _Nullable)  rewarded didFailWithError:(NSError*) error;

@optional
/*
 *  视频广告即将播放
 */
- (void)QHADRewardVideoWillPlaying:(QHADRewardVideo* _Nullable)  rewarded;
/*
 *  广告已展示
 */
- (void)QHADRewardVideoDidFinishShow:(QHADRewardVideo* _Nullable)  rewarded;

/**
 *  广告被点击
 */
- (void)QHADRewardVideoClicked:(QHADRewardVideo* _Nullable)  rewarded;

/**
 *  广告被关闭
 */
- (void)QHADRewardVideoClosed:(QHADRewardVideo* _Nullable)  rewarded;

/**
 *  广告达到激励条件
 */
- (void)QHADRewardVideoDidRewardEffective:(QHADRewardVideo* _Nullable)  rewarded;

/**
 *  广告被点击后弹出LandingPage
 */
- (void)QHADRewardVideoLandingPageShowed:(QHADRewardVideo* _Nullable)  rewarded;

/**
 *  广告弹出的LandingPage被关闭
 */
- (void)QHADRewardVideoLandingPageHided:(QHADRewardVideo* _Nullable)  rewarded;
@end

typedef void (^QHADRewardVideoLoaderCompletionHandler)(BOOL isAdValid,NSError* _Nullable  error);

@interface QHADRewardVideo : NSObject

@property (nonatomic, copy) NSString *adspaceid;

@property (nonatomic, assign, readonly) BOOL isAdValid;

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

@property(nonatomic, weak) id<QHADRewardVideoDelegate> delegate;

//视频播放默认静音
@property(nonatomic,assign) BOOL isMuted;

//视频播放页面屏幕方向. (默认,按照视频素材尺寸,自适应屏幕的方向.第三方广告SDK的页面屏幕方向可能不能设置.)
@property(nonatomic, assign) UIInterfaceOrientation preferredInterfaceOrientation;
/**
 *  加载激励视频广告。
 */
-(void)loadAd:(QHADRewardVideoLoaderCompletionHandler) completion;

/**
 *  播放视频广告。请在视频广告已可用后，(isAdValid == YES)调用。
 */
- (NSError* _Nullable)playVideo:(UIViewController*)vc;


@end

NS_ASSUME_NONNULL_END
