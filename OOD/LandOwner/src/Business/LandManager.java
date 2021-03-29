package Business;

import java.util.ArrayList;
import java.util.List;

public class LandManager {

    List<IShape> lands = new ArrayList<>();

    public void buyLand(IShape shape){
        for (IShape land : lands){
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
        for (IShape land : lands){
            area += land.computeArea();
        }
        return area;
    }
}
