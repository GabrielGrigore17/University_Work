package Business;

import java.util.ArrayList;
import java.util.List;

public class CarManager {

    List<ICar> cars = new ArrayList<>();

    public void addCar(ICar carToAdd){
        for (ICar car : cars){
            if(car.getID() == carToAdd.getID())
                return;
        }
        cars.add(carToAdd);
    }

    public void removeCar(int id){
        cars.removeIf(car -> car.getID() == id);
    }

    public double computeTotalTax(){
        double tax = 0;
        for (ICar car : cars){
            tax += car.computeTax();
        }
        return tax;
    }
}
