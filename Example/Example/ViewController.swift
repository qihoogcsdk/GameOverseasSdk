//
//  ViewController.swift
//  QHGOSDK_Swift_Demo
//
//  Created by xhp281 on 2020/8/26.
//  Copyright © 2020 xhp281. All rights reserved.
//

import UIKit
import SnapKit
import QHADSDK
import GameOverseasSdk

// size
let itemHeight: CGFloat = 40
let itemMarginTB: CGFloat = 10
let itemMarginLR: CGFloat = 20
let rowCount:   CGFloat = 3

class ViewController: UIViewController{
    
    let collectionLayout: UICollectionViewFlowLayout = UICollectionViewFlowLayout.init()
    var collectionView: UICollectionView?
    let versionLabel = UILabel()
    let textView     = UITextView()
    
    // 日志关闭
    var isEnableLog: Bool   = false
    // 绑定成功
    var isBindSuccess: Bool = true
    
    // 数据
    var dataArray = [["":[""]]]
    
    // MARK: - life cycle
    override func viewDidLoad() {
        super.viewDidLoad()
        self.initUIConfig()
        addObserver()
    }
}

/// MARK: - UI
extension ViewController{
    
    /// 初始化UI
    func initUIConfig(){
        initData()
        addSubviews()
        addConstraints()
    }
    
    func initData(){
        let logText    = QGOSSdkMatrix.isLogEnable ? "日志(开启)" : "日志(关闭)"
        let cpBingText = isBindSuccess ? "设置绑定(成功)" : "绑定(失败)"
        dataArray = [["设置":[logText, cpBingText]],
                     ["登录":["自动登录","切换登录","退出登录"]],
                     ["支付":["Apple支付"]],
                     ["广告":["海外广告"]]]
    }
    
    /// 添加控件
    func addSubviews(){
        versionLabel.text = "当前版本 \(QGOSSdkMatrix.sdkVersion)";
        versionLabel.textAlignment = .center
        versionLabel.textColor = .red
        versionLabel.font = .boldSystemFont(ofSize: 18)
        versionLabel.backgroundColor = .white
        view.addSubview(versionLabel)
        
        view.addSubview(textView)
        textView.backgroundColor = .lightGray
        textView.isEditable = false
        textView.text = "回调信息"
        
        // collectionLayout
        collectionLayout.itemSize = CGSize(width: (view.bounds.size.width - (rowCount + 1) * itemMarginLR)/rowCount , height: itemHeight)
        collectionLayout.minimumLineSpacing = 0
        collectionLayout.minimumInteritemSpacing = 0
        collectionLayout.headerReferenceSize = CGSize.init(width: view.bounds.size.width, height: itemHeight)
        collectionLayout.sectionInset = UIEdgeInsets.init(top: itemMarginTB, left: itemMarginLR, bottom: itemMarginTB, right: itemMarginLR)
        collectionLayout.itemSize = CGSize(width: (view.bounds.size.width - (rowCount + 1) * itemMarginLR)/rowCount , height: itemHeight)
        // collectionView
        collectionView = UICollectionView(frame: CGRect(), collectionViewLayout: collectionLayout)
        collectionView!.register(CustomCollectionViewCell.self, forCellWithReuseIdentifier:"collection")
        collectionView!.register(CustomSectionHeader.self, forSupplementaryViewOfKind: UICollectionView.elementKindSectionHeader, withReuseIdentifier: "header")
        collectionView!.backgroundColor = .white
        collectionView!.delegate = self
        collectionView!.dataSource = self
        view.addSubview(collectionView!)
    }
    
    /// 添加约束
    func addConstraints() {
        var marginTop = 0
        if !UIDevice.current.orientation.isLandscape {
            marginTop = Int(UIApplication.shared.statusBarFrame.height)
        }
        versionLabel.snp.makeConstraints { (make) in
            make.left.right.equalTo(self.view)
            make.top.equalTo(self.view).offset(marginTop)
            make.height.equalTo(40)
        }
        collectionView!.snp.makeConstraints({ (make) in
            make.left.right.equalTo(self.view)
            make.top.equalTo(textView.snp.bottom)
            make.bottom.equalTo(self.view.snp.bottom)
        })
        textView.snp.makeConstraints { (make) in
            make.top.equalTo(self.versionLabel.snp.bottom)
            make.left.right.equalTo(self.versionLabel)
            make.bottom.equalTo(self.collectionView!.snp.top)
            make.height.equalTo(150)
        }
    }
    
    // 更新约束
    func updateConstraints(){
        var marginTop = 0
        if !UIDevice.current.orientation.isLandscape {
            marginTop = Int(UIApplication.shared.statusBarFrame.height)
        }
        versionLabel.snp.remakeConstraints{ (make) in
            make.left.right.equalTo(self.view)
            make.top.equalTo(self.view).offset(marginTop)
            make.height.equalTo(40)
        }
        self.collectionLayout.itemSize = CGSize(width: (view.bounds.size.width - (rowCount + 1) * itemMarginLR)/rowCount , height: itemHeight)
    }
}


/// MARK: - UICollectionViewDelegate
extension ViewController:UICollectionViewDelegate,UICollectionViewDataSource{
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return dataArray.count
    }
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        let dict = dataArray[section]
        let array = dict[dict.keys.first!]
        return array!.count
    }
    
    func collectionView(_ collectionView: UICollectionView, viewForSupplementaryElementOfKind kind: String, at indexPath: IndexPath) -> UICollectionReusableView {
        var headerView: CustomSectionHeader?
        if kind == UICollectionView.elementKindSectionHeader  {
            headerView = (collectionView.dequeueReusableSupplementaryView(ofKind: kind, withReuseIdentifier: "header", for: indexPath) as! CustomSectionHeader)
            let dict = dataArray[indexPath.section]
            headerView?.titleLabel.text = dict.keys.first!
        }
        return headerView!
    }
    
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let dict = dataArray[indexPath.section]
        let array = dict[dict.keys.first!]
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "collection", for: indexPath) as! CustomCollectionViewCell
        cell.titleLabel.text = array![indexPath.row]
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        let cell = collectionView.cellForItem(at: indexPath) as! CustomCollectionViewCell
        switch indexPath.section {
        case 0:
            switch indexPath.row {
            case 0:
                QGOSSdkMatrix.isLogEnable = !QGOSSdkMatrix.isLogEnable
                let enableText = QGOSSdkMatrix.isLogEnable ? "开启" : "关闭"
                cell.titleLabel.text =  "日志(\(enableText))"
                break
            case 1:
                isBindSuccess = !isBindSuccess
                let cpBingText = isBindSuccess ? "成功" : "失败"
                cell.titleLabel.text =  "设置绑定(\(cpBingText))"
            default:
                break
            }
        case 1:
            switch indexPath.row {
            case 0:
                QGOSSdkMatrix.login(onSignIn: {(dict) in
                    let str = "------------- The login information -------------\n" +
                        "\(dict)" +
                    "\n------------------------------------------"
                    self.textView.text = str
                }, onBindingAccount: {(dict) in
                    let str = "------------- Visitors upgrade return messages -------------\n" +
                        "\(dict)" +
                    "\n------------------------------------------"
                    self.textView.text = str
                    if dict["code"] as! String == "0" {
                        // 设置绑定回调
                        QGOSSdkMatrix.setBindingAccountResult(isBindingAccountSuccess: self.isBindSuccess)
                    }
                })
            case 1:
                QGOSSdkMatrix.changeAccount(onSignIn: {(dict) in
                    let str = "------------- The login information -------------\n" +
                        "\(dict)" +
                    "\n------------------------------------------"
                    self.textView.text = str
                }, onBindingAccount: {( dict ) in
                    let str = "-------------  Visitors upgrade return messages -------------\n" +
                        "\(dict)" +
                    "\n------------------------------------------"
                    self.textView.text = str
                    if dict["code"] as! String == "0" {
                        // 设置绑定回调
                        QGOSSdkMatrix.setBindingAccountResult(isBindingAccountSuccess: self.isBindSuccess)
                    }
                })
            case 2:
                QGOSSdkMatrix.loginOut(callbock: {
                    self.textView.text = "Logout successful"
                })
            default:
                break
            }
        case 2:
            QGOSSdkMatrix.pay(appUserId: "111",
                              appUserName: "测试用户",
                              productId: "100",
                              productName: "测试商品",
                              productAmount: "1",
                              notiUrl: "http://mgame.360.cn/gamecp/status",
                              ipaProductIdentify: "com.qihoo.www.QHLoginSDKDemo_5",
                              onPaySuccess: { (msg) in
                                self.textView.text = "\(msg)"
            },
                              onPayFailure: {(msg) in
                                self.textView.text = "\(msg)"
            })
            break
        case 3:
            switch indexPath.row {
            case 0:
                QGOSSdkMatrix.loadAd(onAdShow: {() in
                    print("======广告展示======")
                },onReward: {() in
                    print("======广告激励达到======")
                },onAdClick: {() in
                    print("======广告点击======")
                },onAdClose: {() in
                    print("======广告关闭======")
                },onRenderFailed: {(error) in
                    print("======广告渲染失败：\(error.localizedDescription)")
                })
                break
            default:
                break
            }
        default:
            break
        }
    }
}


//  MARK: 旋转操作
extension ViewController{
    
    func addObserver(){
        NotificationCenter.default.addObserver(self, selector: #selector(deviceOrientationDidChange), name: UIDevice.orientationDidChangeNotification, object: nil)
    }
    
    @objc func deviceOrientationDidChange(){
        let orient = UIDevice.current.orientation
        switch orient {
        case .portrait :
            updateConstraints()
            break
        case .landscapeLeft:
            fallthrough
        case .landscapeRight:
            updateConstraints()
            break
        default:
            break
        }
    }
    
}
