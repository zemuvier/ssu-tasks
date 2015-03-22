value struct point //описание структуры для двумерной точки
{
	float x, y;
};

value struct line //описание двумерного отрезка
{
	point start, end;
	System::String^ name;
};
#define M 3//порядок матрицы преобразований
typedef float vec[M];//вектор 
typedef float mat[M][M];//матрица

extern mat T;//матрица совмещенного преобразования

void times(mat a, mat b, mat c);//умножаем а на в
void timesMatVec(mat a, vec b, vec c);
void set(mat a, mat b);//переписываем а в в
void point2vec(point a, vec b);//координаты точки в однородные координаты
void vec2point(vec a, point &b);//обратно
void makeHomogenVec(float x, float y, vec c);//вектор однородных координат 
void unit(mat a);//единичная матрица
void move(float Tx, float Ty, mat c); //перенос
void rotate_r(float phi, mat c);//поворот
void rotate_d(float phi, mat c);
void scale(float Sx, float Sy, mat c);//масштабирование
void trans(float Ty, mat c);
void frame(float Vx, float Vy, float Vcx, float Vcy, float Wx, float Wy, float Wcx, float Wcy, mat c);
