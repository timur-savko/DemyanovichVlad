#include <iostream>
#include <clocale>
#include <time.h>
using namespace std;
float random();
int summOfDigits(int n); 
int maxValue(int n);
int countOfPositiveEvenElements(int A[], int N);
void printEvenDigits(float A[], int N);
void initA50(int A[], int N);
void printNotEvenDigits(float A[], int N);
void fillAPositiveAndNegativeValues(float A[],float B[], float C[],int N,int & t);
void initAn(int A[],int N, int n);
void fillAfloat(float A[], int N);
void printA(float A[], int N);
void sortPositiveAndNegative(float A[], int N);
int main()
{
	setlocale(LC_ALL, "Russian");
	int	task=10;
	srand(time(NULL));
	cout << "������� ����� ������:" << endl 
				<< "1.����� ���� �����" << endl 
					<< "2.���������� ����� �� ���� ���������" << endl 
						<< "3.���������� ������������� ������ ������ �������" << endl
							<< "4.������� �������� ������ �������, ����� ������" << endl 
								<< "5.������������� � ������������� �������� �������" << endl
									<< "6.������������� � ������������� �������� ������� (����� 1 ������)" << endl;
	while (task != 0)
	{
		cin >> task;
		switch (task)
		{
		case 0:
			cout << "���������� ��������� �����������\n";
			break;
		case 1:
			/*������������ ������ � ���������� ����������� �����, ��������� ������������ �����, ��������� � ������� �� ����� ����� ���� ��������� ������������� �����.*/
			int n;
			cout << "������� ����������� �����" << endl;
			cin >> n;
			if (n > 0) cout << "����� ����� ������� �����=" << summOfDigits(n);
			else  cout << "�� ����� ����� �� ���������� ��� �������";
			break;
			//___________________________________________________________________________________________________________________________________________________________________________________________
			//___________________________________________________________________________________________________________________________________________________________________________________________

		case 2:
			/*������������ ������ � ���������� ����������� ����������� �����, ������� ����������� � ���������� n,
				��������� ������������ �����, ��������� � ������� �� ����� ����� �� ���� ��������� ����� n, ���,
				����� ���������� ����� ��������� ������������ �� ���������.��������, ���� ������������ ��� ����� 22195,
				�� ��������� ������ ������� ����� 95221.*/
		{cout << "������� ����������� ����������� �����" << endl;
		cin >> n;
		if (n > 9999 && n < 100000)
		{
			cout << "������������ �����=" << maxValue(n) << endl;
		}
		else cout << "�� ����� ����� �� ���������� ��� �������";
		cout << '\n' << "����� ���������� ���������� ��������� ������� 0, ������ ������� ����� �������\n"; }
		break;
		//___________________________________________________________________________________________________________________________________________________________________________________________
		//___________________________________________________________________________________________________________________________________________________________________________________________
		case 3:
			/*������������ ������ � ���������� ����������� ����� �� ������� 100, ������� ����������� � ���������� n,
			��������� ������������ �����, ������� ������ �� 10 ��������� ����� ����� �� ������� [-2n;n],
			������� ������ �� ����� � ������, ���������� � � ������� �� ����� ���������� ������������� ������ ����� � �������.*/
		{const int N = 10;
		int A[N];
		cout << "������� ����������� ����� �� ������ 100" << '\n';
		cin >> n;
		if (n > 0 && n < 101)
		{
			initAn(A, N, n);
			cout << "����� ������ ������������� ��������� �������=" << countOfPositiveEvenElements(A, N);
		}
		else	cout << "�� ����� ����� ��� ����������"; 
		cout << '\n' << "����� ���������� ���������� ��������� ������� 0, ������ ������� ����� �������\n"; }
		break;
		//___________________________________________________________________________________________________________________________________________________________________________________________
		//___________________________________________________________________________________________________________________________________________________________________________________________
		case 4:
			/*�������� ������ ������������ ����� ������� N (����� N �������� ��� ���������).
			������������������� �������� ��������� ������� ���������� ������� �� ���������� �� -50 �� 50.
			������� �������� ������� ��������� � ��������� �������������� (1-�, 3-�, 5-�,...) � ����� - � �������.*/
		{	const int N = 20;
		float A[N];
		fillAfloat(A, N);
		printEvenDigits(A, N);
		printNotEvenDigits(A, N);
		cout << '\n' << "����� ���������� ���������� ��������� ������� 0, ������ ������� ����� �������\n";
		}
		break;
		//___________________________________________________________________________________________________________________________________________________________________________________________
		//___________________________________________________________________________________________________________________________________________________________________________________________
		case 5:
			/*�������� ������ � ������������ ����� ������� N (����� N �������� ��� ���������).
			������������������� �������� ��������� ������� ���������� ������� �� ���������� �� -50 �� 50.
			"���������" ������ � �� ��� �������: ������������� �������� � ������ �, ������������� - � �.*/
		{
			const int N = 20;
			float A[N], B[N], C[N];
			int k = 0;
			fillAfloat(A, N);
			cout << "#####################" << '\n';
			fillAPositiveAndNegativeValues(A, B, C, N, k);
			printA(B, k);
			cout << "#####################" << '\n';
			printA(C, (N - k));
			cout << '\n' << "����� ���������� ���������� ��������� ������� 0, ������ ������� ����� �������\n";
		}
		break;
		case 6:
			/*�������� ������ � ������������ ����� ������� N (����� N �������� ��� ���������).�������������������
			�������� ��������� ������� ���������� ������� �� ���������� �� -50 �� 50.
			"�������������" ������ � �� ����� (�.�. �� ��������� ��������������� �������� � � �) ����� �������:�������������
			�������� ������� � ����������� � ������, ������������� ����������� � ����� ������� �.*/
		{
			const int N = 20;
			float A[N];
			fillAfloat(A, N);
			sortPositiveAndNegative(A, N);
			printA(A, N);
			cout <<'\n'<< "����� ���������� ���������� ��������� ������� 0, ������ ������� ����� �������\n";
		}
		break;
		default: cout << "������ ������� ����\n";
		}
		
	}
system("PAUSE");
}
void fillAfloat(float A[], int N)
{
	int i = 0;
	while (i<N)
	{
		A[i] = random();
		i++;
	}

}
float random()
{
float r = 0;
		r += rand() % 98 - 49;
		r += (rand() % 9) / 10.0;
		r += (rand() % 9) / 100.0;
		//r += (rand() % 9) / 1000.0;
		return (r);
}
int summOfDigits(int n)
{
	int sum=0;
	while (n > 0)
	{
		sum = sum + (n % 10);
		n = n / 10;
	}
	return (sum);
}
int maxValue(int n)
{
	const int N=5;
	int i = 0, A[N],j=0;
	while (i < N)
	{
		A[i] = n % 10;
		n = n / 10;
		i++;
	}
	i = 0;
	while (i<N)
	{
		j = i + 1;;
		while (j < N)
		{
			if (A[i] < A[j]) swap(A[i], A[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < N)
	{
		n = (n + A[i]) * 10;
		i++;
	}
	return (n/10);
}
void initAn(int A[], int N, int n)
{
	int i = 0;
	while (i < 10)
	{
		A[i] = rand() % (3 * n) - (2 * n);
		i++;
	}
}
int countOfPositiveEvenElements(int A[], int N)
{
	int i = 0, count=0;
	while (i < 10)
	{
		if (A[i] > 0 && ((A[i] % 2) == 0)) count= count + 1;
		i++;
    }
	return(count);
}
void printEvenDigits(float A[], int N)
{
	int i = 0;
	while (i < N)
	{
		cout << A[i] << "  ";
		i += 2;

	}
	cout << '\n';
}
void printNotEvenDigits(float A[], int N)
{
	int i = 1;
	while (i < N)
	{
		cout << A[i] << "  ";
		i += 2;
    }
	cout << '\n';
}
void initA50(int A[], int N)
{
	int i = 0;
	while (i < N)
	{
		A[i] = rand() % (100) - (50);
		i++;
	}
}
void fillAPositiveAndNegativeValues(float A[], float B[],float C[], int N, int & t)
{
	int i = 0, j = 0, k = 0;
	while (i < N)
	{
		if (A[i] > 0) { B[j] = A[i]; j++; t++; }
		else { C[k] = A[i]; k++; }
		i++;
	}
}
void printA(float A[], int N)
{
	int i = 0;
	while (i < N)
	{
		cout << A[i] << '\n';
			i++;
	}
}
void sortPositiveAndNegative(float A[], int N)
{
	int i = 0, j;
	while (i < N)
	{
		j = i + 1;
		while (j < N)
		{
			if (A[i] < A[j]) swap(A[i], A[j]);
			j++;
		}
		i++;
	}

}