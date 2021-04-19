//
//  AppDelegate.swift
//  Example
//
//  Created by xhp281 on 2020/8/26.
//  Copyright © 2020 xhp281. All rights reserved.
//

import UIKit
import GameOverseasSdk

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    var window: UIWindow?
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // 设置屏幕方向，根据具体需求设置（默认支持横屏）
        QGOSSdkMatrix.shared.supportInterfaceOriention = .all
        // 日志
        QGOSSdkMatrix.isLogEnable = true
        // 初始化参数
        // FIXME: key需要联系相关对接人员获取
        let parameters = [QGOSSConfig.appkey: "testios",
                          QGOSSConfig.qdasKey: "xxx",
                          QGOSSConfig.faceBookKey: "xxx",
                          QGOSSConfig.googleKey: "xxx",
                          QGOSSConfig.googleServerKey: "xxx",
                          QGOSSConfig.lineKey: "xxx",
                          QGOSSConfig.twitterKey: "xxx",
                          QGOSSConfig.twitterSecret: "xxx",
                          QGOSSConfig.twitterCallbackUrl : "twitterkey://",
                          QGOSSConfig.adKey: "xxx",
                          QGOSSConfig.adSpaceId: "xxx",
                          QGOSSConfig.isAdTest: true,
                          QGOSSConfig.enableLocation: true,
                          QGOSSConfig.flyerKey: "xxx",
                          QGOSSConfig.appleId: "xxx",
            ] as [String : Any]
        // SDK注册
        QGOSSdkMatrix.registerSDK(application, launchOptions: launchOptions,parameters: parameters)
        return true
    }
    
    @available(iOS 9.0, *)
    func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
        // SDK回调设置
        return  QGOSSdkMatrix.handleOpenURL(app, open: url, options: options)
    }
    
    func application(_ application: UIApplication, supportedInterfaceOrientationsFor window: UIWindow?) -> UIInterfaceOrientationMask {
        // 屏幕方向支持
        return QGOSSdkMatrix.shared.supportInterfaceOriention
    }
}
