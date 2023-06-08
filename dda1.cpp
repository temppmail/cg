#include<GL/glut.h>
#include<math.h>

void setPixel(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}


void dda( float x1, float y1, float x2, float y2){
    
    float dx = x2 - x1;
    float dy = y2 - y1;
    
    float steps;
    
    if(abs(dx) > abs(dy)){
        steps = abs(dx);
    }else{
        steps = abs(dy);
    }
    
    float x_in = dx/steps;
    float y_in = dy/steps;
    
    float x = x1;
    float y = y1;
    
    
    
    for(int i = 0 ; i < steps ; i++){
    	setPixel(x,y);
    	x += x_in;
    	y += y_in;
    }

}


void draw(){
    
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glColor3f(1,1,1);
    gluOrtho2D(-524,524,-312,312);
    
    dda(0,0,0,200);
    dda(0,200,400,200);
    dda(400,200,400,0);
    dda(400,0,0,0);
    
    dda(20,20,20,180);
    dda(20,180,380,180);
    dda(380,180,380,20);
    dda(380,20,20,20);
    
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    
    glutInitWindowSize(800,800);
    glutInitWindowPosition(100,100);
    glutCreateWindow("window 1");
    
    glutDisplayFunc(draw);
    
    glutMainLoop();
    return 0 ;
}
