//class declaration
class Box 
{
    //instance variables
    double width;
    double height;
    double depth;

    //constructor declaration of class Box
    Box(double width, double height, double depth)
    {
        this.width = width;
        this.height = height;
        this.depth = depth;

    }
    //method to find volume of Box
    double volume ()
    {
        double vol = width*height*depth;
        return vol;
    }
}

public class LabAssignment3A {
    public static void main(String[] args)
    {
        //creating object using new operator
        Box box1 = new Box(2.0, 3.0, 4.0);
        System.out.println("The volume of Box with Width = "+box1.width+" Height = "+box1.height+" and depth = "+box1.depth+" is "+box1.volume());
        Box box2 = new Box(5.0, 6.0, 7.0);
        System.out.println("The volume of Box with Width = "+box2.width+" Height = "+box2.height+" and depth = "+box2.depth+" is "+box2.volume());
    }
}