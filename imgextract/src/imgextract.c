#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


int main(int argc,char** argv)
{
    int i=0;
    int j=0;
    int x=0;
    int y=0;
    int w=0;
    int h=0;
    short nframes=0;
    char palette[16][3];
    char image[4][128];
    if(argc<3) {
        printf("Argumentos:\n\r imgextract <files.png> <outfile.led>\n");
        return  1;
    }

    SDL_Surface *surface=NULL;
    memset(&(palette[0][0]),0,16*3);

    surface=IMG_Load(argv[1]);
    w=surface->w;
    h=surface->h;

    nframes=argc-2;
    if(surface->format->palette!=NULL)
    {
        SDL_Palette* pal=surface->format->palette;
        if(pal->ncolors>16)
        {
            printf("Error, > 16 colors\n");
            exit(0);
        }
        printf("char colors[%d][3]={",pal->ncolors);
        for(int i=0;i<pal->ncolors;i++)
        {
            printf("{0x%x ,0x%x ,0x%x},",pal->colors[i].r,pal->colors[i].g,pal->colors[i].b);
            palette[i][0]=pal->colors[i].r;
            palette[i][1]=pal->colors[i].g;
            palette[i][2]=pal->colors[i].b;
        }
        printf("};\n");
    }

    printf("char img[%d]={",nframes*w*h);

    for ( i=1; (i<(nframes+1))&&(i<5); ++i ) {
        surface=IMG_Load(argv[i]);
        //printf("char figure%d[]=\"%s\";\nint w= %d;\nint h=%d ;\nint pitch= %d;int bbp= %d; \n",i,argv[i],surface->w,surface->h,surface->pitch,surface->format->BitsPerPixel);
        //fwrite()
        //printf("{\n");
        for(y=0;y<h;y++)
        {
            for(x=0;x<w;x+=2)
            {
                unsigned char coloridx1=(((char *)surface->pixels)[y*w + x])&0x0F;
                unsigned char coloridx2=(((char *)surface->pixels)[y*w + x+1])&0x0F;
                unsigned char coloridx=(coloridx1<<4)|(coloridx2);
                printf("0x%x,",coloridx);
                image[i-1][(y*w + x)/2]=coloridx;
            }
            printf("\n");
        }
       //printf("}\n");
    }
    printf("};\n");
    FILE* fout=fopen(argv[argc-1],"w");
    //fwrite(&w,1,sizeof(int))
    fwrite(&nframes,1,sizeof(short),fout);
    for(i=0;i<16;i++)
	for(j=0;j<3;j++)
    	   fwrite(&(palette[i][j]),1,1,fout);
    for(i=0;i<4;i++)
	for(j=0;j<128;j++)
          fwrite(&(image[i][j]),1,1,fout);
return 0;
}
