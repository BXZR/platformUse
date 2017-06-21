#ifndef __operates_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __operates_H__   //就定义__XXX_H__

//操作来自socket的数据的操作类
//获得字符串之后的转换等等

#include<iostream>
using namespace std;



class  theOperateController
{
   
   public:

    void InitTheOperateModule(logController theLogControlerIn)
    {
      theLogControler =  theLogControlerIn;
    }
   string makeString(string theIn)
   {
      return (theIn+"sucks!");
   }

   private:
      logController theLogControler;//日志文件控制对象，在初始化的时候获取引用，并从内部使用来写日志
       //这个方法私人订制吧，因为我不能确定所有的模块现实的方式都是一样的）
       void makeLogShow(string theinformation)//控制台输出+日志输出
       {
           cout<<theinformation<<endl;  //额外输出到控制台
           theLogControler.makeLogWithFlush(1,theinformation);//额外输出日志
       }
};




 



#endif       //否则不需要定义
