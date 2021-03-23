package Business;

public class GasolineCar implements Car{
    private final double engine;
    private final int id;
    private final GasolineCarTax tax = new GasolineCarTax();

    public GasolineCar(double engine, int id) {
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
