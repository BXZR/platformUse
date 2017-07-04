/*
*FM201705240915
*整个工程的入口类，也是唯一的总体操作类 
*作为一个main脚本其实什么都不用做，调用已经写好的类就是唯一的职责（注意这里的封装）
*/


//所有我编写的Use头文件原则上都只会在这里引用
//这里的调用顺序不可以被打乱
#include"logUse.h" 
#include"redisUse.h" 
#include"dataBaseUse.h" 
#include"socketUse.h"
#include"protocolUse.h"
#include"commandUse.h"

#include <unistd.h>

 logController  theLogC ;//日志文件控制器
 DBController theDBC;//数据库控制器
 redisUse theRedisC;//redis控制器（类名称暂时不统一是因为我认为这个不算是模块，更像是一种插件）
 socketController theSocketC;//socket控制器
 protocolUse theProcolC;//协议处理方法
 CommandUse theCommandC;//命令处理方法
//这之下是各个模块的测试方法
 
    //协议解析的测试方法
    void playForProtocoUse()
    {
         //协议用的测试
         //theProcolC .getString("0x17;1000;12;\0");
	 //theProcolC .getString("0x17;1001;10;10;10.2;\0");
	 //theProcolC .getString("0x17;1002;10;10;\0");
	 //theProcolC .getString("0x17;1003;10;100;\0");
	 //theProcolC .getString("0x17;2000;10;10;100;\0");
	 //theProcolC .getString("0x17;2001;17;\0");
	 //theProcolC .getString("0x17;2002;10;10;\0");
	 //theProcolC .getString("0x17;2003;10;19;\0");
	 //theProcolC .getString("0x17;2004;102;\0");
	 //theProcolC .getString("0x17;2005;103;\0");
	 //theProcolC .getString("0x17;3000;10;10;10;12;5;\0");
	 //theProcolC .getString("0x17;3001;10;10;\0");
        
         //入库用测试
         theProcolC .getString("0x17;1001;1000011000;10;10.2;\0");
         theProcolC .getString("0x17;1001;1000012000;10;9989;\0");
         theProcolC .getString("0x17;1001;1000013000;10;343;\0");
    }

/*
日志文件标题类型如下（更新log类的时候注意这里的更新）
默认 [info] 信息
1 [info] 信息
2 [warn] 警告
3 [debug]调试
4 [erro]错误
*/
    void playForLog()
	{
	    theLogC.makeLog(0,"战斗吧!!!__"+ to_string(11));
	    theLogC.makeLog(1,"为了宇宙和平!!!__"+ to_string(22));
	   theLogC.makeLog(2,"中二病拯救世界!!!__"+ to_string(33));
	   theLogC.makeLog(3,"男人不二怎么行!!!__"+ to_string(44));
	    theLogC.makeLog(4,"真理就在这里!!!__"+ to_string(55));
            cout<<"\n-------日志测试成功-------\n"<<endl;
	}
   void playForDB()//数据库模块测试方法
	{
	  //theDBC.DBQuery("insert into test values ('jujietou4','shenyiyang5')");
	 // theDBC.DBSelect("select * from test")  ;
 
	 theDBC.makeDepartmentTable(1000);
	 theDBC.makeUserTable(1000);
	 theDBC.makeDevTable(1000);
	 theDBC.makeDataTable(1000);//这个比较特殊，目前的参数表只有businessID, 后期应该会加上typeID
	 theDBC.makeProjectTable(1000);
            cout<<"\n--------数据库测试成功-------\n"<<endl;

	}
   void playforRedis()//Redis模块测测试方法
	{
	   if(theRedisC.isExistKey("suck") )
               cout<< theRedisC.getValueWithKey("suck") ;
           else
              theRedisC.makeNew("suck","zheshizhenli");
            cout<<"\n-------缓存测试成功--------\n"<<endl;
	}
   void playforSocket()//socket测试方法
	{
            /*
	    while(1)
		 { 
		  theSocketC. acceptSocket();//获取到目标socket
		   while(1)
		   {
		      	string receiveString = theSocketC.getInformation();
		        cout<<"<<<<<<<<"<<receiveString<<endl;
		        //发送信息
		       theSocketC. sendInformation("少年，买碟吗？"); 
	  
		        if(receiveString ==""||receiveString =="Quit" ||receiveString == "quit")//给出结束的符号
			{
			  break;
			}
		      
		
		     }
			theSocketC.closeClient();
		        break;
		    }
		 
		   theSocketC.closeServer();	    
		 //方法终结位置
                */
	}

///////////////////////////////////
void makeLog(int type,string information)
{
      cout<<information<<endl;  //额外输出到控制台
      theLogC.makeLogWithFlush(type,information);//额外输出日志
}



int client_fd=0; 
pthread_t tid;  
sockaddr_in client_addr;  
socklen_t socklen = sizeof(client_addr); 
unsigned client_port=0;  
char client_ip[20]; 

 
void *run(void *arg)
    {
         int client_fd = *((int*)&arg);  
         bool canRun =true;
	 while(canRun)
	 {
	  string receiveString = theSocketC.getInformation(client_fd);
        
	   if(receiveString ==""||receiveString =="Quit" ||receiveString == "quit")//给出结束的符号
	   {
	        theSocketC. closeClient(client_fd);
                canRun = false;
		break;
	    }
           /*************************接下来是所有操作的整合（这个系统的最上层就在这里了）***************************/
           //// string theStringGet =  theOpreteC .makeString(receiveString );
           //翻译字符串，这个有可能需要用一个额外的类或者结构来存储信息，在这里只是最简单的一个转换功能作为例子（毕竟要根据协议来）
           ////  theDBC.DBQuery("insert into test values ('"+receiveString+"','"+theStringGet+"')");//插入数据库
	    //theDBC.DBSelect("select * from test")  ;//查询一波看看查没插进去
           //// if(!theRedisC.isExistKey(receiveString) )
           ////   theRedisC.makeNew(receiveString,theStringGet);//插入，但是插入个后到底干什么还不知道
            theProcolC . getString(receiveString);
            /******************************************************************************************************/
	    //theSocketC.sendInformation(client_fd,"information geted"); 


            //如果有命令需要对某硬件进行操控
            string command = theCommandC .setInformation(receiveString);
            theSocketC.sendInformation(client_fd, command ); 
            
         }
    }

void server()
{
    makeLog(1,"服务器正式启动，开始侦听端口......");
    cout<<"-----------------------------------------------------------"<<endl;
    while(1)  
    {  
        //client_fd = accept(fd,(struct sockaddr *)&client_addr,&socklen);
        client_fd = theSocketC.acceptSocket();
        if(client_fd<0)  
        {  
            makeLog(4,"并没有被接受服务器被迫停止，原因有可能是端口被占用，请重试");
            theSocketC. closeServer(); 
            return;  
        }  
        //新线程
        pthread_create(&tid,NULL,run,(void *)client_fd);  
        pthread_detach(tid);  
    }  
       theSocketC. closeServer(); 
}

int main()
{
	  theLogC.InitTheLogModule("./log/");//Log模块初始化
	  //参数是要存日志makeLog的目录
          
          //不断删除和生成的测试数据库 "demos"
          //测试用数据库 "platformUse"
          //留待扩展的数据库数据库 "platformIOT"
          //暂时正式使用的数据库icpscloud
	 theDBC.InitTheDBModule(theLogC,"localhost","root","root","demos");//数据库模块的初始化
	 //参数从左到右分别是：log模块控制器，目标主机，用户名，密码，要用到的数据库名字
	 theRedisC.InitRedisModule(theLogC,"127.0.0.1",6379);//redis模块初始化
	 //参数为，log模块控制器，目标主机，端口号
	 theSocketC.InitTheSocketModule(theLogC,10005);//socket模块初始化
         //参数为  DB模块控制器 log模块控制器 redis模块控制器
         theProcolC.InitTheProtocolModule(theDBC , theLogC , theRedisC );
	 //上面这些是必要的初始化，测试方法和运行方法怎么玩都行，这里一定不能缺项，而且要保证顺序

        //playForLog(); //日志测试方法
       //  playForDB();//数据库模块测试方法
        //playforRedis();//Redis模块测测试方法 
         playForProtocoUse();//协议解析测试方法
         server();//服务器方法，真正地开启这个服务器
        //最核心的功能就是入库，其他的都是到时候扩展就好
        //可以考虑的点：网络连接/入库/库表

return 0;
}
