package Business;

public class ElectricCar implements ICar {
    private final int id;
    private double universalTax = 50;

    public ElectricCar(int id) {
        this.id = id;
    }

    @Override
    public double computeTax() {
        return universalTax;
    }

    @Override
    public int getID() {
        return id;
    }

    public void setUniversalTax(double universalTax) {
        this.universalTax = universalTax;
    }
}
