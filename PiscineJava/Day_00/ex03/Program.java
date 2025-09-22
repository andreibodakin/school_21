import java.util.Scanner;

public class Program
{
    public static void main(String[] argv)
    {
        int week;
        int prevWeek = 0;
        int stop = 0;
        int tmp = 0;
        int min;
        long iter = 1;
        long storage = 0;
        long count = 0;
        String name;

        Scanner sc = new Scanner(System.in);
        sc.useDelimiter(" |\\n");

        while(true)
        {
            name = sc.next();

            if (!name.equals("Week"))
            {
                System.err.println("IllegalArgument");
                System.exit(-1);
            }

            if (!sc.hasNextInt())
            {
                System.err.println("IllegalArgument");
                System.exit(-1);
            }

            week = sc.nextInt();

            if (week != ++prevWeek || week == 19)
            {
                System.err.println("IllegalArgument");
                System.exit(-1);
            }

            min = 10;

            for (int i = 0; i < 5; i++)
            {
                if (!sc.hasNextInt() && i != 4)
                {
                    System.err.println("IllegalArgument");
                    System.exit(-1);
                }

                tmp = sc.nextInt();

                if (tmp < min)
                    min = tmp;
            }

            if ( min > 9 || min < 1)
            {
                System.err.println("IllegalArgument");
                System.exit(-1);
            }

            storage += min * iter;
            iter *= 10;

            if (sc.hasNextInt())
            {
                stop = sc.nextInt();
                if (stop == 42)
                    break ;
            }
        }

        int j = 1;
        while (j <= week)
        {
            System.out.print("Week ");
            System.out.print(j);
            System.out.print(" ");
            count = storage % 10;
            storage /= 10;
            while (count-- > 0)
                System.out.print("=");
            System.out.println(">");
            ++j;
        }

        sc.close();
    }
}
