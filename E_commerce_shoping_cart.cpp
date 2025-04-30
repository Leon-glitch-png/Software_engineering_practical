#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int productId;
    string name;
    double price;
    int quantity;

    Item(int id, string n, double p, int q) : productId(id), name(n), price(p), quantity(q) {}

    double getTotalPrice() const
    {
        return price * quantity;
    }
};

class Promotion
{
public:
    string promoCode;
    double discountPercentage;

    Promotion(string code, double discount) : promoCode(code), discountPercentage(discount) {}

    bool validate()
    {
        return !promoCode.empty();
    }
};

class ShippingInfo
{
public:
    string address;
    vector<string> deliveryOptions;
    double taxRate;

    ShippingInfo(string addr = "", double tax = 0.0) : address(addr), taxRate(tax) {}

    double calculateTax()
    {
        return taxRate;
    }
};

class Order
{
public:
    int orderId;
    vector<Item> items;
    double totalAmount;
    string deliveryAddress;

    Order() : orderId(0), totalAmount(0.0) {}

    bool completeOrder()
    {
        cout << "\nOrder Completed! Total Amount: $" << totalAmount << endl;
        return true;
    }
};

class ShoppingCart
{
public:
    vector<Item> items;
    ShippingInfo shippingInfo;
    vector<Promotion> promotions;

    void addItem(Item item)
    {
        items.push_back(item);
    }

    void changeQuantity(Item item, int qty)
    {
        for (auto &it : items)
        {
            if (it.productId == item.productId)
            {
                it.quantity = qty;
                break;
            }
        }
    }

    vector<Item> viewCart()
    {
        return items;
    }

    double calculateTotal()
    {
        double total = 0.0;
        for (auto &it : items)
        {
            total += it.getTotalPrice();
        }
        for (auto &promo : promotions)
        {
            if (promo.validate())
            {
                total *= (1.0 - promo.discountPercentage / 100.0);
            }
        }
        total += total * shippingInfo.calculateTax();
        return total;
    }

    bool applyPromoCode(Promotion promo)
    {
        if (promo.validate())
        {
            promotions.push_back(promo);
            return true;
        }
        return false;
    }

    Order proceedToCheckout()
    {
        Order order;
        order.items = items;
        order.deliveryAddress = shippingInfo.address;
        order.totalAmount = calculateTotal();
        return order;
    }
};

class User
{
public:
    int userId;
    string name;
    bool isGuest;

    User(int id, string uname, bool guest) : userId(id), name(uname), isGuest(guest) {}

    bool login(const string &credentials)
    {
        return !credentials.empty();
    }

    vector<Item> browseItems()
    {
        return {
            Item(1, "Laptop", 999.99, 1),
            Item(2, "Mouse", 25.50, 1),
            Item(3, "Keyboard", 45.00, 1),
            Item(4, "Headphones", 75.00, 1)};
    }

    void persistCart(ShoppingCart cart)
    {
        cout << "Cart persisted for user " << name << endl;
    }
};

class AdminQA
{
public:
    void startTesting()
    {
        cout << "Admin: Starting tests...\n";
    }

    void writeTestCases()
    {
        cout << "Admin: Writing test cases...\n";
    }

    void testCartReliability()
    {
        cout << "Admin: Testing cart reliability...\n";
    }
};

int main()
{
    int mode;
    cout << "Select mode:\n1. User\n2. AdminQA\nChoice: ";
    cin >> mode;
    cin.ignore();

    if (mode == 1)
    {
        string username, password;
        cout << "\nEnter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);

        User user(101, username, false);
        if (!user.login(password))
        {
            cout << " Login failed!\n";
            return 1;
        }

        cout << "\n Login successful. Welcome, " << username << "!\n";
        ShoppingCart cart;
        vector<Item> availableItems = user.browseItems();

        cout << "\nAvailable items:\n";
        for (const auto &item : availableItems)
        {
            cout << item.productId << ". " << item.name << " - $" << item.price << "\n";
        }

        char choice;
        do
        {
            int itemId, qty;
            cout << "\nEnter product ID to add to cart: ";
            cin >> itemId;
            cout << "Enter quantity: ";
            cin >> qty;

            for (auto &item : availableItems)
            {
                if (item.productId == itemId)
                {
                    item.quantity = qty;
                    cart.addItem(item);
                    break;
                }
            }

            cout << "Add another item? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        string promo;
        cout << "\nEnter promo code (or press Enter to skip): ";
        cin.ignore();
        getline(cin, promo);
        if (!promo.empty())
        {
            Promotion p(promo, 10.0);
            if (cart.applyPromoCode(p))
            {
                cout << "Promo applied.\n";
            }
            else
            {
                cout << " Invalid promo code.\n";
            }
        }

        string address;
        cout << "Enter shipping address: ";
        getline(cin, address);
        cart.shippingInfo = ShippingInfo(address, 0.07);

        cout << "\n🛒 Items in Cart:\n";
        for (const auto &item : cart.viewCart())
        {
            cout << "- " << item.name << " x" << item.quantity << " ($" << item.getTotalPrice() << ")\n";
        }

        cout << "Total with tax and discounts: $" << cart.calculateTotal() << endl;

        Order order = cart.proceedToCheckout();
        order.completeOrder();
    }
    else if (mode == 2)
    {
        AdminQA admin;
        admin.startTesting();
        admin.writeTestCases();
        admin.testCartReliability();
    }
    else
    {
        cout << "Invalid option.\n";
    }

    return 0;
}
