typedef struct _gtkQueryLabel{

	void (*write) (char*);
	void (*writeDouble) (double);

}gtkQueryLabel;

gtkQueryLabel label(char*);
void write(char*);
void writeDouble(double);