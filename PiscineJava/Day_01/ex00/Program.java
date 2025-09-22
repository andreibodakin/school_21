import java.util.UUID;

public class Program
{
    public static void main(String[] argv)
    {
        User user1 = new User(1,"John", 1000);
        User user2 = new User(2, "Mike", 2000);

        user1.printInfo();
        user2.printInfo();

        UUID id1 = UUID.randomUUID();
        Transaction transaction1 = new Transaction(id1, user2, user1, -500, Transaction.Category.credits);

        transaction1.printTransaction();

        user1.printInfo();
        user2.printInfo();

        UUID id2 = UUID.randomUUID();
        Transaction transaction2 = new Transaction(id2, user2, user1, 500, Transaction.Category.debits);

        transaction2.printTransaction();

        user1.printInfo();
        user2.printInfo();
    }
}
