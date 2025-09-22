public class UsersList {
    private UsersArrayList list;

    UsersList() {
        this.list = new UsersArrayList();
    }

    public void addUser(User user) {
        list.addUser(user);
    }

    public User getUserById(int id) throws Exception {
        return list.getUserById(id);
    }

    public User getUserByIndex(int index) throws Exception {
        return list.getUserByIndex(index);
    }

    public int getNumberOfUsers() {
        return list.getNumberOfUsers();
    }

    public void printInfo() {
        list.printInfo();
    }
}