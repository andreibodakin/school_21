public class Program {
    public static void main(String[] argv)
    {
        UsersList usersList = new UsersList();
        usersList.addUser(new User("Alex", 1000));
        usersList.addUser(new User("Rino", 2000));
        usersList.addUser(new User("Carlos", 3000));

        System.out.print("Number of users: ");
        System.out.println(usersList.getNumberOfUsers());
        usersList.printInfo();

        System.out.println("**************");

        try {
            usersList.getUserByIndex(2).printInfo();
        } catch (Exception e) {
            System.err.println("Error: " + e);
        }

        System.out.println("**************");

        try {
            usersList.getUserById(3).printInfo();
        } catch (Exception e) {
            System.err.println("Error: " + e);
        }

        System.out.println("---------------");

        try {
            usersList.getUserById(4).printInfo();
        } catch (Exception e) {
            System.err.println("Error: " + e);
        }

        UsersList usersListExpand = new UsersList();

        usersListExpand.addUser(new User("Random", 1));
        usersListExpand.addUser(new User("Brandon", 2));
        usersListExpand.addUser(new User("Kate", 3));
        usersListExpand.addUser(new User("Emilis", 4));
        usersListExpand.addUser(new User("Camron", 5));
        usersListExpand.addUser(new User("Leigha", 6));
        usersListExpand.addUser(new User("Yusra", 7));
        usersListExpand.addUser(new User("Georga", 8));
        usersListExpand.addUser(new User("Halima", 9));
        usersListExpand.addUser(new User("Jaye", 10));

        System.out.print("Number of users in usersListExpand: ");
        System.out.println(usersListExpand.getNumberOfUsers());

        usersListExpand.addUser(new User("Lyra", 11));

        System.out.print("Number of users in usersListExpand: ");
        System.out.println(usersListExpand.getNumberOfUsers());

        System.out.println("**************");
    }
}
