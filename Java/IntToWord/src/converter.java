import java.math.BigInteger;

public class converter {

  public static String convertToString(BigInteger numbers, String numNames[], String[] tensNames, String[] thousandNames){
    if (numbers.equals(BigInteger.ZERO)) return "zero"; 
    String result = "";
    int count = 0;
      do{
        BigInteger[] divAndRem = numbers.divideAndRemainder(BigInteger.valueOf(1000));
        BigInteger num = divAndRem[1];
        
        if (!num.equals(BigInteger.ZERO)) {
          // String group = specialCase(langcode, num, numNames, tensNames, thousandNames);
          String group = convert(num, numNames, tensNames) + thousandNames[count];
          result = group + result;
        }
        count++;
        numbers = divAndRem[0];
      }while(!numbers.equals(BigInteger.ZERO));
    
    return result.trim();
  }

  private static String convert(BigInteger number, String numNames[], String[] tensNames) {
    String numwords;
    BigInteger[] divAndRem = number.divideAndRemainder(BigInteger.valueOf(1000));
    int num = divAndRem[1].intValue();
    if (num % 100 < 20){ 
        numwords = numNames[num % 100]; 
        num /= 100; 
    } else { 
        numwords = numNames[num % 10]; 
        num /= 10; 

        numwords = tensNames[num % 10] + numwords;                                          
        num /= 10; 
    } if (num == 0) return numwords; 
    return numNames[num] + " hundred" + numwords;
  }
  // public String specialCase(String langcode, BigInteger num, String numNames[], String[] tensNames, String[] thousandNames){
  //   // Message me to unock
  // }
}

// HOW IT WORKS:
//   For int less than 1000 basically check that the number is hundreds or not, if hundreds take the hundreds from dictionary (in this case english.java)
//   using numNames[number % 100]. After that divide by 100 so we get the tens or the units. Do basically the same

//   For int more than 1000 loop until number == 0
//    Looping process:
//    1. check input number is not 0
//    2. group the convert_less_than_1000 and thousandNames dictionary
//    3. append that into result
