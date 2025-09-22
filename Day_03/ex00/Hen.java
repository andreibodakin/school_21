public class Hen extends Thread {
    int count;

    Hen(int i) {
        count = i;
    }

    @Override
    public void run() {
        for (int i = 0; i < count; ++i) {
            System.out.println("Hen");
        }
    }
}
