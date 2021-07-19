//  labAssignment9B1

//  class of salesPersons
class SalesPerson extends Thread {
    // array of salesPerson
    private String[] names = { "Ajit", "Kumar", "Ray", "Raj", "Ram" };

    @Override
    public void run() {
        for (String name : names) {
            System.out.println(name);
            try {
                sleep(500);
            } catch (InterruptedException e1) {
                e1.printStackTrace();
            }
        }
    }
}

// class of Days
class Days extends Thread {
    // array of days
    private String[] days = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    @Override
    public void run() {
        SalesPerson salesPersons = new SalesPerson();
        salesPersons.start();
        for (String day : days) {
            System.out.println(day);
            try {
                sleep(500);
            } catch (InterruptedException e1) {
                e1.printStackTrace();
            }
            if (day.equals("Sunday")) {
                System.out.println("\tSuspending sales");
                salesPersons.suspend();
                try {
                    sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            if (day.equals("Wednesday")) {
                System.out.println("\tResuming sales");
                salesPersons.resume();
            }
        }
    }
}

public class labAssignment9B {
    public static void main(String[] args) {
        Days days = new Days();
        Thread thread = new Thread(days);
        thread.start();
    }
}