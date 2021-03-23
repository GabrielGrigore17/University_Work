package Business;

public class BusinessTax implements Tax{
    @Override
    public double computeTaxForTaxPayer(double land) {
        return land * 0.1;
    }
}
