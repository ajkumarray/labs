class Account
{
    String holderName;
    int accNumber;
    double initialBalance;
    double currentBalence;
    String address;
    String accType;

    //constructor of Account class
    Account(String holderName, int accNumber, double initialBalance)
    {
        this.holderName = holderName;
        this.accNumber = accNumber;
        this.initialBalance = initialBalance;
        this.currentBalence = initialBalance;
        System.out.println("New Account initiated for\nName:"+holderName+"\nAccount Number: "+accNumber+"\nBalence: "+currentBalence);
    }
    
    //overloaded constructor of Account class
    Account(String holderName, int accNumber, String address, String accType, double currentBalence)
    {
        this.holderName = holderName;
        this.accNumber = accNumber;
        this.address = address;
        this.accType = accType;
        this.currentBalence = currentBalence;
        System.out.println("New "+accType+" Account initiated for\nName:"+holderName+"\nAccount Number: "+accNumber+"\nCurrent Balence: "+currentBalence);
    }
    void withdraw(double amount)
    {
        currentBalence -= amount;
        System.out.println(amount+" withdrew from Account Number: "+accNumber);
    }
    void deposit(double amount)
    {
        currentBalence += amount;
        System.out.println(amount+" deposited in Account Number: "+accNumber);
    }
    void getBalance()
    {
        System.out.println("Account Number: "+accNumber+" has Balance: "+currentBalence);
    }
}
public class labAssignment5A {
    public static void main(String[] args)
    {
        Account a1 = new Account("Ajit Kumar", 15163, 50000);
        a1.deposit(20000);
        a1.getBalance();
        a1.withdraw(10000);
        a1.getBalance();

        Account a2 = new Account("Ajit Kumar", 15163, "Danapur Cantt", "Savings", 60000);
        a2.deposit(10000);
        a2.getBalance();
        a2.withdraw(20000);
        a2.getBalance();
    }
}