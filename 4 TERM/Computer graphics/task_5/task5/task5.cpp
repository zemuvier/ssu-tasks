// task5.cpp: ������� ���� �������.

#include "stdafx.h"
#include "function.h"
#include "Transform.h"
#include "clip.h"
#include "Form1.h"

using namespace task5;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew Form1());
	return 0;
}
