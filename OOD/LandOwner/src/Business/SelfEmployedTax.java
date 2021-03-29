package Business;

public class SelfEmployedTax implements ITax {
    @Override
    public double computeTaxForTaxPayer(double land) {
        return land * 0.2;
    }
}
