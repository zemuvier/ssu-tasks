#pragma once


namespace computergraph {

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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 Graphics^ g = e->Graphics;
				 g->Clear(Color::White);
				 Rectangle rect = Form::ClientRectangle;
				 Pen^ blackPen = gcnew Pen(Color::Black);
				 blackPen->Width = 2;
				 g->DrawLine(blackPen, 20, 70, 20, 120 );
				 g->DrawLine(blackPen, 20, 70, 60, 30 );
				 g->DrawLine(blackPen, 60, 30, 80, 30 );
				 g->DrawLine(blackPen, 80, 30, 90, 20 );
				 g->DrawLine(blackPen, 90, 20, 140, 20 );
				 g->DrawLine(blackPen, 140, 20, 150, 30 );
				 g->DrawLine(blackPen, 150, 30, 190, 30 );
				 g->DrawLine(blackPen, 190, 30, 200, 40 );
				 g->DrawLine(blackPen, 200, 40, 220, 40 );
				 g->DrawLine(blackPen, 220, 40, 230, 50 );
				 g->DrawLine(blackPen, 230, 50, 240, 50 );
				 g->DrawLine(blackPen, 240, 50, 260, 70 );
				 g->DrawLine(blackPen, 260, 70, 260, 80 );
				 g->DrawLine(blackPen, 250, 90, 270, 70 );
				 g->DrawLine(blackPen, 270, 70, 290, 70 );
				 g->DrawLine(blackPen, 290, 70, 320, 100 );
				 g->DrawLine(blackPen, 320, 100, 310, 110 );
				 g->DrawLine(blackPen, 310, 110, 290, 110 );
				 g->DrawLine(blackPen, 290, 110, 290, 150 );
				 g->DrawLine(blackPen, 290, 150, 310, 170 );
				 g->DrawLine(blackPen, 310, 170, 290, 190 );
				 g->DrawLine(blackPen, 290, 190, 280, 190 );
				 g->DrawLine(blackPen, 280, 190, 270, 180 );
				 g->DrawLine(blackPen, 270, 180, 260, 180 );
				 g->DrawLine(blackPen, 260, 180, 250, 170 );
				 g->DrawLine(blackPen, 250, 170, 240, 170 );
				 g->DrawLine(blackPen, 240, 170, 230, 160 );//отсюда начинается разбиение
				 g->DrawLine(blackPen, 230, 160, 230, 150 );
				 g->DrawLine(blackPen, 230, 150, 240, 140 );
				 g->DrawLine(blackPen, 240, 140, 240, 110 );//смещение закончено
				 g->DrawLine(blackPen, 230, 160, 220, 170 );
				 g->DrawLine(blackPen, 220, 170, 220, 220 );
				 g->DrawLine(blackPen, 220, 220, 230, 230 );
				 g->DrawLine(blackPen, 230, 230, 230, 240 );
				 g->DrawLine(blackPen, 230, 240, 210, 240 );
				 g->DrawLine(blackPen, 210, 240, 210, 230 );
				 g->DrawLine(blackPen, 210, 230, 200, 200 );
				 g->DrawLine(blackPen, 200, 200, 190, 190 );
				 g->DrawLine(blackPen, 190, 190, 190, 170 );//смещение
				 g->DrawLine(blackPen, 190, 170, 190, 160 );
				 g->DrawLine(blackPen, 190, 160, 180, 150 );
				 g->DrawLine(blackPen, 180, 150, 180, 140 );//закончено
				 g->DrawLine(blackPen, 190, 170, 120, 170 );
				 g->DrawLine(blackPen, 170, 170, 170, 200 );
				 g->DrawLine(blackPen, 150, 170, 150, 200 );
				 g->DrawLine(blackPen, 170, 200, 180 , 210 );
				 g->DrawLine(blackPen, 150, 200, 160, 210 );
				 g->DrawLine(blackPen, 160, 210, 160, 220 );
				 g->DrawLine(blackPen, 180, 210, 180, 220 );
				 g->DrawLine(blackPen, 160, 220, 180, 220 );
				 g->DrawLine(blackPen, 120, 170, 110, 160 );
				 g->DrawLine(blackPen, 110, 160, 90, 160 );
				 g->DrawLine(blackPen, 90, 160, 80, 170 );
				 g->DrawLine(blackPen, 80, 170, 70, 170 );
				 g->DrawLine(blackPen, 80, 170, 80, 200 );//нога
				 g->DrawLine(blackPen, 80, 200, 90, 210 );
				 g->DrawLine(blackPen, 90, 210, 90, 220 );
				 g->DrawLine(blackPen, 90, 220, 70, 220 );
				 g->DrawLine(blackPen, 70, 220, 70, 200 );
				 g->DrawLine(blackPen, 70, 200, 60, 190 );
				 g->DrawLine(blackPen, 60, 190, 60, 180 );
				 g->DrawLine(blackPen, 60, 180, 70, 170 );
				 g->DrawLine(blackPen, 60, 180, 60, 220 );
				 g->DrawLine(blackPen, 60, 220, 70, 230 );
				 g->DrawLine(blackPen, 70, 230, 70, 240 );
				 g->DrawLine(blackPen, 70, 240, 50, 240 );
				 g->DrawLine(blackPen, 50, 240, 50, 220 );
				 g->DrawLine(blackPen, 50, 220, 40, 210 );
				 g->DrawLine(blackPen, 40, 210, 40, 190 );
				 g->DrawLine(blackPen, 40, 190, 30, 180 );
				 g->DrawLine(blackPen, 30, 180, 40, 170 );
				 g->DrawLine(blackPen, 40, 170, 40, 160 );
				 g->DrawLine(blackPen, 40, 160, 30, 150 );
				 g->DrawLine(blackPen, 30, 150, 30, 130 );
				 g->DrawLine(blackPen, 30, 130, 20, 120 );
				 g->DrawLine(blackPen, 280, 150, 280, 140 );
				 g->DrawLine(blackPen, 280, 140, 270, 140 );
				 g->DrawLine(blackPen, 270, 140, 280, 150 );
			 }
	};
}

