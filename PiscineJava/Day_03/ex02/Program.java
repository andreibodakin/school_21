import java.util.Random;

class ThreadingCalculator {

    String[] args;
    int arraySize = 0;
    int threadsCount = 0;
    int[] arrRandom;
    int sumArrBase = 0;
    int sumArrTread = 0;
    ThreadsSum[] TS;

    ThreadingCalculator(String[] args)
    {
        this.args = args;
    }

    class ThreadsSum {
        int first = 0;
        int last = 0;
        int sum = 0;

        ThreadsSum() {
        }

        ThreadsSum(int first, int last)
        {
            this.first = first;
            this.last = last;
        }

        public int getFirst() {
            return first;
        }

        public int getLast() {
            return last;
        }
    }

    public class countSumInArray extends Thread {
        ThreadsSum NT;
        int sum = 0, numThread = 0;

        countSumInArray(ThreadsSum NT, int num) {
            this.NT = NT;
            this.numThread = num;
        }

        @Override
        public void run() {
            synchronized (this) {
                for (int first = NT.getFirst(), last = NT.getLast(); first < last; ++first) {
                    if (first >= arraySize)
                        break;
                    sum = sum + arrRandom[first];
                }
                sumArrTread += sum;
                System.out.println("Thread " + numThread + ": from " + (NT.getFirst() == 0 ? NT.getFirst() : NT.getFirst()) + " to " + (NT.getLast() - 1) + " sum is " + sum);
            }
        }
    }

        public void parseArgs() {

        String arraySizeStr = "";
        String threadsCountStr = "";

        try {
            arraySizeStr = args[0];
            threadsCountStr = args[1];
        } catch (Exception e) {
            System.err.println("Error: wrong arguments");
            System.exit(-1);
        }

        if (arraySizeStr.startsWith("--arraySize=") && threadsCountStr.startsWith("--threadsCount=")) {
            try {
                arraySize = Integer.parseInt(arraySizeStr.substring(12, arraySizeStr.length()));
                threadsCount = Integer.parseInt(threadsCountStr.substring(15, threadsCountStr.length()));
                if ((arraySize < 1) || (threadsCount < 1) || (arraySize < threadsCount)) {
                    System.out.println("Error: negative number or arraySize < threadsCount");
                    System.exit(-1);
                }
            } catch (NumberFormatException e) {
                System.err.println("Error: no number");
                System.exit(-1);
            }
        } else {
            System.out.println("Enter: --arraySize=Number --threadsCount=Number");
            System.exit(-1);
        }
    }

    public void generateArray() {
        arrRandom = new int[arraySize];
        Random random = new Random();

        for (int i = 0; i < arraySize; ++i) {
            arrRandom[i] = (random.nextInt() % 1000);
            sumArrBase += arrRandom[i];
        }
        System.out.println("\nSum: " + sumArrBase);

        TS = new ThreadsSum[threadsCount];
    }

    public void defineBlocksInArray() {
        int sum = arraySize % threadsCount;
        int sum1 = arraySize / threadsCount;

        if (sum != 0) {
            int i = 0, k = 0;
            for (; k < threadsCount - 1; i += sum1, ++k) {
                TS[k] = new ThreadsSum(i, i + sum1);
            }
            TS[threadsCount - 1] = new ThreadsSum(i, arraySize);
        } else {
            for (int i = 0, k = 0; k < threadsCount; i += sum1, ++k) {
                TS[k] = new ThreadsSum(i, i + sum1);
            }
        }
    }

    public void startTreads() throws InterruptedException {
        for (int i = 0; i < threadsCount; ++i) {
            countSumInArray thr = new countSumInArray(TS[i], i);
            thr.start();
        }
        synchronized (this) {
            wait(1);
            System.out.println("Sum by threads: " + sumArrTread);
        }
    }
}

public class Program {
    public static void main(String[] args) throws InterruptedException {
        ThreadingCalculator calc = new ThreadingCalculator(args);

        calc.parseArgs();
        calc.generateArray();
        calc.defineBlocksInArray();
        calc.startTreads();
    }
}
