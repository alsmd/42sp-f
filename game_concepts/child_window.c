#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
//////////////////////
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
//-lX11
int	main(int argc, char *argv[])
{
	Display	*dpy;
	int		screen;
	Window	win;
	Window	childwin;
	XEvent	event;

	dpy = XOpenDisplay(NULL);///faz a conexão com o servidor X

	if (dpy == NULL)//caso a conexão falhe sairemos
	{
		fprintf(stderr, "Cannot open display");
		exit(1);
	}
	screen = DefaultScreen(dpy);//criamos uma screen padrão
	//criamos uma window comas as caracteresticas que queremos
	win = XCreateSimpleWindow(dpy, RootWindow(dpy, screen), 100, 100, 800, 450, 1, BlackPixel(dpy, screen), WhitePixel(dpy, screen));
	//Os eventos que nossa servidor estara recebendo
	XSelectInput(dpy, win, ExposureMask | KeyPressMask);
	//instanciamos nossa window
	XMapWindow(dpy, win);

	//Child Window
	childwin = XCreateSimpleWindow(dpy, win, 20, 20, 200, 100, 1, BlackPixel(dpy, screen), WhitePixel(dpy, screen));
	XSelectInput(dpy, childwin, ExposureMask | KeyPressMask);
	XMapWindow(dpy, childwin);
	//mantemos ela ativa
	while (1)
	{
		XNextEvent(dpy, &event);
		if (event.xany.window == childwin)
		{
			if (event.type == Expose)
			{
				//draw something on the screen
				XDrawLine(dpy, childwin, DefaultGC(dpy, screen), 10, 10, 60, 60);
				XDrawLine(dpy, childwin, DefaultGC(dpy, screen), 10, 60, 60, 10);
			}
		}
	}

	return (0);
}
