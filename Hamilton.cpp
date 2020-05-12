#include<iostream>
#include<fstream>
#define TRUE 1
#define FALSE 0
#define MAX 100
using namespace std;

int n; int arr[MAX][MAX]; int x[MAX]; int u; int dem = 0; int chuaxet[MAX];

void Read_File()
{
	ifstream FileIn;
	FileIn.open("DOTHI.txt", ios_base::in);
	FileIn >> n;
	cout << "\n Tong so dinh : " << n << endl;
	for (int i = 1; i <= n; i++)
	{
		chuaxet[i] = TRUE;
		for (int j = 1; j <= n; j++)
		{
			FileIn >> arr[i][j];
			cout << arr[i][j] << " ";
		}
		cout << endl;

	}
	FileIn.close();

}
void Xuat()
{
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}
	cout << u << endl;
	dem++;
}
void Hamilton(int k)
{
	for (int i = 1; i <= n; i++)
	{
		if (arr[x[k - 1]][i] == 1)
		{
			if (k == n && i == u)
			{
				Xuat();
			}
			else if (chuaxet[i] ==TRUE)
			{
				x[k] = i;
				chuaxet[i] = FALSE;
				Hamilton(k + 1);
				chuaxet[i] = TRUE;

			}
		}
	}
}

int main()
{
	Read_File();
	cout << "\n Hamilton xuat phat tu dinh nao : ";
	cin >> u;
	x[0] = u;
	chuaxet[u] = FALSE;
	Hamilton(1);
	if (dem == 0)
	{
		cout << "\n Khong phai la do thi Hamilton ";
	}
	system("pause");
	return 0;
}
