package Business;

public class DieselCar implements Car{
    private final double engine;
    private final int id;
    private final DieselCarTax tax = new DieselCarTax();

    public DieselCar(double engine, int id) {
        this.engine = engine;
        this.id = id;
    }

    @Override
    public double computeTax() {
        return tax.computeTaxForTaxPayer(engine);
    }

    @Override
    public int getID() {
        return id;
    }
}
