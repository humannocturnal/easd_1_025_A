jelaskan mengapa suatu algortima dibutuhkan untuk menyelesaikan suatu masalah 
//karena dengan adanya algoritma kita bisa mengetahui detail masalah dalam suatu data 
dalam algoritma, di klasssifikasikan menjadi 2 data struktur, sebutkan 2 data struktur tersebut
//data abstrak dan data absolut
untuk mengukur sebuah efisensi waktu suatu algoritma dibutuhkan beberapa faktor, sebutkan faktor-faktoryang memperngaruhi efisiensi waktu eksekusi suatu program !
//kecepatan pengerjaan, menggunakan algoritma yang mudah dipelajari sehingga memudahkan dalam pengerjaan 
dari 6 algoritma yang sudah dipelajari, algoritma manakah yang paling mudah dipahami dan diimplementasikan untuk mengurutkan data yang ukurannya nesar. 
jelaskan kenapa anda memilih itu.
//algortima struktur yang paling mudah dipahami, karena pengaplikasiannya mudah dan terstruktur
sebutkan dari algortima yang telah dipelajari mana yang termasuk kedalam Quadratic dan mana yang termasuk kedalam Loglinear.
//algoritma struktur termasuk kedalam Quadratic dan algoritma absolut termasuk kedalam Loglinear
buatlah sebuah program yang mengimplementasikan merge sort menggunakan bahasan c++, berikut merupakan algoritma merge sort:

#include <iostream>
using namespace std;

//Nominal angka yang dimasukkan
int arr[20];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of data movements
int n;

void input() {
	while (true)
	{
		cout << "Masukkan nilai angka: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum angka adalah 20" << endl;
	}

	cout << "\n------------------" << endl;
	cout << "\nEnter Nominal Element" << endl;
	cout << "\n------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + i) << ">";
		cin >> arr[i];
	}
}
// swaps the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)
		return;                                        

	// partition  the list into two parts:
	// one containing elements less that or equal to pivot
	// Outher conntainning elements greather than pivot 

	pivot = arr[low];                                 

	i = low + 1;                                      
	j = high;                                        
	

	while (i <= j)                                    
	{
		//search for an element greater than pivot
		while ((arr[i] <= pivot) && (i <= high))      
		{
			i++;                                      
			cmp_count++;
		}
		cmp_count++;
		// search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low))        
		{
			j--;                                      
			cmp_count++;
		}
		cmp_count++;

		
		if (i < j) // if the greater element is on the left of the element
		{
			// swap the element at index of the last element at index j
			swap(i, j);
			mov_count++;
		}
	}
	//j now containt the index of the last element in the sorted list
	if (low < j)                                       
	{
		//move the pivot to its correct position in the list 
		swap(low, j);
		mov_count++;
	}
	//sort the list on the left of pivot using quck sort
	q_short(low, j - 1);                               

	//sort the list on the right of pivot using quick sort
	q_short(j + 1, high);                              


}
