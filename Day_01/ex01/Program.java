public class Program {
    public static void main(String[] argv)
    {
        User user1 = new User("Jhon", 21000);
        User user2 = new User("Smith", 42000);
        User user3 = new User("Neo", 0);

        user1.printInfo();
        user2.printInfo();
        user3.printInfo();
    }
}
