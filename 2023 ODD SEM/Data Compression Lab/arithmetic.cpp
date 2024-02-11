#include <iostream>
#include <string>
using namespace std;
struct Symbol {
    char symbol;
    double probability;
    double low;
    double high;
};
string seq="";
Symbol* calculateCDF(Symbol* symbols, int num_symbols) {
    double cumulative_prob = 0.0;
    for (int i = 0; i < num_symbols; ++i) {
        symbols[i].low = cumulative_prob;
        symbols[i].high = cumulative_prob + symbols[i].probability;
        cumulative_prob += symbols[i].probability;
    }
    return symbols;
}
double arithmeticDecode(double encodedValue, const Symbol* symbols, int num_symbols) {
    double low = 0.0;
    double high = 1.0;
    double range = 1.0;
    for (int i = 0; i < num_symbols; ++i) {
        range = high - low;
        high = low + range * symbols[i].high;
        low = low + range * symbols[i].low;
        if (low <= encodedValue && encodedValue < high) {
            return symbols[i].symbol;
        }
    }
    return '\0';
}
double arithmeticEncode(const string& sequence, const Symbol* symbols, int num_symbols) {
    double low = 0.0;
    double high = 1.0;
    for (char c : sequence) { 
        for (int i = 0; i < num_symbols; ++i) {
            if (symbols[i].symbol == c) {
                double range = high - low;
                high = low + range * symbols[i].high;
                low = low + range * symbols[i].low;
                cout<<symbols[i].symbol<<"\t"<<low<<"\t"<<high<<endl;
                if(low<0.5 && high<0.5){
                    while(low<0.5 && high<0.5){
                    seq+= "0";
                    low= 2*low;
                    high= 2*high;
                    }
                }
                if (low>0.5){
                    while(low>0.5){
                    seq+= "1";
                    low= 2*(low-0.5);
                    high= 2*(high-0.5);
                    }
                }
                if(low<0.5 && high>0.5)
                    continue;
                if(low<0.5 && high<0.5){
                    while(low<0.5 && high<0.5){
                    seq+= "0";
                    low= 2*low;
                    high= 2*high;
                    }
                }
                if (low>0.5){
                    while(low>0.5){
                    seq+= "1";
                    low= 2*(low-0.5);
                    high= 2*(high-0.5);
                    }
                }
            
                break;
                
            }
        }
    }
    
    return (low + high) / 2.0;
}
int main() {
    int num_symbols;
    cout << "Enter the number of symbols: ";
    cin >> num_symbols;
    Symbol* symbols = new Symbol[num_symbols];
    for (int i = 0; i < num_symbols; ++i) {
        cout << "Enter symbol " << (i + 1) << ": ";
        cin >> symbols[i].symbol;
        cout << "Enter probability for symbol " << (i + 1) << ": ";
        cin >> symbols[i].probability;
    }
    symbols = calculateCDF(symbols, num_symbols);
    for (int i = 0; i < num_symbols; ++i) {
        cout << symbols[i].symbol << "\t\t" << symbols[i].low << "\t\t" << symbols[i].high << endl;
    }
    cout << "Enter the sequence to encode: ";
    string sequence;
    cin >> sequence;
    double encodedValue = arithmeticEncode(sequence, symbols, num_symbols);
    cout << "Arithmetic encoded value: " << encodedValue << endl;
    double decodedValue = arithmeticDecode(encodedValue, symbols, num_symbols);
    cout<<"Binary sequence: "<<seq<<endl;
    delete[] symbols;
    return 0;
}