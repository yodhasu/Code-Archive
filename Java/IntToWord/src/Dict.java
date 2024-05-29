public class Dict {
    String langcode;
    String zeros;
    String[] units;
    String[] tens;
    String hundreds;
    String[] thousands;
    boolean hyphen;
    boolean rule;
    conv converter;
    english en;
    public Dict(String code, String zeros, String[] units, String[] tens, String hundreds, String[] thousands, boolean hyphen, boolean rule){
        this.langcode = code;
        this.zeros = zeros;
        this.units = units;
        this.tens = tens;
        this.hundreds = hundreds;
        this.thousands = thousands;
        this.hyphen = hyphen;
        this.rule = rule;
    }

}
