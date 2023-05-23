package BookList;

public class Book {
    private String bookId;
    private String title;
    private int totalCopies;
    private int availableCopies;

    // Constructor
    public Book(String bookId, String title, int totalCopies) {
        this.bookId = bookId;
        this.title = title;
        this.totalCopies = totalCopies;
        this.availableCopies = totalCopies;
    }

    // Getters and Setters
    public String getBookId() {
        return bookId;
    }

    public String getTitle() {
        return title;
    }

    public int getTotalCopies() {
        return totalCopies;
    }

    public int getAvailableCopies() {
        return availableCopies;
    }

    public void setTotalCopies(int totalCopies) {
        this.totalCopies = totalCopies;
    }

    public void setAvailableCopies(int availableCopies) {
        this.availableCopies = availableCopies;
    }

    // Method to increase the total and available copies
    public void increaseCopies(int additionalCopies) {
        totalCopies += additionalCopies;
        availableCopies += additionalCopies;
    }

    // Method to decrease the total and available copies
    public void decreaseCopies(int issuedCopies) {
        availableCopies -= issuedCopies;
    }
}
