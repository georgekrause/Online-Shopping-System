#include <iostream>
#include <string>
using namespace std;
#include <vector>

class product {
public:
    std::string name;
    double price;
    int quantity;

    product(std::string n, double p, int q) : name(n), price(p), quantity(q) {}

    double total_price() const {
        return price * quantity;
    }
};

class user {
    public:
        std::string username;
        std::string email;
};

class ShoppingCart {
    private:
        std::vector<product> products;
    public:
        void add_product(const product& p) {
            products.push_back(p);
        }

        double calculate_total() const {
            double total = 0.0;
            for (const auto& p : products) {
                total += p.total_price();
            }
            return total;
        }

        void display_cart() const {
            std::cout << "Shopping Cart:\n";
            for (const auto& p : products) {
                std::cout << p.name << " - $" << p.price << " x " << p.quantity << " = $" << p.total_price() << "\n";
            }
            std::cout << "Total: $" << calculate_total() << "\n";
        }
};

int main() {
    ShoppingCart cart;
    cart.add_product(product("Laptop", 999.99, 1));
    cart.add_product(product("Mouse", 25.50, 2));
    cart.add_product(product("Keyboard", 45.00, 1));

    cart.display_cart();
    system("pause");

    return 0;
}


