//class declaration
class Animal
{
    void eat()
    {
        System.out.println("This is eat() method of Animal class.");
    }
    void sleep()
    {
        System.out.println("This is sleep() method of Animal class.");
    }
}

class Bird extends Animal
{
    void eat()
    {
        System.out.println("This is eat() method of Bird class.");
    }
    void sleep()
    {
        System.out.println("This is sleep() method of Bird class.");
    }
    void fly()
    {
        System.out.println("This is fly() method of Bird class.");
    }
}

public class labAssignment4A
{
    public static void main(String[] args)
    {
        //instance of Animal class
        Animal animal = new Animal();
        animal.eat();  
        animal.sleep();

        //instance of Bird class
        Bird bird = new Bird();
        bird.eat();  
        bird.sleep();
        bird.fly();

    }
}