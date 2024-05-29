import java.math.BigInteger;

public class english extends conv{
  
    public final String lang = "en";

    public static final String zero = "zero";

    public static final String[] tensNames = {
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
  
    public static final String[] numNames = {
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

    public static final String hundreds = " hundred";

    public static final String[] thousandNames = {
      "",
      " thousand",
      " million",
      " billion",
      " trilion",
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
    public static final boolean hyphen = true;
    public static final boolean rule = false;
    public void convert(BigInteger number){
      System.out.println(convert(number, lang, zero, numNames, tensNames, hundreds, thousandNames, hyphen, rule));
    }
}
