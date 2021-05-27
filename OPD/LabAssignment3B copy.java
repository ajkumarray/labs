import java.util.*;

//class declaration
class Rectangle
{
    //instance variables
    double width;
    double length;
    double area;
    String color;

    void set_width(double width)        //method to set width of rectangle
    {
        this.width = width;
    }
    void set_length(double length)      //method to set length of rectangle
    {
        this.length = length;
    }
    void set_color(String color)        //method to set color of rectangle
    {
        this.color = color;
    }

    double findArea()                   //method to find area of rectangle
    {
        double area = width*length;
        return area;
    }
}

public class LabAssignment3B {
    public static void main(String[] args) {
        //creating object of Scanner class using new operator
        Scanner scan = new Scanner(System.in);

        //creating object of rectangle1 using new operator
        Rectangle rectangle1 = new Rectangle();
        //creating object of rectangle2 using new operator
        Rectangle rectangle2 = new Rectangle();

        //reading values of length, width and color of rectangle1
        System.out.print("Enter width of rectangle1: ");
        rectangle1.set_width(scan.nextDouble());
        System.out.print("Enter length of rectangle1: ");
        rectangle1.set_length(scan.nextDouble());
        System.out.print("Enter color of rectangle1: ");
        rectangle1.set_color(scan.next());
        //finding area of rectangle1
        double area1 = rectangle1.findArea();

        //reading values of length, width and color of rectangle2
        System.out.print("Enter width of rectangle2: ");
        rectangle2.set_width(scan.nextDouble());
        System.out.print("Enter length of rectangle2: ");
        rectangle2.set_length(scan.nextDouble());
        System.out.print("Enter color of rectangle2: ");
        rectangle2.set_color(scan.next());
        //finding area of rectangle2
        double area2 = rectangle2.findArea();

        //comparing area and color of both rectangles
        if(area1 == area2 && rectangle1.color.equals(rectangle2.color))
        {
            System.out.println("Matching Rectangles");
        }
        else
            System.out.println("Non Matching Rectangle");
    }
}