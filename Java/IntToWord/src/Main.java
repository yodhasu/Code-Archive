import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws Exception {
        english en = new english();

        Scanner input = new Scanner(System.in);

        print("Input a number");
        try {
            String big_numnum = input.nextLine();
            converter(big_numnum, en);
            input.close();
        } catch (Exception e) {
            // TODO: handle exception
            print("Wrong input datatype");
        }

        converter(big_numnum, en);
        input.close();
    }

    // Function to print like Python
    public static <P> void print(P var){
        System.out.println(var);
    }

    public static void converter(String numnum, english endict){
        BigInteger biggie;
        biggie = new BigInteger(numnum);
        endict.convert(biggie);
    }
}
