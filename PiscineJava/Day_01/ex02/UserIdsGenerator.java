public class UserIdsGenerator {

    private static UserIdsGenerator instance;
    private static int id;

    private UserIdsGenerator() {
        this.id = 0;
    }

    public static UserIdsGenerator getInstance() {
        if (instance == null) {
            instance = new UserIdsGenerator();
        }
        return instance;
    }

    int generateId() {
        return ++id;
    }
}
