CREATE TABLE `iot_business` (
  `business_id` int(10) NOT NULL AUTO_INCREMENT,
  `business_name` varchar(64) DEFAULT NULL COMMENT '公司名称',
  `register_time` int(10) DEFAULT '0',
  `flag` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`business_id`),
  KEY `business_name` (`business_name`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1000 ;

# data_format: 字段为建数据表所需类型字段
# 内容如例： "`data1` int(10),`data2` char(10),"
# 总管理员有权限为该表添加数据，每添加一天数据会触发一次对所有公司的建数据表的操作(待定)
# `data1` int(11) NOT NULL, `data2` int(11) NOT NULL
CREATE TABLE `iot_data_type`(
  `type_id` int(5) NOT NULL AUTO_INCREMENT,
  `type_name` char(11) NOT NULL COMMENT '数据表名前缀',
  `data_format` varchar(255) DEFAULT NULL COMMENT '数据格式描述',
  `ctime` int(10) DEFAULT '0',
  `flag` tinyint(1) DEFAULT '0' COMMENT '预留字段',
  PRIMARY KEY (`type_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=100 ;

# 表名格式为: iot_partation
# 公司管理员可以创建部门，创建时如果用户表中已有经理人员信息可以直接指定部门经理，
# 如果用户表中没有经理人员信息，可以先预留为空。需要用户先注册，然后才能指定经理
CREATE TABLE `iot_department`(
  `department_id` int(10) NOT NULL AUTO_INCREMENT,
  `department_name` varchar(32) NOT NULL COMMENT '部门名称',
  `business_id` int(10) NOT NULL COMMENT '公司id',
  `manager_id` int(5) DEFAULT '0' COMMENT '部门经理id',
  `ctime` int(10) DEFAULT '0' COMMENT '创建时间',
  `flag` tinyint(1) DEFAULT '0' COMMENT '预留字段',
  PRIMARY KEY (`department_id`),
  KEY `business_id` (`business_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=100 ;

# 人员表
# 表名格式为: iot_user
CREATE TABLE `iot_user` (
  `user_id` int(10) NOT NULL AUTO_INCREMENT,
  `password` char(32) COLLATE utf8_unicode_ci NOT NULL,
  `realname` char(6) COLLATE utf8_unicode_ci NOT NULL,
  `business_id` int(10) NOT NULL,
  `department_id` int(5) NOT NULL DEFAULT '0',
  `tel` char(11) COLLATE utf8_unicode_ci DEFAULT NULL,
  `sex` char(2) COLLATE utf8_unicode_ci NOT NULL,
  `email`    varchar(64) NOT NULL,
  `authority` tinyint(1) DEFAULT '0',
  `ctime` int(10) DEFAULT '0' NOT NULL,
  `mtime` int(10) DEFAULT NULL,
  `flag` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`user_id`),
  UNIQUE (`realname`),
  KEY `bd_id` (`business_id`,`department_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1000 ;

#方娟红需要的总设备表
CREATE TABLE `iot_all_dev` (
  `id` int(10) NOT NULL AUTO_INCREMENT COMMENT '主键id',
  `dev_id`  int(10) NOT NULL COMMENT '设备唯一标识符', 
  `devname` varchar(64) NOT NULL COMMENT '设备名字',
  `data_type_id` int(10) NOT NULL COMMENT '采集信息格式id',
  `business_id` int(5) DEFAULT '0' COMMENT '备注面向的公司id',
  `info` varchar(64) NOT NULL COMMENT '设备采集到数据的单位',
  `maker` varchar(127) DEFAULT NULL COMMENT '制造商',
  `phone` char(11) DEFAULT NULL COMMENT '联系方式',
  `ctime` int(10) DEFAULT '0' COMMENT  '安装时间',
  `flag` tinyint(1) DEFAULT '0' COMMENT '是否有效',
  PRIMARY KEY (`id`),
  UNIQUE (`dev_id`),
  KEY `db_id` (`dev_id`,`business_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT '设备表';

#添加设备时候可以指定部门id,不指定的话归属于公司，之后某个部门可以更新到自己部门下；
CREATE TABLE `iot_dev` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `dev_id`  int(10) NOT NULL COMMENT '设备唯一标识符', 
  `devname` varchar(64) NOT NULL COMMENT '设备名字',
  `data_type_id` int(10) NOT NULL COMMENT '采集信息格式id',
  `business_id` int(5) DEFAULT '0' COMMENT '备注面向的公司id',
  `department_id` int(5) DEFAULT '0' NOT NULL COMMENT '所属部门id',
  `info` varchar(64) NOT NULL COMMENT '设备采集到数据的单位',
  `maker` varchar(127) DEFAULT NULL COMMENT '制造商',
  `phone` char(11) DEFAULT NULL COMMENT '联系方式',
  `ctime` int(10) DEFAULT '0' COMMENT  '安装时间',
  `flag` tinyint(1) DEFAULT '0' COMMENT '是否有效',
  PRIMARY KEY (`id`),
  KEY `dev_id` (`dev_id`),
  UNIQUE (`dev_id`),
  KEY `bd_id` (`business_id`,`department_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT '设备表';

# 根据data_type表中字段命名，并确定属性格式;添加设备时发现没有该类型的数据表
# 时，手动创建一个。
CREATE TABLE `iot_typeid_data` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `devid`   int(10) NOT NULL COMMENT '设备唯一标识符', 
  `data1` char(10) NOT NULL COMMENT '采集到的信息',
  `ctime` int(10) DEFAULT '0' COMMENT  '采集时间',
  `flag` tinyint(1) DEFAULT '0' COMMENT '是否有效',
  PRIMARY KEY (`id`),
  KEY `devid` (`devid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT '信息表';

#项目记录表；
#对应的项目是项目名前缀：iot_businessid_departid
CREATE TABLE `iot_project` (
  `project_id` int(10) NOT NULL AUTO_INCREMENT,
  `department_id` int(5) NOT NULL COMMENT '部门id',
  `project_name` varchar(64) DEFAULT NULL COMMENT '项目名',
  `owner_id` int(10) NOT NULL COMMENT '负责人id',
  `muser_id` int(10) DEFAULT '0' COMMENT '记录最后修改人',
  `ctime` int(10) DEFAULT '0',
  `mtime` int(10) DEFAULT '0',
  `authority` tinyint(1) DEFAULT '0' COMMENT '预留权限字段', 
  `flag` tinyint(1) DEFAULT '0',
  UNIQUE (`project_name`),
  PRIMARY KEY (`project_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=5 ;

#员工项目映射表
CREATE TABLE `iot_user_project` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `project_id` int(10) NOT NULL,
  `user_id` int(10) NOT NULL,
  `join_time` int(10) DEFAULT '0',
  `flag` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `pu_id` (`project_id`, `user_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=5 ;

CREATE TABLE `iot_dev_project` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `project_id` int(10) NOT NULL,
  `dev_id` int(10) NOT NULL,
  `flag` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `pd_id` (`project_id`, `dev_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=5 ;
