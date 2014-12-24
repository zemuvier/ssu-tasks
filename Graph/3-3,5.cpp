//���������� ��������� ������ �����, ���������� �� ������� �� �������� ������� �� ����� n

/*�������� �������� ������� ����������� ���� �� ������� s �� ���� ������ �������� � � ��������� ������� t. �������� �������� 
��������, ������ �� ������ ����� ���������� ���� �� s � ����� ������������� ������� x. �� ����, � ������ ����� �� ���������
���� ������� � ������ ������, ��� ������� �� ����� ���������� ���� �� s.*/

#include <iostream>
#include <fstream>

const double inf = 1E9;

using namespace std;

ifstream inp("input.txt");
ofstream outp("output.txt");

int n, g[100][100], length; //������� ���� g � n �������

void dksrt(int s, int k)//�������� ��������
{
	int distance[100];//������ �������� ����� 
	int u;
	int min = 10000;
	bool visited[100];//�������� �������?

	for (int i = 0; i<n; i++)
	{
		distance[i] = inf; //����� �� ����� ������� �� ��� ��������� ���� ���
		visited[i] = false; //�� ���� ������� �� ��������
	}

	distance[s]=0;//��� ������

	for (int count = 0; count<n; count++)
	{
		for (int i=0; i<n; i++)
			if (!visited[i] && distance[i]<=inf)//���� ������� ������� �� ����������� � ���� ���
			{
				min = distance[i]; 
				u = i; //����������� �������, � ������� ���� ���������
			}

			visited[u] = true;//����������� ��

			for (int i=0; i<n; i++)
				if (!visited[i] && g[u][i] distance[u]!=inf && distance[u]+g[u][i]<distance[i])//���� ������� �� �����������, ���� ���� �� u 
					//� i, � ����������� �������� ���������� �����(�������� ��������): ���� ���������� �����, ����� �������
					//���������� ������� ����, ��� ����� �� �������� ������
					distance[i] = distance[u]+g[u][i];//���������� ���� ����������� ����(������� � ������� ������� g)
	}

	if (distance[k - 1] < length)//���� ���� �� k ����������, �� ������� ���
		outp << s+1 << " > "<< k << " = " << distance[k - 1] << endl;
	else//����� ������� ���������, ��� ��� ���
		outp << s+1 << " > "<< k << " = " << "No" << endl;
}

int main()
{
	int s; //�������� �������

	inp >> s; //������ �������
	inp >> n; //���������� ������
	inp >> length; //�������� ����

	//��������� ��� ����
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; j++)
			inp >> g[i][j];//���������� ������� �����

	for (int i = 0; i<n; i++)
		dksrt(i, s);//��������� ��������� � �����, ��� ��� ��� ����� �� ���� ������ �� ������, � �������� �������
	//������ ������ �� ����� �������

	return 0;
}