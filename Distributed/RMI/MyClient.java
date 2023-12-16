import java.rmi.*;

public class MyClient{

public static void main(String args[]){
try{

Adder stub=(Adder)Naming.lookup("rmi://localhost:5000/swayam");
System.out.println(stub.add(123,99));

}catch(Exception e){System.out.println(e);}
}

}