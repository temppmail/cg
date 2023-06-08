#include<GL/glut.h>


void setPixel(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void bresline(float x1, float y1, float x2, float y2){

    float dx = x2 - x1;
    float dy = y2 - y1;
    float xc,yc;
    int x = x1;
    int y = y1;
    if(dx < 0){
    	dx = -dx;
    	xc = -1;
    }else{
    	xc = 1;
    } 
     
    if(dy < 0){
    	dy = -dy;
    	yc = -1;
    }else{
    	yc = 1;
    }
    
    if(dx == 0){
    	for(int i = 0 ; i < abs(dy) ; i++){
    	    setPixel(x,y);
    	    y = y+yc;
    	    
    	}
    	return;
    }
    
    if(dy == 0){
    	for(int i = 0 ; i < abs(dx) ; i++){
    	    setPixel(x,y);
    	    x = x+xc;
    	}
    	return;
    }
    
    if(dx > dy){
    
    	float p = 2*dy - dx;
    	
    	for(int i = 0 ; i < abs(dx) ; i++){
    	    if(p > 0){
    	    	p = p + (2*dy) - (2*dx);
    	    	y = y+yc;
    	    }else{
    	    	
    	    	p = p + (2*dy);
    	    }
    	    x = x+xc;
    	    setPixel(x,y);
    	}
    	
    }
    
    if(dx <= dy){
    
    	float p = 2*dx - dy;
    	
    	for(int i = 0 ; i < abs(dy) ; i++){
    	    if(p > 0){
    	    	p = p + (2*dx) - (2*dy);
    	    	x = x+xc;
    	    }else{
    	    	
    	    	p = p + (2*dx);
    	    }
    	    y = y+yc;
    	    setPixel(x,y);
    	}
    	
    }


}

void draw(){
    
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glColor3f(1,1,1);
    gluOrtho2D(-524,524,-312,312);
    
    //for(int i = -524 ; i < 524 ; i++){
    	//setPixel(i,0);
    //}
    //for(int i = -312 ; i < 312 ; i++){
    	//setPixel(0,i);
    //}
    
    bresline(0,0,0,300);
    bresline(0,300,400,300);
    bresline(400,300,400,0);
    bresline(400,0,0,0);
    
    bresline(20,20,20,280);
    bresline(20,280,380,280);
    bresline(380,280,380,20);
    bresline(380,20,20,20);
    
    bresline(20,20,70,130);
    bresline(70,130,140,20);
    bresline(140,20,280,240);
    bresline(280,240,380,20);
    //bresline(2);
    
    
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    
    glutInitWindowSize(800,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("window 1");
    
    glutDisplayFunc(draw);
    
    glutMainLoop();
    return 0 ;
}
