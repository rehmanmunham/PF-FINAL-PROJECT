#include <iostream>
#include <string>

using namespace std;



void displayWelcomeMessage() 
{
    cout <<"---------------------------------"<<endl;
	cout <<"|Welcome to the Pos Terminal    |"<<endl;
    cout <<"|1. Add a Item                  |"<<endl;
    cout <<"|2. View Cart                   |"<<endl;
    cout <<"|3. CheckOut                    |"<<endl;
    cout <<"|4. Settings                    |"<<endl;
    cout <<"|5. Exit                        |"<<endl;
    cout <<"---------------------------------";
}

void viewItems(string itemNames[], int itemPrice[], int itemCount) {
    if (itemCount == 0) {
        cout << "No Products Added.\n";
    } else {
        cout << "Cart:\n";
        int total = 0;
        for (int i = 0; i < itemCount; i++) {
        total += itemPrice[i];
        }
        cout<<"----------------------------------"<<endl;
        cout<<"|Total: $" << total << "                     "<<endl;
        for (int i = 0; i < itemCount; i++) {
       cout <<"|"<<i + 1 << ". " << itemNames[i] << " ----------- " << itemPrice[i]<<"$" << "             "<<endl;
        
		}
    }
    cout<<"----------------------------------"<<endl;
}

void addItem(string itemNames[], int itemPrice[], int& itemCount) {
        int cartsize=10;
	if (itemCount <cartsize)
	 {
        int total=0;
		cout << "Enter the item name: ";
        cin >> itemNames[itemCount];
        cout << "Enter " << itemNames[itemCount] << "'s Price: ";
        cin >> itemPrice[itemCount];
        
		itemCount++;
        cout << "Item added to cart!\n";}
     
	else {
        cout << "Maximum number of items reached.\n";
    }
     
}
int main() 
{
    string itemNames[50];
    int itemPrice[50];
    int itemCount = 0;
    int choice;
    int total=0;
    

    displayWelcomeMessage();
    
    
    do {
        cout<<"\nEnter your Choice :";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                addItem(itemNames, itemPrice, itemCount);
                break;
            case 2:
                viewItems(itemNames, itemPrice, itemCount);
                break;
            case 3:
            	 if (itemCount == 0) {
                    cout << "Cart is empty. Please add items first.\n";
                } 
				else {
            	cout<<"\n";
            	cout<<"\n";
            	cout<<"\n";
                viewItems(itemNames, itemPrice, itemCount);
                cout<<total;
                cout << "Proceed with checkout? (y/n): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                cout << "\nThank you for shopping!\n";}
                for (int i = 0; i < itemCount; i++) {
                itemNames[i] = "";
                itemPrice[i] = 0;
                }
                itemCount = 0;
				break;
            case 4:
            cout << "Exiting the program.\n";
                break;
			case 5:
			default:
                cout << "Invalid choice. Please try again.\n";
				}
        }
    } while (choice != 4);

    return 0;
}



