import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import BookList.Book;
import MemberList.Member;
import Transaction.TransactionEntry;

public class Q3 implements LibraryManagementSystem {
    private List<Book> bookList;
    private List<Member> memberList;
    private List<TransactionEntry> transactionList;

    public Q3() {
        bookList = new ArrayList<>();
        memberList = new ArrayList<>();
        transactionList = new ArrayList<>();
    }

    @Override
    public void addBook(String bookId, String title, int totalCopies) {
        Book existingBook = findBook(bookId);
        if (existingBook == null) {
            Book book = new Book(bookId, title, totalCopies);
            bookList.add(book);
            System.out.println("Book added successfully!");
        } else {
            System.out.println("Book with the same ID already exists.");
        }
    }

    @Override
    public void addMember(String memberId, String name, String dateOfBirth) {
        Member existingMember = findMember(memberId);
        if (existingMember == null) {
            Member member = new Member(memberId, name, dateOfBirth);
            memberList.add(member);
            System.out.println("Member added successfully!");
        } else {
            System.out.println("Member with the same ID already exists.");
        }
    }

    @Override
    public void viewAllBooks() {
        if (bookList.isEmpty()) {
            System.out.println("No books found.");
        } else {
            System.out.println("Book List:");
            for (Book book : bookList) {
                System.out.println("Book ID: " + book.getBookId());
                System.out.println("Title: " + book.getTitle());
                System.out.println("Total Copies: " + book.getTotalCopies());
                System.out.println("Available Copies: " + book.getAvailableCopies());
                System.out.println("------------------------");
            }
        }
    }

    @Override
    public void viewAllMembers() {
        if (memberList.isEmpty()) {
            System.out.println("No members found.");
        } else {
            System.out.println("Member List:");
            for (Member member : memberList) {
                System.out.println("Member ID: " + member.getMemberId());
                System.out.println("Name: " + member.getName());
                System.out.println("Date of Birth: " + member.getDateOfBirth());
                System.out.println("------------------------");
            }
        }
    }

    @Override
    public void searchBook(String bookId) {
        Book book = findBook(bookId);
        if (book != null) {
            System.out.println("Book Details:");
            System.out.println("Book ID: " + book.getBookId());
            System.out.println("Title: " + book.getTitle());
            System.out.println("Total Copies: " + book.getTotalCopies());
            System.out.println("Available Copies: " + book.getAvailableCopies());
        } else {
            System.out.println("Book not found.");
        }
    }

    @Override
    public void searchMember(String memberId) {
        Member member = findMember(memberId);
        if (member != null) {
            System.out.println("Member Details:");
            System.out.println("Member ID: " + member.getMemberId());
            System.out.println("Name: " + member.getName());
            System.out.println("Date of Birth: " + member.getDateOfBirth());
            System.out.println("Books Issued: " + member.getBooksIssued());
        } else {
            System.out.println("Member not found.");
        }
    }

    @Override
    public void issueBook(String memberId, String bookId) {
        Member member = findMember(memberId);
        Book book = findBook(bookId);

        if (member != null && book != null) {
            if (member.getBooksIssued() < 3 && book.getAvailableCopies() > 0) {
                transactionList.add(new TransactionEntry(memberId, bookId));
                book.decreaseCopies(1);
                member.incrementBooksIssued();
                System.out.println("Book issued successfully!");
            } else {
                System.out.println("Cannot issue the book. Check member eligibility and book availability.");
            }
        } else {
            System.out.println("Member or book not found.");
        }
    }

    @Override
    public void returnBook(String memberId, String bookId) {
        TransactionEntry transactionEntry = findTransaction(memberId, bookId);

        if (transactionEntry != null) {
            Member member = findMember(memberId);
            Book book = findBook(bookId);

            if (member != null && book != null) {
                transactionEntry.markReturned();
                book.setAvailableCopies(book.getAvailableCopies() + 1);
                member.decrementBooksIssued();
                System.out.println("Book returned successfully!");
            } else {
                System.out.println("Member or book not found.");
            }
        } else {
            System.out.println("Transaction entry not found.");
        }
    }

    @Override
    public void addCopies(String bookId, int copies) {
        Book book = findBook(bookId);
        if (book != null) {
            book.increaseCopies(copies);
            System.out.println("Copies added successfully!");
        } else {
            System.out.println("Book not found.");
        }
    }

    private Book findBook(String bookId) {
        for (Book book : bookList) {
            if (book.getBookId().equals(bookId)) {
                return book;
            }
        }
        return null;
    }

    private Member findMember(String memberId) {
        for (Member member : memberList) {
            if (member.getMemberId().equals(memberId)) {
                return member;
            }
        }
        return null;
    }

    private TransactionEntry findTransaction(String memberId, String bookId) {
        for (TransactionEntry transactionEntry : transactionList) {
            if (transactionEntry.getMemberId().equals(memberId) && transactionEntry.getBookId().equals(bookId)) {
                return transactionEntry;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        LibraryManagementSystem library = new Q3();

        int choice = 0;
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("1. Add new book in booklist");
            System.out.println("2. Add more copies for a book");
            System.out.println("3. Show all book details");
            System.out.println("4. Show details of a book");
            System.out.println("5. Add member in the list");
            System.out.println("6. Show all members");
            System.out.println("7. Show details of a member");
            System.out.println("8. Issue a book");
            System.out.println("9. Return a book");
            System.out.println("---------------q4-----------------");
            System.out.println("10. Search book");
            System.out.println("11. Search member");
            System.out.println("12. exit");
            System.out.println("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine();
            switch (choice) {
                case 1:
                    System.out.println("Enter book id: ");
                    String bookId = sc.nextLine();
                    System.out.println("Enter title: ");
                    String title = sc.nextLine();
                    // sc.nextLine();
                    System.out.println("Enter total copies: ");
                    int totalCopies = sc.nextInt();
                    library.addBook(bookId, title, totalCopies);
                    break;
                case 2:
                    System.out.println("Enter book id: ");
                    bookId = sc.nextLine();
                    System.out.println("Enter number of copies to be added: ");
                    int copies = sc.nextInt();
                    library.addCopies(bookId, copies);
                    break;
                case 3:
                    library.viewAllBooks();
                    break;
                case 4:
                    System.out.println("Enter book id: ");
                    bookId = sc.nextLine();
                    library.searchBook(bookId);
                    break;
                case 5:
                    System.out.println("Enter member id: ");
                    String memberId = sc.nextLine();
                    System.out.println("Enter name: ");
                    String name = sc.nextLine();
                    System.out.println("Enter date of birth: ");
                    String dateOfBirth = sc.nextLine();
                    library.addMember(memberId, name, dateOfBirth);
                    break;
                case 6:
                    library.viewAllMembers();
                    break;
                case 7:
                    System.out.println("Enter member id: ");
                    memberId = sc.nextLine();
                    library.searchMember(memberId);
                    break;
                case 8:
                    System.out.println("Enter member id: ");
                    memberId = sc.nextLine();
                    System.out.println("Enter book id: ");
                    bookId = sc.nextLine();
                    library.issueBook(memberId, bookId);
                    break;
                case 9:
                    System.out.println("Enter member id: ");
                    memberId = sc.nextLine();
                    System.out.println("Enter book id: ");
                    bookId = sc.nextLine();
                    library.returnBook(memberId, bookId);
                    break;
                case 10:
                    System.out.println("Enter book id: ");
                    bookId = sc.nextLine();
                    library.searchBook(bookId);
                    break;
                case 11:
                    System.out.println("Enter member id: ");
                    memberId = sc.nextLine();
                    library.searchMember(memberId);
                    break;
                case 12:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;

            }
        }

    }

}
