#include <gtk/gtk.h>
int main (int argc,char *argv[])
{
GtkWidget *window; /*指向窗口的指针*/
GtkWidget *table; /*指向表格的指针*/
GtkWidget *entry; /*指向文本框的指针*/
GtkWidget *button; /*指向按钮的指针*/
GtkWidget *label1; /*指向标签1的指针*/
GtkWidget *label2; /*指向标签2的指针*/
char title[]="Table example";
gtk_init(&argc,&argv);
window=gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW (window), title);
gtk_widget_set_usize (window, 250, 100);
table=gtk_table_new (2,2,FALSE);
/*定义一个2行2列的表格，单元格大小会根据单元格中的元件大小自动调整*/
button=gtk_button_new_with_label("Button");/*新建按钮*/
entry =gtk_entry_new ();/*新建文本框*/
label1=gtk_label_new ("This is label 1");/*新建标签1*/
label2=gtk_label_new ("This is label 2");/*新建标签2*/
gtk_container_add (GTK_CONTAINER (window), table);
/*下面是将四个元件分别添加到表格相应的位置中*/
gtk_table_attach (GTK_TABLE(table), button, 0, 1, 0, 1,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
gtk_table_attach (GTK_TABLE(table), label1, 1, 2, 0, 1,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
gtk_table_attach (GTK_TABLE(table), entry, 0, 1, 1, 2,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
gtk_table_attach (GTK_TABLE(table), label2, 1, 2, 1, 2,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
gtk_widget_show_all (window);   /*显示窗口中的所有元件*/
gtk_main();
return 0;
}
