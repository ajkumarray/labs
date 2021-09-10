import java.io.*;
import java.net.*;
import java.util.*;

public class dccnlab5sender {
    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(System.in);
            InetAddress recHost = InetAddress.getLocalHost();
            System.out.println("\t\t---Sender---");
            System.out.print("Enter your message: ");
            String message = scan.nextLine();
            System.out.print("Enter the Port No. of Reciever: ");
            int recPort = scan.nextInt();
            DatagramSocket socket = new DatagramSocket(9876);
            byte[] buffer = message.getBytes();
            DatagramPacket payload = new DatagramPacket(buffer, buffer.length, recHost, recPort);
            socket.send(payload);
            System.out.println("\t\t---Message sent---");
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}