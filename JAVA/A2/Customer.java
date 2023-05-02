import java.util.Scanner;
public class Customer {
    private String customerId;
    private String name;
    private double currentLoanAmount;
    private String phoneNumber;
    private double creditLimit;

    public Customer(String customerId, String name, double currentLoanAmount, String phoneNumber) {
        this.customerId = customerId;
        this.name = name;
        this.currentLoanAmount = currentLoanAmount;
        this.phoneNumber = phoneNumber;
        this.creditLimit = 10000; 
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public boolean askForLoan(double amount) {
        if (currentLoanAmount + amount <= creditLimit) {
            currentLoanAmount += amount;
            return true;
        } else {
            return false;
        }
    }

    public double getCreditLimit() {
        return creditLimit;
    }

    public double getCurrentLoanAmount() {
        return currentLoanAmount;
    }

    public double getAvailableLoanAmount() {
        return creditLimit - currentLoanAmount;
    }

    public void setCreditLimit(double creditLimit) {
        this.creditLimit = creditLimit;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Customer customer = null;

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Create customer");
            System.out.println("2. Create privileged customer");
            System.out.println("3. Check credit limit");
            System.out.println("4. Check current loan amount");
            System.out.println("5. Check available loan amount");
            System.out.println("6. Request loan");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); 
            switch (choice) {
                case 1:
                    System.out.print("Enter customer ID: ");
                    String customerId = scanner.nextLine();
                    System.out.print("Enter customer name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter current loan amount: ");
                    double currentLoanAmount = scanner.nextDouble();
                    scanner.nextLine();
                    System.out.print("Enter phone number: ");
                    String phoneNumber = scanner.nextLine();
                    customer = new Customer(customerId, name, currentLoanAmount, phoneNumber);
                    break;
                case 2:
                    System.out.print("Enter customer ID: ");
                    customerId = scanner.nextLine();
                    System.out.print("Enter customer name: ");
                    name = scanner.nextLine();
                    System.out.print("Enter current loan amount: ");
                    currentLoanAmount = scanner.nextDouble();
                    scanner.nextLine();
                    System.out.print("Enter phone number: ");
                    phoneNumber = scanner.nextLine();
                    customer = new PrivilegedCustomer(customerId, name, currentLoanAmount, phoneNumber);
                    break;
                case 3:
                    if (customer != null) {
                        System.out.println("Credit limit: " + customer.getCreditLimit());
                    } else {
                        System.out.println("Please create a customer first.");
                    }
                    break;
                case 4:
                    if (customer != null) {
                        System.out.println("Current loan amount: " + customer.getCurrentLoanAmount());
                    } else {
                        System.out.println("Please create a customer first.");
                    }
                    break;
                case 5:
                    if (customer != null) {
                        System.out.println("Available loan amount: " + customer.getAvailableLoanAmount());
                    } else {
                        System.out.println("Please create a customer first.");
                    }
                    break;
                case 6:
                    if (customer != null) {
                        System.out.print("Enter loan amount: ");
                        double loanAmount = scanner.nextDouble();
                        boolean result = customer.askForLoan(loanAmount);
                        if (result) {
                            System.out.println("Loan request approved.");
                        } else {
                            System.out.println("Loan request denied.");
                        }
                    } else {
                        System.out.println("Please create a customer first.");
                    }
                    break;
                case 7:
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

}

class PrivilegedCustomer extends Customer {
    public PrivilegedCustomer(String customerId, String name, double currentLoanAmount, String phoneNumber) {
        super(customerId, name, currentLoanAmount, phoneNumber);
        super.setCreditLimit(20000) ;
    }
}