//
//  QHSConfiguration.h
//  QHSAnalyticsSdk
//
//  Created by sunyimin on 16/5/23.
//  Copyright © 2016年 北京奇虎科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>


/**报告策略*/
typedef NS_ENUM(NSUInteger, QHSReportPolicy){
    QHSReportPolicyBatch = 0,          //应用启动时发送(默认)
    QHSReportPolicyInterval = 1        //间隔发送
//    QHSReportPolicyRealtime = 2        //实时发送
};


/**上报数据优先级*/
typedef NS_ENUM(int, QHSDataLevel) {
    QHSDataLevel1 = 1, //默认时间间隔24小时
    QHSDataLevel5 = 5, //等级5为标准级别，1，2，3，4，6，7，8为非标准级别
    QHSDataLevel9 = 9  //实时
};


/**统计项目*/
typedef NS_ENUM(NSUInteger, QHSAnalyticsItem) {
    QHSAnalyticsItemModuleName             =0,//model机型
    QHSAnalyticsItemCarrier                =1,//operator 电信运营商
    QHSAnalyticsItemLocaleCountryCode      =2,//country 国家
    QHSAnalyticsItemBoard                  =3,//board 主版名称 IOS 没有这项
    QHSAnalyticsItemBrand                  =4,//brand 商标名称 IOS 没有这项
    QHSAnalyticsItemManufacturer           =5,//manufacturer 制造商 IOS 没有这项
    QHSAnalyticsItemUid                    =6,//ip 已不使用该位，保留做其它用处
    QHSAnalyticsItemMac                    =7,//mac IOS 没有这项
    QHSAnalyticsItemTag                    =8,//tag 自定义标签
    QHSAnalyticsItemImei                   =9,//imei IOS 没有这项
    QHSAnalyticsItemLanguage               =10,//language 系统语言
    QHSAnalyticsItemPage                   =11,//activity 页面信息
    QHSAnalyticsItemSession                =12,//terminate 会话信息
    QHSAnalyticsItemCpu                    =13,//cpu IOS 没有这项
    QHSAnalyticsItemLongitude              =14,//longitude
    QHSAnalyticsItemLatitude               =15,//latitude
    QHSAnalyticsItemCustomEvent            =16,//event 自定义事件
    QHSAnalyticsItemSocialEvent            =17,//social 社交行为
    QHSAnalyticsItemBSSID                  =18,//Wifi BSSID
    QHSAnalyticsItemLiveEvent              =19,//live 事件
    QHSAnalyticsItemPlayEvent              =20//play 事件

};


//采样项目ID,一个ID对应一个采样值，可通过云控来设置
typedef NS_ENUM(int, QHSSampledItemId){
    QHSSampledItemIdPage,            //页面
    QHSSampledItemIdCustomEventA,    //A类型事件
    QHSSampledItemIdCustomEventB     //B类型事件
};


typedef NS_ENUM(NSUInteger, QHSCustomEventSamplingType){
    QHSCustomEventSamplingTypeA,    //A类型事件
    QHSCustomEventSamplingTypeB     //B类型事件
};

/**数据类型*/
typedef NS_ENUM(NSUInteger, QHSDataType) {
    QHSDataTypeBasicInfo,
    QHSDataTypeSession,
    QHSDataTypePage,
    QHSDataTypeCustomEvent,
    QHSDataTypeSocialEvent,
    QHSDataTypeLiveEvent,
    QHSDataTypePlayEvent,
    QHSDataTypeError
};

/**报告类型*/
typedef NS_ENUM(NSUInteger, QHSDataReportType) {
    QHSDataReportTypeNormal = 0,//正常报告
    QHSDataReportTypeFileSystemFreeSizeIsLow = 2,//存储空间不足
    QHSDataReportTypeOnSessionBegin = 3//应用启动报告
};


//1为收到远程推送，2为点击打开远程推送，3为远程推送已展示，4为触发下载
typedef NS_ENUM(NSUInteger, QHSPushType) {
    QHSPushTypeReceived = 1,//收到推送
    QHSPushTypeOpen     = 2,//用户打开推送
    QHSPushTypeShown    = 3,//推送信息打开并展示
    QHSPushTypeDownload = 4 //推送触发下载
};

/**A／B Test类型*/
typedef NS_ENUM(NSUInteger, QHSAbTestTag) {
    QHSAbTestTagA = 1,
    QHSAbTestTagB = 2,
    QHSAbTestTagC = 3,
    QHSAbTestTagD = 4,
    QHSAbTestTagE = 5
};


/**header中放入ext里的tag类型*/
typedef NS_ENUM(NSUInteger, QHSExtraTagIndex) {
    QHSExtraTagIndex1 = 1,
    QHSExtraTagIndex2 = 2,
    QHSExtraTagIndex3 = 3,
    QHSExtraTagIndex4 = 4,
    QHSExtraTagIndex5 = 5,
    QHSExtraTagIndex6 = 6,
    QHSExtraTagIndex7 = 7,
    QHSExtraTagIndex8 = 8,
    QHSExtraTagIndex9 = 9,
    QHSExtraTagIndex10 = 10,
};


@interface QHSConfiguration : NSObject

@property(nonatomic,copy)NSString *appKey;
@property(nonatomic,assign)BOOL reportEnabled;//是否上报统计数据
//@property(nonatomic,assign)BOOL crashReportAppleFormatSymbolicated;//是否符号化苹果错误报告
@property(nonatomic,assign)BOOL crashReportEnabled;//是否上报错误信息
@property(nonatomic,assign)BOOL autoLocationEnabled;//是否自动定位位置信息
@property(nonatomic,assign)BOOL loactionReportEnabled;//是否上报位置信息
@property(nonatomic,assign)BOOL logEnabled;//是否输出日志
@property(nonatomic,assign)BOOL useIdfvOnly;//是否只使用IDFV,不使用KEYCHAIN
@property(nonatomic,assign)BOOL debugMode;//测试模式会开启数据监听
@property(nonatomic,assign)QHSReportPolicy reportPolicy;
@property(nonatomic,assign)double onlineConfigUpdateTimeInterval;//云控的更新时间间隔
@property(nonatomic,assign)NSUInteger reportWhenNoDataRetryTimes;//读取上报数据并上传时，没有读取到数据时的重试次数
@property(nonatomic,assign)long long switchValue;//一个十进制的无符号64位数字，用来做采集项开关
@property(nonatomic,assign)unsigned long long dataCacheItemSize;   //每个包的大小，默认5KB
@property(nonatomic,assign)unsigned long long dataCacheMinFileSystemFreeSize;   //最小可用存储空间，默认50MB
@property(nonatomic,assign)unsigned long long dataCacheMaxFileSize;    //本地最多备份的数据大小，默认2MB


@property (nonatomic,assign) BOOL onlineConfigBeBetaVersion;//是否使用测试版本的云控
@property (nonatomic,assign) BOOL devLogEnable;
@property (nonatomic,assign) BOOL dataL1Enable;
@property (nonatomic,assign) BOOL autoManageSession;
@property (nonatomic,strong) NSCondition *_lock;
@property(nonatomic,assign,readonly) BOOL debugInfo;//是否上传排错信息，默认关闭
@property(nonatomic,assign,readonly) BOOL debugInfoPersistable;
@property(nonatomic,assign) BOOL sdkError;//是否上报SDKError
@property(nonatomic,strong) NSString *domainReport;//报告域名
@property(nonatomic,strong) NSString *domainConfig;//云控域名
@property(nonatomic,assign)NSUInteger intervalReportCancelTimeInterval;//间隔上传的最大时间间隔
@property(nonatomic,assign)NSUInteger maxErrorCountOneDay;//每天上报错误条数最大值
@property(nonatomic,assign)BOOL isReportADDataEnabled;//是否上报广告监测数据
 @property(nonatomic,copy) NSDictionary *specialHandleEvents;

//=====
- (instancetype)initWithAppKey:(NSString *)appkey andQueue:(dispatch_queue_t) queueName;
- (NSTimeInterval)reportTimeInervalWithDataLevel:(QHSDataLevel)dataLevel;
- (BOOL)isQHSAnalyticsItemEanble:(QHSAnalyticsItem)item;
- (BOOL)isQHSAnalyticsItemEanble:(QHSAnalyticsItem)item samplingEffect:(BOOL)hasEffect;
- (BOOL)isQHSAnalyticsItemEanble:(QHSAnalyticsItem)item customEventSamplingType:(QHSCustomEventSamplingType)samplingType samplingEffect:(BOOL)hasEffect;
- (void)syncUpdateOnlineConfiguration;
/**
 *  云控项目“设备每天可上报错误条数最大值”
 *
 *  @return Yes：达到上报最大值（不允许上报）  NO：没达到
 */
-(BOOL)isMaxErrorCountToday;
@end
////////////////////////////////////////////
#pragma mark -
#pragma mark 采样项目
@interface QHSSampledItem : NSObject
@property (nonatomic,assign)QHSSampledItemId itemId;
@property (nonatomic,assign,readonly) BOOL isSampled;//是否是取样设备，YES表示是取样设备，则采集信息，否则不采集信息
- (instancetype)initWithItemId:(QHSSampledItemId)itemId;
- (void)updateWithSamplingRate:(unsigned int)rateValue;
@end
////////////////////////////////////////////
#pragma mark -
#pragma mark 云控对象
@interface QHSOnlineConfiguration : NSObject
@property (nonatomic,strong) NSString *appKey;
@property (nonatomic,strong) NSNumber *refreshInterval;//请求云控配置的间隔，单位为小时
@property (nonatomic,strong) NSNumber *reportPolicy;//上传策略，0为下次启动时，1为按间隔

@property (nonatomic,strong) NSNumber *reportInterval2G;//2G上传间隔
@property (nonatomic,strong) NSNumber *reportInterval3G;//3G上传间隔
@property (nonatomic,strong) NSNumber *reportInterval4G;//4G上传间隔
@property (nonatomic,strong) NSNumber *reportIntervalWiFi;//WIFI上传间隔

@property (nonatomic,strong) NSNumber *reportIntervalBg;//后台活跃上传间隔

@property (nonatomic,strong) NSNumber *reportInterval2GL1;//L1,2G上传间隔
@property (nonatomic,strong) NSNumber *reportInterval3GL1;//L1,3G上传间隔
@property (nonatomic,strong) NSNumber *reportInterval4GL1;//L1,4G上传间隔
@property (nonatomic,strong) NSNumber *reportIntervalWiFiL1;//L1,WIFI上传间隔

@property (nonatomic,strong) NSNumber *reportWhenNoDataRetryTimes; //读取上报数据并上传时，没有读取到数据时的重试次数
@property (nonatomic,strong) NSNumber *sessionFinishDelay;//会话持续时间，单位毫秒,这个字段IOS版本不会使用。
@property (nonatomic,strong) NSNumber *dataCacheItemSize;//上报时每个包的大小byte，超过此值就要分包。
@property (nonatomic,strong) NSNumber *dataCacheMaxFileSize;//本地缓存文件最大的大小bype，超过此大小就要删除一部分或全部
@property (nonatomic,strong) NSNumber *dataCacheMinFileSystemFreeSize;//文件系统最小可用空间，满足此项才会写缓存文件
@property (nonatomic,strong) NSNumber *transportProtocols;//上传协议顺序，1为Post、2为Get、3为TCP、4为UDP

@property(nonatomic,assign)NSNumber *intervalReportCancelTimeInterval;//间隔上传的最大时间间隔
@property(nonatomic,assign)NSNumber *maxErrorCountOneDay;//每天上报错误条数最大值

@property (nonatomic,strong) NSNumber *switchValue;//一个十进制的无符号64位数字，用来做采集项开关
@property (nonatomic,strong) NSNumber *sdkSwitchValue;//SDK排错用的开关。为开时会上传排错信息。

@property (nonatomic,strong) QHSSampledItem *sampledItemPage;//页面路径的采样率
@property (nonatomic,strong) QHSSampledItem *sampledItemCustomEventA;//自定义事件A的采样率
@property (nonatomic,strong) QHSSampledItem *sampledItemCustomEventB;//自定义事件B的采样率
@property(nonatomic,copy) NSDictionary *specialHandleEvents;

//=====
- (instancetype)initWithDic:(NSDictionary *)dic;

 
@end
