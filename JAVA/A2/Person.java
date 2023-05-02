public class Person {
    private String name;
    private Address address;
    private String phoneNumber;
    private String email;

    public Person(String name, Address address, String phoneNumber, String email) {
        this.name = name;
        this.address = address;
        this.phoneNumber = phoneNumber;
        this.email = email;
    }

    public void viewDetails() {
        System.out.println("Name: " + name);
        System.out.println("Address: " + address.toString());
        System.out.println("Phone Number: " + phoneNumber);
        System.out.println("Email: " + email);
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}



 class Student extends Person {
    private String rollNumber;
    private String courseOfStudy;

    public Student(String name, Address address, String phoneNumber, String email, String rollNumber, String courseOfStudy) {
        super(name, address, phoneNumber, email);
        this.rollNumber = rollNumber;
        this.courseOfStudy = courseOfStudy;
    }

    @Override
    public void viewDetails() {
        super.viewDetails();
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Course of Study: " + courseOfStudy);
    }

    public void setRollNumber(String rollNumber) {
        this.rollNumber = rollNumber;
    }

    public void setCourseOfStudy(String courseOfStudy) {
        this.courseOfStudy = courseOfStudy;
    }
}
 class Faculty extends Person {
    private String employeeId;
    private String department;
    private String specialization;

    public Faculty(String name, Address address, String phoneNumber, String email, String employeeId, String department, String specialization) {
        super(name, address, phoneNumber, email);
        this.employeeId = employeeId;
        this.department = department;
        this.specialization = specialization;
    }

    @Override
    public void viewDetails() {
        super.viewDetails();
        System.out.println("Employee ID: " + employeeId);
        System.out.println("Department: " + department);
        System.out.println("Specialization: " + specialization);
    }

    public void setEmployeeId(String employeeId) {
        this.employeeId = employeeId;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public void setSpecialization(String specialization) {
        this.specialization = specialization;
    }
}