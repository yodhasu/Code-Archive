package Learn;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // System.out.println("Hello, World!");
        // System.out.println("Another Hello world");

        // String newstr = "This is a string";
        // System.out.println(newstr);
        // int a = 2;
        // int b = 3;
        // int c = a + b * 2;
        // System.out.println(c - b - a);

        Scanner sc = new Scanner(System.in);
        // String str = sc.nextLine();
        
        // try{
        //     if(str.equals("Hello World!")){
        //         System.out.println("Yout typed Hello World ^_^");
        //     } else{
        //         System.out.println("You didn't type Hello World! but you type "+ str + " instead >_<");
        //     }
        // }catch(Exception e){
        //     System.out.println("Your input must be a string!");
        // }
        // System.out.println(str);
        try{
            int integer = sc.nextInt();
            if(integer == 69){
                System.out.println("Yout typed 69 ^_^");
            } else{
                System.out.println("You didn't type Hello World! but you type "+ integer + " instead >_<");
            }
        }catch(Exception exception){
            System.out.println("Your input must be an Integer!");
        }

    }
}
