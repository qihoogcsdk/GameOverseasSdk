//
//  QHADUnifiedNativeView.h
//  QHADSDK
//
//  Created by wangfei-sal on 2020/3/25.
//  Copyright © 2020 360.cn. All rights reserved.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface QHADUnifiedNativeView : UIView
//请自行创建UIView
@property(nonatomic, strong, nullable)  UIView *headlineView;

@property(nonatomic, strong, nullable)  UIView *callToActionView;

@property(nonatomic, strong, nullable)  UIView *bodyView;

@property(nonatomic, strong, nullable)  UIView *storeView;

@property(nonatomic, strong, nullable)  UIView *priceView;

@property(nonatomic, strong, nullable)  UIView *starRatingView;

@property(nonatomic, strong, nullable)  UIView *advertiserView;

//在原生横幅广告中,您必须使用iconView来显示广告商图标
@property(nonatomic, strong, nullable) UIView *iconView;

//在信息流广告中,您必须使用mediaView来显示以下广告内容：广告图像，视频或轮播。
@property(nonatomic, strong, nullable) UIView *mediaView;

@property(nonatomic, strong, nullable) UIView *adChoicesView;

//当前界面的ViewController,用来present广告的详情页或下载页面.（不能为空）
@property(nonatomic, weak, nullable) UIViewController *rootViewController;
@end

NS_ASSUME_NONNULL_END
