package library;

import java.util.Scanner;

public class LibraryManagementSystem {

    private BookList bookList;
    private MemberList memberList;
    private TransactionList transactionList;

    public LibraryManagementSystem() {
        bookList = new BookList();
        memberList = new MemberList();
        transactionList = new TransactionList();
    }

    public void addNewBook(String bookId, String title, int totalCopies, int availableCopies) {
        if (bookList.isBookIdUnique(bookId)) {
            bookList.addBook(bookId, title, totalCopies, availableCopies);
        } else {
            System.out.println("Book ID already exists.");
        }
    }

    public void addMoreCopies(String bookId, int numberOfCopies) {
        if (bookList.isBookIdValid(bookId)) {
            bookList.addMoreCopies(bookId, numberOfCopies);
        } else {
            System.out.println("Book ID does not exist.");
        }
    }

    public void showAllBooks() {
        bookList.showAllBooks();
    }

    public void showBookDetails(String bookId) {
        if (bookList.isBookIdValid(bookId)) {
            bookList.showBookDetails(bookId);
        } else {
            System.out.println("Book ID does not exist.");
        }
    }

    public void addMember(String memberId, String name, String dateOfBirth) {
        if (memberList.isMemberIdUnique(memberId)) {
            memberList.addMember(memberId, name, dateOfBirth);
        } else {
            System.out.println("Member ID already exists.");
        }
    }

    public void showAllMembers() {
        memberList.showAllMembers();
    }

    public void showMemberDetails(String memberId) {
        if (memberList.isMemberIdValid(memberId)) {
            memberList.showMemberDetails(memberId);
        } else {
            System.out.println("Member ID does not exist.");
        }
    }

    public void issueBook(String bookId, String memberId) {
        if (bookList.isBookIdValid(bookId) && memberList.isMemberIdValid(memberId)) {
            if (bookList.getAvailableCopies(bookId) > 0 && memberList.getNoOfBooksIssued(memberId) < getMaxNoOfBooksPerMember()) {
                transactionList.addTransaction(bookId, memberId);
                bookList.decreaseAvailableCopies(bookId);
                memberList.increaseNoOfBooksIssued(memberId);
            } else {
                System.out.println("Book is either not available or the member has already reached the maximum limit of issued books.");
            }
        } else {
            System.out.println("Book ID or Member ID does not exist.");
        }
    }

    public void returnBook(String bookId, String memberId) {
        if (transactionList.isTransactionValid(bookId, memberId)) {
            transactionList.markTransactionAsReturned(bookId, memberId);
            bookList.increaseAvailableCopies(bookId);
            memberList.decreaseNoOfBooksIssued(memberId);
        } else {
            System.out.println("Book ID or Member ID does not exist or the book has not been issued to the member.");
        }
    }

    private int getMaxNoOfBooksPerMember() {
        return 5;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to the Library Management System.");

        while (true) {
            System.out.println("What would you like to do?");
            System.out.println("1. Add a new book");
            System.out.println("2. Add more copies for a book");
            System.out.println("3. Show all book details");
            System.out.println("4. Show details of a book");
            System.out.println("5. Add a new member");
            System.out.println("6. Show all members");
            System.out.println("7. Show details of a member");
            System.out.println("8. Issue a book");
            System.out.println("9. Return a book");
            System.out.println("10. Exit");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter the book ID: ");
                    String bookId = scanner.next();
                    System.out.println("Enter the book title: ");
                    String title = scanner.next();
                    System.out.println("Enter the total number of copies: ");
                    int totalCopies = scanner.nextInt();
                    System.out.println("Enter the number of copies available: ");
                    int availableCopies = scanner.nextInt();

                    addNewBook(bookId, title, totalCopies, availableCopies);
                    break;

                case 2:
                    System.out.println("Enter the book ID: ");
                    bookId = scanner.next();
                    System.out.println("Enter the number of copies to add: ");
                    numberOfCopies = scanner.nextInt();

                    addMoreCopies(bookId, numberOfCopies);
                    break;

                case 3:
                    bookList.showAllBooks();
                    break;

                case 4:
                    System.out.println("Enter the book ID: ");
                    bookId = scanner.next();

                    bookList.showBookDetails(bookId);
                    break;

                case 5:
                    System.out.println("Enter the member ID: ");
                    String memberId = scanner.next();
                    System.out.println("Enter the member name: ");
                    String name = scanner.next();
                    System.out.println("Enter the member date of birth: ");
                    String dateOfBirth = scanner.next();

                    addMember(memberId, name, dateOfBirth);
                    break;

                case 6:
                    memberList.showAllMembers();
                    break;

                case 7:
                    System.out.println("Enter the member ID: ");
                    memberId = scanner.next();

                    memberList.showMemberDetails(memberId);
                    break;

                case 8:
                    System.out.println("Enter the book ID: ");
                    bookId = scanner.next();
                    System.out.println("Enter the member ID: ");
                    memberId = scanner.next();

                    issueBook(bookId, memberId);
                    break;

                case 9:
                    System.out.println("Enter the book ID: ");
                    bookId = scanner.next();
                    System.out.println("Enter the member ID: ");
                    memberId = scanner.next();

                    returnBook(bookId, memberId);
                    break;

                case 10:
                    System.out.println("Exiting the library management system.");
                    System.exit(0);

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}

