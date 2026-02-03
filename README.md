# E-Cart-Manager
This E-commerce Cart Management System efficiently handles cart operations.


This is a simple **console-based application in C** that simulates an e-commerce cart system. It allows users to select items, add them to a cart, view the cart, place an order, and remove or clear items. It uses a **linked list** data structure to manage cart items dynamically.

## Features

- View available main items (Laptop, Smartphone, Headphones, Keyboard, Mouse)
- Choose from sub-items (e.g., Laptop-1, Laptop-2)
- Add items to cart with quantity
- View cart contents
- Remove specific items from cart
- Clear all cart items
- Place an order (view summary and clear cart)

## Data Structures Used

- **Struct `Item`**: Represents available items with an ID and name.
- **Struct `Node`**: Represents each cart entry with item ID, quantity, and pointer to next node (for linked list).

## How It Works

- Main items (IDs < 10) are shown first.
- When a main item is selected, the user can choose from its available sub-items.
- The cart is maintained using a linked list (`Node`).
- Each function provides core functionality like `addItem`, `viewCart`, `clearCart`, `removeItem`, and `placeOrder`.

## Compilation

Use any standard C compiler. For example, using `gcc`:

```bash
gcc cart_system.c -o cart_system
./cart_system
```

## Menu Options

```
1. Add Item to Cart
2. View Cart
3. Clear Cart
4. Place Order
5. Remove Item
6. Exit
```

## Example Flow

1. Select "Add Item to Cart"
2. Choose Item ID (e.g., `1` for Laptop)
3. Choose sub-item (e.g., `1` for Laptop-1)
4. Enter quantity (e.g., `2`)
5. View cart or place order when ready

## Notes

- Only main item IDs (1–5) are shown initially. Sub-items are prompted upon selection.
- The system validates all inputs for valid IDs and sub-item options.
- Memory is properly freed when the cart is cleared or on exit.

## Author

This code is part of a mini-project demonstrating the use of **linked lists** in **C programming** for managing dynamic data in an e-commerce context.
