import java.util.Scanner;

public class Hellowolrd {

    static void menu(double total){
        
        System.out.println("Calculator");
        System.out.println("=================================================");
        System.out.println("Total: " + total);
    }

    static void option(){
        System.out.println("!. +");
        System.out.println("2. -");
        System.out.println("3. *");
        System.out.println("4. /");
        System.out.println("5. %");
        System.out.println("6. Clear total");
        System.out.println("7. Exit");
    }
    public static void main(String[] args){
        // System.out.println("Hello, World!");

        // Scanner inp = new Scanner(System.in);
        // Scanner inp2 = new Scanner(System.in);

        // System.out.println("input a char in first line and int on second line: ");
        // try{
        //     String str = inp.nextLine();
        //     int inter = inp2.nextInt();
        //     int i = 0;
        //     do{
        //         System.out.println("You type " + str + " and " + i + "!");
        //         i++;
        //     }while(i <= inter);
        // }catch(Exception e){
        //     System.out.println("You input a wrong datatype");
        // }
       double tot = 0;
        do {
            try {
                menu(tot);
                Scanner inp = new Scanner(System.in);
                // System.out.println("Input number: ");
                // double first_num = inp.nextDouble();
                

                option();
                
                System.out.println("Input operator: ");
                int opt = inp.nextInt();

                if(opt != 6 && opt != 7){
                    System.out.println("Input number: ");
                    double sec_num = inp.nextDouble();
                

                    switch (opt) {
                        case 1:

                            tot = tot + sec_num;

                            break;
                        
                        case 2:

                            tot = tot - sec_num;

                            break;

                        case 3:

                            tot = tot * sec_num;

                            break;

                        case 4:

                            tot = tot / sec_num;

                            break;
                        
                        case 5:

                            tot = tot % sec_num;

                            break;
                    }
                } else if (opt == 6) {
                    
                    tot = 0;
                    continue;

                } else {
                    
                    System.exit(0);
                    break;

                }
            } catch (Exception e) {
                // TODO: handle exception
                System.out.println("You input a wrong datatype!");
                continue;
            }
            System.out.flush();
        }while(true);
        
    }
}
