
//OPD Lab Assignment 7A
import java.util.*;

abstract class Compartment {
    public abstract void notice();
}

class FirstClass extends Compartment {
    @Override
    public void notice() {
        System.out.println("Notice: You are in FirstClass");
    }
}

class General extends Compartment {
    @Override
    public void notice() {
        System.out.println("Notice: You are in General");
    }
}

class Ladies extends Compartment {
    @Override
    public void notice() {
        System.out.println("Notice: You are in Ladies");
    }
}

class Luggage extends Compartment {
    @Override
    public void notice() {
        System.out.println("Notice: You are in Luggage");
    }
}

public class labAssignment7A {
    public static void main(String[] args) {
        Compartment[] compartments = new Compartment[10];
        Random rand = new Random();

        for (int i = 0; i < 10; i++) {
            int randomNum = rand.nextInt(4) + 1;

            if (randomNum == 1)
                compartments[i] = new FirstClass();
            else if (randomNum == 2)
                compartments[i] = new Ladies();
            else if (randomNum == 3)
                compartments[i] = new General();
            else if (randomNum == 4)
                compartments[i] = new Luggage();

            compartments[i].notice();
        }
    }
}