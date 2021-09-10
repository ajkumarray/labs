//OPD Lab Assignment 8B
public class labAssignment8B {
    public static void main(String[] args) {
        String n = args[0];
        int x = Integer.parseInt(args[1]);
        try {
            if (x < 18 || x > 60) {
                throw new AgeException("Age is not correct");
            } else {
                System.out.println("Name: " + n + "\n Age: " + x);
            }
        } catch (AgeException e) {
            System.out.println(e);
        }
    }
}

class AgeException extends Exception {
    public AgeException(String x) {
        super(x);
    }
}