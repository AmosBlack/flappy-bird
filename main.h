
//SPRITE
class Sprite{
    public:
        double x, y, radius;
        bool falling = true;
        double g = 0.1;
        double velocity = 0;
    
    Sprite(double x, double y, int radius){
        this->x = x;
        this->y = y;
        this->radius = radius;
    }

    void updateSprite(){
        y -= velocity;
        DrawCircle(x, y, radius, PINK);
    }

    void gravity(){
        if(falling)
            velocity -= 0.01;
            updateSprite();
    }

    void goUp(){
        bool goUp = IsKeyPressed(KEY_UP);
        if(goUp){/*w*/
            velocity = 0;
            falling = false;
            int end = y - 30;
            double increment = 0.005;
            goUp = false;
            while(y > end){ 
                velocity += increment;
                updateSprite();
            }
            while(velocity > 0){
                velocity -= increment;
            }
            falling = true;
        }
    }
};

// //PILLARS
// class PillarPair{
//     public:
//         Rectangle A,B;
//         double posx = RectangleA.x;
//         //Color color; check docs
    
//     Pillar(Rectangle A, Rectangle B ){
//         this->A = A;
//         this->B = B;
//     }



// };
//GAME

