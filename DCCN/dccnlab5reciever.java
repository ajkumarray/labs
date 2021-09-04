import java.io.*;
import java.net.*;
import java.util.*;

public class dccnlab5reciever {
    public static void main(String[] args) {
        final int MAX_LEN = 100;
        try {
            InetAddress host = InetAddress.getLocalHost();
            Scanner scan = new Scanner(System.in);
            System.out.println("\t\t---Reciever---");
            System.out.print("Enter the Port No.: ");
            int port = scan.nextInt();
            DatagramSocket socket = new DatagramSocket(port);
            socket.setSoTimeout(10000);
            byte[] buffer = new byte[MAX_LEN];
            DatagramPacket payload = new DatagramPacket(buffer, MAX_LEN);
            System.out.println("\nWaiting for Message to come ...");
            socket.receive(payload);
            String message = new String(buffer);
            System.out.println("\nNew Message: " + message);
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}