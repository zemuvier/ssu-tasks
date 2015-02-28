#pragma once


namespace tasks3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
			 System::Collections::Generic::List<line> lines; //список lines с элементами типа line
			 int WIDTH;
			 int HEIGHT;
			 int CELL_SIZE;
			 int PEN_WIDTH;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
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
			this->openFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(96, 126);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(75, 23);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"Открыть";
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
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				Graphics^ g = e->Graphics; //ссылка на область рисования в форме
				g->Clear(Color::White);//очистили область для рисования
				Rectangle rect = Form::ClientRectangle;

				Pen^ bPen = gcnew Pen(Color::Black); //перо для отрезков
				bPen->Width = PEN_WIDTH;
				
				for (int i = 0; i < lines.Count; i++) //рисуем отрезок
				{
					vec A, B;//тройка однородных координат
					point2vec(lines[i].start, A);
					point2vec(lines[i].end, B);

					vec A1, B1;//преобразование Т
					timesMatVec(T, A, A1);
					timesMatVec(T, B, B1);

					point a, b;
					vec2point(A1, a);
					vec2point(B1, b);
					
					g->DrawLine(bPen, a.x, a.y, b.x, b.y);
				}
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				WIDTH = 32;
				HEIGHT = 26;
				CELL_SIZE = 20;
				PEN_WIDTH = 2;
				Rectangle rect = Form::ClientRectangle;

				lines.Clear();
				unit(T);
				T[1][1] = -1;
				T[1][M - 1] = rect.Height;
			 }
	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {
				if ( this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)				{					wchar_t fileName[1024];
					for (int i = 0; i < openFileDialog->FileName->Length; i++)
						fileName[i] = openFileDialog->FileName[i];
					fileName[openFileDialog->FileName->Length] = '\0';					
					std::ifstream in;
					in.open(fileName);
					if ( in.is_open() ) 					{						lines.Clear();
						std::string str;
						getline (in, str);
						while (in) 						{							if ((str.find_first_not_of(" \t\r\n") != std::string::npos)&& (str[0] != '#')) 							{								std::stringstream s(str);
								line l;
								std::string linename;
								s >> l.start.x >> l.start.y >> l.end.x >> l.end.y >> linename;
								l.start.x *= CELL_SIZE;
								l.start.y *= CELL_SIZE;
								l.end.x *= CELL_SIZE;
								l.end.y *= CELL_SIZE;
								l.name = gcnew String(linename.c_str());
								lines.Add(l);							}						getline (in, str);						}					}					unit(T);					T[1][1] = -1;
					T[1][M - 1] = Form::ClientRectangle.Height;					this->Refresh();					}
				}
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				Rectangle rect = Form::ClientRectangle;
				mat R, T1;
				unit(R);

				
				float scaleCoeff = 1 / 1.1;
				float centerX = rect.Width / 2;
				float centerY = rect.Height / 2;

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
				case Keys::T:
					move(0, -CELL_SIZE, R);
					break;
				case Keys::G:
					move(0, CELL_SIZE, R);
					break;
				case Keys::F:
					move(-CELL_SIZE, 0, R);
					break;
				case Keys::H:
					move(CELL_SIZE, 0, R);
					break;
				case Keys::E:
					rotate(0.05, 0, 0, R);
					break;
				case Keys::Q:
					rotate(-0.05, 0, 0, R);
					break;
				case Keys::Y:
					rotate(0.05, centerX, centerY, R);
					break;
				case Keys::R:
					rotate(-0.05, centerX, centerY, R);
					break;
				case Keys::Z:
					scale(scaleCoeff, scaleCoeff, R);
					break;
				case Keys::X:
					scale(1.1, 1.1, R);
					break;
				case Keys::C:
					move(-centerX, -centerY, R);
					times(R, T, T1);

					scale(scaleCoeff, scaleCoeff, R);
					times(R, T1, T);

					move(centerX, centerY, R);
					break;
				case Keys::V:
					move(-centerX, -centerY, R);
					times(R, T, T1);

					scale(1.1, 1.1, R);
					times(R, T1, T);

					move(centerX, centerY, R);
					break;
				case Keys::L:
					move(-centerX, 0, R);
					times(R, T, T1);

					scale(1.1, 1, R);
					times(R, T1, T);

					move(centerX, 0, R);
					break;
				case Keys::K:
					move(-centerX, 0, R);
					times(R, T, T1);

					scale(scaleCoeff, 1, R);
					times(R, T1, T);

					move(centerX, 0, R);
					break;
				case Keys::O:
					move(0, -centerY, R);
					times(R, T, T1);

					scale(1, 1.1, R);
					times(R, T1, T);

					move(0, centerY, R);
					break;
				case Keys::I:
					move(0, -centerY, R);
					times(R, T, T1);

					scale(1, scaleCoeff, R);
					times(R, T1, T);

					move(0, centerY, R);
					break;
				case Keys::U:
					reflectVertical(R);
					times(R, T, T1);
					set(T1, T);
					move(rect.Width, 0, R);				
					break;
				case Keys::J:
					reflectHorizontal(R);
					times(R, T, T1);
					set(T1, T);
					move(0, rect.Height, R);	
					break;
				case Keys::Escape :
					unit(T);
					T[1][1] = -1;
					T[1][M - 1] = rect.Height;
				 }

				 times(R, T, T1);
				 set(T1, T);
				 this->Refresh();

			 }
};
}

