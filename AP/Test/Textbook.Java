public class Textbook extends Book{
    private int editionNumber;

    public TextBook(String bookTitle, double bookPrice, int edNum) {
        super(bookTitle, bookPrice);
        editionNumber = edNum;
    }

    public int getEdition() {
        return editionNumber;
    }

    public String getBookInfo() {
        String s = super.getBookInfo();
        s = s + "-" + (String) editionNumber;
        return s;
    }

    public boolean canSubstituteFor(TextBook tb) {
        if (this.title != tb.title)
            return false;
        return (this.editionNumber >= tb.getEdition());
    }
}