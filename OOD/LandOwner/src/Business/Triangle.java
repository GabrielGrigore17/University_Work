package Business;

public class Triangle implements Shape{

    private final double side;
    private final double height;
    private final int id;

    public Triangle(double side, double height, int id) {
        this.side = side;
        this.height = height;
        this.id = id;
    }

    @Override
    public double computeArea() {
        return (side * height)/2;
    }

    @Override
    public int getID() {
        return id;
    }

}
