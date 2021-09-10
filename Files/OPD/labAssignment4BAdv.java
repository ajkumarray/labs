class Person
{
    String name;
    Person(String name)
    {
        this.name = name;
    }
}
class Student extends Person
{
    int rollNo;
    Student(String name, int rollNo)
    {
        super(name);
        this.rollNo = rollNo;
    }
}
class Teacher extends Person
{
    double salary;
    String subject;
    Teacher(String name, double salary, String subject)
    {
        super(name);
        this.salary = salary;
        this.subject = subject;
    }
    void showInfo()
    {
        System.out.println("Name of teacher: "+name+" salary: "+salary+" teaching subject: "+subject);
    }
}
class CollegeStudent extends Student
{
    int year;
    String major;
    CollegeStudent(String name, int rollNo, int year, String major)
    {
        super(name,rollNo);
        this.year = year;
        this.major = major;
    }
    void showInfo()
    {
        System.out.println("Name of student: "+name+" Roll Number: "+rollNo+" currently in year: "+year+" with major: "+major);
    }
}

public class labAssignment4BAdv {
    public static void main(String[] args)
    {
        Teacher teacher = new Teacher("AK Ray",80000,"Software Engineering");
        teacher.showInfo();
        CollegeStudent student = new CollegeStudent("Ajit Kumar",15163,2,"IT");
        student.showInfo();

    }
}
