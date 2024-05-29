import java.math.BigInteger;

public class conv{
    String langcode; 
    BigInteger inp_num;
    
    public String convert(BigInteger numbers, String langcode, String zeros, String[] units, String[] tens, String hundreds, String[] thousands, boolean hypstatus, boolean rule){
        Dict dictionary = new Dict(langcode, zeros, units, tens, hundreds, thousands, hypstatus, rule);

        String words = "";
        int groupIndex = 0;
        if (numbers.equals(BigInteger.ZERO)) {
            words =  dictionary.zeros;
        }
        while (numbers.compareTo(BigInteger.ZERO) > 0) {
            BigInteger[] divAndRem = numbers.divideAndRemainder(BigInteger.valueOf(1000));
            BigInteger num = divAndRem[1];
            String group = convertThreeDigits(num, groupIndex, dictionary, dictionary.hyphen) + dictionary.thousands[groupIndex];
            words = group + words;
            numbers = divAndRem[0];
            groupIndex++;
        }
        String finres = rules.checkRules(langcode, words);
        return finres;
    }

    public String convertThreeDigits(BigInteger number, int index, Dict dict, boolean hype){
        String numwords;
        BigInteger[] divAndRem = number.divideAndRemainder(BigInteger.valueOf(1000));
        int num = divAndRem[1].intValue();
        if (num % 100 < 20){ 
            numwords = dict.units[num % 100]; 
            num /= 100; 
        } else { 
            numwords = dict.units[num % 10]; 
            num /= 10; 

            if (hype) {
                numwords = dict.tens[num % 10] +"-"+numwords.trim();       
                // numwords.trim();                                   
                num /= 10; 
            } else{
                numwords = dict.tens[num % 10] + numwords;                                          
                num /= 10; 
            }
        } if (num == 0) return numwords; 
        
        return dict.units[num] + dict.hundreds + numwords;
    }
}
