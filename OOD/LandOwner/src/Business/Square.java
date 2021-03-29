package Business;

public class Square implements IShape {

    private final double side;
    private final int id;

    public Square(double side, int id) {
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
