#include<graphics.h>
#include<math.h>
#include<stdio.h>
#include<dos.h>

double p_x[8]={0,0,1,1,0,0,1,1};
double p_y[8]={0,1,1,0,0,1,1,0};
double p_z[8]={0,0,0,0,1,1,1,1};

int Julia(int i,int j)
{
	int a=200,b=200;
	double p=0.33,q=0.4;
	int K = 15,k=0;
	int M = 100;
	double xmin=-1.5,ymin=-1.5,xmax=1.5,ymax=1.5,xx,yy,x0,y0,x1,y1,r;
	xx=(xmax-xmin)/(a-1);
	yy=(ymax-ymin)/(b-1);
	x0=xmin+i*xx;
	y0=ymin+j*yy;
	k=0;
	while(1){
		x1=x0*x0-y0*y0+p;
		y1=2*x0*y0+q;
		k=k+1;
		r=x0*x0+y0*y0;
		if(r>M){break;}
		else if(k==K){k=0;break;}
		else {x0=x1;y0=y1;}
	}
	return k;
}

void trance(double* x,double*y,double x1,double y1,double z1,int i,double zprp){
	x[i] = x1*1/(1-z1/zprp);
	y[i] = y1*1/(1-z1/zprp);
}

double tranceJuliax(double x1,double z1,double zprp){
	return x1*1/(1-z1/zprp);
}
double tranceJuliay(double y1,double z1,double zprp){
	return y1*1/(1-z1/zprp);
}

main()
{
	int flag0=1,flag1=0,flag2=0,flag3=0,flag4=0,flag5=1;
	double j_x=0;
	double j_y=0;
	double ii,jj;
	int j_xx=0;
	int j_yy=0;
	double x_min,x_max,y_min,y_max,sx,sy,zprp=2.0,pp_x[8],pp_y[8];
	int i,j,k;
	int xv[8],yv[8];
	char c;
	int driver = DETECT,mode;
  	initgraph(&driver,&mode,"d:\\tc");
	while(1){
		for(i=0;i<8;i++){
			trance(pp_x,pp_y,p_x[i],p_y[i],p_z[i],i,zprp);
		}
		x_min = pp_x[0];
		x_max = pp_x[0];
		y_min = pp_y[0];
		y_max = pp_y[0];
		for(i=0;i<8;i++){
			if(x_min>pp_x[i])
				x_min = pp_x[i];
			if(x_max<pp_x[i])
				x_max = pp_x[i];
			if(y_min>pp_y[i])
				y_min = pp_y[i];
			if(y_max<pp_y[i])
				y_max = pp_y[i];
		}
		sx=(300-100)/(x_max-x_min);
		sy=(300-100)/(y_max-y_min);
		for(i=0;i<8;i++){
			xv[i]=100+(pp_x[i]-x_min)*sx;
			yv[i]=100+(pp_y[i]-y_min)*sy;
		}
		setcolor(14);
		
		rectangle(xv[5],yv[5],xv[7],yv[7]);
		rectangle(xv[1],yv[1],xv[3],yv[3]);
		line(xv[0],yv[0],xv[4],yv[4]);
		line(xv[1],yv[1],xv[5],yv[5]);
		line(xv[2],yv[2],xv[6],yv[6]);
		line(xv[3],yv[3],xv[7],yv[7]);


		if(xv[1]<xv[5]){flag1=1;}	else flag1=0;
		if(xv[2]>xv[6]){flag2=1;}	else flag2=0;
		if(yv[0]<yv[4]){flag3=1;}	else flag3=0;
		if(yv[1]>yv[5]){flag4=1;}	else flag4=0;


		if(flag3==1){
			for(i=0,ii=p_x[0];i<200;i++,ii=ii+0.005){
				for(j=0,jj=p_z[0];j<200;j++,jj=jj+0.005){
					j_x=tranceJuliax(ii,jj,zprp);
					j_y=tranceJuliay(p_y[0],jj,zprp);
					j_xx=(int)(100+(j_x-x_min)*sx);
					j_yy=(int)(100+(j_y-y_min)*sy);
					k=Julia(i,j);
					putpixel(j_xx,j_yy,k);

				}
			}
			line(xv[0],yv[0],xv[4],yv[4]);
			line(xv[3],yv[3],xv[7],yv[7]);
			line(xv[0],yv[0],xv[3],yv[3]);
		}

		if(flag1==1){
			for(i=0,ii=p_y[0];i<200;i++,ii=ii+0.005){
				for(j=0,jj=p_z[0];j<200;j++,jj=jj+0.005){
					j_x=tranceJuliax(p_x[1],jj,zprp);
					j_y=tranceJuliay(ii,jj,zprp);
					j_xx=(int)(100+(j_x-x_min)*sx);
					j_yy=(int)(100+(j_y-y_min)*sy);
					k=Julia(i,j);
					putpixel(j_xx,j_yy,k);

				}
			}
			line(xv[0],yv[0],xv[4],yv[4]);
			line(xv[1],yv[1],xv[5],yv[5]);
			line(xv[1],yv[1],xv[0],yv[0]);
		}

		if(flag2==1){
			for(i=0,ii=p_y[3];i<200;i++,ii=ii+0.005){
				for(j=0,jj=p_z[3];j<200;j++,jj=jj+0.005){
					j_x=tranceJuliax(p_x[3],jj,zprp);
					j_y=tranceJuliay(ii,jj,zprp);
					j_xx=(int)(100+(j_x-x_min)*sx);
					j_yy=(int)(100+(j_y-y_min)*sy);
					k=Julia(i,j);
					putpixel(j_xx,j_yy,k);

				}
			}
			line(xv[2],yv[2],xv[6],yv[6]);
			line(xv[3],yv[3],xv[7],yv[7]);
			line(xv[2],yv[2],xv[3],yv[3]);
		}
		if(flag4==1){
			for(i=0,ii=p_x[1];i<200;i++,ii=ii+0.005){
				for(j=0,jj=p_z[1];j<200;j++,jj=jj+0.005){
					j_x=tranceJuliax(ii,jj,zprp);
					j_y=tranceJuliay(p_y[1],jj,zprp);
					j_xx=(int)(100+(j_x-x_min)*sx);
					j_yy=(int)(100+(j_y-y_min)*sy);
					k=Julia(i,j);
					putpixel(j_xx,j_yy,k);

				}
			}
			line(xv[2],yv[2],xv[6],yv[6]);
			line(xv[1],yv[1],xv[5],yv[5]);
			line(xv[1],yv[1],xv[2],yv[2]);
		}

		if(flag0==1){
			for(i=0,ii=p_x[5];i<200;i++,ii=ii+0.005){
				for(j=0,jj=p_y[7];j<200;j++,jj=jj+0.005){
					j_x=tranceJuliax(ii,p_z[5],zprp);
					j_y=tranceJuliay(jj,p_z[5],zprp);
					j_xx=(int)(100+(j_x-x_min)*sx);
					j_yy=(int)(100+(j_y-y_min)*sy);
					k=Julia(i,j);
					putpixel(j_xx,j_yy,k);

				}
			}
			rectangle(xv[5],yv[5],xv[7],yv[7]);
		}


		c=getch();
		if(c=='a'){
			for(i=0;i<8;i++){
				p_x[i]+=0.1;
			}
		}
		else if(c=='d'){
			for(i=0;i<8;i++){
				p_x[i]-=0.1;
			}
		}
		else if(c=='w'){
			for(i=0;i<8;i++){
				p_y[i]+=0.1;
			}
		}
		else if(c=='s'){
			for(i=0;i<8;i++){
				p_y[i]-=0.1;
			}
		}
		else if(c=='q'){
			for(i=0;i<8;i++){
				p_z[i]-=0.1;

			}
		}
		else if(c=='e'){
			for(i=0;i<8;i++){
				p_z[i]+=0.1;

			}
		}
		else if(c=='r'){closegraph();}

		setfillstyle(1,BLACK);
		bar(20,20,480,640);

	}
}
