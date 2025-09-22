public class Egg extends Thread {
    int count;

    Egg(int i) {
        count = i;
    }

    @Override
    public void run() {
        for (int i = 0; i < count; ++i) {
            System.out.println("Egg");
        }
    }
}