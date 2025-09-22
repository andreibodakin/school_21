import java.io.*;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class FileExtensions {

    HashMap<String, String> token = new HashMap<>();
    String buf = new String();
    boolean ExtExist = false;
    OutputStream output;
    Writer writer;

    FileExtensions() {
        try {
            FileInputStream input = new FileInputStream("signatures.txt");
            Scanner sc = new Scanner(input);
            String line = new String(), value = new String();
            while (sc.hasNextLine()) {
                line = sc.nextLine();
                value = line.substring(line.indexOf(',') + 1);
                token.put(line.substring(0, line.indexOf(',')), value.replaceAll("\\s", ""));
            }
            output = new FileOutputStream("result.txt");
            writer = new BufferedWriter(new OutputStreamWriter(output, "utf-8"));
        } catch (IOException e) {
            System.out.println("Exception: Input file error");
        }
    }

    void writeToFile() {
        if (ExtExist == true) {
            try {
                writer.write(buf.toString());
                writer.append('\n');
                writer.flush();
            } catch (IOException e) {
                System.err.println("Exception: write error");
            }
        }
    }

    void checkFormat() {
        for (Map.Entry<String, String> pair : token.entrySet()) {
            if (buf.lastIndexOf(pair.getValue()) == -1) {
                ExtExist = false;
            } else {
                ExtExist = true;
                buf = pair.getKey();
                System.out.println("PROCESSED");
                return;
            }
        }
        System.out.println("UNDEFINED");
    }

    void readFromFile() {
        Scanner in = new Scanner(System.in);
        String nextLine = in.nextLine();

        if (nextLine.equals("42"))
            System.exit(0);

        try {
            FileInputStream sigfis = new FileInputStream(nextLine);
            byte[] sigToVerify = new byte[8];
            sigfis.read(sigToVerify);
            sigfis.close();
            buf = bytesToHex(sigToVerify);
        } catch (Exception e) {
            System.err.println("Exception: file not found");
        }
    }

    private static final char[] HEX_ARRAY = "0123456789ABCDEF".toCharArray();
    public static String bytesToHex(byte[] bytes) {
        char[] hexChars = new char[bytes.length * 2];
        for (int j = 0; j < bytes.length; j++) {
            int v = bytes[j] & 0xFF;
            hexChars[j * 2] = HEX_ARRAY[v >>> 4];
            hexChars[j * 2 + 1] = HEX_ARRAY[v & 0x0F];
        }
        return new String(hexChars);
    }

    public static void main(String... argv)
    {
        FileExtensions file =  new FileExtensions();

        while  (true) {
            file.readFromFile();
            file.checkFormat();
            file.writeToFile();
        }
    }
}
