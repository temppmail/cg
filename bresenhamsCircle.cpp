#include<GL/glut.h>

void setPixel(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void bcircle(int x1, int y1,int r){
    
    int x = 0;
    int y = r;
    setPixel(x+x1,y+y1);
    int p = 3-(2*r);
    while(x<=y){
    	x+=1;
    	if(p < 0){
	    p = p + (4*x)+6;  
    	}else{
    	    y -=1;
    	    p = p+(4*(x-y))+10;
    	}
    	setPixel(x1+x, y1+y);
    	setPixel(x1+x, y1-y);
    	setPixel(x1-x, y1+y);
    	setPixel(x1-x, y1-y);
    	
    	setPixel(x1+y, y1+x);
    	setPixel(x1+y, y1-x);
    	setPixel(x1-y, y1+x);
    	setPixel(x1-y, y1-x);
    }
}

void draw(){
    
    for(int i = -524 ; i < 524 ; i++){
        setPixel(i,0);
    }
    for(int i = -312 ; i < 312 ; i++){
        setPixel(0,i);
    }
    
    bcircle(0,0,100);
    bcircle(0,0,150);
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    
    glutInitWindowSize(800,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("window 1");
    
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    
    gluOrtho2D(-524,524,-321,321);
    
    glutDisplayFunc(draw);
    
    glutMainLoop();
    
    return 0;
    
}
