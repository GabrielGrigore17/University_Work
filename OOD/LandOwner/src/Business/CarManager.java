package Business;

import java.util.ArrayList;
import java.util.List;

public class CarManager {

    List<Car> cars = new ArrayList<>();

    public void addCar(Car carToAdd){
        for (Car car : cars){
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
        for (Car car : cars){
            tax += car.computeTax();
        }
        return tax;
    }
}
