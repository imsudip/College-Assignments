public class BankAcct {
    private String accountNumber;
    private double balance;
    private static double interestRate;

    public BankAcct(String accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public static void initializeInterestRate(double rate) {
        interestRate = rate;
    }

    public static void changeInterestRate(double rate) {
        interestRate = rate;
    }

    public static void displayInterestRate() {
        System.out.println("Interest Rate: " + interestRate);
    }

    public double getBalance() {
        return balance;
    }

    public double calculateInterest() {
        return balance * interestRate;
    }

    public static void main(String[] args) {
        BankAcct.initializeInterestRate(0.05);

        BankAcct acct1 = new BankAcct("12345", 1000);
        BankAcct acct2 = new BankAcct("67890", 2000);

        System.out.println("Account 1 Balance: " + acct1.getBalance());
        System.out.println("Account 1 Interest: " + acct1.calculateInterest());

        System.out.println("Account 2 Balance: " + acct2.getBalance());
        System.out.println("Account 2 Interest: " + acct2.calculateInterest());

        BankAcct.changeInterestRate(0.1);

        System.out.println("Account 1 Balance: " + acct1.getBalance());
        System.out.println("Account 1 Interest: " + acct1.calculateInterest());

        System.out.println("Account 2 Balance: " + acct2.getBalance());
        System.out.println("Account 2 Interest: " + acct2.calculateInterest());
    }
}