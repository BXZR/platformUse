#ifndef __protocolUse_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __protocolUse_H__   //就定义__XXX_H__

//这个类保管所有的socket操作中具体具体的操作
//包括，数据库，redis,log以及自身的协议解析等等
//其余的操作需要在本类之外的总控制中实现

#include"redisUse.h" 
#include"dataBaseUse.h" 
#include"logUse.h" 
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
    //按照要求切成字符串数组
    string * theStringClips = stringSplite(information);
    int theStringClipsLength = getStringClipCount(information);

    //for(int i=0;i<theStringClipsLength;i++)
    //cout<<theStringClips[i]<<"-----"<<endl;
    //string kind = theStringClips[1];//标记，1号位值记录命令
    //cout<< record:: commandKinds[1] << "-LL"<<endl;
     if(theStringClipsLength >=2)//数据太短就暂时不管了
    {

     for(int i=0;i<commandCount ;i++)
     {
       if( theStringClips[1] == commandKinds [i]  )//字符串比较
       {
         operate(i);//终极调用方法，这个方法其实在扩展的时候很有问题
         break;
       }
     }
    }
  }


  private:
    
    int commandCount = 10;
    string commandKinds[10]  = {"1000" , "1001" ,"1002" , "1003" , "2000" ,"2001" , "2002" , "2003" , "3000" , "3001"};

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
   //------------------------------这下面是针对一些类型的传输内容的处理操作----------------------------
    
   //这个类的终极底层操作方法，给出int作为区分
   void operate(int operateType)
   {
   }
};
 



















#endif       //否则不需要定义
