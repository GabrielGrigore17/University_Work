package Business;

import java.util.List;

public class Owner {

    List<Shape> lands;

    public void buyLand(Shape shape){
        for (Shape land : lands){
            if(shape.getID() == land.getID())
                return;
        }
        lands.add(shape);
    }

    public void sellLand(int id){
        lands.removeIf(land -> land.getID() == id);
    }

    public double getTotalArea(){
        double area = 0;
        for (Shape land : lands){
            area += land.computeArea();
        }
        return area;
    }
}
