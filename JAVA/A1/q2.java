public class q2 {
  public static void main(String[] args) {
    int count = args.length;

    System.out.println("You gave me " + count + " command line parameters! Here they are:");

    for (int i = 0; i < count; i++) {
      System.out.println("Parameter " + (i + 1) + ": " + args[i]);
    }

    System.out.println("That's all.");
  }
}
