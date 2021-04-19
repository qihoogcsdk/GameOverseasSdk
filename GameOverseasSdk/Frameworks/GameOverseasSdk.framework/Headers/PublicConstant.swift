//
//  PublicHeader.swift
//  GameOverseasSdk
//
//  Created by xuhaipeng on 2020/8/27.
//  Copyright © 2020 北京奇虎科技有限公司. All rights reserved.
//

import Foundation

/// 登录回调信息
public struct LoginCallback {
    /// 登录回调
    /// deviceId, uUid, uToken, sign
    public  typealias onSignIn = (([String:Any]) -> Void)
    
    /// 退出登录
    public  typealias onSignOut = (() -> Void)
    
    /// 游客绑定回调
    /// deviceId, uUid, uToken
    public  typealias onBindingAccount = (([String:Any]) -> Void)
}

/// 支付回调信息
public struct PayCallback {
    /// 支付成功
    public  typealias onPaySuccess = (([String:Any]) -> Void)
    /// 支付失败
    public  typealias onPayFailure = (([String:Any]) -> Void)
}

/// 广告回调信息
public struct IAdRewardCallback {
    public  typealias onAdShow = (() -> Void)
    public  typealias onAdClick = (() -> Void)
    public  typealias onVideoComplete = (() -> Void)
    public  typealias onAdClose = (() -> Void)
    public  typealias onReward = (() -> Void)
    public  typealias onRenderFailed = ((Error) -> Void)
}

/// 参数key
@objcMembers public class QGOSSConfig: NSObject{
    /// 应用 key
    public static let appkey          = "appkey"
    /// 打点 sdk key
    public static let qdasKey         = "qdasKey"
    /// faceBookKey
    public static let faceBookKey     = "faceBookKey"
    /// googleKey
    public static let googleKey       = "googleKey"
    /// googleServerKey
    public static let googleServerKey = "googleServerKey"
    /// lineKey
    public static let lineKey         = "lineKey"
    /// twitterKey
    public static let twitterKey      = "twitterKey"
    /// twitterSecret
    public static let twitterSecret   = "twitterSecret"
    /// twitterCallbackUrl
    public static let twitterCallbackUrl   = "twitterCallbackUrl"
    /// 广告 key
    public static let adKey           = "adKey"
    /// 广告 spaceId
    public static let adSpaceId       = "adSpaceId"
    /// 是不是使用测试广告
    public static let isAdTest        = "isAdTest"
    /// 是不是开启地理位置获取
    public static let enableLocation  = "enableLocation"
    /// 广告统计key
    public  static let flyerKey       = "flyerKey"
    /// appleId(苹果开发者创建的应用的id)
    public static let appleId         = "appleId"

}
