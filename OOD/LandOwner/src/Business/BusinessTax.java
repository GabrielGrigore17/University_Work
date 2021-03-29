package Business;

public class BusinessTax implements ITax {
    @Override
    public double computeTaxForTaxPayer(double land) {
        return land * 0.1;
    }
}
