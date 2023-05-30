6-1狗的继承
#include <iostream>
using namespace std;

class Animal
{
    public:
    Animal()
    {

    }
    Animal(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return age;
    }

    public:
    int age;
};
class Dog : public Animal
{
    public:
    Dog(int a, string color)
    {
        age2 = a;
        this->color = color;
    }
    void showInfor()
    {
        cout << "age:" << age2 << endl;
        cout << "color:" << color << endl;
    }

    private:
    string color;
    int age2;
};


6-2写出派生类构造方法
:People(id, name)
{
    this->score = score;
    this->sid = sid;


6-3使用类输出图形
class Square:public Rectangle
{
    private:
    int side;

    public:
    Square(int s)
    {
        side = s;
    }
    void Print()
    {
        cout << "Side=" << side << endl;
    }
    int getArea()
    {
        return side * side;
    }
    int getPerimeter()
    {
        return 4 * side;
    }
};
class Circle: public Shape
{
    private:
    int x;
    int y;
    float adius;

    public:
    Circle(int x0, int y0, float a)
    {
        x = x0;
        y = y0;
        adius = a;
    }
    void Print()
    {
        cout << "Center=["<<x<<","<<y<<"],Adius="<< adius << endl;
    }
    double getArea()
    {
        return PI * adius * adius;
    }
    double getPerimeter()
    {
        return 2 * PI * adius;
    }
};


6-4计算两点之间距离
void pointDis(Point& p1, Point& p2)
{
    double distant;
 	distant = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<distant<<endl;
}


6-5复数的加减运算
#include<iostream>
#include<string>
using namespace std;
class CComplex
{
public:
    CComplex()
    {
        real = 0.0;
        imag = 0.0;
    }
    CComplex(double real, double imag)
    {
        this->real = real;
        this->imag = imag;
    }
    void display()
    {
        string i = "i";
        if (imag >= 0)
        {
            cout << real << "+" << imag << i << endl;
        }
        else
        {
            cout << real << imag << i << endl;
        }
    }
private:
    double real, imag;
    friend CComplex add(CComplex &a, CComplex& b)
    {
        CComplex c;
        c.real = a.real + b.real;
        c.imag = a.imag + b.imag;
        return c;
    }
    friend CComplex sub(CComplex& a, CComplex& b)
    {
        CComplex c;
        c.real = a.real - b.real;
        c.imag = a.imag - b.imag;
        return c;
    }
};


6-6 减、相等和输入输出的运算符重载（2维向量Vec2）
Vec2::Vec2(double u,double v){
     this->u=u;this->v=v;
}
Vec2 operator-(const Vec2&a,const Vec2&b){
    Vec2 sub;
    sub.u=a.u-b.u;
    sub.v=a.v-b.v;
    return sub;
}
bool Vec2::operator==(const Vec2&b) const{
   return u==b.u && v==b.v;
}
ostream&operator<<(ostream&os,const Vec2&c){
   os<<"("<<c.u<<","<<c.v<<")";
}
istream&operator>>(istream&is,Vec2&c){
    is>>c.u>>c.v;
}


6-7 加、不等和输入输出的运算符重载（2维向量Vec2）
Vec2::Vec2(double a,double b){
    u = a;
    v = b;
}
Vec2 Vec2::operator+(const Vec2&b){
    Vec2 c;
    c.u = this->u + b.u;
    c.v = this->v + b.v;
    return c;
}
bool operator!=(const Vec2&a,const Vec2&b)
{
    if (a.u!=b.u||a.v!=b.v) return 1;
    else return 0;
}
ostream&operator<<(ostream&os,const Vec2&c){
    os << "u=" <<c.getU()<<"," << "v="<<c.getV();

}
istream&operator>>(istream&is,Vec2&c){
   is>>c.u>>c.v;
}


6-8 相等、不等和输入输出的运算符重载（2维向量Vec2）
Vec2::Vec2(double u,double v){
   this->u=u;this->v=v;
}
bool Vec2::operator==(const Vec2&b) const{
    return u==b.u && v==b.v;
}
bool operator!=(const Vec2&a,const Vec2&b)
{
    return a.u!=b.u||b.v!=a.v;
}
ostream&operator<<(ostream&os,const Vec2&c){
   os<<"u:"<<c.u<<",v:"<<c.v;
}
istream&operator>>(istream&is,Vec2&c){
    is>>c.u>>c.v;
}


6-9 矩阵与向量的乘法
int& Matrix::operator()(int i,int j){
     if (i < 0 || i >= szl || j < 0 || j >= szr) {
            cout << "Matrix index out of range.\n";
            exit(0);
        }
        return m[i * szr + j];
}
ostream& operator<<(ostream& out, const Vector& x) {
        for (int i = 0; i <= x.sz - 1; ++i) {
            out << x.v[i] << " ";
        }
        return out;
    }

Vector operator*(Matrix& m, Vector& v) {
        if (m.szr != v.sz) { //判断是否可以相乘
            cout << "Bad multiplying Matrix with Vector.";
            exit(0);
        }
        Vector res(m.szl);
        for (int i = 0; i < m.szl; ++i) {
            res[i] = 0;
            for (int j = 0; j < m.szr; ++j) {
                res[i] += m(i, j) * v[j];
            }
        }
        return res;
}


6-10 学生平均分计算
#include<iostream>
using namespace std;
class Stud
{
private:
    int no,score;
    string name;

public:
    static int sum;
    static int num;
    static int avg();
    Stud(int no1, string name1, int score1) {
        no = no1;name = name1;score = score1;
        num++;sum += score;
    }
    void disp() {
        cout << no << "," << name << "," << score << endl;
    }
};
int Stud::avg() {
        return sum / num;
}


6-11 圆类的定义与使用（拷贝构造函数）
class Circle
{
private:
    double r;
public:
    Circle(double r)
    {cout << "Constructor called" << endl;
        this->r = r;
    }
    Circle(Circle& c)
    {
        this->r = c.r;
        cout << "Copy constructor called" << endl;
    }
    double area()
    {
        return 3.14 * r * r;
    }
    double perimeter()
    {
        return 3.14 * r * 2;
    }
    ~Circle()
    {
        cout << "Destructor called" << endl;
    }
};


6-12 直角坐标*
class COORD {
    private:
        double X,Y;
    public:
        COORD() {
            this->X=0;this->Y=0;
        }
        COORD(double x,double y) {
            this->X=x;this->Y=y;
        }
        void Input() {
            char s;
            cin>>s>>X>>s>>Y>>s;
        }
        void Output() const{
            cout<<"("<<X<<", "<<Y<<")";
        }
        void Set(double x,double y) {
            this->X=x;
            this->Y=y;
        }
        void Get(double &x,double &y) const{
            x=this->X;
            y=this->Y;
        }
};


6-13 时间*
class TIME {
private:
    int hour;
    int minute;
    int second;
public:
    TIME(): hour(0), minute(0), second(0) {}
    TIME(int h, int m, int s): hour(h), minute(m), second(s) {}
    void Input() {
        char c;
        cin >> hour >> c >> minute >> c >> second;
    }
    void Output() const {
        cout << hour << ':' << minute << ':' << second;
    }
    void Set(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }
    void Get(int& h, int& m, int& s) const {
        h = hour;
        m = minute;
        s = second;
    }
};


6-14 学生排名表（析构函数）
Student *temp;
	for(int i=0;i<count;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(pS[i]->getRank()>pS[j]->getRank())
			{
				temp=pS[i];
				pS[i]=pS[j];
				pS[j]=temp;
			}
		}
	}
	for(int i=0;i<count;i++)
		delete pS[i];


6-15 Tree类的构造函数和成员函数
Tree::Tree()
{
	ages=1;
}
void Tree::grow(int years)//函数的类别不要忘记
{
	 ages+=years;
}
void Tree::age()
{
	cout<<ages<<endl;
}


6-16 自定义的学生类
Student::Student(int id,char *name)
{
    m_id=id;
    strcpy(m_name ,name) ;
    cout<<"Hi!"<<m_id<<" "<<m_name<<endl;
}

Student::~Student()
{
    cout<<"Bye!"<<m_id<<" "<<m_name<<endl;
}


6-17 角度的加法*
class ANGLE {
    private:
    int degree, minute, second;
    public:
    ANGLE() : degree(0), minute(0), second(0) {}
    ANGLE(int d, int m, int s) : degree(d), minute(m), second(s) {}

    void Input() {
        cin >> degree >> minute >> second;
    }

    void Output() const {
        cout << degree << " " << minute << " " << second;
    }

    ANGLE Add(const ANGLE& other) const {
        int total_seconds = (degree + other.degree) * 3600
                          + (minute + other.minute) * 60
                          + (second + other.second);
        int d = total_seconds / 3600;
        int m = (total_seconds % 3600) / 60;
        int s = total_seconds % 60;
        return ANGLE(d, m, s);
    }
};


6-18 平面矩形 - C/C++ 类与抽象
class Point {
public:
    int x;
    int y;

    Point(int _x=0,int _y=0){
        x = _x;y = _y;
    }
};
class Rect{
public:
    Point tl;
    Point br;

    Rect(const Point p1,const Point p2){
        tl = p1;br = p2;
    }
    Point topRight(){
        return Point(br.x,tl.y);
    }
    Point bottomLeft(){
        return Point(tl.x,br.y);
    }
    int width(){
        return br.x-tl.x;
    }
    int height(){
        return br.y-tl.y;
    }
    int area(){
        return width()*height();
    }
    double diagonalLength(){
        return sqrt(width()*width()+height()*height());
    }
};


6-19 类的定义（教师类Teacher）
Teacher::Teacher(string n,int a){
    name = n;
    age = a;
}
string Teacher::getName() const{
    return name;
}
int Teacher::getAge() const{
    return age;
}
void Teacher::setName(string n)
{
    name = n;
}
void Teacher::setAge(int a)
{
    age = a;
}


6-20 类的定义（雇佣员类Employee）
Employee::Employee(string n,int a){
    name = n;
    age = a;
}
string Employee::getName() const{
    return name;
}
int Employee::getAge() const{
    return age;
}
void Employee::setName(string n)
{
    name = n;
}
void Employee::setAge(int a)
{
    age = a;
}


6-21 日复一日 - C/C++ 类与抽象
class Date{
    private:
    int year;
    int month;
    int day;
    public:
    bool isLeapYear(int year){
    //四年一闰，百年不闰，四百年又闰
    if (year%400==0)
        return true;
    else if (year%100==0)
        return false;
    else if (year%4==0)
        return true;
    else
        return false;
    }
    Date(const int& y=0,const int& m=0,const int& d=0){
        year=y;
        month=m;
        day=d;
    }
    string toText(){
        char buffer[1024];
        sprintf(buffer,"%d-%d-%d",year,month,day);
        return buffer;
    }
    Date nextDay(){
        Date d;
        d.month=month;
        d.year=year;
        d.day=day;
        if(d.month==2){
            if(d.day==29){
                d.day=1;d.month++;
            }
            else if(d.day==28){
                if(isLeapYear(d.year)==true){
                    d.day++;
                }
                else{
                    d.day=1;d.month=3;
                }
            }
            else{
                d.day++;
            }
        }
        else if(d.month==4||d.month==6||d.month==9||d.month==11){
            if(d.day==30){
                d.day=1;d.month++;
            }
            else d.day++;
        }
        else if(d.month==12){
            if(d.day==31){
                d.day=1;d.month=1;d.year++;
            }
            else d.day++;
        }
        else{
            if(d.day==31){
                d.day=1;d.month++;
            }
            else d.day++;
        }
        return d;
    }
    Date prevDay(){
        Date d;
        d.month=month;
        d.year=year;
        d.day=day;
        if(d.month==3){
            if(d.day==1){
                if(isLeapYear(d.year)==true){
                    d.day=29;d.month=2;
                }
                else{
                    d.day=28;d.month=2;
                }
            }
            else{
                d.day--;
            }
        }
        else if(d.month==5||d.month==7||d.month==10||d.month==12){
            if(d.day==1){
                d.day=30;
                d.month--;
            }
            else d.day--;
        }
        else if(d.month==1){
            if(d.day==1){
                d.day=31;d.month=12;d.year--;
            }
            else d.day--;
        }
        else{
            if(d.day==1){
                d.day=31;d.month--;
            }
            else d.day--;
        }
        return d;
    }
};


6-22 凸N边形的面积 - C/C++ 类与抽象
class Point{
    public:
    double x {0};
    double y {0};
    Point(double x=0,double y=0){
        this->x=x;
        this->y=y;
    }
    double distToPoint(const Point& p) const{
        return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
    }
};
class Polygon{
    private:
    Point* pts {nullptr};
    unsigned int n {0};
    double computerTriangleArea(const Point& p1,const Point& p2,const Point& p3){
        auto a=p1.distToPoint(p2);
        auto b=p2.distToPoint(p3);
        auto c=p1.distToPoint(p3);
        double p=(a+b+c)/2.0;
        double s=sqrt(p*(p-a)*(p-b)*(p-c));
        return s;
    }

    public:
    Polygon(unsigned int N){
        pts=new Point[N];
        n=N;
    }

    Polygon(){
        delete [] pts;
        pts=nullptr;
        n=0;
    }

    void setVertice(int i,const Point& p){
        pts[i]=p;
    }

    Point getVertice(int i){
        return pts[i];
    }

    double getArea(){
        double dArea {0};
        for(auto i=1u;i<n-1;i++){
            dArea+=computerTriangleArea(pts[0],pts[i],pts[i+1]);
        }
        return dArea;
    }
};



6-23 面积计算器（函数重载）
int area(int x,int y)
{

    return x*y;
}
int area(int x,int y,int z)
{

        return 2*(x*y+y*z+x*z);
}


6-24 输出较大或较小值（函数模板）
template<class T>
    T m(T t,int task){
    T a,b;
    cin>>a>>b;
    if(task==1)
    {
        if(a>b)
        {
            return a;
        }
    }
    if(task==2){
            if(a<b)
            {
                return a;
            }
        }
    return b;
}


6-25 最大值函数重载
#include<iostream>
using namespace std;
int myMax(int x,int y)
{
    return x>y?x:y;
}
int myMax(int x,int y,int z)
{
    int max=x>y?x:y;
    return max>z?max:z;
}
double myMax(double x,double y){
    return x>y?x:y;
}


6-26 函数重载实现两数相加
int add(int x,int y)
{
    return x+y;
}
double add(double x,double y)
{
    return x+y;
}
string add(string x,string y)
{
    return x+y;
}


6-27 引用作函数形参交换两个整数
void Swap(int &a,int &b) {
    int *pa=&a;
    int *pb=&b;

    int temp=*pa;
    *pa=*pb;
    *pb=temp;
}

6-28 无规矩不成方圆 - C/C++ 多态
const float PI = 3.14159;
class Shape{
    public:
        Shape(){}
        virtual ~Shape(){}
        virtual float area()=0;
};
class Circle:public Shape{
    private:
        int x,y;
        float radius;
    public:
        Circle(int _x,int _y,float _radius):x(_x),y(_y),radius(_radius){}
        ~Circle(){}
        float area(){
            return PI*radius*radius;
        }
};
class Rectangle:public Shape{
    private:
        int width,heigth;
    public:
        Rectangle(int w,int h):width(w),heigth(h){}
        ~Rectangle(){}
        float area(){
            return width*heigth;
        }
};


6-29 继承和多态（人员、学生）
class Person{
 protected:
  string name;
  int age;
 public:
  Person(){}
  Person(string n,int a):name(n),age(a){}
  virtual void display() const{
   cout<<"人员姓名:"<<name<<","<<"年龄:"<<age<<endl;
  }
};
class Student:public Person{
 private:
  string id;
 public:
  Student(){}
  Student(string n,int a,string i):Person(n,a),id(i){}
  void display() const{
   cout<<"学生姓名:"<<name<<","<<"年龄:"<<age<<","<<"学号:"<<id<<endl;
  }
};


7-1 点到原点的距离（继承）
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class Point_1D
{
    protected:
    float x;//1D 点的x坐标

    public:
    Point_1D(float p = 0.0)
    {
        x = p;
    };
    void distance( )//计算当前点到原点的距离
    {
        cout<<"Distance from Point "<<x<<" to original point is "<<sqrt(x*x)<<endl;
    }
};

//以Point_1D为基类建立一个派生类Point_2D，增加一个保护数据成员：
class Point_2D:public Point_1D
{
    protected:
    float y;//2D平面上点的y坐标

    public:
    Point_2D(float a=0.0, float b=0.0)
    {
        x=a;
        y=b;
    }
    void distance()
    {
        cout<<"Distance from Point("<<x<<","<<y<<") to original point is "<<sqrt(x*x+y*y)<<endl;
    }
};

//以Point_2D为直接基类再建立一个派生类Point_3D，增加一个保护数据成员：
class Point_3D:public Point_2D
{
    protected:
    float z;//3D立体空间中点的z坐标

    public:
    Point_3D(float a=0.0, float b=0.0, float c=0.0)
    {
        x=a;
        y=b;
        z=c;
    }
    void distance()
    {
        cout<<"Distance from Point("<<x<<","<<y<<","<<z<<") to original point is "<<sqrt(x*x+y*y+z*z)<<endl;
    }
};

int main()
{
    int n;
    float a,b,c;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        if(n==1)
        {
            cin>>a;
            Point_1D point1D(a);
            point1D.distance();
        }
        else if (n==2)
        {
            cin>>a>>b;
            Point_2D point2D(a,b);
            point2D.distance();
        }
        else if (n==3)
        {
            cin>>a>>b>>c;
            Point_3D point3D(a,b,c);
            point3D.distance();
        }
    }
}


7-2 学生CPP成绩计算
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{
    protected:
    string name;
    int age;

    public:
    Person()
    {

    };
    Person (string p_name, int p_age)
    {
        name=p_name;
		age=p_age;
    };
    void display ()
    {
        cout<<name<<":"<<age<<endl;
    }
};

//建立一个派生类student,增加以下成员数据：
class Student:public Person
{
    int ID;//学号
    float cpp_score;//cpp上机成绩
    float cpp_count;//cpp上机考勤
    float cpp_grade;//cpp总评成绩
    //总评成绩计算规则：cpp_grade = cpp_score * 0.9 + cpp_count * 2;
    //增加以下成员函数：
    public :
    //student类的无参构造函数
    Student()
    {

    }
    //student类的参数化构造函数//注意cpp_grade为上机成绩和考勤的计算结果
    Student(string Name,int id,float a,float b)
    {
        name=Name;
     	ID=id;
	    cpp_score=a;
		cpp_count=b;
    }
    //void print()//输出当前student的信息
    void print()
    {
        cpp_grade=cpp_grade = cpp_score * 0.9 + cpp_count * 2;//其中cpp_grade输出保留一位小数
        //输出格式为ID name cpp_grade
     	cout<<ID<<" "<<name<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<cpp_grade<<endl;

    }

};

//生成上述类并编写主函数，根据输入的学生基本信息，建立一个学生对象，计算其cpp总评成绩，并输出其学号、姓名、总评成绩
int main()
{
    int ID;
    string name;
    int age;
    float cpp_score;
    float cpp_count;
	cin >> name;
	while(name!="0"){
        cin	>> ID >>age>> cpp_score >>cpp_count;
        Student a(name,ID,cpp_score,cpp_count);
        a.print();
        cin >> name ;
	}

    return 0;
}


7-3 计算全班学生C++课程的总成绩和平均成绩
#include <iostream>
using namespace std;

class Student
{
	static int total_score;
	static float average;
	int score;
	public:
		void Setscore()
		{
			int x;
			cin >> x;
			score = x;
		}
		int add()
		{
			total_score += score;
			return total_score;
		}
		int aver()
		{
			average *= total_score/5;
		}
		void show()
		{
			cout << total_score << endl;
			cout << average << endl;
		}
};
int Student::total_score = 0;
float Student::average = 1;

int main()
{
	Student a[5];
	int i;
	for (i=0;i<5;i++)
	{
		a[i].Setscore();
		a[i].add();
	}
	a[i].aver();
	a[i].show();
	return 0;
}


7-4 设计一个People类
#include<bits/stdc++.h>
using namespace std;
class people
{
	private:
		string name;
		int age;
		double h,w;
	public:
		void show()
		{
			name=" ";
			age=0;
			h=0;
			w=0;
		}
		void input()
		{
			cin>>name;
			while(name!="exit")
    	{
		    cin>>age>>h>>w;
		    cnt++;
		    cin>>name;
    	};
		}
		void output()
		{
			cout<<cnt;
		}
	static int cnt;
};
int people::cnt;
int main()
{
   	people A;
	A.input();
	A.output();
	return 0;

}


7-5 重载大于号运算符，比较复数大小
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Complex
{
public:
	Complex(int i, int j) :m(i), n(j){}
	int operator>(const Complex& c)
	{
		int square1 = pow(m, 2) + pow(n, 2);
		int square1_root1 = sqrt(square1);
		int square2 = pow(c.m, 2) + pow(c.n, 2);
		int square2_root1 = sqrt(square2);

		if (square1_root1>square2_root1){ return 1; }
		else if (square1_root1<square2_root1){ return -1; }
		else if (square1_root1 = square2_root1){ return 0; }

	}
private:
	int m, n;

};

int main()
{
	int x, y, m, n;
	cin >> x >> y >> m >> n;
	Complex c1(x, y);
	Complex c2(m, n);

	int rat = c1>c2;

	cout<< rat << endl;

	return 0;
}


7-6 加减乘除运算符
#include <iostream>
using namespace std;

int main(){
    double a,b,c,d;
    int num;
    cin >> a >> b;
    cin >> c >> d;
    cin >> num;

    printf("c1+c2=(%.2lf,%.2lfi)\n"
           "c1-c2=(%.2lf,%.2lfi)\n"
           "c1*c2=(%.2lf,%.2lfi)\n"
           "c1/c2=(%.2lf,%.2lfi)\n"
           "c1+num=(%.2lf,%.2lfi)\n"
           "c1-num=(%.2lf,%.2lfi)\n"
           "c1*num=(%.2lf,%.2lfi)\n"
           "c1/num=(%.2lf,%.2lfi)\n"
           "num+c1=(%.2lf,%.2lfi)\n"
           "num-c1=(%.2lf,%.2lfi)\n"
           "num*c1=(%.2lf,%.2lfi)\n"
           "num/c1=(%.2lf,%.2lfi)",
           a + c, b + d,
           a - c, b - d,
           ((a * c) - (b * d)), (b * c) + (a * d),

           ((a * c) + (b * d)) / ((c * c) + (d * d)),
           ((b * c) - (a * d)) / ((c * c) + (d * d)),

           a +num,b,
           a-num,b,
           a*num,b*num,
           a/num,b/num,

           a+num,b,

           num-a,0-b,
           num*a,num*b,

           ((num * a) + (0 * b)) / ((a * a) + (b * b)),
           ((0 * a) - (num * b)) / ((a * a) + (b * b))
           );
    return 0;
}



7-7 设计一个矩形类Rectangle并创建测试程序（C++）
#include<iostream>
using namespace std;
class Rectangle{
private:
    double width = 1;
    double height = 1;
public:
    Rectangle(){

    }
    Rectangle(double width,double height) {
        this->width = width;
        this->height = height;
    }
    double getArea() {
        return width * height;
    }
    double getPerimeter() {
        return width * 2 + height * 2;
    }
};

int main() {
    double width,height,area,perimeter;

    cin >> width >> height;

    Rectangle rectangle(width, height);

    area = rectangle.getArea();
    perimeter = rectangle.getPerimeter();

    cout << area << endl << perimeter << endl;
    return 0;
}


7-8 字符统计
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    char content;
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
    while ((content = getchar()) && (content != '\n'))
    {
        if (content >= '0' && content <= '9')
            n1++;
        else if (content >= 'A' && content <= 'Z')
            n2++;
        else if (content >= 'a' && content <= 'z')
            n3++;
        else if (content == ' ')
            n4++;
        else
            n5++;
    }
    cout<<"n1="<<n1<<"  "<<"n2="<<n2<<"  "<<"n3="<<n3<<"  "<<"n4="<<n4<<"  "<<"n5="<<n5;
    return 0;
}


7-9 求2个整数，3个整数的最大值，用同名函数实现
#include <iostream>
using namespace std;
int Max(int a,int b)
{
    return a>b?a:b;
}
int Max(int a,int b,int c)
{
    int t=a>b?a:b;
    t=t>c?t:c;
    return t;
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<Max(a,b)<<endl;
    cout<<Max(a,b,c)<<endl;
    return 0;
}


7-10 对角线 - C/C++ 语法基础
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std ;
int main()
{
    double a,b,c;
    cin >> a;
    cin >> b;
    c = sqrt((double)(a * a + b * b));
    cout << "The diagonal legnth is: "<<fixed<<setprecision(1)<<c<<" cm.";
}


7-11 计算圆的面积
#include <iostream>
using namespace std;
const double PI=3.1415926;
int main(){
    float r,s;
    cin>>r;
    cout<<PI*r*r;
}


7-12 英文字母 - C/C++ 变量及简单数据类型
#include <iostream>
using namespace std;
int main(){
    char Q,num2;
    int N,num1;
    cin>>Q>>N;
    num1 = Q-'A'+1;
    num2 = 'A'+N-1;
    cout<<num1<<endl<<num2;
    return 0;
}


7-13 猴子吃桃 - C/C++ 变量及简单数据类型
#include <iostream>
using namespace std;
int main(){
    int x,y,all1,all2;
    cin>>x;
    all2=(1+1)/0.01/(100-x);
    all1=(all2+1)/0.01/(100-x);
    y=(all1+1)/0.01/(100-x);
    cout<<"The monkey taken "<<y<<" peaches at the first day.";
    return 0;
}


7-14 温度单位转换 - C/C++ 语法基础
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double c,f;
    cin>>f;
    c=(f-32)*5/9;
    cout<<setprecision(3)<<c;
    return 0;
}

7-15 定义基类Point和派生类Circle，求圆的周长.
#include<iostream>
#include<iomanip>
#define PI 3.14
using namespace std;
class Point {
protected:
    float X, Y;
public:
    Point() {}
    Point(float x, float y) :X(x), Y(y) {
        cout << "Point constructor called" << endl;
    }~Point() {
        cout << "Point destructor called" << endl;
    }
};
class Circle :public Point {
    float R;
public:
    float c;
    Circle() {}
    Circle(float x, float y, float r) :Point(x, y), R(r) {
        cout << "Circle constructor called" << endl;
    };
    ~Circle() {
        cout << "Circle destructor called" << endl;
    }
    float getCircumference();
};
float Circle::getCircumference() {
    c = PI * R * 2;
    return c;
}int main()
{
    float x, y, r;
    cin >> x >> y >> r;
    Circle c(x, y, r);
    cout << fixed << setprecision(2) << c.getCircumference() << endl;
    return 0;
}


7-16 单继承中的构造函数与析构函数
#include <iostream>
#include<iomanip>
using namespace std;
const double PI=3.14;
//请编写你的代码
class Dot{
    private:
    float x;
    float y;
    public:
    Dot(float a,float b):x(a),y(b){
        cout<<"Dot constructor called"<<endl;
    }
    ~Dot(){
        cout<<"Dot destructor called"<<endl;
    }
};
class Cir:public Dot{
    private:
    float r;
    public:
    Cir(float a,float b,float c):Dot(a,b),r(c){
        cout<<"Cir constructor called"<<endl;
    }
    ~Cir(){
        cout<<"Cir destructor called"<<endl;
    }
    double getArea(){
        return PI*r*r;
    }
};
int main(){
    float x,y,r;
    cin>>x>>y>>r;
    Cir c(x,y,r);
    cout<<fixed<<setprecision(2)<<c.getArea()<<endl;
    //system("pause");
    return 0;
}
