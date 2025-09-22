import java.util.Scanner;

public class Program
{
    public static boolean checkSumPrime(int number)
    {
        int sum = 0;

        while (number >= 10)
        {
            sum += number % 10;
            number /= 10;
        }
        sum += number;

        boolean isPrime = true;

        for (int n = 2; n * n <= sum && isPrime; n++)
        {
            if (sum % n == 0)
            {
                isPrime = false;
            }
        }

        return (isPrime);
    }

    public static void main(String[] argv)
    {
        int sumPrime = 0;
        int number;
        boolean goOn = true;
        Scanner sc = new Scanner(System.in);

        while (goOn)
        {
            if (!sc.hasNextInt())
            {
                System.err.println("IllegalArgument");
                System.exit(-1);
            }

            number = sc.nextInt();

            if (number <= 0 || number == 1)
            {
                System.err.println("IllegalArgument");
                continue ;
            }

            if (number == 42)
            {
                goOn = false;
            }
            else if (checkSumPrime(number))
            {
                sumPrime++;
            }
        }

        System.out.print("Count of coffee - request - ");
        System.out.println(sumPrime);

        sc.close();
    }
}
