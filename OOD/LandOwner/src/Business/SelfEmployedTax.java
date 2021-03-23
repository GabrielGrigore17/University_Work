package Business;

public class SelfEmployedTax implements Tax{
    @Override
    public double computeTaxForTaxPayer(double land) {
        return land * 0.2;
    }
}
