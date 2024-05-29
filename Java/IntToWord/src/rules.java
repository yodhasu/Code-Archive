public class rules{
    public static String checkRules(String code, String check){
        String result = "";
        // System.out.println(code);
        switch (code) {
            case "id":
                // System.out.println(check.contains("satu ribu"));
                // result = check;
                if (check.startsWith(" satu ribu") || !check.contains(" ratus")) {
                    check = check.replace(" satu ribu", " seribu");
                }
                check = check.replace(" satu ratus", " seratus");
                return check.trim();
                // break;
        
            default:
                result = check;
                break;
        }
        return result.trim();
    }
}
