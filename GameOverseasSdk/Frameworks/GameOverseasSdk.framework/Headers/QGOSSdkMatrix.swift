//
//  QGOSSdkMatrix.swift
//  GameOverseasSdk
//
//  Created by xuhaipeng on 2020/7/15.
//  Copyright © 2020年 北京奇虎科技有限公司. All rights reserved.
//

import Foundation
import UIKit
import SwiftyJSON
import StoreKit

/// Game SDK for Overseas
@objcMembers public class QGOSSdkMatrix: NSObject {
    
    /// 单例方法
    public static let shared = QGOSSdkMatrix()
    
    /// 初始化SDK
    ///
    /// - Parameter application:   UIApplication
    /// - Parameter launchOptions: Options
    /// - Parameter parameters:    初始化所需参数字典
    public class func registerSDK(_ application: UIApplication,
                                  launchOptions: [UIApplication.LaunchOptionsKey: Any]?,
                                  parameters: [String : Any]){
        // FaceBook设置参数
        FaceBookLoginHelper.shared.application(application, didFinishLaunchingWithOptions: launchOptions)
        // 初始化配置
        Settings.shared.initConfig(parameters: parameters)
    }
    
    // MARK: - SDK设置
    /// 设置应用支持方向接口
    ///
    /// - NOTE: 默认横屏（UIInterfaceOrientationMask.landscape）
    /// - NOTE: 此方法必须接入，否则可能导致 SDK 页面展示异常
    public var supportInterfaceOriention: UIInterfaceOrientationMask{
        set{ DeviceUtil.shared.supportInterfaceOriention = newValue }
        get{ return DeviceUtil.shared.supportInterfaceOriention }
    }
    
    /// 获取当前sdk版本号
    public class  var sdkVersion: String {
        Settings.shared.getCurrSdkVersion()
    }
    
    /// 是否开启日志
    ///
    /// - NOTE: 默认false，需要在SDK初始化之前调用
    public class var isLogEnable: Bool {
        get{ Settings.shared.isLogEnable }
        set{ Settings.shared.isLogEnable = newValue }
    }
    
    // MARK: - SDK第三方回调
    /// SDK回调
    /// - Parameter application:   UIApplication
    /// - Parameter open url:      URL
    /// - Parameter options:       参数字典
    public class func handleOpenURL(_ app: UIApplication,
                                    open url: URL,
                                    options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool{
        FaceBookLoginHelper.shared.handleOpenURL(app, open: url, options: options)
        AppsFlyerHelper.shared.handleOpenURL(url, options)
        
        return GoogleLoginHelper.shared.handleOpenURL(url) || LineLoginHelper.shared.handleOpenURL(app, open: url, options: options) || TwitterLoginHelper.shared.handleOpenURL(url)
    }

    // MARK: - 登录相关
    /// 登录方法
    /// 
    /// - Parameter onSignIn:         登录回调
    /// - Parameter onBindingAccount: 绑定回调
    public class func login(onSignIn: @escaping LoginCallback.onSignIn,
                            onBindingAccount: @escaping LoginCallback.onBindingAccount) {
        LoginHelper.shared.onSignIn = onSignIn
        LoginHelper.shared.onBindingAccount = onBindingAccount
        LoginHelper.shared.checkLoginStatus()
    }
    
    /// 切换账号
    ///
    /// - Parameter onSignIn:         登录回调
    /// - Parameter onBindingAccount: 绑定回调
    public class func changeAccount(onSignIn: @escaping LoginCallback.onSignIn,
                                    onBindingAccount: @escaping LoginCallback.onBindingAccount) {
        LoginHelper.shared.onSignIn = onSignIn
        LoginHelper.shared.onBindingAccount = onBindingAccount
        LoginHelper.shared.jumpLogin()
    }
    
    /// 退出登录
    ///
    /// - Parameter callbock: 退出登录回调
    public class func loginOut(callbock: @escaping LoginCallback.onSignOut) {
        LoginHelper.logOut(callbock: callbock)
    }
    
    /// 游客账号升级为正式账号
    ///
    /// - Parameter isBindingAccountSuccess: 绑定是不是成功
    public class func setBindingAccountResult(isBindingAccountSuccess: Bool) {
        LoginHelper.setBindingAccountResult(isBindingAccountSuccess: isBindingAccountSuccess)
    }
    
    // MARK: - 广告相关
    /// 加载广告
    ///
    /// - Parameters
    /// - onAdShow:        展示回调
    /// - onReward:        达到激励条件回调
    /// - onAdClick:       点击回调
    /// - onAdClose:       关闭回调
    /// - onRenderFailed:  广告加载失败回调
    public class func loadAd(onAdShow: @escaping IAdRewardCallback.onAdShow,
                             onReward: @escaping IAdRewardCallback.onReward,
                             onAdClick: @escaping IAdRewardCallback.onAdClick,
                             onAdClose: @escaping IAdRewardCallback.onAdClose,
                             onRenderFailed: @escaping IAdRewardCallback.onRenderFailed){
        ADHelper.shared.onAdShow = onAdShow
        ADHelper.shared.onReward = onReward
        ADHelper.shared.onAdClick = onAdClick
        ADHelper.shared.onAdClose = onAdClose
        ADHelper.shared.onRenderFailed = onRenderFailed
        ADHelper.shared.loadAd()
    }
    
    // MARK: - 支付相关
    /// 发起支付
    ///
    /// - Parameters
    /// - appUserId:          调用方用户id
    /// - appUserName:        调用方用户名称
    /// - productId:          产品id（联系运营核实）
    /// - productName:        产品名字
    /// - productAmount:      金额（单位分）
    /// - notiUrl:            发货通知地址
    /// - ipaProductIdentify: 开发者中心的商品id
    /// - onPaySuccess:  成功回调
    /// - onPayFailure:  失败回调
    public class func pay(appUserId: String,
                          appUserName: String,
                          productId: String,
                          productName: String,
                          productAmount: String,
                          notiUrl: String,
                          ipaProductIdentify: String,
                          onPaySuccess: @escaping PayCallback.onPaySuccess,
                          onPayFailure: @escaping PayCallback.onPayFailure) {
        PayHelper.shared.onPaySuccess = onPaySuccess
        PayHelper.shared.onPayFailure = onPayFailure
        // 初始化参数
        PayHelper.shared.pay(appUserId: appUserId,
                             appUserName: appUserName,
                             productId: productId,
                             productName: productName,
                             productAmount: productAmount,
                             notiUrl: notiUrl,
                             ipaProductIdentify: ipaProductIdentify)
    }
}
