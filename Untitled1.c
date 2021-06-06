#include<stdio.h>

#include<gtk/gtk.h>



    GtkBuilder *builder;


void show1(GtkWidget *widget,gpointer   user_data){



    GtkWidget *window11;
    GtkWidget  *button1,*buttonn1 ,*buttonnn1,*buttonnne1,* buttonnnn1;





    builder=gtk_builder_new_from_file("ttaha.glade");
    window11=GTK_WIDGET(gtk_builder_get_object(builder,"window2"));
     button1=GTK_WIDGET(gtk_builder_get_object(builder,"button1"));
      buttonn1=GTK_WIDGET(gtk_builder_get_object(builder,"button2"));
       buttonnn1=GTK_WIDGET(gtk_builder_get_object(builder,"button3"));
        buttonnne1=GTK_WIDGET(gtk_builder_get_object(builder,"button4"));
         buttonnnn1=GTK_WIDGET(gtk_builder_get_object(builder,"button5"));


    gtk_widget_show(window11);





}
void show2(GtkWidget *widget,gpointer   user_data){



    GtkWidget *window12;
    GtkWidget  *button2,*buttonn2 ,*buttonnn2,* buttonnnn2;



    builder=gtk_builder_new_from_file("gestion.glade");
    window12=GTK_WIDGET(gtk_builder_get_object(builder,"window3"));
     button2=GTK_WIDGET(gtk_builder_get_object(builder,"button1"));
      buttonn2=GTK_WIDGET(gtk_builder_get_object(builder,"button2"));
       buttonnn2=GTK_WIDGET(gtk_builder_get_object(builder,"button3"));
        buttonnnn2=GTK_WIDGET(gtk_builder_get_object(builder,"button4"));


    gtk_widget_show(window12);





}
void show3(GtkWidget *widget,gpointer   user_data){



    GtkWidget *window13;
    GtkWidget  *button3,*buttonn3 ,*buttonnn3,* buttonnnn3;



    builder=gtk_builder_new_from_file("gestioncli.glade");
    window13=GTK_WIDGET(gtk_builder_get_object(builder,"window4"));
     button3=GTK_WIDGET(gtk_builder_get_object(builder,"button1"));
      buttonn3=GTK_WIDGET(gtk_builder_get_object(builder,"button2"));
       buttonnn3=GTK_WIDGET(gtk_builder_get_object(builder,"button3"));
        buttonnnn3=GTK_WIDGET(gtk_builder_get_object(builder,"button4"));


    gtk_widget_show(window13);





}





int main(int argc ,char **argv){
    gtk_init(&argc,&argv);
    GtkBuilder *builder;

    GtkWidget *window,*window11,*window22,*window33;
    GtkWidget *button,*buttonn ,*buttonnn;

    builder=gtk_builder_new_from_file("first.glade");
    window=GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    button=GTK_WIDGET(gtk_builder_get_object(builder,"button1"));
    buttonn=GTK_WIDGET(gtk_builder_get_object(builder,"button2"));
    buttonnn=GTK_WIDGET(gtk_builder_get_object(builder,"button3"));
gtk_widget_show_all(window);

g_signal_connect(button,"clicked", G_CALLBACK(show1) , NULL );
g_signal_connect(buttonn,"clicked", G_CALLBACK(show2) , NULL );
g_signal_connect(buttonnn,"clicked", G_CALLBACK(show3) , NULL );








    gtk_main();
    return 0;
}
