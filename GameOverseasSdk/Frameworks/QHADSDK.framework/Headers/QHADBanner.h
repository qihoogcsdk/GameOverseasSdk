//
//  QHADBanner.h
//  QHADSDK
//
//  Created by Zy on 2020/1/8.
//  Copyright © 2020 360.cn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
// Represents the ad size.
typedef NS_ENUM(NSUInteger, QHAdSizeType) {
    kQHADAdSizeHeight250Rectangle, /*  中矩形广告. 300x250 像素的横幅广告，最适合滚动画面或固定画面。  */
    kQHADAdSizeHeight60Banner, /* 标准横幅广告.  此横幅广告格式适用于手机. 高度60 宽度为屏幕宽度，如果使用海外版本可设置为50*/
    kQHADAdSizeHeight90Banner, /*大型横幅广告. 此横幅广告格式适用于平板电脑. 高度90 宽度为屏幕宽度*/
};

@class QHADBanner;
@protocol QHADBannerDelegate <NSObject>
/*
 *  广告已展示
 */
- (void)QHADBannerDidFinishShow:(QHADBanner* _Nullable)  adView;
/*
 *  广告获取失败
 *  广告失败不会重试,请开发者轮换下一个广告!
 */
- (void)QHADBannerDidFaildLoad:(QHADBanner* _Nullable)  adView withError:(NSError*) error;

@optional

/**
 *  广告被点击
 */
- (void)QHADBannerClicked:(QHADBanner* _Nullable)  adView;

/**
*  广告被关闭，仅广点通SDK返回此回调
*/
- (void)QHADBannerlClosed:(QHADBanner* _Nullable)adView;

/**
 *  广告被点击后弹出LandingPage
 */
- (void)QHADBannerLandingPageShowed:(QHADBanner* _Nullable)  adView;

/**
 *  广告弹出的LandingPage被关闭
 */
- (void)QHADBannerLandingPageHided:(QHADBanner* _Nullable)  adView;
@end

@interface QHADBanner : UIView
@property (nonatomic, weak) UIViewController        *rootViewController;
@property (nonatomic, copy) NSString                *adspaceid;
@property(nonatomic, weak) id<QHADBannerDelegate>   delegate;
@property (nonatomic, assign) QHAdSizeType          adSizeType;
/*
 广告平台来源。
 6，广点通SDK。
 9，穿山甲SDK。
 11，AdMob SDK。
 12，Facebook SDK。
 */
@property (nonatomic, strong,readonly) NSNumber* pl_id;
- (void)loadAd;
@end

NS_ASSUME_NONNULL_END
