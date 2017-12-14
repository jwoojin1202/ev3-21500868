#include "h_crane.h"
#include <iostream>



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
    Crain():m_speed(0), touch_q(ev3dev::INPUT_2), ultra_q(ev3dev::INPUT_3),b(ev3dev::OUTPUT_B), c(ev3dev::OUTPUT_C), a(ev3dev::OUTPUT_A)
    {
        
    }
    
    int m_speed;
    
    float get_distance_centimeters() 
    {
        return ultra_q.distance_centimeters();
    }
    
    bool get_touch_pressed()
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

    virtual int  get_speed()
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
    void example_code2();
};

void Crain::example_code2()
{
      
        a.reset(); //위 아래
        b.reset(); //집게
        c.reset(); //좌우
        //start에서 finish 로
        b.set_speed_sp(500);
        b.set_position_sp(-200);
        b.run_to_abs_pos();
        b.set_stop_action("hold");
        b.stop();
        c.set_speed_sp(500);
        c.set_position_sp(600);
        c.run_to_abs_pos();
        sleep(2);
        std::cout<<"hello"<<std::endl;
        /*// 집게 내려가기
        b.set_speed_sp(300);
        b.set_position_sp(0);
        b.run_to_abs_pos();
        sleep(2);
        b.set_stop_action("hold");
        std::cout<<"hello1"<<std::endl;
        //집게가 잡는부분
        a.set_speed_sp(300);
        a.set_position_sp(50);
        a.run_to_abs_pos();
        a.set_stop_action("hold");
        sleep(2);
        std::cout<<"hello2"<<std::endl;
        //집게 올리는 부분
        b.set_speed_sp(300);
        b.set_position_sp(-200);
        b.run_to_abs_pos();
        b.set_stop_action("hold");
        sleep(2);
        
        std::cout<<"hello3"<<std::endl;
        */
        
        float distance;
      
        
        for(int i = 0; i < 3 ; i++)
        {
            distance = 20;
            //탐지
            while(distance  > 15){
            
               distance = ultra_q.distance_centimeters();
               c.set_position_sp(-20);
               c.set_speed_sp(150);
               c.run_to_rel_pos();
               std::cout << distance << std::endl;
            }
            //집게 내리기
            b.set_speed_sp(300);
            b.set_position_sp(0);
            b.run_to_abs_pos();
            b.set_stop_action("hold");
            b.stop();
            sleep(1);
            std::cout<<"hello1"<<std::endl;
            //집게가 잡는부분
            a.set_speed_sp(300);
            a.set_position_sp(50);
            a.run_to_abs_pos();
            a.set_stop_action("hold");
            sleep(1);
            std::cout<<"hello2"<<std::endl;
            //집게 올리는 부분
            b.set_speed_sp(300);
            b.set_position_sp(-200);
            b.run_to_abs_pos();
            b.set_stop_action("hold");
            sleep(1);
            //finish로
            c.set_speed_sp(600);
            c.set_position_sp(510);
            c.run_to_abs_pos();
            sleep(1);
            // 내리기
            b.set_speed_sp(600);
            b.set_position_sp(0);
            b.run_to_abs_pos();
            sleep(1);
            // 집게 피기
            a.set_speed_sp(500);
            a.set_position_sp(0);
            a.run_to_abs_pos();
            sleep(0.8);
            // 올리기
            b.set_speed_sp(500);
            b.set_position_sp(-200);
            b.run_to_abs_pos();
            b.set_stop_action("hold");
            
        }
        
        
    /*b.set_position_sp(0);
    b.set_speed_sp(300);
    b.run_to_rel_pos();
    
    c.set_position_sp(0);
    c.set_speed_sp(300);
    c.run_to_abs_pos();
    
    a.set_position_sp(0);
    a.set_speed_sp(300);
    a.run_to_abs_pos();
    */
        
        
        
        
        
    
        
     
        
        
        
        

    
}
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
        
        int posa, posb, posc;
        a.reset();
        b.reset();
        c.reset();
        posa = a.position();
        posb = b.position();
        posc = c.position();
        std::cout << "posa: "<< posa << std::endl;
        std::cout << "posb: "<< posb << std::endl;
        std::cout << "posc: "<< posc << std::endl;
        
        if(get_up())
        {   
                a.set_speed_sp(-1*get_speed());
                a.run_forever();
        }   
        if(get_down())
        {
                a.set_speed_sp(get_speed());
                a.run_forever();
        }
        if(get_left())
        {
               b.set_speed_sp(get_speed());
               b.run_forever();
        }
        if(get_right())
        {
               b.set_speed_sp(-1* get_speed());
               b.run_forever();
        }
       
       
        if(!(get_up() | get_down() | get_right() | get_left() | get_enter()))
        {
            a.set_speed_sp(0);
            a.run_forever();
            b.set_speed_sp(0);
            b.run_forever();
        }
    }

    a.stop();
    b.stop();
}

int main()
{     
    Crain crain;
    while(true){
        if(crain.get_touch_pressed()==true){ 
            
        
        crain.example_code(); //This line is for example, you should erase this ex_code in your 'real code' 
  
        }
    }
}