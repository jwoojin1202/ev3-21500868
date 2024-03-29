#include <iostream>
#include "h_crane.h"
#include "ev3dev.h"


class Crain : public CraneCrane
{
private:
ev3dev::touch_sensor touch_q;
ev3dev::ultrasonic_sensor ultra_q;
ev3dev::motor a;
ev3dev::motor b; 
ev3dev::motor c;

public:
// Hardware Configuration
Crain():m_speed(0), touch_q(ev3dev::INPUT_2),a(ev3dev::OUTPUT_B), b(ev3dev::OUTPUT_C), c(ev3dev::OUTPUT_A)
{

}

int m_speed;

bool get_touch_pressed() // 눌렀는지 안눌렀는지 확인하기.!

{
return touch_q.is_pressed();
}

virtual bool get_down()
{
return m_down;
}

virtual bool get_up()
{
return m_up;
}

virtual bool get_right()
{
return m_right;
}

virtual bool get_left()
{
return m_left;
}

virtual bool get_enter()
{
return m_enter;
}

virtual bool get_escape()
{
return m_escape;
}

virtual int get_speed()
{
return 100;
}

virtual void set_down(bool val)
{
m_down = val;
}

virtual void set_up(bool val)
{
m_up = val; 
}

virtual void set_right(bool val)
{
m_right = val; 
}
virtual void set_left(bool val)
{
m_left = val; 
} 

virtual void set_enter(bool val)
{
m_enter = val; 
}

virtual void set_escape(bool val)
{
m_escape = val; 
}

virtual void set_speed(int val)
{
m_speed = val; 
}
public:
void example_code();
};

/*
void Crain::real_code()
{
//먼저 디텍트 할려면 감지하는 센서가 필요함

}

*/

void Crain::example_code()
{ //This function is for example, you should develop your own logics



while(get_escape() == false)
{
set_down(ev3dev::button::down.pressed());
set_up(ev3dev::button::up.pressed());
set_right(ev3dev::button::right.pressed());
set_left(ev3dev::button::left.pressed());
set_escape(ev3dev::button::back.pressed());
set_enter(ev3dev::button::enter.pressed());

float test;
test = ultra_q.distance_centimeters();
//std::cout << test << std::endl;
int posa, posb, posc;
posa = a.position();
posb = b.position();
posc = c.position();
std::cout << "posa: "<< posa << std::endl;
std::cout << "posb: "<< posb << std::endl;
std::cout << "posc: "<< posc << std::endl;


int posa_sp, posb_sp, posc_sp;
posa_sp =a.position_sp(); 
posb_sp =b.position_sp(); 
posc_sp =c.position_sp(); 
std::cout << "posa_sp: " << posa_sp << std::endl;
std::cout << "posb_sp: " << posb_sp << std::endl;
std::cout << "posc_sp: " << posc_sp << std::endl;


if(get_up())
{ 
a.set_speed_sp(-2*get_speed());
a.run_forever();
} 
if(get_down())
{
a.set_speed_sp(2*get_speed());
a.run_forever();
}
if(get_left())
{
b.set_speed_sp(2*get_speed());
b.run_forever();
}
if(get_right())
{
b.set_speed_sp(-2*get_speed());
b.run_forever();
}
if(get_enter())
{
c.set_speed_sp(-1* get_speed());
c.run_forever();
}

if(!(get_up() | get_down() | get_right() | get_left() | get_enter()))
{
a.set_speed_sp(0);
a.run_forever();
b.set_speed_sp(0);
b.run_forever();
c.set_speed_sp(0);
c.run_forever();
}
}

a.stop();
b.stop();
c.stop();
}


int main()
{ 
Crain crain;

while(true){
if(crain.get_touch_pressed()==true){ 


crain.example_code(); // This line is for example, you should erase this ex_code in your 'real code' 

}
}
}
