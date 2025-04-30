
# 🛒 E-Commerce Shopping Cart (C++ Console App)

This is a **console-based e-commerce shopping cart system** implemented using **C++ and Object-Oriented Programming (OOP)** concepts. It allows users to simulate online shopping with item selection, promo codes, and checkout, along with a separate mode for AdminQA testing.

---

## 📂 Features

### 👤 User Mode
- Simulated login using username and password
- Browse and add items to the cart
- Change item quantities
- Apply promo codes (e.g., `SUMMER10` for 10% off)
- Provide a shipping address
- Calculate total including tax and discount
- Checkout and display order summary

### 🧪 AdminQA Mode
- Simulate admin testing process:
  - Start testing
  - Write test cases
  - Test shopping cart reliability

---

## 🧱 Classes Used

| Class         | Description |
|---------------|-------------|
| `Item`        | Represents a product with ID, name, price, and quantity |
| `Promotion`   | Handles promo codes and discounts |
| `ShippingInfo`| Stores address and tax rate |
| `Order`       | Final order object after checkout |
| `ShoppingCart`| Manages the user's cart, promotions, and order processing |
| `User`        | Represents a customer with browsing and login features |
| `AdminQA`     | Represents admin for quality assurance testing |

---

## 💻 How to Run

1. **Compile the program** using a C++ compiler (e.g., `g++`):
   ```bash
   g++ -o ecommerce_app main.cpp
   ```

2. **Run the executable**:
   ```bash
   ./ecommerce_app
   ```

3. **Select a mode**:
   - `1` for User interaction
   - `2` for Admin testing

---

## 📌 Example User Flow

```
Select mode:
1. User
2. AdminQA
Choice: 1

Enter username: Alice
Enter password: 1234

Login successful. Welcome, Alice!

Available items:
1. Laptop - $999.99
2. Mouse - $25.50
...

Enter product ID to add to cart: 1
Enter quantity: 2
Add another item? (y/n): n

Enter promo code (or press Enter to skip): SUMMER10
Promo applied.

Enter shipping address: 123 Main St

🛒 Items in Cart:
- Laptop x2 ($1999.98)

Total with tax and discounts: $1925.98
Order Completed! Total Amount: $1925.98
```

---

## 🛠️ Future Improvements
- Add file persistence for cart data
- Implement real promo code validation
- Enhance AdminQA with test result logging
- Support for guest checkout
- GUI version using frameworks like Qt or SFML

---

## 📃 License

This project is open-source and can be used for educational or personal purposes.

---

