#pragma once


namespace tasks3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Form1
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Button^  btnOpen;
			 System::Collections::Generic::List<line> lines; //������ lines � ���������� ���� line
			// int WIDTH;
			// int HEIGHT;
			 float left, right, top, bottom;
			 float Wcx, Wcy, Wx, Wy;
			 float Vcx, Vcy, Vx, Vy;
			 bool drawNames;



	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->FileName = L"openFileDialog2";
			this->openFileDialog->Filter = L"��������� ����� (*.txt)|*.txt|��� ����� (*.*)|*.*";
			this->openFileDialog->Title = L"������� ����";
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(12, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(75, 23);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"�������";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &Form1::btnOpen_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->btnOpen);
			this->KeyPreview = true;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				Graphics^ g = e->Graphics; //������ �� ������� ��������� � �����
				g->Clear(Color::White);//�������� ������� ��� ���������

				Pen^ bPen = gcnew Pen(Color::Black); //���� ��� ��������
				SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black); //���� ��� ������
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 5); //����� ��� ������
				 Pen^ rectPen = gcnew Pen(Color::Red);
				bPen->Width = 4;
				 rectPen->Width = 2;
				g->DrawRectangle(rectPen, Wcx, top, Wx, Wy);
				
				for (int i = 0; i < lines.Count; i++) //������ �������
				{
					vec A, B;//������ ���������� ���������
					point2vec(lines[i].start, A);
					point2vec(lines[i].end, B);

					vec A1, B1; //������ ���������� ���������
					timesMatVec(T, A, A1);//�������������� �: �������� T �� � ��� �
					timesMatVec(T, B, B1);

					point a, b;
					vec2point(A1, a);
					vec2point(B1, b);//�������� � ��������� �������
					
					point r1, r2;
					r2.x = Form::ClientRectangle.Width - right;
					r2.y = Form::ClientRectangle.Height - bottom;
					r1.x = left;
					r1.y = top;
					if(clip(a, b, r1, r2)){
					g->DrawLine(bPen, a.x, a.y, b.x, b.y);
					 if(this->drawNames){
							g->DrawString(lines[i].name, drawFont, drawBrush, a.x + (b.x - a.x) / 2, a.y + (b.y - a.y) / 2 - 8);
						}
					}
					

				}
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				Rectangle rect = Form::ClientRectangle;
				lines.Clear();
				unit(T);

				 top = 50;
				 left = 60;
				 right = 60;
				 bottom = 50;

				 Wcx = left;
				 Wcy = Form::ClientRectangle.Height - bottom;
				Wx = Form::ClientRectangle.Width - left - right;
				 Wy = Form::ClientRectangle.Height - top - bottom;

			 }
	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {
				 if ( this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					wchar_t fileName[1024];
					for (int i = 0; i < openFileDialog->FileName->Length; i++)
						fileName[i] = openFileDialog->FileName[i];
					fileName[openFileDialog->FileName->Length] = '\0';
					
					std::ifstream in;
					in.open(fileName);
					if ( in.is_open() ) 
					{
						lines.Clear();
						std::string str;
						getline (in, str);
						 bool finish = false;

						while (in) 
						{
							if ((str.find_first_not_of(" \t\r\n") != std::string::npos)&& (str[0] != '#')) 
							{
								std::stringstream s(str);
								line l;
								std::string linename;
								float z,x,y,w;
								if (!finish)
								{
									s >> z >> x >> y >> w;
									Vcx = z;
									Vcy = x;
									Vx = y;
									Vy = w;
									finish = true;

								}
								else {

								s >> l.start.x >> l.start.y >> l.end.x >> l.end.y >> linename;
								l.start.x *= 10;
								l.start.y *= 10;
								l.end.x *= 10;
								l.end.y *= 10;

								l.name = gcnew String(linename.c_str());
								lines.Add(l);}
							}
						getline (in, str);
						}
					}
					frame(Vx, Vy, Vcx, Vcy, Wx, Wy, Wcx, Wcy, T);
					
					this->Refresh();
					}
				}
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				Rectangle rec = Form::ClientRectangle;
				mat R, T1;
				unit(R);

				switch(e->KeyCode) {
				
				case Keys::W:
					move(0, -1, R);
					break;
				case Keys::S:
					move(0, 1, R);
					break;
				case Keys::A:
					move(-1, 0, R);
					break;
				case Keys::D:
					move(1, 0, R);
					break;
				case Keys::E: //������� �� ������� �������
					rotate_r(0.05, R);
					break;
				case Keys::X: //���������� �����������
					scale(1.1, 1.1, R);
					break;
				case Keys::Q: //������ ������ ������� �������
					rotate_r(-0.05, R);
					break;
				case Keys::Z://���������� � 1.1 ���
					scale(1/1.1, 1/1.1, R);
					break;
				case Keys::T: //������ �����
					move(0, -15, R);
					break;
				case Keys::G: //������ ����
					move(0, 15, R);
					break;
				case Keys::F: //������ �����
					move(-15, 0, R);
					break;
				case Keys::H://������ ������
					move(15, 0, R);
					break;
				case Keys::U: //���������� ����������� ������������ ������������ ���
					R[0][0] = -1;
					times(R, T, T1);
					set(T1, T);
					move(rec.Width, 0, R);
					break;
				case Keys::J: //���������� ����������� ������������ �������������� ���
					R[1][1] = -1; 
					times(R, T, T1);
					set(T1, T);
					move(0, rec.Height, R);
					break;	
				case Keys::R: //������� ������ ������� ������� ������������ ������
					move(-rec.Width/2, -rec.Height/2, R);
					times(R, T, T1);
					set(T1, T);
					rotate_r(0.1, R);
					times(R, T, T1);
					set(T1, T);
					move(rec.Width/2, rec.Height/2, R);
					break;
				case Keys::Y: //������� �� ������� ������� ������������ ������
					move(-rec.Width/2, -rec.Height/2, R);
					times(R, T, T1);
					set(T1, T);
					rotate_d(0.1, R);
					times(R, T, T1);
					set(T1, T);
					move(rec.Width/2, rec.Height/2, R);
					break;
				case Keys::C://���������� � 1.1 ������������ ������
					move(-rec.Width/2, -rec.Height/2, R);
					times(R, T, T1);
					set(T1, T);
					scale(1/1.1, 1/1.1, R);
					times(R, T, T1);
					set(T1, T);
					move(rec.Width/2, rec.Height/2, R);
					break;
				case Keys::V: //���������� � 1.1 ��� ������������ ������
					move(-rec.Width/2, -rec.Height/2, R);
					times(R, T, T1);
					set(T1, T);
					scale(1.1, 1.1, R);
					times(R, T, T1);
					set(T1, T);
					move(rec.Width/2, rec.Height/2, R);
					break;
				case Keys::I: //���������� �� �������������
					move(-rec.Width/2, 0, R);
					times(R, T, T1);
					set(T1, T);
					scale(1/1.1, 1, R);
					times(R, T, T1);
					set(T1, T);
					move(rec.Width/2, 0, R);
					break;
				case Keys::O: 
					move(-rec.Width/2, 0, R);
					times(R, T, T1);
					set(T1, T);
					scale(1.1, 1, R);
					times(R, T, T1);
					set(T1, T);
					move(rec.Width/2, 0, R);
					break;
				case Keys::K:
					move(0, -rec.Height/2, R);
					times(R, T, T1);
					set(T1, T);
					scale(1, 1/1.1, R);
					times(R, T, T1);
					set(T1, T);
					move(0, rec.Height/2, R);
					break;
				case Keys::L:
					move(0, -rec.Height/2, R);
					times(R, T, T1);
					set(T1, T);
					scale(1, 1.1, R);
					times(R, T, T1);
					set(T1, T);
					move(0, rec.Height/2, R);
					break;
				case Keys::Escape:
					frame(Vx, Vy, Vcx, Vcy, Wx, Wy, Wcx, Wcy, T);
					unit(R);

				case Keys::P: //����������� �������� ��� ����������� ����
					if(drawNames == true)
						drawNames = false;
					else
						drawNames = true;
					break;
				default:
					unit(R);
					}

				 times(R, T, T1);
				 set(T1, T);//�������� ������� T ����� �� R
				 this->Refresh();

			 }
private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {
			 float oldWx = Wx, oldWy = Wy;
			 Wcy = Form::ClientRectangle.Height - bottom;
			 Wx = Form::ClientRectangle.Width - left - right;
			 Wy = Form::ClientRectangle.Height - top - bottom;
			 mat Mov, nMov, Scale;
			 scale(this->Wx/oldWx, this->Wy/oldWy, Scale);
			 move(-this->Wcx, -this->top, Mov);
			 move(this->Wcx, this->top, nMov);
			 mat MS, R, T1;
			 times(nMov, Scale, MS);
			 times(MS, Mov, R);
			 times(R, T, T1);
			 set(T1, T);
			 this->Refresh();
		 }
};
}

