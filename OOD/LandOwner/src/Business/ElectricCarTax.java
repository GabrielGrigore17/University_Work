package Business;

public class ElectricCarTax implements Tax{
    private static final int universalTax = 10;

    @Override
    public double computeTaxForTaxPayer(double engineSize) {
        return universalTax;
    }
}
