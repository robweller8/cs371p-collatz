
#include <iostream> // cin, cout, ios_base
#include <cassert>  // assert









bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}


int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
	int maxCycle = 0;
	if(j>=i){
	int cache [10] = {1,2,8,3,6,9,17,4,20,7};
         
    for(int x = i; x<=j; x++){
		int value = x;
		int counter=1;
		while(value !=1)
			if (value <= 10){
			counter = counter + cache[value-1] -1;
			value = 1;
			}
			else{
			if (value%2 == 0){
				value = value/2;
				counter++;
			}
			
			else{
				value = 3*value+1;
				counter++;
			}
			}
        if (counter > maxCycle){
            maxCycle = counter;
        }
        
    }
    
    
    }
    else{
	for(int x = j; x<=i; x++){
		int value = x;
		int counter=1;
		while(value !=1)
			if (value <= 10){
			counter = counter + cache[value-1] -1;
			value = 1;
			}
			else{
			if (value%2 == 0){
				value = value/2;
				counter++;
			}
			
			else{
				value = 3*value+1;
				counter++;
			}
			}
        if (counter > maxCycle){
            maxCycle = counter;
        }
        
    }
    
    
    }
    int v = maxCycle;
    assert(v > 0);
    return v;
}


void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}


void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}


int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    collatz_solve(cin, cout);
    return 0;}


