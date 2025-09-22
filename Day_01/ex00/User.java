public class User
{
    private int identifier;
    private String name;
    private double balance;

    User(int identifier, String name, double balance)
    {
        this.identifier = identifier;
        this.name = name;
        if (balance >= 0) {
            this.balance = balance;
        }
        else {
            System.err.println("Illegal Argument: Negative balance");
            balance = 0;
        }
    }

    public double getBalance()
    {
        return (this.balance);
    }

    public void setBalance(double balance)
    {
        if (balance >= 0) {
            this.balance = balance;
        }
        else {
            System.err.println("Illegal Argument: Negative balance");
        }
    }

    public String getName()
    {
        return (this.name);
    }

    public void printInfo()
    {
        System.out.printf("User info: id %d, name %s, balance %.2f\n", identifier, name, balance);
    }
}
