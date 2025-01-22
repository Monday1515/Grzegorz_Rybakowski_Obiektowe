interface Discount { // poprawnie
    double applyDiscount(double price);
}

// Rabat regularny (10%)
class RegularDiscount implements Discount {
    @Override
    public double applyDiscount(double price) {
        return price * 0.90; // 10% rabatu
    }
}

// Rabat sezonowy (20%)
class SeasonalDiscount implements Discount {
    @Override
    public double applyDiscount(double price) {
        return price * 0.80; // 20% rabatu
    }
}

// Rabat świąteczny (15%)
class HolidayDiscount implements Discount {
    @Override
    public double applyDiscount(double price) {
        return price * 0.85; // 15% rabatu
    }
}

class ShoppingCart {
    private Discount discount; 

    public ShoppingCart(Discount discount) {
        this.discount = discount;
    }

    public double calculatePrice(double price) {
        return discount.applyDiscount(price);
    }
}

public class Main {
    public static void main(String[] args) {
        double originalPrice = 100.0; 

        Discount regularDiscount = new RegularDiscount();
        Discount seasonalDiscount = new SeasonalDiscount();
        Discount holidayDiscount = new HolidayDiscount();

        ShoppingCart regularCart = new ShoppingCart(regularDiscount);
        ShoppingCart seasonalCart = new ShoppingCart(seasonalDiscount);
        ShoppingCart holidayCart = new ShoppingCart(holidayDiscount);

        System.out.println("Cena po rabacie regularnym: " + regularCart.calculatePrice(originalPrice));
        System.out.println("Cena po rabacie sezonowym: " + seasonalCart.calculatePrice(originalPrice));
        System.out.println("Cena po rabacie świątecznym: " + holidayCart.calculatePrice(originalPrice));
    }
}
