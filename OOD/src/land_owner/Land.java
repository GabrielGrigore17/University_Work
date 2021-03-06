package land_owner;

public class Land {
    private final Shape shape;
    private final int id;
    private final double price;

    public Land(int id, double price, double width, double length) {
        this.shape = new Shape(width, length);
        this.id = id;
        this.price = price;
    }

    public Land(int id, double price, double width) {
        this.shape = new Shape(width);
        this.id = id;
        this.price = price;
    }

    public int getId() {
        return id;
    }

    public double getPrice(){
        return price;
    }

    public double getArea(){
        return shape.return_area();
    }
}
