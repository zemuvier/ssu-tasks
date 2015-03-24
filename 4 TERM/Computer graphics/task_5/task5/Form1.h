#pragma once


namespace task5 {

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
		float Wcx, Wcy, Wx, Wy;


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
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 Graphics^ g = e->Graphics;
				 g->Clear(Color::White);
				 
				 Rectangle rect = Form::ClientRectangle;
				 
				 Pen^ blackPen = gcnew Pen(Color::Black);
				 Pen^ bluePen = gcnew Pen(Color::Blue);
				 blackPen->Width = 3;
				 bluePen->Width = 3;

				 float Wcx = 10, Wcy = rect.Height - 10, Wy = rect.Height - 20, Wx = rect.Width - 20; 
				 g->DrawRectangle(bluePen, Wcx, Wcy - Wy, Wx, Wy);

				 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 7);
				 SolidBrush^ drawBrush = gcnew SolidBrush(Color::Red);			 

				 Pen^ greenPen = gcnew Pen(Color::Lime);
				 greenPen->Width = 1;


				//отрисовка координатной системы
				 for(int xl = Wcx + Wx/(l + 1); xl < Wcx + Wx; xl += Wx/(l + 1))
				 {
					point t, b;
					b.x = t.x = xl;
					t.y = 10;
					b.y = Form::ClientRectangle.Height - t.y;
					float x = ((xl - Wcx) / Wx) * Vx + Vcx;
					g->DrawLine(greenPen, t.x, t.y, b.x, b.y);
					g->DrawString(Convert::ToString(x), drawFont, drawBrush, xl, 0);
				 }

				 for(int yl = 10 + Wy/(k + 1); yl < 10 + Wy; yl += Wy/(k + 1))
				 {
					point l, r;
					l.y = r.y = yl;
					l.x = 10;
					r.x = Form::ClientRectangle.Width - l.x;
					float y = Vcy - ((yl - Wcy) / Wy) * Vy;
					g->DrawLine(greenPen, l.x, l.y, r.x, r.y);
					g->DrawString(Convert::ToString(y), drawFont, drawBrush, 0, yl);

				 }
				 //отрисовка функции 
				 float x1 = Wcx;
				 float x = Vcx;
				 float y, y1, y2;
				 bool visible1, visible2;
				 
				 if (fexists(x))
				 {
					visible1 = true;
					y = f(x);
					y1 = Wcy - ((y - Vcy) * Wy) / Vy;
				 }
				 else
					visible1 = false;

				 while (x1 < Wcx + Wx)
				 {
					x = ((x1 + 1 - Wcx) * Vx) / Wx + Vcx;
					
					if (fexists(x))
					{
						visible2 = true;
						y = f(x);
						y2 = Wcy - (y - Vcy ) / Vy* Wy;
					}
					else
						visible2 = false;
					
					if (visible1 && visible2)
					{
						float x2 = x1 + 1;
						point a, b, r1, r2;
						a.x = x1;
						a.y = y1;
						b.x = x2;
						b.y = y2;
						r1.x = 10;
						r1.y = 10;
						r2.x = rect.Width - 10;
						r2.y = rect.Height - 10;

						if (clip(a, b, r1, r2))
							g->DrawLine(blackPen, x1, y1, x2, y2);
					}

						x1+=1;
						y1 = y2;
						visible1 = visible2;
				 }


			 }
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 float p;
				 switch (e->KeyCode){

				 case Keys::W: 
						Vcy -= (Vy / Wy);
						break;
					case Keys::S:
						Vcy += (Vy / Wy);
						break;
					case Keys::D:
						Vcx += (Vx / Wx);
						break;
					case Keys::A:
						Vcx -= (Vx / Wx);
						break;

					case Keys::T:
						Vcy -= 15 * (Vy / Wy);
						break;
					case Keys::G:
						Vcy += 15 * (Vy / Wy);
						break;
					case Keys::F:
						Vcx += 15 * (Vx / Wx);
						break;
					case Keys::H:
						Vcx -= 15 * (Vx / Wx);
						break;
					
					case Keys::Q:
						k++;
						break;
					case Keys::E:
						if (k > 1)
							k--;
						break;
					case Keys::Z:
						l++;
						break;
					case Keys::C:
						if (l > 1)
							l--;
						break;

					case Keys::I:
						p = Vy;
						Vy *= 1/1.1;
						Vcy += (p - Vy)/2;
						break;
					case Keys::O :
						p = Vy;
						Vy *= 1.1;
						Vcy += (p - Vy)/2;
						break;
					case Keys::K :
						p = Vx;
						Vx *= 1 / 1.1;
						Vcx += (p - Vx)/2;
						break;
					case Keys::L :
						p = Vx;
						Vx *= 1.1;
						Vcx += (p - Vx)/2;
						break;
				 			 
				 
					 case Keys::Escape:
						 Vx = Vx1;
						 Vy = Vy1;
						 Vcx = Vcx1;
						 Vcy = Vcy1;
						 break;
				 
				 }
				 
				 this->Refresh();
			 }
private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {
				 float oldWx = Wx, oldWy = Wy;
				 Wcy = Form::ClientRectangle.Height - 10;
				 Wx = Form::ClientRectangle.Width - 20;
				 Wy = Form::ClientRectangle.Height - 20;
				

			 this->Refresh();
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 Wcx = 10;
				 Wcy = Form::ClientRectangle.Height - 10;
				 Wx = Form::ClientRectangle.Width - 20;
				 Wy = Form::ClientRectangle.Height - 20;


		 }
};
}

