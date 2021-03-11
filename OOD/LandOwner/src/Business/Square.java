package Business;

public class Square implements Shape{

    private double side;
    private int id;

    public Square(double side, int id) {
        super();
        this.side = side;
        this.id = id;
    }

    @Override
    public double computeArea() {
        return side * side;
    }

    @Override
    public int getID() {
        return id;
    }

}
