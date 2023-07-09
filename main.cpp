#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>

// Structure that will hold the data of an individual product
struct Entity{
  std::string brand;
  std::string name;
  std::string id;
  std::string stock;
  bool state;
};

// Entities class
class Entities{
  private:
    // Array to hold entity objects that contain data such as the brand, name, id and so on...
    std::vector<Entity> entity;

  public:
    // Add a new product
    void add_product(){
      Entity product_entity;
      std::cin.ignore();
      std::cout << "Please enter the brand name: " << std::endl;
      std::getline (std::cin, product_entity.brand);

      std::cout << "Please enter the product name: \n";
      std::getline (std::cin, product_entity.name);

      std::cout << "Please enter the product id: \n";
      std::getline (std::cin, product_entity.id);

      std::cout << "Please enter the available stock: \n";
      std::getline (std::cin, product_entity.stock);
      entity.push_back(product_entity);
    }
    
    // Display the current inventory
    void display_inventory(){
      std::cout << "- - - - - - - - - - > INVENTORY < - - - - - - - - - -\n";
      std::cout << "Brand\t\t Name\t\t ID\t\t Quantity\n";
      std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
      
      // Iterate over the objects and output it's members
      for(const auto& element : entity){
        std::cout << element.brand << "\t\t" << element.name << "\t\t" << element.id << "\t\t" << element.stock << "\n";
      }
    }
    
    // Search for a product
    void search_product(){
      std::string product_id;

      std::cin.ignore();
      std::cout << "Please enter the product id: ";
      std::getline(std::cin, product_id);

      for(const auto& element : entity){
        if(element.id == product_id){
          std::cout << "Product found! \n";
          std::cout << "- - - - - - - - - - > INVENTORY < - - - - - - - - - -\n";
          std::cout << "Brand\t\t Name\t\t ID\t\t Quantity\n";
          std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
          std::cout << element.brand << "\t\t" << element.name << "\t\t" << element.id << "\t\t" << element.stock << "\n";
        }
      }
    }
    
    // Returns a searched product
    Entity search_product(){
      std::string product_id;
      std::cin.ignore();
      std::cout << "Please enter the product id: ";
      std::getline(std::cin, product_id);

      for(const auto& element : entity){
        if(element.id == product_id){
          return element;
        }
      }

      return;

    }
};

// Write data
void write_data(std::string name, std::string source){
  std::ofstream file;
  file.open(source, std::ios_base::app);
  file << name;
  file.close();
}

// Main menu
void display_menu(){
  std::cout << "- - - - - - - - - - > INVENTORY SYSTEM < - - - - - - - - - -\n";
  std::cout << "    1. Add new product\n";
  std::cout << "    2. Update product\n";
  std::cout << "    3. Remove product\n";
  std::cout << "    4. Search for a product\n";
  std::cout << "    5. Run scripts\n";
  std::cout << "    6. View products out of stock\n";
  std::cout << "    7. View inventory\n";
  std::cout << "    8. Exit\n";
  std::cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
}

void sub_menu_action(int result, Entities& e){
  std::cout << "\n";

  switch(result){
    case 1:
      e.add_product();
      break;
    
    case 2:
      std::cout << "\n\n";
      std::cout << "Coming soon";
      break;

    case 3:
      std::cout << "Coming soon";
      break;

    case 4:
      e.search_product();
      break;

    case 5:
      std::cout << "Searching for product out of stock";
      break;

    case 6:
      std::cout << "\n\n";
      e.display_inventory();
      break;
  }
}


int validate_input(int n){
  int value;
  //std::cout << "Please enter a valid operation\n";

  while(!std::cin >> value){
    std::cout << "Invalid operation. Please enter a correct choice.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return value;
}

int fetch_input(){
  int user_input;
  std::cout << "Please select a task to perform: \n";
  std::cin >> user_input;

  return user_input;
}


// Main entry point of the program
int main(){
  bool running = true;
  Entities p;
  while(running){
    std::cout << "\n\n";
    display_menu();
    int input = fetch_input();
    int valid = validate_input(input);
    if(valid == 7){
      running = false;
    }
    sub_menu_action(valid, p);

  }
  
  return 0;
}
