#include <iostream>

//TEMPLATE
template <typename T>

//Vector Mimic Class, the goal is to try to make a array behave like a vector (adding to the end)
class vectorMimic{
	private:
	T *array;
	int size;

	public:
	
	//Constructor
	vectorMimic(){ array = nullptr; size = 0; }

	//Destructor
	~vectorMimic(){}

	//Add Element to end of list function
	void addElement(T param) { 
		//New array allocation
		T *newArray = new T[size + 1];

		//Initializing and copying to new array
		for(int i = 0; i < size; i++){
			newArray[i] = array[i];
		}

		newArray[size] = param;
			
		//Deleting original array
		delete[] array;
		
		//Setting the new array as the main array
		array = newArray;

		//Counting for next loop and to keep track of array size
		size++;
	}
	
	//size in the previous function is used for this
	//Used for getting a particular index, and finding its value
	void at(int param){
		if(param > size){
			std::cout << "index does not exist yet" << std::endl;
			return;
		}
		std::cout << "Value at index " << param << " is: " <<  array[param] << std::endl;
	}
	
	//Using size to find the amount of inputs
	void sizeArray(){
		std::cout << "Size of array is: " << size << std::endl;
	}
	
	//basic sum function
	auto sumArray(){
		T sum = 0;
		for(int i = 0; i < size; i++){
			sum = sum + array[i];
		}
		return sum;
	}
	
	//basic max function
	auto max(){
		T max = array[0];
		for(int i = 1; i < size; i++){
			if(array[i] > array[i-1]){
				max = array[i];
			}
		}
		return max;
	}
	
	//basic min function
	auto min(){
                T min = array[0];
                for(int i = 1; i < size; i++){
                        if(array[i] < array[i-1]){
                                min = array[i];
                        }
                }
                return min;
        }

	//Function for slicing the array
	void slice(int begin, int end){
		int begIndex = begin - 1; //To make the index correct
		int endIndex = end - 1; //Same here
		int newSize =  end - begin + 1; // Finding amount of numbers in slice
		
		//New Array
		T *slicedArray = new T[newSize];

		//Assigning array values into sliced array
		int counter = 0;
		for(int i = begIndex; i <= endIndex; i++){
			slicedArray[counter] = array[i];
			counter++;
		}
		
		//print
		std::cout << "Sliced array of (" << begin << ", " << end << ")" << std::endl;
		for(int i = 0; i < newSize; i++){
			std::cout << slicedArray[i] << std::endl;
		}	
		
	}


};

int main(){
	vectorMimic<double> array1;

	//Array of (10,20,30,40)
	array1.addElement(10);
	array1.addElement(20);
	array1.addElement(30);
	array1.addElement(40);

	//want array value at array(2). Should be 30 
	array1.at(2);

	//Size of array
	array1.sizeArray();

	//Maxes and Mins, sum
	std::cout << "sum of array is: " << array1.sumArray() << std::endl;
	std::cout << "max of array is: " << array1.max() << std::endl;
	std::cout << "min of array is: " << array1.min() << std::endl;

	//SLICE
	array1.slice(1,4);

	return 0;

		
		
	
	}




