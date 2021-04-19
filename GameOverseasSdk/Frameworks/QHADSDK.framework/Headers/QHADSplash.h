//
//  QHADSplash.h
//  QHADSDK
//
//  Created by wangfei-sal on 2019/12/12.
//  Copyright © 2019 360.cn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class QHADSplash;

@protocol QHADSplashDelegate <NSObject>

/*
 *  开屏广告已展示
 */
- (void)QHADSplashDidFinishShow:(QHADSplash* _Nullable)  splashed;
/*
 *  广告获取失败
 *  广告失败不会重试,请开发者轮换下一个广告!
 */
- (void)QHADSplashDidFaildLoad:(QHADSplash* _Nullable)  splashed withError:(NSError*) error;

@optional

/**
 *  广告被点击
 */
- (void)QHADSplashClicked:(QHADSplash* _Nullable)  splashed;

/**
 *  广告被关闭
 */
- (void)QHADSplashClosed:(QHADSplash* _Nullable)  splashed;

/**
 *  广告被点击后弹出LandingPage
 */
- (void)QHADSplashLandingPageShowed:(QHADSplash* _Nullable)  splashed;

/**
 *  广告弹出的LandingPage被关闭
 */
- (void)QHADSplashLandingPageHided:(QHADSplash* _Nullable)  splashed;
@end
@interface QHADSplash : NSObject

//开屏广告的倒计时秒数(单位:秒).//建议时间：5秒
@property(nonatomic,assign) NSInteger skipInterval;

//广告请求的超时时间。(单位秒)，默认3秒
@property(nonatomic,assign) NSTimeInterval timeout;

@property (nonatomic, copy) NSString *adspaceid;

@property(nonatomic, weak) id<QHADSplashDelegate> delegate;

//自定义底部View，可以在此View中设置应用Logo
//注意:bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%
@property(nonatomic,strong) UIView* bottomView;

//广告加载过程中的背景view.
@property(nonatomic,strong) UIView* backgroundView;

/*
 广告平台来源。
 1，360广告。
 2，广点通API。
 6，广点通SDK。
 9，穿山甲SDK。
 */
@property (nonatomic, strong,readonly) NSNumber* pl_id;

//仅在项目中应用SceneDelegate类的时候设置。
@property(nonatomic,assign) UIResponder* windowScene;
//Splash广告只支持竖屏.
- (void)loadAdAndShow;
@end

NS_ASSUME_NONNULL_END
