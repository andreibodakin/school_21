
public class Program {
    public static void main(String[] argv) {
        String input = "";
        int count = 0;

        try {
            input = argv[0];
        } catch (Exception e) {
            System.err.println("Example: java Program --count=50");
            System.exit(-1);
        }
        if (input.startsWith("--count=")) {
            try {
                count = Integer.parseInt(input.substring(8, input.length()));
                if (count < 1) {
                    System.out.println("Error: negative number");
                    System.exit(-1);
                }
            } catch (NumberFormatException e) {
                System.err.println("Error: no number");
                System.exit(-1);
            }
        } else {
            System.out.println("Enter: --count=positive number");
            System.exit(-1);
        }

        Egg eggThread = new Egg(count);
        Hen henThread = new Hen(count);

        try {
            eggThread.start();
            henThread.start();
            eggThread.join();
            henThread.join();

            for (int i = 0; i < count; ++i) {
                System.out.println("Human");
            }
        } catch (Exception e) {
            System.err.println("Exception");
        }
    }
}


