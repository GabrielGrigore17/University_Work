package Business;

public class ElectricCar implements Car{
    private final int id;
    private final ElectricCarTax tax = new ElectricCarTax();

    public ElectricCar(int id) {
        this.id = id;
    }

    @Override
    public double computeTax() {
        return tax.computeTaxForTaxPayer(0);
    }

    @Override
    public int getID() {
        return id;
    }
}
