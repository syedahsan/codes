#include <iostream>

using namespace std;
class array {

	private:
		int size;
		int *data;
	
	public:
		array() {
			size = 0;
			data = NULL;
		}
		array(int s) {
			size = s;
			data = new int[s];
		}

		~array() {
			delete[] data;
		}
		array& operator= (const array& rhs) {
			size = rhs.size;
			delete[] data;

			data = new int[size];
			for(int i=0; i<size; i++) {
				data[i] = rhs.data[i];
			}
			return *this;
		}
};
