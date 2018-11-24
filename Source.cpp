#include <iostream>
#include <ctime>
using namespace std;
double** matrix_initialization(int n)
{
	double **arr = new double*[n];
	for (int i = 0; i < n; i++)
	{
		{
			arr[i] = new double[n];
		}
	}
	return arr;
}
void filling_the_matrix(int n, double **arr)
{
	cout << "Please, choose the left and the right limit of elements' value: " << endl;
	cout << "The left limit is: ";
	int left_limit;
	cin >> left_limit;
	cout << "The right limit is: ";
	int right_limit;
	cin >> right_limit;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = (double(rand()) / RAND_MAX)*(right_limit-left_limit)+left_limit;
		}
	}
}
void output_the_started_matrix(int n, double **arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(*(arr + i) + j) << " " ;
		}
		cout << endl;
	}
	cout << endl;
}
void output_the_elements_of_the_painted_area(int n, double **arr)
{
	cout << "The selected elements of matrix are: "  << endl;
	for (int i = 0; i < n; i++)
	{
		if (i < ((n / 2) + 1))
		{
			for (int j = n - i - ((n / 2) + 1); j <= n + i - ((n / 2) + 1); j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		else
		{
			for (int j = n - (n - 1 - i) - ((n / 2) + 1); j <= n + (n - 1 - i) - ((n / 2) + 1); j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	cout << endl;
}
void max_of_the_selected_elements(int n, double **arr)
{
		double max = arr[0][(n / 2) + 1];
		for (int i = 0; i < n; i++)
		{
			if (i < ((n / 2) + 1))
				for (int j = n - i - ((n / 2) + 1); j <= n + i - ((n / 2) + 1); j++)
				{
					if (arr[i][j] > max) max = arr[i][j];
				}
			else
			{
				for (int j = n - (n - 1 - i) - ((n / 2) + 1); j <= n + (n - 1 - i) - ((n / 2) + 1); j++)
				{
					if (arr[i][j] > max) max = arr[i][j];
				}
			}
		}
		cout << "Max of the selected elements = " << max << endl;
}
void sum_of_the_selected_elements(int n, double **arr)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < ((n / 2) + 1))
		{
			for (int j = n - i - ((n / 2) + 1); j <= n + i - ((n / 2) + 1); j++)
			{
				sum += arr[i][j];
			}
		}
		else
		{
			for (int j = n - (n - 1 - i) - ((n / 2) + 1); j <= n + (n - 1 - i) - ((n / 2) + 1); j++)
			{
				sum += arr[i][j];
			}
		}
	}
	cout << "Sum of the selected elements = " << sum << endl;
}
void removing_the_matrix(int n, double **arr)
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}
int main()
{
	srand(time(NULL));
	int size;
	cout << "Please, enter the size of the square matrix: ";
	cin >> size;
	if (size % 2 == 0) cout << "The task can not be done" << endl;
	else
	{
		double **the_first_element = matrix_initialization(size);
		filling_the_matrix(size, the_first_element);
		output_the_started_matrix(size, the_first_element);
		output_the_elements_of_the_painted_area(size, the_first_element);
		max_of_the_selected_elements(size, the_first_element);
		sum_of_the_selected_elements(size, the_first_element);
		removing_the_matrix(size, the_first_element);
    }
	system("pause");
}
