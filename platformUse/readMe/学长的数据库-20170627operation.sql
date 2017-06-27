CREATE TABLE `iot_data_type`(
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `data_format` varchar(127) DEFAULT NULL COMMENT '数据格式描述',
  `data_tab_name` char(11) NOT NULL COMMENT '数据表名前缀',
  `flag` tinyint(1) DEFAULT '0' COMMENT '预留字段',
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=5 ;

CREATE TABLE `iot_dev_type`(
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `apk_url` varchar(127) NOT NULL COMMENT 'apk文件路径',
  `apk_info` varchar(127) DEFAULT NULL COMMENT 'apk描述信息',
  `ctime` int(10) DEFAULT '0' COMMENT  '上传时间',
  `flag` tinyint(1) DEFAULT '0' COMMENT '预留字段',
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=5 ;

CREATE TABLE `iot_dev` (
  //`id` int(10) NOT NULL AUTO_INCREMENT,
  `devid`   int(10) NOT NULL COMMENT '设备唯一标识符', 
 // `devname` varchar(64) NOT NULL COMMENT '设备名字',
  `business_id` int(10) NOT NULL COMMENT '所属公司id',
  `data_type_id` int(10) NOT NULL COMMENT '数据格式类型',
  `dev_type_id` int(10) NOT NULL COMMENT '设备类型',
  `owner` varchar(127) DEFAULT NULL COMMENT '制造商',
  //`phone` char(11) DEFAULT NULL COMMENT '联系方式',
  `ctime` int(10) DEFAULT '0' COMMENT  '安装时间',
  `flag` tinyint(1) DEFAULT '0' COMMENT '是否有效',
  PRIMARY KEY (`id`),
  KEY `devid` (`devid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT '设备表';

CREATE TABLE `iot_info_0` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `devid`   int(10) NOT NULL COMMENT '设备唯一标识符', 
  `info` varchar(255) DEFAULT NULL COMMENT '采集到的信息',
  `ctime` int(10) DEFAULT '0' COMMENT  '采集时间',
  `flag` tinyint(1) DEFAULT '0' COMMENT '是否有效',
  PRIMARY KEY (`id`),
  KEY `devid` (`devid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT '信息表';
 
 

CREATE TABLE `iot_group` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `business_id` varchar(64) DEFAULT NULL COMMENT '公司名称',
  `group_name` varchar(64) DEFAULT NULL COMMENT '组名',
  `user_id` int(10) NOT NULL COMMENT '创建者',
  `create_time` int(10) DEFAULT '0',
  `authority` tinyint(1) DEFAULT '0' COMMENT '其他用户是否可见', 
  `flag` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=5 ;

############################################
# set: key(iot_groupid_userId) -> value (devId);
############################################
