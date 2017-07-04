import org.apache.thrift.TException;  
import org.apache.thrift.protocol.TCompactProtocol;  
import org.apache.thrift.protocol.TProtocol;  
import org.apache.thrift.transport.TFramedTransport;  
import org.apache.thrift.transport.TNonblockingSocket;  
import org.apache.thrift.transport.TSocket;  
import org.apache.thrift.transport.TTransport;  
import org.apache.thrift.transport.TTransportException;  
  
//import UserService.Client;  
  
public class UserClient {  
    private void start() {  
        try {  
            TTransport socket = new TSocket("localhost", 9090);  
            //TTransport transport = new TFramedTransport(socket);  
            TProtocol protocol = new TCompactProtocol(socket);  
  
            UserService.Client client = new UserService.Client(protocol);  
            socket.open();  
            System.out.println(client.get("lll"));  
  
            User u = new User();  
            u.uid="leojava";  
            u.uname="yueyue";  
            u.usex=true;  
            u.uage=3;  
            client.add(u);  
            socket.close();  
  
        } catch (TTransportException e) {  
            e.printStackTrace();  
        } catch (TException e) {  
            e.printStackTrace();  
        }  
    }  
  
    public static void main(String[] args) {  
        UserClient c = new UserClient();  
        c.start();  
  
    }  
}  
