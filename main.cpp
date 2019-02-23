#include "main.h"


using namespace std;






int main(int argc, const char * argv[]){
    
    try {
        
        
        Bikes b1;
        
        b1.read(argv[1]);
        
        b1.print();
        
        cout << "Total gears: " << b1.getTotalGears() << endl;
        
        cout << "Total capacity: " << b1.getTotalCapacity() << endl;
    
        
    }
    
    catch(invalid_argument& ia) {
        
        cout << "ERROR: caught invalid_argument in function main:\n";
        cout << ia.what() <<endl;
        
    }
    
    catch(logic_error& le) {
        
        cout << "ERROR: caught logic_error in function main:\n";
        cout << le.what() << endl;
        
    }
    
    catch(...) {
        
        cout << "ERROR: caught in function main:\n";
        
    }
    
    
    
    
    
    return 0;
    
}

