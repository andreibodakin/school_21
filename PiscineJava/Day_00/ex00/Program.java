public class Program {
    public static void main(String argv[])
    {
        int my6DigInt;
        int Sum;

        my6DigInt = 123456;

        Sum = (my6DigInt % 10);
        my6DigInt = my6DigInt / 10;
        Sum = Sum + (my6DigInt % 10);
        my6DigInt = my6DigInt / 10;
        Sum = Sum + (my6DigInt % 10);
        my6DigInt = my6DigInt / 10;
        Sum = Sum + (my6DigInt % 10);
        my6DigInt = my6DigInt / 10;
        Sum = Sum + (my6DigInt % 10);
        my6DigInt = my6DigInt / 10;
        Sum = Sum + (my6DigInt % 10);

        System.out.println(Sum);
    }
}
