public class Synchronized {
        public static void main(String[] argv) throws InterruptedException
        {
            String input = argv[0];
            int count = 0;

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

            final PC pc = new PC(count);

            Thread EggThread = new Thread(new Runnable() {
                @Override
                public void run()
                {
                    try {
                        pc.egg();
                    }
                    catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            });

            Thread HenThread = new Thread(new Runnable() {
                @Override
                public void run()
                {
                    try {
                        pc.hen();
                    }
                    catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            });

            EggThread.start();
            HenThread.start();

            EggThread.join();
            HenThread.join();
        }

        public static class PC {

            int order = 0;
            int eggCount = 0;
            int henCount = 0;

            PC(int count) {
                eggCount = count;
                henCount = count;
            }

            public void egg() throws InterruptedException
            {
                while (eggCount > 0) {
                    synchronized (this)
                    {
                        while (order == 1)
                            wait();

                        System.out.println("Egg");
                        order = 1;
                        notify();
                        --eggCount;
                        Thread.sleep(10);
                    }
                }
            }

            public void hen() throws InterruptedException
            {
                while (henCount > 0) {
                    synchronized (this)
                    {
                        while (order == 0)
                            wait();

                        System.out.println("Hen");
                        order = 0;
                        notify();
                        --henCount;
                        Thread.sleep(10);
                    }
                }
            }
        }
    }

