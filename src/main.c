#include <nds.h>

u32 triangle[] = 
{
    12,
    FIFO_COMMAND_PACK(FIFO_BEGIN, FIFO_COLOR, FIFO_VERTEX16, FIFO_COLOR),
    GL_TRIANGLE,
    RGB15(31,0,0),
    VERTEX_PACK(inttov16(-1), inttov16(-1)), VERTEX_PACK(0,0),
    RGB15(0,31,0),
    FIFO_COMMAND_PACK(FIFO_VERTEX16, FIFO_COLOR, FIFO_VERTEX16, FIFO_END),
    VERTEX_PACK(inttov16(1), inttov16(1)), VERTEX_PACK(0,0),
    RGB15(0,0,31),
    VERTEX_PACK(inttov16(0), inttov16(1)), VERTEX_PACK(0,0),
};

int main()
{
    float rotateX = 0.0f;
    float rotateY = 0.0f;
    //set mode 0, enable BG0, and set it to 3D.
    videoSetMode(MODE_0_3D);
    
    glInit();
    glEnable(GL_ANTIALIAS); 

    glClearColor(0, 0, 0, 31); //BG must be opaque for AA to work
    glClearPolyID(63); //BG must have a unique polygon ID for AA to work
    glClearDepth(0x7FFF);

    //should work the same as normal gl call
    glViewport(0,0,255,191);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 256.0f / 192.0f, 0.1f, 40);

    gluLookAt( 0.0f, 0.0f, 1.0f,  //camera position
               0.0f, 0.0f, 0.0f,  //look at
               0.0f, 1.0f, 0.0f); //up

    while(1)
    {
        glPushMatrix();
        glTranslatef32(0, 0, floattof32(-1));
        
        glRotateX(rotateX);
        glRotateY(rotateY);
        
        glMatrixMode(GL_TEXTURE);
        glLoadIdentity();

        glMatrixMode(GL_MODELVIEW);

        glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);

        scanKeys();
        
        u16 keys = keysHeld();
    
        if((keys & KEY_UP)){ rotateX += 3; }
        if((keys & KEY_DOWN)){ rotateX -= 3; }
        if((keys & KEY_LEFT)){ rotateY += 3; }
        if((keys & KEY_RIGHT)){ rotateY -= 3; }

        glCallList(triangle);

        glPopMatrix(1);
        glFlush(0);
    }

    return 0;
}
