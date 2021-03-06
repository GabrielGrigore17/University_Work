package land_owner;

public class Shape {
    private final double width;
    private final double length;
    private boolean is_square;

    public Shape(double width, double length) {
        this.width = width;
        this.length = length;
        this.is_square = false;
    }

    public Shape(double width){
        this(width, -1);
        this.is_square = true;
    }

    public double return_area(){
        if(is_square)
            return width * width;
        else
            return width * length;
    }
}
