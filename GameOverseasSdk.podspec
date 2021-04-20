Pod::Spec.new do |s|
    s.name             = 'GameOverseasSdk'
    s.version          = '1.1.0'
    s.summary          = 'GameOverseasSdk'

    s.description      = <<-DESC
        海外SDK聚合工程库
    DESC

    s.homepage         = 'https://github.com/qihoogcsdk/GameOverseasSdk'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'xuhaipeng' => 'xuhaipeng@360.cn' }
    s.source           = { :git => 'https://github.com/qihoogcsdk/GameOverseasSdk.git', :tag => s.version.to_s }
    s.requires_arc = true
    s.platform     = :ios

    # 是否是静态库
    s.static_framework  =  true
    
    s.ios.deployment_target = '11.0'
    
    # 链接设置 重要
    s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC', 'ENABLE_BITCODE' => 'NO', 'BUILD_LIBRARY_FOR_DISTRIBUTION' => 'YES'}

    # # 模拟器排除 Apple Silicon
    # s.pod_target_xcconfig = {
    #     'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
    # }
    # s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

    # 依赖的系统库
    s.frameworks = 'WebKit', 'CoreTelephony','Security', 'StoreKit', 'SystemConfiguration', 'CoreLocation', 'AdSupport'
    s.libraries  = 'c++', 'c++abi', 'z'

    # 第三方非开源库
    s.preserve_paths      = "GameOverseasSdk/Frameworks/*.{framework,a}"
    s.vendored_libraries  = 'GameOverseasSdk/Frameworks/*.{a}'
    s.vendored_frameworks = 'GameOverseasSdk/Frameworks/*.{framework}'

    # 资源文件
    s.resources = 'GameOverseasSdk/Resources/*.bundle'

    # 第三方库
    s.dependency "Alamofire",      '~> 5.2.2'     # 网络请求
    s.dependency "SwiftyJSON",     '~> 5.0.0'     # 自动解包
    s.dependency "KakaJSON",       '~> 1.1.2'     # 数据解析
    s.dependency "SnapKit",        '~> 5.0.1'     # 自动布局
    s.dependency "KeychainAccess", '~> 4.2.0'     # 钥匙串存储
    s.dependency "MBProgressHUD",  '~> 1.2.0'     # toast
    s.dependency "FBSDKLoginKit",      '~> 8.2.0'     # FackBook登录
    s.dependency "GoogleSignIn",       '~> 5.0.2'     # google登录
    s.dependency "LineSDKSwift",       '~> 5.7.0'     # line登录
    s.dependency "AppsFlyerFramework", '~> 6.1.4'     # 广告分析SDK
    s.dependency "CocoaLumberjack/Swift", '~> 3.6.1'  # 日志系统

end