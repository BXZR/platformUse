#ifndef __redisUse_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __redisUse_H__   //就定义__XXX_H__
//因为我的思路是尽可能简化早期功能耦合，所以这些功能大多写在头文件，这个方法是头文件保护，预防重复引用
#include"logUse.h"
#include<iostream>
#include <hiredis/hiredis.h>
#include <string>

using namespace std;

//Redis操作类，在运行之前应该记得开启redis(redis-server)，否则可能会出现连接不上的错误
class redisUse
{
   public:
     void InitRedisModule( logController &theLogControlerIn,string theServerIP,int thePort)
    {
      //redis默认监听端口为6387 可以再配置文件中修改
     theLogControler = theLogControlerIn;//日志控制器的引用保有
     // conn = redisConnect("127.0.0.1",6379);//这个是最原始的初始化格式，只不过是又包了一层
     connection = redisConnect( theServerIP.c_str(),thePort);
     if(connection->err)//尝试进行连接
     {
       makeLogShow(4,"Redis模块"+connection->err);
     }
     else
     { 
     makeLogShow(1,"Redis模块已经启动");
     }
    }
    //在彻底结束的时候调用，类似OnDestory方法
    //有些东西真的是手动操作才放心
    void Over()
    {
      redisFree(connection);
    }
    
      //加入新的记录，传入参数key 和 value
     void makeNew(string key,string value)
     { 
        redisReply* reply = (redisReply*)redisCommand(connection,("set "+key +" "+value).c_str());
	if(strcmp(reply->str ,"OK") == 0)
	{
           makeLogShow(1,"Key("+key+")-Value("+value+")插入成功");   
        }
        else
	{
	   makeLogShow(4,"Key("+key+")-Value("+value+")插入失败");   
	}
         freeReplyObject(reply);
     }
    
    //通过key返回string的value
    string getValueWithKey(string key)
    {
        string toReturn ="";
        redisReply*  reply = (redisReply*)redisCommand(connection,("get "+key).c_str());
         toReturn =reply->str;
          makeLogShow(1,"查询到Key("+key+")对应的value为"+toReturn);
        freeReplyObject(reply);
        return toReturn;
    } 
    //查询是否存在的方法，传入参数key 
    bool isExistKey(string key)
    {
       bool toReturn = false;//返回值
       redisReply* reply = (redisReply*)redisCommand(connection,("exists "+key).c_str());//拼接字符串
       if(reply->integer == 1)
       {
          makeLogShow(1,"Key("+key+")查询存在");
          toReturn = true;   
       }
       else
       {
          makeLogShow(2,"Key("+key+")查询并不存在");
          toReturn = false; 
       }
        freeReplyObject(reply);
       return toReturn;
    }
    /*
     *不同命令返回值和返回值的类型不同
     *不同类型的返回值存在于不同的结构体项目中
     *命令太多只能差文档
     *pReply->integer
     *pReply->str
    */
     
   private:
   logController theLogControler;//日志文件控制对象，在初始化的时候获取引用，并从内部使用来写日志
    redisContext* connection;//与redis的连接
     //这个方法私人订制吧，因为我不能确定所有的模块现实的方式都是一样的）   
     void makeLogShow(int type,string theinformation)//控制台输出+日志输出（
       {
           cout<<theinformation<<endl;  //额外输出到控制台
           theLogControler.makeLogWithFlush(type,theinformation);//额外输出日志
       }
    


     
    
};




#endif
