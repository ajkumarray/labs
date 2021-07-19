//  labAssignment9B2

class Even extends Thread {
    public void run() {
        int i = 2;
        System.out.println("Even numbers between 1 & 20 are:");
        while (i <= 20) {
            System.out.println(i);
            i += 2;
        }
    }
}

class Odd extends Thread {
    public void run() {
        int i = 1;
        System.out.println("Odd numbers between 1 & 20 are:");
        while (i < 20) {
            System.out.println(i);
            i += 2;
        }
    }
}

public class labAssignment9B2 {
    public static void main(String[] args) {
        Even even = new Even();
        Odd odd = new Odd();
        even.start();
        try {
            even.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        odd.start();
    }
}