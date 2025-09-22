import java.util.Scanner;

public class Program {
    public static void main(String[] argv)
    {
        Scanner sc = new Scanner(System.in);

        if (!sc.hasNextInt())
        {
            System.err.println("IllegalArgument");
            System.exit(-1);
        }

        int number = sc.nextInt();

        if (number <= 1)
        {
            System.err.println("IllegalArgument");
            System.exit(-1);
        }

        boolean isPrime = true;
        int iter = 1;

        for (int n = 2; n * n <= number && isPrime; n++)
        {
            if (number % n == 0)
            {
                isPrime = false;
            }
            if (isPrime)
            {
                ++iter;
            }
        }

        if (isPrime)
        {
            System.out.print("true ");
            System.out.println(iter);
        }
        else
        {
            System.out.print("fasle ");
            System.out.println(iter);
        }

        sc.close();
    }
}
