import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Person person = null;

        while (true) {
            System.out.println("1. Create Student");
            System.out.println("2. Create Faculty");
            System.out.println("3. View Details");
            System.out.println("4. Set Name");
            System.out.println("5. Set Address");
            System.out.println("6. Set Phone Number");
            System.out.println("7. Set Email");
            System.out.println("8. Set Roll Number (Student only)");
            System.out.println("9. Set Course of Study (Student only)");
            System.out.println("10. Set Employee ID (Faculty only)");
            System.out.println("11. Set Department (Faculty only)");
            System.out.println("12. Set Specialization (Faculty only)");
            System.out.println("13. Exit");

            int choice = scanner.nextInt();
            scanner.nextLine();

            if (choice == 1) {
                System.out.print("Enter name: ");
                String name = scanner.nextLine();
                System.out.print("premisesNumber: ");
                String premisesNumber = scanner.nextLine();
                System.out.print("street: ");
                String street = scanner.nextLine();
                System.out.print("city: ");
                String city = scanner.nextLine();
                System.out.print("pin: ");
                String pin = scanner.nextLine();
                System.out.print("state: ");
                String state = scanner.nextLine();
                Address address = new Address(premisesNumber, street, city, pin, state);
                System.out.print("Enter phone number: ");
                String phoneNumber = scanner.nextLine();
                System.out.print("Enter email: ");
                String email = scanner.nextLine();
                System.out.print("Enter roll number: ");
                String rollNumber = scanner.nextLine();
                System.out.print("Enter course of study: ");
                String courseOfStudy = scanner.nextLine();

                person = new Student(name, address, phoneNumber, email, rollNumber, courseOfStudy);
            } else if (choice == 2) {
                System.out.print("Enter name: ");
                String name = scanner.nextLine();
                System.out.print("Enter premises number: ");
                String premisesNumber = scanner.nextLine();
                System.out.print("Enter street: ");
                String street = scanner.nextLine();
                System.out.print("Enter city: ");
                String city = scanner.nextLine();
                System.out.print("Enter pin: ");
                String pin = scanner.nextLine();
                System.out.print("Enter state: ");
                String state = scanner.nextLine();
                Address address = new Address(premisesNumber, street, city, pin, state);
                System.out.print("Enter phone number: ");
                String phoneNumber = scanner.nextLine();
                System.out.print("Enter email: ");
                String email = scanner.nextLine();
                System.out.print("Enter employee ID: ");
                String employeeId = scanner.nextLine();
                System.out.print("Enter department: ");
                String department = scanner.nextLine();
                System.out.print("Enter specialization: ");
                String specialization = scanner.nextLine();

                person = new Faculty(name, address, phoneNumber, email, employeeId, department, specialization);
            } else if (choice == 3) {
                System.out.println(person);
            } else if (choice == 4) {
                System.out.print("Enter name: ");
                String name = scanner.nextLine();
                person.setName(name);
            } else if (choice == 5) {
                System.out.print("Enter premises number: ");
                String premisesNumber = scanner.nextLine();
                System.out.print("Enter street: ");
                String street = scanner.nextLine();
                System.out.print("Enter city: ");
                String city = scanner.nextLine();
                System.out.print("Enter pin: ");
                String pin = scanner.nextLine();
                System.out.print("Enter state: ");
                String state = scanner.nextLine();
                Address address = new Address(premisesNumber, street, city, pin, state);
                person.setAddress(address);
            } else if (choice == 6) {
                System.out.print("Enter phone number: ");
                String phoneNumber = scanner.nextLine();
                person.setPhoneNumber(phoneNumber);
            } else if (choice == 7) {
                System.out.print("Enter email: ");
                String email = scanner.nextLine();
                person.setEmail(email);
            } else if (choice == 8) {
                System.out.print("Enter roll number: ");
                String rollNumber = scanner.nextLine();
                ((Student) person).setRollNumber(rollNumber);
            } else if (choice == 9) {
                System.out.print("Enter course of study: ");
                String courseOfStudy = scanner.nextLine();
                ((Student) person).setCourseOfStudy(courseOfStudy);
            } else if (choice == 10) {
                System.out.print("Enter employee ID: ");
                String employeeId = scanner.nextLine();
                ((Faculty) person).setEmployeeId(employeeId);
            } else if (choice == 11) {
                System.out.print("Enter department: ");
                String department = scanner.nextLine();
                ((Faculty) person).setDepartment(department);
            } else if (choice == 12) {
                System.out.print("Enter specialization: ");
                String specialization = scanner.nextLine();
                ((Faculty) person).setSpecialization(specialization);
            } else if (choice == 13) {
                break;
            }
        }
    }
}

// write a demo input to all the cases for the above program
