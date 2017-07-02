#ifndef __dataBaseUse_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __dataBaseUse_H__   //就定义__XXX_H__
//因为我的思路是尽可能简化早期功能耦合，所以这些功能大多写在头文件，这个方法是头文件保护，预防重复引用

//下面这些引用没有必要有，我在这里列出来是为了记录这个类使用了这些头文件包装的功能
//所有由我编写的Use头文件都只会在operate.cpp里面引用
//#include"logUse.h"

#include<iostream>
#include<mysql/mysql.h>


using namespace std;

class DBController
{
    public:
      //初始化数据库模块，其实这个模块的也就是一个操作集合
      //传入的参数中还有日志控制器（日志控制器每一个模块都会引用一个）
      void InitTheDBModule( logController &theLogControlerIn, string hostIP,string user,string password,string database) 
      {
        theLogControler = theLogControlerIn;//日志控制器的引用保有
        mysql_init(&connection);//没有这一步就连不上数据库
        makeLogShow(1,"尝试初始化数据库模块");
        //根据参数连接数据库
        if(mysql_real_connect(&connection,hostIP.c_str(),user.c_str(),password.c_str(),database.c_str(),0,NULL,0))
        { 
            makeLogShow(1,"数据库连接成功");
        }
        else
       {
         makeLogShow(4,"数据库连接失败");
       }
       makeLogShow(1,"数据库模块已经启动");
      }
      
      //--------------------------------------------------打包的建表操作--------------------------------------------------------//
      //说明： 这些方法有可能永远不会使用，并且因为现在在设定初期，参数表未必同意，因此没有再做额外的封装 
      //动态建立公司部门表
      /*
           CREATE TABLE `iot_businessid_department`(
	  `department_id` int(5) NOT NULL AUTO_INCREMENT,
	  `department_name` varchar(32) NOT NULL COMMENT '部门名称',
	  `manager_id` int(5) DEFAULT '0' COMMENT '部门经理id',
	  `ctime` int(10) DEFAULT '0',
	  `flag` tinyint(1) DEFAULT '0' COMMENT '预留字段',
	  PRIMARY KEY (`department_id`)
	) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=100 ;
      */
      void makeDepartmentTable(int businessid)
      {
	 string theMakeStringt =
          "  CREATE TABLE `iot_"+to_string(businessid )+"_department`"+
          "( `department_id` int(5) NOT NULL AUTO_INCREMENT,"+
          "`department_name` varchar(32) NOT NULL COMMENT '部门名称',"+
	  "`manager_id` int(5) DEFAULT '0' COMMENT '部门经理id',"+
	  "`ctime` int(10) DEFAULT '0',"+
	  "`flag` tinyint(1) DEFAULT '0' COMMENT '预留字段',"+
	  "PRIMARY KEY (`department_id`)"+
	  ") ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=100 ;";
           DBQuery(theMakeStringt);
      }
      //动态建立公司的人员表
      /*
           CREATE TABLE `iot_businessid_user` (
	  `user_id` int(10) NOT NULL AUTO_INCREMENT,
	  `login_id` int(10) DEFAULT '0' NOT NULL,
	  `password` char(32) COLLATE utf8_unicode_ci NOT NULL,
	  `realname` char(6) COLLATE utf8_unicode_ci NOT NULL,
	  `department_id` int(5) NOT NULL,
	  `tel` char(11) COLLATE utf8_unicode_ci DEFAULT NULL,
	  `sex` char(2) COLLATE utf8_unicode_ci NOT NULL,
	  `email`    varchar(64) NOT NULL,
	  `authority` tinyint(1) DEFAULT '0',
	  `ctime` int(10) DEFAULT '0' NOT NULL,
	  `mtime` int(10) DEFAULT NULL,
	  `flag` tinyint(1) DEFAULT '0',
	  PRIMARY KEY (`user_id`),
	  KEY `department_id` (`department_id`)
	) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1000 ;
      */
      void makeUserTable(int businessid)
      {
	 string theMakeStringt =  
          "CREATE TABLE `iot_"+to_string(businessid )+"_user` ("+
	  "`user_id` int(10) NOT NULL AUTO_INCREMENT,"+
	  "`login_id` int(10) DEFAULT '0' NOT NULL,"+
	  "`password` char(32) COLLATE utf8_unicode_ci NOT NULL,"+
	  "`realname` char(6) COLLATE utf8_unicode_ci NOT NULL,"+
	  "`department_id` int(5) NOT NULL,"+
	  "`tel` char(11) COLLATE utf8_unicode_ci DEFAULT NULL,"+
	  "`sex` char(2) COLLATE utf8_unicode_ci NOT NULL,"+
	  "`email`    varchar(64) NOT NULL,"+
	  "`authority` tinyint(1) DEFAULT '0',"+
	  "`ctime` int(10) DEFAULT '0' NOT NULL,"+
	  "`mtime` int(10) DEFAULT NULL,"+
	  "`flag` tinyint(1) DEFAULT '0',"+
	  "PRIMARY KEY (`user_id`),"
	  "KEY `department_id` (`department_id`)"
	  ") ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1000 ;";
           DBQuery(theMakeStringt);
      }
      //动态建立公司的设备表
      /*
	   CREATE TABLE `iot_businessid_dev` (
	  `devid`  int(10) NOT NULL COMMENT '设备唯一标识符', 
	  `devname` varchar(64) NOT NULL COMMENT '设备名字',
	  `data_type_id` int(10) NOT NULL COMMENT '采集信息格式id',
	  `department_id` int(5) DEFAULT '0' NOT NULL COMMENT '所属部门id',
	  `info` varchar(64) NOT NULL COMMENT '设备采集到数据的单位'
	  `maker` varchar(127) DEFAULT NULL COMMENT '制造商',
	  `phone` char(11) DEFAULT NULL COMMENT '联系方式',
	  `ctime` int(10) DEFAULT '0' COMMENT  '安装时间',
	  `flag` tinyint(1) DEFAULT '0' COMMENT '是否有效',
	  PRIMARY KEY (`devid`),
	  KEY `department_id` (`department_id`)
	) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT '设备表';
      */
         void makeDevTable(int businessid)
         {
	 string theMakeStringt =  
   	  " CREATE TABLE `iot_"+to_string(businessid )+"_dev` ("+
	  "`devid`  int(10) NOT NULL COMMENT '设备唯一标识符',"+ 
	  "`devname` varchar(64) NOT NULL COMMENT '设备名字',"+
	  "`data_type_id` int(10) NOT NULL COMMENT '采集信息格式id',"+
	  "`department_id` int(5) DEFAULT '0' NOT NULL COMMENT '所属部门id',"+
	  "`info` varchar(64) NOT NULL COMMENT '设备采集到数据的单位' ,"+
	  "`maker` varchar(127) DEFAULT NULL COMMENT '制造商',"+
	  "`phone` char(11) DEFAULT NULL COMMENT '联系方式',"+
	  "`ctime` int(10) DEFAULT '0' COMMENT  '安装时间',"+
	  "`flag` tinyint(1) DEFAULT '0' COMMENT '是否有效',"+
	  "PRIMARY KEY (`devid`),"+
	  "KEY `department_id` (`department_id`)"+
          ")ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT '设备表';"
          ;
           DBQuery(theMakeStringt);
      }
      //动态建立公司的数据表
      /*
	   CREATE TABLE `iot_businessid_data` (
	  `data_id` int(10) NOT NULL AUTO_INCREMENT,
	  `devid`   int(10) NOT NULL COMMENT '设备唯一标识符', 
	  `data1` char(10) NOT NULL COMMENT '采集到的信息',
	  `ctime` int(10) DEFAULT '0' COMMENT  '采集时间',
	  `flag` tinyint(1) DEFAULT '0' COMMENT '是否有效',
	  PRIMARY KEY (`data_id`),
	  KEY `devid` (`devid`)
	  ) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT '信息表';
      */
       void makeDataTable(int businessid)//这个表待定在解析的地方还有必要处理，这个方法仅仅作为原型出现
         {
	 string theMakeStringt =  
          "CREATE TABLE `iot_"+to_string(businessid )+"_data` ("+
	  "`data_id` int(10) NOT NULL AUTO_INCREMENT,"+
	  "`devid`   int(10) NOT NULL COMMENT '设备唯一标识符',"+ 
	  "`data1` char(10) NOT NULL COMMENT '采集到的信息',"+
	  "`ctime` int(10) DEFAULT '0' COMMENT  '采集时间',"+
	  "`flag` tinyint(1) DEFAULT '0' COMMENT '是否有效',"+
	  "PRIMARY KEY (`data_id`),"+
	  "KEY `devid` (`devid`)"+
	  ") ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT '信息表';"
          ;
           DBQuery(theMakeStringt);
      }
      //动态创建公司项目表
      /*
	  CREATE TABLE `iot_businessid__project` (
	  `project_id` int(10) NOT NULL AUTO_INCREMENT,
	  `department_id` int(5) NOT NULL COMMENT '部门id',
	  `project_name` varchar(64) DEFAULT NULL COMMENT '项目名',
	  `owner_id` int(10) NOT NULL COMMENT '创建者',
	  `ctime` int(10) DEFAULT '0',
	  `mtime` int(10) DEFAULT '0',
	  `authority` tinyint(1) DEFAULT '0' COMMENT '预留权限字段', 
	  `flag` tinyint(1) DEFAULT '0',
	  PRIMARY KEY (`project_id`)
	  ) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=5 ;
      */
       void makeProjectTable(int businessid)//这个表待定在解析的地方还有必要处理，这个方法仅仅作为原型出现
         {
	 string theMakeStringt =  
          "CREATE TABLE `iot_"+to_string(businessid )+"_project` ("+
	  "`project_id` int(10) NOT NULL AUTO_INCREMENT,"+
	  "`department_id` int(5) NOT NULL COMMENT '部门id',"+
	  "`project_name` varchar(64) DEFAULT NULL COMMENT '项目名',"+
	  "`owner_id` int(10) NOT NULL COMMENT '创建者',"+
	  "`ctime` int(10) DEFAULT '0',"+
	  "`mtime` int(10) DEFAULT '0',"+
	  "`authority` tinyint(1) DEFAULT '0' COMMENT '预留权限字段', "+
	  "`flag` tinyint(1) DEFAULT '0',"+
	  "PRIMARY KEY (`project_id`)"+
	  ") ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=5 ;"
          ;
           DBQuery(theMakeStringt);
      } 

     //--------------------------------------------------打包的数据库操作--------------------------------------------------------//

       //向指定公司的指定表插入数据
       void insertDataValues()
       {
       }
    
      //没有返回值的操作人家已经打包好了，直接用(因为权限超级强大，慎用)
      //这个方法只是在增加新的数据的时候才可以使用，一般不会使用这种语句
      //当然，作为内部，这是一个究极的建表操作，因为有一些表是需要动态建立和删除的
      void DBQuery(string sql)//增删改都是一样的，传入sql语句就可以
      {
        if(mysql_query(&connection, sql.c_str()))
            makeLogShow(4,"数据操作失败");
        else 
            makeLogShow(1,"数据操作成功");
      }
      //说实话这个查询只不过就是后台验证是否正确操作了数据库
      //真正的前台调用不可能用这种方法进行，所以这个方法事实上也就算是自己看着玩的......
       void DBSelect(string sql)  
      {  
            mysql_query(&connection, sql.c_str());//首先需要将数据库操作字段“提交”到数据库
            MYSQL_RES *result;  
            MYSQL_ROW row; 
	    result = mysql_use_result(&connection); //这个看上去就是结果集 
	    while(row = mysql_fetch_row(result))//搜索所有的行
	    {  
	      for(int j=0; j < mysql_num_fields(result); j++)  //按列输出
	     {  
		  cout << row[j] << " ";
	     }  
		  cout << endl;  
	    }
		mysql_free_result(result);
      }

     private:
       MYSQL connection;//数据库连接对象引用
       logController theLogControler;//日志文件控制对象，在初始化的时候获取引用，并从内部使用来写日志
       //这个方法私人订制吧，因为我不能确定所有的模块现实的方式都是一样的）
       void makeLogShow(int type,string theinformation)//控制台输出+日志输出
       {
           cout<<theinformation<<endl;  //额外输出到控制台
           theLogControler.makeLogWithFlush(type,theinformation);//额外输出日志
       }
};



#endif       //否则不需要定义
