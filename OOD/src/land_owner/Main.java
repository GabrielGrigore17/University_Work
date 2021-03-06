package land_owner;

public class Main {
    public static void main(String[] args) {
        Person person = new Person("Andrei", 1000);

        System.out.println(person.getName());
        person.buy_land(100, 12345, 300);
        person.buy_land(200, 12335, 250, 200);
        System.out.println(person.get_land_area());
        person.sell_land(12335);
        System.out.println(person.get_land_area());
        person.buy_land(1200, 22325, 120);
        System.out.println(person.get_land_area());
    }
}
