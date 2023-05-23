public interface LibraryManagementSystem {
    void addBook(String bookId, String title, int totalCopies);

    void addMember(String memberId, String name, String dateOfBirth);

    void viewAllBooks();

    void viewAllMembers();

    void searchBook(String bookId);

    void searchMember(String memberId);

    void issueBook(String memberId, String bookId);

    void returnBook(String memberId, String bookId);
}