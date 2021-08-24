#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
//-lX11
int	main(int argc, char *argv[])
{
	Display	*dpy;
	int		screen;
	Window	win;
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
	//mantemos ela ativa
	while (1)
	{
		XNextEvent(dpy, &event);
	}

	return (0);
}
