package Business;

public class Circle implements Shape{

    private final double radix;
    private final int id;

    public Circle(double radix, int id) {
        this.radix = radix;
        this.id = id;
    }

    @Override
    public double computeArea() {
        return radix * radix * 3.14;
    }

    @Override
    public int getID() {
        return id;
    }

}
