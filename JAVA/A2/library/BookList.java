package library;

public class BookList {

    private Book[] books;
    private int size;

    public BookList() {
        books = new Book[10];
        size = 0;
    }

    public void addBook(String bookId, String title, int totalCopies, int availableCopies) {
        if (isBookIdUnique(bookId)) {
            books[size] = new Book(bookId, title, totalCopies, availableCopies);
            size++;
        } else {
            System.out.println("Book ID already exists.");
        }
    }

    public void addMoreCopies(String bookId, int numberOfCopies) {
        if (isBookIdValid(bookId)) {
            for (int i = 0; i < size; i++) {
                if (books[i].getBookId().equals(bookId)) {
                    books[i].setTotalCopies(books[i].getTotalCopies() + numberOfCopies);
                    books[i].setAvailableCopies(books[i].getAvailableCopies() + numberOfCopies);
                    break;
                }
            }
        } else {
            System.out.println("Book ID does not exist.");
        }
    }

    public void showAllBooks() {
        for (int i = 0; i < size; i++) {
            System.out.println(books[i].toString());
        }
    }

    public void showBookDetails(String bookId) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                System.out.println(books[i].toString());
                break;
            }
        }
    }

    public boolean isBookIdUnique(String bookId) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                return false;
            }
        }
        return true;
    }

    public boolean isBookIdValid(String bookId) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                return true;
            }
        }
        return false;
    }

    public int getAvailableCopies(String bookId) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                return books[i].getAvailableCopies();
            }
        }
        return 0;
    }

    public void decreaseAvailableCopies(String bookId) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                books[i].setAvailableCopies(books[i].getAvailableCopies() - 1);
                break;
            }
        }
    }

    public void increaseAvailableCopies(String bookId) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                books[i].setAvailableCopies(books[i].getAvailableCopies() + 1);
                break;
            }
        }
    }
}

