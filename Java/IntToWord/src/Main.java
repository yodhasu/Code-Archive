import java.math.BigInteger;
// import java.util.ArrayList;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws Exception {
        english en = new english();
        indo id = new indo();
        Scanner input = new Scanner(System.in);

        print("Input a number");

        try {
            String big_numnum = input.nextLine();
            converter(big_numnum, en, id);
            input.close();
        } catch (Exception e) {
            // TODO: handle exception
            print("Wrong input datatype");
        }
        input.close();
    }

    // Function to print like Python
    public static <P> void print(P var){
        System.out.println(var);
    }

    public static void converter(String numnum, english endict, indo iddict){
        BigInteger biggie;
        biggie = new BigInteger(numnum);
        endict.convert(biggie);
        iddict.convert(biggie);
        iddict.convert(biggie);
    }
}
