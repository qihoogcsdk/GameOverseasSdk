//
//  CustomSectionHeader.swift
//  Swift_Demo
//
//  Created by xhp281 on 2020/8/26.
//  Copyright © 2020 xhp281. All rights reserved.
//

import Foundation
import UIKit
import SnapKit

class CustomSectionHeader: UICollectionReusableView {
    
    let titleLabel = UILabel()
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        self.backgroundColor = .clear
        initUI()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func initUI() {
        titleLabel.textAlignment = .left
        titleLabel.textColor = .lightGray
        titleLabel.font = .boldSystemFont(ofSize: 18)
        titleLabel.backgroundColor = .white
        
        self.addSubview(titleLabel)
        titleLabel.snp.makeConstraints { (make) in
            make.top.bottom.equalTo(self)
            make.right.equalTo(-(2 * itemMarginLR))
            make.left.equalTo(itemMarginLR)
        }
    }
}
