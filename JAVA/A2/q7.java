
import java.util.Arrays;
import java.util.StringTokenizer;

public class q7 {
    public static void main(String[] args) {
        String input = "The man @ going on . a walk and @ he is going to the market.";

        // Number of times 'a' appears
        int countA = countCharacter(input, 'a');
        System.out.println("Number of times 'a' appears: " + countA);

        // Number of times "and" appears
        int countAnd = countSubstring(input, "and");
        System.out.println("Number of times 'and' appears: " + countAnd);

        // Whether it starts with "The" or not
        boolean startsWithThe = input.startsWith("The");
        System.out.println("Starts with 'The': " + startsWithThe);

        // Put the String into an array of characters
        char[] charArray = input.toCharArray();
        System.out.println("Array of characters: " + Arrays.toString(charArray));

        // Display the tokens in the String
        StringTokenizer tokenizer = new StringTokenizer(input, " @.");
        System.out.println("Tokens in the String:");
        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken();
            System.out.println(token);
        }
    }

    private static int countCharacter(String input, char c) {
        int count = 0;
        for (char ch : input.toCharArray()) {
            if (ch == c) {
                count++;
            }
        }
        return count;
    }

    private static int countSubstring(String input, String substring) {
        int count = 0;
        int index = input.indexOf(substring);
        while (index != -1) {
            count++;
            index = input.indexOf(substring, index + 1);
        }
        return count;
    }
}
