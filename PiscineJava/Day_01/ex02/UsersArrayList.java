public class UsersArrayList {
    private User[] users;
    private int total;

    {
        users = new User[10];
        total = 0;
    }

    public void addUser(User user) {
        if (total >= this.users.length) {
            User[] newUsers = new User[this.users.length * 2];
            for (int i = 0; i < users.length; i++) {
                newUsers[i] = this.users[i];
            }
            this.users = newUsers;
        }

        this.users[total++] = user;
    }

    public User getUserById(int id) throws Exception {
        for (int i = 0; i < total; i++) {
            if (users[i].getIdentifier() == id)
                return users[i];
        }
        throw new Exception("UserNotFoundException");
    }

    public User getUserByIndex(int index) throws Exception {
        if (index >= 0 && index < total)
            return users[index];
        throw new Exception("UserNotFoundException");
    }

    public int getNumberOfUsers() {
        return this.total;
    }

    public void printInfo() {
        for (int i = 0; i < total; i++) {
            users[i].printInfo();
        }
    }
}