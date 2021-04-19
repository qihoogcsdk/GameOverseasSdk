//
//  CustomCollectionViewCell.swift
//  QHGOSDK_Swift_Demo
//
//  Created by xhp281 on 2020/8/26.
//  Copyright © 2020 xhp281. All rights reserved.
//

import UIKit

// 自定义cell
class CustomCollectionViewCell: UICollectionViewCell {
    var titleLabel: UILabel!
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupUI()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func setupUI(){
        self.backgroundColor = .lightGray
        titleLabel = UILabel()
        titleLabel.textAlignment = .center
        titleLabel.textColor = .white
        titleLabel.font = .systemFont(ofSize: 12)
        titleLabel.backgroundColor = backgroundColor
        self.addSubview(titleLabel)
        titleLabel.snp.makeConstraints { (make) in
            make.edges.equalTo(self)
        }
    }
}
