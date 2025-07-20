# Inventory Management System

A simple yet efficient console-based inventory management system written in C that helps you track and manage your product inventory with ease.

## Features

- **Add Products**: Add new products to your inventory or update quantities of existing products
- **View Inventory**: Display all products with their IDs, names, and quantities
- **Dead Stock Detection**: Identify products with zero quantity
- **Sell Products**: Process sales and automatically update inventory quantities
- **Delete Products**: Remove products from the inventory
- **Data Persistence**: Automatically save and load inventory data from file
- **Case-Insensitive Search**: Product names are handled case-insensitively for better user experience
- **Unique Product IDs**: Auto-generated unique IDs using timestamps and random numbers

## Project Structure

```
Inventory_management_system/
├── inventory_management_system.c    # Main source code
├── inventory_management_system.exe  # Compiled executable
├── inventory.txt                   # Data storage file (created automatically)
└── README.md                      # This file
```

## Prerequisites

- GCC compiler (MinGW/MSYS2 recommended for Windows)
- Windows OS (uses Windows-specific headers)

## Compilation

To compile the program, use the following command:

```bash
gcc -o inventory_management_system inventory_management_system.c
```

Or use the VS Code build task if available:
- Press `Ctrl+Shift+P`
- Select "Tasks: Run Build Task"
- Choose "C/C++: gcc.exe build active file"

## Usage

1. Run the executable:
   ```bash
   ./inventory_management_system.exe
   ```

2. Follow the on-screen menu options:
   - **Option 1**: Add a product to inventory
   - **Option 2**: Show all products in inventory
   - **Option 3**: View dead stock (products with 0 quantity)
   - **Option 4**: Sell products (reduce quantity)
   - **Option 5**: Delete a product from inventory
   - **Option 6**: Exit the program

## Data Storage

The program automatically saves inventory data to `inventory.txt` in the following format:
```
[Product_ID] [Product_Name] [Quantity]
```

Example:
```
1721526543-1234 Apple 50
1721526550-5678 Orange 30
```

## Code Structure

### Main Components

- **Data Structure**: Linked list implementation for dynamic inventory management
- **File Operations**: Automatic save/load functionality for data persistence
- **User Interface**: Interactive console menu with loading animations
- **Core Functions**:
  - `push()`: Add or update products
  - `showinventory()`: Display all products
  - `deadstock()`: Show products with zero quantity
  - `sell()`: Process sales transactions
  - `deleteProduct()`: Remove products
  - `savefile()` & `loadInventoryFromFile()`: Data persistence

### Key Features Implementation

- **Case-Insensitive Handling**: Uses `toLowerCase()` function for consistent product name comparison
- **Duplicate Prevention**: Automatically updates quantity if product already exists
- **Input Validation**: Checks for sufficient stock before selling
- **Memory Management**: Proper allocation and deallocation of linked list nodes

## Example Usage

```
Welcome to IMS
Press Enter to continue...
Loading [####################]

|**Enter your option**|
1: Add your product
2: Show the list
3: Dead stock
4: Sell
5: Delete product
6: Exit

Enter your choice: 1
Enter product name: Apple
Enter product quantity: 100

Enter your choice: 2
List of products:
Product ID: 1721526543-1234, Name: Apple, Quantity: 100
```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## Future Enhancements

- Add product categories and descriptions
- Implement search functionality
- Add low stock alerts
- Create a GUI version
- Add barcode scanning support
- Implement user authentication
- Add reporting and analytics features

## License

This project is open source and available under the [MIT License](LICENSE).

## Author

Created as part of an inventory management learning project.

## Troubleshooting

**Common Issues:**

1. **Compilation Errors**: Ensure you have GCC installed and properly configured
2. **File Access Issues**: Make sure the program has write permissions in the directory
3. **Data Loss**: The program automatically saves data, but ensure proper exit using option 6

**System Requirements:**
- Windows OS (due to Windows.h dependency)
- Minimum 1MB free disk space
- Console/terminal access

---

*Last updated: July 2025*
