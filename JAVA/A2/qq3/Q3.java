import java.util.ArrayList;
import java.util.List;

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
                book.increaseCopies(1);
                member.decrementBooksIssued();
                System.out.println("Book returned successfully!");
            } else {
                System.out.println("Member or book not found.");
            }
        } else {
            System.out.println("Transaction entry not found.");
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

        // Add books
        library.addBook("B001", "Book 1", 5);
        library.addBook("B002", "Book 2", 3);
        library.addBook("B003", "Book 3", 2);

        // Add members
        library.addMember("M001", "John Doe", "1990-01-01");
        library.addMember("M002", "Jane Smith", "1992-05-15");

        // View all books
        library.viewAllBooks();

        // View all members
        library.viewAllMembers();

        // Search book
        library.searchBook("B002");

        // Search member
        library.searchMember("M001");

        // Issue a book
        library.issueBook("M001", "B001");

        // Return a book
        library.returnBook("M001", "B001");
    }
}
