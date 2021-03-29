package Business;

public class InternalCombustionCar implements ICar {
    private final double engine;
    private final int id;
    private final InternalCombustionCarTax tax;

    public InternalCombustionCar(double engine, int id, String engineType) {
        this.engine = engine;
        this.id = id;
        this.tax = new InternalCombustionCarTax(engineType);
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
