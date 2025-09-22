import javax.jws.soap.SOAPBinding;
import java.util.UUID;

public class Transaction
{
    enum Category
    {
        debits,
        credits
    }

    private UUID identifier;
    private User recipient;
    private User sender;
    private double amount;
    private Category category;

    Transaction(UUID identifier, User recipient, User sender, double amount, Category category)
    {
        this.identifier = identifier;
        this.recipient = recipient;
        this.sender = sender;
        this.amount = amount;
        this.category = category;

        switch (category) {
            case debits:
                if (amount <= 0) {
                    System.err.println("Illegal Argument: Negative Amount for debit Category");
                }
                else
                {
                    recipient.setBalance(recipient.getBalance() + amount);
                    sender.setBalance(sender.getBalance() - amount);
                }
                break ;
            case credits:
                if (amount >= 0) {
                    System.err.println("Illegal Argument: Positive Amount for credit Category");
                }
                else
                {
                    recipient.setBalance(recipient.getBalance() - amount);
                    sender.setBalance(sender.getBalance() + amount);
                }
                break ;
        }
    }

    public double getAmount()
    {
        return (amount);
    }

    public void printTransaction()
    {
        System.out.printf("Transaction info:\n UUID %s\n Recipient %s\n Sender %s\n Amount %.2f\n Category %s\n",
                identifier, recipient.getName(), sender.getName(), amount, category);
    }

}
