package Business;

public class Rectangle implements IShape {

    private final double height;
    private final double width;
    private final int id;

    public Rectangle(double height, double width, int id) {
        this.height = height;
        this.width = width;
        this.id = id;
    }

    @Override
    public double computeArea() {
        return width * height;
    }

    @Override
    public int getID() {
        return id;
    }

}
