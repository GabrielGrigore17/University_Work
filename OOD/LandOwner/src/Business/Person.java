package Business;

import java.util.ArrayList;
import java.util.List;

public class Person {
    private final String name;
    private double budget;
    private final List<Land> list_of_lands = new ArrayList<>();
    private final List<Integer> list_of_ids = new ArrayList<>();

    public Person(String name, double budget) {
        this.name = name;
        this.budget = budget;
    }

    public String getName() {
        return name;
    }

    public void buy_land(double price, int land_id, double width, double length){
        if (list_of_ids.contains(land_id)){
            System.out.println("Land ID already registered");
            return;
        }
        if(budget >= price) {
            list_of_lands.add(new Land(land_id, price, width, length));
            list_of_ids.add(land_id);
            budget -= price;
        }
        else
            System.out.println("Not enough funds");
    }

    public void buy_land(double price, int land_id, double width){
        if (list_of_ids.contains(land_id)){
            System.out.println("Land ID already registered");
            return;
        }
        if(budget >= price) {
            list_of_lands.add(new Land(land_id, price, width));
            list_of_ids.add(land_id);
            budget -= price;
        }
        else
            System.out.println("Not enough funds");
    }

    public void sell_land(int id){
        for(int i = 0; i < list_of_lands.size(); i++)
            if(list_of_lands.get(i).getId() == id) {
                list_of_ids.remove((Integer) (id));
                budget += list_of_lands.get(i).getPrice();
                list_of_lands.remove(i);
                i--;

            }
    }

    public double get_land_area(){
        double area = 0;
        for (Land land : list_of_lands) {
            area += land.getArea();
        }
        return area;
    }
}
