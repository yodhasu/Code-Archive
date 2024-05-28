import java.math.BigInteger;

public class english extends converter{
    private final String lang = "en"; 
    
    private static final String[] tensNames = {
        "",
        " ten",
        " twenty",
        " thirty",
        " forty",
        " fifty",
        " sixty",
        " seventy",
        " eighty",
        " ninety"
      };
    
      private static final String[] numNames = {
        "",
        " one",
        " two",
        " three",
        " four",
        " five",
        " six",
        " seven",
        " eight",
        " nine",
        " ten",
        " eleven",
        " twelve",
        " thirteen",
        " fourteen",
        " fifteen",
        " sixteen",
        " seventeen",
        " eighteen",
        " nineteen"
      };

      private static final String[] thousandNames = {
        "",
        " thousand",
        " million",
        " billion",
        " quadrillion",
        " quintillion",
        " sextillion",
        " septillion",
        " octillion",
        " nonillion",
        " decillion",
        " undecilion",
        " duodecillion",
        " tredecillion",
        " quattuordecillion",
        " quindecillion",
        " sexdecillion",
        " septendecillion",
        " octodecillion",
        " novemdecillion",
        " vigintillion"
      };
      
      public void convert(BigInteger number){
        System.out.println(convertToString(lang, number, numNames, tensNames, thousandNames));
      }
}
