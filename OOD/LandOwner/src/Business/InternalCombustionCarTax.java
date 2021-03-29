package Business;

import java.util.Hashtable;
import java.util.Map;

public class InternalCombustionCarTax implements ITax {

    Hashtable<Integer, Double> gasolineIntervals = new Hashtable<>();
    Hashtable<Integer, Double> dieselIntervals = new Hashtable<>();
    String engineType;


    public InternalCombustionCarTax(String engineType) {
        this.engineType = engineType.toLowerCase();

        this.gasolineIntervals.put(1000, 0.2);
        this.gasolineIntervals.put(1500, 0.3);
        this.gasolineIntervals.put(2000, 0.4);
        this.dieselIntervals.put(1000, 0.3);
        this.dieselIntervals.put(1500, 0.4);
        this.dieselIntervals.put(2000, 0.5);
    }

    @Override
    public double computeTaxForTaxPayer(double engineSize) {
        int engineInterval = 0;
        switch (engineType){
            case "diesel":
                for (Map.Entry<Integer, Double> e : dieselIntervals.entrySet()){
                    if(e.getKey() < engineSize && e.getKey() > engineInterval)
                        engineInterval = e.getKey();
                }
                return engineSize * dieselIntervals.get(engineInterval);
            case "gasoline":
                for (Map.Entry<Integer, Double> e : gasolineIntervals.entrySet()){
                    if(e.getKey() < engineSize && e.getKey() > engineInterval)
                        engineInterval = e.getKey();
                }
                return engineSize * gasolineIntervals.get(engineInterval);
            default:
                return -1;
        }
    }

    public void addGasolineInterval(int engineSize, double interval){
        int engineInterval = 0;
        for (Map.Entry<Integer, Double> e : gasolineIntervals.entrySet()){
            if(e.getKey() < engineSize && e.getKey() > engineInterval)
                engineInterval = e.getKey();
        }
        if(gasolineIntervals.get(engineInterval) < interval)
            this.gasolineIntervals.put(engineSize, interval);
    }
    public void addDieselInterval(int engineSize, double interval){
        int engineInterval = 0;
        for (Map.Entry<Integer, Double> e : dieselIntervals.entrySet()){
            if(e.getKey() < engineSize && e.getKey() > engineInterval)
                engineInterval = e.getKey();
        }
        if(dieselIntervals.get(engineInterval) < interval)
            this.dieselIntervals.put(engineSize, interval);
    }
}
