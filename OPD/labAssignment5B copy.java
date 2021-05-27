class Fruit
{
    String name;
    String taste;
    String size;

    Fruit(String name, String taste, String size)
    {
        this.name = name;
        this.taste = taste;
        this.size = size;
    }
    void eat()
    {
        System.out.println(name+" is a "+size+" sized Fruit with "+taste+" taste.");
    }
}

class Apple extends Fruit
{
    Apple(String size)
    {
        super("Apple", "sweet-tart", size);
    }
    //overriding eat() method
    void eat()
    {
        System.out.println(name+" is a "+size+" sized Fruit with "+taste+" taste.");
    }
}

class Orange extends Fruit
{
    Orange(String size)
    {
        super("Orange", "sweet-sour-tart", size);
    }
    //overriding eat() method
    void eat()
    {
        System.out.println(name+" is a "+size+" sized Fruit with "+taste+" taste.");
    }
}

public class labAssignment5B {
    public static void main(String[] args)
    {
        Fruit f1 = new Fruit("Mango", "sweet", "medium-oval");
        f1.eat();

        Apple f2 = new Apple("small-round");
        f2.eat();

        Orange f3 = new Orange("big-round");
        f3.eat();
    }
}
