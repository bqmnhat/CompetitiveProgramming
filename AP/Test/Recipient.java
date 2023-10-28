import java.util.*;
public class Recipient {
    private List<String> lines;
    public String getAddress(String name) {
        String ans = "";
        int i = 0;
        while ((i < lines.size()) && (!lines.get(i).equals(name)))
            i++;
        while ((i < lines.size()) && (!lines.get(i).equals(" "))) {
            ans = ans + lines.get(i) + "\n";
            String tmp = lines.get(i);
            if (tmp.charAt(1) == 'A')
                i++;
        }
        return ans;
    }
}