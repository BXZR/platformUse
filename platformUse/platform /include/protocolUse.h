#ifndef __protocolUse_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __protocolUse_H__   //就定义__XXX_H__

//这个类保管所有的socket操作中具体具体的操作
//包括，数据库，redis,log以及自身的协议解析等等
//其余的操作需要在本类之外的总控制中实现

//下面这些引用没有必要有，我在这里列出来是为了记录这个类使用了这些头文件包装的功能
//所有由我编写的Use头文件都只会在operate.cpp里面引用
//#include"redisUse.h" 
//#include"dataBaseUse.h" 
//#include"logUse.h" 


//#include"record.h"//暂时无视配置文件
#include <string.h>
#include <iostream>
#include <sstream>//我用的是这种方法做的字符串分割，因为实现上貌似比较简洁
using namespace std;

class protocolUse
{

 public:
  void InitTheProtocolModule( DBController theDBCIn , logController theLogIn , redisUse theRedisCIn )
  {
    theLogC = theLogIn ;
    theDBC = theDBCIn;
    theRedisC = theRedisCIn ;
    makeLogShow(1,"协议处理模块初始化完成");
  }

  void getString(string information)
  {
    //在这里应该做一个区分的

    //这个下面是面对协议的，从下面收到了一些东西之后进行解析转化存数据库的过程在这里实现
    //按照要求切成字符串数组
    string * theStringClips = stringSplite(information);
    int theStringClipsLength = getStringClipCount(information);

    //for(int i=0;i<theStringClipsLength;i++)
    //cout<<theStringClips[i]<<"-----"<<endl;
    //string kind = theStringClips[1];//标记，1号位值记录命令
    //cout<< record:: commandKinds[1] << "-LL"<<endl;
     if(theStringClipsLength >=2)//数据太短就暂时不管了
    {
        //终极调用方法，这个方法其实在扩展的时候很有问题
         operate(theStringClips,theStringClipsLength );
    }
    else
    {
       makeLogShow(4 , "获取的信息不足，无法操作");
    }
  }


  private:
    
    int commandCount = 12;
    string commandKinds[12]  = {"1000" , "1001" ,"1002" , "1003" , "2000" ,"2001" , "2002" , "2003" , "2004" , "2005" , "3000" , "3001"};

    logController  theLogC ;//日志文件控制器
    DBController theDBC;//数据库控制器
    redisUse theRedisC;//redis控制器
     //这个方法私人订制吧，因为我不能确定所有的模块现实的方式都是一样的）   
    void makeLogShow(int type,string theinformation)//控制台输出+日志输出（
    {
           cout<<theinformation<<endl;  //额外输出到控制台
           theLogC.makeLogWithFlush(type,theinformation);//额外输出日志
    }

    //统一使用，切分成数组大法，返回的是切分好的字符串数组（我们可能不知道它的长度，这个长度可以通过协议编号查询得到）
    string * stringSplite(string information)
    {
     int index = 0;
     int countNeed = 0;
     string * theStringClips;
     string sub_str;

     stringstream ssForCount(information);
     stringstream ss(information);

     //以;为间隔分割test的内容
     //遇到第一个\0就算是结束了正好与协议的结尾内容相同
     while(getline(ssForCount,sub_str,';')) 
       countNeed ++;
     theStringClips = new  string [countNeed];     
     while(getline(ss,sub_str,';')) 
     {
       theStringClips [index] = sub_str;
       index ++;
      }

    return theStringClips;
   }
   
   //简化方法，仅仅获取切分字符串数组的长度
   //比较土的方法
   int getStringClipCount(string information)
   { 
      int countNeed = 0;
      stringstream ssForCount(information);
      string sub_str;
      while(getline(ssForCount,sub_str,';')) 
       countNeed ++;
      return countNeed;
   }
    

   float stringToFloat(string str)
   {
     float f=atof(str.c_str());
     return f;
    //这种写法仅仅是为了展示结构
   } 
   int stringToInt(string str)
   {
     float i=atoi(str.c_str());
     return i;
    //这种写法仅仅是为了展示结构
   }  
//------------------------------------------------这下面是针对一些类型的传输内容的处理操作------------------------------------------------------------------
    
   //这个类的终极底层操作方法，给出int作为区分
   //注意名称的匹配
   //这个方法太恶心了，真心不推荐
   void operate(string * theInformations ,int length)
   {

      if(theInformations[1] == commandKinds[0])
      {
         operate_1000(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[1])
      {
         operate_1001(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[2])
      {
         operate_1002(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[3])
      {
         operate_1003(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[4])
      {
         operate_2000(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[5])
      {
         operate_2001(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[6])
      {
         operate_2002(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[7])
      {
         operate_2003(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[8])
      {
         operate_2004(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[9])
      {
         operate_2005(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[10])
      {
         operate_3000(theInformations , length);
      }
      else if(theInformations[1] == commandKinds[11])
      {
         operate_3001(theInformations , length);
      }
      else
      {
        makeLogShow(4 , "找不到方法："+theInformations[1]);
      }  
     

   }


   //接下来的方法分别是每一种协议数据解析的子方法，仅仅是一个权宜之计
   //此外，因为规定已经很严格了，我这里直接使用下标进行访问数据
   //难点：怎么将这些方法进行整合？在这里罗列方法只是对代码的浪费了......

   /*
	数据包命令字段：1000
        数据字段1：设备ID
   */
   void operate_1000(string * information,int length)
   {
     if(length ==3)//开头，类型，数据1
     {
     int deviceID =  stringToInt(  information[2]);
     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_1000 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }


    /*
	数据包命令字段：1001
	数据字段1：设备ID
	数据字段2：数据类型(温湿度等)
	数据字段3：采集的数据(整数浮点数均可)
    */

   //str.assign(base, 10, 9);    //取出下标10开始的9长度的子串
   // str.assign("pangrams are cool", 7);  //取出前7位的子串
   void operate_1001(string * information,int length)
   {
     if(length ==5)//开头，类型，数据1，数据2，数据3
     {
     string theID = information[2];
     int dataTypeID = stringToInt(information[3]);
     string data = information[4];
     //ID的排布样式位10位，前4位位公司ID，中间两位是数据类型ID（似乎现在没有使用，预留），最后是公司内部的设备ID
     string businessID ;
     businessID.assign (theID ,0, 4);
     string typeID;
     typeID.assign (theID, 4,2);
     string deviceID;
     deviceID.assign(theID ,6,4);
    // cout<< "获得的ID - "+ theID<<endl;
    // cout<<"切分结果 - "+ businessID +" - " + typeID +" - "+ deviceID<<endl;

     theDBC .insertDataValues( typeID ,theID, information , length);
     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_1001 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }

  /*
	数据包命令字段：1002
	数据字段1：设备ID(受控方)
	数据字段2：开关标记
  */
     void operate_1002(string * information,int length)
   {
     if(length ==4)//开头，类型，数据1，数据2
     {
     int deviceID =  stringToInt(  information[2]);
     int switchOpen = stringToInt(  information[3]);
  

     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_1002 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }

 /*
	数据包命令字段：1003
	数据字段1：设备ID(受控方)
	数据字段2：频率
 */
     void operate_1003(string * information,int length)
   {
     if(length ==4)//开头，类型，数据1，数据2
     {
     int deviceID =  stringToInt(  information[2]);
     int frequency = stringToInt(  information[3]);
  

     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_1003 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }

  /*
	数据包命令字段：2000
	数据字段1：汇聚节点设备ID
	数据字段2：Zigbee终端设备ID
	数据字段3：采集的数据(整数浮点数均可)
  */
    void operate_2000(string * information,int length)
   {
     if(length ==5)//开头，类型，数据1，数据2, 数据3 
     {
     int deviceRootID =  stringToInt(  information[2]);
     int deviceID =  stringToInt(  information[3]);
     string  data =   information[4];

     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_2000 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }
  
 /*
	数据包命令字段：2001
	数据字段1：汇聚节点设备ID
 */
    void operate_2001(string * information,int length)
   {
     if(length ==3)//开头，类型，数据1
     {
     int deviceRootID =  stringToInt(  information[2]);
     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_2001 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }

/*
	数据包命令字段：2002
	数据字段1：设备ID
	数据字段2：开关标记
*/
    void operate_2002(string * information,int length)
   {
     if(length ==4)//开头，类型，数据1，数据2, 数据3 
     {
     int deviceID = stringToInt(  information[2]);
     int switchType = stringToInt(  information[3]);

     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_2002 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }

/*
	数据包命令字段：2003
	数据字段1：设备ID
	数据字段2：频率
*/
    void operate_2003(string * information,int length)
   {
     if(length ==4)//开头，类型，数据1，数据2 
     {
     int deviceID = stringToInt(information[2]);
     int frequency = stringToFloat(  information[3]);

     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_2003 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }

/*
  	数据包命令字段：2004
	数据字段1：增添的设备ID
*/
   void operate_2004(string * information,int length)
   {
     if(length ==3)//开头，类型，数据1
     {
     int deviceID = stringToInt(information[2]);
     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_2004 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }
/*
  	数据包命令字段：2005
	数据字段1：删除的设备ID
*/
   void operate_2005(string * information,int length)
   {
     if(length ==3)//开头，类型，数据1
     {
     int deviceID = stringToInt(information[2]);
     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_2005 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }


/*
	数据包命令字段：3000
	数据字段1：增添的设备ID
	数据字段2：设备类型(Zigbee、汇聚节点或其他)
	数据字段3：企业ID
	数据字段4：部门ID
        数据字段5：部门ID
*/
    void operate_3000(string * information,int length)
   {
     if(length ==7)//开头，类型，数据1，数据2, 数据3, 数据4, 数据5
     {
     int deviceRootID =  stringToInt(  information[2]);
     int deviceTypeID = stringToInt(information[3]);
     int companyID = stringToInt(  information[4]);
     int departmentID = stringToInt(  information[5]);
     int projectID = stringToInt(  information[6]);
     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_3000 解析完成");
      return ;
     }
     makeLogShow(4,"operate_3000数据格式不正确，无法解析。");
   }

/*
	数据包命令字段：3001
	数据字段1：删除的设备ID
	数据字段2：设备类型
*/
 void operate_3001(string * information,int length)
   {
     if(length ==4)//开头，类型，数据1，数据2, 数据3 
     {
     int deviceID =  stringToInt(  information[2]);
     int deviceTypeID = stringToInt(information[3]);

     //接下来应该是缓存和数据库的操作
      makeLogShow(0,"operate_3001 解析完成");
      return ;
     }
     makeLogShow(4,"数据格式不正确，无法解析。");
   }

};
 



















#endif       //否则不需要定义
