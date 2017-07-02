#ifndef __commandUse_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h
#define __commandUse_H__   //就定义__XXX_H__
//因为我的思路是尽可能简化早期功能耦合，所以这些功能大多写在头文件，这个方法是头文件保护，预防重复引用

//这个是上层web需要调用的方法类，用来控制硬件的开关等等内容
//由于调用的功能有可能很多，封装成成一个专门的类已备扩展


//流程：
//上层传来一个命令字符串，这里通过某种方式接收到了这个字符串
//通过这个字符串解析出来需要向某一个socket_FD传输的字符串
//这个类提供上层和下层的字符串传输中的解析和处理


#include <iostream>
#include<string.h>

using namespace std;

class CommandUse
{
 public:

     string setInformation(string information)
    {
       return information+"-operated";
    }


};

#endif       //否则不需要定义
