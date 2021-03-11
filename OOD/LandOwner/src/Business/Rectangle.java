package Business;

public class Rectangle implements Shape{

    private double height;
    private double width;
    private int id;

    public Rectangle(double height, double width, int id) {
        super();
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
