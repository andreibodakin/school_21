import java.lang.System.*;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        if (args[0] == null) {
            System.out.println("Input parameter should be full path to the image.");
            System.exit(1);
        }
        try {
            PrintImage printImage = new PrintImage(args[0]);
            printImage.print();
        } catch (IOException e) {
            System.err.println("Can't open image: " + args[0]);
        }
    }
}