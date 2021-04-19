//
//  QHADInterstitial.h
//  QHADSDK
//
//  Created by Work on 2020/3/2.
//  Copyright © 2020 360.cn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class QHADInterstitial;
@protocol QHADInterstitialDelegate <NSObject>

/*
*  插屏广告加载完成
*/
- (void)QHADInterstitialAdDidLoad:(QHADInterstitial *)interstitialAd;

/*
*  插屏广告已展示
*/
- (void)QHADInterstitialDidFinishShow:(QHADInterstitial *)interstitialAd;

/*
*  广告获取失败
*  广告失败不会重试,请开发者轮换下一个广告!
*/
- (void)QHADInterstitialAd:(QHADInterstitial *)interstitialAd didFailWithError:(NSError *)error;

@optional
/*
*  广告被点击
*/

- (void)QHADInterstitialClicked:(QHADInterstitial *)interstitialAd;

/*
*  广告被关闭
*/

- (void)QHADInterstitialClosed:(QHADInterstitial *)interstitialAd;

@end

@interface QHADInterstitial : NSObject
@property (nonatomic, weak) UIViewController             *rootViewController;
@property (nonatomic, copy) NSString                     *adspaceid;
@property (nonatomic, weak) id<QHADInterstitialDelegate> delegate;
/*
 广告平台来源。
 6，广点通SDK。
 9，穿山甲SDK。
 11，AdMob SDK。
 12，Facebook SDK。
 */
@property (nonatomic, strong,readonly) NSNumber* pl_id;
- (void)loadAd;
- (BOOL)isAdValid;
- (void)showAd;
@end

NS_ASSUME_NONNULL_END
